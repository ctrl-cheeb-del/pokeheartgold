#ifndef POKEHEARTGOLD_TO45_OVERLAY41_TRANSITION_TASKS_R46_PRIVATE_H
#define POKEHEARTGOLD_TO45_OVERLAY41_TRANSITION_TASKS_R46_PRIVATE_H

#include "global.h"

#include "sys_task.h"

typedef struct Ov41R46Main {
    u8 padding_00[8];
    void *work;
    u8 padding_0C[4];
    void *object;
    u8 padding_14[0x1C];
    s32 moving;
} Ov41R46Main;

typedef struct Ov41R46MoveTask {
    void *work;
    void *object;
    s32 stepX;
    s32 stepY;
    s32 destinationX;
    s32 destinationY;
    s32 argument5;
    s32 argument6;
    s32 duration;
    s32 *stopFlag;
    s32 *moving;
} Ov41R46MoveTask;

typedef struct Ov41R46MessageMode {
    s32 *argument;
    s32 mode;
} Ov41R46MessageMode;

typedef struct Ov41R46MessageContext {
    u8 padding_00[0xC];
    void *work;
    Ov41R46MessageMode *message;
} Ov41R46MessageContext;

typedef struct Ov41R46DragState {
    u8 padding_00[4];
    void *work;
    u8 padding_08[8];
    void *object;
    u8 padding_14[0x10];
    s32 x;
    s32 y;
} Ov41R46DragState;

typedef struct Ov41R46NarcMember {
    u16 narcId;
    u16 memberId;
} Ov41R46NarcMember;

typedef struct Ov41R46PictureResource {
    u8 padding_00[0x14];
    u8 *rawData;
} Ov41R46PictureResource;

void ov41_02249480(Ov41R46Main *main, s32 duration, s32 destinationX, s32 destinationY, s32 argument5, s32 argument6);
void ov41_022494F4(SysTask *task, Ov41R46MoveTask *environment);
void ov41_02249574(Ov41R46MessageContext *context);
void ov41_022495A4(Ov41R46DragState **state, s32 x, s32 y);
void ov41_022495C8(void *work, const Ov41R46NarcMember *member);

void ov41_02249B44(void *object, s32 *x, s32 *y);
void ov41_02249AF4(void *object, s32 x, s32 y);
void ov41_022486C4(void *work, s32 argument5, s32 argument6, void *object);
void ov41_02248724(void *work);
void ov41_022463FC(void);
void ov41_0224AC08(void *work, s32 group, s32 message, s32 argument);
void ov41_02248114(void *work, s32 deltaX, s32 deltaY);
Ov41R46PictureResource *ov41_022463DC(void *work, void *data, u32 index);

#endif
