#include "global.h"
extern u8 *_022577C0;
extern void GF_AssertFail(void);
extern int ov45_0222FB24(void *, int, int);
extern int ov45_0222FB5C(void *, int, int);
extern int ov45_0222F7B4(void *);
extern int ov45_0223021C(void *, int);
extern void *ov45_022302B0(void *, int);
extern void ov45_02230434(void *, int);
extern void ov45_0223045C(void *, int);
extern int ov45_02232E60(int);
u32 ov45_0222F3E8(int);
void ov45_0222F4D4(int);
u8 ov45_0222F6B0(int, int);
extern void ov00_021E5CD0(int, int);
extern void ov00_021E5CA0(int, int);
extern void *ov45_02232580(void);
extern void ov45_0222E810(void *, int);
extern int ov45_02231490(void);
extern void ov45_0222F88C(void *, void *, int);
extern void ov45_022325B0(void *, void *, int);
extern void *ov45_0222F954(void *, int);
void ov45_0222E804(void *);
void ov45_0222E91C(void);
void ov45_0222E9F8(void *);
void ov45_0222EA4C(int, void *);
void ov45_0222EB94(void);
void ov45_0222EE80(void);
void ov45_0222EEB8(void);
extern void ov45_0222F8D8(void *, int);
extern void ov45_0222FBD8(void *, int);
extern int ov45_0222F7B0(int);
extern int ov45_02231C8C(int);
extern int ov45_02231EC0(void);
extern int ov45_0223247C(int, int, int, int);
extern int ov45_02232500(int, int, int, int);
extern int ov45_02232CA4(void);
extern int ov45_022301E0(void *, int, void *);
extern int ov45_02232BB0(void *);
extern int ov45_022303BC(void *, int);
void *ov45_0222E9E0(void);
void ov45_0222EA2C(int);
u8 ov45_0222EB74(void);
BOOL ov45_0222EBC4(void);
void ov45_0222EBF0(int);
void ov45_0222EC10(void *);
void ov45_0222EC3C(void *);
int ov45_0222EA78(void);
int ov45_0222EAD4(int);
void ov45_0222EB38(int);
void ov45_0222EEF0(int, int, int);
void ov45_0222EF4C(int, int, int, int);
void ov45_0222EFAC(int, int, int);
void ov45_0222F154(void);
void ov45_0222F1BC(void);
u32 ov45_0222ECDC(int);
u32 ov45_0222F544(int);
void *ov45_0222F628(int);

typedef struct Ov45Pair {
    u32 lo;
    u32 hi;
} Ov45Pair;
typedef struct Ov45PairOut {
    u32 lo;
    u32 hi;
} Ov45PairOut;
typedef struct Ov45SmallState {
    u8 pad_000[0x12d];
    u8 mode;
    u8 state;
    u8 flag;
} Ov45SmallState;

int ov45_0222E8F4(void);
int ov45_0222E944(void);
int ov45_0222E96C(void);
u8 ov45_0222E9BC(void);
int ov45_0222EC68(int x);
int ov45_0222EC7C(int x);
int ov45_0222EC90(int x);
int ov45_0222ECA4(int x);
void ov45_0222ECB8(void *out);
void ov45_0222ED7C(void);
BOOL ov45_0222EDA8(void);
u16 ov45_0222EDC4(int i);
u8 ov45_0222EDF0(int i);
void ov45_0222EE20(u32 a, u32 b, u32 c);
void ov45_0222EE50(u32 a, u32 b, u32 c);
int ov45_0222F218(void);
u8 ov45_0222F254(void);
int ov45_0222F274(int i);
BOOL ov45_0222F294(int i);
int ov45_0222F2D4(int i);
u32 ov45_0222F314(int i);
int ov45_0222F430(void);
u8 ov45_0222F464(void);
void ov45_0222F484(int x);
void ov45_0222F4AC(int x);
u32 ov45_0222F524(void);
void ov45_0222F70C(void);
BOOL ov45_0222F74C(int x);
void ov45_0222F78C(void);

void ov45_0222F154(void) {
    u8 *state;
    void *context;
    if (_022577C0 == NULL) {
        GF_AssertFail();
    }
    if (*(u16 *)(_022577C0 + 0x69c) != 3 && _022577C0[0x69e] != 0) {
        if (ov45_0222F74C(ov45_02232CA4()) == 0) {
            GF_AssertFail();
        }
        state = _022577C0;
        context = ov45_02232580();
        if (ov45_022301E0(state, *(u16 *)(state + 0x69c), context) == 0) {
            GF_AssertFail();
        }
        _022577C0[0x69e] = 0;
    }
}
