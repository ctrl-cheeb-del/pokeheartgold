#include "pokeathlon/pokeathlon_box.h"

extern void GF_AssertFail(void);

void ov97_0221F5F8(PokeathlonBox_SubGraphics *subGraphics, PokeathlonBox_UnkStruct0221EC14 *mon) {
    u8 i;
    u8 j;

    for (i = 0; i < 5; i++) {
        const u8 *entry = (const u8 *)mon + i * 8;
        s8 direction = *(const s8 *)(entry + 0x28);

        if (direction > 0) {
            Sprite_SetDrawFlag(*(Sprite **)((u8 *)subGraphics + i * 0x18 + 0x1dc), 1);
            Sprite_SetAnimCtrlSeq(*(Sprite **)((u8 *)subGraphics + i * 0x18 + 0x1dc), 4);
        } else if (direction < 0) {
            Sprite_SetDrawFlag(*(Sprite **)((u8 *)subGraphics + i * 0x18 + 0x1dc), 1);
            Sprite_SetAnimCtrlSeq(*(Sprite **)((u8 *)subGraphics + i * 0x18 + 0x1dc), 5);
        } else {
            Sprite_SetDrawFlag(*(Sprite **)((u8 *)subGraphics + i * 0x18 + 0x1dc), 0);
        }

        for (j = 0; j < 5; j++) {
            switch (entry[0x29 + j]) {
            case 0:
                Sprite_SetDrawFlag(subGraphics->unk1DC[i].sprites[j], 0);
                break;
            case 1:
                Sprite_SetDrawFlag(subGraphics->unk1DC[i].sprites[j], 1);
                Sprite_SetAnimCtrlSeq(subGraphics->unk1DC[i].sprites[j], 3);
                break;
            case 2:
                Sprite_SetDrawFlag(subGraphics->unk1DC[i].sprites[j], 1);
                Sprite_SetAnimCtrlSeq(subGraphics->unk1DC[i].sprites[j], 0);
                break;
            case 3:
                Sprite_SetDrawFlag(subGraphics->unk1DC[i].sprites[j], 1);
                Sprite_SetAnimCtrlSeq(subGraphics->unk1DC[i].sprites[j], 1);
                break;
            case 4:
                Sprite_SetDrawFlag(subGraphics->unk1DC[i].sprites[j], 1);
                Sprite_SetAnimCtrlSeq(subGraphics->unk1DC[i].sprites[j], 2);
                break;
            default:
                GF_AssertFail();
                break;
            }
        }
    }
}
