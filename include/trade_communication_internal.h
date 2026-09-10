#ifndef POKEHEARTGOLD_TRADE_COMMUNICATION_INTERNAL_H
#define POKEHEARTGOLD_TRADE_COMMUNICATION_INTERNAL_H
#include "global.h"

#include "save.h"
#include "save_palpad.h"
#include "save_special_ribbons.h"
#include "unk_02033AE0.h"
#include "unk_02035900.h"
#include "unk_02037C94.h"
typedef struct TradePacket {
    u32 data[0xFB];
} TradePacket;
typedef struct TradeWork {
    u8 pad0[0x5c];
    int sequence, state, count;
    u32 unk68;
    u32 slots[2];
    u8 pad74[0x24];
    u32 selection;
    u8 pad9c[0x2188];
    void *send, *receive;
    u32 unk222c;
    SavePalPad *palPad;
    u8 pad2234[0x98];
    u32 remoteState;
    u8 pad22d0[0x30];
    u8 buffers[2][0x590];
    TradePacket packets[2];
} TradeWork;
typedef struct TradeContext {
    u8 pad0[12];
    SaveData *saveData;
    u8 pad10[0x78];
    TradeWork *work;
} TradeContext;
extern const u32 _02105430[];
void ov65_0221DE24(TradeWork *, int, int);
void ov65_0221DE64(int, void *, int);

void sub_0208F658(TradeContext *context);
u32 sub_0208F66C(u32 slot);
void sub_0208F680(int sender, int unused, void *data, TradeContext *context);
void sub_0208F6F4(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F714(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F724(int sender, int unused, void *data, TradeContext *context);
void sub_0208F728(int sender, int unused, void *data, TradeContext *context);
void sub_0208F72C(int sender, int unused, void *data, TradeContext *context);
void sub_0208F738(int sender, int unused, void *data, TradeContext *context);
void sub_0208F73C(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F74C(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F77C(int sender, int unused, SavePalPad *data, TradeContext *context);
void sub_0208F7A8(int sender, int unused, void *data, TradeContext *context);
void sub_0208F7E0(TradeContext *context, TradeWork *work);
u32 sub_0208F7E8(void);
u32 sub_0208F7F0(void);
u32 sub_0208F7F4(void);
u32 sub_0208F7F8(void);
void *sub_0208F800(int sender, TradeContext *context);

void sub_0208F658(TradeContext *context);
u32 sub_0208F66C(u32 slot);
void sub_0208F680(int sender, int unused, void *data, TradeContext *context);
void sub_0208F6F4(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F714(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F724(int sender, int unused, void *data, TradeContext *context);
void sub_0208F728(int sender, int unused, void *data, TradeContext *context);
void sub_0208F72C(int sender, int unused, void *data, TradeContext *context);
void sub_0208F738(int sender, int unused, void *data, TradeContext *context);
void sub_0208F73C(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F74C(int sender, int unused, u8 *data, TradeContext *context);
void sub_0208F77C(int sender, int unused, SavePalPad *data, TradeContext *context);
void sub_0208F7A8(int sender, int unused, void *data, TradeContext *context);
void sub_0208F7E0(TradeContext *context, TradeWork *work);
u32 sub_0208F7E8(void);
u32 sub_0208F7F0(void);
u32 sub_0208F7F4(void);
u32 sub_0208F7F8(void);
void *sub_0208F800(int sender, TradeContext *context);

#endif
