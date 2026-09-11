#include "overlay_80_02236450_opus_partial_internal.h"

void ov80_02236698(void *a0, void *dst, int index) {
    void *r;

    MI_CpuFill8(dst, 0, 0x110);
    r = sub_0202D928(a0);
    if (sub_0202D7B0() == 0) {
        ov80_022366D4(dst, index);
    } else {
        sub_0202D804(r, dst, index);
    }
}

void ov80_022366D4(u8 *dst, int index) {
    const u8 *entry;
    const u8 *table;
    int i;

    MI_CpuFill8(dst, 0, 0x110);
    entry = &ov80_0223C050[index * 6];
    table = ov80_0223C0AC;
    MI_CpuCopy8(&ov80_0223C07C[index * 0x30], dst, 0x30);
    *(u16 *)(dst + 6) = *(u16 *)&ov80_0223C050[index * 6];
    dst += 0x30;
    for (i = 0; i < 4; i++) {
        MI_CpuCopy8(&table[entry[i + 2] * 0x38], dst, 0x38);
        dst += 0x38;
    }
}

u32 ov80_02236734(void *work, FrontierMon *dst, u16 trainerMonId, u32 otId, u32 personality, u8 ivs, u8 index, u32 useFixedItem, int heapId) {
    u8 *p = work;
    FrontierMonSrc src;
    u32 unk21;
    u32 pid;
    int i;
    int n;
    u8 ev;
    int total;
    int stat;

    MI_CpuFill8(dst, 0, 0x38);
    ov80_02229EF4(&src, trainerMonId, ov80_02236AF0(p[0xf]));
    dst->species = src.species;
    dst->form = src.unk_0e;
    if (useFixedItem != 0) {
        dst->item = ((const u16 *)ov80_0223C048)[index];
    } else {
        dst->item = src.item;
    }
    unk21 = 0xFF;
    for (i = 0; i < 4; i++) {
        dst->moves[i] = src.moves[i];
        if (src.moves[i] == 0xDA) {
            unk21 = 0;
        }
    }
    dst->unk_0c = otId;
    pid = personality;
    if (pid == 0) {
        do {
            u16 lo = FrontierFieldSystem_0204B510(work);
            u16 hi = FrontierFieldSystem_0204B510(work);
            pid = lo | (hi << 16);
        } while (src.nature != GetNatureFromPersonality(pid) || CalcShininessByOtIdAndPersonality(otId, pid) == 1);
        dst->personality = pid;
    } else {
        dst->personality = pid;
    }
    dst->iv0 = ivs;
    dst->iv1 = ivs;
    dst->iv2 = ivs;
    dst->iv3 = ivs;
    dst->iv4 = ivs;
    dst->iv5 = ivs;
    n = 0;
    for (i = 0; i < 6; i++) {
        if (MaskOfFlagNo(i) & src.evFlags) {
            n++;
        }
    }
    total = _s32_div_f(0x1FE, n);
    if (total > 0xFF) {
        total = 0xFF;
    }
    i = 0;
    ev = total;
    for (; i < 6; i++) {
        if (MaskOfFlagNo(i) & src.evFlags) {
            dst->evs[i] = ev;
        }
    }
    dst->unk_1e = 0;
    dst->language = gGameLanguage;
    stat = GetMonBaseStat(dst->species, 0x19);
    if (stat != 0) {
        if (dst->personality & 1) {
            dst->ability = stat;
        } else {
            dst->ability = GetMonBaseStat(dst->species, 0x18);
        }
    } else {
        dst->ability = GetMonBaseStat(dst->species, 0x18);
    }
    dst->unk_21 = unk21;
    GetSpeciesNameIntoArray(dst->species, heapId, dst->name);
    return pid;
}

void *ov80_0223690C(void *work, void *a1) {
    u8 *p = work;
    u8 *q = a1;
    void *bs;
    void *party;
    void *mon;
    u8 *cursor;
    int i;
    u32 exp;

    bs = BattleSetup_New(*(int *)(p + 4), ov80_02236A88(p[0xf]));
    party = SaveArray_Party_Get(*(void **)(q + 8));
    sub_02051D18(bs, 0, *(void **)(q + 8), *(int *)(q + 0x18), *(int *)(q + 0xc), *(int *)(q + 0x1c));
    *(u32 *)((u8 *)bs + 0x14C) = 0x12;
    *(u32 *)((u8 *)bs + 0x150) = 0x12;
    mon = AllocMonZeroed(*(int *)(p + 4));
    Party_InitWithMaxSize(*(void **)((u8 *)bs + 4), p[0xe]);
    for (i = 0; i < p[0xe]; i++) {
        CopyPokemonToPokemon(Party_GetMonByIndex(party, p[0x2a + i]), mon);
        if (GetMonData(mon, 0xA1, NULL) > 0x32) {
            exp = GetMonExpBySpeciesAndLevel(GetMonData(mon, 5, NULL), 0x32);
            SetMonData(mon, 8, &exp);
            CalcMonLevelAndStats(mon);
        }
        BattleSetup_AddMonToParty(bs, mon, 0);
    }
    Heap_Free(mon);
    BattleSetup_SetAllySideBattlersToPlayer(bs);
    ov80_02236A34(bs, p + 0x78, p[0xe], 1, *(int *)(p + 4));
    i = 0;
    cursor = bs;
    for (; i < 4; i++) {
        *(u32 *)(cursor + 0x34) = 7;
        cursor += 0x34;
    }
    switch (p[0xf]) {
    case 2:
        ov80_02236A34(bs, p + 0x298 + ((Ov80Flags *)(p + 0x10))->unk_5 * 0x110, p[0xe], 2, *(int *)(p + 4));
        /* fallthrough */
    case 3:
    case 6:
        ov80_02236A34(bs, p + 0x188, p[0xe], 3, *(int *)(p + 4));
        break;
    }
    return bs;
}

void ov80_02236A34(void *bs, u8 *mons, int count, int idx, int heapId) {
    void *mon;
    int i;

    ov80_0222A480(bs, mons, count, idx, heapId);
    mon = AllocMonZeroed(heapId);
    i = 0;
    if (count > 0) {
        mons += 0x30;
        do {
            ov80_0222A140(mons, mon, 0x78);
            Party_AddMon(((void **)((u8 *)bs + idx * 4))[1], mon);
            i++;
            mons += 0x38;
        } while (i < count);
    }
    Heap_Free(mon);
}

u32 ov80_02236A88(u32 mode) {
    u32 ret = 0x81;

    switch (mode) {
    case 0:
    case 4:
        return 0x81;
    case 1:
        return 0x83;
    case 2:
        return 0xCB;
    case 3:
    case 6:
        return 0x8F;
    case 5:
        break;
    }
    return ret;
}

void ov80_02236ABC(void *work, u16 value) {
    u8 *p = work;

    ((Ov80Flags *)(p + 0x10))->unk_3 = value;
    *(u16 *)(p + 0x83E) = value;
}

BOOL ov80_02236AD8(void *work, const u16 *arg) {
    u8 *p = work;

    if (((Ov80Flags *)(p + 0x10))->unk_3 || *arg != 0) {
        return TRUE;
    }
    return FALSE;
}

u32 ov80_02236AF0(u32 mode) {
    if (ov80_02236B30(mode) == 0) {
        return 0x81;
    }
    return 0xCD;
}

u32 ov80_02236B04(u32 mode) {
    if (ov80_02236B30(mode) == 0) {
        return 0x80;
    }
    return 0xCC;
}

u32 ov80_02236B18(u32 mode) {
    if (ov80_02236B30(mode) == 0) {
        return 0x2D3;
    }
    return 0x2D4;
}

BOOL ov80_02236B30(u32 mode) {
    int v0;
    int v1;
    void *a;
    void *b;

    if (mode == 3 || mode == 6) {
        a = sub_02034818(0);
        GF_ASSERT(a != NULL);
        b = sub_02034818(1);
        GF_ASSERT(b != NULL);
        v0 = PlayerProfile_GetVersion(a);
        v1 = PlayerProfile_GetVersion(b);
        if (v0 == 0 || v1 == 0) {
            return FALSE;
        }
        return TRUE;
    }
    return TRUE;
}
