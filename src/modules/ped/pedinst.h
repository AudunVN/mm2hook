#pragma once
#include <modules\ped.h>
#include <modules\level.h>

namespace MM2
{
    // Forward declarations
    class aiPedestrianInstance;

    // External declarations
    extern class dgPhysEntity;
    extern class lvlInstance;

    extern class pedAnimationInstance;
    extern class aiPedestrian;

    // Class definitions

    class aiPedestrianInstance : public lvlInstance {
    private:
        byte _buffer[0x18];
    protected:
        static hook::Field<0x18, pedAnimationInstance> _animationInstance;
        static hook::Field<0x14, aiPedestrian*> _ped;
    public:
        aiPedestrian* GetPedestrian() const {
            return _ped.get(this);
        }

        pedAnimationInstance* GetAnimationInstance() const {
            return _animationInstance.ptr(this);
        }

        aiPedestrianInstance(void)                          DONOTCALL;
        aiPedestrianInstance(const aiPedestrianInstance &&) DONOTCALL;

        /*
            lvlInstance virtuals
        */

        virtual AGE_API dgPhysEntity * AttachEntity(void)   { return hook::Thunk<0x57B730>::Call<dgPhysEntity *>(this); }
        virtual AGE_API bool IsCollidable(void)             { return hook::Thunk<0x57B780>::Call<bool>(this); }

        // lua
        static void BindLua(LuaState L) {
            LuaBinding(L).beginExtendClass<aiPedestrianInstance, lvlInstance>("aiPedestrianInstance")
                .addPropertyReadOnly("Pedestrian", &GetPedestrian)
                .addPropertyReadOnly("AnimationInstance", &GetAnimationInstance)
                .endClass();
        }
    };

    ASSERT_SIZEOF(aiPedestrianInstance, 0x2C);
}