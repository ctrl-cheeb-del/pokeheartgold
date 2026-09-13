#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define FSYS(c)   PTR((c), 0)
#define APP(c)    PTR(FSYS(c), 0)

u16 FrontierScript_ReadVar(void *ctx);
u16 FrontierScriptContext_ReadHalfWord(void *ctx);
void *Frontier_GetLaunchArgs(void *app);
void *Save_PlayerData_GetProfile(void *saveData);
u32 sub_0203769C(void);
void *sub_02034818(u32 player);
void BufferItemName(void *fmt, u32 field, u32 item);
void BufferIntegerAsString(void *fmt, u32 field, s32 value, u32 digits, u32 mode, BOOL charset);
void BufferPlayersName(void *fmt, u32 field, void *profile);
void BufferMoveName(void *fmt, u32 field, u32 move);
void BufferString(void *fmt, u32 field, void *string, s32 a3, s32 a4, s32 a5);
void BufferTypeName(void *fmt, u32 field, u32 type);
void *NewMsgDataFromNarc(u32 type, u32 narc, u32 file, u32 heap);
void *NewString_ReadMsgData(void *msgData, s32 msgNo);
void DestroyMsgData(void *msgData);
void String_Delete(void *string);

u32 ov80_0222CF6C(u32 value);
void *ov80_0222D0D4(u32 msgNo, u32 heapId);
int FrtCmd_121(void *ctx);
int FrtCmd_122(void *ctx);
int FrtCmd_123(void *ctx);
int FrtCmd_124(void *ctx);
int FrtCmd_125(void *ctx);
int FrtCmd_126(void *ctx);
int FrtCmd_127(void *ctx);

int FrtCmd_121(void *ctx) {
    u8 *script = PTR(ctx, 0x1c);
    void *fmt;
    u8 field;
    u16 item;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    item = FrontierScript_ReadVar(ctx);
    fmt = PTR(FSYS(ctx), 0x44);
    BufferItemName(fmt, field, item);
    return 0;
}

int FrtCmd_122(void *ctx) {
    u8 *script = PTR(ctx, 0x1c);
    u8 field;
    u16 value;
    u32 digits;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    value = FrontierScript_ReadVar(ctx);
    digits = ov80_0222CF6C(value);
    BufferIntegerAsString(PTR(FSYS(ctx), 0x44), field, value, digits, 1, TRUE);
    return 0;
}

u32 ov80_0222CF6C(u32 value) {
    if (value / 10 == 0) {
        return 1;
    }
    if (value / 100 == 0) {
        return 2;
    }
    if (value / 1000 == 0) {
        return 3;
    }
    if (value / 10000 == 0) {
        return 4;
    }
    if (value / 100000 == 0) {
        return 5;
    }
    if (value / 1000000 == 0) {
        return 6;
    }
    if (value / 10000000 == 0) {
        return 7;
    }
    if (value / 100000000 == 0) {
        return 8;
    }
    return 1;
}

int FrtCmd_123(void *ctx) {
    void *args = Frontier_GetLaunchArgs(APP(ctx));
    u8 *script = PTR(ctx, 0x1c);
    u8 field;
    void *profile;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    profile = Save_PlayerData_GetProfile(PTR(args, 8));
    BufferPlayersName(PTR(FSYS(ctx), 0x44), field, profile);
    return 0;
}

int FrtCmd_124(void *ctx) {
    Frontier_GetLaunchArgs(APP(ctx));
    u8 *script = PTR(ctx, 0x1c);
    PTR(ctx, 0x1c) = script + 1;
    u8 field = *script;
    void *profile = sub_02034818(sub_0203769C() ^ 1);
    BufferPlayersName(PTR(FSYS(ctx), 0x44), field, profile);
    return 0;
}

int FrtCmd_125(void *ctx) {
    u8 *script = PTR(ctx, 0x1c);
    u8 field;
    u16 move;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    move = FrontierScript_ReadVar(ctx);
    BufferMoveName(PTR(FSYS(ctx), 0x44), field, move);
    return 0;
}

int FrtCmd_126(void *ctx) {
    u8 *script = PTR(ctx, 0x1c);
    u8 field;
    u16 msgNo;
    u16 stringNo;
    u8 mode;
    void *string;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    msgNo = FrontierScript_ReadVar(ctx);
    stringNo = FrontierScriptContext_ReadHalfWord(ctx);
    script = PTR(ctx, 0x1c);
    PTR(ctx, 0x1c) = script + 1;
    mode = *script;
    string = ov80_0222D0D4(msgNo, 0xb);
    BufferString(PTR(FSYS(ctx), 0x44), field, string, stringNo, mode, 2);
    String_Delete(string);
    return 0;
}

void *ov80_0222D0D4(u32 msgNo, u32 heapId) {
    void *msgData = NewMsgDataFromNarc(1, 0x1b, 0xed, heapId);
    void *string = NewString_ReadMsgData(msgData, msgNo);
    DestroyMsgData(msgData);
    return string;
}

int FrtCmd_127(void *ctx) {
    u8 *script = PTR(ctx, 0x1c);
    u8 field;
    u16 type;

    PTR(ctx, 0x1c) = script + 1;
    field = *script;
    type = FrontierScript_ReadVar(ctx);
    BufferTypeName(PTR(FSYS(ctx), 0x44), field, type);
    return 0;
}
