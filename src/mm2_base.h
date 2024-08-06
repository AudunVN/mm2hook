#pragma once
#include "mm2_common.h"
#include "mm2_lua.h"

#include <modules\node.h>

namespace MM2
{
    // External declarations
    extern class asNode;

    template<>
    void luaAddModule<module_base>(LuaState L) {
        luaBind<Base>(L);
        luaBind<asCullable>(L);
        luaBind<asNode>(L);
        luaBind<asRoot>(L);
        luaBind<asFileIO>(L);
        luaBind<asCullManager>(L);
        luaBind<asLinearCS>(L);
        luaBind<asDofCS>(L);
        luaBind<asViewCS>(L);
        luaBind<luaNode>(L);
        luaBind<Random>(L);
    }
}