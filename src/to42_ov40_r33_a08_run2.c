#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define BYTE(p, off) (*(u8 *)((u8 *)(p) + (off)))
#define SHRT(p, off) (*(s16 *)((u8 *)(p) + (off)))

typedef struct Ov40Tbl {
    s32 e[2][6];
} Ov40Tbl;

extern Ov40Tbl ov40_0224551C;
extern Ov40Tbl ov40_0224554C;

BOOL sub_0202FC48(void);
void *sub_02030920(int heapId);
void *sub_020314A4(int heapId);
void MI_CpuCopy8(const void *src, void *dest, u32 size);
void ManagedSprite_SetDrawFlag(void *sprite, BOOL draw);
void ManagedSprite_SetDrawPriority(void *sprite, int priority);
BOOL SpriteManager_UnloadCharObjById(void *manager, u32 id);
void ov39_022271C0(const void *src, void *dst);
void ov40_0222BF80(void *p, int state);
void ov40_0222DEAC(void *p);
void *ov40_0222FEA0(void *p, void *a1, void *a2, u32 a3, u32 a4, int a5);
void ov40_0222FF48(void *p, void *a1, void *a2);
void ov40_0222FF64(void *p, void *a1, void *a2);
int ov40_022303B8(void *p);
void ov40_02230944(void *p);
void ov40_02230964(void *p, int value);
void ov40_0223A3BC(void *p);
void ov40_0223CE38(void *p);

void ov40_0223CE64(u32 a, int b, void *p);
void ov40_0223CF00(u32 a, int b, void *p);
void ov40_0223CF70(u32 a, int b, void *p);
void ov40_0223CFA8(void *p);
void ov40_0223D008(void *p);
void ov40_0223D1AC(void *p, BOOL draw);
void ov40_0223D1F0(void *p);
void ov40_0223D244(void *p);

void ov40_0223CE64(u32 a, int b, void *p);
void ov40_0223CF00(u32 a, int b, void *p);
void ov40_0223CF70(u32 a, int b, void *p);
void ov40_0223CFA8(void *p);
void ov40_0223D008(void *p);
void ov40_0223D244(void *p);

void ov40_0223D1AC(void *p, BOOL draw) {
    int i;
    int j;
    u8 *q;

    for (j = 0, q = PTR(p, 0x860); j < 5; q += 0x30, j++) {
        u8 *r = q;
        for (i = 0; i < 6; i++, r += 8) {
            if (PTR(r, 0x2090) != NULL) {
                ManagedSprite_SetDrawFlag(PTR(r, 0x2090), draw);
            }
        }
    }
}

void ov40_0223D1F0(void *p) {
    int i;
    int j;
    u8 *q;

    for (j = 0, q = PTR(p, 0x860); j < 5; q += 0x30, j++) {
        u8 *r = q;
        for (i = 0; i < 6; i++, r += 8) {
            if (PTR(r, 0x2090) != NULL) {
                ov40_0222FF48(p, PTR(r, 0x208c), PTR(r, 0x2090));
                PTR(r, 0x2090) = NULL;
            }
        }
    }
}
