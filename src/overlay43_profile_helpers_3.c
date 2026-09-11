#include "overlay43_profile_helpers_private.h"

void ov43_0222AA70(void*w){u8 id=*(u32*)((u8*)w+0x84);if(TextPrinterCheckActive(id)==1){TextFlags_SetCanTouchSpeedUpPrint(0);RemoveTextPrinter(*(u32*)((u8*)w+0x84));}ClearWindowTilemapAndScheduleTransfer((u8*)w+0x64);}
