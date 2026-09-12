#include "overlay02_roamer_pokecenter_r14_private.h"

void ov02_0224B88C(void *p) {
    u8 *q = (u8 *)p + 0x228;
    HeapExp_FndInitAllocator(q, 4, 0x20);
    PTR(q, 0x10) = AllocAtEndAndReadWholeNarcMemberByIdPair(0x67, 0x83, 4);
    ov01_021FBD38(q + 0x14, PTR(q, 0x10));
    Field3dObject_InitFromModel(q + 0x24, q + 0x14);
    Field3dModelAnimation_LoadFromFilesystem(q + 0x9c, q + 0x14, 0x67, 0xa7, 4, q);
    Field3dModelAnimation_LoadFromFilesystem(q + 0xb0, q + 0x14, 0x67, 0xa5, 4, q);
    Field3dObject_AddAnimation(q + 0x24, q + 0x9c);
    Field3dObject_AddAnimation(q + 0x24, q + 0xb0);
}
void ov02_0224B90C(void *p) {
    u8 *q = (u8 *)p + 0x228;
    ov01_021FBDFC(q + 0x14);
    ov01_021F1448(PTR(q, 0x10));
    Field3dModelAnimation_Unload(q + 0x9c, q);
    Field3dModelAnimation_Unload(q + 0xb0, q);
}
BOOL ov02_0224B938(void *p) {
    MapObject_SetVisible(PTR(p, 0x20c), 1);
    sub_0205F484(PTR(p, 0x20c));
    ov02_0224B784(p);
    U32(p, 0)
    ++;
    return TRUE;
}
BOOL ov02_0224B964(void *p) {
    if (U32(sub_02068D74(PTR(p, 0x1f0)), 8) == 1) {
        sub_02068B48(PTR(p, 0x1f0));
        ov02_0224B90C(p);
        U32(p, 0)
        ++;
        return FALSE;
    }
    return FALSE;
}
void ov02_BattleExit_HandleRoamerAction(void *fs, void *setup) {
    void *mon = Party_GetMonByIndex(PTR(setup, 8), 0);
    void *roamers = Save_Roamers_Get(PTR(fs, 0xc));
    u32 species = GetMonData(mon, 5, NULL);
    void *roamer = ov02_0224BAA8(roamers, species);
    if (roamer != NULL) {
        u32 idx = SpeciesToRoamerIdx((u16)species);
        u16 hp = (u16)GetMonData(mon, 0xa3, NULL);
        u8 level = (u8)GetMonData(mon, 0xa0, NULL);
        u32 action = U32(setup, 0x14);
        if (action == 1 && hp == 0) {
            RoamerMon_Init(&roamer);
            sub_02066BE8(Save_VarsFlags_Get(PTR(fs, 0xc)), idx, 2);
        } else if (action == 4) {
            RoamerMon_Init(&roamer);
            sub_02066BE8(Save_VarsFlags_Get(PTR(fs, 0xc)), idx, 1);
        } else {
            SetRoamerData(roamer, 5, hp);
            SetRoamerData(roamer, 7, level);
        }
        ov02_RepelActiveRoamersFromMapNo(roamers, U32(PTR(fs, 0x20), 0));
    } else if ((u16)((s32)LCRandom() % 100) < 30) {
        ov02_RepelActiveRoamersFromMapNo(roamers, U32(PTR(fs, 0x20), 0));
    }
}
void ov02_RepelActiveRoamersFromMapNo(void *roamers, u32 map) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (GetRoamerIsActiveByIndex(roamers, i) && map == GetRoamMapByLocationIdx(Roamer_GetLocation(roamers, i))) {
            RoamerLocationUpdateRand(roamers, i);
        }
    }
}
void *ov02_0224BAA8(void *roamers, u32 species) {
    u8 i;
    for (i = 0; i < 4; i++) {
        if (GetRoamerIsActiveByIndex(roamers, i)) {
            void *r = Roamers_GetRoamMonStats(roamers, i);
            if (species == GetRoamerData(r, 4)) {
                return r;
            }
        }
    }
    return NULL;
}
BOOL PlayerStepEvent_RepelCounterDecrement(void *save, void *fieldSystem) {
    u8 *repel = RoamerSave_GetRepelAddr(Save_Roamers_Get(save));
    if (*repel != 0) {
        (*repel)--;
        if (*repel == 0) {
            StartMapSceneScript(fieldSystem, 2022, NULL);
            return TRUE;
        }
    }
    return FALSE;
}
void PokecenterAnimCreate(void *fs, u8 kind) {
    VecFx32 delta, trans;
    void *prop;
    int idx;
    if (sub_02054C20(fs, 0x24, &prop, &idx)) {
        u8 *env = Heap_AllocAtEnd(4, 0x18);
        U8(env, 0xc) = kind;
        U8(env, 0xd) = 0;
        U8(env, 0xe) = 0;
        U8(env, 0xf) = 0;
        sub_02054DC8(idx, MapMatrix_GetWidth(PTR(fs, 0x30)), &delta);
        MapProp_GetTranslation(&trans, prop);
        *(VecFx32 *)env = trans;
        ((VecFx32 *)env)->x += delta.x;
        ((VecFx32 *)env)->z += delta.z;
        TaskManager_Call(PTR(fs, 0x10), PokecenterAnimRun, env);
    } else {
        GF_AssertFail();
    }
}
