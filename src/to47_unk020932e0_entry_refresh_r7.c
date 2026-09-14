#include "to47_unk020932e0_entry_refresh_r7_private.h"

void sub_02094758(UnkGfxBuf_02094758 *buf);
void sub_02094C08(UnkEntryData_020932E0 *data, UnkGfxBuf_02094758 *bufs, int index, Sprite *sprite, void *buf, NARC *narc, int a6);
void sub_02094C88(UnkState_020932E0 *ptr, u32 a1);
void sub_02094EB4(UnkState_020932E0 *ptr);
void sub_02094F14(UnkState_020932E0 *ptr, int index, UnkEntryData_020932E0 *dest);

int sub_02094400(UnkState_020932E0 *ptr);
int sub_02094528(UnkState_020932E0 *ptr);
void sub_02094668(UnkState_020932E0 *ptr, int a1, int a2, int a3);

void sub_02094668(UnkState_020932E0 *ptr, int a1, int a2, int a3);

int sub_02094400(UnkState_020932E0 *ptr) {
    UnkEntryData_020932E0 data;
    void *buf;
    NARC *narc;
    int i;

    narc = NARC_New((NarcId)20, ptr->heapId);
    buf = Heap_AllocAtEnd(ptr->heapId, 0x1000);
    for (i = 0; i < 30; i++) {
        Sprite_SetOamMode(ptr->entriesB[i].sprite, (GXOamMode)0);
        if (ptr->fetch(ptr->unk_463C, ptr->unk_0F, i, &data)) {
            ptr->entriesB[i].data = data;
            sub_02094C08(&data, ptr->gfxBufs, i, ptr->entriesB[i].sprite, buf, narc, 0x40);
            if (data.isEgg != 0) {
                Sprite_SetOamMode(ptr->entriesB[i].sprite, (GXOamMode)1);
            } else {
                Sprite_SetOamMode(ptr->entriesB[i].sprite, (GXOamMode)0);
            }
        } else {
            sub_02094C08(&data, ptr->gfxBufs, i, NULL, buf, narc, 0x40);
            Sprite_SetDrawFlag(ptr->entriesB[i].sprite, FALSE);
        }
    }
    Heap_Free(buf);
    NARC_Delete(narc);
    ptr->callback = (UnkCallback_020932E0)sub_02094758;
    sub_02094C88(ptr, ptr->unk_0F);
    sub_02094EB4(ptr);
    CopyRectToBgTilemapRect(ptr->bgConfig, 2, 0, 0, 20, 20, (u8 *)ptr->unk_46D4 + 12, 0, 0, 32, 24);
    ScheduleBgTilemapBufferTransfer(ptr->bgConfig, 2);
}

int sub_02094528(UnkState_020932E0 *ptr) {
    UnkEntryData_020932E0 data;
    void *buf;
    NARC *narc;
    int count;
    int i;

    narc = NARC_New((NarcId)20, ptr->heapId);
    buf = Heap_AllocAtEnd(ptr->heapId, 0x1000);
    count = (u8)Party_GetCount(ptr->party);
    for (i = 0; i < count; i++) {
        sub_02094F14(ptr, i, &data);
        ptr->entriesB[i].data = data;
        sub_02094C08(&data, ptr->gfxBufs, i, ptr->entriesB[i].sprite, buf, narc, 0x40);
        if (data.isEgg != 0) {
            Sprite_SetOamMode(ptr->entriesB[i].sprite, (GXOamMode)1);
        } else {
            Sprite_SetOamMode(ptr->entriesB[i].sprite, (GXOamMode)0);
        }
    }
    data.species = 0;
    data.isEgg = 0;
    data.form = 0;
    data.heldItem = 0;
    data.unk_0E = 0;
    for (; i < 30; i++) {
        sub_02094C08(&data, ptr->gfxBufs, i, NULL, buf, narc, 0x40);
        Sprite_SetDrawFlag(ptr->entriesB[i].sprite, FALSE);
    }
    Heap_Free(buf);
    NARC_Delete(narc);
    ptr->callback = (UnkCallback_020932E0)sub_02094758;
    sub_02094C88(ptr, ptr->unk_0F);
    sub_02094EB4(ptr);
    CopyRectToBgTilemapRect(ptr->bgConfig, 2, 0, 0, 20, 20, (u8 *)ptr->unk_46D0 + 12, 0, 0, 20, 20);
    ScheduleBgTilemapBufferTransfer(ptr->bgConfig, 2);
}
