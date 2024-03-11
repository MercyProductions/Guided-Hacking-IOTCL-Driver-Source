#pragma once
#include <ntdef.h>

#include "ntifs.h" // Include necessary header for PLOAD_IMAGE_NOTIFY_ROUTINE definition

PLOAD_IMAGE_NOTIFY_ROUTINE ImageLoadCallback(PUNICODE_STRING FullImageName, HANDLE ProcessId, PIMAGE_INFO ImageInfo);

