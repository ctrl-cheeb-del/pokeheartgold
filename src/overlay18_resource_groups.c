#include "overlay18_resource_groups_private.h"
#define PTR(p, o)    (*(void **)((u8 *)(p) + (o)))
#define U32_AT(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov18_021F8FA0(void *p) {
    PTR(p, 0xB4) = G2dRenderer_Init(0x20, (u8 *)p + 0xB8, *(int *)((u8 *)p + 0x14));
    ClearMainOAM(*(int *)((u8 *)p + 0x14));
    ov18_021F8F28(p);
    ov18_021F8F60(p);
    ov18_021F8FF8(p);
    ov18_021F9068(p);
    ov18_021F9150(p);
    ov18_021F94BC(p);
    ov18_021F9370(p);
    ov18_021F9518(p);
    GfGfx_EngineBTogglePlanes(0x10, 1);
}

void ov18_021F8FF8(void *p) {
    ov18_021F922C((u8 *)p + 0x1F4, (u8 *)p + 0x1E0, *(u32 *)((u8 *)p + 0x14), *(void **)((u8 *)p + 0x1C), 0x1D, 0x20, 0x1E, 0x1F, 2, 0xC618, 0xC618, 0xC618, 0xC618);
    PaletteData_LoadPaletteSlotFromHardware(PTR(p, 4), 2, SpriteTransfer_GetPlttOffset(PTR(p, 0x1F8), 1) << 4, 0x40);
}

void ov18_021F9054(void *p) {
    ov18_021F92DC((u8 *)p + 0x1F4, (u8 *)p + 0x1E0);
}

void ov18_021F9068(void *p) {
    ov18_021F922C((u8 *)p + 0x208, (u8 *)p + 0x1E0, *(u32 *)((u8 *)p + 0x14), *(void **)((u8 *)p + 0x1C), ov18_021F967C(U32_AT(p, 0x24C)), 0x23, 0x21, 0x22, 4, 0xC619, 0xC619, 0xC619, 0xC619);
    ov18_021F922C((u8 *)p + 0x21C, (u8 *)p + 0x1E0, *(u32 *)((u8 *)p + 0x14), *(void **)((u8 *)p + 0x1C), ov18_021F967C(U32_AT(p, 0x250)), -1, 0x21, 0x22, 4, 0xC61A, 0xC61A, 0xC61A, 0xC61A);
    PaletteData_LoadPaletteSlotFromHardware(PTR(p, 4), 2, SpriteTransfer_GetPlttOffset(PTR(p, 0x20C), 1) << 4, 0x80);
}

void ov18_021F9108(void *p) {
    ov18_021F92DC((u8 *)p + 0x208, (u8 *)p + 0x1E0);
    SpriteTransfer_DeleteCharTransferTask(PTR(p, 0x21C));
    DestroySingle2DGfxResObj(PTR(p, 0x1E0), PTR(p, 0x21C));
    DestroySingle2DGfxResObj(PTR(p, 0x1E8), PTR(p, 0x224));
    DestroySingle2DGfxResObj(PTR(p, 0x1EC), PTR(p, 0x228));
}

void ov18_021F9150(void *p) {
    void *narc = NARC_New(ov18_021E5900(), *(u32 *)((u8 *)p + 0x14));
    ov18_021F922C((u8 *)p + 0x230, (u8 *)p + 0x1E0, *(u32 *)((u8 *)p + 0x14), *(void **)((u8 *)p + 0x1C), 0x4D, -1, 0x4E, 0x4F, 1, 0xC61B, 0xC61B, 0xC61B, 0xC61B);
    PTR(p, 0x234) = ov18_021F92AC(PTR(p, 0x1E4), *(u32 *)((u8 *)p + 0x14), narc, ov18_021E5908(), 1, 0xC61B);
    PaletteData_LoadPaletteSlotFromHardware(PTR(p, 4), 2, SpriteTransfer_GetPlttOffset(PTR(p, 0x234), 1) << 4, 0x20);
    NARC_Delete(narc);
}

void ov18_021F91DC(void *p) {
    ov18_021F92DC((u8 *)p + 0x230, (u8 *)p + 0x1E0);
}
