#ifndef OVERLAY_14_RESIDUAL_28_R40_PRIVATE_H
#define OVERLAY_14_RESIDUAL_28_R40_PRIVATE_H
#include "global.h"
typedef struct Ov14R28Data {
    u8 pad00[0x2c];
    u32 unk2c;
    u8 pad30[4];
    void *unk34;
} Ov14R28Data;
void ov14_021F6070(Ov14R28Data *data);
void ov14_021E875C(void *obj);
void ov14_021F0234(Ov14R28Data *data, void (*func)(void), u32 value);
void ov14_021E9618(void);
void ov14_021F6AC0(Ov14R28Data *data, u32 value, u32 state);
void ov14_021F29E4(void *obj, u32 value, u32 param);
void ov14_021F6844(Ov14R28Data *data, u32 value, u32 param);
void ov14_021F2A18(void *obj, u32 value, u32 param);
void ov14_021F6654(void *obj, u32 value);
void ov14_021F10DC(Ov14R28Data *data, u32 value);
void ov14_021E87BC(void *obj);
void ov14_021ED62C(Ov14R28Data *data);
u32 ov14_021ED650(Ov14R28Data *data);
void ov14_021ED684(Ov14R28Data *data);
void ov14_021ED6A4(Ov14R28Data *data);
#endif
