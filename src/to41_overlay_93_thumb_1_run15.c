#include "to41_overlay_93_thumb_1_private.h"

/* ------------------------------------------------------------------ */
/* Symbols owned by sibling objects (overlay_93_arm.o /
   overlay_93_thumb_2.o) or by the rest of the game.  Prototype only —
   never defined here.  .rodata for this object is left in assembly.    */
/* ------------------------------------------------------------------ */
extern const s32 ov93_022630D8[];
extern const u8 ov93_02262A54[];
extern u32 (*const ov93_02262A20[])(void *, void *);
typedef struct {
    u8 pad[0xa4];
    void *obj;
} Ov93D700;

extern void GF_AssertFail(void);
extern void *OverlayManager_GetArgs(void *);
extern void *OverlayManager_GetData(void *);
extern void *OverlayManager_CreateAndGetData(void *, u32, u32);
extern void OverlayManager_FreeData(void *);
extern BOOL Heap_Create(u32, u32, u32);
extern void Heap_Destroy(u32);
extern void Heap_Free(void *);
extern void Camera_Delete(void *);
extern void *GF_3DVramMan_Create(u32, int, int, int, int, void (*)(void));
extern void GF_3DVramMan_Delete(void *);
extern void *sub_020154D0(void *);
extern void sub_02014EBC(void *);
extern void sub_02015354(u32);
extern void sub_02015394(u32);
extern void sub_02015494(void *, u32, u32);
extern void sub_020181E0(void *, void *);
extern void sub_020181EC(void *);
extern void sub_02018068(void *);
extern void sub_020180F8(void *, void *);
extern u32 sub_0201815C(void *, u32);
extern u32 sub_0203769C(void);
extern u32 sub_02034818(u32);
extern u32 sub_02037B38(u32);
extern void sub_02037AC0(u8);
extern u32 ov90_02258B54(void *p);
extern void ov90_02258800(void *, u32, u32, u32, void *);
extern void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void DrawFrameAndWindow1(void *, u32, u32, u32);
extern void *NewString_ReadMsgData(void *, u32);
extern void AddTextPrinterParameterizedWithColor(void *, u32, void *, u32, u32, u32, u32, u32);
extern void String_Delete(void *);
extern void ScheduleWindowCopyToVram(void *);
extern void GX_BeginLoadTexPltt(void);
extern void GX_LoadTexPltt(const void *, u32, u32);
extern void GX_EndLoadTexPltt(void);
extern void GF_RunVramTransferTasks(void);
extern void SpriteSystem_TransferOam(void);
extern void PaletteData_PushTransparentBuffers(void *);
extern void ToggleBgLayer(u32, u32);
extern void DoScheduledBgGpuUpdates(void *);

/* Defined in this object but not written this round. */
extern void ov93_0225CF34(void);
extern void ov93_0225C6D8(void *, void *);
void *ov93_0225E1A0(void *p, s32 idx);

extern void ov93_02261FB0(void *);
extern void ov93_02262310(void *);
extern void ov93_02262338(void *, void *);
extern void ov93_02262368(void *, void *);
extern u32 ov93_02262724(void *, void *);
extern void PlaySE(u32);
extern void BlendPalette(void *, void *, u16, u8, u16);

extern void sub_02014DA0(void *);
extern void *Heap_Alloc(u32, u32);
extern void *sub_02014DB4(u32 (*)(u32, u32), u32 (*)(u32, u32), void *, u32, u32, u32);
extern void *sub_02015524(void *);
extern void Camera_SetPerspectiveClippingPlane(u32, u32, void *);
extern void *sub_02015264(u32, u32, u32);
extern void sub_0201526C(void *, void *, u32, u32);

/* Defined in a sibling object. */
extern void ov93_02260A14(void *);
extern void ov93_0226114C(void *, void *);
extern void ov93_022612E0(void *, void *);
extern void ov93_02261C3C(void *, void *);
extern u32 ov93_022627C0(void *, void *);
extern void ov93_02262934(void *, u32);
extern u32 ov93_02262748(void *);
extern u32 ov93_0225F9AC(void *);
extern void ov93_0225FBE4(u32);
extern void ov93_0225FABC(void *);

/* ------------------------------------------------------------------ */
/* Forward declarations for everything defined in this file.           */
/* ------------------------------------------------------------------ */
u32 ov93_0225C540(void *man);
u32 ov93_0225C6C0(void *man);
u32 ov93_0225C730(void *p);
void ov93_0225CF14(u32 heapId);
void ov93_0225CFB8(void *vramMan);
void ov93_0225D064(void *p);
void ov93_0225D468(void *p);
void ov93_0225D4B8(void *p);
void ov93_0225D6E0(void *p);
void ov93_0225D700(Ov93D700 *p, u32 kind);
u32 ov93_0225D744(u32 a, u32 b);
u32 ov93_0225D768(u32 a, u32 b);
void ov93_0225DAF8(void *p);
void ov93_0225DBC4(void);
void ov93_0225DD28(void);
void ov93_0225E008(void *p, s32 a, s32 b);
u32 ov93_0225E0F4(void *p);
void ov93_0225E230(void *p, const Ov93Evt *src);
Ov93Evt *ov93_0225E2D4(void *p);
u32 ov93_0225E3B8(void *p);
void ov93_0225E370(void *p);
s32 ov93_0225E45C(void *pp, s32 v);
void ov93_0225E48C(void *p, u32 a, u32 b);
u32 ov93_0225E548(void *p, u32 a);
u32 ov93_0225E764(void *p);
void ov93_0225E7AC(void);
void ov93_0225E860(void *a, void *p);
void ov93_0225EA50(void *a, void *p);
s32 ov93_0225EA6C(void *p, s32 b);
void ov93_0225EA98(void *p);
void ov93_0225EB38(void *p);
u32 ov93_0225EDB8(void *p, s32 d);
void ov93_0225EDE8(void *p);
void ov93_0225EDFC(void *p);
void ov93_0225EE4C(u32 a, u32 b);
void ov93_0225ED3C(void *p);
u32 ov93_0225E4B0(void *p);
u32 ov93_0225E10C(u32 *p);
void ov93_0225E0A4(void *p);
u32 ov93_0225E6F8(void *p, void *state);
void ov93_0225CEA0(void *p);
s32 ov93_0225E3C4(u32 *p, s32 target);
void ov93_0225DED0(void *p);
void ov93_0225E03C(void *p);

void ov93_0225D674(void *p);
void ov93_0225D9E8(void *p);
u32 ov93_0225E1E0(void *p, s32 idx, const Ov93Evt *src);
void ov93_0225E144(void *p, s32 idx, const Ov93Evt *src);
u32 ov93_0225E27C(void *p, const Ov93Evt *src);
u32 ov93_0225E300(void *p);
void ov93_0225EAE0(void *a, void *p, u32 unused, u32 flag);
void ov93_0225ED60(void *p, s32 n);

/* ------------------------------------------------------------------ */

void ov93_0225E144(void *p, s32 idx, const Ov93Evt *src) {
    s32 *ctr;
    Ov93Evt *dst;
    if (ov93_0225E1E0(p, idx, src) == 1) {
        return;
    }
    ctr = (s32 *)((u8 *)p + 0x2f04);
    dst = (Ov93Evt *)((u8 *)p + 0x1c1c + idx * 0x4b0) + ctr[idx] % 0x3c;
    ctr[idx]++;
    if (dst->kind != 0) {
        GF_AssertFail();
    }
    *dst = *src;
}

void *ov93_0225E1A0(void *p, s32 idx) {
    u32 *ctr;
    s32 rem;
    Ov93Evt *arr;
    ctr = (u32 *)((u8 *)p + 0x2f14);
    rem = (s32)ctr[idx] % 0x3c;
    arr = (Ov93Evt *)((u8 *)p + 0x1c1c + 0x4b0 * idx);
    if (arr[rem].kind != 0) {
        ctr[idx]++;
        return &arr[rem];
    }
    return NULL;
}

u32 ov93_0225E1E0(void *p, s32 idx, const Ov93Evt *src) {
    (void)idx;
    switch (src->kind) {
    case 0:
        break;
    case 1:
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        if (((Ov93Sys *)p)->pending.kind != 0) {
            GF_AssertFail();
        }
        ((Ov93Sys *)p)->pending = *src;
        return 1;
    }
    return 0;
}

void ov93_0225E230(void *p, const Ov93Evt *src) {
    Ov93Evt *dst;
    if (ov93_0225E27C(p, src) == 1) {
        return;
    }
    dst = (Ov93Evt *)((u8 *)p + 0x176c) + S32AT(p, 0x2f24) % 0x3c;
    U32AT(p, 0x2f24)
    ++;
    if (dst->kind != 0) {
        GF_AssertFail();
    }
    *dst = *src;
}

u32 ov93_0225E27C(void *p, const Ov93Evt *src) {
    u32 kind = src->kind;
    u32 cur;
    switch (kind) {
    case 0:
        break;
    case 1:
        break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
        cur = ((Ov93Sys *)p)->cur.kind;
        if (cur == 0) {
            ((Ov93Sys *)p)->cur = *src;
            return 1;
        }
        if (kind == cur) {
            return 1;
        }
        GF_AssertFail();
        return 0;
    }
    return 0;
}

Ov93Evt *ov93_0225E2D4(void *p) {
    Ov93Evt *e;
    e = (Ov93Evt *)((u8 *)p + 0x176c) + S32AT(p, 0x2f28) % 0x3c;
    if (e->kind == 0) {
        return NULL;
    }
    return e;
}

u32 ov93_0225E300(void *p) {
    Ov93Evt *e;
    if (((Ov93Sys *)p)->delay > 0) {
        ((Ov93Sys *)p)->delay = ((Ov93Sys *)p)->delay - 1;
        return 0;
    }
    if (((Ov93Sys *)p)->cur.kind != 0) {
        if (ov93_02262724(p, &((Ov93Sys *)p)->cur) == 1) {
            ((Ov93Sys *)p)->cur.kind = 0;
            return 1;
        }
        return 0;
    }
    e = ov93_0225E2D4(p);
    if (e == NULL) {
        return 0;
    }
    if (ov93_02262724(p, e) == 1) {
        e->kind = 0;
        ((Ov93Sys *)p)->tail++;
        return 1;
    }
    return 0;
}

void ov93_0225E370(void *p) {
    s32 i;
    void *e;
    if (ov93_022627C0(p, (u8 *)p + 0x2ef0) == 1) {
        return;
    }
    i = 0;
    for (; i < U8AT(PAT(p, 0), 0x30); i++) {
        do {
            e = ov93_0225E1A0(p, U8AT(PAT(p, 0), 0x2c + i));
            if (e == NULL) {
                break;
            }
            ov93_022627C0(p, e);
        } while (TRUE);
    }
}

u32 ov93_0225E3B8(void *p) {
    return U32AT(p, 0x2fc8);
}
