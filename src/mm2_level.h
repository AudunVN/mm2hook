#pragma once
#include "mm2_common.h"
#include "mm2_inst.h"

namespace MM2
{
    // Forward declarations
    extern class lvlLevel;

    namespace $
    {
        namespace lvlLevel {
            HOOK_EXPORT(0x00465480, _MemberFunc<void>, MoveToRoom);
        }
    }

    class lvlLevel {
    public:
        AGE_API void MoveToRoom(lvlInstance *instance, int room) {
            $::lvlLevel::MoveToRoom(this, instance, room);
        }
    };
    
}