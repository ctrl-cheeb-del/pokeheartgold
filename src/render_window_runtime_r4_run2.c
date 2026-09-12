#include "render_window_runtime_r4_private.h"

void sub_0200F3D0(SysTask *task, WaitingIconRuntimeWork *data) {
    if (data->state != 0) {
        if (data->state == 1) {
            sub_0200F1D4(data, 2);
        }
        SysTask_Destroy(task);
        return;
    }
    data->tick++;
    if (data->tick == 0x10) {
        data->tick = 0;
        data->frame = (data->frame + 1) & 7;
        sub_0200F1D4(data, 0);
    }
}
