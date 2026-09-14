#include "to46_overlay40_mode_transition_tail_private.h"

void ov40_0222E79C(void *, void *);
void ov40_0222E7DC(void *, int);
void ov39_022271C0(void *, void *);
void ov40_02235868(void *, u32);
int ov40_02235434(void *);
int ov40_02235644(void *);

int ov40_02235434(void *p) {
    void *w = PTR(p, 0x860);

    switch (S32(p, 8)) {
    case 0:
        if (S32(w, 0xC) == 0) {
            ov40_02236130(p);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        } else {
            ov40_02230964(p, 1);
            ov40_0222E7B8((u8 *)w + 0x250, p);
            ov40_02230964(p, 0);
        }
        S32(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 1)) {
            if (S32(w, 0xC) == 0) {
                if (PTR(w, 0x228) != NULL) {
                    ov41_0224B57C();
                    ov40_0222BC54(p);
                    SetBgPriority(2, 0);
                    PTR(w, 0x228) = NULL;
                    ov40_02235994();
                }
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                GfGfx_EngineATogglePlanes(4, 0);
            }
            S32(p, 8)
            ++;
        }
        break;
    case 2:
        if (S32(w, 0xC) == 0) {
            ov40_02230964(p, 1);
            ov39_022271C0(PTR((u8 *)w + S32(w, 0x234) * 4, 0x23C), PTR(w, 0x250));
            ov40_0222E79C((u8 *)w + 0x250, p);
            ov40_0222E7DC((u8 *)w + 0x250, 0);
            ov40_02230964(p, 0);
            ov40_022307DC(p, 0x50, 3);
        } else {
            ov39_02227080((u8 *)PTR((u8 *)w + S32(w, 0x234) * 4, 0x23C) + 0x80, PTR(w, 0x238));
            PTR(w, 0x228) = ov41_0224B530((u8 *)w + 0x218, PTR(w, 0x238));
            ov41_0224B5D0(PTR(w, 0x228), 0);
            ov40_02235940();
            ov40_022307DC(p, 0x23, 3);
            GfGfx_EngineBTogglePlanes(8, 1);
            GfGfx_EngineATogglePlanes(8, 1);
            GfGfx_EngineATogglePlanes(4, 0);
            GfGfx_EngineATogglePlanes(1, 0);
        }
        S32(p, 8)
        ++;
        break;
    case 3:
        if (S32(w, 0xC) != 0) {
            PaletteData_LoadPaletteSlotFromHardware(PTR(p, 0x28), 0, 0, 0x200);
        }
        S32(p, 8)
        ++;
        break;
    case 4:
        if (ov40_0222DA00(w, (u8 *)w + 4, 0, 1)) {
            if (S32(w, 0xC) == 0) {
                ov40_0222E7DC((u8 *)w + 0x250, 1);
                GfGfx_EngineATogglePlanes(4, 1);
            } else {
                ov40_02235C7C(p, S32(w, 0x234));
                ov41_0224B5D0(PTR(w, 0x228), 1);
                GfGfx_EngineATogglePlanes(4, 1);
                GfGfx_EngineATogglePlanes(1, 1);
            }
            S32(p, 8)
            ++;
        }
        break;
    default:
        S32(w, 0xC) ^= 1;
        ov40_02235868(p, S32(w, 0xC) + 0x79);
        ov40_0222BF80(p, 8);
        break;
    }
    return 0;
}

int ov40_02235644(void *p) {
    void *w = PTR(p, 0x860);

    switch (S32(p, 8)) {
    case 0:
        if (S32(w, 0xC) == 0) {
            ov40_02236130(p);
            BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        } else {
            ov40_02230964(p, 1);
            ov40_0222E7B8((u8 *)w + 0x250, p);
            ov40_02230964(p, 0);
        }
        S32(p, 8)
        ++;
        break;
    case 1:
        if (ov40_0222DA00(w, (u8 *)w + 4, 1, 1)) {
            if (S32(w, 0xC) == 0) {
                if (PTR(w, 0x228) != NULL) {
                    ov41_0224B57C();
                    ov40_0222BC54(p);
                    SetBgPriority(2, 0);
                    PTR(w, 0x228) = NULL;
                    ov40_02235994();
                }
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
                BgClearTilemapBufferAndCommit(PTR(p, 0x24), 3);
                GfGfx_EngineATogglePlanes(4, 0);
            }
            S32(p, 8)
            ++;
        }
        break;
    case 2:
        ov40_02230964(p, 1);
        if (S32(w, 0xC) == 0) {
            ov39_02227080((u8 *)PTR((u8 *)w + S32(w, 0x234) * 4, 0x23C) + 0x80, PTR(w, 0x238));
            PTR(w, 0x228) = ov41_0224B530((u8 *)w + 0x218, PTR(w, 0x238));
            ov41_0224B5D0(PTR(w, 0x228), 0);
            ov40_02235940();
            ov40_022307DC(p, 0x23, 3);
            GfGfx_EngineBTogglePlanes(8, 1);
            GfGfx_EngineATogglePlanes(8, 1);
            GfGfx_EngineATogglePlanes(4, 0);
            GfGfx_EngineATogglePlanes(1, 0);
        } else {
            ov39_022271C0(PTR((u8 *)w + S32(w, 0x234) * 4, 0x23C), PTR(w, 0x250));
            ov40_0222E79C((u8 *)w + 0x250, p);
            ov40_0222E7DC((u8 *)w + 0x250, 0);
            ov40_022307DC(p, 0x50, 3);
            GfGfx_EngineATogglePlanes(4, 0);
        }
        ov40_02230964(p, 0);
        S32(p, 8)
        ++;
        break;
    case 3:
        if (S32(w, 0xC) == 0) {
            PaletteData_LoadPaletteSlotFromHardware(PTR(p, 0x28), 0, 0, 0x200);
        }
        S32(p, 8)
        ++;
        break;
    case 4:
        if (ov40_0222DA00(w, (u8 *)w + 4, 0, 1)) {
            if (S32(w, 0xC) == 0) {
                ov40_02235C7C(p, S32(w, 0x234));
                ov41_0224B5D0(PTR(w, 0x228), 1);
                GfGfx_EngineATogglePlanes(4, 1);
                GfGfx_EngineATogglePlanes(1, 1);
            } else {
                ov40_0222E7DC((u8 *)w + 0x250, 1);
                GfGfx_EngineATogglePlanes(4, 1);
            }
            S32(p, 8)
            ++;
        }
        break;
    default:
        ov40_0222BF80(p, 8);
        break;
    }
    return 0;
}
