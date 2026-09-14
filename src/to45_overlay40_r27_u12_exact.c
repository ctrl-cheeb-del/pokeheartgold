#include "to45_overlay40_r27_u12_private.h"

void ov40_022338D0(Ov40Work *work) {
    Ov40SpriteGroup *group = work->sprites;
    int i;

    for (i = 0; i < 5; i++) {
        SpriteManager_UnloadCharObjById(work->spriteManager, 0x4705 + i);
        SpriteManager_UnloadPlttObjById(work->spriteManager, 0x4705 + i);
        Sprite_DeleteAndFreeResources(group->group2[i]);
    }
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x4705);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x4705);
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x4706);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x4706);

    for (i = 0; i < 5; i++) {
        Sprite_DeleteAndFreeResources(group->group1[i]);
    }
    SpriteManager_UnloadCharObjById(work->spriteManager, 0x2869F);
    SpriteManager_UnloadPlttObjById(work->spriteManager, 0x2869F);
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x2869F);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x2869F);

    for (i = 0; i < 5; i++) {
        Sprite_DeleteAndFreeResources(group->group3[i]);
    }
    SpriteManager_UnloadCharObjById(work->spriteManager, 0x6E7A);
    SpriteManager_UnloadPlttObjById(work->spriteManager, 0x6E7A);
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x6E7A);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x6E7A);

    for (i = 0; i < 5; i++) {
        Sprite_DeleteAndFreeResources(group->group4[i]);
    }
    SpriteManager_UnloadCharObjById(work->spriteManager, 0x726C);
    SpriteManager_UnloadPlttObjById(work->spriteManager, 0x726C);
    SpriteManager_UnloadCellObjById(work->spriteManager, 0x726C);
    SpriteManager_UnloadAnimObjById(work->spriteManager, 0x726C);
}

BOOL ov40_022339CC(Ov40Work *work) {
    Ov40SpriteGroup *group = work->sprites;
    s16 x, y;
    int i;

    for (i = 0; i < 5; i++) {
        group->angle[i] += 20;
        group->angle[i] %= 360;
    }
    ov40_0222DA00(&group->transitionA, &group->transitionB, 0, 0);
    for (i = 0; i < 5; i++) {
        if (group->angle[0] != 0) {
            group->scale[i] += 0.05f;
        } else {
            ManagedSprite_SetAffineOverwriteMode(group->group1[i], 0);
            ManagedSprite_SetAffineOverwriteMode(group->group2[i], 0);
            ManagedSprite_SetAffineOverwriteMode(group->group3[i], 0);
            group->scale[i] = 1.0f;
        }
        {
            fx32 dx = GF_SinDeg((u16)group->angle[i]) * group->radius[i];
            fx32 dy = GF_CosDeg((u16)group->angle[i]) * group->radius[i];
            dy = 0x6A000 - dy;
            dx += 0x80000;
            ManagedSprite_SetPositonFxXY(group->group3[i], dx, dy);
        }
        ManagedSprite_GetPositionXY(group->group3[i], &x, &y);
        ManagedSprite_SetPositionXY(group->group1[i], x - 0x20, y - 2);
        ManagedSprite_SetPositionXY(group->group2[i], x + 0x10, y - 2);
        ManagedSprite_SetAffineScale(group->group3[i], group->scale[i], group->scale[i]);
        ManagedSprite_SetAffineScale(group->group1[i], group->scale[i], group->scale[i]);
        ManagedSprite_SetAffineScale(group->group2[i], group->scale[i], group->scale[i]);
    }
    return group->angle[0] != 0;
}

BOOL ov40_02233AEC(Ov40Work *work) {
    Ov40SpriteGroup *group = work->sprites;
    s16 x, y;
    int i;

    for (i = 0; i < 5; i++) {
        group->angle[i] += 20;
        group->angle[i] %= 360;
    }
    if (group->angle[0] == 20) {
        for (i = 0; i < 5; i++) {
            ManagedSprite_SetAffineOverwriteMode(group->group1[i], 2);
            ManagedSprite_SetAffineOverwriteMode(group->group2[i], 2);
            ManagedSprite_SetAffineOverwriteMode(group->group3[i], 2);
        }
    }
    ov40_0222DA00(&group->transitionA, &group->transitionB, 1, 0);
    for (i = 0; i < 5; i++) {
        if (group->angle[0] != 0) {
            group->scale[i] -= 0.05f;
        } else {
            ManagedSprite_SetDrawFlag(group->group3[i], 0);
            ManagedSprite_SetDrawFlag(group->group1[i], 0);
            ManagedSprite_SetDrawFlag(group->group2[i], 0);
        }
        {
            fx32 dx = GF_SinDeg((u16)group->angle[i]) * group->radius[i];
            dx = 0x80000 - dx;
            fx32 dy = GF_CosDeg((u16)group->angle[i]) * group->radius[i];
            dy = 0x6A000 - dy;
            ManagedSprite_SetPositonFxXY(group->group3[i], dx, dy);
        }
        ManagedSprite_GetPositionXY(group->group3[i], &x, &y);
        ManagedSprite_SetPositionXY(group->group1[i], x - 0x20, y - 2);
        ManagedSprite_SetPositionXY(group->group2[i], x + 0x10, y - 2);
        ManagedSprite_SetAffineScale(group->group3[i], group->scale[i], group->scale[i]);
        ManagedSprite_SetAffineScale(group->group1[i], group->scale[i], group->scale[i]);
        ManagedSprite_SetAffineScale(group->group2[i], group->scale[i], group->scale[i]);
    }
    return group->angle[0] != 0;
}
