#include "to41_overlay_15_prefix_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void BagApp_ToggleGBSounds(void *work) {
    if (SoundSys_GetGBSoundsState() == 1) {
        SoundSys_ToggleGBSounds();
        NewString_ReadMsgData(PTR(work, 0x2f0), 105);
    } else {
        SoundSys_ToggleGBSounds();
        NewString_ReadMsgData(PTR(work, 0x2f0), 104);
    }
}
