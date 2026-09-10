#include "global.h"

extern void Heap_Free(void *);
extern void GF_AssertFail(void);
extern void OamManager_ApplyAndResetBuffers(void);
extern void ov99_021E59588(void); /* unused compatibility declaration */
extern void ov99_021E7CE4(void *, int, int, int);
extern void *ov99_021E9430(void *);
extern int ov98_0221F024(void *);
extern void ov98_0221EF80(int);
extern int Pokedex_GetSeenSpindaPersonality(void *, int);
extern int MATH_CountPopulation(u32);
extern void ov99_021E89A4(void *);
extern void ov99_021E9038(void *);
extern void GridInputHandler_Free(void *);
extern void GridInputHandler_SetNextInput(void *, u8);
extern void ov99_021E7C58(void *, int);
extern void String_Delete(void *);
extern void *Heap_Alloc(int, u32);
extern void SysTask_Destroy(void *);
extern void ov98_0221EBD8(void *, int, int, int);
extern void ov98_0221EE84(void *, int);
extern void ov98_0221EBEC(void *, int, int, int, int, int);
extern void *ov98_0221E6E0(void *, const void *);
extern void ManagedSprite_SetAnimateFlag(void *, BOOL);
extern const u8 ov99_021E9E2C[];

void *ov99_021E5B70(void **p);
int ov99_021E714C(void);
void ov99_021E7CC8(void);
void ov99_021E5B74(void *p);
void ov99_021E7060(void *p);
void *ov99_021E7150(void **p);
void *ov99_021E71DC(void **p);
void *ov99_021E945C(void **p);
u8 ov99_021E7180(void **p, int index);
int ov99_021E718C(void **p);
void ov99_021E724C(void **p);
void ov99_021E7CCC(void *a, int b, int c);
void ov99_021E7CD8(void *a, int b, int c);
void *ov99_021E94FC(void *p);
u8 ov99_021E7068(u8 *p);
u8 ov99_021E7078(u8 *p);
u8 ov99_021E7088(u8 *p);
void *ov99_021E7098(void **p);
u16 ov99_021E70A8(u8 *p);
u16 ov99_021E70B8(u8 *p);
u16 ov99_021E70C8(u8 *p);
u16 ov99_021E70D8(u8 *p);
u16 ov99_021E70E8(u8 *p, int index);
u32 ov99_021E723C(void **p);
BOOL ov99_021E7198(void **p, int index);
void ov99_021E8818(void *p);
void *ov99_021E9508(void **p);
void *ov99_021E5B7C(void **p, int row, int col);
void ov99_021E9418(u8 *p);
void ov99_021E5B54(void **p, const u32 *src);
void ov99_021E7CA8(u8 *p, int input);
void ov99_021E9020(void **p);
void ov99_021E88D4(void **p);
void ov99_021E6C14(void **p);

void ov99_021E6C14(void **p) {
    void *sprite = ov98_0221E6E0(p[5], ov99_021E9E2C);
    p[6] = sprite;
    ManagedSprite_SetAnimateFlag(sprite, TRUE);
}
