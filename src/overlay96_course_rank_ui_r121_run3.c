#include "overlay96_course_rank_ui_r121_private.h"

void ov96_022196E4(Ov96RankUiWork *work, s32 value) {
    u8 remainder = (u8)(value % 100);
    u8 tens = (u8)(remainder / 10);
    u8 ones = (u8)(remainder % 10);
    int i;

    OV96_RANK_U32(work, 0xC4) = value < 10 || value > 55;
    i = 0;
    {
        u8 *cursor = (u8 *)work;
        int one = 1;
        do {
            int draw;
            if (OV96_RANK_U32(work, 0xC4) == 0) {
                draw = one;
            } else {
                draw = 0;
            }
            ManagedSprite_SetDrawFlag(*(void **)(cursor + 0x88), draw);
            i++;
            cursor += 4;
        } while (i < 4);
    }
    Sprite_SetAnimCtrlSeq(OV96_RANK_PTR(work, 0xA8), tens + 1);
    Sprite_SetAnimCtrlSeq(OV96_RANK_PTR(work, 0xAC), ones + 1);
}

void ov96_02219770(Ov96RankUiWork *work, int first, int second) {
    ManagedSprite_SetDrawFlag(OV96_RANK_PTR(work, 0xA0), first);
    ManagedSprite_SetDrawFlag(OV96_RANK_PTR(work, 0xA4), second);
}
