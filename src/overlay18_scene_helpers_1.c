#include "overlay18_scene_helpers_private.h"

void ov18_021F3AD8(void *work) {
    Position18 pos;
    if (R17_U32(work, 0x1860) == 1) {
        ov18_021F11C0(work, 0x11, 1);
        ov18_021F2AC0(work, 0x11);
        ManagedSprite_GetPositionXY(R17_PTR(work, 0x6b4), &pos.x, &pos.y);
        ManagedSprite_SetPositionXY(R17_PTR(work, 0x6b4), pos.x - 0x120, pos.y);
    }
}

void ov18_021F3B2C(void *work, s32 delta) {
    Position18 pos;
    ManagedSprite_GetPositionXY(R17_PTR(work, 0x6b4), &pos.x, &pos.y);
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x6b4), pos.x + delta, pos.y);
}

void ov18_021F3B60(void *work, u32 show) {
    u32 i;
    if (show == 1) {
        for (i = 0x2c; i <= 0x3a; i++) ov18_021F11C0(work, i, 1);
        ov18_021F11C0(work, 0x2b, 0);
    } else {
        for (i = 0x2c; i <= 0x3a; i++) ov18_021F11C0(work, i, 0);
        ov18_021F3BA4(work);
    }
}

void ov18_021F3BA4(void *work) {
    Work18BA4 *typed = work;
    if (typed->value188c == 0xe) {
        ov18_021F11C0(work, 0x2b, 0);
    } else {
        ov18_021F11C0(work, 0x2b, 1);
        ov18_021F118C(work, 0x2b, typed->value188c);
    }
}

void ov18_021F3BD4(void *work, s32 delta) {
    Position18 pos;
    ManagedSprite_GetPositionXY(R17_PTR(work, 0x6e0), &pos.x, &pos.y);
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x6e0), pos.x, pos.y + delta);
    ManagedSprite_GetPositionXY(R17_PTR(work, 0x71c), &pos.x, &pos.y);
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x71c), pos.x, pos.y + delta);
}

void ov18_021F3C30(void *work) {
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x6d4), 0x30, -0x60);
    ov18_021F11C0(work, 0x19, 1);
}

void ov18_021F3C54(void *work, s32 delta) {
    Position18 pos;
    ManagedSprite_GetPositionXY(R17_PTR(work, 0x6d4), &pos.x, &pos.y);
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x6d4), pos.x, pos.y + delta);
}

void ov18_021F3C88(void *work) {
    ManagedSprite_SetPositionXY(R17_PTR(work, 0x6d4), 0x30, 0x18);
    ov18_021F11C0(work, 0x19, 1);
}

void ov18_021F3CA8(void *work, u32 index, u8 *form, u8 *gender) {
    Work18CA8 *typed = work;
    u8 value = typed->forms[index];
    if (value & 0x80) {
        if (typed->species == 0xac) {
            switch (value ^ 0x80) {
            case 0: *form = 0; *gender = 0; return;
            case 1: *form = 0; *gender = 1; return;
            case 2: *form = 1; *gender = 1; return;
            }
            return;
        }
        *form = value ^ 0x80;
        *gender = Pokedex_SpeciesGetLastSeenGender(*(void **)typed->root, typed->species, 0);
        return;
    }
    *form = 0;
    switch (typed->forms[index]) {
    case 1: *gender = 0; return;
    case 2: *gender = 1; return;
    case 3: break;
    }
    *gender = 2;
}

void ov18_021F3D34(void *work) {
    ov18_021F2648(work);
    R17_PTR(work, 0x670) = SpriteSystem_NewSprite(R17_PTR(work, 0x668), R17_PTR(work, 0x66c), ov18_021FA554);
    ManagedSprite_SetPaletteOverride(R17_PTR(work, 0x670), 4);
    ov18_021F11C0(work, 0, 0);
}
