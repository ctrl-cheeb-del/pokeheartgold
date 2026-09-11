#include "overlay14_pc_box_move_private.h"

void ov14_021E5EFC(void *p, u32 cursorPos);
u32 ov14_021E5F4C(void *p);
void ov14_021E6048(void *p);
u32 ov14_021E6070(void *p, u32 idx, u32 field, void *dest);
void ov14_021E6094(void *p, u32 idx, u32 field, void *src);
void *ov14_021E60C0(void *p, u32 boxId, u32 idx);
void ov14_021E6100(void *p, u32 boxId, u32 idx);
void ov14_021E611C(void *p, BoxMoveEntry *a, BoxMoveEntry *b);
void ov14_021E6184(void *p, BoxMoveEntry *e);
void ov14_021E61BC(void *p, BoxMoveEntry *e);
void ov14_021E6210(void *p, BoxMoveEntry *e);
void ov14_021E627C(void *p, BoxMoveEntry *e);
void ov14_021E62C8(void *p, BoxMoveEntry *e);
void ov14_021E6318(void *p, BoxMoveEntry *e);
void ov14_021E637C(void *p);
u32 ov14_021E6464(void *p, u32 v);
u32 ov14_021E6480(void *p, u32 skip);
u32 ov14_021E64D0(void *boxmon);
void ov14_021E6548(void *p, u32 a, u32 b);
u32 ov14_021E65C4(void *p);
u32 ov14_021E66F4(void *p);
u32 ov14_021E6814(void *p);
void ov14_021E6CF8(void *p, u32 a, u32 b);
u32 ov14_021E690C(void *p, u32 a, u32 b);
u32 ov14_021E6A3C(void *p, u32 a, u32 b);
u32 ov14_021E6AA0(void *p, u32 a, u32 b);
void ov14_021E6B48(void *p, BoxMoveEntry *e);
void ov14_021E6C0C(void *p, BoxMoveEntry *e);
void ov14_021E6CC8(void *p, u32 a, u32 b);
void ov14_021E6F3C(void *p, u32 a, u32 b);
void ov14_021E7034(void *p, u32 a, u32 b);
u32 ov14_021E70B0(void *p, u32 v);
void ov14_021E70E0(void *p, u32 a);
void ov14_021E7148(void *p, BoxMoveEntry *e);
s32 ov14_021E71C8(u16 v);
void ov14_021E71E8(void *p);

void ov14_021E5EFC(void *p, u32 cursorPos) {
    YesNoTemplate tmpl;
    tmpl.bgConfig = PTR_AT(PTR_AT(p, 0x34), 0x14);
    tmpl.bgId = 0;
    tmpl.tileStart = 0x3AC;
    tmpl.plttSlot = 8;
    tmpl.x = 0x19;
    tmpl.y = 0xC;
    tmpl.ignoreTouchFlag = 0;
    tmpl.initialCursorPos = (u8)cursorPos;
    tmpl.shapeParam = 0;
    YesNoPrompt_InitFromTemplate(PTR_AT(PTR_AT(p, 0x34), 0x434), &tmpl);
}
u32 ov14_021E5F4C(void *p) {
    void *q = PTR_AT(p, 0x34);
    PalFade *f = (PalFade *)((u8 *)q + 0x88D4);
    switch (f->state) {
    case 0:
        if (f->isBg == 0) {
            ManagedSprite_SetPaletteOverride(SPRITE(q, f->index), f->palA);
        } else {
            BgTilemapRectChangePalette(PTR_AT(q, 0x14), f->index, f->x, f->y, f->w, f->h, f->palA);
            ScheduleBgTilemapBufferTransfer(PTR_AT(PTR_AT(p, 0x34), 0x14), f->index);
        }
        f->state++;
        break;
    case 1:
        f->timer++;
        if (f->timer == 4) {
            if (f->isBg == 0) {
                ManagedSprite_SetPaletteOverride(SPRITE(PTR_AT(p, 0x34), f->index), f->palB);
            } else {
                BgTilemapRectChangePalette(PTR_AT(PTR_AT(p, 0x34), 0x14), f->index, f->x, f->y, f->w, f->h, f->palB);
                ScheduleBgTilemapBufferTransfer(PTR_AT(PTR_AT(p, 0x34), 0x14), f->index);
            }
            f->timer = 0;
            f->state++;
        }
        break;
    case 2:
        f->timer++;
        if (f->timer == 2) {
            return 0;
        }
        break;
    }
    return 1;
}
void ov14_021E6048(void *p) {
    if (GridInputHandler_IsButtonInputMode(PTR_AT(PTR_AT(p, 0x34), 0x2C)) == 1) {
        MenuInputStateMgr_SetState(PTR_AT(PTR_AT(p, 0), 4), 0);
    } else {
        MenuInputStateMgr_SetState(PTR_AT(PTR_AT(p, 0), 4), 1);
    }
}
u32 ov14_021E6070(void *p, u32 idx, u32 field, void *dest) {
    void *boxmon = ov14_021E60C0(p, U8_AT(p, 0x1F), idx);
    if (boxmon == NULL) {
        return 0;
    }
    return GetBoxMonData(boxmon, field, dest);
}
void ov14_021E6094(void *p, u32 idx, u32 field, void *src) {
    void *boxmon = ov14_021E60C0(p, U8_AT(p, 0x1F), idx);
    if (boxmon != NULL) {
        SetBoxMonData(boxmon, field, src);
        if (idx < 30) {
            PCStorage_SetBoxModified(PTR_AT(p, 4), U8_AT(p, 0x1F));
        }
    }
}
void *ov14_021E60C0(void *p, u32 boxId, u32 idx) {
    if (boxId == 0xFF || idx >= 30) {
        if (idx >= 30) {
            idx -= 30;
        }
        if (Party_GetCount(PTR_AT(p, 8)) > idx) {
            return Mon_GetBoxMon(Party_GetMonByIndex(PTR_AT(p, 8), idx));
        }
        return NULL;
    }
    if (idx == 0xFF) {
        return NULL;
    }
    return PCStorage_GetMonByIndexPair(PTR_AT(p, 4), boxId, idx);
}
void ov14_021E6100(void *p, u32 boxId, u32 idx) {
    if (idx < 30) {
        PCStorage_DeleteBoxMonByIndexPair(PTR_AT(p, 4), boxId, idx);
    } else {
        Party_RemoveMon(PTR_AT(p, 8), idx - 30);
    }
}
void ov14_021E611C(void *p, BoxMoveEntry *a, BoxMoveEntry *b) {
    u8 mood;
    u32 slot;
    CopyBoxPokemonToPokemon(ov14_021E60C0(p, U8_AT(p, 0x1F), a->from), a->mon);
    slot = b->from - 30;
    CopyPokemonToPokemon(Party_GetMonByIndex(PTR_AT(p, 8), slot), b->mon);
    mood = 0;
    SetMonData(b->mon, MON_DATA_MOOD, &mood);
    Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(PTR_AT(p, 8), slot, a->mon);
    PCStorage_PlaceMonInBoxByIndexPair(PTR_AT(p, 4), U8_AT(p, 0x1F), b->to, Mon_GetBoxMon(b->mon));
    ov14_021F4958(p, U8_AT(p, 0x1F));
    ov14_021F4A20(p, U8_AT(p, 0x1F));
}
void ov14_021E6184(void *p, BoxMoveEntry *e) {
    CopyBoxPokemonToPokemon(ov14_021E60C0(p, U8_AT(p, 0x1F), e->from), e->mon);
    Party_AddMon(PTR_AT(p, 8), e->mon);
    ov14_021E6100(p, U8_AT(p, 0x1F), e->from);
    ov14_021F4958(p, U8_AT(p, 0x1F));
    ov14_021F4A20(p, U8_AT(p, 0x1F));
}
void ov14_021E61BC(void *p, BoxMoveEntry *e) {
    u8 mood;
    void *mon;
    mon = Party_GetMonByIndex(PTR_AT(p, 8), e->from - 30);
    mood = 0;
    SetMonData(mon, MON_DATA_MOOD, &mood);
    PCStorage_PlaceMonInBoxByIndexPair(PTR_AT(p, 4), U8_AT(p, 0x1F), e->to, Mon_GetBoxMon(mon));
    ov14_021E6100(p, U8_AT(p, 0x1F), e->from);
    ov14_021F4958(p, U8_AT(p, 0x1F));
    ov14_021F4A20(p, U8_AT(p, 0x1F));
}
void ov14_021E6210(void *p, BoxMoveEntry *e) {
    PartyExtraSub subA;
    PartyExtraSub subB;
    u32 slotA;
    u32 slotB;
    slotB = e->to - 30;
    slotA = e->from - 30;
    CopyPokemonToPokemon(Party_GetMonByIndex(PTR_AT(p, 8), slotA), e->mon);
    Party_GetMonAprijuiceModifiers(PTR_AT(p, 8), &subA, slotA);
    Party_GetMonAprijuiceModifiers(PTR_AT(p, 8), &subB, slotB);
    Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(PTR_AT(p, 8), slotA, Party_GetMonByIndex(PTR_AT(p, 8), slotB));
    Party_SafeCopyMonToSlot_ResetAprijuiceModifiers(PTR_AT(p, 8), slotB, e->mon);
    Party_SetMonAprijuiceModifiers(PTR_AT(p, 8), &subB, slotA);
    Party_SetMonAprijuiceModifiers(PTR_AT(p, 8), &subA, slotB);
}
void ov14_021E627C(void *p, BoxMoveEntry *e) {
    PartyExtraSub sub;
    u32 slot = e->from - 30;
    u32 last;
    CopyPokemonToPokemon(Party_GetMonByIndex(PTR_AT(p, 8), slot), e->mon);
    Party_GetMonAprijuiceModifiers(PTR_AT(p, 8), &sub, slot);
    ov14_021E6100(p, U8_AT(p, 0x1F), e->from);
    Party_AddMon(PTR_AT(p, 8), e->mon);
    last = Party_GetCount(PTR_AT(p, 8)) - 1;
    Party_SetMonAprijuiceModifiers(PTR_AT(p, 8), &sub, last);
}
void ov14_021E62C8(void *p, BoxMoveEntry *e) {
    void *mon = ov14_021E60C0(p, U8_AT(p, 0x1F), e->from);
    u32 box = ov14_021E6464(p, e->to);
    PCStorage_PlaceMonInBoxFirstEmptySlot(PTR_AT(p, 4), box, mon);
    PCStorage_DeleteBoxMonByIndexPair(PTR_AT(p, 4), U8_AT(p, 0x1F), e->from);
    ov14_021F4958(p, U8_AT(p, 0x1F));
    ov14_021F4A20(p, U8_AT(p, 0x1F));
    ov14_021F4958(p, box);
    ov14_021F4A20(p, box);
}
void ov14_021E6318(void *p, BoxMoveEntry *e) {
    u32 box = ov14_021E6464(p, e->to);
    CopyPokemonToPokemon(Party_GetMonByIndex(PTR_AT(p, 8), e->from - 30), e->mon);
    if (GetMonData(e->mon, 5, NULL) == 492) {
        Mon_UpdateShayminForm(e->mon, 0);
    }
    PCStorage_PlaceMonInBoxFirstEmptySlot(PTR_AT(p, 4), box, Mon_GetBoxMon(e->mon));
    ov14_021E6100(p, U8_AT(p, 0x1F), e->from);
    ov14_021F4958(p, box);
    ov14_021F4A20(p, box);
}
void ov14_021E637C(void *p) {
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    u32 count;
    if (w->from == 0xFF) {
        return;
    }
    count = Party_GetCount(PTR_AT(p, 8));
    if ((w->to & 0x80) != 0) {
        ov14_021E6464(p, w->to);
        if (w->from < 30) {
            ov14_021E62C8(p, &w->entries[0]);
        } else {
            ov14_021E6318(p, &w->entries[w->from - 30]);
        }
    } else if (w->from < 30) {
        if (w->to < 30) {
            PCStorage_SwapMonsInBoxByIndexPair(PTR_AT(p, 4), U8_AT(p, 0x1F), w->from, w->to);
            ov14_021F4958(p, U8_AT(p, 0x1F));
            ov14_021F4A20(p, U8_AT(p, 0x1F));
        } else if (w->to - 30 < count) {
            ov14_021E611C(p, &w->entries[0], &w->entries[1]);
        } else {
            ov14_021E6184(p, &w->entries[0]);
        }
    } else if (w->to < 30) {
        if (ov14_021E6070(p, w->to, 0xAC, NULL) != 0) {
            ov14_021E611C(p, &w->entries[1], &w->entries[0]);
        } else {
            ov14_021E61BC(p, &w->entries[w->from - 30]);
        }
    } else if (w->to - 30 < count) {
        ov14_021E6210(p, &w->entries[0]);
    } else {
        ov14_021E627C(p, &w->entries[w->from - 30]);
    }
}
u32 ov14_021E6464(void *p, u32 v) {
    return (v & 0x7F) + U8_AT(p, 0x25) / 6 * 6;
}
u32 ov14_021E6480(void *p, u32 skip) {
    u32 i;
    void *mon;
    for (i = 0; i < Party_GetCount(PTR_AT(p, 8)); i++) {
        if (i == skip) {
            continue;
        }
        mon = Party_GetMonByIndex(PTR_AT(p, 8), i);
        if (GetMonData(mon, 0x4C, NULL) != 0) {
            continue;
        }
        if (GetMonData(mon, 0xA3, NULL) == 0) {
            continue;
        }
        return 1;
    }
    return 0;
}
u32 ov14_021E64D0(void *boxmon) {
    u16 species = GetBoxMonData(boxmon, 5, NULL);
    u16 form;
    if (species == 493) {
        form = GetBoxMonData(boxmon, 0x70, NULL);
        BoxMon_UpdateArceusForm(boxmon);
        if (form != (u16)GetBoxMonData(boxmon, 0x70, NULL)) {
            return 1;
        }
    } else if (species == 487) {
        form = GetBoxMonData(boxmon, 0x70, NULL);
        BoxMon_UpdateGiratinaForm(boxmon);
        if (form != (u16)GetBoxMonData(boxmon, 0x70, NULL)) {
            return 1;
        }
    }
    return 0;
}
void ov14_021E6548(void *p, u32 a, u32 b) {
    void *q;
    if (a < 30 && b < 30) {
        return;
    }
    if (a >= 30 && b >= 30) {
        return;
    }
    if (a >= 30) {
        a = b;
    }
    if (ov14_021E6070(p, a, 5, NULL) != 492) {
        return;
    }
    if (ov14_021E6070(p, a, 0x70, NULL) == 0) {
        return;
    }
    BoxMon_UpdateShayminForm(ov14_021E60C0(p, U8_AT(p, 0x1F), a), 0);
    q = PTR_AT(p, 0x34);
    ov14_021F2ED0(p, U8_AT(p, 0x1F), a, TBL4094(q, a));
    if (U8_AT(p, 0x21) == a) {
        ov14_021E7588(p, a);
    }
}
u32 ov14_021E65C4(void *p) {
    s16 pos[2];
    u32 j;
    u32 i;
    u32 s;
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    if (w->timer == 8) {
        for (i = 0; i < 7; i++) {
            if (w->entries[i].active != 0) {
                s = TBL4094(PTR_AT(p, 0x34), w->entries[i].from);
                if ((w->entries[i].to & 0x80) == 0) {
                    ov14_021F2F88(w->entries[i].to, &pos[1], &pos[0], U8_AT(p, 0x22));
                } else {
                    if (w->entries[i].from >= 30) {
                        ov14_021F2F88(0x23, &pos[1], &pos[0], U8_AT(p, 0x22));
                    } else {
                        ov14_021F2F88(w->entries[i].from, &pos[1], &pos[0], U8_AT(p, 0x22));
                    }
                    ov14_021F2A18(PTR_AT(p, 0x34), s, 0);
                }
                ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            }
        }
        return 0;
    }
    w->timer++;
    for (j = 0; j < 7; j++) {
        if (w->entries[j].active != 0) {
            s = TBL4094(PTR_AT(p, 0x34), w->entries[j].from);
            pos[1] = w->entries[j].px + (w->entries[j].dx * w->timer >> 16) * w->entries[j].sx;
            pos[0] = w->entries[j].py + (w->entries[j].dy * w->timer >> 16) * w->entries[j].sy;
            ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            ov14_021F3190(PTR_AT(p, 0x34), w->entries[j].from, 0);
        }
    }
    return 1;
}
u32 ov14_021E66F4(void *p) {
    s16 pos[2];
    u32 i;
    u32 s;
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    if (w->timer == 8) {
        for (i = 0; i < 7; i++) {
            if (w->entries[i].active != 0) {
                s = TBL4094(PTR_AT(p, 0x34), w->entries[i].from);
                ov14_021F2F88(w->entries[i].to, &pos[1], &pos[0], U8_AT(p, 0x22));
                if (U8_AT(p, 0x21) != w->entries[i].to) {
                    pos[0] += 0x90;
                }
                ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            }
        }
        return 0;
    }
    w->timer++;
    for (i = 0; i < 7; i++) {
        if (w->entries[i].active != 0 && U8_AT(p, 0x21) == w->entries[i].to) {
            s = TBL4094(PTR_AT(p, 0x34), w->entries[i].from);
            pos[1] = w->entries[i].px + (w->entries[i].dx * w->timer >> 16) * w->entries[i].sx;
            pos[0] = w->entries[i].py + (w->entries[i].dy * w->timer >> 16) * w->entries[i].sy;
            ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            ov14_021F3190(PTR_AT(p, 0x34), w->entries[i].from, 0);
            break;
        }
    }
    return 1;
}
u32 ov14_021E6814(void *p) {
    s16 pos[2];
    u32 j;
    u32 i;
    u32 s;
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    if (w->timer == 8) {
        for (i = 0; i < 7; i++) {
            if (w->entries[i].active != 0) {
                s = TBL4094(PTR_AT(p, 0x34), w->entries[i].from);
                ov14_021F2F88(w->entries[i].to, &pos[1], &pos[0], U8_AT(p, 0x22));
                ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            }
        }
        return 0;
    }
    w->timer++;
    for (j = 0; j < 7; j++) {
        if (w->entries[j].active != 0) {
            s = TBL4094(PTR_AT(p, 0x34), w->entries[j].from);
            pos[1] = w->entries[j].px + (w->entries[j].dx * w->timer >> 16) * w->entries[j].sx;
            pos[0] = w->entries[j].py + (w->entries[j].dy * w->timer >> 16) * w->entries[j].sy;
            ManagedSprite_SetPositionXY(SPRITE(PTR_AT(p, 0x34), s), pos[1], pos[0]);
            ov14_021F31E0(PTR_AT(p, 0x34), w->entries[j].from, w->entries[j].to);
        }
    }
    return 1;
}
u32 ov14_021E690C(void *p, u32 a, u32 b) {
    u32 box;
    u32 t;
    void *mon;
    ov14_021E6070(p, b, 0xAC, NULL);
    if ((b & 0x80) != 0) {
        box = ov14_021E6464(p, b);
        if (box == U8_AT(p, 0x1F) || PCStorage_CountMonsAndEggsInBox(PTR_AT(p, 4), box) == 30) {
            return 0;
        }
        b ^= 0x80;
        t = 0;
    } else {
        box = U8_AT(p, 0x1F);
        t = ov14_021E6070(p, b, 0xAC, NULL);
    }
    if (a >= 30) {
        if (ov14_021E6480(p, a - 30) == 0) {
            if (t == 0) {
                if (b < 30 || box != U8_AT(p, 0x1F)) {
                    return 0;
                }
            } else if (ov14_021E6070(p, b, 0x4C, NULL) != 0 && b < 30) {
                return 0;
            }
        }
        if (b < 30) {
            mon = Party_GetMonByIndex(PTR_AT(p, 8), a - 30);
            if (ItemIdIsMail((u16)GetMonData(mon, 6, NULL)) == 1) {
                return 0;
            }
            if (GetMonData(mon, 0xA2, NULL) != 0) {
                return 0;
            }
        }
    } else if (b >= 30 && t != 0) {
        mon = Party_GetMonByIndex(PTR_AT(p, 8), b - 30);
        if (ItemIdIsMail((u16)GetMonData(mon, 6, NULL)) == 1) {
            return 0;
        }
        if (GetMonData(mon, 0xA2, NULL) != 0) {
            return 0;
        }
        if (ov14_021E6070(p, a, 0x4C, NULL) != 0 && ov14_021E6480(p, b - 30) == 0) {
            return 0;
        }
    }
    return 1;
}
u32 ov14_021E6A3C(void *p, u32 a, u32 b) {
    void *mon;
    if (ov14_021E6070(p, b, 0xAC, NULL) != 0) {
        return 0;
    }
    if (ov14_021E6480(p, a - 30) == 0) {
        return 0;
    }
    mon = Party_GetMonByIndex(PTR_AT(p, 8), a - 30);
    if (ItemIdIsMail((u16)GetMonData(mon, 6, NULL)) == 1) {
        return 0;
    }
    if (GetMonData(mon, 0xA2, NULL) != 0) {
        return 0;
    }
    return 1;
}
u32 ov14_021E6AA0(void *p, u32 a, u32 b) {
    u16 itemA;
    u16 itemB;
    if (ov14_021E6070(p, b, 0xAC, NULL) == 0) {
        return 0;
    }
    if (ov14_021E6070(p, b, 0x4C, NULL) != 0) {
        return 0;
    }
    itemA = ov14_021E6070(p, a, 6, NULL);
    if (ItemIdIsMail(itemA) == 1) {
        return 0;
    }
    itemB = ov14_021E6070(p, b, 6, NULL);
    if (ItemIdIsMail(itemB) == 1) {
        return 0;
    }
    if (itemA == 0x70 && ov14_021E6070(p, b, 5, NULL) != 487) {
        return 0;
    }
    if (itemB == 0x70 && ov14_021E6070(p, a, 5, NULL) != 487) {
        return 0;
    }
    return 1;
}
void ov14_021E6B48(void *p, BoxMoveEntry *e) {
    s16 pos[2];
    void *q = PTR_AT(p, 0x34);
    ManagedSprite_GetPositionXY(SPRITE(q, TBL4094(q, e->from)), &e->px, &e->py);
    if ((e->to & 0x80) == 0) {
        ov14_021F2F88(e->to, &pos[1], &pos[0], U8_AT(p, 0x22));
    } else {
        ov14_021F4940(PTR_AT(p, 0x34), e->to & 0x7F, &pos[1], &pos[0]);
    }
    if (e->px <= pos[1]) {
        e->sx = 1;
        e->dx = ((pos[1] - e->px) << 16) / 8;
    } else {
        e->sx = -1;
        e->dx = ((e->px - pos[1]) << 16) / 8;
    }
    if (e->py <= pos[0]) {
        e->sy = 1;
        e->dy = ((pos[0] - e->py) << 16) / 8;
    } else {
        e->sy = -1;
        e->dy = ((e->py - pos[0]) << 16) / 8;
    }
}
void ov14_021E6C0C(void *p, BoxMoveEntry *e) {
    s16 pos[2];
    void *q = PTR_AT(p, 0x34);
    u32 j = TBL4094(q, e->to);
    ManagedSprite_GetPositionXY(SPRITE(q, TBL4094(q, e->from)), &e->px, &e->py);
    ManagedSprite_GetPositionXY(SPRITE(PTR_AT(p, 0x34), j), &pos[1], &pos[0]);
    if (e->px <= pos[1]) {
        e->sx = 1;
        e->dx = ((pos[1] - e->px) << 16) / 8;
    } else {
        e->sx = -1;
        e->dx = ((e->px - pos[1]) << 16) / 8;
    }
    if (e->py <= pos[0]) {
        e->sy = 1;
        e->dy = ((pos[0] - e->py) << 16) / 8;
    } else {
        e->sy = -1;
        e->dy = ((e->py - pos[0]) << 16) / 8;
    }
}
void ov14_021E6CC8(void *p, u32 a, u32 b) {
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    w->entries[0].from = a;
    w->entries[0].to = b;
    w->entries[0].active = 1;
    ov14_021E6B48(p, &w->entries[0]);
    w->entries[1].from = b;
    w->entries[1].to = a;
    w->entries[1].active = 1;
    ov14_021E6B48(p, &w->entries[1]);
}
void ov14_021E6CF8(void *p, u32 a, u32 b) {
    BoxMoveWork *w;
    u32 sA;
    u32 sC;
    u32 sB;
    u32 i;
    u32 count;
    w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    U32_AT(PTR_AT(p, 0x34), 0x40C4) = 1;
    for (i = 0; i < 7; i++) {
        w->entries[i].from = 0;
        w->entries[i].to = 0;
        w->entries[i].active = 0;
    }
    w->sel = b;
    if (b == 0xFF || a == b || ov14_021E690C(p, a, b) == 0) {
        w->from = 0xFF;
        w->to = 0xFF;
        w->entries[0].from = a;
        w->entries[0].to = a;
        w->entries[0].active = 1;
        ov14_021E6B48(p, &w->entries[0]);
        return;
    }
    w->from = a;
    w->to = b;
    count = Party_GetCount(PTR_AT(p, 8));
    if ((b & 0x80) != 0) {
        if (a < 30) {
            w->entries[0].from = a;
            w->entries[0].to = b;
            w->entries[0].active = 1;
            ov14_021E6B48(p, &w->entries[0]);
            U32_AT(PTR_AT(p, 0x34), 0x40C4) = 0;
            return;
        }
        sA = a - 30;
        for (i = sA + 1; i < 6; i++) {
            w->entries[i].from = i + 30;
            w->entries[i].to = i + 29;
            w->entries[i].active = 1;
            ov14_021E6B48(p, &w->entries[i]);
        }
        w->entries[sA].from = a;
        w->entries[sA].to = b;
        w->entries[sA].active = 1;
        ov14_021E6B48(p, &w->entries[sA]);
        U32_AT(PTR_AT(p, 0x34), 0x40C4) = 0;
        return;
    }
    if (a < 30) {
        if (b < 30) {
            ov14_021E6CC8(p, a, b);
            return;
        }
        if (b - 30 < count) {
            ov14_021E6CC8(p, a, b);
            return;
        }
        ov14_021E6CC8(p, a, count + 30);
        return;
    }
    if (b < 30) {
        if (ov14_021E6070(p, b, 0xAC, NULL) != 0) {
            ov14_021E6CC8(p, a, b);
            return;
        }
        sB = a - 30;
        for (i = sB + 1; i < count; i++) {
            w->entries[i].from = i + 30;
            w->entries[i].to = i + 29;
            w->entries[i].active = 1;
            ov14_021E6B48(p, &w->entries[i]);
        }
        w->entries[sB].from = a;
        w->entries[sB].to = b;
        w->entries[sB].active = 1;
        ov14_021E6B48(p, &w->entries[sB]);
        w->entries[count].from = b;
        w->entries[count].to = count + 29;
        w->entries[count].active = 1;
        ov14_021E6B48(p, &w->entries[count]);
        return;
    }
    if (b - 30 < count) {
        ov14_021E6CC8(p, a, b);
        return;
    }
    sC = a - 30;
    for (i = sC + 1; i < count; i++) {
        w->entries[i].from = i + 30;
        w->entries[i].to = i + 29;
        w->entries[i].active = 1;
        ov14_021E6B48(p, &w->entries[i]);
    }
    w->entries[sC].from = a;
    w->entries[sC].to = count + 29;
    w->entries[sC].active = 1;
    ov14_021E6B48(p, &w->entries[sC]);
}
void ov14_021E6F3C(void *p, u32 a, u32 b) {
    BoxMoveWork *w;
    u32 slot;
    u32 i;
    u32 count;
    w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    U32_AT(PTR_AT(p, 0x34), 0x40C4) = 1;
    for (i = 0; i < 7; i++) {
        w->entries[i].from = 0;
        w->entries[i].to = 0;
        w->entries[i].active = 0;
    }
    if (b == 0xFF || ov14_021E6A3C(p, a, b) == 0) {
        w->from = 0xFF;
        w->to = 0xFF;
        w->entries[0].from = a;
        w->entries[0].to = a;
        w->entries[0].active = 1;
        ov14_021E6B48(p, &w->entries[0]);
        return;
    }
    w->from = a;
    w->to = b;
    count = Party_GetCount(PTR_AT(p, 8));
    if (b < 30) {
        slot = a - 30;
        for (i = slot + 1; i < count; i++) {
            w->entries[i].from = i + 30;
            w->entries[i].to = i + 29;
            w->entries[i].active = 1;
            ov14_021E6C0C(p, &w->entries[i]);
        }
        w->entries[slot].from = a;
        w->entries[slot].to = b;
        w->entries[slot].active = 1;
        ov14_021E6C0C(p, &w->entries[slot]);
        w->entries[count].from = b;
        w->entries[count].to = count + 29;
        w->entries[count].active = 1;
        ov14_021E6C0C(p, &w->entries[count]);
        U32_AT(PTR_AT(p, 0x34), 0x40C4) = 0;
    }
}
void ov14_021E7034(void *p, u32 a, u32 b) {
    void *q = PTR_AT(p, 0x34);
    BoxMoveWork *w = PTR_AT(q, 0xC);
    u32 i;
    U32_AT(q, 0x40C4) = 1;
    for (i = 0; i < 7; i++) {
        w->entries[i].from = 0;
        w->entries[i].to = 0;
        w->entries[i].active = 0;
    }
    if (b == 0xFF || ov14_021E6070(p, b, 0xAC, NULL) != 0) {
        w->from = 0xFF;
        w->to = 0xFF;
        w->entries[0].from = a;
        w->entries[0].to = a;
        w->entries[0].active = 1;
        ov14_021E6B48(p, &w->entries[0]);
    } else {
        w->from = a;
        w->to = b;
        ov14_021E6CC8(p, a, Party_GetCount(PTR_AT(p, 8)) + 30);
    }
}
u32 ov14_021E70B0(void *p, u32 v) {
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    u32 i;
    for (i = 0; i < 7; i++) {
        if (w->entries[i].active == 1 && w->entries[i].from == v) {
            return w->entries[i].to;
        }
    }
    return 0xFF;
}
void ov14_021E70E0(void *p, u32 a) {
    BoxMoveWork *w = PTR_AT(PTR_AT(p, 0x34), 0xC);
    u32 i;
    u32 slot = a - 30;
    for (i = 0; i < 6; i++) {
        w->entries[i].from = i + 30;
        w->entries[i].to = i + 30;
        w->entries[i].active = 0;
    }
    w->entries[i].active = 0;
    for (i = slot + 1; i < 6; i++) {
        w->entries[i].to = i + 29;
        w->entries[i].active = 1;
        ov14_021E6B48(p, &w->entries[i]);
    }
    w->entries[slot].to = 0x23;
    w->entries[slot].active = 1;
    ov14_021E6B48(p, &w->entries[slot]);
}
void ov14_021E7148(void *p, BoxMoveEntry *e) {
    u8 tmp[7];
    u32 i;
    for (i = 0; i < 7; i++) {
        if (e[i].active != 0) {
            tmp[i] = TBL4094(PTR_AT(p, 0x34), e[i].from);
        }
    }
    for (i = 0; i < 7; i++) {
        if (e[i].active != 0) {
            if ((e[i].to & 0x80) == 0) {
                TBL4094(PTR_AT(p, 0x34), e[i].to) = tmp[i];
                ov14_021F3190(PTR_AT(p, 0x34), e[i].to, 1);
            } else {
                if (e[i].from >= 30) {
                    U8_AT(PTR_AT(p, 0x34), 0x40B7) = tmp[i];
                }
                ov14_021F3190(PTR_AT(p, 0x34), e[i].from, 1);
            }
        }
    }
}
s32 ov14_021E71C8(u16 v) {
    u32 i;
    for (i = 0; i < 4; i++) {
        if (v == ov14_021F7BC0[i]) {
            return i;
        }
    }
    return -1;
}
void ov14_021E71E8(void *p) {
    void *q;
    void *r;
    void *boxmon;
    u32 i;
    s32 idx;
    U32_AT(PTR_AT(p, 0x34), 0x88DC) = (u32)Heap_AllocAtEnd(10, 12);
    q = PTR_AT(p, 0x34);
    r = PTR_AT(q, 0x88DC);
    PTR_AT(r, 0) = SPRITE(q, TBL4094(q, U8_AT(p, 0x21)));
    U16_AT(r, 4) = 0;
    U8_AT(r, 6) = 0;
    boxmon = ov14_021E60C0(p, U8_AT(p, 0x1F), U8_AT(p, 0x21));
    for (i = 0; i < 4; i++) {
        idx = ov14_021E71C8((u16)GetBoxMonData(boxmon, i + 0x36, NULL));
        if (idx != -1) {
            U8_AT(r, 6) |= 1 << idx;
            return;
        }
    }
}
