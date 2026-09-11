#ifndef TO30_SOL_R5_UNK_0205CC94_PRIVATE_H
#define TO30_SOL_R5_UNK_0205CC94_PRIVATE_H

#include "global.h"

#include "constants/sndseq.h"

#include "map_object.h"
#include "metatile_behavior.h"
#include "player_avatar.h"
#include "unk_02005D10.h"
#include "unk_02062108.h"

typedef struct FootstepEntry {
    u16 sequence;
    u16 special;
} FootstepEntry;

u16 sub_0205F504(LocalMapObject *);
int sub_02062390(int);
int sub_02060FA8(LocalMapObject *, int);
int sub_02060FE0(LocalMapObject *, int);
BOOL sub_0205DE64(int);
BOOL sub_0205DE98(PlayerAvatar *);
int sub_0205D01C(PlayerAvatar *, int);
void sub_0205CC94(PlayerAvatar *);
void sub_0205CD70(LocalMapObject *, PlayerAvatar *);
void sub_02005BA8(u16);
void PlayerAvatar_UpdateMovement(PlayerAvatar *);

extern const FootstepEntry _020FCB98[];

#endif
