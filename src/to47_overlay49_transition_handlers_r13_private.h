#ifndef TO47_OV49_R13_PRIVATE_H
#define TO47_OV49_R13_PRIVATE_H

#include "global.h"

typedef struct Ov49R13Interpolation {
    u32 raw[4];
} Ov49R13Interpolation;

typedef struct Ov49R13Position {
    u32 x;
    u32 z;
    u32 y;
} Ov49R13Position;

typedef struct Ov49R13Work {
    void *field;
    void *object;
    u16 state;
    u8 finished;
    u8 padding_0B;
    union {
        struct {
            s16 timer;
            s16 selected;
        };
        Ov49R13Interpolation interpolation;
    };
    u32 counter;
} Ov49R13Work;

extern const u8 ov49_02269658[];
extern const u8 ov49_0226965C[];

int ov42_02228188(void *, int);
void ov45_0223089C(void *, int);
void ov45_022308E4(void *, Ov49R13Position *);
void ov45_02230908(void *, Ov49R13Position *);
void ov45_0223093C(void *, int);
void ov45_02230968(void *);
void ov49_02258E7C(void *, Ov49R13Work *, int, int);
u8 ov49_02259294(const u8 *, u32);
BOOL ov49_022592A8(void *, Ov49R13Work *, int, int);
void ov49_02259320(Ov49R13Interpolation *, u32, u32, u32);
BOOL ov49_0225932C(Ov49R13Interpolation *, u32);
u32 ov49_022593BC(Ov49R13Interpolation *);
void PlaySE(u16);

void ov49_022594D8(Ov49R13Work *, void *);
void ov49_022595CC(Ov49R13Work *);
void ov49_0225967C(Ov49R13Work *);

#endif
