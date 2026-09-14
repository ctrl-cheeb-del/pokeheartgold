#include "global.h"

#include "gf_gfx_loader.h"
#include "pokepic.h"
#include "systask_environment.h"
#include "to45_overlay41_transition_tasks_r46_private.h"

void ov41_02249480(Ov41R46Main *main, s32 duration, s32 destinationX, s32 destinationY, s32 argument5, s32 argument6) {
    s32 currentX;
    s32 currentY;
    Ov41R46MoveTask *environment = SysTask_GetData(CreateSysTaskAndEnvironment((SysTaskFunc)ov41_022494F4, sizeof(Ov41R46MoveTask), 0, HEAP_ID_13));

    environment->work = main->work;
    environment->object = main->object;
    environment->duration = duration;
    environment->destinationX = destinationX;
    environment->destinationY = destinationY;
    environment->argument5 = argument5;
    environment->argument6 = argument6;
    environment->stopFlag = (s32 *)((u8 *)main->work + 0x3C);
    environment->moving = &main->moving;
    ov41_02249B44(main->object, &currentX, &currentY);
    environment->stepX = (environment->destinationX - currentX) / duration;
    environment->stepY = (environment->destinationY - currentY) / duration;
    main->moving = 0;
}

void ov41_022494F4(SysTask *task, Ov41R46MoveTask *environment) {
    s32 x;
    s32 y;

    if (*environment->stopFlag != 1) {
        ov41_02249B44(environment->object, &x, &y);
        x += environment->stepX;
        y += environment->stepY;
        environment->duration--;
        if (environment->duration < 0 || (environment->stepX == 0 && environment->stepY == 0)) {
            ov41_02249AF4(environment->object, environment->destinationX, environment->destinationY);
            ov41_022486C4(environment->work, environment->argument5, environment->argument6, environment->object);
            ov41_02248724(environment->work);
            if (*environment->moving == 0) {
                ov41_022463FC();
            }
            DestroySysTaskAndEnvironment(task);
            return;
        }
        ov41_02249AF4(environment->object, x, y);
    }
}

void ov41_02249574(Ov41R46MessageContext *context) {
    if (context->message->mode == 0) {
        ov41_0224AC08(context->work, 0x1B, 0xD8, *context->message->argument);
    } else if (context->message->mode == 1) {
        ov41_0224AC08(context->work, 0x1B, 0xDA, *context->message->argument);
    }
}

void ov41_022495A4(Ov41R46DragState **statePtr, s32 x, s32 y) {
    Ov41R46DragState *state = *statePtr;

    ov41_02249AF4(state->object, x, y);
    ov41_02248114(state->work, x - state->x, y - state->y);
    state->x = x;
    state->y = y;
}

void ov41_022495C8(void *work, const Ov41R46NarcMember *member) {
    void *data = GfGfxLoader_LoadFromNarc((NarcId)member->narcId, member->memberId, FALSE, HEAP_ID_14, FALSE);
    Ov41R46PictureResource *resource = ov41_022463DC(work, data, 0x76);

    UnscanPokepic(resource->rawData, (NarcId)member->narcId);
}
