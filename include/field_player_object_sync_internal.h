#ifndef POKEHEARTGOLD_FIELD_PLAYER_OBJECT_SYNC_INTERNAL_H
#define POKEHEARTGOLD_FIELD_PLAYER_OBJECT_SYNC_INTERNAL_H
#include "global.h"

#include "map_object.h"
#include "player_avatar.h"
#include "save_palpad.h"
#include "unk_02062108.h"

typedef struct {
    u8 status;
    u8 state;
    u8 effect;
    u8 trigger;
    u8 active;
    u8 pad5;
    u16 timer;
    u8 sprite;
    u8 effectStarted;
    u8 padA[2];
    void *identity;
    void *effect1;
    void *effect2;
} PlayerEffectSlot;

typedef struct {
    u8 padC[12];
    u8 status;
    u8 state;
    u8 effect;
    u8 trigger;
    u8 active;
    u8 pad11[3];
    u8 sprite;
    u8 effectStarted;
} PlayerEffectCursor;

typedef struct {
    void *fieldSystem;
    void *task;
    PlayerAvatar *avatar;
    PlayerEffectSlot slots[51];
    void *remote;
    SavePalPad *palPad;
    void *messages;
    u32 enabled;
    u32 pad4E4;
} PlayerEffectManager;

extern const u16 _020FC824[];
extern void GF_AssertFail(void);
extern void sub_0205AEA0(u8 *, int, u8);
extern void sub_0205B0DC(PlayerEffectSlot *, BOOL);
extern void sub_0205B118(PlayerEffectSlot *);
extern void sub_0205B13C(PlayerEffectSlot *, LocalMapObject *, u32, u32);
extern void sub_0205B1E4(PlayerEffectSlot *, LocalMapObject *);
extern void sub_0205B218(PlayerEffectSlot *, LocalMapObject *);
extern void sub_0205FC94(LocalMapObject *, u32);

BOOL sub_0205AD9C(PlayerEffectManager *, int, void *, SavePalPad *);
void sub_0205AF78(PlayerEffectManager *, MapObjectManager *);

BOOL sub_0205AD9C(PlayerEffectManager *manager, int group, void *record, SavePalPad *palPad);
void sub_0205AF78(PlayerEffectManager *manager, MapObjectManager *objectManager);

#endif
