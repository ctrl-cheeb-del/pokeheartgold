#include "unk020932e0_residual_4_private.h"

#include "unk_02005D10.h"

void sub_02094150(SpriteTemplate *, UnkStruct_020932E0_R4 *, NNS_G2D_VRAM_TYPE);
Sprite *sub_0209417C(UnkStruct_020932E0_R4 *, int, int, int, BOOL);
void sub_0209428C(TouchscreenHitbox *, int, int, int, int);
void sub_02094668(UnkStruct_020932E0_R4 *ptr, int a1, int a2, int a3);
void sub_02093B84(UnkStruct_020932E0_R4 *ptr);
void sub_02093E7C(UnkStruct_020932E0_R4 *ptr, u8 index);
void sub_02093F84(UnkStruct_020932E0_R4 *ptr, u8 previous, u8 next);

void sub_02093B84(UnkStruct_020932E0_R4 *ptr)
{
    SpriteTemplate template;
    int i;
    u8 unused;

    sub_02094150(&template, ptr, NNS_G2D_VRAM_TYPE_2DMAIN);
    ptr->pairs = Heap_Alloc(ptr->heapId, ptr->count * sizeof(UnkPair_020932E0_R4));
    for (i = 0; i < ptr->count; i++) {
        ptr->pairs[i].x = 0x20 + i * 0x28;
        ptr->pairs[i].x2 = ptr->pairs[i].x + 0x18;
        ptr->pairs[i].y = 0xc0;
        ptr->pairs[i].y2 = ptr->pairs[i].y + 0x20;
        ptr->pairs[i].unk_04 = 0;
        template.position.x = 0xd4000;
        template.position.y = (i * 0x28 + 0x28) << 12;
        if (ptr->entries[i].sprite == NULL) {
            ptr->entries[i].sprite = Sprite_CreateAffine(&template);
        }
        Sprite_SetAnimActiveFlag(ptr->entries[i].sprite, TRUE);
        Sprite_SetAnimCtrlSeq(ptr->entries[i].sprite, i + 0x27);
        Sprite_SetPriority(ptr->entries[i].sprite, 1);
        Sprite_SetDrawFlag(ptr->entries[i].sprite, FALSE);
        Sprite_SetDrawPriority(ptr->entries[i].sprite, 6);
        sub_0209428C(&ptr->hitboxes[i + 0x21], 0xd4, i * 0x28 + 0x2c, 0x18, 0x18);
    }

    unused = 0;
    for (; i < 3; i++) {
        ((Sprite **)&ptr->filler_08C8)[unused++] = sub_0209417C(ptr, 0xd4, i * 0x28 + 0x2c, 0x2f, TRUE);
    }

    ptr->dragState.x = 0x20;
    ptr->dragState.x2 = 0x97;
    ptr->dragState.y = 8;
    ptr->dragState.y2 = 0x97;
    ptr->dragState.unk_04 = 0;
}
