#include "r45_overlay_41_tail_private.h"

typedef struct Ov41Config {
    u32 unk00;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
} Ov41Config;

typedef struct Ov41Bundle {
    void *unk00;
    void *unk04;
    void *unk08;
    void *unk0C;
    void *unk10;
    void *unk14;
    void *unk18;
    void *unk1C;
    void *unk20;
} Ov41Bundle;

typedef struct Ov41Args {
    void *base;
    void *mons[20];
    s32 count;
    u8 pad58[0x10];
    s32 heapId;
} Ov41Args;

void ov41_0224B6CC(void *work, void *args);
void ov41_0224B780(void *work, void *args);

void ov41_0224B5D8(void *work, s32 x, s32 y) {
    ov41_02248120((u8 *)work + 0x190, PTR_AT(work, 0x23C), PTR_AT(work, 0x240), x, y);
    if (PTR_AT(work, 0x260) != NULL) {
        BgSetPosTextAndCommit(PTR_AT(work, 0x40), 2, 0, 0x88 - x);
        BgSetPosTextAndCommit(PTR_AT(work, 0x40), 2, 3, 0x10 - y);
    }
    S32_AT(work, 0x23C) = x;
    S32_AT(work, 0x240) = y;
}

void *ov41_0224B630(void *args) {
    void *work = Heap_Alloc(S32_AT(args, 0x68), 0x268);
    memset(work, 0, 0x268);
    S32_AT(work, 0x238) = S32_AT(args, 0x68);
    PTR_AT(work, 0x234) = AllocMonZeroed(S32_AT(args, 0x68));
    sub_0202BEF4(PTR_AT(args, 0), PTR_AT(work, 0x234));
    ov41_0224B6CC(work, args);
    ov41_02246544(work, PTR_AT(args, 0x58), S32_AT(args, 0x68));
    ov41_022499B4((u8 *)work + 0x184, 0x15, S32_AT(args, 0x68));
    PTR_AT(work, 0x18C) = ov41_02245EA0(0x14, S32_AT(args, 0x68));
    ov41_0224B780(work, args);
    ov41_0224B848(work, args);
    ov41_0224B4E8((u8 *)work + 0x218, (u8 *)work + 0x190, S32_AT(args, 0x68));
    S32_AT(work, 0x260) = 1;
    S32_AT(work, 0x264) = 1;
    ov41_0224B888(work, args);
    return work;
}

void ov41_0224B6CC(void *work, void *args) {
    u8 temporary[0x18];
    Ov41Config config;
    PTR_AT(work, 0x180) = NARC_New(0x1A, S32_AT(args, 0x68));
    config.unk00 = 0x2CE;
    config.unk04 = 0x76;
    config.unk08 = 0x13;
    config.unk0C = S32_AT(args, 0x68);
    ov41_02246518(work, &config, S32_AT(args, 0x68));
    ov41_0224B938(work, temporary, args, S32_AT(args, 0x68));
    ov41_02246250(work, temporary);
    ov41_022463D4(temporary);
}

void ov41_0224B720(void *work) {
    ov41_022465D8(work, S32_AT(work, 0x23C) + S32_AT(work, 0x244), S32_AT(work, 0x240) + S32_AT(work, 0x248), U16_AT(work, 0x24C), (u8 *)work + 0x250);
}

void ov41_0224B754(void *work) {
    ov41_0224626C(work);
    ov41_02246594(work);
    if (PTR_AT(work, 0x260) != NULL) {
        ov41_022465C0(work);
    }
    NARC_Delete(PTR_AT(work, 0x180));
}

void ov41_0224B780(void *work, void *rawArgs) {
    Ov41Bundle bundle = { 0 };
    u32 temporary[4];
    int i;
    Ov41Args *args = rawArgs;
    bundle.unk00 = PTR_AT(work, 0x00);
    bundle.unk04 = PTR_AT(work, 0x04);
    bundle.unk08 = PTR_AT(work, 0x10);
    bundle.unk0C = PTR_AT(work, 0x30);
    bundle.unk10 = PTR_AT(work, 0x20);
    bundle.unk14 = PTR_AT(work, 0x40);
    bundle.unk18 = PTR_AT(work, 0x18C);
    bundle.unk1C = (u8 *)work + 0x184;
    bundle.unk20 = (void *)0x15;
    ov41_02247F3C((u8 *)work + 0x190, &bundle);
    ov41_02247FAC((u8 *)work + 0x190, PTR_AT(work, 0x234), temporary, sub_0202BEE4(args->base), sub_0202BEEC(args->base), sub_0202BEDC(args->base), args->heapId);
    for (i = 0; i < args->count; i++) {
        ov41_02248044((u8 *)work + 0x190, sub_0202BEFC(args->mons[i]), sub_0202BF00(args->mons[i]), sub_0202BF04(args->mons[i]), sub_0202BF08(args->mons[i]));
    }
}
