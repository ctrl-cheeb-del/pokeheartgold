#ifndef TO42_OV45_R35_LANDING_PRIVATE_H
#define TO42_OV45_R35_LANDING_PRIVATE_H
#include "global.h"
extern u8 *_022577C0;
typedef void (*Ov45Callback1)(void *, void *);
typedef void (*Ov45Callback2)(void *, void *, void *);
typedef struct Ov45Pair {
    u32 lo, hi;
} Ov45Pair;
extern void GF_AssertFail(void);
extern int ov45_0222FB24(void *, int, int);
extern void ov45_0222F88C(void *, int, void *);
extern void ov45_0222F928(void *, int, const void *);
extern int ov45_022301E0(void *, int, u32);
extern int ov45_0223021C(void *, int);
extern u16 ov45_0223023C(void *, int);
extern void *ov45_022302B0(void *, int);
extern void ov45_02230384(const void *, u32 *);
#endif
