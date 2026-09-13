#include "to42_overlay15_r16_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

s32 ov15_021FCFC8(void *work) {
    void *str;
    s32 n;
    sub_0200E5D4((u8 *)work + 0x44, TRUE);
    ov15_021FF834(work);
    FillWindowPixelBuffer((u8 *)work + 0x34, 15);
    str = NewString_ReadMsgData(PTR(work, 0x2f0), 78);
    n = S16(work, 0x680) * U32(work, 0x684);
    BufferIntegerAsString(PTR(work, 0x2f4), 0, n, 6, 0, TRUE);
    StringExpandPlaceholders(PTR(work, 0x2f4), PTR(work, 0x5e4), str);
    String_Delete(str);
    U8(work, 0x616) = ov15_021FEF48(work, 1);
    ov15_02200428(work);
    ov15_021FFF24(work);
    ov15_021FD788(work, 0);
    return 21;
}

s32 ov15_021FD058(void *work) {
    void *state;
    U32(work, 0x684) = 0;
    sub_0200E5D4((u8 *)work + 0x214, TRUE);
    sub_0200E5D4((u8 *)work + 0x44, TRUE);
    ClearFrameAndWindow2((u8 *)work + 0x34, TRUE);
    ClearWindowTilemapAndScheduleTransfer((u8 *)work + 0x34);
    ScheduleWindowCopyToVram((u8 *)work + 4);
    ov15_02200428(work);
    ov15_021FFF24(work);
    state = PTR(work, 0x234);
    ov15_02200140(work, (u8 *)state + 4 + U8(state, 0x64) * 12, ov15_021FA074(work), 0);
    ov15_021FE868(work);
    ov15_021FED3C(work);
    ov15_021FB518(work);
    ov15_02200458(work, 1);
    ov15_021FD788(work, 1);
    return 16;
}
