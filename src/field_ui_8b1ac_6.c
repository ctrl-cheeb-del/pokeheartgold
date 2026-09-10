#include "field_ui_8b1ac_internal.h"

void sub_0208BA60(u8 *work) {
    sub_0208BA88(work, 11, 3, work[0x240]);
    sub_0208BA88(work, 12, 4, work[0x241]);
}

void sub_0208BA88(u8 *work, u8 index, u8 slot, u8 attr) {
    int charId = sub_020776B4();
    int charValue = sub_02077678(attr);
    SpriteSystem_ReplaceCharResObj(*(void **)(work + 0x3FC), *(void **)(work + 0x400), charId, charValue, 1, slot);
    thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x404 + index * 4), sub_0207769C(attr) + 3);
}

void sub_0208BAD8(u8 *work, u8 *index, s16 *a, s16 *b) {
    s16 target = (s16)((*index << 5) + 16);
    s16 i;
    u8 *cursor = work;
    for (i = 0; i < 4; i++) {
        Sprite_GetPositionXY(*(void **)(cursor + 0x438), a, b);
        if (target == *b) {
            *index = i;
            return;
        }
        cursor += 4;
    }
}

void sub_0208BB24(u8 *work, u8 firstIndex, u8 secondIndex, int unused) {
    s16 first[2];
    s16 second[2];
    (void)unused;
    sub_0208BAD8(work, &firstIndex, &first[1], &first[0]);
    sub_0208BAD8(work, &secondIndex, &second[1], &second[0]);
    Sprite_SetPositionXY(*(void **)(work + 0x404 + (firstIndex + 13) * 4), second[1], second[0]);
    Sprite_SetPositionXY(*(void **)(work + 0x404 + (secondIndex + 13) * 4), first[1], first[0]);
}

void sub_0208BB8C(u8 *work, u16 move) {
    int attr = GetMoveAttr(move, 1);
    int charId = sub_02077830(attr);
    int charValue = sub_02077800(attr);
    SpriteSystem_ReplaceCharResObj(*(void **)(work + 0x3FC), *(void **)(work + 0x400), charId, charValue, 1, 10);
    thunk_Sprite_SetPaletteOverride(*(void **)(work + 0x44C), sub_02077818(attr) + 3);
}
