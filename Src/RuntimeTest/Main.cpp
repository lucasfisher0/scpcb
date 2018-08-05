#include <Windows.h>
#include <bbruntime.h>
#include <bbgraphics.h>
#include <bbblitz3d.h>
#include <bbinput.h>
#include <bbmath.h>
#include <bbstring.h>
#include <iostream>
#include <vector>

int main() {
    bbruntime_create(GetModuleHandle(NULL));

    bbGraphics3D(1280, 720, 0, 2);

    bbAppTitle(String("     Test  thing     ").trim(),"");

	String test = "this is a test";
	std::vector<String> list = test.split(" "); // Exception here.
	//for (int i = 0; i < list.size(); i++) {
	//	std::cout << list[i];
	//}
    Object* cube = bbCreateCube(nullptr);
    Object* camera = bbCreateCamera(nullptr);

    bbImage* cursor = bbLoadImage("cursor.png");

    bbPositionEntity(camera, 5.0f, 2.0f, -3.0f, false);
    bbPointEntity(camera, cube, 0.0f);

    bbSetBuffer(bbBackBuffer());
    float cnt = 0;
    while (!bbKeyHit(1)) {
        cnt+=0.01f;
        bbPositionEntity(camera,bbSin(cnt)*6.0f,2.0,bbCos(cnt)*6.0f,true);
        bbPointEntity(camera,cube,0.0f);
        bbRenderWorld(1.0f);
        bbDrawImage(cursor, bbMouseX(), bbMouseY(), 0);
        bbFlip(0);
    }

    bbFreeEntity(camera); bbFreeEntity(cube);
    bbFreeImage(cursor);

    bbEndGraphics();

    bbruntime_destroy();

    return 0;
}
