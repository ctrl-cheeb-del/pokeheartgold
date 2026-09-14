#include "overlay96_course_ui_r90_gap2_private.h"

void ov96_02207DDC(Ov96R90Work *work) {
    GfGfxLoader_LoadCharData((NarcId)0xE2, 5, work->bgConfig, (GFBgLayer)5, 0, 0, FALSE, work->heapId);
    GfGfxLoader_LoadCharData((NarcId)0xE2, 6, work->bgConfig, (GFBgLayer)6, 0, 0x2000, FALSE, work->heapId);
    GfGfxLoader_LoadScrnData((NarcId)0xE2, 7, work->bgConfig, (GFBgLayer)5, 0, 0, FALSE, work->heapId);
    GfGfxLoader_LoadScrnData((NarcId)0xE2, 8, work->bgConfig, (GFBgLayer)6, 0, 0, FALSE, work->heapId);
    work->tileData = GfGfxLoader_GetScrnData((NarcId)0xE2, 9, FALSE, &work->screenData, work->heapId);
    GfGfxLoader_GXLoadPal((NarcId)0xE2, 4, (enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0, 0x40, work->heapId);
    ov96_02208374(work, 0);
}

void ov96_02207E7C(void *unused, void *sprites) {
    u32 ids[2];
    u32 *id = ids;
    int i;

#pragma unused(unused)
    ids[0] = ov96_0221CBCC[2];
    ids[1] = ov96_0221CBCC[3];
    for (i = 0; i < 2; i++) {
        ov96_021EB2BC(sprites, 0x5D, 9, *id, 2);
        ov96_021EB2F4(sprites, 0x5D, 6, *id, 2, 1);
        ov96_021EB334(sprites, 0x5D, 10, *id);
        ov96_021EB36C(sprites, 0x5D, 10, *id);
        id++;
    }
    ov96_021EB2BC(sprites, 0xE2, 13, 0x65, 2);
    ov96_021EB2F4(sprites, 0xE2, 10, 0x65, 2, 8);
    ov96_021EB334(sprites, 0xE2, 12, 0x65);
    ov96_021EB36C(sprites, 0xE2, 11, 0x65);
}

void ov96_02207F18(Ov96R90Work *work, void *sprites, void *resources) {
    int participant;
    int i;
    Ov96R90Work *participantWork;
    Sprite **action;
    Sprite **choice;
    VecFx32 digitPosition;
    VecFx32 initialPosition;

    participant = 0;
    participantWork = work;
    action = work->actionSprites[0];
    choice = work->choiceSprites[0];
    for (; participant < 4; participant++) {
        participantWork->participant[0].sprite38 = ov96_021EB3E4(sprites, 3, 2, 0x65, 2);
        participantWork->participant[0].sprite40 = ov96_021EB3E4(sprites, 3, 2, 0x65, 3);
        participantWork->participant[0].sprite3C = ov96_021EB3E4(sprites, 3, 2, 0x65, 10);
        action[2] = ov96_021EB3E4(sprites, 2, 2, 0x65, 19);
        ov96_021EB564(action[2], 0);
        ov96_021EB52C(action[2], 1, 1);
        action[1] = ov96_021EB3E4(sprites, 2, 2, 0x65, 21);
        ov96_021EB564(action[1], 9);
        ov96_021EB52C(action[1], 1, 1);
        action[0] = ov96_021EB3E4(sprites, 2, 2, 0x65, 20);
        ov96_021EB564(participantWork->participant[0].sprite38, participant + 19);
        ov96_021EB564(participantWork->participant[0].sprite40, participant + 5);
        ov96_021EB564(action[0], 3);
        ov96_021EB52C(action[0], 1, 1);
        for (i = 0; i < 2; i++) {
            choice[i] = ov96_021EB3E4(sprites, 2, 2, 0x65, 24);
            ov96_021EB564(choice[i], 2);
        }
        participantWork = (Ov96R90Work *)((u8 *)participantWork + 0x1C);
        action += 4;
        choice += 2;
    }
    initialPosition = ov96_0221CBF4;
    work->specialSprite = ov96_021EB3E4(sprites, 3, 2, 0x65, 22);
    ov96_021EB564(work->specialSprite, 4);
    ov96_021EB52C(work->specialSprite, 1, 1);
    ov96_021EB588(work->specialSprite, &initialPosition);
    ov96_02208914(sprites, work);
    for (i = 0; i < 2; i++) {
        work->digitSprites[i] = ov96_021EA2C4(resources, ov96_021EB5E8(sprites), 3, work->heapId);
        Sprite_SetDrawFlag(work->digitSprites[i], TRUE);
        digitPosition.x = ov96_0221CBC4[i] << FX32_SHIFT;
        digitPosition.y = 0x2C4000;
        digitPosition.z = 0;
        Sprite_SetMatrix(work->digitSprites[i], &digitPosition);
        Sprite_SetAnimCtrlSeq(work->digitSprites[i], ov96_0221CBC8[i]);
    }
}

void ov96_022080F4(Ov96R90Work *work, const Ov96R90Mon *mons) {
    NARC *volatile narc;
    volatile int x;
    Ov96R90Work *volatile choiceWork;
    u32 iconNarc;
    int i;
    u8 *rawBase;
    Ov96R90Graphic **graphic;
    Ov96R90Work *participantWork;
    Ov96R90Work *actionWork;
    VecFx32 position;
    struct {
        u32 species;
        u32 form;
    } current;

    narc = NARC_New(NARC_poketool_icongra_poke_icon, work->heapId);
    iconNarc = sub_02074490();
    GfGfxLoader_GXLoadPal(NARC_poketool_icongra_poke_icon, iconNarc, GF_PAL_LOCATION_SUB_OBJ, GF_PAL_SLOT_6_OFFSET, 0x60, work->heapId);
    rawBase = (u8 *)work;
    i = 0;
    graphic = work->graphics;
    for (; i < 12; i++) {
        *(void **)(rawBase + 0x9C) = Heap_AllocAtEnd(work->heapId, 0x1000);
        current.form = (u8)mons->form;
        current.species = mons->species;
        NARC_ReadWholeMember(narc, GetMonIconNaixEx(current.species, FALSE, current.form), *(void **)(rawBase + 0x9C));
        NNS_G2dGetUnpackedBGCharacterData(*(void **)(rawBase + 0x9C), (NNSG2dCharacterData **)graphic);
        work->palette[i] = GetMonIconPaletteEx(current.species, current.form, FALSE) + 6;
        rawBase += 4;
        mons++;
        graphic++;
    }
    NARC_Delete(narc);

    i = 0;
    participantWork = work;
    x = 0x70;
    choiceWork = work;
    actionWork = work;
    for (; i < 4; i++) {
        ov96_0220831C(work, (u8)i, 0);
        ov96_021EB52C(participantWork->participant[0].sprite38, 1, 1);
        ov96_021EB52C(participantWork->participant[0].sprite40, 1, 1);
        position.z = 0;
        position.x = x << FX32_SHIFT;
        position.y = 0x350000;
        ov96_021EB588(participantWork->participant[0].sprite38, &position);
        ov96_021EB588(participantWork->participant[0].sprite40, &position);
        ov96_021EB588(participantWork->participant[0].sprite3C, &position);
        {
            int j;
            Ov96R90Work *choiceCursor = choiceWork;
            for (j = 0; j < 2; j++) {
                ov96_021EB588(choiceCursor->choiceSprites[0][0], &position);
                choiceCursor = (Ov96R90Work *)((u8 *)choiceCursor + 4);
            }
        }
        position.y -= 0x20000;
        ov96_021EB588(actionWork->actionSprites[0][0], &position);
        ov96_021EB588(actionWork->actionSprites[0][1], &position);
        ov96_021EB588(actionWork->actionSprites[0][2], &position);
        participantWork = (Ov96R90Work *)((u8 *)participantWork + 0x1C);
        x += 0x28;
        actionWork = (Ov96R90Work *)((u8 *)actionWork + 0x10);
        choiceWork = (Ov96R90Work *)((u8 *)choiceWork + 8);
    }
}
