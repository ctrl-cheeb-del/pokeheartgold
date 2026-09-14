#ifndef TO45_OV01_MOTION_SEQUENCES_R5_PRIVATE_H
#define TO45_OV01_MOTION_SEQUENCES_R5_PRIVATE_H

#include "global.h"

typedef struct Ov01MotionStateR5 {
    s16 index;
    s8 previousDirection;
    s8 kind;
} Ov01MotionStateR5;

typedef struct Ov01Table4R5 {
    u32 values[4];
} Ov01Table4R5;
typedef struct Ov01Table7R5 {
    u32 values[7];
} Ov01Table7R5;
typedef struct Ov01Table8R5 {
    u32 values[8];
} Ov01Table8R5;

void ov01_021F7A90(void *owner, void *object, s8 *state, int direction);
void ov01_021F7B14(void *owner, void *object, s8 *state, int direction);
void ov01_021F7B90(void *owner, void *object, s8 *state, int direction);
void ov01_021F7C80(void *owner, void *object, const s8 *state, int direction);

#endif
