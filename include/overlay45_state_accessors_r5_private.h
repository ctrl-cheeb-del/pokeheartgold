#ifndef OVERLAY45_STATE_ACCESSORS_R5_PRIVATE_H
#define OVERLAY45_STATE_ACCESSORS_R5_PRIVATE_H
#include "global.h"
typedef struct Overlay45State {
    u8 pad_000[8];
    u32 unk_008;
    u8 pad_00c[0x1f0];
    u8 flag0 : 1;
    u8 flag1 : 1;
    u8 mode2 : 2;
    u8 flag4 : 1;
    u8 mode5 : 2;
    u8 flag7 : 1;
    u8 value_1fd;
    u8 value_1fe;
    u8 value_1ff;
    s16 value_200;
    s16 value_202;
    s16 value_204;
    s16 value_206;
    u8 pad_208[3];
    u8 low : 4;
    u8 high : 4;
} Overlay45State;
extern int ov45_0222ECDC(int);
int ov45_0222A2CC(void *);
u32 ov45_0222A2E0(Overlay45State *);
u32 ov45_0222A2F8(Overlay45State *);
void ov45_0222A310(Overlay45State *);
u32 ov45_0222A324(Overlay45State *);
u32 ov45_0222A330(Overlay45State *);
BOOL ov45_0222A33C(Overlay45State *);
u32 ov45_0222A35C(Overlay45State *);
BOOL ov45_0222A374(Overlay45State *);
u32 ov45_0222A394(Overlay45State *);
BOOL ov45_0222A3A0(Overlay45State *);
u32 ov45_0222A3BC(Overlay45State *);
u32 ov45_0222A3D4(Overlay45State *);
u32 ov45_0222A3EC(Overlay45State *);
#endif
