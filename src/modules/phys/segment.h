#pragma once
#include <modules\vector.h>

namespace MM2
{
    // Forward declarations
    struct phSegment;
    struct lvlSegmentInfo;
    struct lvlSegment;

    // External declarations
    extern struct sdlPolyCached;

    // Class definitions
    struct lvlSegmentInfo
    {
        int StartRoomId;
        int EndRoomId;
        sdlPolyCached* Polygon;
    };

    struct phSegment
    {
        int unknown0;
        Vector3 StartPos;
        Vector3 EndPos;
    };
    ASSERT_SIZEOF(phSegment, 0x1C);

    struct lvlSegment : phSegment
    {
        bool IsVertical;
        float InvLength;
        lvlSegmentInfo* SegmentInfo;

        lvlSegment()
        {
            IsVertical = false;
            InvLength = 0.0f;
            SegmentInfo = nullptr;
        }

        AGE_API void Set(Vector3 const & startPosition, Vector3 const & endPosition, int flag, lvlSegmentInfo* info)                  
                                                                { hook::Thunk<0x469F90>::Call<void>(this, &startPosition, &endPosition, flag, info);}
    };
    ASSERT_SIZEOF(lvlSegment, 0x28);

    // Lua initialization

}