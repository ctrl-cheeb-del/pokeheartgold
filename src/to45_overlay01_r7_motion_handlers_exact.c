#include "global.h"

typedef void (*Ov01MotionCallback)(void *object, void *model, s8 *state, int facing);
typedef struct Ov01MotionState {
    s8 facing;
    u8 unused;
    s8 type;
    u8 flag : 1;
    u8 unusedFlags : 7;
} Ov01MotionState;

extern void *sub_0205F40C(void *object);
extern BOOL ov01_021FA2D4(void *object);
extern int MapObject_GetFacingDirection(void *object);
extern int sub_0205F330(void *object);
extern void GF_AssertFail(void);
extern void *MapObject_GetFacingVector(void *object);
extern void ov01_021FA3E8(void *object, void *model);
extern void ov01_021F8C88(void *object, void *model);
extern u32 ov01_021FA44C(int facing);
extern void sub_02023EE0(void *model, u32 value);
extern void sub_02023F40(void *model, fx32 value);
extern void ov01_021F8C64(void *model, u32 value);
extern void ov01_021F8C30(void *model);
extern BOOL ov01_021F9344(void *object);
extern void sub_02023F04(void *model, fx32 value);
extern const Ov01MotionCallback ov01_02208B34[];

void ov01_021F7E6C(void *object);
void ov01_021F7EE4(void *unused, void *model, Ov01MotionState *state, int facing);
void ov01_021F7F54(void *object, void *model, Ov01MotionState *state, int facing);

void ov01_021F7E6C(void *object) {
    int facing;
    int type;
    s8 *state = sub_0205F40C(object);
    void *model = *(void **)(state + 4);

    if (ov01_021FA2D4(object) != TRUE && model != NULL) {
        facing = MapObject_GetFacingDirection(object);
        type = sub_0205F330(object);
        if (type >= 10) {
            GF_AssertFail();
        }
        ov01_02208B34[type](object, model, state, facing);
        ((VecFx32 *)MapObject_GetFacingVector(object))->z = 2 << 10;
        state[0] = facing;
        state[2] = sub_0205F330(object);
        ov01_021FA3E8(object, model);
        ov01_021F8C88(object, model);
    }
}

void ov01_021F7EE4(void *unused, void *model, Ov01MotionState *state, int facing) {
#pragma unused(unused)
    if (facing != state->facing) {
        sub_02023EE0(model, ov01_021FA44C(facing));
        sub_02023F40(model, 0);
        state->flag = 0;
        return;
    }
    if (state->type == 9) {
        state->flag = 1;
        return;
    }
    if (state->flag == 1) {
        ov01_021F8C64(model, ov01_021FA44C(facing));
        state->flag = 0;
        return;
    }
    ov01_021F8C30(model);
}

void ov01_021F7F54(void *object, void *model, Ov01MotionState *state, int facing) {
    if (facing != state->facing) {
        sub_02023EE0(model, ov01_021FA44C(facing));
        sub_02023F40(model, 0);
    } else if (state->type == 9) {
        state->flag = 1;
        return;
    } else if (state->flag == 1) {
        ov01_021F8C64(model, ov01_021FA44C(facing));
        state->flag = 0;
    }
    if (!ov01_021F9344(object)) {
        sub_02023F04(model, 2 << 10);
    }
}
