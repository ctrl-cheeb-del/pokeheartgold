#include "global.h"
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
void *sub_0202C6F4(void *);
int sub_0202C090(void *, int, int);
void ov43_0222DC7C(void *, void *);
int ov43_0222DCC4(void *, int);
void CopyToBgTilemapRect(void *, u32, u32, u32, u32, u32, const void *, u32, u32, u32, u32);
void ScheduleBgTilemapBufferTransfer(void *, u32);
extern const u16 _0222ED5C[];
void *GfGfxLoader_GetScrnDataFromOpenNarc(void *, int, int, void **, int);
void ov43_0222DD40(void **, void *, int);
