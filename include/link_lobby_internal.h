#ifndef POKEHEARTGOLD_LINK_LOBBY_INTERNAL_H
#define POKEHEARTGOLD_LINK_LOBBY_INTERNAL_H
#include "global.h"

#include "field_system.h"
#include "heap.h"
#include "party.h"
#include "sys_task.h"
#include "unk_02035900.h"
#include "unk_020379A0.h"
#include "unk_02037C94.h"
typedef void (*LobbyState)(void);
typedef struct Lobby {
    void *packets[4];
    u8 received[4];
    FieldSystem *fieldSystem;
    u8 pad18[24];
    LobbyState state;
    SysTask *task;
    u16 timer;
    u8 mode, pad3b, paused, pad3d, host, ready;
    Party *party;
} Lobby;
extern Lobby *_021D41C8;
void sub_02034434(void);
void ov03_02255C54(void);
void ov03_02255BEC(void);
BOOL sub_02034DB8(void);
void sub_02037E1C(u8);
BOOL sub_02037EC8(void);
u32 sub_02057180(void);
void sub_02056D7C(void *, FieldSystem *, int);
void sub_02057F80(void);
void sub_02034638(void);
void sub_02056E60(void);
void sub_0205701C(int);
BOOL sub_02057E50(void);
BOOL sub_02057C94(void);
void sub_020376E0(int, void *);
BOOL sub_02057F18(int);
void sub_02057F58(void);
void sub_02059538(FieldSystem *, void (*)(int, Party *));
BOOL sub_02036010(void);
void sub_02035FD8(void);
void sub_02035FE4(void);
void sub_02056EA0(int);
void sub_02037E38(void);
BOOL sub_02035664(void);
void sub_02037E9C(void);
BOOL sub_02036FD8(int, void *, int);
void sub_02058098(void);
void sub_020583EC(void);
void sub_02058518(void);
void sub_0205857C(void);
void sub_0205876C(void);
#include "encounter.h"
#include "screen_fade.h"
#include "unk_02091564.h"
void sub_0203778C(void *);
void sub_02037D8C(SaveData *, s32, s32, LinkBattleRuleset *, int);
void sub_02037DD4(SaveData *, u8, u32, LinkBattleRuleset *, int);
void sub_02039980(void *);
void sub_02058034(void);
void sub_02058038(FieldSystem *fieldSystem);
void sub_02058098(void);
void sub_020580E4(FieldSystem *fieldSystem, s32 arg1, s32 arg2);
void sub_02058124(FieldSystem *fieldSystem, u8 arg1, u32 arg2);
void sub_02058164(u16 mode);
void sub_02058180(void);
BOOL sub_02058258(void);
void sub_02058284(void);
void sub_020582A8(void);
void sub_020582CC(SysTask *task, void *unused);
void sub_020582F4(LobbyState state, u16 timer);
void sub_02058304(void);
void sub_02058328(void);
void sub_0205832C(void);
void sub_02058348(void);
void sub_0205834C(void);
void sub_0205836C(void);
void sub_02058388(void);
void sub_0205838C(void);
void sub_020583EC(void);
void sub_02058444(void);
void sub_02058478(void);
void sub_020584BC(void);
void sub_02058518(void);
void sub_02058608(void);
void sub_02058640(int start, Party *party);
void sub_02058690(void);
void sub_020586A0(void);
void sub_020586EC(void);
void sub_02058720(int sender, int unused, u8 *data);
BOOL sub_02058740(void);
void sub_0205876C(void);
void sub_020587E8(void);
void sub_0205882C(void);
void sub_02058854(void);
void sub_02058870(void);
void sub_020588A0(void);
void sub_020588B4(void);
void sub_020588CC(int index);
void *sub_020588DC(int index);
void sub_020588F8(void);
void sub_02058930(void);
void sub_0205896C(void);
void sub_020589B0(void);
void sub_020589D8(void);
void sub_020589F4(void);
void sub_02058A38(void);
void sub_02058A60(void);
void sub_02058A78(void);
BOOL sub_02058AA0(void);

void sub_02058034(void);
void sub_02058038(FieldSystem *fieldSystem);
void sub_02058098(void);
void sub_020580E4(FieldSystem *fieldSystem, s32 arg1, s32 arg2);
void sub_02058124(FieldSystem *fieldSystem, u8 arg1, u32 arg2);
void sub_02058164(u16 mode);
void sub_02058180(void);
BOOL sub_02058258(void);
void sub_02058284(void);
void sub_020582A8(void);
void sub_020582CC(SysTask *task, void *unused);
void sub_020582F4(LobbyState state, u16 timer);
void sub_02058304(void);
void sub_02058328(void);
void sub_0205832C(void);
void sub_02058348(void);
void sub_0205834C(void);
void sub_0205836C(void);
void sub_02058388(void);
void sub_0205838C(void);
void sub_020583EC(void);
void sub_02058444(void);
void sub_02058478(void);
void sub_020584BC(void);
void sub_02058518(void);
void sub_02058608(void);
void sub_02058640(int start, Party *party);
void sub_02058690(void);
void sub_020586A0(void);
void sub_020586EC(void);
void sub_02058720(int sender, int unused, u8 *data);
BOOL sub_02058740(void);
void sub_0205876C(void);
void sub_020587E8(void);
void sub_0205882C(void);
void sub_02058854(void);
void sub_02058870(void);
void sub_020588A0(void);
void sub_020588B4(void);
void sub_020588CC(int index);
void *sub_020588DC(int index);
void sub_020588F8(void);
void sub_02058930(void);
void sub_0205896C(void);
void sub_020589B0(void);
void sub_020589D8(void);
void sub_020589F4(void);
void sub_02058A38(void);
void sub_02058A60(void);
void sub_02058A78(void);
BOOL sub_02058AA0(void);

#endif
