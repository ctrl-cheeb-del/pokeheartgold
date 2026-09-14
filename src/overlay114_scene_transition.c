#include "overlay114_scene_transition_private.h"

void ov114_0225F020(void *task, Ov114Task *ctx) {
    Triple scale5;
    Triple scale6;
    Triple tmp5;
    Triple tmp6;
    BOOL done;
    Ov114WorkA *work = ctx->work;

    switch (ctx->state) {
    case 0:
        ctx->work = Heap_Alloc(4, 0x1a4);
        memset(ctx->work, 0, 0x1a4);
        work = ctx->work;
        ov01_021F05C4(work->spriteResources, 1, 1);
        ov01_021F0614(ctx->spriteManager, work->spriteResources, &work->resource168, 0, 1, 7, 9, 8, 0x927c0);
        work->sprite19c = ov01_021F0718(work->spriteResources, &work->resource168, 2 << 18, 6 << 16, 0, 0);
        Sprite_SetDrawFlag(work->sprite19c, FALSE);
        Sprite_SetOamMode(work->sprite19c, 1);
        GfGfx_EngineATogglePlanes(0x10, TRUE);
        ctx->state++;
        break;
    case 1:
        ov01_021EFCF8(1, 16, -16, &ctx->done, 2);
        ctx->state++;
        break;
    case 2:
        if (ctx->done != 0) {
            ctx->state++;
        }
        break;
    case 3:
        ov01_021EFE34(&work->fade, 0, 16, 12);
        G2x_SetBlendAlpha_(0x04000050, 0, 15, work->fade.value, 16 - work->fade.value);
        Sprite_SetDrawFlag(work->sprite19c, TRUE);
        ctx->state++;
        break;
    case 4:
        done = ov01_021EFE44(&work->fade);
        *(vu16 *)0x04000052 = (u16)(((16 - work->fade.value) << 8) | work->fade.value);
        if (done == TRUE) {
            *(vu16 *)0x04000050 = 0;
            Sprite_SetOamMode(work->sprite19c, 0);
            ctx->state++;
        }
        break;
    case 5:
        ov01_021EFEC8(&work->scale, 1 << 12, 0x19a, 1, 6);
        Sprite_SetAffineOverwriteMode(work->sprite19c, 2);
        ov01_021F074C(&tmp5, work->scale.value, work->scale.value, work->scale.value);
        scale5 = tmp5;
        Sprite_SetAffineScale(work->sprite19c, &scale5);
        HBlankSystem_Stop(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        BeginNormalPaletteFade(3, 0x10, 0, 0, 6, 1, 4);
        ctx->state++;
        break;
    case 6:
        done = ov01_021EFF28(&work->scale);
        ov01_021F074C(&tmp6, work->scale.value, work->scale.value, work->scale.value);
        scale6 = tmp6;
        Sprite_SetAffineScale(work->sprite19c, &scale6);
        if (done == TRUE && IsPaletteFadeFinished() == TRUE) {
            ctx->state++;
        }
        break;
    case 7:
        sub_0200FBF4(1, 0);
        HBlankSystem_Start(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        if (ctx->completionFlag != NULL) {
            *ctx->completionFlag = 1;
        }
        Sprite_Delete(work->sprite19c);
        ov01_021F06EC(work->spriteResources, &work->resource168);
        ov01_021F05F4(work->spriteResources);
        ov01_021EFCDC(ctx, task);
        break;
    }

    if (ctx->state != 7) {
        SpriteList_RenderAndAnimateSprites(*(SpriteList **)&work->spriteResources[0]);
    }
}

void ov114_0225F280(void *task, Ov114Task *ctx) {
    Triple matrix;
    BOOL done;
    int i;
    Interp *interp;
    Ov114WorkB *work = ctx->work;

    switch (ctx->state) {
    case 0:
        ctx->work = Heap_Alloc(4, 0x1b0);
        memset(ctx->work, 0, 0x1b0);
        work = ctx->work;
        ov01_021F05C4(work->spriteResources, 4, 1);
        ov01_021F0614(ctx->spriteManager, work->spriteResources, &work->resource13c, 0, 1, 4, 6, 5, 0x927c0);
        for (i = 0; i < 4; i++) {
            work->sprites170[i] = ov01_021F0718(work->spriteResources, &work->resource13c, 2 << 18, 6 << 16, 0, 0);
            Sprite_SetDrawFlag(work->sprites170[i], FALSE);
        }
        GfGfx_EngineATogglePlanes(0x10, TRUE);
        ctx->state++;
        break;
    case 1:
        ov01_021EFCF8(1, 16, -16, &ctx->done, 2);
        ctx->state++;
        break;
    case 2:
        if (ctx->done != 0) {
            ctx->state++;
        }
        break;
    case 3:
        ov01_021EFEC8(&work->horiz, 0, 2 << 18, 0x19a, 4);
        ov01_021EFEC8(&work->vert, 0, 10 << 16, 0x19a, 4);
        for (i = 0; i < 4; i++) {
            Sprite_SetDrawFlag(work->sprites170[i], TRUE);
        }
        ctx->state++;
        break;
    case 4:
        i = 0;
        interp = &work->horiz;
        while (i < 2) {
            done = ov01_021EFF28(interp);
            i++;
            interp = (Interp *)((u8 *)interp + 0x18);
        }
        ov01_021F074C(&matrix, 2 << 18, (6 << 16) - work->horiz.value, 0);
        Sprite_SetMatrix(work->sprites170[0], &matrix);
        ov01_021F074C(&matrix, 2 << 18, work->horiz.value + (6 << 16), 0);
        Sprite_SetMatrix(work->sprites170[1], &matrix);
        ov01_021F074C(&matrix, (2 << 18) - work->vert.value, 6 << 16, 0);
        Sprite_SetMatrix(work->sprites170[2], &matrix);
        ov01_021F074C(&matrix, work->vert.value + (2 << 18), 6 << 16, 0);
        Sprite_SetMatrix(work->sprites170[3], &matrix);
        if (done == TRUE) {
            ctx->state++;
        }
        break;
    case 5:
        HBlankSystem_Stop(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        BeginNormalPaletteFade(3, 0x22, 0, 0, 8, 1, 4);
        ctx->state++;
        break;
    case 6:
        if (IsPaletteFadeFinished() == TRUE) {
            ctx->state++;
        }
        break;
    case 7:
        sub_0200FBF4(1, 0);
        HBlankSystem_Start(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        if (ctx->completionFlag != NULL) {
            *ctx->completionFlag = 1;
        }
        for (i = 0; i < 4; i++) {
            Sprite_Delete(work->sprites170[i]);
        }
        ov01_021F06EC(work->spriteResources, &work->resource13c);
        ov01_021F05F4(work->spriteResources);
        ov01_021EFCDC(ctx, task);
        break;
    }

    if (ctx->state != 7) {
        SpriteList_RenderAndAnimateSprites(*(SpriteList **)&work->spriteResources[0]);
    }
}
