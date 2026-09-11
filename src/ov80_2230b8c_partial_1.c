#include "ov80_2230b8c_partial_internal.h"

int FrtCmd_139(void *c) {
    u16 a = FrontierScript_ReadVar(c);
    u16 b = FrontierScript_ReadVar(c);
    u16 d = FrontierScript_ReadVar(c);
    u16 e = FrontierScript_ReadVar(c);
    u32 v = ov80_022310C4(PTR(Frontier_GetLaunchArgs(SYS(c)), 8), a, (u8)b, (u8)d, (u8)e);
    Frontier_SetData(SYS(c), v);
    return 0;
}

int FrtCmd_140(void *c) {
    u16 v = FrontierScript_ReadVar(c);
    ov80_022313C0(Frontier_GetData(SYS(c)), v);
    return 0;
}

int FrtCmd_141(void *c) {
    ov80_022314A0(Frontier_GetData(SYS(c)));
    return 0;
}

int FrtCmd_142(void *c) {
    void *launch = Frontier_GetLaunchArgs(SYS(c));
    void *data = Frontier_GetData(SYS(c));
    u8 *arg = Heap_Alloc(0xb, 0x20);
    void *party;
    void *mon;
    MI_CpuFill8(arg, 0, 0x20);
    PTR(arg, 0) = PTR(launch, 8);
    U8(arg, 4) = U8(data, 4);
    PTR(arg, 0x10) = data;
    PTR(arg, 8) = (u8 *)data + 0x704 + U8(data, 4) * 9;
    PTR(arg, 0xc) = PTR(data, 0x264);
    U16(arg, 0x18) = U16(data, 8);
    U8(arg, 5) = U8(data, 0x6f5);
    PTR(arg, 0x14) = (u8 *)data + 0xd84;
    SaveArray_Party_Init(PTR(arg, 0xc));
    party = SaveArray_Party_Get(PTR(launch, 8));
    mon = Party_GetMonByIndex(party, U8(data, 0x260));
    Party_AddMon(PTR(arg, 0xc), mon);
    if (U8(arg, 4) == 1) {
        mon = Party_GetMonByIndex(party, U8(data, 0x261));
        Party_AddMon(PTR(arg, 0xc), mon);
    } else if ((u8)(U8(arg, 4) + 0xfe) <= 1) {
        Party_AddMon(PTR(arg, 0xc), PTR(data, 0xd8c));
    }
    Frontier_LaunchApplication(SYS(c), ov80_0223BDEC, arg, 0, ov80_02230D5C);
    return 1;
}

int FrtCmd_143(void *c) {
    void *data = Frontier_GetData(SYS(c));
    void *setup = PTR(data, 0x700);
    U32(data, 0x14) = IsBattleResultWin(U32(setup, 0x14));
    BattleSetup_Delete(setup);
    return 0;
}

int FrtCmd_144(void *c) {
    void *args = Frontier_GetLaunchArgs(SYS(c));
    void *data = Frontier_GetData(SYS(c));
    void *setup = ov80_022375D0(data, args);
    PTR(data, 0x700) = setup;
    Sound_SetSceneAndPlayBGM(5, 0x45d, 1);
    Frontier_LaunchApplication(SYS(c), gOverlayTemplate_Battle, setup, 0, 0);
    return 1;
}

void ov80_02230D5C(void *p) {
    ov80_022314DC(PTR(p, 0x10), p);
    Heap_Free(p);
}

int FrtCmd_145(void *c) {
    struct ScratchContext {
        u8 pad[0x1c];
        const u8 *scriptPtr;
    } *ctx = c;
    u8 cmd;
    u8 arg;
    u16 *out;
    void *launch;
    void *data;

    cmd = *(ctx->scriptPtr++);
    arg = *(ctx->scriptPtr++);
    ctx->scriptPtr++;
    out = FrontierScript_ReadVarPtr(c);
    launch = Frontier_GetLaunchArgs(SYS(c));
    data = Frontier_GetData(SYS(c));

    switch (cmd) {
    case 2:
        U8(data, 4) = arg;
        break;
    case 3:
        *out = U16(data, 0x6f2);
        break;
    case 4:
        *out = U16(data, 8);
        break;
    case 5:
        if (U16(data, 8) < 9999) {
            U16(data, 8)
            ++;
        }
        break;
    case 7:
        OS_ResetSystem(0);
        break;
    case 9:
        *out = sub_02030B14(PTR(data, 0x6f8));
        break;
    case 10:
        ov80_0223157C(data, 2);
        break;
    case 14:
        *out = ov80_022317C0(data);
        break;
    case 19:
        if (U8(data, 4) == 2) {
            *out = 10;
        } else {
            *out = U16(data, 0xa);
        }
        break;
    case 20:
        *out = ov80_022317D0(data, arg);
        break;
    case 21:
        ov80_02231804(data);
        break;
    case 22:
        ov80_02231828(data);
        break;
    case 23:
        *out = ov80_022317CC(data);
        break;
    case 24:
        *out = U8(data, 0xd88);
        break;
    case 27: {
        struct Data27 {
            u8 pad[0x260];
            u8 partySlots[1];
        } *typed = data;
        void *party = SaveArray_Party_Get(PTR(launch, 8));
        int count = ov80_0223787C(U8(data, 4));
        int i = 0;
        if (count > 0) {
            u8 *dst = (u8 *)data + 0x728;
            do {
                void *mon = Party_GetMonByIndex(party, typed->partySlots[i]);
                SetMonData(mon, 6, dst);
                i++;
                dst += 2;
            } while (i < count);
        }
        break;
    }
    case 28: {
        u32 n = sub_02030BD0(U8(data, 0x6f5), (u8 *)data + 0x704 + U8(data, 4) * 9);
        if (n < 10) {
            sub_02030BF4(U8(data, 0x6f5), (u8 *)data + 0x704 + U8(data, 4) * 9, (u8)(n + 1));
        }
        break;
    }
    case 29:
        sub_02096910();
        break;
    case 30:
        *out = ov80_0223792C(U8(data, 4));
        break;
    case 17:
        *out = U8(data, 4);
        break;
    case 31:
        if (arg == 0) {
            GfGfx_EngineATogglePlanes(4, 1);
        } else {
            GfGfx_EngineATogglePlanes(4, 0);
        }
        break;
    case 32: {
        u8 *q = (u8 *)data + U8(data, 5) * 4;
        ov80_0222A474((u8 *)data + 0x40, U16(q, 0x18), 0xb, 0xcc);
        q = (u8 *)data + (U8(data, 5) * 2 + 1) * 2;
        ov80_0222A474((u8 *)data + 0x150, U16(q, 0x18), 0xb, 0xcc);
        break;
    }
    case 33:
        *out = sub_02030BD0(U8(data, 0x6f5), (u8 *)data + 0x704 + U8(data, 4) * 9);
        break;
    case 34:
        *out = ov80_02231888(data);
        break;
    case 15: {
        void *party = SaveArray_Party_Get(PTR(launch, 8));
        void *mon = Party_GetMonByIndex(party, U8(data, 0x260));
        *out = GetMonData(mon, 5, 0);
        break;
    }
    case 35:
        ov80_022319B0(data);
        break;
    case 36:
        ov80_02231A04(data);
        break;
    case 37:
        *out = 0;
        if (U8(data, 4) == 0) {
            if (U16(data, 8) + 1 == 50) {
                *out = 1;
            } else if (U16(data, 8) + 1 == 170) {
                *out = 2;
            }
        }
        break;
    case 38:
        break;
    }
    return 0;
}

int FrtCmd_146(void *c) {
    u16 *out = FrontierScript_ReadVarPtr(c);
    *out = (u16)U32(Frontier_GetData(SYS(c)), 0x14);
    return 0;
}

int FrtCmd_147(void *c) {
    u16 a = FrontierScript_ReadVar(c);
    u16 b = FrontierScript_ReadVar(c);
    u16 *out = FrontierScript_ReadVarPtr(c);
    *out = (u16)ov80_02231844(Frontier_GetData(SYS(c)), a, b);
    return 1;
}

int FrtCmd_148(void *c) {
    U16(c, 0x78) = FrontierScriptContext_ReadHalfWord(c);
    FrontierScriptContext_Pause(c, ov80_02231040);
    return 1;
}

BOOL ov80_02231040(void *c) {
    void *data;
    ov80_0222BE9C(c, U16(c, 0x78));
    data = Frontier_GetData(SYS(c));
    if (U8(data, 0xd90) >= 2) {
        U8(data, 0xd90) = 0;
        return TRUE;
    }
    return FALSE;
}

int FrtCmd_149(void *c) {
    u8 *p;
    u8 n;
    void *args = Frontier_GetLaunchArgs(SYS(c));
    p = PTR(c, 0x1c);
    PTR(c, 0x1c) = p + 1;
    n = *(volatile u8 *)p;
    {
        void *data = Frontier_GetData(SYS(c));
        if (!data) {
            return 0;
        }
        ov80_0222F44C(c, (u8 *)data + 0x58 + n * 0x110);
    }
    return 1;
}

int FrtCmd_118(void *c) {
    u16 *out = FrontierScript_ReadVarPtr(c);
    ov80_0223151C(Frontier_GetData(SYS(c)), out);
    return 1;
}

int FrtCmd_199(void *c) {
    return 0;
}
