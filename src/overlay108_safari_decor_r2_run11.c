#include "overlay108_safari_decor_r2_private.h"

void ov108_021E9DE0(void *p) {
    u8 *q = p;
    int i;
    YesNoPrompt_Destroy(PTR(q, 0x514));
    i = 0;
    q += 0x454;
    do {
        ClearWindowTilemapAndCopyToVram(q);
        RemoveWindow(q);
        i++;
        q += 0x10;
    } while (i < 12);
}

void ov108_021E9E10(void *p) {
    GF_CreateVramTransferManager(0x20, U32(p, 0));
    PTR(p, 0x43c) = SpriteSystem_Alloc(U32(p, 0));
    SpriteSystem_Init(PTR(p, 0x43c), ov108_021EABA8, ov108_021EAAD0, 1);
    PTR(p, 0x440) = SpriteManager_New(PTR(p, 0x43c));
    SpriteSystem_InitSprites(PTR(p, 0x43c), PTR(p, 0x440), 4);
    sub_0200D2A4(PTR(p, 0x43c), PTR(p, 0x440), ov108_021EAAB0, 0, 0);
    thunk_ClearMainOAM(U32(p, 0));
    thunk_ClearSubOAM(U32(p, 0));
}

void ov108_021E9E80(void *p) {
    SpriteSystem_DestroySpriteManager(PTR(p, 0x43c), PTR(p, 0x440));
    SpriteSystem_Free(PTR(p, 0x43c));
    PTR(p, 0x43c) = 0;
    PTR(p, 0x440) = 0;
    GF_DestroyVramTransferManager();
    thunk_ClearMainOAM(U32(p, 0));
    thunk_ClearSubOAM(U32(p, 0));
}

void ov108_021E9EB8(void *arg) {
    SafariDecorationWorkForSprites *work = arg;
    SafariSpriteTemplate *template = ov108_021EAC48;
    int i = 0;

    do {
        work->sprites[i] = SpriteSystem_CreateSpriteFromResourceHeader(work->spriteSystem, work->spriteManager, template);
        Sprite_SetDrawFlag(work->sprites[i], TRUE);
        template++;
        i++;
    } while (i < 4);
    thunk_Sprite_SetPriority(work->sprites[0], 1);
}

void ov108_021E9F04(void *p) {
    u32 off = 0x444;
    u8 *q = p;
    int i = 0;
    do {
        thunk_Sprite_Delete(PTR(q, off));
        i++;
        q += 4;
    } while (i < 4);
}
