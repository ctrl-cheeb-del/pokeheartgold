#include "overlay18_profile_animation_internal.h"

void ov18_021F4CC4(void *p) {
    ov18_021F13DC(p, 1);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC551);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC551);
    SpriteManager_UnloadCellObjById(PTR(p, 0x66C, SpriteManager), 0xC55A);
    SpriteManager_UnloadAnimObjById(PTR(p, 0x66C, SpriteManager), 0xC55A);
    SpriteManager_UnloadCellObjById(PTR(p, 0x66C, SpriteManager), 0xC55B);
    SpriteManager_UnloadAnimObjById(PTR(p, 0x66C, SpriteManager), 0xC55B);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC59B);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC59C);
    SpriteManager_UnloadCharObjById(PTR(p, 0x66C, SpriteManager), 0xC59D);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC55D);
    SpriteManager_UnloadPlttObjById(PTR(p, 0x66C, SpriteManager), 0xC55E);
}
