#include "to47_overlay70_box_graphics_r21_private.h"



void ov70_0223E120(Ov70Work *w) {
    int i;
    Ov70MonGfx *p = w->gfx;
    for (i = 0; i < 30; i++) {
        if (p->sprite != NULL) {
            DC_FlushRange(p->buf, 0x200);
            GX_LoadOBJ(p->buf, p->offset, 0x200);
            Sprite_SetPaletteOverride(p->sprite, p->palette);
        }
        p++;
    }
    Heap_Free(w->gfx);
}

void ov70_0223E170(void *boxmon, void *spriteA, void *spriteB, u16 *species, int index, void *narc, Ov70BoxEntry *entry, Ov70MonGfx *gfx) {
    u32 exists;
    u32 item;
    u32 egg;
    u32 form;

    AcquireBoxMonLock(boxmon);
    exists = GetBoxMonData(boxmon, 0xac, NULL);
    *species = GetBoxMonData(boxmon, 5, NULL);
    form = GetBoxMonData(boxmon, 0x70, NULL);
    egg = GetBoxMonData(boxmon, 0x4c, NULL);
    item = GetBoxMonData(boxmon, 6, NULL);
    entry->species = *species;
    entry->unk2 = GetBoxMonData(boxmon, 0x6f, NULL) + 1;
    if (egg != 0) {
        entry->unk3 = 0;
    }
    ReleaseBoxMonLock(boxmon, 1);
    if (exists != 0) {
        ov70_0223E0BC(*species, form, egg, index, spriteA, narc, gfx);
        Sprite_SetDrawFlag(spriteA, 1);
        if (item != 0) {
            Sprite_SetDrawFlag(spriteB, 1);
            if (ItemIdIsMail((u16)item)) {
                Sprite_SetAnimCtrlSeq(spriteB, 41);
            } else {
                Sprite_SetAnimCtrlSeq(spriteB, 40);
            }
        } else {
            Sprite_SetDrawFlag(spriteB, 0);
        }
    } else {
        Sprite_SetDrawFlag(spriteA, 0);
        Sprite_SetDrawFlag(spriteB, 0);
        gfx->sprite = NULL;
    }
}

void ov70_0223E264(Ov70Work *w, int box) {
    void *pcStorage = PTR(w->sub, 0xc);
    void *narc;
    Ov70MonGfx *gfx;
    u16 i;
    u16 species[30];

    gfx = (Ov70MonGfx *)Heap_AllocAtEnd(3, sizeof(Ov70MonGfx) * 30);
    w->gfx = gfx;
    narc = NARC_New(20, 61);
    if (box >= 0 && box < 18) {
        for (i = 0; i < 30; i++) {
            ov70_0223E114(PCStorage_GetMonByIndexPair(pcStorage, box, i), (u8 *)&w->entries[i]);
        }
        for (i = 0; i < 30; i++) {
            w->entries[i].species = 0;
            ov70_0223E170(PCStorage_GetMonByIndexPair(pcStorage, box, i),
                          w->spritesA[i], w->spritesB[i],
                          &species[i], i, narc, &w->entries[i], &gfx[i]);
            if (i < 6) {
                Sprite_SetDrawFlag(w->spritesC[i], 0);
            }
        }
        PCStorage_GetBoxName(pcStorage, box, w->str);
    } else {
        int count = Party_GetCount(PTR(w->sub, 8));
        for (i = 0; i < count; i++) {
            void *mon = Party_GetMonByIndex(PTR(w->sub, 8), i);
            void *bm = Mon_GetBoxMon(mon);
            ov70_0223E114(bm, (u8 *)&w->entries[i]);
            ov70_0223E170(bm, w->spritesA[i], w->spritesB[i],
                          &species[i], i, narc, &w->entries[i], &gfx[i]);
            if (GetMonData(mon, 0xa2, NULL) != 0) {
                Sprite_SetDrawFlag(w->spritesC[i], 1);
            } else {
                Sprite_SetDrawFlag(w->spritesC[i], 0);
            }
        }
        for (; i < 30; i++) {
            w->entries[i].species = 0;
            Sprite_SetDrawFlag(w->spritesA[i], 0);
            Sprite_SetDrawFlag(w->spritesB[i], 0);
            gfx[i].sprite = NULL;
            if (i < 6) {
                Sprite_SetDrawFlag(w->spritesC[i], 0);
            }
        }
        ReadMsgDataIntoString(w->msgData, 92, w->str);
    }
    NARC_Delete(narc);
    FillWindowPixelBuffer(w->window, 0);
    ov70_02245084(w->window, w->str, 0, 5, 1, 0x10200);
    if (w->mode == 6) {
        ov70_0223E738(w->entries, w->spritesA, (u8 *)w + 0x350 + 0x124 * w->index, gfx);
    }
    w->callback = (void *)ov70_0223E120;
}
