#ifndef SCRIPTMODULE_H_INCLUDED
#define SCRIPTMODULE_H_INCLUDED

#include <angelscript.h>
#include <Misc/FilePath.h>
#include <Misc/String.h>
#include <map>
#include <inttypes.h>
#include <tinyxml2.h>

class Type;
class ScriptManager;
class ScriptFunction;
class ScriptClass;
class ScriptGlobal;
class Script;

class ScriptModule {
    private:
        PGE::String name;
        ScriptManager* scriptManager;
        asIScriptModule* scriptModule;
        bool built;

        std::vector<Script*> scripts;
        std::vector<ScriptFunction*> functions;
        std::vector<ScriptGlobal*> globals;
        std::vector<ScriptClass*> classes;

    public:
        ScriptModule(ScriptManager* mgr, const PGE::String& nm);

        void addScript(const PGE::String& sectionName, Script* script);
        void build();

        asIScriptModule* getAngelScriptModule() const;
        ScriptManager* getScriptManager() const;

        ScriptClass* getClassByName(const PGE::String& name) const;
        ScriptClass* getClassByTypeId(int typeId) const;

        ScriptFunction* getFunctionByName(const PGE::String& name) const;

        Type* typeFromTypeId(int typeId) const;

        void save(tinyxml2::XMLDocument& doc) const;
        void load(tinyxml2::XMLElement* moduleElement) const;
        void saveXML(const void* ref, Type* type, tinyxml2::XMLElement* element) const;
        void loadXML(void* ref, Type* type, tinyxml2::XMLElement* element) const;
};

#endif
