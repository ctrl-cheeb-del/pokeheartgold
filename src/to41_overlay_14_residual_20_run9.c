#include "to41_overlay_14_residual_20_private.h"

u32 ov14_021E9618(void *p);
u32 ov14_021E9660(void *p);
void ov14_021E96A8(void *p);
u32 ov14_021E98AC(void *p);
u32 ov14_021E9920(void *p);
u32 ov14_021E9970(void *p);
u32 ov14_021E99A0(void *p);
u32 ov14_021E99F0(void *p);
u32 ov14_021EAF8C(void *p, u32 *state);

u32 ov14_021EB170(void *p);
u32 ov14_021EA068(void *p);
u32 ov14_021EA130(void *p);
u32 ov14_021EA728(void *p);
void ov14_021EA1F0(void *p);
u32 ov14_021EA0B8(void *p);
u32 ov14_021EA180(void *p);
u32 ov14_021EA378(void *p);
u32 ov14_021EAF08(void *p);
u32 ov14_021EB0E4(void *p);
u32 ov14_021EA674(void *p);

u32 ov14_021EA408(void *p);
u32 ov14_021EAC24(void *p);
u32 ov14_021EAB54(void *p);

u32 ov14_021EB0E4(void *p) {
    ov14_021E6048(p);
    SysTask_Destroy(PTR_AT(PTR_AT(p, 0x34), 0));
    ov14_021F6B10(p);
    ov14_021E5EE8(p);
    ov14_021E7D7C(PTR_AT(p, 0x34));
    ov14_021F29AC(PTR_AT(p, 0x34));
    ov14_021F4F00(p);
    ov14_021E5DB8(p);
    ov14_021E5E94(p);
    ov14_021E5C00(p);
    NARC_Delete(PTR_AT(PTR_AT(p, 0x34), 0x454));
    NARC_Delete(PTR_AT(PTR_AT(p, 0x34), 0x450));
    sub_02021238();
    *(volatile u16 *)0x04000050 = 0;
    *(volatile u16 *)0x04001050 = 0;
    GfGfx_EngineASetPlanes(0);
    GfGfx_EngineBSetPlanes(0);
    Heap_Free(PTR_AT(p, 0x34));
    Heap_Destroy(0xa);
    return U32_AT(p, 0x30);
}

u32 ov14_021EB170(void *p) {
    if (IsPaletteFadeFinished() == 1) {
        return U32_AT(PTR_AT(p, 0x34), 0x440);
    }
    return 2;
}
