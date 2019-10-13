#include <iostream>
#include <cmath>
#include <Color/Color.h>

#include "World.h"
#include "Timing.h"
#include "FPSCounter.h"
#include "../Graphics/Camera.h"
#include "../Graphics/GraphicsResources.h"
#include "../Menus/PauseMenu.h"
#include "../Menus/Menu.h"
#include "../Save/Config.h"
#include "../Menus/GUI/GUIComponent.h"
#include "../Menus/GUI/GUIText.h"
#include "../Input/KeyBinds.h"
#include "../Input/Input.h"
#include "../Utils/TextMgmt.h"

World::World() {
    config = new Config("options.ini");

    graphics = PGE::Graphics::create("SCP - Containment Breach", config->getWidth(), config->getHeight(), false);
    graphics->setViewport(PGE::Rectanglei(0, 0, config->getWidth(), config->getHeight()));
    io = PGE::IO::create(graphics->getWindow());

    timing = new Timing(60);

    gfxRes = new GraphicsResources(graphics, config);
    txtMngt = new TxtManager(config->getLangCode());

    FT_Init_FreeType(&ftLibrary);
    largeFont = new Font(ftLibrary, gfxRes, config, PGE::FileName::create("GFX/Font/cour.ttf"), 20);
    spriteMesh = Sprite::createSpriteMesh(graphics);
    uiMesh = new UIMesh(gfxRes);
    keyBinds = new KeyBinds(io);

    camera = new Camera(gfxRes, config->getAspectRatio());

    currMenu = nullptr;
    menuGraveyard = nullptr;
    io->setMouseVisibility(false);
    io->setMousePosition(PGE::Vector2f(config->getWidth() / 2, config->getHeight() / 2));
    pauseMenu = new PauseMenu(this, uiMesh, largeFont, keyBinds, config, txtMngt, io);

    fps = new FPSCounter(uiMesh, keyBinds, config, largeFont);
    fps->visible = true;

#ifdef DEBUG
    mouseTxtX =  new GUIText(uiMesh, keyBinds, config, largeFont, 0.f, -5.f, Alignment::Bottom | Alignment::Left);
    mouseTxtY =  new GUIText(uiMesh, keyBinds, config, largeFont, 0.f, -2.5f, Alignment::Bottom | Alignment::Left);
#endif

    shutdownRequested = false;

    // TODO: Remove.
    loadPlaying();
}

World::~World() {
    delete pauseMenu;
    delete uiMesh;
    delete keyBinds;
    delete todo_Remove.testSquare;
    delete spriteMesh;
#ifdef DEBUG
    delete mouseTxtX;
    delete mouseTxtY;
#endif

    delete camera;
    delete timing;
    delete gfxRes;
    delete txtMngt;

    delete io;
    delete graphics;
}

void World::activateMenu(Menu *mu) {
    if (currMenu != nullptr) {
        throw std::runtime_error("Attempted to activate a menu while another was active.");
    }

    currMenu = mu;
}

void World::deactivateMenu(Menu *mu) {
    if (mu != currMenu) {
        throw std::runtime_error("Attempted to deactivate a menu that wasn't active.");
    }

    if (mu->isMarkedForDeath()) {
        menuGraveyard = mu;
    }
    currMenu = nullptr;
}

bool World::run() {
    if (shutdownRequested) {
        return false;
    }
    
    keyBinds->update();
    Input input = keyBinds->getFiredInputs();

    // Game logic updates first, use accumulator.
    while (timing->tickReady()) {
        runTick((float)timing->getTimeStep(), input);
        timing->subtractTick();
    }

    // Rendering next, don't use accumulator.
    graphics->update();

    graphics->clear(PGE::Color(1.f, 0.f, 1.f, 1.f)); // Puke-inducing magenta

    draw();

    // Get elapsed seconds since last run.
    double secondsPassed = timing->getElapsedSeconds();
    timing->addSecondsToAccumulator(secondsPassed);
    fps->update(secondsPassed);

    return graphics->getWindow()->isOpen();
}

void World::runTick(float timeStep, Input input) {
    SysEvents::update();
    io->update();

    // Get mouse position and convert it to screen coordinates.

    // Convert it to [0, 100].
    PGE::Vector2f scale = PGE::Vector2f(GUIComponent::SCALE_MAGNITUDE * 2 / config->getWidth(), GUIComponent::SCALE_MAGNITUDE * 2 / config->getHeight());
    PGE::Vector2f mousePosition = PGE::Vector2f(io->getMousePosition().x * scale.x, io->getMousePosition().y * scale.y);
    mousePosition.x *= config->getAspectRatio();

    // Subtract 50 to bring it inline with the [-50, 50] screen coordinates.
    mousePosition.x -= GUIComponent::SCALE_MAGNITUDE * config->getAspectRatio();
    mousePosition.y -= GUIComponent::SCALE_MAGNITUDE;

#ifdef DEBUG
    mouseTxtX->text = PGE::String("MouseX: ", PGE::String(mousePosition.x));
    mouseTxtY->text = PGE::String("MouseY: ", PGE::String(mousePosition.y));
#endif

    // If a menu is in the graveyard then remove it.
    if (menuGraveyard != nullptr) {
        delete menuGraveyard;
        menuGraveyard = nullptr;
    }

    bool prevMenu = currMenu != nullptr;
    if (!prevMenu) {
        updatePlaying(timeStep, input);
    } else {
        currMenu->update(mousePosition);
    }
    
    if (keyBinds->escape->isHit()) {
        // If a text input is active then escape de-selects it.
        // Unless it's the console's input.
        if (GUITextInput::hasSubscriber() && currMenu != nullptr && !currMenu->getType().equals("console")) {
            GUITextInput::deselectSubscribed();
        } else if (currMenu != nullptr) {
            currMenu->onEscapeHit();
        } else {
            activateMenu(pauseMenu);
        }
    }

    // If a menu was closed this tick then reset the mouse position.
    if (prevMenu && currMenu == nullptr) {
        io->setMousePosition(PGE::Vector2f(config->getWidth() / 2, config->getHeight() / 2));
        io->setMouseVisibility(false);
    } else if (!prevMenu && currMenu != nullptr) {
        io->setMouseVisibility(true);
    }
}

void World::draw() {
    drawPlaying();

    // UI.
    graphics->setDepthTest(false);

    if (currMenu != nullptr) {
        currMenu->render();
    }

    fps->draw();
#ifdef DEBUG
    mouseTxtX->render();
    mouseTxtY->render();
#endif

    graphics->setDepthTest(true);

    graphics->swap(config->isVsync());
}

void World::updatePlaying(float timeStep, Input input) {
    int centerX = config->getWidth() / 2;
    int centerY = config->getHeight() / 2;

    // TODO: Sensitivity from Config class.
    float mouseXDiff = (float)(io->getMousePosition().x - centerX) / 300.f;
    float mouseYDiff = (float)(io->getMousePosition().y - centerY) / 300.f;

    camera->addAngle(mouseXDiff, mouseYDiff);

    // Reset mouse to center.
    io->setMousePosition(PGE::Vector2f(centerX, centerY));

    todo_Remove.testSquare->addRotation(5.f * timeStep);
    todo_Remove.testSquare->update();
    
    // View/Projection matrix.
    camera->update();
}

void World::drawPlaying() {
    gfxRes->setCameraUniforms(camera);
    
    PGE::Matrix4x4f rm2Matrix;
    for (int i = -20; i <= 20; i++) {
        for (int j = -20; j <= 20; j++) {
            rm2Matrix = PGE::Matrix4x4f::constructWorldMat(PGE::Vector3f(i * (2048.f * 0.01f) - 2.3f, -1.f, j * (2048.f * 0.01f) - 7.f), PGE::Vector3f::one.multiply(0.01f), PGE::Vector3f::zero);

            todo_Remove.rm2->render(rm2Matrix);
        }
    }

    todo_Remove.testSquare->render();
}

void World::loadPlaying() {
    todo_Remove.dirtymetal = gfxRes->getTexture(PGE::FileName::create("GFX/Map/Textures/dirtymetal.jpg"));
    todo_Remove.testSquare = new Sprite(gfxRes, spriteMesh, todo_Remove.dirtymetal);
    todo_Remove.testSquare->setPosition(0.f, 0.f, 2.f);
    todo_Remove.testSquare->setRotation(0.5f);
    todo_Remove.testSquare->setScale(1.f);
    todo_Remove.rm2 = new RM2(gfxRes, PGE::FileName::create("GFX/Map/Rooms/EntranceZone/hll_plain_4/hll_plain_4.rm2"));
}

void World::destroyPlaying() {
    gfxRes->dropTexture(todo_Remove.dirtymetal); todo_Remove.dirtymetal = nullptr;
    delete todo_Remove.testSquare; todo_Remove.testSquare = nullptr;
}

void World::quit() {
    shutdownRequested = true;
}
