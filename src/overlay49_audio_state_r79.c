#include "overlay49_audio_state_r79_private.h"

void ov49_02268CEC(void *work) {
    ov49_02268DB0(work);
    ov49_0225E82C(PTR_AT(work, 4), 0, 0x1000);
    ov49_0225E624(PTR_AT(work, 4), 0);
}

void ov49_02268D0C(u32 kind, Ov49ChoiceSet *set) {
    switch (kind) {
    case 0:
        set->count = 6;
        set->entries = ov49_0226A834;
        break;
    case 1:
        set->count = 2;
        set->entries = ov49_0226A82C;
        break;
    case 2:
        set->count = 2;
        set->entries = ov49_0226A824;
        break;
    case 3:
        set->count = 1;
        set->entries = ov49_0226A81C;
        break;
    case 4:
        set->count = 1;
        set->entries = ov49_0226A820;
        break;
    case 5:
        set->count = 2;
        set->entries = ov49_0226A828;
        break;
    case 6:
        set->count = 3;
        set->entries = ov49_0226A830;
        break;
    default:
        GF_AssertFail();
        break;
    }
}

void ov49_02268D94(void *work) {
    if (U8_AT(work, 9) == 0) {
        PlaySE(0x5B5);
        U8_AT(work, 9) = 1;
    }
}

void ov49_02268DB0(void *work) {
    if (U8_AT(work, 9) != 0) {
        StopSE(0x5B5, 0);
        U8_AT(work, 9) = 0;
    }
}

BOOL ov49_02268DCC(void *task, void *ctx) {
    u32 *returnState = (u32 *)ov49_0225EF84(task);
    void *state = (void *)ov49_02259FE8(ctx);
    void *field = (void *)ov49_02259FF0(ctx);
    void *manager = (void *)ov49_02258DB0();
    void *sub = (void *)ov49_02258DAC(field);

    switch (ov49_0225EF88(task)) {
    case 0: {
        void *message;
        u32 value;

        returnState = (u32 *)ov49_0225EF40(task, 4);
        PlaySE(0x5DC);
        ov49_02258E60(sub, 6);
        value = ov42_022282A4();
        ov49_02258EEC(field, manager, 0);
        ov49_02259130(manager, 0);
        ov49_02259160(manager, value);
        if (ov45_0222A330(state) != 0) {
            message = (void *)ov49_0225A30C(ctx, 1, 3);
            *returnState = 4;
            ov49_0225A08C(ctx, message);
            ov49_0225EF8C(task, 5);
        } else if (ov45_0222A3A0(state) == 1) {
            message = (void *)ov49_0225A30C(ctx, 1, 0x58);
            *returnState = 4;
            ov49_0225A08C(ctx, message);
            ov49_0225EF8C(task, 5);
        } else if (ov45_0222A2E0(state) == 1) {
            message = (void *)ov49_0225A30C(ctx, 1, 0x57);
            *returnState = 4;
            ov49_0225A08C(ctx, message);
            ov49_0225EF8C(task, 5);
        } else {
            message = (void *)ov49_0225A30C(ctx, 1, 0x51);
            *returnState = 1;
            ov49_0225A08C(ctx, message);
            ov49_0225EF8C(task, 5);
        }
        break;
    }
    case 1:
        ov49_0225A264(ctx);
        ov49_0225EF8C(task, 2);
        break;
    case 2:
        switch (ov49_0225A2C4(ctx)) {
        case 0:
            ov49_0225EF8C(task, 3);
            ov49_0225A2F8(ctx);
            break;
        case 1:
            ov49_0225EF8C(task, 4);
            ov49_0225A2F8(ctx);
            break;
        case 2:
            break;
        }
        break;
    case 3: {
        void *message = (void *)ov49_0225A30C(ctx, 1, 0x55);
        *returnState = 4;
        ov49_0225A08C(ctx, message);
        ov49_0225EF8C(task, 5);
        break;
    }
    case 4:
        ov49_0225A0EC(ctx);
        ov49_0225A2F8(ctx);
        ov49_02258EEC(field, sub, 1);
        ov49_0225EF68(task);
        ov49_02259130(manager, 1);
        ov49_02258EAC(field, manager, 0, 1);
        return TRUE;
    case 5:
        if (ov49_0225A0AC(ctx) == 1) {
            ov49_0225EF8C(task, *returnState);
        }
        break;
    default:
        GF_AssertFail();
        break;
    }
    return FALSE;
}

void *ov49_02268FAC(void *ctx, u32 heapId) {
    void *work = Heap_Alloc(heapId, 0xC4);
    u8 *record;
    int i;
    const u8 *src;
    u16 values[2];

    memset(work, 0, 0xC4);
    PTR_AT(work, 0) = ctx;
    PTR_AT(work, 4) = (void *)ov49_02259FE8(ctx);
    PTR_AT(work, 8) = (void *)ov49_02259FF8(ctx);
    PTR_AT(work, 0xC) = (void *)ov49_0225A000(ctx);
    U32_AT(work, 0xBC) = ov49_022589A8() + 6;
    U32_AT(work, 0xC0) = -8 - U32_AT(work, 0xBC);
    U32_AT(work, 0xBC) <<= 16;
    U32_AT(work, 0xC0) <<= 16;

    src = ov49_0226A8C8;
    i = 0;
    record = work;
    for (; i < 3; i++, src++, record += 4) {
        ov49_022589D8(PTR_AT(work, 0xC), *src, &values[1], &values[0], 0);
        U16_AT(record, 0xAA) = values[1] << 4;
        U16_AT(record, 0xAC) = values[0] << 4;
    }
    for (i = 0; i < 9; i++) {
        ov49_0225E3B8(PTR_AT(work, 8), i, U32_AT(work, 0xBC));
        if (ov45_0222AD80(PTR_AT(work, 4), i) == 1) {
            ov49_02269178(work, i);
            ov49_022695C4(work, i);
        }
    }
    return work;
}
