#include "to45_overlay01_r7_private.h"

BOOL ov01_021F9FCC(void *manager, u32 spriteId, void *skip) {
    u32 index = 0;
    void *obj = NULL;
    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE) {
        do {
            if (skip == NULL || skip != obj) {
                u32 objectSpriteId = MapObject_GetSpriteID(obj);
                if (objectSpriteId == spriteId) {
                    return TRUE;
                }
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE);
    }
    return FALSE;
}

BOOL ov01_021FA01C(void *manager, u32 transformedId, void *skip) {
    u32 index = 0;
    void *obj = NULL;
    u32 spriteId;
    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE) {
        do {
            if ((skip == NULL || skip != obj) && (spriteId = MapObject_GetSpriteID(obj)) != 0xffff && ov01_021F9318(obj)->low == 1 && spriteId != 0xffff && ov01_021FA28C(spriteId) == transformedId) {
                return TRUE;
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE);
    }
    return FALSE;
}

BOOL ov01_021FA094(void *manager, u32 transformedId, void *skip) {
    u32 index = 0;
    void *obj = NULL;
    u32 spriteId;
    if (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE) {
        do {
            if ((skip == NULL || obj != skip) && spriteId != 0xffff && ov01_021F9318(obj)->low == 1 && (spriteId = MapObject_GetSpriteID(obj)) != 0xffff && ov01_021FA2A0(spriteId) == transformedId) {
                return TRUE;
            }
        } while (MapObjectManager_GetNextObjectWithFlagFromIndex(manager, &obj, &index, 1) == TRUE);
    }
    return FALSE;
}

void ov01_021FA108(void *manager, u32 gfxId, void *mapObject) {
    void *render = sub_0205F1A0(manager);
    u32 idA = ov01_021FA28C(gfxId);
    u32 idB;
    if (ov01_021F9EEC(render, idA) == TRUE && !ov01_021FA01C(manager, idA, mapObject)) {
        ov01_021FC588(*(void **)((u8 *)render + 0xf8), idA);
        ov01_021F9BAC(render, idA);
    }
    idB = ov01_021FA2A0(gfxId);
    if (ov01_021F9F14(render, idB) == TRUE && !ov01_021FA094(manager, idB, mapObject)) {
        ov01_021FC588(*(void **)((u8 *)render + 0xfc), idB);
        ov01_021F9CD0(render, idB);
    }
    if (ov01_021F9EC4(render, gfxId) == TRUE && !ov01_021F9FCC(manager, gfxId, mapObject)) {
        GF3dGfxRawResMan_FreeObjById(ov01_021FA1F4(render), gfxId);
        ov01_021F9E04(render, gfxId);
        ov01_021FA4F0(render, gfxId);
        ov01_021FA6A4(render, gfxId);
    }
}
