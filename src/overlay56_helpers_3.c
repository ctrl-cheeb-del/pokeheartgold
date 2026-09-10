#include "overlay_56_helpers_internal.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct {
    u32 v[10];
} BanksConfig;
typedef struct {
    u32 v[4];
} ScreenModes;
typedef struct {
    u32 v[35];
} BgTemplates;
typedef struct {
    u8 padding[0x3ff8];
    volatile u32 irqCheck;
} DtcmLayout;
typedef struct {
    void *bgConfig;
    u32 zero;
    u32 tile;
    u32 palette;
    u8 x;
    u8 y;
    u8 touchMode : 4;
    u8 bgId : 4;
    u8 padding;
} PromptTemplate;
extern const BanksConfig ov56_021E6E58;
extern const u8 ov56_021E6E20[];
extern int (*const ov56_021E6DE4[])(void *);
extern const ScreenModes _021E6DD4;
extern const BgTemplates ov56_021E6E80;

void ov56_021E6D90(void *data) {
    int i;
    u8 *cursor;
    if (U8(data, 0xc) != 0) {
        return;
    }
    i = 0;
    cursor = data;
    do {
        void *s = PTR(cursor, 0xb8);
        if (s != 0) {
            Sprite_DeleteAndFreeResources(s);
        }
        i++;
        cursor += 4;
    } while (i < 3);
    SpriteSystem_FreeResourcesAndManager(PTR(data, 0xb0), PTR(data, 0xb4));
    SpriteSystem_Free(PTR(data, 0xb0));
    GF_DestroyVramTransferManager();
}
