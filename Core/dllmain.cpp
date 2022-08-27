#include <Windows.h>

#include "minhook/MinHook.h"

#pragma comment(lib, "minhook/minhook.lib")

#include "Util.h"

DWORD WINAPI MainThread(LPVOID)
{


    return 0;
}

BOOL APIENTRY DllMain(HMODULE mod, DWORD reason, LPVOID res)
{
    if (reason == 1)
        CreateThread(0, 0, MainThread, mod, 0, 0);

    return TRUE;
}