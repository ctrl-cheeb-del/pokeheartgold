#include "ov80_3a00c_partial_internal.h"

void ov80_0223A748(void *object) {
    u8 *p = object;
    FontOAM_Delete(*(void **)p);
    sub_02021B5C(p + 4);
}

void ov80_0223A75C(int font, void *string, int *widthOut, int *tilesOut) {
    int width = FontID_String_GetWidth(string, font, 0);
    int tiles = width / 8;
    if (FX_ModS32(width, 8) != 0) {
        tiles++;
    }
    *widthOut = width;
    *tilesOut = tiles;
}

void ov80_0223A78C(void *work, void *object, s32 x, s32 y, int heap) {
    u8 *w = work;
    u8 *entry = object;
    MotionR21 *motion;
    SpriteDescriptorR21 descriptor = ov80_0223DB64;
    int i;
    motion = (MotionR21 *)entry;
    *(s16 *)&descriptor = x >> 12;
    *(s16 *)((u8 *)&descriptor + 2) = y >> 12;
    i = 0;
    *(u16 *)entry = 0;
    *(u16 *)(entry + 2) = 0;
    motion = (MotionR21 *)((u8 *)motion + 0x14);
    for (i = 0; i < 4; i++) {
        *(void **)(entry + 4) = SpriteSystem_NewSprite(*(void **)(w + 0x14), *(void **)(w + 0x18), &descriptor);
        ManagedSprite_SetDrawFlag(*(void **)(entry + 4), 0);
        if (i != 3) {
            Sprite_SetAffineOverwriteMode(**(void ***)(entry + 4), 2);
            Sprite_SetAnimCtrlSeq(**(void ***)(entry + 4), 1);
            ov80_0223A8C4(motion, 0x2000, 0x1000, 6);
        } else {
            ov80_0223A8C4(motion, 0x1000, 0x1000, 6);
        }
        entry += 4;
        motion++;
    }
}

void ov80_0223A81C(void *array) {
    u8 *p = array;
    int i;
    for (i = 0; i < 4; i++) {
        Sprite_DeleteAndFreeResources(*(void **)(p + 4));
        p += 4;
    }
}
