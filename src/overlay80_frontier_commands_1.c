#include "overlay80_frontier_commands_internal.h"

int FrtCmd_092(void *c) {
    u16 a = FrontierScript_ReadVar(c), b = FrontierScript_ReadVar(c), d = FrontierScript_ReadVar(c);
    u32 v = ov80_0222FD08(PTR(Frontier_GetLaunchArgs(SYS(c)), 8), a, (u8)b, (u8)d);
    Frontier_SetData(SYS(c), v);
    return 0;
}

int FrtCmd_093(void *c) {
    u16 v = FrontierScript_ReadVar(c);
    ov80_0222FEEC(Frontier_GetData(SYS(c)), v);
    return 0;
}

int FrtCmd_094(void *c) {
    ov80_02230424(Frontier_GetData(SYS(c)));
    return 0;
}

int FrtCmd_095(void *c) {
    void *launch = Frontier_GetLaunchArgs(SYS(c));
    void *data = Frontier_GetData(SYS(c));
    u8 *arg = Heap_Alloc(0xb, 0x24);
    MI_CpuFill8(arg, 0, 0x24);
    PTR(arg, 0) = PTR(launch, 8);
    U8(arg, 4) = U8(data, 4);
    U8(arg, 5) = U8(data, 5);
    U8(arg, 6) = 0;
    U32(arg, 8) = U32(data, 0x4d4);
    U32(arg, 0xc) = U32(data, 0x4d8);
    PTR(arg, 0x1c) = data;
    Frontier_LaunchApplication(SYS(c), ov80_0223BDB4, arg, 0, ov80_0222F7CC);
    return 1;
}

int FrtCmd_096(void *c) {
    void *d = Frontier_GetData(SYS(c));
    void *setup = PTR(d, 0x4fc);
    U32(d, 0x14) = IsBattleResultWin(U32(setup, 0x14));
    BattleSetup_Delete(setup);
    return 0;
}

int FrtCmd_097(void *c) {
    void *args = Frontier_GetLaunchArgs(SYS(c));
    void *data = Frontier_GetData(SYS(c));
    void *setup = ov80_02236F24(data, args);
    PTR(data, 0x4fc) = setup;
    Frontier_LaunchApplication(SYS(c), gOverlayTemplate_Battle, setup, 0, 0);
    return 1;
}

int FrtCmd_098(void *c) {
    void *launch = Frontier_GetLaunchArgs(SYS(c));
    void *data = Frontier_GetData(SYS(c));
    u8 *arg;
    int i = 0;
    u8 *p = data;
    u16 zero = i;
    do {
        i++;
        U16(p, 0x4dc) = zero;
        p += 2;
    } while (i < 6);
    arg = Heap_Alloc(0xb, 0x24);
    MI_CpuFill8(arg, 0, 0x24);
    PTR(arg, 0) = PTR(launch, 8);
    U8(arg, 4) = U8(data, 4);
    U8(arg, 5) = U8(data, 5);
    U8(arg, 6) = 1;
    U32(arg, 8) = U32(data, 0x4d4);
    U32(arg, 0xc) = U32(data, 0x4d8);
    PTR(arg, 0x1c) = data;
    Frontier_LaunchApplication(SYS(c), ov80_0223BDC4, arg, 0, ov80_0222F7CC);
    return 1;
}

void ov80_0222F7CC(void *p) {
    ov80_02230460(PTR(p, 0x1c), p);
    Heap_Free(p);
}

int FrtCmd_099(void *c) {
    ov80_022307F0(Frontier_GetData(SYS(c)));
    return 0;
}

int FrtCmd_100(void *c) {
    ov80_022308C4(Frontier_GetData(SYS(c)));
    return 0;
}

int FrtCmd_101(void *c) {
    ov80_022309F8(Frontier_GetData(SYS(c)));
    return 0;
}

int FrtCmd_102(void *c) {
    ov80_02230A60(Frontier_GetData(SYS(c)));
    return 0;
}
