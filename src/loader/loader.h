#pragma once

// MM2 uses DirectInput 7
#define DIRECTINPUT_VERSION 0x0700

#include "common.h"
#include "hook.h"
#include "patch.h"

#include "mm2.h"

// dinput hooking
#include <dinput.h>

typedef HRESULT(WINAPI *LPFNDIRECTINPUTCREATE)(HINSTANCE, DWORD, LPVOID *, LPUNKNOWN);

EXTERN_C LPFNDIRECTINPUTCREATE lpDICreate;
EXTERN_C HRESULT DirectInputCreateImpl(HINSTANCE hinst, DWORD dwVersion, LPVOID *ppDI, LPUNKNOWN punkOuter);