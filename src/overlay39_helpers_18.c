#include "overlay39_helpers_internal.h"

void ov39_02228948(Ov39App *app) {
    RemoveWindow((u8 *)app + 0x44);
    RemoveWindow((u8 *)app + 0x54);
    RemoveWindow((u8 *)app + 0x64);
}
