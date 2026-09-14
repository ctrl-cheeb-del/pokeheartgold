#include "global.h"
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define SYS(c)    PTR(PTR((c), 0), 0)
typedef struct Bits11 {
    u16 lo : 11;
} Bits11;
typedef struct Rec38 {
    u8 raw[0x38];
} Rec38;
#define READ_U8(c) (*(*(u8 **)((u8 *)(c) + 0x1c))++)
extern u16 *FrontierScript_ReadVarPtr(void *);
extern void *Frontier_GetData(void *);
extern void *FrontierSystem_GetFrontierMap(void *);
extern void OS_ResetSystem(u32);
extern u16 sub_0203095C(void *);
extern void sub_02096910(void *);
extern void ov80_0223049C(void *, int);
extern u16 ov80_02230784(void *);
extern u16 ov80_02230790(void *);
extern u16 ov80_02230794(void *, u16);
extern void ov80_022307C8(void *);
extern void ov80_022307D4(void *);
extern void ov80_02230AE4(void *);
extern u16 ov80_02230B4C(void *);
extern u16 ov80_022372B4(void *);
extern void ov80_022371B0(void *);
extern void ov80_02237130(void *);
extern u32 ov80_02237120(void *);
extern u16 ov80_02237254(u32);
extern int ov80_02236DD4(u32);
extern int ov80_02236DF8(u32, u32);
extern void ov80_0222A140(void *, void *, u32);
extern void ov80_0222A474(void *, u16, u32, u32);
extern void ov80_0222A52C(void *, void *, void *, void *, int, int, int, int);
extern void *AllocMonZeroed(u32);
extern u32 GetMonData(void *, int, void *);
extern void Heap_Free(void *);
extern void *Party_GetMonByIndex(void *, int);
extern void *Mon_GetBoxMon(void *);
extern void BufferBoxMonSpeciesName(void *, int, void *);
extern void BgTilemapRectChangePalette(void *, int, int, int, int, int, int);
extern void ScheduleBgTilemapBufferTransfer(void *, int);
extern void *SysTask_CreateOnMainQueue(void (*)(void *, void *), void *, u32);
extern void SysTask_Destroy(void *);
extern void ov80_0222FC08(void *, void *);
int FrtCmd_103(void *);
