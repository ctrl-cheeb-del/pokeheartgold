#include "overlay27_menu_setup_r7_private.h"

void ov27_0225AA7C(Ov27WorkR7 *work) {
    u32 flagOffset = 0x514;
    int i = 0;
    u8 *walker = (u8 *)work;

    while (i < 7) {
        Sprite_SetDrawFlag(*(Sprite **)(walker + 0x390), work->raw[flagOffset + i]);
        i++;
        walker += 4;
    }
    work->raw[0x50C] = 1;
    if (!ov27_0225BDC8(work)) {
        Sprite_SetDrawFlag(*(Sprite **)&work->raw[0x3BC], 0);
        Sprite_SetDrawFlag(*(Sprite **)&work->raw[0x3C4], 0);
        work->raw[0x50C] = 0;
    }
}

void ov27_0225AAD4(Ov27WorkR7 *work) {
    Window *windows;
    register Window *computedWindows;
    int count;
    int oldCount;
    const Ov27IconEntryR7 *entry;
    int i;
    u8 *state;

    oldCount = ov27_0225AA60(&work->raw[0x514], 7);
    count = oldCount;
    computedWindows = (Window *)&work->raw[0x3F0];
    entry = ov27_0225CF10;
    i = 0;
    state = (u8 *)work;
    windows = computedWindows;

    while (i < 7) {
        if (FieldSystem_ShouldDrawStartMenuIcon(*(void **)&work->raw[0x10], i) == 1 && work->raw[0x514 + i] == 0) {
            Sprite_SetDrawFlag(((Sprite **)&work->raw[0x390])[entry->sprite], 1);
            Sprite_SetAnimCtrlSeq(((Sprite **)&work->raw[0x390])[entry->sprite], entry->anim);
            CopyWindowToVram(&windows[entry->window]);
            work->raw[0x514 + i] = 1;
            state[0x470] = 1;
            ((u8 *)*(void **)&work->raw[0x10])[0xD2] |= 0x80;
            count++;
        }
        i++;
        entry++;
        state += 8;
    }

    if (count != 0 && oldCount == 0) {
        Sprite_SetDrawFlag(*(Sprite **)&work->raw[0x3C8], 1);
        CopyWindowToVram((Window *)&work->raw[0x3E0]);
    }

    if (oldCount != count) {
        ((u8 *)*(void **)&work->raw[0x10])[0xD3] = 0;
        *(int *)&work->raw[0x14] = ov27_0225C1AC(work, ((u8 *)*(void **)&work->raw[0x10])[0xD3]);
        ov27_0225C1EC(work);
    }

    if (ov27_0225BDC8(work) == 1 && work->raw[0x50C] == 0) {
        Sprite_SetDrawFlag(*(Sprite **)&work->raw[0x3BC], 1);
        Sprite_SetDrawFlag(*(Sprite **)&work->raw[0x3C4], 1);
        Sprite_SetAnimCtrlSeq(*(Sprite **)&work->raw[0x3BC], 10);
        work->raw[0x50C] = 1;
    }
}

void ov27_0225AC00(void *bg, int variant, Window *top, Window *bottom, Window *icons) {
    int i;
    int baseTile;
    const Ov27WindowPosR7 *pos;
    Window *icon;

    GfGfxLoader_LoadCharData(14, ov27_0225CEF0[variant].member, bg, 4, 0, 0, 1, 8);
    GfGfxLoader_LoadScrnData(14, ov27_0225CEF4[variant].member, bg, 4, 0, 0, 1, 8);
    GfGfxLoader_GXLoadPal(14, ov27_0225CEEC[variant].member, 4, 0, 0x200, 8);

    AddWindowParameterized(bg, top, 5, 24, 20, 8, 2, 4, 0xD2);
    FillWindowPixelBuffer(top, 0);
    AddWindowParameterized(bg, bottom, 5, 9, 0, 10, 2, 4, 0xE2);
    FillWindowPixelBuffer(bottom, 0);

    pos = ov27_0225D074;
    icon = icons;
    i = 0;
    baseTile = 0xF6;
    while (i < 8) {
        AddWindowParameterized(bg, icon, 5, (u8)pos->x, (u8)pos->y, 9, 2, 4, (u16)baseTile);
        FillWindowPixelBuffer(icon, 0);
        i++;
        baseTile += 0x12;
        pos++;
        icon++;
    }
}

void ov27_0225AD0C(Ov27WorkR7 *work) {
    int i;
    u8 *resource;
    void *allocation;
    Ov27PaletteDataR7 *palette;

    *(void **)&work->raw[0x18] = G2dRenderer_Init(16, &work->raw[0x1C], 8);
    G2dRenderer_SetSubSurfaceCoords(&work->raw[0x1C], 0, 1 << 20);

    i = 0;
    while (i < 4) {
        ((Ov27WorkManagersR7 *)work)->managers[i] = Create2DGfxResObjMan(11, i, 8);
        i++;
    }

    i = 0;
    resource = &work->raw[0x154];
    while (i < 11) {
        int gender = PlayerProfile_GetTrainerGender(Save_PlayerData_GetProfile(*(void **)((u8 *)*(void **)&work->raw[0x10] + 0xC)));
        void *bag = Save_Bag_Get(*(void **)((u8 *)*(void **)&work->raw[0x10] + 0xC));
        ov27_0225AEA8(*(void **)&work->raw[0x10], (void **)&work->raw[0x144], resource, i, i + 100, gender, bag, (*(u32 *)&work->raw[0x51C] << 27) >> 28);
        i++;
        resource += 0x10;
    }

    *(void **)&work->raw[0x15C] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x14C], 14, 16, 1, 100, 2, 8);
    *(void **)&work->raw[0x160] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x150], 14, 17, 1, 100, 3, 8);
    *(void **)&work->raw[0x16C] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x14C], 14, 0x44, 1, 101, 2, 8);
    *(void **)&work->raw[0x170] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x150], 14, 0x45, 1, 101, 3, 8);
    *(void **)&work->raw[0x17C] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x14C], 14, 0x36, 1, 102, 2, 8);
    *(void **)&work->raw[0x180] = AddCellOrAnimResObjFromNarc(*(void **)&work->raw[0x150], 14, 0x37, 1, 102, 3, 8);

    allocation = GfGfxLoader_GetPlttData(14, 14, &palette, 8);
    DC_FlushRange(palette->raw, 0x40);
    MIi_CpuCopyFast(palette->raw, (u32 *)&work->raw[0x4CC], 0x40);
    Heap_Free(allocation);
}
