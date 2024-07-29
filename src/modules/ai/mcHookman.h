#pragma once
#include "aiVehiclePhysics.h"

namespace MM2
{
    // Forward declarations
    class mcHookman;

    // External declarations


    // Class definitions

    class mcHookman {
    private:
        byte _buffer[0x9870];
    protected:
        static hook::Field<0x00, aiVehiclePhysics> _vehiclePhysics;
        static hook::Field<0x9794, short> _id;
    public:
        mcHookman(void)                                     DONOTCALL;
        mcHookman(const mcHookman &&)                       DONOTCALL;

        int GetId() const                            { return _id.get(this); }
        aiVehiclePhysics* GetVehiclePhysics() const  { return _vehiclePhysics.ptr(this); }
        vehCar* GetCar() const                       { return _vehiclePhysics.ptr(this)->GetCar(); }
        short GetState() const                       { return _vehiclePhysics.ptr(this)->GetState(); }
        int GetCurrentLap() const                    { return _vehiclePhysics.ptr(this)->GetCurrentLap(); }
        int GetLapCount() const                      { return _vehiclePhysics.ptr(this)->GetLapCount(); }
        bool CanRepairDamage() const                 { return _vehiclePhysics.ptr(this)->CanRepairDamage(); }
        void SetCanRepairDamage(bool value)          { _vehiclePhysics.ptr(this)->SetCanRepairDamage(true); }

        void DrawRouteThroughTraffic()
        {
            this->GetVehiclePhysics()->DrawRouteThroughTraffic();
        }

        static void BindLua(LuaState L) {
            LuaBinding(L).beginClass<mcHookman>("mcHookman")
                .addPropertyReadOnly("ID", &GetId)
                .addPropertyReadOnly("Car", &GetCar)
                .addPropertyReadOnly("State", &GetState)
                .addPropertyReadOnly("CurrentLap", &GetCurrentLap)
                .addPropertyReadOnly("NumLaps", &GetLapCount)
                .addProperty("CanRepairDamage", &CanRepairDamage, &SetCanRepairDamage)
                .addFunction("DrawRouteThroughTraffic", &DrawRouteThroughTraffic)
                .endClass();
        }
    };

    ASSERT_SIZEOF(mcHookman, 0x9870);
}