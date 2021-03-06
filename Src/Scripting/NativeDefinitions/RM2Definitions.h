#ifndef RM2DEFINITIONS_H_INCLUDED
#define RM2DEFINITIONS_H_INCLUDED

#include "../ScriptManager.h"
#include "../NativeDefinition.h"
#include <Misc/String.h>
#include <Math/Matrix.h>
#include "../../Models/RM2.h"

class GraphicsResources;

class RM2Definitions : public NativeDefinition {
    private:
        RM2* loadRM2(PGE::String filename);
        void deleteRM2(RM2* rm2);

        GraphicsResources* graphicsResources;
    public:
        RM2Definitions(GraphicsResources* gfxRes);
        void registerToEngine(ScriptManager* mgr) override;
        void cleanup() override;
};

#endif
