#include "overlay89_r8_private.h"

BOOL ov89_0225A49C(void *context, Ov89Work *work, const Ov89Object *input, int arg3, void *arg4, int arg5) {
    int i;

    if (work->active != 0) {
        return FALSE;
    }
    for (i = 0; i < 128; i++) {
        if (work->objects[i] == NULL) {
            work->objects[i] = ov89_0225A7BC(context, work, input, arg3, arg4, arg5);
            if (work->objects[i] != NULL) {
                return TRUE;
            }
            return FALSE;
        }
    }
    return FALSE;
}
