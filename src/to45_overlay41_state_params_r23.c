#include "global.h"

typedef struct Ov41R23Work {
    u8 padding_000[0x40];
    u32 field_040;
    u32 field_044;
    u8 field_048[0x138];
    u32 field_180;
    u8 padding_184[0x1E4];
    u8 field_368[0x348];
    u32 state_6B0;
} Ov41R23Work;

typedef struct Ov41R23Params {
    u32 field_00;
    u32 field_04;
    void *field_08;
    void *field_0C;
    u32 field_10;
    u32 field_14;
    u32 field_18;
    u32 field_1C;
    u32 field_20;
    u32 field_24;
} Ov41R23Params;

int ov41_0224895C(void *context, int state);
void ov41_022487F8(void *context, int state, int value);
void ov41_0224AA08(void *context, Ov41R23Params *params, int count, void *argument);
void ov41_022475F4(void *unused, Ov41R23Work *work);
void ov41_02247628(void *unused, Ov41R23Work *work);
void ov41_0224765C(Ov41R23Work *work, void *argument);

void ov41_022475F4(void *unused, Ov41R23Work *work) {
    int value;

    if (work->state_6B0 != 0) {
        value = ov41_0224895C(work->field_368, 0);
        ov41_022487F8(work->field_368, 0, value);
        work->state_6B0 = 0;
    }
}

void ov41_02247628(void *unused, Ov41R23Work *work) {
    int value;

    if (work->state_6B0 != 1) {
        value = ov41_0224895C(work->field_368, 1);
        ov41_022487F8(work->field_368, 1, value);
        work->state_6B0 = 1;
    }
}

void ov41_0224765C(Ov41R23Work *work, void *argument) {
    Ov41R23Params params = { 0 };

    params.field_00 = work->field_040;
    params.field_04 = work->field_044;
    params.field_08 = work->field_048;
    params.field_0C = argument;
    params.field_10 = 10;
    params.field_24 = work->field_180;
    ov41_0224AA08(work->field_368 + 0x200, &params, 15, argument);
}
