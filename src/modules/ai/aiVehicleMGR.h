#pragma once
#include <modules\ai\aiVehicleData.h>

namespace MM2
{
    // Forward declarations
    class aiVehicleActive;
    class aiVehicleManager;

    // External declarations
    extern class asNode;
    extern class ltLight;

    // Class definitions
    class aiVehicleActive 
    {
        byte buffer[0xAFC];
    };

    class aiVehicleManager : public asNode {
    private:
        aiVehicleData vehicleDatas[32];
        int numVehicleDatas;
        aiVehicleActive* activeActives[32];
        aiVehicleActive aiVehicleActives[32];
        __int16 attachedCount;
        ltLight* sharedLight;
    public:
        static hook::Type<aiVehicleManager *> Instance;
        static hook::Type<int> SignalClock;

        AGE_API aiVehicleManager(void) {
            scoped_vtable x(this);
            hook::Thunk<0x553B30>::Call<void>(this);
        }

        AGE_API virtual ~aiVehicleManager(void) {
            scoped_vtable x(this);
            hook::Thunk<0x553C2>::Call<void>(this);
        }

        //members
        AGE_API void Init(char *unused)                           { hook::Thunk<0x553CE0>::Call<void>(this, unused); }
        AGE_API int AddVehicleDataEntry(LPCSTR name)              { return hook::Thunk<0x553FA0>::Call<int>(this, name); }
        AGE_API void SaveEntry()                                  { hook::Thunk<0x5541E0>::Call<void>(this); }
        /*
        AGE_API aiVehicleActive Attach
        AGE_API aiVehicleActive Detach
        */

        //asNode overrides
        AGE_API void Reset() override                             { hook::Thunk<0x553D60>::Call<void>(this); }
        AGE_API void Update() override                            { hook::Thunk<0x553EA0>::Call<void>(this); }

        //helpers
        int GetDataCount() {
            return this->numVehicleDatas;
        }

        aiVehicleData * GetData(int num) {
            if (num < 0 || num >= GetDataCount())
                return nullptr;
            return &this->vehicleDatas[num];
        }

        //lua
        static void BindLua(LuaState L) {
            LuaBinding(L).beginExtendClass<aiVehicleManager, asNode>("aiVehicleManager")
                .addStaticProperty("Instance", [] { return Instance.get(); })
                
                .addFunction("AddVehicleDataEntry", &AddVehicleDataEntry)
                .addFunction("SaveEntry", &SaveEntry)

                .addPropertyReadOnly("NumVehicleDatas", &GetDataCount)
                .addPropertyReadOnly("DataCount", &GetDataCount) // old naming convention
                .addFunction("GetData", &GetData)
            .endClass();
        }
    };

    ASSERT_SIZEOF(aiVehicleManager, 0x177A4);
}