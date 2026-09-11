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
void ov85_021EA39C(ArcScene *work, int a1);
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

void ov85_021E9324(ArcScene *work);

void ov85_021E943C(ArcScene *work);

void ov85_021E9FCC(ArcScene *work);

void ov85_021EA4EC(void *a0, void *a1);

int ov85_021EA398(ArcScene *work);

void ov85_021E9458(ArcScene *work, u32 a1);

int ov85_021E9440(ArcScene *work, int state);

int ov85_021E9614(ArcScene *work, int state);

int ov85_021E96B0(ArcScene *work, int state);

int ov85_021E9A90(ArcScene *work, int state);

int ov85_021E98E0(ArcScene *work, int state);

int ov85_021E9B1C(ArcScene *work, int state);

int ov85_021E9468(ArcScene *work, int state);

int ov85_021E9AF0(ArcScene *work, int state);

int ov85_021E9A6C(ArcScene *work, int state);

int ov85_021E98C4(ArcScene *work, int state);

int ov85_021E9814(ArcScene *work, int state);

int ov85_021E97E8(ArcScene *work, int state);

int ov85_021E92F8(ArcScene *work, int state);

int ov85_021E9EA4(void);

int ov85_021E9FD0(void);

u32 ov85_021E9FEC(void);

BOOL ov85_021EA17C(u32 printerId);

void ov85_021EA19C(ArcScene *work);

void ov85_021E8C14(BgConfig *bgConfig);

// ---- batch C: remaining state dispatchers ----
int ov85_021E948C(ArcScene *work, int state);
int ov85_021E94BC(ArcScene *work, int state);
int ov85_021E94EC(ArcScene *work, int state);
void ov85_021EA39C(ArcScene *work, int a1);
int ov85_021E96D0(ArcScene *work, int state);
int ov85_021E97B8(ArcScene *work, int state);
int ov85_021E9834(ArcScene *work, int state);
int ov85_021E9900(ArcScene *work, int state);
int ov85_021E993C(ArcScene *work, int state);
int ov85_021E9AB0(ArcScene *work, int state);
int ov85_021E9C50(ArcScene *work, int state);

int ov85_021E948C(ArcScene *work, int state);

int ov85_021E94BC(ArcScene *work, int state);

int ov85_021E94EC(ArcScene *work, int state);

int ov85_021E96D0(ArcScene *work, int state);

int ov85_021E993C(ArcScene *work, int state);

int ov85_021E97B8(ArcScene *work, int state);

int ov85_021E9834(ArcScene *work, int state);

int ov85_021E9900(ArcScene *work, int state);

int ov85_021E9AB0(ArcScene *work, int state);

int ov85_021E9C50(ArcScene *work, int state);

// ---- batch D ----
void ov85_021E9288(ArcScene *work);
void ov85_021EA368(ArcScene *work);
void ov85_021E8E00(ArcScene *work);
void ov85_021E8F58(void);
void ov85_021E83E0(ArcWork *work);
void ov85_021E8428(ArcWork *work, ArcMsg *msg);

void ov85_021E9288(ArcScene *work);

void ov85_021EA368(ArcScene *work);

void ov85_021E8E00(ArcScene *work);

void ov85_021E8F58(void);

// ---- batch E ----
void *ov85_021E8588(ArcScene *work, u32 member, int atStart);
int ov85_021E9BA0(ArcScene *work, int state);
int ov85_021E92B8(ArcScene *work, int state);
BOOL ov85_021E8834(ArcWork *work);
void ov85_021E9244(Window *window, String *str, u32 speed);

void *ov85_021E8588(ArcScene *work, u32 member, int atStart);

int ov85_021E9BA0(ArcScene *work, int state);

int ov85_021E92B8(ArcScene *work, int state);

BOOL ov85_021E8834(ArcWork *work);

void ov85_021E8F88(ArcScene *work, NARC *narc);

void ov85_021E8F88(ArcScene *work, NARC *narc);

BOOL ov85_021E9EC0(Window *window, u32 a1, u32 color, ArcScene *scene);
void ov85_021E9160(ArcScene *work);

void ov85_021E9084(ArcScene *work);

void ov85_021E9084(ArcScene *work);

void ov85_021E9160(ArcScene *work);

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

int ov85_021E9A1C(ArcScene *scene, int a1);

void ov85_021E9E58(u16 *p);

void ov85_021EA324(ArcGfxHolder *a0, ArcGfxHolder *a1, int a2, int a3, int a4);

// ================= batch B =================
void ov85_021E86CC(ArcWork *work, int a1);
int ov85_021E9864(ArcScene *scene, int a1);
int ov85_021E9B40(ArcScene *scene, int a1);
void ov85_021EA39C(ArcScene *scene, int a1);

void ov85_021E86CC(ArcWork *work, int a1);

int ov85_021E9864(ArcScene *scene, int a1);

int ov85_021E9B40(ArcScene *scene, int a1);

void ov85_021EA39C(ArcScene *scene, int a1);

// ================= batch C =================
int ov85_021E962C(ArcScene *scene, int a1);
int ov85_021E9BDC(ArcScene *scene, int a1);
void ov85_021EA2C0(ArcScene *scene, NARC *narc);

int ov85_021E962C(ArcScene *scene, int a1);

int ov85_021E9BDC(ArcScene *scene, int a1);

void ov85_021EA0EC(ArcScene *scene, int a1, int a2);

void ov85_021EA2C0(ArcScene *scene, NARC *narc);

// ================= batch D =================
int ov85_021E9700(ArcScene *scene, int a1);
int ov85_021E996C(ArcScene *scene, int a1);

int ov85_021E9700(ArcScene *scene, int a1);

int ov85_021E996C(ArcScene *scene, int a1);

// ================= batch E =================
void ov85_021E8D64(ArcScene *scene, NARC *narc);
void ov85_021E9D9C(ArcScene *scene, int a1, int a2);

void ov85_021E8D64(ArcScene *scene, NARC *narc);

void ov85_021E9D9C(ArcScene *scene, int a1, int a2);

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

BOOL ov85_021EA010(ArcScene *scene);

void ov85_021EA1AC(ArcScene *scene);

int ov85_021EA3F0(ArcScene *scene, int a1);

// ================= round-6 tail batch =================
BOOL ov85_021E9EC0(Window *window, u32 a1, u32 color, ArcScene *scene);

BOOL ov85_021E9EC0(Window *window, u32 a1, u32 color, ArcScene *scene);

void ov85_021E9C84(ArcScene *scene, int msg, int a2);

void ov85_021E9C84(ArcScene *scene, int msg, int a2);

/* ---- run 1: 3 functions, source order == reference address order ---- */
void ov85_021E83E0(ArcWork *work);
void ov85_021E8418(ArcWork *work);
void ov85_021E8428(ArcWork *work, ArcMsg *msg);

void ov85_021E83E0(ArcWork *work) {
    memset(work->unk_C4C, 0, 0x50);
    work->unk_DC4 = SysTask_CreateOnMainQueue(ov85_021E83C0, work, 0x104);
    if (work->unk_DC4 == NULL) {
        GF_AssertFail();
    }
}

void ov85_021E8418(ArcWork *work) {
    SysTask_Destroy((SysTask *)*(void **)((u8 *)work + 0xDC4));
}

void ov85_021E8428(ArcWork *work, ArcMsg *msg) {
    ArcEntry *e;
    e = &work->unk_C4C[msg->unk_0C];
    if (msg->unk_0C < 5) {
    } else {
        GF_AssertFail();
    }
    if (e->unk_00 != 0) {
        GF_AssertFail();
    }
    e->unk_00 = 1;
    e->unk_0C = msg;
}
