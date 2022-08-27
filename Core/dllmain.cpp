#include <Windows.h>
#include <cstdint>
#include <winnt.h>
#include <cstdio>
#include <consoleapi.h>
#include <libloaderapi.h>
#include <vector>
#include <iostream>
#include <Psapi.h>
#include <fstream>
#include <format>

#include "minhook/MinHook.h"

#pragma comment(lib, "minhook/minhook.lib")

#include "SDK.hpp"

#include "Util.h"
#include "Core.h"

#include "Abilities.h"
#include "Inventory.h"

#include "NetHooks.h"
#include "Net.h"

#include "Hooks.h"
#include "NativeHooks.h"

DWORD WINAPI MainThread(LPVOID)
{
    Util::InitConsole();

    CORE_LOG(Init, "Setting up.");

    MH_Initialize();

    UObject::GObjects = decltype(UObject::GObjects)(Util::BaseAddress() + 0x5B1B0B0);
    FMemory_Free = decltype(FMemory_Free)(Cool::CoolSigScan("48 85 C9 74 ? 53 48 83 EC ? 48 8B D9 48 8B 0D"));
    FMemory_Malloc = decltype(FMemory_Malloc)(Cool::CoolSigScan("48 89 5C 24 08 57 48 83 EC ? 48 8B F9 8B DA 48 8B 0D ? ? ? ? 48 85 C9"));
    FMemory_Realloc = decltype(FMemory_Realloc)(Cool::CoolSigScan("48 89 5C 24 08 48 89 74 24 10 57 48 83 EC ? 48 8B F1 41 8B D8 48 8B 0D"));
    FNameToString = decltype(FNameToString)(Cool::CoolSigScan("48 89 5C 24 08 57 48 83 EC ? 83 79 04 ? 48 8B DA"));

    Core::Init();

    GetLocalPlayerController()->SwitchLevel(L"Athena_Terrain");

    Abilities::Init();
    Hooks::Init();
    NativeHooks::Init();
    Net::Init();
    NetHooks::Init();

    CORE_LOG(Init, "Setup.");

    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID res)
{
    if (reason == 1)
        CreateThread(0, 0, MainThread, mod, 0, 0);

    return TRUE;
}