#ifndef POKEHEARTGOLD_UNK_0205AA9C_PRIVATE_H
#define POKEHEARTGOLD_UNK_0205AA9C_PRIVATE_H
#include "global.h"

#include "easy_chat.h"
#include "message_format.h"
#include "msgdata.h"
#include "player_data.h"

extern const s32 _020FC898[7];
PlayerProfile *sub_02035798(int objId);
PlayerProfile *sub_02034818(int netId);
int sub_0203769C(void);
void sub_0205AA9C(MessageFormat *msgFmt, u16 mode, u16 objId, PlayerProfile *profile, SaveEasyChat *easyChat);
#endif
