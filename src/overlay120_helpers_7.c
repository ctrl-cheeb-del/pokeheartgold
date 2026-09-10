#include "overlay120_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern const u32 ov120_022601F4[];
extern const u32 ov120_022601F8[];
extern const u32 ov120_022601FC[];
extern const u32 ov120_02260200[];

void ov120_0225FDA0(void *task, void *env) {
    void *owner = PTR(env, 0);
    void *character;
    switch (U16(env, 0x1e)) {
    case 0:
        character = PTR(env, 0xc);
        BG_LoadCharTilesData(PTR(PTR(owner, 0x10), 8), 1, U32(character, 0x14), PTR(character, 0x10), 0);
        U16(env, 0x1e)
        ++;
        return;
    case 1:
        character = PTR(env, 0x10);
        BG_LoadCharTilesData(PTR(PTR(owner, 0x10), 8), 3, U32(character, 0x14), PTR(character, 0x10), 0);
        U16(env, 0x1e)
        ++;
        return;
    case 2:
        PTR(env, 0x18) = 0;
        SysTask_Destroy(task);
        return;
    default:
        GF_AssertFail();
    }
}

void ov120_0225FE08(void *task, void *env) {
    void *owner = PTR(env, 0);
    if (PTR(owner, 0x20) == 0) {
        GF_AssertFail();
    }
    switch (U16(env, 0x1c)) {
    case 0:
        GfGfxLoader_GXLoadPalFromOpenNarc(PTR(owner, 0x20), 0xa0, 0, 0, 0x20, 4);
        PTR(env, 4) = ov120_0225FD14(PTR(owner, 0x20), 0xa1, (NNSG2dCharacterData **)((u8 *)env + 0xc), 4);
        PTR(env, 8) = ov120_0225FD14(PTR(owner, 0x20), 0xa4, (NNSG2dCharacterData **)((u8 *)env + 0x10), 4);
        U16(env, 0x1e) = 0;
        PTR(env, 0x18) = SysTask_CreateOnVBlankQueue(ov120_0225FDA0, env, 0);
        U16(env, 0x1c)
        ++;
        return;
    case 1:
        if (PTR(env, 0x18) != 0) {
            return;
        }
        ov120_0225FD2C(PTR(PTR(owner, 0x10), 8), PTR(owner, 0x20), 0xa2, 1);
        ov120_0225FD2C(PTR(PTR(owner, 0x10), 8), PTR(owner, 0x20), 0xa5, 3);
        U16(env, 0x1c)
        ++;
        return;
    case 2:
        Heap_Free(PTR(env, 4));
        Heap_Free(PTR(env, 8));
        PTR(env, 0x14) = 0;
        SysTask_Destroy(task);
        return;
    default:
        GF_AssertFail();
    }
}

void ov120_0225FECC(void *data, void *owner) {
    PTR(data, 0) = owner;
    U16(data, 0x1c) = 0;
    PTR(data, 0x14) = SysTask_CreateOnMainQueue(ov120_0225FE08, data, 1);
}

int ov120_0225FEE8(void *data) {
    if (data == 0) {
        GF_AssertFail();
    }
    return PTR(data, 0x14) == 0;
}
