#include "overlay102_window_sprites_r36_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))

void ov102_021EBD68(void *state);

void *ov102_021EBC34(void *work, void *args, void *fieldSystem) {
    u8 *state = Heap_Alloc(0x23, 0x98);

    PTR(state, 0) = work;
    PTR(state, 4) = args;
    PTR(state, 8) = fieldSystem;
    PTR(state, 0xC) = ov102_021EA268(work);
    PTR(state, 0x3C) = String_New(0x20, 0x23);
    AddWindowParameterized(PTR(state, 0xC), state + 0x10, 2, 4, 0, 0x1A, 0x20, 0xC, 1);
    AddWindowParameterized(PTR(state, 0xC), state + 0x20, 2, 0, 0, 0xC, 4, 0xC, 1);
    PTR(state, 0x30) = NULL;
    PTR(state, 0x34) = NULL;
    PTR(state, 0x38) = NULL;
    PTR(state, 0x94) = ov102_021E8F68(PTR(state, 4));
    return state;
}

void ov102_021EBCBC(void *arg) {
    u8 *state = arg;

    if (PTR(state, 0x30) != NULL) {
        Sprite_Delete(PTR(state, 0x30));
    }
    if (PTR(state, 0x34) != NULL) {
        Sprite_Delete(PTR(state, 0x34));
    }
    if (PTR(state, 0x38) != NULL) {
        Sprite_Delete(PTR(state, 0x38));
    }
    if (PTR(state, 0x3C) != NULL) {
        String_Delete(PTR(state, 0x3C));
    }
    RemoveWindow(state + 0x20);
    RemoveWindow(state + 0x10);
    Heap_Free(state);
}

void ov102_021EBD00(void *arg) {
    u8 *state = arg;
    void *bg = ov102_021EA268(PTR(state, 0));

    BG_ClearCharDataRange(2, 0x20, 0, 0x23);
    FillBgTilemapRect(bg, 2, 0, 0, 0, 0x20, 0x20, 0xC);
    FillWindowPixelBuffer(state + 0x10, 0);
    PutWindowTilemap(state + 0x10);
    CopyWindowPixelsToVram_TextMode(state + 0x10);
    BgCommitTilemapBufferToVram(bg, 2);
    ov102_021EBD68(state);
    ToggleBgLayer(2, 0);
}

void ov102_021EBD68(void *arg) {
    u8 resource[0x24];
    u8 *state = arg;

    ov102_021EA270(PTR(state, 0), resource, 0, 0);
    PTR(state, 0x30) = ov102_021EA2B4(PTR(state, 0), resource, 0x48, 0x38, 3, 1);
    Sprite_SetAnimCtrlSeq(PTR(state, 0x30), 8);
    Sprite_SetDrawFlag(PTR(state, 0x30), 0);
    PTR(state, 0x34) = ov102_021EA2B4(PTR(state, 0), resource, 0xF0, 0x50, 4, 1);
    Sprite_SetAnimCtrlSeq(PTR(state, 0x34), 0x18);
    Sprite_SetDrawFlag(PTR(state, 0x34), 0);
    PTR(state, 0x38) = ov102_021EA2B4(PTR(state, 0), resource, 0xF0, 0x80, 4, 1);
    Sprite_SetAnimCtrlSeq(PTR(state, 0x38), 0x1A);
    Sprite_SetDrawFlag(PTR(state, 0x38), 0);
}

void ov102_021EBDEC(void *arg) {
    u8 *state = arg;
    u32 count;
    u8 *entry;
    u32 i;

    FillWindowPixelBuffer(state + 0x10, 0);
    ov102_021EC11C(state);
    count = ov102_021E8FD8(PTR(state, 4));
    if (count > 10) {
        count = 10;
    }
    entry = PTR(state, 0x8C);
    for (i = 0; i < count; i++) {
        ov102_021EC13C(state, i, entry);
        if (i & 1) {
            entry += 0x18;
        }
    }
    CopyWindowPixelsToVram_TextMode(state + 0x10);
}

int ov102_021EBE3C(void *arg) {
    u8 *state = arg;

    G2x_SetBlendAlpha_(0x04000050, 4, 0x3F, 0, 0x10);
    ToggleBgLayer(2, 1);
    U32(state, 0x80) = 0;
    return ov102_021EC37C(state + 0x40, 4, 0x3F, 0, 0x7C, 0xC);
}
