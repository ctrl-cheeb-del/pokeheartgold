#ifndef OV27_PRIVATE_H
#define OV27_PRIVATE_H

#include "global.h"

typedef struct SysTask SysTask;
typedef struct Sprite Sprite;
typedef struct MsgData MsgData;
typedef struct MessageFormat MessageFormat;
typedef struct BgConfig BgConfig;
typedef struct PlayerAvatar PlayerAvatar;
typedef struct LocalFieldData LocalFieldData;
typedef struct PlayerSaveData PlayerSaveData;
typedef struct SaveData SaveData;
typedef struct GearPhoneRingManager GearPhoneRingManager;

typedef struct Ov27Window {
    BgConfig *bgConfig;
    u8 bgId;
    u8 tilemapLeft;
    u8 tilemapTop;
    u8 width;
    u8 height;
    u8 paletteNum;
    u16 baseTile : 15;
    u16 colorMode : 1;
    void *pixelBuffer;
} Ov27Window;

typedef struct Ov27Vec {
    s32 x;
    s32 y;
    s32 z;
} Ov27Vec;

typedef struct Ov27Pos {
    u16 x;
    u16 y;
} Ov27Pos;

typedef struct String String;

typedef struct FieldSystem {
    u8 padding00[0xc];
    SaveData *saveData;
} FieldSystem;

typedef struct Ov27Entry {
    u32 unk00;
    u32 unk04;
} Ov27Entry;

typedef union Ov27Bits {
    u32 raw;
    struct {
        u32 bit0 : 1;
        u32 bits1_4 : 4;
        u32 bit5 : 1;
        u32 bits6_7 : 2;
        u32 rest : 24;
    } b;
} Ov27Bits;

typedef struct Ov27Work {
    /* 0x000 */ u32 unk00;
    /* 0x004 */ void *unk04;
    /* 0x008 */ SysTask *unk08;
    /* 0x00C */ void *unk0C;
    /* 0x010 */ FieldSystem *unk10;
    /* 0x014 */ s32 unk14;
    /* 0x018 */ BgConfig *unk18;
    /* 0x01C */ u8 padding1C[0x28 - 0x1c];
    /* 0x028 */ Ov27Window window28;
    /* 0x038 */ Ov27Window window38;
    /* 0x048 */ u32 padding48;
    /* 0x04C */ MsgData *unk4C;
    /* 0x050 */ MessageFormat *unk50;
    /* 0x054 */ Ov27Window windows[8];
    /* 0x0D4 */ u8 paddingD4[0x388 - 0xd4];
    /* 0x388 */ Sprite *unk388;
    /* 0x38C */ u8 padding38C[0x394 - 0x38c];
    /* 0x394 */ u32 unk394;
    /* 0x398 */ u32 unk398;
    /* 0x39C */ void *unk39C;
    /* 0x3A0 */ void *unk3A0;
    /* 0x3A4 */ u8 padding3A4[0x3bc - 0x3a4];
    /* 0x3BC */ Sprite *unk3BC;
    /* 0x3C0 */ u32 unk3C0;
    /* 0x3C4 */ Sprite *unk3C4;
    /* 0x3C8 */ u8 padding3C8[0x3d0 - 0x3c8];
    /* 0x3D0 */ Ov27Window window3D0;
    /* 0x3E0 */ u8 padding3E0[0x510 - 0x3e0];
    /* 0x510 */ s32 unk510;
    /* 0x514 */ u8 padding514[0x51c - 0x514];
    /* 0x51C */ Ov27Bits unk51C;
} Ov27Work;

typedef struct Ov27Sub {
    /* 0x00 */ void *unk00;
    /* 0x04 */ GearPhoneRingManager *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ Ov27Window window;
    /* 0x1C */ u32 unk1C;
} Ov27Sub;

typedef struct Ov27Timer {
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u32 unk0C;
    /* 0x10 */ s32 unk10;
} Ov27Timer;

typedef struct Ov27Flags {
    u8 padding00[0xd2];
    u8 unkD2_0 : 6;
    u8 unkD2_6 : 1;
    u8 unkD2_7 : 1;
} Ov27Flags;

// external
void *Heap_AllocAtEnd(u32 heapId, u32 size);
void *SysTask_GetData(SysTask *task);
void Sprite_SetAnimCtrlSeq(Sprite *sprite, int seq);
void Sprite_SetDrawFlag(Sprite *sprite, int flag);
void DestroyMsgData(MsgData *msgData);
void MessageFormat_Delete(MessageFormat *fmt);
MessageFormat *MessageFormat_New(u32 heapId);
MsgData *NewMsgDataFromNarc(int type, u32 narcId, u32 fileId, u32 heapId);
PlayerAvatar *FieldSystem_GetPlayerAvatar(FieldSystem *fsys);
u16 PlayerAvatar_CheckRunningShoesLock(PlayerAvatar *avatar);
int FieldSystem_GetParkBallCount(FieldSystem *fsys);
GearPhoneRingManager *FieldSystem_GetGearPhoneRingManager(FieldSystem *fsys);
LocalFieldData *Save_LocalFieldData_Get(SaveData *saveData);
PlayerSaveData *LocalFieldData_GetPlayer(LocalFieldData *data);
u16 *LocalFieldData_GetSafariBallsCounter(LocalFieldData *data);
BOOL PlayerSaveData_CheckRunningShoes(PlayerSaveData *data);
void ClearWindowTilemapAndCopyToVram(Ov27Window *window);

void RemoveWindow(Ov27Window *window);
Ov27Entry *ov01_021EEF58(void *p);

extern const u8 ov27_0225D3C6[];

// internal
void ov27_0225A468(Ov27Work *work, s32 a1);
void ov27_0225A4B8(Ov27Work *work);
s32 ov27_0225A594(Ov27Work *work);
void ov27_0225A61C(Ov27Work *work, s32 a1);
void ov27_0225A66C(Ov27Work *work);
void ov27_0225A690(Ov27Work *work, s32 a1);
void ov27_0225A7DC(Ov27Work *work);
u8 ov27_0225AA60(const u8 *data, int size);
u32 ov27_0225AE8C(u32 a0);
void ov27_0225B398(Ov27Work *work, s32 a1);
void ov27_0225B630(Ov27Window *window, u32 a1);
u32 ov27_0225BD44(Ov27Flags *p);
BOOL ov27_0225BDAC(Ov27Work *work);
BOOL ov27_0225BDC8(Ov27Work *work);
void ov27_0225BDDC(Ov27Sub *sub, Ov27Work *work);
void ov27_0225BEB0(Ov27Sub *sub);
void ov27_0225BF84(Ov27Work *work, u32 a1, u32 a2, u16 a3);
void ov27_0225C01C(Ov27Work *work);
void ov27_0225C044(Ov27Work *work);
void ov27_0225C06C(Ov27Work *work);
void *ov27_0225C238(void);
void ov27_0225C248(SysTask *task, void *data);
void ov27_0225C24C(SysTask *task, void *data);
BOOL ov27_0225C418(Ov27Work *work);
void ov27_0225C41C(SysTask *task, void *a1, void *a2);
void ov27_0225C914(Ov27Work *work);
void ov27_0225C930(Ov27Work *work);
u32 ov27_0225C944(Ov27Work *work);
u32 ov27_0225C988(Ov27Work *work);
u32 ov27_0225C9CC(Ov27Work *work);
u32 ov27_0225C9E4(Ov27Timer *p);
void ov27_0225CD94(Ov27Work *work);
u32 ov27_0225CCBC(Ov27Work *work);
void ov27_0225CD74(Ov27Work *work, s32 a1);
BOOL ov27_0225A2C8(Ov27Work *work);
void ov27_0225A2CC(SysTask *task, void *unused);

// batch 2 externs
BOOL Sprite_IsAnimated(Sprite *sprite);
void Sprite_SetOamMode(Sprite *sprite, u32 mode);
void Sprite_SetMatrix(Sprite *sprite, const Ov27Vec *vec);
void BgClearTilemapBufferAndCommit(BgConfig *bgConfig, u32 layer);
void FillWindowPixelBuffer(Ov27Window *window, u8 fillValue);
void AddTextPrinterParameterizedWithColor(Ov27Window *window, u32 fontId, String *str, u32 x, u32 y, u32 speed, u32 colors, void *callback);
void ScheduleWindowCopyToVram(Ov27Window *window);
void CopyWindowToVram(Ov27Window *window);
String *NewString_ReadMsgData(MsgData *msgData, u32 msgId);
void String_Delete(String *str);
void PlayerAvatar_SetRunningShoesLock(PlayerAvatar *avatar, u32 lock);
s32 ov01_021EEF60(void *p);
int sub_0203DF8C(FieldSystem *fsys);

extern const u32 ov27_0225CEC4[];
extern const u32 ov27_0225D480[];
extern const u8 ov27_0225D0B4[][4][3];
extern const u16 ov27_0225D118[];
extern const u16 ov27_0225D11A[];

void ov27_0225A2EC(SysTask *task, s32 a1);
void ov27_0225A48C(Ov27Work *work, s32 a1);
void ov27_0225A7B0(Ov27Work *work);
void ov27_0225A86C(Ov27Work *work);
void ov27_0225AAD4(Ov27Work *work);
s32 ov27_0225B360(s32 a0, s32 a1, const u8 *a2);
void ov27_0225B4AC(Sprite **sprites, s32 a1);
void ov27_0225BB38(Ov27Window *window, String *str, s32 a2);
void ov27_0225BED8(Ov27Work *work, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, s32 a7, u32 a8);
void ov27_0225C088(Ov27Work *work);
void ov27_0225C0E0(Ov27Work *work);
void ov27_0225C540(Ov27Work *work);
void ov27_0225C5E4(Ov27Work *work);
void ov27_0225C6F8(Ov27Work *work);
void ov27_0225C8D0(Ov27Window *window, MsgData *msgData, u32 msgId);
u32 ov27_0225C94C(Ov27Work *work);
u32 ov27_0225C994(Ov27Work *work);
BOOL ov27_0225CA68(Ov27Timer *p, s32 a1, const s8 *a2);
u32 ov27_0225CC90(Ov27Work *work);
void ov27_0225CCE0(Ov27Work *work, s32 a1);

#endif // OV27_PRIVATE_H
