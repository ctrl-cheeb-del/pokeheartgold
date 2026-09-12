#include "overlay40_pc_box_theme_private.h"

void ov40_02238EBC(void *p, u32 *a);
void ov40_02238F00(void *p);
void ov40_02239340(void *p);
void ov40_022393F4(void *p);
void ov40_02239418(void *p);
void ov40_02239514(void *p);
u32 ov40_02239538(void *p, int idx);
void ov40_02239574(void *p);
void ov40_022397BC(void *p, int a);
void ov40_02239838(void *p);
void ov40_022398F8(void *p);
void ov40_0223992C(void *p);
void ov40_02239954(u32 sel, int flag, void *scene);
int ov40_022399B8(void *p);
int ov40_02239A58(void *p);

int ov40_0223A034(void *p) {
    void *w = PTR(p, 0x860);
    ov40_0222FA88((u8 *)p + 0x47C);
    ov40_0222F6D0((u8 *)p + 0x49C, *(s16 *)((u8 *)p + 0x48C));
    ov40_0222F09C((u8 *)p + 0x49C, p, WORD(w, 0xC), WORD(w, 0x14), PTR(w, 0x748));
    TouchHitboxController_IsTriggered(PTR(w, 0xDC));
    return 0;
}

int ov40_0223A080(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_02230964(p, 1);
        ov40_0222FA24((u8 *)p + 0x47C);
        ov40_0222F720((u8 *)p + 0x49C);
        if (PTR(w, 0x748) != NULL) {
            String_Delete(PTR(w, 0x748));
        }
        ov40_0222F920((u8 *)p + 0x49C, p);
        ov40_02230964(p, 0);
        sub_020879E0(PTR(p, 0x6F4), 0);
        GfGfx_EngineBTogglePlanes(4, 0);
        GfGfx_EngineATogglePlanes(4, 0);
        WORD(p, 8) = WORD(p, 8) + 1;
        break;
    case 1:
        ov40_0222DA84((u8 *)w + 8, 1);
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 0)) {
            WORD(p, 8) = WORD(p, 8) + 1;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
        PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, WORD(w, 8), WORD(p, 0x58));
        break;
    default:
        ov40_0222BF80(p, 8);
        break;
    }
    return 0;
}

int ov40_0223A158(void *p) {
    void *w = PTR(p, 0x860);
    switch (WORD(p, 8)) {
    case 0:
        ov40_022393F4(p);
        ov40_02239514(p);
        ov40_02230964(p, 1);
        ov40_022398F8(p);
        ov40_02230964(p, 0);
        TouchHitboxController_Destroy(PTR(w, 0xDC));
        WORD(p, 8) = WORD(p, 8) + 1;
        break;
    case 1:
        ov40_02230964(p, 1);
        ov40_0222DAA8((u8 *)w + 8);
        ov40_0222D88C(p);
        ov40_02230964(p, 0);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 7);
        ov40_0222FB90(p, 1);
        WORD(p, 8) = WORD(p, 8) + 1;
        break;
    default:
        if (ov40_0222FBB4(p) != NULL) {
            if (ov40_0222DA84((u8 *)w + 8, 0)) {
                ov40_0222DD08(p);
                ov40_0222DAA8((u8 *)w + 8);
                PaletteData_BlendPalettes(PTR(p, 0x28), 2, 0xC, 0x10, WORD(p, 0x58));
                ov40_0222BF64(p, 1, TRUE, (u32 *)PTR(p, 0x10));
                ov40_0222BF80(p, 5);
                Heap_Free(w);
            } else {
                PaletteData_BlendPalettes(PTR(p, 0x28), 1, 2, WORD(w, 8), WORD(p, 0x58));
                PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, WORD(w, 8), WORD(p, 0x58));
            }
        }
        break;
    }
    return 0;
}
