#include "overlay_80_command_helpers_internal.h"
u16 *FrontierScript_ReadVarPtr(void *c);
u16 FrontierScript_ReadVar(void *c);
u16 ov80_0222BE9C(void *c, u16 v);
int FrtCmd_000(void *c);
int FrtCmd_001(void *c);
int FrtCmd_002(void *c);
BOOL ov80_0222BEFC(void *c);
BOOL ov80_0222BF5C(void *c);
int FrtCmd_006(void *c);
int FrtCmd_007(void *c);
int FrtCmd_008(void *c);
int FrtCmd_009(void *c);
int ov80_0222BFE4(u16 a, u16 b);
int FrtCmd_032(void *c);
void ov80_0222C03C(void *c, void *p);
int FrtCmd_010(void *c);
int FrtCmd_012(void *c);
int FrtCmd_013(void *c);
BOOL ov80_0222C17C(void *c);
int FrtCmd_018(void *c);
BOOL ov80_0222C200(void *c);
int FrtCmd_020(void *c);
int FrtCmd_025(void *c);
int FrtCmd_029(void *c);
int FrtCmd_030(void *c);
int FrtCmd_035(void *c);
int FrtCmd_039(void *c);
BOOL ov80_0222C80C(void *c);
int FrtCmd_041(void *c);
int FrtCmd_045(void *c);
int FrtCmd_050(void *c);
int FrtCmd_051(void *c);
int FrtCmd_084(void *c);
void ov80_0222CB94(void *p);
int FrtCmd_108(void *c);
int FrtCmd_111(void *c);
int FrtCmd_114(void *c);
int FrtCmd_116(void *c);
int FrtCmd_119(void *c);
int FrtCmd_120(void *c);
int FrtCmd_121(void *c);
int FrtCmd_125(void *c);
int FrtCmd_127(void *c);
BOOL ov80_0222D200(void *c);
int FrtCmd_054(void *c);
BOOL ov80_0222D244(void *c);
int FrtCmd_055(void *c);
int FrtCmd_057(void *c);
BOOL ov80_0222D2AC(void *c);
int FrtCmd_058(void *c);
int FrtCmd_059(void *c);
int FrtCmd_060(void *c);
u32 ov80_0222D63C(u32 a, u32 b);
int FrtCmd_066(void *c);
int FrtCmd_068(void *c);
BOOL ov80_0222DE00(void *c);
int FrtCmd_077(void *c);
BOOL ov80_0222DE9C(void *c);
int FrtCmd_079(void *c);
BOOL ov80_0222DF3C(void *c);
int FrtCmd_150(void *c);
int FrtCmd_070(void *c);
int FrtCmd_075(void *c);
int FrtCmd_113(void *c);
int FrtCmd_200(void *c);
int FrtCmd_201(void *c);
int FrtCmd_204(void *c);
int FrtCmd_205(void *c);
int FrtCmd_206(void *c);
int FrtCmd_207(void *c);
void ov80_0222E328(void *p, int n, void *out);

u16 ov80_0222BE9C(void *c, u16 v) {
    u16 *p = ov80_0222BE24(c, v);
    if (p) {
        v = *p;
    }
    return v;
}

int FrtCmd_000(void *c) {
    return 0;
}

int FrtCmd_001(void *c) {
    FrontierScriptContext_Stop(c);
    return 0;
}

int FrtCmd_002(void *c) {
    FrontierScriptContext_Stop(c);
    sub_0209684C(APP(c));
    return 0;
}

int FrtCmd_003(void *c) {
    void *s = FSYS(c);
    u16 v = FrontierScript_ReadVar(c);
    sub_02096854(PTR(s, 0), v, 0xffff);
    FrontierScriptContext_Pause(c, ov80_0222BEFC);
    return 1;
}

BOOL ov80_0222BEFC(void *c) {
    return TRUE;
}

int FrtCmd_004(void *c) {
    void *s = FSYS(c);
    u16 a = FrontierScript_ReadVar(c), b = FrontierScript_ReadVar(c);
    sub_02096854(PTR(s, 0), a, b);
    FrontierScriptContext_Stop(c);
    return 0;
}

int FrtCmd_005(void *c) {
    u16 a = FrontierScriptContext_ReadHalfWord(c), b = FrontierScriptContext_ReadHalfWord(c);
    *ov80_0222BE24(c, b) = a;
    U16(c, 0x78) = b;
    FrontierScriptContext_Pause(c, ov80_0222BF5C);
    return 1;
}

BOOL ov80_0222BF5C(void *c) {
    u16 *p = ov80_0222BE24(c, U16(c, 0x78));
    (*p)--;
    return *p == 0;
}

int FrtCmd_006(void *c) {
    u16 *p = FrontierScript_ReadVarPtr(c);
    *p = FrontierScriptContext_ReadHalfWord(c);
    return 0;
}

int FrtCmd_007(void *c) {
    u16 *p = FrontierScript_ReadVarPtr(c);
    *p = *FrontierScript_ReadVarPtr(c);
    return 0;
}

int FrtCmd_008(void *c) {
    u16 *p = FrontierScript_ReadVarPtr(c);
    *p += FrontierScript_ReadVar(c);
    return 0;
}

int FrtCmd_009(void *c) {
    u16 *p = FrontierScript_ReadVarPtr(c);
    *p -= FrontierScript_ReadVar(c);
    return 0;
}

int ov80_0222BFE4(u16 a, u16 b) {
    if (a < b) {
        return 0;
    }
    if (a == b) {
        return 1;
    }
    return 2;
}

int FrtCmd_032(void *c) {
    u16 a = FrontierScript_ReadVar(c);
    U8(c, 0x8c) = ov80_0222BFE4(a, FrontierScriptContext_ReadHalfWord(c));
    return 0;
}

int FrtCmd_033(void *c) {
    u16 *a = FrontierScript_ReadVarPtr(c), *b = FrontierScript_ReadVarPtr(c);
    U8(c, 0x8c) = ov80_0222BFE4(*a, *b);
    return 0;
}

void ov80_0222C03C(void *c, void *p) {
    PTR(c, 0x1c) = p;
}

int FrtCmd_010(void *c) {
    u32 x = FrontierScriptContext_ReadWord(c);
    ov80_0222C03C(c, (u8 *)PTR(c, 0x1c) + x);
    return 0;
}
