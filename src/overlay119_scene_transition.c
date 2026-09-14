#include "overlay119_scene_transition_private.h"

void ov119_0225FF9C(void *task, Ov119Task *ctx) {
    Triple vec2;
    Triple vec1;
    Triple vec0;
    BOOL done;
    s32 distance;
    s32 scale;
    Ov119Work *work = ctx->work;

    switch (ctx->state) {
    case 0:
        ctx->work = Heap_Alloc(4, 0x1f0);
        memset(ctx->work, 0, 0x1f0);
        work = ctx->work;
        work->camera1d0 = *(Camera **)((u8 *)ctx->fieldSystem + 0x24);
        ov01_021F05C4(work->spriteResources, 1, 1);
        ov01_021F0614(ctx->spriteManager, work->spriteResources, &work->resource198, 0, 1, 4, 6, 5, 0x927c0);
        work->sprite1cc = ov01_021F0718(work->spriteResources, &work->resource198, 0x80000, -0x20000, 0, 0);
        Sprite_SetDrawFlag(work->sprite1cc, FALSE);
        GfGfx_EngineATogglePlanes(0x10, TRUE);
        ctx->state++;
        break;
    case 1:
        ov01_021EFCF8(1, -16, -16, &ctx->done, 2);
        ctx->state++;
        break;
    case 2:
        if (ctx->done != 0) {
            ctx->state++;
        }
        break;
    case 3:
        ov01_021EFEC8(&work->interp0, 0, 0x100000, 0x2000, 12);
        Sprite_SetDrawFlag(work->sprite1cc, TRUE);
        ov01_021EFEC8(&work->interp18, 0x19a, 0x2000, 0, 12);
        ov01_021EFEC8(&work->interp30, 0x19a, 0x2000, 0, 12);
        ov01_021F074C(&vec2, work->interp18.value, work->interp30.value, 0);
        Sprite_SetScaleAndAffineType(work->sprite1cc, &vec2, 2);
        ov01_021EFE34(&work->interp48, 0, 0xffff, 12);
        ctx->state++;
        break;
    case 4:
        done = ov01_021EFF28(&work->interp0);
        scale = 2 << 18;
        ov01_021F074C(&vec0, scale, work->interp0.value - (scale >> 2), 0);
        vec1 = vec0;
        Sprite_SetMatrix(work->sprite1cc, &vec1);
        ov01_021EFF28(&work->interp18);
        ov01_021EFF28(&work->interp30);
        ov01_021F074C(&vec2, work->interp18.value, work->interp30.value, 0);
        Sprite_SetAffineScale(work->sprite1cc, &vec2);
        ov01_021EFE44(&work->interp48);
        Sprite_SetAffineZRotation(work->sprite1cc, (u16)work->interp48.value);
        if (done == TRUE) {
            Sprite_SetDrawFlag(work->sprite1cc, FALSE);
            ctx->state++;
        }
        break;
    case 5:
        HBlankSystem_Stop(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        distance = Camera_GetDistance(work->camera1d0);
        ov01_021EFEC8(&work->cameraInterp, distance, distance - (250 << 14), 10 << 12, 8);
        BeginNormalPaletteFade(3, 0x12, 0, 0, 8, 1, 4);
        ctx->state++;
        break;
    case 6:
        ov01_021EFF28(&work->cameraInterp);
        Camera_SetDistance(work->cameraInterp.value, work->camera1d0);
        if (IsPaletteFadeFinished()) {
            ctx->state++;
        }
        break;
    case 7:
        sub_0200FBF4(1, 0);
        HBlankSystem_Start(*(void **)((u8 *)*(void **)((u8 *)ctx->fieldSystem + 4) + 0x1c));
        if (ctx->completionFlag != NULL) {
            *ctx->completionFlag = 1;
        }
        Sprite_Delete(work->sprite1cc);
        ov01_021F06EC(work->spriteResources, &work->resource198);
        ov01_021F05F4(work->spriteResources);
        ov01_021EFCDC(ctx, task);
        break;
    }

    if (ctx->state != 7) {
        SpriteList_RenderAndAnimateSprites(*(SpriteList **)&work->spriteResources[0]);
    }
}
