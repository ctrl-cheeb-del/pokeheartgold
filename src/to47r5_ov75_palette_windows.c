#include "global.h"

typedef struct {
    u8 raw[0x400];
} State;

typedef struct {
    u8 raw[0x330];
} Sub;

extern void AddWindowParameterized(void *, void *, u8, u8, u8, u8, u8, u8, u16);
extern void FillWindowPixelBuffer(void *, int);
extern void ov75_02249684(void *, void *, u32, u32, u32, u32);

void ov75_022476E8(void *task, Sub *p);
void ov75_02247790(State *p);

void ov75_022476E8(void *task, Sub *p) {
    if (*(void **)((u8 *)p + 4)) {
        *(u8 *)((u8 *)p + 0x32b) ^= 1;
        if ((*(u8 *)((u8 *)p + 0x32b) & 1) == 0) {
            if (*(u32 *)((u8 *)p + 0x32c) <= 1) {
                GX_LoadBGPltt((u8 *)p + 0x88 + *(s16 *)((u8 *)p + 0x328) * 32, 0, 32);
            }
            if (*(u32 *)((u8 *)p + 0x32c) == 0 || *(u32 *)((u8 *)p + 0x32c) == 2) {
                GXS_LoadBGPltt((u8 *)p + 0x88 + *(s16 *)((u8 *)p + 0x328) * 32, 0, 32);
            }
            if (*(s8 *)((u8 *)p + 0x32a) == 0) {
                (*(s16 *)((u8 *)p + 0x328))++;
                if (*(s16 *)((u8 *)p + 0x328) >= 21) {
                    *(s16 *)((u8 *)p + 0x328) = 19;
                    *(s8 *)((u8 *)p + 0x32a) ^= 1;
                }
            } else {
                (*(s16 *)((u8 *)p + 0x328))--;
                if (*(s16 *)((u8 *)p + 0x328) < 0) {
                    *(s16 *)((u8 *)p + 0x328) = 1;
                    *(s8 *)((u8 *)p + 0x32a) ^= 1;
                }
            }
        }
    }
}

void ov75_02247790(State *p) {
    AddWindowParameterized(*(void **)((u8 *)p + 4), (u8 *)p + 0x68, 0, 4, 4, 23, 16, 13, 148);
    FillWindowPixelBuffer((u8 *)p + 0x68, 0);
    AddWindowParameterized(*(void **)((u8 *)p + 4), (u8 *)p + 0x58, 0, 4, 1, 24, 2, 13, 516);
    FillWindowPixelBuffer((u8 *)p + 0x58, 0);
    ov75_02249684((u8 *)p + 0x58, *(void **)((u8 *)p + 0x3c), 0, 1, 1, 0xF0E00);
    AddWindowParameterized(*(void **)((u8 *)p + 4), (u8 *)p + 0x48, 0, 2, 19, 27, 4, 13, 40);
    FillWindowPixelBuffer((u8 *)p + 0x48, 0);
}
