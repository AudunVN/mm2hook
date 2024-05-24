#pragma once
#include <mm2_common.h>

namespace MM2
{
    // Forward declarations
    class Base;

    // External declarations


    // Class definitions
    class Base {
    public:
        ANGEL_ALLOCATOR
        virtual AGE_API ~Base();
        static void BindLua(LuaState L);
    };
}