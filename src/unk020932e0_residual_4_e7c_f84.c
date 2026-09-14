#include "unk020932e0_residual_4_private.h"

#include "unk_02005D10.h"

void sub_02094150(SpriteTemplate *, UnkStruct_020932E0_R4 *, NNS_G2D_VRAM_TYPE);
Sprite *sub_0209417C(UnkStruct_020932E0_R4 *, int, int, int, BOOL);
void sub_0209428C(TouchscreenHitbox *, int, int, int, int);
void sub_02094668(UnkStruct_020932E0_R4 *ptr, int a1, int a2, int a3);
void sub_02093B84(UnkStruct_020932E0_R4 *ptr);
void sub_02093E7C(UnkStruct_020932E0_R4 *ptr, u8 index);
void sub_02093F84(UnkStruct_020932E0_R4 *ptr, u8 previous, u8 next);

void sub_02093E7C(UnkStruct_020932E0_R4 *ptr, u8 index)
{
    u8 i;

    PlaySE(0x5EA);
    ptr->pairs[index].unk_04 = 1;
    sub_02094668(ptr, index, (u8)ptr->unk_4684, 0);

    for (i = 0; i < ptr->count; i++) {
        if (ptr->list[i].unk_04 == -1) {
            VecFx32 matrix = ptr->unk_4688;
            matrix.x -= 0x8000;
            matrix.y -= 0x4000;
            Sprite_SetMatrix(ptr->list[i].sprite, &matrix);
            Sprite_SetDrawFlag(ptr->list[i].sprite, TRUE);
            ptr->list[i].unk_04 = ptr->unk_4684;
            ptr->list[i].unk_08 = ptr->unk_0F;
            ptr->unk_0E++;
            Sprite_SetOamMode(ptr->entriesB[ptr->unk_4684].sprite, (GXOamMode)1);
            ptr->rowData.rows[index].unk_04 = ptr->unk_4684;
            ptr->rowData.rows[index].unk_00 = ptr->unk_0F;
            ptr->rowData.rows[index].unk_08 = i;
            ptr->rowData.rows[index].unk_0C = 1;
            ptr->unk_46B0 = index;
            return;
        }
    }
}

void sub_02093F84(UnkStruct_020932E0_R4 *ptr, u8 previous, u8 next)
{
    PlaySE(0x5EA);
    ptr->rowData.rows[previous].unk_0C = 0;
    Sprite_SetDrawFlag(ptr->entries[previous].sprite, FALSE);
    ptr->pairs[previous].unk_04 = 0;
    ptr->pairs[next].unk_04 = 1;
    sub_02094668(ptr, next, previous, 1);

    ptr->rowData.rows[next].unk_04 = ptr->rowData.rows[previous].unk_04;
    ptr->rowData.rows[next].unk_00 = ptr->rowData.rows[previous].unk_00;
    ptr->rowData.rows[next].unk_08 = ptr->rowData.rows[previous].unk_08;
    ptr->rowData.rows[next].unk_0C = 1;
    ptr->unk_46B0 = next;
}
