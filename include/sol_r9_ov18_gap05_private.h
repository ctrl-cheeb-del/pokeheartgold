#ifndef TO47_SOL_R4_OV18_GAP05_PRIVATE_H
#define TO47_SOL_R4_OV18_GAP05_PRIVATE_H

#include "global.h"

void FillWindowPixelBuffer(void *, u32);
void ClearWindowTilemapAndScheduleTransfer(void *);
void ScheduleWindowCopyToVram(void *);
u8 GetWindowWidth(void *);
u32 FontID_String_GetWidthMultiline(u32, void *, u32);
void String_Delete(void *);
u32 Pokedex_ConvertToCurrentDexNo(BOOL, u32);
void BufferIntegerAsString(void *, int, int, int, int, int);
void *ov18_021E590C(u32, int, int);
void *ov18_021E595C(u32, int, int);
void *ov18_021E59A8(u32, int, int, int);
void ov18_021EE3AC(void *, void *, u32, u32, s32, u32, u32, u32, u32);
void ov18_021F95FC(void *, void *, u32, u32, u32, u32, u32);
void ov18_021EE9FC(void *, u32);
void ov18_021EEA40(void *, u32);
void ov18_021EEAE4(void *, u32, u32, u32);
void ov18_021EEB94(void *, u32, u32, u32);
void ov18_021EEBE4(void *, u32);
void ov18_021EEC34(void *, u32, u32, u32);
void ov18_021EECB0(void *, u32, u32);
void ov18_021EED00(void *, u32, u32, u32);
void ov18_021EE75C(void *, u32, u32);
void ov18_021EE7DC(void *, u32, u32);
void ov18_021EE834(void *, u32, u32, u32);
void ov18_021EE984(void *, u32, u32, u32);

typedef struct To47Window18 {
    u8 raw[0x10];
} To47Window18;

typedef struct To47Work18 {
    u8 header[0xc];
    To47Window18 windows[101];
    u8 filler_065c[0x1200];
    u8 language;
} To47Work18;

void ov18_021EE8B8(To47Work18 *, u32, u32);

#endif
