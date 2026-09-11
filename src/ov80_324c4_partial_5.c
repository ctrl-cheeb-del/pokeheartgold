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

void ov80_022331E8(void *save, u32 mode, s32 amount) {
    void *frontier = Save_Frontier_GetStatic(save);
    u32 stat = sub_0205C1F0(mode);
    u32 substat = sub_0205C268(sub_0205C1F0(mode));
    {
        s32 current = FrontierSave_GetStat(frontier, stat, substat);
        current += amount;
        if (current > 9999) {
            frontier = Save_Frontier_GetStatic(save);
            stat = sub_0205C1F0(mode);
            substat = sub_0205C268(sub_0205C1F0(mode));
            sub_02031108(frontier, stat, substat, 9999);
        } else {
            frontier = Save_Frontier_GetStatic(save);
            stat = sub_0205C1F0(mode);
            substat = sub_0205C268(sub_0205C1F0(mode));
            sub_02031228(frontier, stat, substat, amount);
        }
    }
    GameStats_Add(Save_GameStats_Get(save), 0x42, amount);
}

void ov80_02233280(void *ctx, u32 state, u16 value) {
    switch (state) {
    case 0:
        ov80_0222B5C8(ctx);
        break;
    case 1:
        ov80_0222B65C(ctx);
        break;
    case 2:
        ov80_0222B6C8(ctx);
        break;
    case 3:
        ov80_0222B7E4(ctx);
        break;
    case 4:
        ov80_0222B8D8(ctx, value);
        break;
    case 5:
        ov80_0222B920(ctx, value);
        break;
    case 6:
        ov80_0222B968(ctx);
        break;
    }
}
