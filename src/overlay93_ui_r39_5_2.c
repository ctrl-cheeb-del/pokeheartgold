#include "global.h"

#include "sprite_system.h"

#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

extern const ManagedSpriteTemplate ov93_02262E34;

extern void ov93_02260314(void *sys, void *sprites, void *counter);
extern void ov93_0225FC8C(void *bg, void *counter);
extern void ov93_02260B84(void *sys);
extern void PlaySE(u32 seqNo);

typedef struct {
    u8 pad[0x1428];
    u8 counter[0x18];
    u8 pad1440[0x1F5C];
    struct {
        u32 active;
        u8 rest[0x46C];
    } sprites;
} Ov93SystemPrefix;

void ov93_02260608(void *sys);
BOOL ov93_02260908(void *sys);
ManagedSprite *ov93_02260984(void *sys, u32 anim, u32 index);

BOOL ov93_02260908(void *sys) {
    Ov93SystemPrefix *work = sys;
    void *block = (u8 *)sys + 0x339C;
    s32 i;

    if (U32AT(block, 0) == 1) {
        return FALSE;
    }

    MI_CpuFill8(block, 0, 0x470);
    ov93_02260314(sys, &work->sprites, work->counter);
    ov93_0225FC8C(PAT(sys, 0x2C), work->counter);
    ov93_02260B84(sys);

    U32AT(sys, 0x2FCC) = 0;
    U32AT(sys, 0x1430) = 0;
    U32AT(sys, 0x1438) = 0;
    for (i = 0; i < 4; i++) {
        U32AT(sys, 0x1440) = 0;
        sys = (u8 *)sys + 4;
    }
    PlaySE(0x594);
    U32AT(block, 0) = 1;
    return TRUE;
}

ManagedSprite *ov93_02260984(void *sys, u32 anim, u32 index) {
    ManagedSpriteTemplate template = ov93_02262E34;
    ManagedSprite *sprite = SpriteSystem_NewSprite(PAT(sys, 0x24), PAT(sys, 0x28), &template);

    ManagedSprite_SetPositionXYWithSubscreenOffset(sprite, 0x48 - index * 0x10, 0x20, 0x160000);
    ManagedSprite_SetAnim(sprite, anim);
    Sprite_TickFrame(sprite->sprite);
    ManagedSprite_SetAnimateFlag(sprite, 1);
    return sprite;
}
