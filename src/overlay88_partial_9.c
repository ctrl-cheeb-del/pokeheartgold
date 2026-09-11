#include "global.h"

typedef struct {
    u16 state;
    u16 count;
    u16 limit;
    u16 value;
    void *ptr;
} Small;

extern void *Heap_Alloc(int, int);
extern void Heap_Free(void *);
extern void DoScheduledBgGpuUpdates(void *);
extern void OamManager_ApplyAndResetBuffers(void);
extern void GF_RunVramTransferTasks(void);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern int ov45_0222DD38(void *);
extern void NARC_Delete(void *);
extern void GF_DestroyVramTransferManager(void);
extern void ov88_02258C60(void *);
extern void ov88_02258D38(void *);
extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void *, int, int, void **, int);
extern void String_Delete(void *);
extern void RemoveWindow(void *);
extern void ov88_02259884(void *);
extern void GF_AssertFail(void);
extern void ov88_02258B20(void *);
extern void ov88_02258F74(void *, void *, void *);
extern void ov88_02258F88(void *, void *, void *);

void ov88_02258A64(void *);
void ov88_02258B14(void *);
void ov88_02258B20(void *);
void ov88_02258D84(void *);
void ov88_02258AF4(void *);
void ov88_02258D64(void *, void *, int);
void ov88_02258EF8(void);
void ov88_02258F60(void *, void *, void *);
void ov88_02258F74(void *, void *, void *);
void ov88_022590D4(void);
int ov88_022590D8(Small *, void *);
void ov88_022595DC(Small *);
int ov88_022595E4(Small *);
void ov88_0225983C(Small *, u16, void *);
void ov88_0225985C(Small *);
void ov88_02259878(Small *);
void ov88_02259818(void *, u32);
void ov88_0225954C(void *);
void ov88_022597DC(void *);
void ov88_02259800(void *);

void ov88_02259818(void *p, u32 index) {
    if (index >= 4) {
        GF_AssertFail();
    }
    if (index == 0) {
        GF_AssertFail();
    }
    ov88_02259878((Small *)((u8 *)p + 0x40 + index * 12));
}

void ov88_0225983C(Small *p, u16 value, void *ptr) {
    u8 *q = (u8 *)p;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    q[5] = 0;
    q[6] = 0;
    q[7] = 0;
    q[8] = 0;
    q[9] = 0;
    q[10] = 0;
    q[11] = 0;
    *(u16 *)(q + 6) = value;
    *(void **)(q + 8) = ptr;
}

void ov88_0225985C(Small *p) {
    u8 *q = (u8 *)p;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    q[3] = 0;
    q[4] = 0;
    q[5] = 0;
    q[6] = 0;
    q[7] = 0;
    q[8] = 0;
    q[9] = 0;
    q[10] = 0;
    q[11] = 0;
}

void ov88_02259878(Small *p) {
    p->state = 1;
    p->count = 0;
}
