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

void ov93_02260608(void *sys) {
    s32 i;
    u8 *entry;

    for (i = 0, entry = (u8 *)sys + 0x33A0; i < 0x24; i++, entry += 0x18) {
        if (PAT(entry, 0) != NULL) {
            Sprite_DeleteAndFreeResources(PAT(entry, 0));
        }
    }

    {
        u8 *entry2;
        s32 j;
        j = 0;
        entry2 = (u8 *)sys + 0x3700;
        for (; j < 8; j++, entry2 += 0x18) {
            if (PAT(entry2, 0) != NULL) {
                Sprite_DeleteAndFreeResources(PAT(entry2, 0));
            }
        }
    }

    {
        s32 k = 0;
        u8 *entry3 = (u8 *)sys + 0x37C0;
        for (; k < 3; k++, entry3 += 0x18) {
            if (PAT(entry3, 0) != NULL) {
                Sprite_DeleteAndFreeResources(PAT(entry3, 0));
            }
        }
    }
}
