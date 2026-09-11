#include "global.h"

#include "hblank_fade_pair_internal.h"

void sub_0200FEE4(FadeBlankPair *data, u32 value, FadeBlankFunc func, int index) {
    u8 installed = TRUE;
    u32 *active = &data->active[index];

    if (*active != 0) {
        GF_AssertFail();
    }
    if (data->funcs[index] == NULL) {
        GF_AssertFail();
    }
    if (data->active[0] == 0 && data->active[1] == 0) {
        installed = Main_SetHBlankIntrCB((void (*)(void *))sub_0200FECC, data);
    }
    if (installed != TRUE) {
        GF_AssertFail();
    }
    data->values[index] = value;
    if (func != NULL) {
        data->funcs[index] = func;
    } else {
        data->funcs[index] = sub_02010014;
    }
    *active = TRUE;
}
