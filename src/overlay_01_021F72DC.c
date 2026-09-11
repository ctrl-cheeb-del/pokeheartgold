#include "global.h"

#include "overlay_01_021F72DC_internal.h"

void *ov01_021F72DC(void *object) {
    int spriteId = MapObject_GetSpriteID(object);

    switch (spriteId) {
    case 0:
    case 0x15:
    case 0x61:
    case 0x62:
    case 0xB0:
    case 0xB1:
    case 0xB2:
    case 0xB3:
    case 0xB4:
    case 0xB5:
    case 0xBC:
    case 0xBD:
    case 0xC4:
    case 0xC5:
    case 0xC6:
    case 0xC7:
    case 0xC8:
    case 0xC9:
    case 0xF8:
    case 0xF9:
    case 0x102:
    case 0x103:
    case 0x104:
    case 0x105:
        return ((void **)sub_0205F40C(object))[1];
    }

    if (spriteId >= 0x1AC && spriteId <= 0x3E1) {
        return ((void **)sub_0205F40C(object))[0];
    }
    if (spriteId >= 0x106 && spriteId <= 0x10D) {
        return sub_02064084(object);
    }
    return ((void **)sub_0205F40C(object))[1];
}
