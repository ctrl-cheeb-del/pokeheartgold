#include "overlay81_box_icons_r14r5_private.h"
#define U32(w, o) (*(u32 *)((w)->d + (o)))
#define U16(w, o) (*(u16 *)((w)->d + (o)))
void ov81_0224218C(Work *w) {
    u16 i = 3;
    do {
        u8 n = (u8)(i - 3);
        if (n < w->d[0x11]) {
            u8 *entry = w->d + n * 2;
            u16 value = *(u16 *)(entry + 0x3c8);
            u8 *object = w->d + value * 4;
            VecFx32 pos = *(VecFx32 *)ov81_02242F30((void *)*(u32 *)(object + 0x360));
            pos.x -= 0x4000;
            pos.y += 0x4000;
            {
                u8 *sprite = w->d + i * 4;
                ov81_02242DCC((void *)*(u32 *)(sprite + 0x3a8), &pos);
                ov81_02242D88((void *)*(u32 *)(sprite + 0x3a8), TRUE);
            }
        } else {
            u8 *sprite = w->d + i * 4;
            ov81_02242D88((void *)*(u32 *)(sprite + 0x3a8), FALSE);
        }
        i++;
    } while (i < 6);
}
void ov81_02242218(Work *w, Party *party, u32 index, u32 limit) {
    Pokemon *mon;
    u16 species;
    u16 form;
    u32 fileId;
    u32 palette;
    void *buffer;
    NNSG2dCharacterData *charData;
    void *sprite;

    if (index >= limit) {
        return;
    }
    mon = Party_GetMonByIndex(party, index);
    species = (u16)GetMonData(mon, 5, NULL);
    form = (u16)GetMonData(mon, 0x70, NULL);
    fileId = GetMonIconNaixEx(species, FALSE, form);
    buffer = GfGfxLoader_GetCharData((NarcId)0x14, fileId, FALSE, &charData, (enum HeapID)0x64);
    sprite = (void *)U32(w, 0x394 + U32(w, 0x480) * 4);
    ov81_02242E14(sprite, charData->pRawData, 0x200, 2);
    Heap_Free(buffer);
    palette = GetMonIconPaletteEx(species, form, FALSE);
    ov81_02242E08((void *)U32(w, 0x394 + U32(w, 0x480) * 4), palette);
    ov81_02242D88((void *)U32(w, 0x394 + U32(w, 0x480) * 4), TRUE);
    U32(w, 0x480) ^= 1;
    sprite = (void *)U32(w, 0x394 + U32(w, 0x480) * 4);
    ov81_02242D88(sprite, FALSE);
    ov81_022409B0(w, w->d + 0xD0, (u8)index, 4, 0, 15, 2, 0, 0, party);
}
void ov81_02242300(Work *w, u32 target, u32 limit) {
    u16 i;
    volatile BOOL found;
    s32 count;
    if (target >= limit) {
        return;
    }
    i = 0;
    found = FALSE;
    count = *(volatile u8 *)(w->d + 0x11);
    if (count > 0) {
        do {
            u8 *p = w->d + i * 2;
            u16 value = *(u16 *)(p + 0x3c8);
            if (target == value) {
                found = TRUE;
            }
            ov81_022409B0(w, w->d + 0x50 + (i + 2) * 0x10, (u8)value, 4, 0, 15, 2, 0, 0, (void *)U32(w, 0x3c0));
            i++;
        } while (i < w->d[0x11]);
    }
    if (!found) {
        ov81_022409B0(w, w->d + 0x50 + (i + 2) * 0x10, (u8)target, 4, 0, 15, 2, 0, 0, (void *)U32(w, 0x3c0));
        i++;
    }
    if (i < U32(w, 0x47c)) {
        u8 *base = w->d + 0x50;
        do {
            u32 off = (i + 2) * 0x10;
            FillWindowPixelBuffer((Window *)(base + off), 0);
            ScheduleWindowCopyToVram((Window *)(base + off));
            i++;
        } while (i < U32(w, 0x47c));
    }
}
void ov81_022423D0(Work *w, void *arg) {
    u32 i = 0;
    if (i < U32(w, 0x47c)) {
        do {
            ov81_022409B0(w, w->d + 0x50 + (i + 2) * 0x10, (u8)i, 4, 0, 15, 2, 0, 0, arg);
            i++;
        } while (i < U32(w, 0x47c));
    }
}
void ov81_02242420(Work *w, u32 value) {
    u32 i = 0;
    if (i < U32(w, 0x47c)) {
        u8 *base = w->d;
        u32 tmp = value << 24;
        base += 0x50;
        value = tmp >> 24;
        do {
            if (U16(w, 0x3c8) == i) {
                ov81_022409B0(w, base + (i + 2) * 0x10, (u8)value, 4, 0, 15, 2, 0, 0, (void *)U32(w, 0x3c4));
            } else {
                ov81_022409B0(w, base + (i + 2) * 0x10, (u8)i, 4, 0, 15, 2, 0, 0, (void *)U32(w, 0x3c0));
            }
            i++;
        } while (i < U32(w, 0x47c));
    }
}
void ov81_022424AC(Work *w, u32 value) {
    u32 idx = U16(w, 0x3c8) + 2;
    if (value >= 4) {
        ClearWindowTilemapAndScheduleTransfer((Window *)(w->d + 0x50 + idx * 0x10));
    } else {
        u32 off = idx * 0x10;
        ov81_022409B0(w, w->d + 0x50 + off, (u8)value, 4, 0, 15, 2, 0, 0, (void *)U32(w, 0x3c4));
        ScheduleWindowCopyToVram((Window *)(w->d + 0x50 + off));
    }
}
