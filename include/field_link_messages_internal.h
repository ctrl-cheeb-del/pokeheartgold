#ifndef POKEHEARTGOLD_FIELD_LINK_MESSAGES_INTERNAL_H
#define POKEHEARTGOLD_FIELD_LINK_MESSAGES_INTERNAL_H

#include "global.h"

#include "mail_message.h"
#include "player_data.h"

struct UnkStruct_02059E1C {
    u32 unk00;
    u32 unk04;
    PlayerProfile *unk08;
    u8 pad0C[0x20 - 0x0C];
    u32 unk20;
    u32 unk24;
    u32 unk28;
    u32 unk2C;
    u32 unk30;
    u32 unk34;
    u8 pad38[0x40 - 0x38];
    u32 unk40;
    u32 unk44;
    u8 pad48[0x174 - 0x48];
    u16 unk174;
    u8 unk176[2];
    u8 unk178[8];
    u32 unk180;
    void *unk184;
    void *unk188[2];
};

struct MessageFormat;

struct UnkSub_0205AA4C {
    u32 unk00[4];
    u8 unk10[4];
    u8 unk14[4];
    u8 unk18[4];
    u8 unk1C;
};

struct FieldSysPriv {
    u8 pad00[0x80];
    struct UnkStruct_02059E1C *unk80;
};

BOOL sub_0203769C(void);
PlayerProfile *sub_02034818(u32 netId);
BOOL sub_02037030(int a0, void *a1, int a2);
void *sub_02036FD8(int a0, void *a1, int a2);
void sub_020388E0(void);
void MailMsg_Copy(MailMessage *dst, const MailMessage *src);
void Heap_Free(void *ptr);
void GF_AssertFail(void);
void sub_02035838(MailMessage *a0);
void sub_02035854(struct UnkSub_0205AA4C *a0);
void sub_0203588C(void);
u32 sub_020348A8(int netId);
u32 sub_020348CC(int netId);
void BufferCountryName(struct MessageFormat *msgFmt, u32 idx, u32 country);
void BufferCityName(struct MessageFormat *msgFmt, u32 idx, u32 country, u32 city);

extern const u16 _020FC824[];
extern const u32 _020FC99C[][2];
extern const u32 _020FC7D4[];
extern const u32 _020FC7DC[];
extern const u32 _020FC7E4[];
extern const u32 _020FC7EC[];
extern const u32 _020FC7F4[];
extern const u32 _020FC838[][2];
extern const u32 _020FC850[][2];
extern const u32 _020FC868[][2];
extern const u32 _020FC880[][2];
extern const u32 _020FC934[][2];
extern const u32 _020FC95C[][2];

PlayerProfile *sub_02035798(int objId);
void *sub_020691A8(int a0);
u8 GetUnionRoomAvatarAttrBySprite(int gender, u32 avatar, int a2);
void sub_02068FC8(int a0, int a1, int a2, u8 a3, u32 a4, void *a5);
void sub_020398D4(int a0, int a1);
void sub_02039AD8(int a0);

void sub_0205A44C(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys);
void sub_0205A46C(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys);
BOOL sub_0205A478(struct UnkStruct_02059E1C *p);
int sub_0205A47C(struct UnkStruct_02059E1C *p, int a1);
void sub_0205A498(int a0, int a1, void *a2);
void *sub_0205A4B4(int idx, struct FieldSysPriv *fsys);
void sub_0205A4C4(int a0, int a1, u8 *a2, struct FieldSysPriv *fsys);
BOOL sub_0205A4D8(struct UnkStruct_02059E1C *p);
void sub_0205A508(int a0);
int sub_0205A51C(int a0);
int sub_0205A544(struct UnkStruct_02059E1C *p, int a1);
int sub_0205A6AC(struct MessageFormat *msgFmt);
int sub_0205A730(int a0, int a1, struct MessageFormat *msgFmt);
int sub_0205A750(struct UnkStruct_02059E1C *p, int objId, int a2, struct MessageFormat *msgFmt);
u8 sub_0205A894(void);
void sub_0205A8B4(struct UnkSub_0205AA4C *p);
void sub_0205AA4C(struct UnkSub_0205AA4C *p);
void sub_0205AA6C(struct UnkStruct_02059E1C *p, MailMessage *mailMessage);
MailMessage *sub_0205AA84(struct UnkStruct_02059E1C *p);
void sub_0205AB88(MailMessage *mailMessage);
void sub_0205ABB0(struct UnkStruct_02059E1C *p);
void sub_0205ABBC(struct UnkStruct_02059E1C *p);
void *sub_0205ABD8(struct UnkStruct_02059E1C *p);
void sub_0205AC4C(struct UnkStruct_02059E1C *p);
void *sub_0205AC70(struct UnkStruct_02059E1C *p);

#endif
