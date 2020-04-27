// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#define FAKE_EXPORT __declspec(dllexport)
// can export functions here
extern "C" {
    FAKE_EXPORT void FakeExport();
}

void FakeExport()
{
    DbgPrint(PSTR("Initiating Fake Export Function\n"));
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        FakeExport();
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

