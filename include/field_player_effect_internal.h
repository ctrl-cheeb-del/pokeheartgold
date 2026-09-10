#ifndef POKEHEARTGOLD_FIELD_PLAYER_EFFECT_INTERNAL_H
#define POKEHEARTGOLD_FIELD_PLAYER_EFFECT_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "mail_message.h"
#include "map_object.h"
#include "player_data.h"
#include "pm_string.h"
#include "save.h"
#include "save_palpad.h"
#include "sys_task_api.h"
#include "task.h"
#include "unk_02005D10.h"
#include "unk_02062108.h"
#include "unk_0206793C.h"
#include "unk_020689C8.h"

typedef struct {
    u8 unk0;
    u8 state;
    u8 effect;
    u8 trigger;
    u8 active;
    u8 pad5;
    u16 timer;
    u8 sprite;
    u8 pad9[3];
    void *unkC;
    struct UnkStruct_0206793C *effect1;
    struct UnkStruct_0206793C *effect2;
} Slot;

typedef struct {
    u8 padC[12];
    u8 unk0;
    u8 state;
    u8 effect;
    u8 trigger;
    u8 active;
    u8 pad11;
    u16 timer;
    u8 sprite;
    u8 pad15[3];
    void *unkC;
    struct UnkStruct_0206793C *effect1;
    struct UnkStruct_0206793C *effect2;
} SlotCursor;

typedef struct {
    String *string0;
    String *string1;
    String *string2;
    u32 unkC;
    u32 unk10;
    MailMessage message;
} MessageSlot;

typedef struct {
    void *fieldSystem;
    SysTask *task;
    LocalMapObject *avatar;
    Slot slots[51];
    void *remote;
    void *palPad;
    MessageSlot *messages;
    u32 enabled;
    u32 pad4E4;
} Manager;

typedef struct {
    u8 pad0[0xC];
    SaveData *saveData;
    u8 pad10[0x2C];
    MapObjectManager *objectManager;
    LocalMapObject *avatar;
} RemoteState;

extern void GF_AssertFail(void);
extern void sub_0205FC94(LocalMapObject *, u32);
extern void sub_0205E3AC(LocalMapObject *, u32);
extern void *ov01_021FD8E8(LocalMapObject *, int);
extern void *ov01_02200730(LocalMapObject *);
extern BOOL sub_02037FCC(void);
extern BOOL sub_02037F94(void);
extern RemoteState *sub_0205A1F0(void *);
extern void *sub_0205A1F4(void *, int);
extern void sub_0205AEA8(Manager *, void *, MapObjectManager *, void *);
extern void sub_0205AF78(Manager *, MapObjectManager *);
extern BOOL sub_0205AD9C(Manager *, int, void *, void *);
extern const u16 _020FC824[];

void sub_0205B0DC(Slot *, BOOL);
void sub_0205B118(Slot *);
void sub_0205B13C(Slot *, LocalMapObject *, u32, u32);
void sub_0205B1E4(Slot *, LocalMapObject *);
void sub_0205B218(Slot *, LocalMapObject *);
void sub_0205B240(MapObjectManager *, int, int);
void sub_0205AEA0(u8 *, int, u8);
void sub_0205B338(MessageSlot *);
void sub_0205B35C(MessageSlot *);
void sub_0205B380(MessageSlot *);
void sub_0205B3A0(MessageSlot *);
MessageSlot *sub_0205B3B8(int);
void sub_0205B3CC(MessageSlot *);
void sub_0205AD0C(Manager *);
void sub_0205AD24(Manager *);
void sub_0205AD3C(Manager *);
void sub_0205B27C(MapObjectManager *, Manager *);
void sub_0205AD60(SysTask *, void *);
Manager *sub_0205AC88(void *);

Manager *sub_0205AC88(void *fieldSystem);
BOOL sub_0205AD9C(Manager *manager, int group, void *recordArg, void *palPad);
void sub_0205AEA8(Manager *manager, void *fieldSystem, MapObjectManager *objectManager, void *palPad);
void sub_0205AD0C(Manager *manager);
void sub_0205AD24(Manager *manager);
void sub_0205AD3C(Manager *manager);
void sub_0205AD60(SysTask *task, void *data);
void sub_0205B0DC(Slot *slot, BOOL both);
void sub_0205B118(Slot *slot);
void sub_0205B13C(Slot *slot, LocalMapObject *object, u32 x, u32 z);
void sub_0205B1E4(Slot *slot, LocalMapObject *object);
void sub_0205B218(Slot *slot, LocalMapObject *object);
void sub_0205B240(MapObjectManager *manager, int first, int last);
void sub_0205B27C(MapObjectManager *objectManager, Manager *manager);
void sub_0205AEA0(u8 *slots, int index, u8 value);
void sub_0205B338(MessageSlot *slot);
void sub_0205B35C(MessageSlot *slots);
void sub_0205B380(MessageSlot *slot);
void sub_0205B3A0(MessageSlot *slots);
MessageSlot *sub_0205B3B8(int heapId);
void sub_0205B3CC(MessageSlot *slots);

#endif
