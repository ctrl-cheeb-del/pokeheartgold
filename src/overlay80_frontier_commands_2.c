#include "overlay80_frontier_commands_internal.h"

void ov80_0222FC08(void *task, void *d) {
    (void)task;
    if (Bg_GetYpos(PTR(d, 0), 2) >= 0xff) {
        ScheduleSetBgPosText(PTR(d, 0), 2, 3, 0);
    } else {
        ScheduleSetBgPosText(PTR(d, 0), 2, 4, 1);
    }
}

int FrtCmd_104(void *c) {
    u16 *out = FrontierScript_ReadVarPtr(c);
    *out = (u16)U32(Frontier_GetData(SYS(c)), 0x14);
    return 0;
}

int FrtCmd_105(void *c) {
    u16 a = FrontierScript_ReadVar(c), b = FrontierScript_ReadVar(c);
    u16 *out = FrontierScript_ReadVarPtr(c);
    *out = (u16)ov80_02230AF8(Frontier_GetData(SYS(c)), a, b);
    return 1;
}

int FrtCmd_106(void *c) {
    U16(c, 0x78) = FrontierScriptContext_ReadHalfWord(c);
    FrontierScriptContext_Pause(c, ov80_0222FCA0);
    return 1;
}

BOOL ov80_0222FCA0(void *c) {
    void *d;
    ov80_0222BE9C(c, U16(c, 0x78));
    d = Frontier_GetData(SYS(c));
    if (U8(d, 0x702) >= 2) {
        U8(d, 0x702) = 0;
        return TRUE;
    }
    return FALSE;
}

int FrtCmd_107(void *c) {
    u8 *p;
    u8 n;
    void *args = Frontier_GetLaunchArgs(SYS(c));
    p = PTR(c, 0x1c);
    PTR(c, 0x1c) = p + 1;
    n = *(volatile u8 *)p;
    {
        void *d = Frontier_GetData(SYS(c));
        if (!d) {
            return 0;
        }
        ov80_0222F44C(c, (u8 *)d + 0x4c + n * 0x110);
    }
    return 1;
}
