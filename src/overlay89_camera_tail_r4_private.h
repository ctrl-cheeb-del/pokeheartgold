#ifndef POKEHEARTGOLD_TO47_OVERLAY89_TAIL_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY89_TAIL_PRIVATE_H

#include "bg_window.h"
#include "camera.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"
#include "string_util.h"
#include "text.h"

int GF_SinDegFX32(int angle);
void PlaySE(int se);
void GF_AssertFail(void);
int ov45_0222EC7C(void *network);
int ov45_0222EC68(void *network);
void *ov45_0222A578(void *context, int slot);
void ov45_0222A844(void *record, PlayerProfile *profile, enum HeapID heapId);
int ov45_0222AB28(void *context, int slot);

int ov89_0225C498(void *unused, u8 *work, Camera *camera);
int ov89_0225C570(void *unused, u8 *work, Camera *camera);
int ov89_0225C648(void *unused, u8 *work, Camera *camera);
void ov89_0225C724(MsgData *msgData, MessageFormat *format, Window *windows, void *context, void *network);

#endif
