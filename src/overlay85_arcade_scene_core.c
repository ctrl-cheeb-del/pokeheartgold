#include "overlay85_arcade_scene_core_private.h"

// ---- callees implemented elsewhere in the overlay ----
void ov85_021E7644(void *p);
void ov85_021E78A4(ArcWork *work, u32 a1);

// ---- implemented here ----
void ov85_021E8418(ArcWork *work);
void ov85_021E8530(s32 *p, s32 delta);
void ov85_021E8558(ArcWork *work, u32 a1);
BOOL ov85_021E8570(ArcCounter *p);
void ov85_021E85C4(ArcWork *work, u32 data);
void ov85_021E85CC(ArcWork *work, const u16 *data);
void *ov85_021E85F0(ArcWork *work, u32 a1);
void *ov85_021E8610(ArcWork *work);
u32 ov85_021E8614(ArcWork *work, u32 a1);
BOOL ov85_021E8628(ArcWork *work);
int ov85_021E8660(ArcWork *work);
void ov85_021E86AC(ArcWork *work, u32 data);
BOOL ov85_021E86B0(ArcWork *work, u32 a1);
int ov85_021E8720(ArcWork *work);
void ov85_021E8740(ArcWork *work, int sender, u32 data);
void ov85_021E8748(ArcWork *work, const u16 *src);
u32 ov85_021E8878(ArcWork *work);
u32 ov85_021E8898(ArcWork *work);
BOOL ov85_021E87F0(void *party);
void ov85_021E8E38(BgConfig *bgConfig);

void ov85_021E8418(ArcWork *work);

void ov85_021E8530(s32 *p, s32 delta);

void ov85_021E8558(ArcWork *work, u32 a1);

BOOL ov85_021E8570(ArcCounter *p);

void ov85_021E85C4(ArcWork *work, u32 data);

void ov85_021E85CC(ArcWork *work, const u16 *data);

void *ov85_021E85F0(ArcWork *work, u32 a1);

void *ov85_021E8610(ArcWork *work);

u32 ov85_021E8614(ArcWork *work, u32 a1);

BOOL ov85_021E8628(ArcWork *work);

int ov85_021E8660(ArcWork *work);

void ov85_021E86AC(ArcWork *work, u32 data);

BOOL ov85_021E86B0(ArcWork *work, u32 a1);

int ov85_021E8720(ArcWork *work);

void ov85_021E8740(ArcWork *work, int sender, u32 data);

void ov85_021E8748(ArcWork *work, const u16 *src);

u32 ov85_021E8878(ArcWork *work);

u32 ov85_021E8898(ArcWork *work);

BOOL ov85_021E87F0(void *party);

void ov85_021E8E38(BgConfig *bgConfig);

// ---- batch B: scene dispatchers ----
void ov85_021E9324(ArcScene *work);
void ov85_021EA0EC(ArcScene *work, int a1, int a2);

void ov85_021E943C(ArcScene *work);
int ov85_021E9440(ArcScene *work, int state);
void ov85_021E9458(ArcScene *work, u32 a1);
int ov85_021E9468(ArcScene *work, int state);
int ov85_021E9614(ArcScene *work, int state);
int ov85_021E96B0(ArcScene *work, int state);
int ov85_021E97E8(ArcScene *work, int state);
int ov85_021E9814(ArcScene *work, int state);
int ov85_021E98C4(ArcScene *work, int state);
int ov85_021E98E0(ArcScene *work, int state);
int ov85_021E9A6C(ArcScene *work, int state);
int ov85_021E9A90(ArcScene *work, int state);
int ov85_021E9AF0(ArcScene *work, int state);
int ov85_021E9B1C(ArcScene *work, int state);
int ov85_021E92F8(ArcScene *work, int state);
int ov85_021E9EA4(void);
void ov85_021E9FCC(ArcScene *work);
int ov85_021E9FD0(void);
u32 ov85_021E9FEC(void);
BOOL ov85_021EA17C(u32 printerId);
void ov85_021EA19C(ArcScene *work);
int ov85_021EA398(ArcScene *work);
void ov85_021EA4EC(void *a0, void *a1);
void ov85_021E8C14(BgConfig *bgConfig);

void ov85_021E943C(ArcScene *work);

void ov85_021E9458(ArcScene *work, u32 a1);

int ov85_021E9440(ArcScene *work, int state);

int ov85_021E9468(ArcScene *work, int state);

int ov85_021E92F8(ArcScene *work, int state);

void ov85_021E8C14(BgConfig *bgConfig);

// ---- batch C: remaining state dispatchers ----
int ov85_021E948C(ArcScene *work, int state);
int ov85_021E94BC(ArcScene *work, int state);
int ov85_021E96D0(ArcScene *work, int state);
int ov85_021E97B8(ArcScene *work, int state);
int ov85_021E9834(ArcScene *work, int state);
int ov85_021E9900(ArcScene *work, int state);
int ov85_021E993C(ArcScene *work, int state);
int ov85_021E9AB0(ArcScene *work, int state);
int ov85_021E9C50(ArcScene *work, int state);

int ov85_021E948C(ArcScene *work, int state);

int ov85_021E94BC(ArcScene *work, int state);

// ---- batch D ----
void ov85_021E9288(ArcScene *work);
void ov85_021EA368(ArcScene *work);
void ov85_021E8E00(ArcScene *work);
void ov85_021E8F58(void);
void ov85_021E83E0(ArcWork *work);
void ov85_021E8428(ArcWork *work, ArcMsg *msg);

void ov85_021E9288(ArcScene *work);

void ov85_021E8E00(ArcScene *work);

void ov85_021E8F58(void);

void ov85_021E83E0(ArcWork *work);

void ov85_021E8428(ArcWork *work, ArcMsg *msg);

// ---- batch E ----
void *ov85_021E8588(ArcScene *work, u32 member, int atStart);
int ov85_021E9BA0(ArcScene *work, int state);
int ov85_021E92B8(ArcScene *work, int state);
BOOL ov85_021E8834(ArcWork *work);
void ov85_021E9244(Window *window, String *str, u32 speed);

void *ov85_021E8588(ArcScene *work, u32 member, int atStart);

int ov85_021E92B8(ArcScene *work, int state);

BOOL ov85_021E8834(ArcWork *work);

void ov85_021E9244(Window *window, String *str, u32 speed);

// ================= batch A =================
void ov85_021E84A4(SysTask *task, void *data);
void ov85_021E84EC(ArcWork *work, u32 a1);
void ov85_021E8680(ArcWork *work, ArcPair *p);
void ov85_021E8C3C(void);
int ov85_021E9A1C(ArcScene *scene, int a1);
void ov85_021E9E58(u16 *p);
void ov85_021EA324(ArcGfxHolder *a0, ArcGfxHolder *a1, int a2, int a3, int a4);
void ov85_021E9458(ArcScene *scene, u32 a1);
void ov85_021E943C(ArcScene *scene);

void ov85_021E84A4(SysTask *task, void *data);

void ov85_021E84EC(ArcWork *work, u32 a1);

void ov85_021E8680(ArcWork *work, ArcPair *p);

void ov85_021E8C3C(void);

// ================= batch B =================
void ov85_021E86CC(ArcWork *work, int a1);
int ov85_021E9864(ArcScene *scene, int a1);
int ov85_021E9B40(ArcScene *scene, int a1);
void ov85_021EA39C(ArcScene *scene, int a1);

void ov85_021E86CC(ArcWork *work, int a1);

// ================= batch C =================
int ov85_021E962C(ArcScene *scene, int a1);
int ov85_021E9BDC(ArcScene *scene, int a1);
void ov85_021EA2C0(ArcScene *scene, NARC *narc);

// ================= batch D =================
int ov85_021E9700(ArcScene *scene, int a1);
int ov85_021E996C(ArcScene *scene, int a1);

// ================= batch E =================
void ov85_021E8D64(ArcScene *scene, NARC *narc);
void ov85_021E9D9C(ArcScene *scene, int a1, int a2);

void ov85_021E8D64(ArcScene *scene, NARC *narc);

// ================= batch F =================
BOOL ov85_021E8B08(void *man, int *state);

BOOL ov85_021E8B08(void *man, int *state);

// ================= batch G =================
void ov85_021E8BB0(void *a0, ArcScene *scene);

void ov85_021E8BB0(void *a0, ArcScene *scene);

// ================= round-5 tail batch =================
extern u32 sub_02033250(void);

int ov85_021EA3F0(ArcScene *scene, int a1);
void ov85_021EA1AC(ArcScene *scene);
BOOL ov85_021EA010(ArcScene *scene);

// ================= round-6 tail batch =================
BOOL ov85_021E9EC0(Window *window, u32 a1, u32 color, ArcScene *scene);

void ov85_021E9C84(ArcScene *scene, int msg, int a2);

int ov85_021E9614(ArcScene *work, int state) {
    work->unk_4A5C = 0;
    ov85_021E943C(work);
    return state;
}

int ov85_021E962C(ArcScene *scene, int a1) {
    if (((ArcSub10 *)scene->unk_010)->unk_38 != sub_02037454() || ((ArcSub10 *)scene->unk_010)->unk_38 != ov85_021E9FD0()) {
        scene->unk_4A5C = 0;
        scene->unk_354 = 8;
        ov85_021E943C(scene);
        return a1;
    }
    scene->unk_4A5C++;
    if (scene->unk_4A5C > 30) {
        u8 buf[4];
        MI_CpuFill8(buf, 0, 4);
        buf[2] = 1;
        buf[0] = (u8)sub_0203769C();
        sub_02096D4C(scene->unk_010, 2, buf, 4);
        scene->unk_4A5C = 0;
        scene->unk_354 = 9;
    }
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E96B0(ArcScene *work, int state) {
    work->unk_4A50 = 0;
    ov85_021E9458(work, 0);
    ov85_021E943C(work);
    return state;
}

int ov85_021E96D0(ArcScene *work, int state) {
    work->unk_330 = Std_CreateYesNoMenu((BgConfig *)work->unk_014, (const WindowTemplate *)ov85_021EA8D8, 0x1F, 0xB, (enum HeapID)0x66);
    work->unk_354 = 0x17;
    ov85_021E943C(work);
    return state;
}

int ov85_021E9700(ArcScene *scene, int a1) {
    ArcSub10 *p = scene->unk_010;
    if (p->unk_2C != ov85_021E9FD0() || p->unk_30 != 0) {
        if (0xC3 & gSystem.newKeys) {
            PlaySE(0x5F2);
        }
        ov85_021E943C(scene);
        return a1;
    }
    {
        int r = Handle2dMenuInput_DeleteOnFinish(scene->unk_330, (enum HeapID)0x66);
        if (r != -1) {
            if (r == -2) {
                u32 v = 0;
                sub_02096D4C(scene->unk_010, 7, &v, 1);
                ov85_021EA39C(scene, 1);
                ov85_021E9458(scene, 0);
            } else if (sub_0203769C() == 0) {
                scene->unk_354 = 0x18;
                scene->unk_4A52 = (u8)ov85_021E9FD0();
                sub_0205A904(0xC);
            } else {
                GF_AssertFail();
            }
            scene->unk_330 = NULL;
        }
    }
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E97B8(ArcScene *work, int state) {
    if (work->unk_4A53 == 0) {
        if (sub_02096D4C(work->unk_010, 5, NULL, 0) == 1) {
            work->unk_354 = 0x1F;
        }
    }
    return state;
}

int ov85_021E97E8(ArcScene *work, int state) {
    if (!sub_0203769C()) {
        sub_02037454();
    }
    if (((ArcSub10 *)work->unk_010)->unk_20 == sub_02037454()) {
        work->unk_354 = 0x1F;
    }
    return state;
}

int ov85_021E9814(ArcScene *work, int state) {
    ov85_021EA4EC(((ArcSubC *)work->unk_00C)->unk_1C, work->unk_F80);
    work->unk_354 = 0x1B;
    return state;
}

int ov85_021E9834(ArcScene *work, int state) {
    gSystem.softResetDisabled = 1;
    GameStats_AddScore((GameStats *)((ArcSaveHolder *)work->unk_00C)->unk_28, SCORE_EVENT_RECORDS_MIXED);
    sub_02039EAC(work->unk_3B0);
    work->unk_354 = 0x1C;
    return state;
}

int ov85_021E9864(ArcScene *scene, int a1) {
    if (sub_0203769C() == 0) {
        sub_02037454();
    }
    if (sub_02039EB4(((ArcSubC *)scene->unk_00C)->unk_1C, 2, scene->unk_3B0) != 0) {
        StopSE(0x657, 8);
        ov85_021EA0EC(scene, 0xD, 0);
        ov85_021E9458(scene, 0x1D);
        scene->unk_01C = 0;
        scene->unk_360 = 0;
        gSystem.softResetDisabled = 0;
        ((ArcSub10 *)scene->unk_010)->unk_24 = 0;
    }
    return a1;
}

int ov85_021E98C4(ArcScene *work, int state) {
    if (work->unk_360++ > 0x3C) {
        work->unk_354 = 0xF;
    }
    return state;
}

int ov85_021E98E0(ArcScene *work, int state) {
    ov85_021EA0EC(work, 5, 0);
    ov85_021E9458(work, 0xA);
    ov85_021E943C(work);
    return state;
}

int ov85_021E9900(ArcScene *work, int state) {
    work->unk_360++;
    if (work->unk_360 > 0x3C) {
        BeginNormalPaletteFade(0, 0x10, 0x10, 0, 0x10, 1, 0x66);
        state = 3;
    }
    ov85_021E943C(work);
    return state;
}

int ov85_021E993C(ArcScene *work, int state) {
    work->unk_330 = Std_CreateYesNoMenu((BgConfig *)work->unk_014, (const WindowTemplate *)ov85_021EA8D8, 0x1F, 0xB, (enum HeapID)0x66);
    work->unk_354 = 0xC;
    ov85_021E943C(work);
    return state;
}

int ov85_021E996C(ArcScene *scene, int a1) {
    ArcSub10 *p = scene->unk_010;
    if (p->unk_2C != ov85_021E9FD0() || p->unk_30 != 0) {
        if (0xC3 & gSystem.newKeys) {
            PlaySE(0x5F2);
        }
        ov85_021E943C(scene);
        return a1;
    }
    {
        int r = Handle2dMenuInput_DeleteOnFinish(scene->unk_330, (enum HeapID)0x66);
        if (r != -1) {
            if (r == -2) {
                u32 v = 0;
                scene->unk_354 = 0;
                sub_02096D4C(scene->unk_010, 7, &v, 1);
                ov85_021EA39C(scene, 1);
            } else {
                scene->unk_354 = 0xD;
                sub_02096D4C(scene->unk_010, 3, NULL, 0);
                BufferPlayersName(scene->unk_034, 0, (PlayerProfile *)sub_02034818(0));
            }
            scene->unk_330 = NULL;
        }
    }
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E9A1C(ArcScene *scene, int a1) {
    if (sub_0203769C() == 0) {
        ov85_021EA0EC(scene, 5, 0);
    } else {
        BufferPlayersName(scene->unk_034, 0, (PlayerProfile *)sub_02034818(0));
        ov85_021EA0EC(scene, 0x10, 0);
    }
    ov85_021E9458(scene, 14);
    scene->unk_360 = 0;
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E9A6C(ArcScene *work, int state) {
    work->unk_360++;
    if (work->unk_360 > 0x2D) {
        work->unk_354 = 0xF;
    }
    ov85_021E943C(work);
    return state;
}

int ov85_021E9A90(ArcScene *work, int state) {
    sub_02037AC0(0xCA);
    work->unk_354 = 0x10;
    ov85_021E943C(work);
    return state;
}

int ov85_021E9AB0(ArcScene *work, int state) {
    if (sub_02037B38(0xCA)) {
        sub_020398D4(0, 0);
        BeginNormalPaletteFade(0, 0x10, 0x10, 0, 0x10, 1, 0x66);
        state = 3;
    }
    ov85_021E943C(work);
    return state;
}

int ov85_021E9AF0(ArcScene *work, int state) {
    if (ov85_021EA17C(work->unk_05C)) {
        ov85_021EA0EC(work, 9, 0);
    }
    work->unk_354 = 0x12;
    ov85_021E943C(work);
    return state;
}

int ov85_021E9B1C(ArcScene *work, int state) {
    if (ov85_021EA17C(work->unk_05C)) {
        work->unk_354 = 0xA;
    }
    ov85_021E943C(work);
    return state;
}

int ov85_021E9B40(ArcScene *scene, int a1) {
    if (scene->unk_05C != 0xFF && ov85_021EA17C(scene->unk_05C) == 0) {
        RemoveTextPrinter((u8)scene->unk_05C);
    }
    ov85_021EA0EC(scene, 0xF, 1);
    scene->unk_354 = 0x14;
    if (sub_0203769C() == 0) {
        ov85_021EA39C(scene, 0);
    }
    scene->unk_4A58 = sub_02037454();
    scene->unk_4A54 = 0x12C;
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E9BA0(ArcScene *work, int state) {
    if (work->unk_4A58 != 0) {
        if (work->unk_4A58 != sub_02037454()) {
            work->unk_4A58 = 0;
        }
    }
    work->unk_354 = 0x15;
    work->unk_360 = 0;
    ov85_021E943C(work);
    return state;
}

int ov85_021E9BDC(ArcScene *scene, int a1) {
    if (scene->unk_4A58 != 0) {
        if (scene->unk_4A58 != sub_02037454()) {
            scene->unk_4A58 = 0;
        }
    }
    scene->unk_4A54--;
    if (scene->unk_4A54 < 0) {
        scene->unk_4A58 = 0;
    }
    scene->unk_360++;
    if (scene->unk_360 > 0x3C && scene->unk_4A58 == 0) {
        scene->unk_354 = 0;
        if (sub_0203769C() == 0) {
            ov85_021EA39C(scene, 1);
        }
    }
    ov85_021E943C(scene);
    return a1;
}

int ov85_021E9C50(ArcScene *work, int state) {
#pragma unused(state)
    sub_0205A904(0xC);
    BeginNormalPaletteFade(0, 0x10, 0x10, 0, 0x10, 1, 0x66);
    work->unk_008 = 1;
    ov85_021E943C(work);
    return 3;
}

void ov85_021E9C84(ArcScene *scene, int msg, int a2) {
    switch (msg) {
    case 2:
        ov85_021EA19C(scene);
        break;
    case 7:
    case 8:
        break;
    case 0xD:
        if (scene->unk_330 != NULL) {
            Clear2dMenuWindowAndDelete(scene->unk_330, (enum HeapID)0x66);
            scene->unk_330 = NULL;
        }
        break;
    case 0x19:
        if (!ov85_021EA17C(scene->unk_05C)) {
            RemoveTextPrinter((u8)scene->unk_05C);
        }
        ov85_021EA0EC(scene, 0xC, 0);
        if (scene->unk_330 != NULL) {
            Clear2dMenuWindowAndDelete(scene->unk_330, (enum HeapID)0x66);
            scene->unk_330 = NULL;
        }
        break;
    case 0x13:
        if (scene->unk_4A50 == 1) {
            return;
        }
        BufferPlayersName(scene->unk_034, 0, (PlayerProfile *)sub_02034818(a2));
        if (a2 == sub_0203769C()) {
            return;
        }
        if (scene->unk_330 != NULL) {
            Clear2dMenuWindowAndDelete(scene->unk_330, (enum HeapID)0x66);
            scene->unk_330 = NULL;
        }
        if (sub_0203769C() == 0) {
            ((ArcSub10 *)scene->unk_010)->unk_30 &= 0xFFFF ^ a2;
        }
        break;
    case 0x1F:
        if (!ov85_021EA17C(scene->unk_05C)) {
            RemoveTextPrinter((u8)scene->unk_05C);
        }
        if (scene->unk_330 != NULL) {
            Clear2dMenuWindowAndDelete(scene->unk_330, (enum HeapID)0x66);
            scene->unk_330 = NULL;
        }
        break;
    default:
        return;
    }
    scene->unk_354 = msg;
}

void ov85_021E9D9C(ArcScene *scene, int a1, int a2) {
    if (scene->unk_354 == 3) {
        switch (a1) {
        case 1: {
            ArcSub10 *p;
            BufferPlayersName(scene->unk_034, 0, (PlayerProfile *)sub_02034818(a2));
            ov85_021EA39C(scene, 1);
            scene->unk_354 = a1;
            ((ArcSub10 *)scene->unk_010)->unk_2C = sub_02037454();
            p = scene->unk_010;
            p->unk_30 = 0;
            if (sub_0203769C() == 0) {
                u32 v = 1;
                sub_02096D4C(scene->unk_010, 7, &v, 1);
            }
            break;
        }
        case 0x13:
            BufferPlayersName(scene->unk_034, 0, (PlayerProfile *)sub_02034818(a2));
            if (a2 != sub_0203769C()) {
                if (sub_0203769C() == 0) {
                    ArcSub10 *p = scene->unk_010;
                    p->unk_30 = (0xFFFF ^ a2) & p->unk_30;
                }
                scene->unk_354 = a1;
            }
            break;
        default:
            GF_AssertFail();
            break;
        }
    } else if (a1 == 1) {
        ((ArcSub10 *)scene->unk_010)->unk_30 = 0;
        ((ArcSub10 *)scene->unk_010)->unk_2C = sub_02037454();
    }
}

void ov85_021E9E58(u16 *p) {
    u16 color;
    *p += 10;
    if (*p > 360) {
        *p = 0;
    }
    color = (u16)((((GF_SinDeg(*p) * 10) / 0x1000) + 15) << 5 | 29);
    GX_LoadOBJPltt(&color, 10, 2);
    GX_LoadOBJPltt(&color, 42, 2);
}

int ov85_021E9EA4(void) {
    int i;
    int count;
    count = 0;
    i = 0;
    for (; i < 5; i++) {
        if (sub_02034818(i)) {
            count++;
        }
    }
    return count;
}

BOOL ov85_021E9EC0(Window *window, u32 a1, u32 color, ArcScene *scene) {
    int i;
    int sel;
    String *str;
    u32 tid;

    sel = sub_0203769C();
    if (!ov85_021EA010(scene)) {
        return FALSE;
    }
    FillWindowPixelBuffer(window, 0);
    for (i = 0; i < 5; i++) {
        if (scene->unk_374[i].unk_00 != 0) {
            tid = PlayerProfile_GetTrainerID_VisibleHalf((PlayerProfile *)scene->unk_374[i].unk_00);
            PlayerName_FlatToString((PlayerProfile *)scene->unk_374[i].unk_00, scene->unk_03C[i]);
            BufferIntegerAsString(scene->unk_034, 0, (s32)tid, 5, (PrintingMode)2, TRUE);
            str = ReadMsgData_ExpandPlaceholders(scene->unk_034, scene->unk_038, 1, (enum HeapID)0x66);
            if (sel == i) {
                AddTextPrinterParameterizedWithColor(window, 0, scene->unk_03C[i], 5, i * 0x12 + 1, 0xFF, 0x20300, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, str, 0x46, i * 0x12 + 1, 0xFF, 0x20300, NULL);
            } else {
                AddTextPrinterParameterizedWithColor(window, 0, scene->unk_03C[i], 5, i * 0x12 + 1, 0xFF, color, NULL);
                AddTextPrinterParameterizedWithColor(window, 0, str, 0x46, i * 0x12 + 1, 0xFF, color, NULL);
            }
            String_Delete(str);
        }
    }
    CopyWindowToVram(window);
    return TRUE;
}

void ov85_021E9FCC(ArcScene *work) {
#pragma unused(work)
}

int ov85_021E9FD0(void) {
    int i;
    int count;
    count = 0;
    i = 0;
    for (; i < 5; i++) {
        if (sub_02034818(i)) {
            count++;
        }
    }
    return count;
}

u32 ov85_021E9FEC(void) {
    int i;
    u32 mask;
    mask = 0;
    i = 0;
    for (; i < 5; i++) {
        if (sub_02034818(i)) {
            mask |= 1 << i;
        }
    }
    return mask;
}

BOOL ov85_021EA010(ArcScene *scene) {
    int i;
    BOOL changed = FALSE;
    for (i = 0; i < 5; i++) {
        scene->unk_374[i].unk_04 = scene->unk_374[i].unk_00;
        scene->unk_374[i].unk_00 = (u32)sub_02034818(i);
        scene->unk_4A60[i].prev = scene->unk_4A60[i].cur;
        if (scene->unk_374[i].unk_00 != 0) {
            scene->unk_4A60[i].cur.f.id = PlayerProfile_GetTrainerID((PlayerProfile *)scene->unk_374[i].unk_00);
            scene->unk_4A60[i].cur.f.valid = 1;
        } else {
            scene->unk_4A60[i].cur.f.id = 0;
            scene->unk_4A60[i].cur.f.valid = 0;
        }
    }
    for (i = 0; i < 5; i++) {
        if (scene->unk_374[i].unk_04 != scene->unk_374[i].unk_00) {
            changed = TRUE;
            if (scene->unk_374[i].unk_00 == 0) {
                scene->unk_39C[i] = 3;
            } else {
                scene->unk_39C[i] = 1;
            }
        } else if (scene->unk_4A60[i].cur.raw != scene->unk_4A60[i].prev.raw) {
            changed = TRUE;
            if (scene->unk_4A60[i].cur.f.valid == 0) {
                scene->unk_39C[i] = 3;
            } else {
                scene->unk_39C[i] = 1;
            }
        }
    }
    return changed;
}

void ov85_021EA0EC(ArcScene *scene, int a1, int a2) {
    String *str = String_New(0xB4, (enum HeapID)0x66);
    ReadMsgDataIntoString(scene->unk_038, a1, str);
    StringExpandPlaceholders(scene->unk_034, scene->unk_054, str);
    String_Delete(str);
    FillWindowPixelBuffer(&scene->unk_2F8, 0xF);
    DrawFrameAndWindow2(&scene->unk_2F8, 0, 1, 0xA);
    if (a2 == 0) {
        scene->unk_05C = AddTextPrinterParameterized(&scene->unk_2F8, 1, scene->unk_054, 0, 0, ov85_021EA398(scene), NULL);
    } else {
        AddTextPrinterParameterized(&scene->unk_2F8, 1, scene->unk_054, 0, 0, 0, NULL);
        scene->unk_05C = 0xFF;
    }
}

BOOL ov85_021EA17C(u32 printerId) {
    if (printerId == 0xFF) {
        return TRUE;
    }
    if (!TextPrinterCheckActive((u8)printerId)) {
        return TRUE;
    }
    return FALSE;
}

void ov85_021EA19C(ArcScene *work) {
    ClearFrameAndWindow2(&work->unk_2F8, 0);
}

void ov85_021EA1AC(ArcScene *scene) {
    int i;
    int played = 0;
    for (i = 0; i < 5; i++) {
        switch (scene->unk_39C[i]) {
        case 0:
            break;
        case 1: {
            int gender;
            int avatar;
            if (scene->unk_374[i].unk_00 == 0) {
                GF_AssertFail();
            }
            gender = PlayerProfile_GetTrainerGender((PlayerProfile *)scene->unk_374[i].unk_00);
            avatar = PlayerProfile_GetAvatar((PlayerProfile *)scene->unk_374[i].unk_00);
            if (i == sub_0203769C()) {
                Sprite_SetAnimCtrlSeq(scene->unk_23C[i], gender * 2 + 0x26);
            } else {
                ov85_021EA324((ArcGfxHolder *)&scene->unk_33C, (ArcGfxHolder *)&scene->unk_34C, i, avatar, gender);
                Sprite_SetAnimCtrlSeq(scene->unk_23C[i], i * 2 + 0x1B);
            }
            Sprite_SetDrawFlag(scene->unk_23C[i], 1);
            scene->unk_39C[i] = 2;
            played = 1;
            break;
        }
        case 2:
            break;
        case 3:
            if (i == sub_0203769C()) {
                Sprite_SetAnimCtrlSeq(scene->unk_23C[i], PlayerProfile_GetTrainerGender((PlayerProfile *)scene->unk_374[i].unk_00) * 2 + 0x27);
            } else {
                Sprite_SetAnimCtrlSeq(scene->unk_23C[i], i * 2 + 0x1C);
            }
            scene->unk_39C[i] = 0;
            break;
        }
    }
    if (played) {
        PlaySE(0x64E);
    }
}

void ov85_021EA2C0(ArcScene *scene, NARC *narc) {
    scene->unk_344 = GfGfxLoader_GetPlttData((NarcId)0x64, 9, (NNSG2dPaletteData **)&scene->unk_34C, (enum HeapID)0x66);
    scene->unk_348 = GfGfxLoader_GetPlttDataFromOpenNarc(narc, 7, (NNSG2dPaletteData **)&scene->unk_350, (enum HeapID)0x66);
    scene->unk_334 = GfGfxLoader_GetCharData((NarcId)0x64, 0x2B, TRUE, (NNSG2dCharacterData **)&scene->unk_33C, (enum HeapID)0x66);
    scene->unk_338 = GfGfxLoader_GetCharDataFromOpenNarc(narc, 9, TRUE, (NNSG2dCharacterData **)&scene->unk_340, (enum HeapID)0x66);
}

void ov85_021EA324(ArcGfxHolder *a0, ArcGfxHolder *a1, int a2, int a3, int a4) {
    int idx = SpriteToUnionRoomAvatarIdx(a4, a3);
    void *pltt = a1->unk_04->unk_0C;
    GX_LoadOBJ((u8 *)a0->unk_04->unk_14 + idx * 0x600, ov85_021EA8E0[a2], 0x600);
    GX_LoadOBJPltt((u8 *)pltt + idx * 0x20, (a2 + 7) * 0x20, 0x20);
}

void ov85_021EA368(ArcScene *work) {
    Heap_Free(work->unk_344);
    Heap_Free(work->unk_348);
    Heap_Free(work->unk_334);
    Heap_Free(work->unk_338);
}

int ov85_021EA398(ArcScene *work) {
#pragma unused(work)
    return 1;
}

void ov85_021EA39C(ArcScene *scene, int a1) {
    if (sub_0203769C() == 0) {
        if (a1 == -1) {
            sub_02038C1C(1);
        } else {
            int v = a1 + sub_02037454();
            if (v > 5) {
                v = 5;
            }
            sub_02038C1C(v);
        }
        if (a1 == -1) {
            scene->unk_4A51 = 2;
        } else if (a1 == 0) {
            scene->unk_4A51 = 1;
        } else {
            scene->unk_4A51 = 0;
        }
    }
}

int ov85_021EA3F0(ArcScene *scene, int a1) {
    int v = ov85_021E9FD0();
    if (v > (int)((ArcSub10 *)scene->unk_010)->unk_2C) {
        u8 x = 1;
        sub_02096D4C(scene->unk_010, 7, &x, 1);
        scene->unk_4A48 = 1;
    } else {
        scene->unk_4A48 = 0;
    }
    if (v == (int)scene->unk_4A44) {
        return 1;
    }
    switch (v) {
    case 1:
        if ((int)sub_02037454() > 1 || sub_02033250() > 1) {
            return 1;
        }
        scene->unk_354 = 0x11;
        ov85_021EA39C(scene, -1);
        if (scene->unk_330 != NULL) {
            Clear2dMenuWindowAndDelete(scene->unk_330, (enum HeapID)0x66);
            scene->unk_330 = NULL;
        }
        return 2;
    case 2:
    case 3:
    case 4:
        sub_0205A904(0xD);
        if (v < (int)scene->unk_4A44) {
            switch (scene->unk_4A51) {
            case 0:
                ov85_021EA39C(scene, a1);
                break;
            case 1:
                ov85_021EA39C(scene, 0);
                break;
            }
            ((ArcSub10 *)scene->unk_010)->unk_2C = sub_02037454();
        }
        break;
    case 5:
        sub_0205A904(0xC);
        ov85_021EA39C(scene, a1);
        break;
    }
    scene->unk_4A44 = ov85_021E9FD0();
    return 1;
}

void ov85_021EA4EC(void *a0, void *a1) {
#pragma unused(a0)
#pragma unused(a1)
}
