#include "global.h"

#define U8_AT(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16_AT(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16_AT(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define PTR_AT(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov90Work19 {
    u8 pad_000[0x14];
    u8 count;
    u8 selected;
    u8 pad_016[0x2C - 0x16];
    u8 inactive[4];
    u8 pad_030[0x654 - 0x30];
    void *allocation;
    void *palette;
    u16 phase;
    u16 enabled;
} Ov90Work19;

typedef struct Ov90Palette19 {
    u8 pad_00[0xC];
    u8 *data;
} Ov90Palette19;

extern const u8 ov90_0225C1EC[];
extern void GF_RunVramTransferTasks(void);
extern void GF_AssertFail(void);
extern BOOL GF_CreateNewVramTransferTask(int, u32, void *, u32);
extern void *GfGfxLoader_GetPlttDataFromOpenNarc(void *, s32, void **, u32);
extern void ov90_022590C0(void *);
extern void ov90_0225917C(void *);
extern void ov90_0225A198(void *);
extern void ov90_0225B954(void *);

void ov90_0225B230(void *, void *);
void ov90_0225B254(void *, void *, u32);
void ov90_0225B274(void *);
void ov90_0225B2A8(void *);

void ov90_0225B230(void *unused, void *work) {
    GF_RunVramTransferTasks();
    ov90_022590C0((u8 *)work + 0x4C);
    ov90_0225917C((u8 *)work + 0xA0);
    ov90_0225A198((u8 *)work + 0x33C);
}

void ov90_0225B254(void *work, void *narc, u32 heapId) {
    PTR_AT(work, 0x654) = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 5, (void **)((u8 *)work + 0x658), heapId);
}

void ov90_0225B274(void *work) {
    Ov90Work19 *w = work;
    int i;
    int count;

    w->enabled = 1;
    count = w->count;
    for (i = 0; i < count; i++) {
        if (w->inactive[i] == 0 && w->selected == i) {
            ov90_0225B954(work);
            return;
        }
    }
}
