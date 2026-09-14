#include "to47r5_overlay96_selection_update_private.h"

#define F32AT(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define S32AT(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define U32AT(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PAT(p, o)   (*(void **)((u8 *)(p) + (o)))

typedef struct Ov96R71Rect {
    s16 x;
    s16 y;
    s16 w;
    s16 h;
} Ov96R71Rect;

extern void ov96_021FA7BC(void *, u32, u32, void *);
extern void *ov96_021FA340(void *, s32);
extern BOOL ov96_021FBEA0(void);
extern void ov96_021FBEA4(void *);
extern void ov96_021FBF5C(void *, Ov96R71Rect *);
extern s32 ov96_021EAF8C(void *);
extern s32 ov96_021EAF90(void *);
extern u32 ov96_021FAB04(s32, const Ov96R71Rect *);
extern u32 ov96_021FAAE0(s32, s32, const Ov96R71Rect *);
extern void ov96_021FBCB8(void *, void *);
extern void *ov96_021EB5B8(void *);
extern void Sprite_SetDrawFlag(void *, u32);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern void ov96_021FB6B4(void *, u32, u32);
extern void ov96_021FB6C8(void *, void *);
extern void ov96_021FBEFC(void *, s32);
extern void ov96_021FC6EC(void *, u32, s32);
extern void ov96_021FA83C(u32, void *, void *);
extern void ov96_021EAC0C(void *, u32);
extern void ov96_021FAB24(void *, void *);
extern void sub_0200606C(u32, u32);
extern void sub_020061D0(u32, s32);
extern const u8 ov96_0221DC2C[];
extern const s8 ov96_0221DC28[];

extern void ov96_021FA34C(void *, void *, void *, void *);



void ov96_021FA34C(void *sys, void *work, void *node, void *sel) {
    BOOL hit;
    void *spr;
    s32 i;
    s32 dy;
    f32 sum;
    BOOL go;
    Ov96R71Rect r1;
    Ov96R71Rect r2;

    if (U8AT(node, 8) != 1 && S32AT(node, 0x28) != 2 && U8AT(node, 9) == 0 && F32AT(node, 0xC) < F32AT(node, 0x50)) {
        F32AT(node, 0xC) = F32AT(node, 0xC) + F32AT(node, 0x54);
        if (F32AT(node, 0xC) > F32AT(node, 0x50)) {
            F32AT(node, 0xC) = F32AT(node, 0x50);
        }
    }
    if (sel != NULL && S32AT(node, 0x28) == 0) {
        ov96_021FA7BC(sys, U32AT(sel, 4), U8AT(node, 0x18), (u8 *)node + 0x24);
        hit = FALSE;
        if (U8AT(node, 0x58) != 0) {
            for (i = 0; i < 4; i++) {
                spr = ov96_021FA340(node, i);
                if (ov96_021FBEA0()) {
                    ov96_021FBF5C(spr, &r1);
                    if (ov96_021FAB04(S32AT(node, 0x3C) + 0x110 - ov96_021EAF8C(PAT(node, 0x24)), &r1)) {
                        hit = TRUE;
                        ov96_021FBCB8(sys, node);
                        break;
                    }
                }
            }
        }
        spr = ov96_021EB5B8(PAT(node, 0x44));
        Sprite_SetDrawFlag(spr, 1);
        if (hit) {
            Sprite_SetAnimCtrlSeq(spr, 0);
        } else {
            Sprite_SetAnimCtrlSeq(spr, 1);
        }
    } else if (sel != NULL && S32AT(node, 0x28) == 1 && S32AT(node, 0x2C) == 3 && U8AT(node, 0x58) != 0) {
        U16AT(node, 0x60) = 1;
        U16AT(node, 0x62) = U16AT(node, 0x62) + 1;
    }

    sum = F32AT(node, 0xC) + F32AT(node, 0x10);
    dy = (s32)sum;
    F32AT(node, 0x10) = sum - (f32)dy;
    U16AT(node, 0) = U16AT(node, 0) + dy;
    ov96_021FB6B4(work, U16AT(node, 0), U8AT(node, 0x18));
    ov96_021FB6C8(work, node);
    U16AT(node, 4) = U16AT(node, 4) - dy;
    if ((s32)(U16AT(node, 4) + 0x200) <= 0) {
        U16AT(node, 4) = U16AT(node, 4) + 0x200;
    }
    U16AT(node, 6) = U16AT(node, 4) + 0x110;
    if ((s32)(U16AT(node, 6) + 0x200) <= 0) {
        U16AT(node, 6) = U16AT(node, 6) + 0x200;
    }
    for (i = 0; i < 4; i++) {
        ov96_021FBEFC(ov96_021FA340(node, i), dy);
    }
    ov96_021FC6EC(PAT(work, 0xDC), U8AT(node, 0x18), dy);
    ov96_021FA83C(U8AT(node, 0x18), (u8 *)node + 0x24, (u8 *)node + 0xC);

    if (U8AT(node, 8) == 1) {
        if (S32AT(node, 0x28) == 0) {
            S32AT(node, 0x28) = 3;
        } else if (S32AT(node, 0x28) == 3 || S32AT(node, 0x28) == 1) {
            s32 n3c = S32AT(node, 0x3C);
            if (U16AT(node, 0) >= 0x1080) {
                if (n3c == 120) {
                    S32AT(node, 0x28) = 4;
                    S32AT(node, 0xC) = 0;
                    S32AT(node, 0x10) = 0;
                }
            } else if (U16AT(node, 0) >= 0x1000) {
                U32AT(node, 0xC) = 0x3F800000;
                S32AT(node, 0x10) = 0;
                ov96_021EAC0C(PAT(node, 0x24), 1);
                Sprite_SetAnimCtrlSeq(ov96_021EB5B8(PAT(node, 0x4C)), 0);
            }
        }
        ov96_021FAB24(PAT(work, 4), node);
        return;
    } else {
        go = TRUE;
        if (S32AT(node, 0x28) == 1) {
            go = FALSE;
        }
        if (U16AT(node, 0x60) == 1 && U16AT(node, 0x62) == 1) {
            go = TRUE;
        }
        if (go) {
            for (i = 0; i < 4; i++) {
                spr = ov96_021FA340(node, i);
                if (ov96_021FBEA0()) {
                    void *ref = PAT(node, 0x24);
                    ov96_021FBF5C(spr, &r2);
                    if (ov96_021FAAE0(S32AT(node, 0x3C) + 0x110 - ov96_021EAF90(ref), (u8)ov96_021EAF8C(ref), &r2)) {
                        ov96_021FBEA4(spr);
                        sub_0200606C(0x8A5, ov96_0221DC2C[U8AT(node, 0x18)]);
                        sub_020061D0(ov96_0221DC2C[U8AT(node, 0x18)], ov96_0221DC28[U8AT(node, 0x18)]);
                        if (U16AT(node, 0x60) == 1 && U16AT(node, 0x62) == 1) {
                            ov96_021E8228(sys, (u8)ov96_021E5F24(sys), U8AT(node, 0x18), 2, 1);
                            U8AT(node, 0x30) = 3;
                            S32AT(node, 0x2C) = 1;
                            ov96_021FBCB8(sys, node);
                        } else {
                            U32AT(node, 0xC) = 0x3F000000;
                            U8AT(node, 9) = 0;
                            S32AT(node, 0x28) = 2;
                            U8AT(node, 0x31) = 0;
                            U8AT(node, 0x32) = 1;
                            S32AT(node, 0x2C) = 4;
                            Sprite_SetAnimCtrlSeq(ov96_021EB5B8(PAT(node, 0x4C)), 0);
                            ov96_021E8228(sys, (u8)ov96_021E5F24(sys), U8AT(node, 0x18), 1, 1);
                        }
                        U16AT(node, 0x60) = 0;
                        U16AT(node, 0x62) = 0;
                    }
                }
            }
        }
        if (U8AT(node, 8) != 1 && U16AT(node, 0) >= 0x1000) {
            U8AT(node, 8) = 1;
            U16AT(node, 2) = U32AT(work, 0x230);
            sub_0200606C(0x8AB, ov96_0221DC2C[U8AT(node, 0x18)]);
            U16AT(work, 0x3C4) = 30;
        }
    }
    ov96_021FAB24(PAT(work, 4), node);
}

BOOL ov96_021FA6D0(void *course, void *work) {
    BOOL ret = FALSE;
    s32 hit = -1;
    Ov96R71Sel sel;
    u8 count;
    s32 i;
    u8 *p;

    sel.idx = -1;
    sel.flag = ret;

    if (System_GetTouchNew()) {
        ov96_021E8228(course, (u8)ov96_021E5F24(course), 3, 0, 1);
        hit = ov96_021FB784(work, gSystem.touchX, gSystem.touchY);
        if (hit < 3) {
            sel.idx = hit;
        }
    }

    count = 0;
    i = 0;
    p = (u8 *)work + 0xE0;
    for (; i < 3; i++) {
        void *arg = NULL;
        if (U8AT(p, 8) == 0) {
            if (hit == i) {
                arg = &sel;
            }
        } else {
            count++;
        }
        ov96_021FA34C(course, work, p, arg);
        p += 0x6C;
    }

    G2_SetBG0Offset(0, U16AT(work, 0xE6));
    G2_SetBG1Offset(0, U16AT(work, 0x152));
    G2_SetBG2Offset(0, U16AT(work, 0x1BE));
    G2S_SetBG0Offset(0, U16AT(work, 0xE4));
    G2S_SetBG1Offset(0, U16AT(work, 0x150));
    G2S_SetBG2Offset(0, U16AT(work, 0x1BC));

    if (count >= 3) {
        ret = TRUE;
    }
    return ret;
}
