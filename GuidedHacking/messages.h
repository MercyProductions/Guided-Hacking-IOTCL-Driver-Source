#pragma once

#include <ntdef.h> // Include necessary header for DbgPrintEx
#define DebugMessage(x, ...) DbgPrintEx(0,0, x, __VA_ARGS__)

