#ifndef POKEHEARTGOLD_BATTLE_LINK_INTERNAL_H
#define POKEHEARTGOLD_BATTLE_LINK_INTERNAL_H
#include "global.h"

#include "battle/battle_setup.h"
#include "battle/battle_system.h"

#include "heap.h"
#include "string_util.h"
#include "sys_task.h"
#include "unk_02033AE0.h"
#include "unk_02035900.h"
#include "unk_020379A0.h"
typedef struct LinkWork {
    BattleSetup *setup;
    u8 pad4[12];
    SavePalPad *friends[4];
    union {
        u32 words[1024];
        Trainer trainer;
        SOUND_CHATOT chatot;
        SavePalPad palPad;
    } buffer;
    u8 received;
} LinkWork;
typedef struct LinkTask {
    BattleSystem *battle;
    u8 state;
} LinkTask;
typedef struct LinkHeader {
    u8 command, battler;
    u16 size;
} LinkHeader;
extern const u32 _020FFE30[];
int sub_02037190(void);
BOOL sub_02036FD8(int command, void *data, int size);
void sub_0203049C(int sender, u32 flags);
BOOL ov12_02264334(BattleSystem *battle, u8 *data);
void sub_02074E5C(BattleSystem *battle);
void sub_02074EC4(LinkWork *work);
u32 sub_02074ED8(void);
u32 sub_02074EDC(void);
u32 sub_02074EE4(void);
u32 sub_02074EEC(void);
u32 sub_02074EF4(void);
void *sub_02074EF8(int sender, LinkWork *work);
void *sub_02074F18(int sender, LinkWork *work);
void *sub_02074F38(int sender, LinkWork *work);
void *sub_02074F54(int sender, LinkWork *work);
void *sub_02074F74(int sender, LinkWork *work);
void *sub_02074F7C(int sender, LinkWork *work);
void *sub_02074F84(int sender, LinkWork *work);
void *sub_02074F8C(int sender, LinkWork *work);
void *sub_02074F94(int sender, LinkWork *work);
void sub_02074F9C(BattleSystem *battle, int command, int battler, u8 *data, u8 size);
void sub_02075028(int sender, int size, u8 *data, BattleSystem *battle);
BOOL sub_02075074(LinkWork *work, u32 value, ...);
void sub_020750B4(int sender, int unused, u32 *data, LinkWork *work);
BOOL sub_020750E0(LinkWork *work);
BOOL sub_02075108(LinkWork *work);
void sub_0207513C(int sender, int unused, void *data, LinkWork *work);
BOOL sub_0207514C(LinkWork *work);
BOOL sub_02075178(LinkWork *work);
void sub_020751A8(int sender, int unused, void *data, LinkWork *work);
BOOL sub_020751B8(LinkWork *work);
BOOL sub_020751DC(LinkWork *work);
void sub_02075210(int sender, int unused, void *data, LinkWork *work);
BOOL sub_02075220(LinkWork *work);
BOOL sub_02075248(LinkWork *work);
BOOL sub_0207527C(LinkWork *work);
BOOL sub_020752D8(LinkWork *work);
void sub_0207530C(int sender, int unused, void *data, LinkWork *work);
BOOL sub_0207531C(LinkWork *work, int index);
BOOL sub_02075350(LinkWork *work, int index, int command);
void sub_02075398(int sender, int unused, void *data, LinkWork *work);
BOOL sub_020753A8(LinkWork *work, int index);
BOOL sub_020753D4(LinkWork *work, int index, int command);
void sub_02075424(int sender, int unused, void *data, LinkWork *work);
void sub_02075434(SysTask *task, void *ptr);
void sub_020754C0(SysTask *task, void *ptr);
void sub_02075534(int sender, int unused, void *data, BattleSystem *battle);
void sub_02075554(PlayerProfile *profile, SavePalPad *friends, SavePalPad *out);
void sub_020755B4(int sender, int unused, SavePalPad *data, LinkWork *work);
u32 sub_020755E4(void);

#endif
