#pragma warning (disable : 4047 4311 4459)
#include "events.h"
#include "messages.h"
#include "data.h"


PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo)
{
    if (FullImageName != NULL && ImageInfo != NULL && wcsstr(FullImageName->Buffer, L"\\Counter-Strike Global Offensive\\csgo\\bin\\client.dll"))
    {
        DebugMessage("CSGO Client.Dll Found!\n");
        CSGOClientDLLAddress = (ULONG)(ULONG_PTR)ImageInfo->ImageBase;
        ProcessID = (ULONG)ProcessId;


        DebugMessage("ProcessID: %p \n", ProcessId);

    }

    return STATUS_SUCCESS;
}

