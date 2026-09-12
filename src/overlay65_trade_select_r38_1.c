#include "overlay65_r38_private.h"

void ov65_0221C9D8(Pokemon *mon, Ov65MonSummary *summary) {
    BOOL decryptResult;
    u32 heldItem;

    decryptResult = AcquireMonLock(mon);
    summary->gender = GetMonData(mon, 0x9b, NULL);
    summary->species = GetMonData(mon, 5, NULL);
    summary->form = GetMonData(mon, 0x70, NULL);
    summary->language = GetMonData(mon, 0x4c, NULL);
    summary->unk8 = GetMonData(mon, 0x6f, NULL);
    summary->personality = GetMonData(mon, 0xa2, NULL);
    heldItem = GetMonData(mon, 6, NULL);
    ReleaseMonLock(mon, decryptResult);

    if (summary->species != 0) {
        summary->unka = GetMonBaseStat_HandleAlternateForm(summary->species, summary->form, 0x1c);
    }
    if (heldItem != 0) {
        summary->mail = ItemIdIsMail((u16)heldItem) + 1;
    }
}

void ov65_0221CA64(void *work, int index, int form) {
    Sprite **sprites = (Sprite **)((u8 *)work + 0x40c);

    Sprite_SetAnimCtrlSeq(sprites[index], form + 7);
    if (index == 2) {
        GfGfxLoader_GXLoadPal(0xa2, ov65_0221FEEC[form - 1], 5, 0x160, 0x20, 0x1a);
        Sprite_SetPaletteOverride(sprites[index], 0xb);
    } else if (index == 3) {
        GfGfxLoader_GXLoadPal(0xa2, ov65_0221FEEC[form - 1], 5, 0x180, 0x20, 0x1a);
        Sprite_SetPaletteOverride(sprites[index], 0xc);
    }
}

void ov65_0221CADC(void *work, int selection) {
    int slot;
    int page;
    void *mon;

    slot = selection % 6;
    mon = Party_GetMonByIndex(PTR_AT(work, 0x2228), slot);
    page = selection / 6;
    PTR_AT(work, 0x211c) = ov65_0221D57C(1, mon, (u8 *)work + 0x7fc + page * 0xc80, (u8 *)work + 0x20fc + page * 16);
    ov65_0221D674((u8 *)work + 0x444, 1, PTR_AT(work, 0x2228), slot, work);
    {
        u8 *entry = (u8 *)work + selection * 16;
        ov65_0221CA64(work, 3, U8_AT(entry, 0x6a0));
    }
}

void ov65_0221CB5C(void *work) {
    int state = S32_AT(work, 0x94);

    if (state == 12) {
        return;
    }
    if (state < 6) {
        void *mon = Party_GetMonByIndex(PTR_AT(work, 0x2224), state);
        int page = S32_AT(work, 0x94) / 6;

        PTR_AT(work, 0x211c) = ov65_0221D57C(0, mon, (u8 *)work + 0x7fc + page * 0xc80, (u8 *)work + 0x20fc + page * 16);
        ov65_0221D674((u8 *)work + 0x444, 0, PTR_AT(work, 0x2224), S32_AT(work, 0x94), work);
        ov65_0221D8C4((u8 *)work + 0x444, 1, work);
        Sprite_SetDrawFlag(PTR_AT(work, 0x418), FALSE);
    } else {
        ov65_0221CADC(work, state);
        ov65_0221D8C4((u8 *)work + 0x444, 0, work);
        Sprite_SetDrawFlag(PTR_AT(work, 0x414), FALSE);
    }
}

int ov65_0221CC0C(void *work) {
    int (*callback)(void *) = PTR_AT(work, 0x2220);

    if (callback != NULL) {
        U32_AT(work, 0x14c) = callback(work);
    }

    switch (U32_AT(work, 0x14c)) {
    case 0:
    case 1:
        break;
    case 2:
        return 2;
    case 3:
        return 3;
    default:
        break;
    }

    if (ov65_0221DDC0((u8 *)work + 0x158, (u8 *)work + 0x94, PTR_AT(work, 0x344), (u8 *)work + 0x69c, 0)) {
        ov65_0221CB5C(work);
    }
    ov65_0221DDC0((u8 *)work + 0x15c, (u8 *)work + 0x98, PTR_AT(work, 0x348), (u8 *)work + 0x69c, 1);
    ov65_0221DCBC((u8 *)work + 0x9c);
    ov65_0221DE24(work, 0x17, U32_AT(work, 0x94));
    return 1;
}
