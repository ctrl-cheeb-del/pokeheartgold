#include "overlay41_helpers_internal.h"

/* ---- prototypes, source order ---- */
void *ov41_02245EA0(int count, enum HeapID heapId);
void ov41_02245ECC(void *w);
void ov41_02245F04(Ov41Work *w);
void ov41_02245F9C(Ov41Work *w);
void ov41_02246008(Ov41Work *w);
void ov41_02246014(Ov41Work *w);
void ov41_02246130(void);
void ov41_02246150(void);
void ov41_02246250(Ov41Work *w, u32 *src);
void ov41_0224626C(Ov41Work *w);
void ov41_022462E4(Ov41Work *w, void *narc, int fileId, BOOL compressed, int a4, int a5);
void ov41_02246328(Ov41Work *w, void *narc, int fileId, BOOL compressed, int id);
void ov41_02246344(Ov41Work *w, void *narc, int fileId, BOOL compressed, int id);
void ov41_02246360(Ov41Work *w, int id);
void ov41_02246374(Ov41Work *w, int id);
void ov41_02246388(Ov41Work *w, int id);
void ov41_0224639C(Ov41Work *w, int id);
void ov41_022463D4(void *a);
void *ov41_022463DC(Ov41Work *w, void *a, u32 idx);
void ov41_02246494(Ov41Work *w);
void ov41_022464AC(Ov41Work *w, void *arg);
void ov41_022465C0(Ov41Work *w);
void ov41_022465CC(Ov41Work *w);
void ov41_02246698(Ov41Work *w);
void ov41_022466B8(Ov41Work *w);
void ov41_022466C8(void *a);
void ov41_022467C8(void);
void ov41_022467D4(void);
void ov41_02246820(Ov41Work *w);
void ov41_02246830(Ov41Work *w);
void ov41_02246A7C(Ov41Work *w);
void ov41_02246B5C(Ov41Work *w);
void ov41_02246C90(Ov41Work *w, int fileId);
void ov41_02246CB0(Ov41Work *w);
void ov41_0224726C(void *a);
void ov41_02247274(Ov41Work *w);
void ov41_02247310(Ov41Work *w);
void ov41_022473F0(Ov41Work *w);
void ov41_02247478(void *a);
void ov41_022474C4(Ov41Work *w);
void ov41_02247568(Ov41Work *w);
void ov41_02247578(Ov41Work *w);
void ov41_02247588(Ov41Work *w);
void ov41_02247598(void *unused, Ov41Work *w);
void ov41_022475B4(void *unused, Ov41Work *w);
void ov41_022475D4(void *unused, Ov41Work *w);
void ov41_022476A8(Ov41Work *w);
void ov41_02247B5C(Ov41Work *w);
void ov41_02247D00(Ov41Work *w);
void ov41_02247D1C(void *a, void *b);
void ov41_02247D34(void *a);
void ov41_02247D3C(void *a);
void ov41_02247D44(Ov41Work *w);
void ov41_02247F90(Ov41Work *w);
void ov41_02247FE0(Ov41Work *w, void *a, void *b, void *c);
void ov41_02248020(Ov41Work *w, void *a);
void ov41_02248030(void *a);
void ov41_02248038(Ov41Work *w);
BOOL ov41_022480A4(Ov41Work *w, void *a, void *b);
void ov41_022480C8(Ov41Work *w, void *a);
void ov41_022480E0(Ov41Work *w);
void ov41_022480F8(Ov41Work *w, void *a, void *b);
void ov41_02248114(Ov41Work *w, void *a, void *b);
void ov41_02248158(void *a);
BOOL ov41_022481BC(void);
BOOL ov41_022481D8(u32 x, u32 y);
void ov41_022482A8(Ov41Work *w);
u32 ov41_022482B4(Ov41Work *w);
void ov41_022486F0(void *a);
BOOL ov41_02248820(void);
BOOL ov41_0224883C(u32 x, u32 y);
void ov41_02248940(Ov41Work *w);
void *ov41_0224894C(Ov41Work *w);
void ov41_02248984(void *a, int b, int c, void *d, void *e);
BOOL ov41_02248998(Ov41Work *w);
void ov41_02248A08(void *a, int b, int c, void *d);
void ov41_02248A18(void *a, void *b);
int ov41_02248AE0(void *a, int b, int c);
void ov41_02248D64(void *owner, void *a, void *b);
void ov41_02248DA4(Ov41E12 *p, int n);
void ov41_02248E80(void);
u32 ov41_02248ED4(Ov41Work *w, u32 idx);
u32 ov41_02248EE8(Ov41Work *w, u32 idx);
void ov41_02248F6C(Ov41Work *w);
void ov41_022490AC(void);
void ov41_0224946C(Ov41Work *w, void *a, void *b, void *c, void *d);
void ov41_022495F0(void *a, void *b, void *c, void *d, void *e);
void ov41_02249700(Ov41Work *w, u32 v);
u32 ov41_02249710(Ov41Work *w);
BOOL ov41_02249768(Ov41Work *w);
BOOL ov41_02249774(Ov41Work *w, u32 x, u32 y);
void ov41_02249780(Ov41Work *w, u32 *a, u32 *b);
void ov41_022497A0(void *unused, u32 *a, u32 *b);
void ov41_02249888(void *src, void *dst);

/* ---- bodies ---- */

void ov41_02246698(Ov41Work *w) {
    ov41_02246A20(w);
    Heap_Free((void *)W(w, 0x40));
    NARC_Delete((void *)W(w, 0x180));
    ov41_02246B34(w);
}

void ov41_022466B8(Ov41Work *w) {
    DoScheduledBgGpuUpdates((void *)W(w, 0x40));
    OamManager_ApplyAndResetBuffers();
}

void ov41_022466C8(void *a) {
    ov41_02246B5C(a);
}
