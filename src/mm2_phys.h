#pragma once
#include "mm2_common.h"

#include <modules\phys.h>
#include <modules\banger.h>

namespace MM2
{
    template<>
    void luaAddModule<module_phys>(LuaState L) {
        luaBind<phMaterial>(L);
        luaBind<phPolygon>(L);
        luaBind<LuaRaycastResult>(L);
        luaBind<PhysicsStats>(L);
        luaBind<phInertialCS>(L);
        luaBind<dgPhysManager::CollisionTableEntry>(L);
        luaBind<dgPhysManager>(L);
        luaBind<phColliderBase>(L);
        luaBind<phCollider>(L);
        luaBind<phJoint>(L);
        luaBind<phColliderJointed>(L);
        luaBind<dgTrailerJoint>(L);
        luaBind<dgPhysEntity>(L);
        luaBind<dgBangerData>(L);
        luaBind<dgBangerDataManager>(L);
        luaBind<dgBangerInstance>(L);
        luaBind<dgUnhitBangerInstance>(L);
        luaBind<dgUnhitYBangerInstance>(L);
        luaBind<dgUnhitMtxBangerInstance>(L);
        luaBind<dgHitBangerInstance>(L);
        luaBind<dgBangerActive>(L);
        luaBind<dgBangerManager>(L);
    }
}