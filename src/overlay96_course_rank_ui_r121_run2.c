#include "overlay96_course_rank_ui_r121_private.h"

void ov96_022195C8(Ov96RankUiWork *work) {
    ov96_02219C30(work);
    ov96_022196E4(work, 60);
    ov96_02219A5C(work, 0);
    ov96_02219B30(work);
}

void ov96_022195E8(Ov96RankUiWork *work) {
    if (work == NULL) {
        GF_AssertFail();
    }
    NARC_Delete(OV96_RANK_PTR(work, 0x24));
    {
        int i = 0;
        u8 *cursor = (u8 *)work;
        do {
            String_Delete(*(void **)(cursor + 0xB0));
            i++;
            cursor += 4;
        } while (i < 3);
    }
    Heap_Free(OV96_RANK_PTR(work, 0x28));
    {
        u8 *cursor = (u8 *)work;
        int i = 0;
        cursor += 0x30;
        do {
            RemoveWindow(cursor);
            i++;
            cursor += 0x10;
        } while (i < 3);
    }
    {
        u8 *cursor;
        int i;
        i = 0;
        cursor = (u8 *)work;
        do {
            if (*(void **)(cursor + 0x60) == NULL) {
                GF_AssertFail();
            }
            Sprite_DeleteAndFreeResources(*(void **)(cursor + 0x60));
            i++;
            cursor += 4;
        } while (i < 18);
    }
    Heap_Free(work);
}

void ov96_0221964C(Ov96RankUiWork *work) {
    int i = 0;
    u8 *cursor = (u8 *)work;
    int zero = i;

    do {
        ManagedSprite_SetAnimateFlag(*(void **)(cursor + 0xA0), zero);
        i++;
        cursor += 4;
    } while (i < 2);
}
