#include "ov80_324c4_partial_internal.h"

void ov80_02232ABC(void *ctx);
u16 ov80_02232B44(const void *data, u32 index);
u8 ov80_02232E58(void *ctx);
u8 ov80_02232E64(const void *ctx);
void ov80_02232EE0(void *ctx);
void ov80_02232F00(void *ctx);
void ov80_022333D0(void *unused, void *window);
u32 ov80_02233648(const void *ctx);
void ov80_02232824(void *ctx, u32 mode);
void ov80_02232E68(void *ctx, u32 index);
void ov80_02232E9C(void *ctx);
void ov80_02232F08(void *ctx);
void ov80_02233280(void *ctx, u32 state, u16 value);
void ov80_022331E8(void *save, u32 mode, s32 amount);
void ov80_02232AEC(void *ctx, const void *data);
void ov80_02232F60(void *ctx);
void ov80_022333F0(void *data, const void *ctx);
void ov80_02233594(void *ctx, void *window, const void *profile, u32 value);

u8 ov80_02232E58(void *ctx) {
    u8 *p = ctx;
    p[0x11]++;
    return p[0x11];
}

u8 ov80_02232E64(const void *ctx) {
    return ((const u8 *)ctx)[0x11];
}

void ov80_02232E68(void *ctx, u32 index) {
    u8 work[0x30];
    u8 *p = ctx;
    u8 item = p[0x11] + index * 7;
    void *allocated = ov80_02229F04(work, *(u16 *)(p + 0x30 + item * 2), 11, 0xCC);
    Heap_Free(allocated);
    ov80_0222A30C((u8) * (u16 *)(work + 4));
}

void ov80_02232E9C(void *ctx) {
    u8 *p = ctx;
    int i;
    for (i = 0; i < 3; i++) {
        void *frontier = Save_Frontier_GetStatic(*(void **)(p + 4));
        u32 stat = sub_0205C174(p[0x10], (u8)i);
        u32 substat = sub_0205C268(sub_0205C174(p[0x10], (u8)i));
        sub_02031108(frontier, stat, substat, 1);
    }
    ov80_02232B58(ctx, 1);
}

void ov80_02232EE0(void *ctx) {
    u8 *p = ctx;
    p[0x27] = 1;
    if (*(u16 *)(p + 0x16) < 8) {
        (*(u16 *)(p + 0x16))++;
    }
    p[0x11] = 0;
    ov80_02232B58(ctx, 0);
}

void ov80_02232F00(void *ctx) {
    ov80_02237E30(ctx);
}
