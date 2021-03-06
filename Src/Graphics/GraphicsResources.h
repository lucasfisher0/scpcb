#ifndef GRAPHICSRESOURCES_H_INCLUDED
#define GRAPHICSRESOURCES_H_INCLUDED

#include <Graphics/Graphics.h>
#include <Shader/Shader.h>
#include <Texture/Texture.h>

class Config;
class Camera;

class GraphicsResources {
    private:
        struct Shader {
            PGE::FilePath filename;
            PGE::Shader* shader;
            int refCount;
            bool needsViewProjection;
        };
        std::vector<Shader> shaders;

        struct Texture {
            PGE::FilePath filename;
            PGE::Texture* texture;
            int refCount;
        };
        std::vector<Texture> textures;

        PGE::Matrix4x4f orthoMat;
        PGE::FilePath uiShaderPath = PGE::FilePath::fromStr("GFX/Shaders/UI/");
        PGE::FilePath uiTexturelessShaderPath = PGE::FilePath::fromStr("GFX/Shaders/UITextureless/");
        PGE::FilePath fontShaderPath = PGE::FilePath::fromStr("GFX/Shaders/Text/");

        PGE::Graphics* graphics;

    public:
        GraphicsResources(PGE::Graphics* gfx, Config* con);

        PGE::Shader* getShader(const PGE::FilePath& filename, bool needsViewProjection);
        void dropShader(PGE::Shader* shader);
        void updateShaderConstant(const PGE::FilePath& shd, const PGE::String& constant, const PGE::Matrix4x4f& val);

        PGE::Texture* getTexture(const PGE::FilePath& filename);
        void dropTexture(PGE::Texture* texture);
    
        void updateOrthoMat(float aspectRatio);
        PGE::Matrix4x4f getOrthoMat() const;
        void setCameraUniforms(const Camera* cam) const;

        PGE::Graphics* getGraphics() const;
};

#endif // GRAPHICSRESOURCES_H_INCLUDED
