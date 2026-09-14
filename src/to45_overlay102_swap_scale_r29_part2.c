#include "heap.h"
#include "overlay102_swap_scale_r29_private.h"
#include "sys_task_api.h"

void ScheduleBgTilemapBufferTransfer(void *, u8);

void ov102_021EB5B8(void *task, void *data) {
    Ov102SwapWork *work = data;

    switch (work->state) {
    case 0:
        ov102_021EB570((Ov102Owner *)work->owner, (u8)work->selection, 1);
        ov102_021EB570((Ov102Owner *)work->owner, (u8)(work->selection ^ 1), 0);
        ScheduleBgTilemapBufferTransfer(*(BgConfig **)(work->owner + 0x10), 3);
        work->count++;
        work->state++;
        break;
    case 1:
        work->timer++;
        if (work->timer >= 4) {
            *(void **)(work->owner + 0x64) = NULL;
            Heap_Free(work);
            SysTask_Destroy(task);
        }
        break;
    }
}
