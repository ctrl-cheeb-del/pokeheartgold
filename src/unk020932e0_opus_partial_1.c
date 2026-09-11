#include "unk020932e0_opus_partial_internal.h"

void PlaySE(u32 seq);
void GF_RunVramTransferTasks(void);
void OamManager_ApplyAndResetBuffers(void);

extern const BgTemplate _021083E4;
extern const BgTemplate _021083C8;
extern const BgTemplate _021083AC;
extern const BgTemplate _02108400;

void sub_020956B8(UnkStruct_020932E0 *ptr);
int sub_02093630(UnkStruct_020932E0 *ptr);
void sub_0209389C(UnkStruct_020932E0 *ptr);
void sub_02093908(UnkStruct_020932E0 *ptr);
void sub_0209396C(UnkStruct_020932E0 *ptr);
void sub_020939B8(UnkStruct_020932E0 *ptr);
void sub_0209511C(UnkStruct_020932E0 *ptr);
void sub_0209501C(UnkStruct_020932E0 *ptr, int a1, int a2);
void sub_02095780(void);
void sub_02095794(void);
void sub_02094F5C(UnkStruct_020932E0 *ptr, int a1);
void sub_020950C0(UnkStruct_020932E0 *ptr);
void sub_02094A90(UnkStruct_020932E0 *ptr, int a1);
int sub_02093CE4(UnkStruct_020932E0 *ptr);
void sub_020947C0(UnkStruct_020932E0 *ptr, int a1);
int sub_02094894(UnkStruct_020932E0 *ptr, int a1);
int sub_02094528(UnkStruct_020932E0 *ptr);
int sub_02094400(UnkStruct_020932E0 *ptr);

void sub_02093594(UnkStruct_020932E0 *ptr);
int sub_020935E0(UnkStruct_020932E0 *ptr);
void sub_02093A40(UnkStruct_020932E0 *ptr);
void sub_02093B40(UnkStruct_020932E0 *ptr);
void sub_02094150(SpriteTemplate *tmpl, UnkStruct_020932E0 *ptr, NNS_G2D_VRAM_TYPE vram);
void sub_0209428C(TouchscreenHitbox *rect, int x, int y, int width, int height);
int sub_020943EC(UnkStruct_020932E0 *ptr);
void sub_02094758(UnkGfxBuf_02094758 *buf);
void sub_02094794(UnkStruct_020932E0 *ptr, int index);
int sub_02094860(UnkStruct_020932E0 *ptr, int index);
void sub_02094A70(UnkStruct_020932E0 *ptr);
void sub_02094F14(UnkStruct_020932E0 *ptr, int index, MonDisplayInfo *dest);
void sub_020950D4(UnkStruct_020932E0 *ptr);
void sub_020950F8(Window *window, int a1);
void sub_0209569C(UnkStruct_020932E0 *ptr);
Sprite *sub_0209417C(UnkStruct_020932E0 *ptr, int x, int y, int animSeq, BOOL drawFlag);
void sub_02094C6C(u32 fileId, NNSG2dCharacterData **ppChar, void *dest, NARC *narc);
void sub_02094F14(UnkStruct_020932E0 *ptr, int slot, MonDisplayInfo *dest);
Sprite *Sprite_CreateAffine(const SpriteTemplate *template);
void Sprite_SetAnimActiveFlag(Sprite *sprite, BOOL flag);
void sub_02094DF8(BgConfig *bgConfig);
void sub_02094D9C(BgConfig *bgConfig, enum HeapID heapId);
void sub_02094D1C(UnkStruct_020932E0 *ptr);
int sub_020954CC(UnkStruct_020932E0 *ptr);
void sub_02094EB4(UnkStruct_020932E0 *ptr);

void sub_02093594(UnkStruct_020932E0 *ptr) {
    if (ptr->callback != NULL) {
        ptr->callback((u8 *)ptr + 0x8D4);
        ptr->callback = NULL;
        sub_020956B8(ptr);
    }
    GF_RunVramTransferTasks();
    OamManager_ApplyAndResetBuffers();
    DoScheduledBgGpuUpdates(ptr->bgConfig);
    OS_SetIrqCheckFlag(OS_IE_V_BLANK);
}

int sub_020935E0(UnkStruct_020932E0 *ptr) {
    switch (ptr->state) {
    case 0:
        return sub_02093630(ptr);
    case 1:
        sub_0209389C(ptr);
        return 0;
    case 2:
        sub_02093908(ptr);
        return 0;
    case 3:
        break;
    case 4:
        sub_0209396C(ptr);
        return 0;
    case 5:
        sub_020939B8(ptr);
        return 0;
    case 6:
        sub_0209511C(ptr);
        return 2;
    }
}
