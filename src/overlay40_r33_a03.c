#include "global.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

typedef struct Ov40Entry {
    u8 raw[0xE4];
} Ov40Entry;

typedef struct Ov40Work {
    u8 pad0[0x2608];
    Ov40Entry *ptrs[30];
    Ov40Entry entries[30];
    s32 count;
} Ov40Work;

void GfGfx_EngineBTogglePlanes(int plane, BOOL enable);
void GfGfx_EngineATogglePlanes(int plane, BOOL enable);
BOOL ov40_0222DA00(int *a, int *b, int c, int d);
int ov40_0222DA84(int *p, int direction);
void ov40_0223CE38(void *p);
void BgClearTilemapBufferAndCommit(void *bgConfig, int bgId);
void ov40_0223A510(void *p, int msgId, int arg);
void PaletteData_BlendPalettes(void *palette, int buffer, int mask, int coeff, int color);
void ov40_0222BF80(void *p, int state);
void GfGfxLoader_LoadScrnDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int size, int compressed, int heapId);
void ov40_0223CD58(void *p);
void ov40_0223CCA0(void *p);
void ov40_0223CD14(void *p);
void GfGfxLoader_LoadCharDataFromOpenNarc(void *narc, int memberNo, void *bgConfig, int layer, int tileStart, int size, int compressed, int heapId);
void ov40_02230964(void *p, void *value);
void ov40_0223064C(void *obj, void *p);
void ov40_02230638(void *obj, void *p);
void ov40_022306A0(void *obj, int value);
int ov40_02230410(void *obj);
void ov40_022307DC(void *p, int value, int bgId);
void ov40_0222E7B8(void *obj, void *p);
void ov40_0222E79C(void *obj, void *p);
void ov40_0222E7DC(void *obj, int value);
void ManagedSprite_SetAnim(void *sprite, int anim);
void ov40_0222D66C(void *dst, void *src, int id);
int ov40_0222FC14(void *a0, void *a1, u8 value);
void ov40_022306E0(void *p);
void ov40_0223077C(void *a0, void *a1, int a2, int a3);
void sub_020879E0(void *p, int value);
void sub_02087A08(void *p, int a, int b);
void PlaySE(int seqNo);
void StopSE(int seqNo, int fadeFrames);
BOOL ov40_0223D5CC(void);
void *sub_020307F8(void);
u64 sub_0203088C(void *p, int a, int b);
void *ov40_0223D540(void *p);
BOOL ov39_0222774C(void *p, u64 value);
BOOL ov39_02227D44(void *p, u32 *value);
BOOL System_GetTouchNew(void);
void ov40_0222DEAC(void *p);
void ov40_0223B44C(void *p);
void ov40_0222FDC4(void *p);
void ov40_0222FCCC(void *p);
void ov40_0222F734(void *p);
void TouchHitboxController_Destroy(void *controller);
void ov40_0223A83C(void *p);
void ov40_0222DAA8(void *p);
void ov40_0222D88C(void *p);
void sub_0203A948(int a, int heapId);
void ov40_0222FB90(void *p, int value);
BOOL ov40_0222FBB4(void *p);
void ov40_0222DD08(void *p);
void ov40_0222BF64(void *p, int a1, int a2, void *a3);
void Heap_Free(void *p);
BOOL sub_0202FC48(void);
void sub_0202FC24(void);
int ov40_0223A874(void *p);
int ov40_0223A924(void *p);
int ov40_0223AC24(void *p);
int ov40_0223ACD0(Ov40Work *p);

int ov40_0223A874(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        GfGfx_EngineBTogglePlanes(4, FALSE);
        WORD(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA00(w, (int *)w + 1, 1, 2)) {
            ov40_0223CE38(p);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
            WORD(p, 8)
            ++;
        }
        break;
    case 2:
        ov40_0222DA84((int *)w + 2, 0);
        if (ov40_0222DA00(w, (int *)w + 1, 0, 2)) {
            ov40_0223A510(p, 0x64, 0);
            GfGfx_EngineBTogglePlanes(4, TRUE);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 0xC);
        break;
    }
    return 0;
}

int ov40_0223A924(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        GfGfx_EngineBTogglePlanes(4, FALSE);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((int *)w + 2, 1);
        if (ov40_0222DA00(w, (int *)w + 1, 1, 2)) {
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
            ov40_0223A510(p, 0x116, 0);
            ov40_022306E0(p);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 2: {
        u32 off = WORD(p, 0x4D4);
        if (ov40_0222FC14(p, PTR(w, 0x2028), *(u8 *)((u8 *)p + off + 0x413C))) {
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 3:
        ov40_0223077C(p, PTR(p, 0x6F0), 0x80, 0x60);
        sub_020879E0(PTR(p, 0x6F0), 1);
        sub_02087A08(PTR(p, 0x6F0), 0x18, 0x18);
        WORD(p, 8)
        ++;
        PlaySE(0x57D);
        break;
    case 4: {
        u64 value;
        if (!ov40_0223D5CC()) {
            return 0;
        }
        ov40_0223A510(p, 0x118, 0);
        value = sub_0203088C(sub_020307F8(), 4, 0);
        if (ov39_0222774C(ov40_0223D540(p), value) == TRUE) {
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 5: {
        u32 value;
        if (!ov40_0223D5CC()) {
            return 0;
        }
        if (ov39_02227D44(ov40_0223D540(p), &value) == TRUE) {
            StopSE(0x57D, 0);
        } else {
            StopSE(0x57D, 0);
            PlaySE(0x577);
        }
        WORD(p, 8)
        ++;
        ov40_0223A510(p, 0x119, 0);
        break;
    }
    case 6:
        if (System_GetTouchNew()) {
            ov40_0222DEAC(p);
            ov40_02230964(p, (void *)1);
            ov40_0223B44C(p);
            ov40_02230964(p, NULL);
            sub_020879E0(PTR(p, 0x6F0), 0);
            sub_02087A08(PTR(p, 0x6F0), 0, 0);
            ov40_0222FDC4(p);
            ov40_0222FCCC(p);
            ov40_0222F734((u8 *)p + 0x49C);
            WORD(p, 8)
            ++;
        }
        break;
    case 7:
        TouchHitboxController_Destroy(PTR(w, 0x188));
        TouchHitboxController_Destroy(PTR(w, 0x18C));
        TouchHitboxController_Destroy(PTR(w, 0x190));
        ov40_0223A83C(p);
        ov40_0222DAA8((u8 *)w + 8);
        ov40_02230964(p, (void *)1);
        ov40_0222D88C(p);
        ov40_02230964(p, NULL);
        sub_0203A948(1, 0x6D);
        ov40_0222FB90(p, 1);
        WORD(p, 8)
        ++;
        break;
    default:
        if (ov40_0222FBB4(p)) {
            if (ov40_0222DA84((int *)w + 2, 0)) {
                ov40_0222DD08(p);
                ov40_0222DAA8((u8 *)w + 8);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, (u16)WORD(p, 0x58));
                ov40_0222BF64(p, 1, 1, PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
                Heap_Free(w);
                if (sub_0202FC48() == TRUE) {
                    sub_0202FC24();
                }
            } else {
                PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
                PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
            }
        }
        break;
    }
    return 0;
}

int ov40_0223AC24(void *p) {
    void *w = PTR(p, 0x860);

    switch (WORD(p, 8)) {
    case 0:
        ov40_0222DA84((int *)w + 2, 1);
        if (ov40_0222DA00(w, (int *)w + 1, 1, 2)) {
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x54, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
            ov40_0223A510(p, 0x66, WORD(w, 0x2028));
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 1:
        if (ov40_0222DA00(w, (int *)w + 1, 0, 2)) {
            ov40_0223CD58(p);
            GfGfx_EngineBTogglePlanes(4, TRUE);
            WORD(p, 8)
            ++;
        }
        break;
    default:
        ov40_0222BF80(p, 0xF);
        break;
    }
    return 0;
}

int ov40_0223ACD0(Ov40Work *p) {
    void *w = PTR(p, 0x860);
    int i;

    switch (WORD(p, 8)) {
    case 0:
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        GfGfx_EngineBTogglePlanes(4, FALSE);
        GfGfx_EngineATogglePlanes(4, FALSE);
        WORD(p, 8)
        ++;
        break;
    case 1:
        ov40_0222DA84((int *)w + 2, 1);
        if (ov40_0222DA00(w, (int *)w + 1, 1, 0)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 2:
        if (WORD(p, 0x86C) == 0xD2) {
            ov40_0222D66C((u8 *)w + 0x114, (u8 *)p + 0x14, 3);
            ov40_0222D66C((u8 *)w + 0x130, (u8 *)p + 0x14, 0x5E);
            ManagedSprite_SetAnim(PTR(w, 0x118), 0);
            ManagedSprite_SetAnim(PTR(w, 0x134), 3);
        }
        ov40_0223CCA0(p);
        ov40_0223CD14(p);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        GfGfxLoader_LoadCharDataFromOpenNarc(PTR(p, 0x14), 0x3E, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        ov40_02230964(p, (void *)1);
        if (WORD(w, 0x10) == 0) {
            ov40_0223064C((u8 *)w + 0x220, p);
            ov40_02230638((u8 *)w + 0x220, p);
            ov40_022306A0((u8 *)w + 0x220, 0);
            ov40_022307DC(p, ov40_02230410((u8 *)w + 0x220), 3);
        } else {
            ov40_0222E7B8((u8 *)w + 0x194, p);
            ov40_0222E79C((u8 *)w + 0x194, p);
            ov40_0222E7DC((u8 *)w + 0x194, 0);
            GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 0x50, PTR(p, 0x24), 3, 0, 0, 0, 0x6D);
        }
        ov40_02230964(p, NULL);
        GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(p, 0x14), 6, PTR(p, 0x24), 7, 0, 0, 0, 0x6D);
        WORD(p, 8)
        ++;
        break;
    case 3:
        ov40_0222DA84((int *)w + 2, 0);
        if (ov40_0222DA00(w, (int *)w + 1, 0, 0)) {
            if (WORD(w, 0x10) == 0) {
                ov40_022306A0((u8 *)w + 0x220, 1);
            } else {
                ov40_0222E7DC((u8 *)w + 0x194, 1);
            }
            GfGfx_EngineBTogglePlanes(4, TRUE);
            GfGfx_EngineATogglePlanes(4, TRUE);
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    default:
        for (i = 0; i < p->count; i++) {
            p->ptrs[i] = &p->entries[i];
        }
        ov40_0222BF80(p, 7);
        break;
    }
    return 0;
}
