#include "sol_r9_ov18_gap05_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov18_021EE75C(void *work, u32 species, u32 index) {
    u8 *windowBase = (u8 *)work + 0xc;
    u32 offset = index << 4;

    FillWindowPixelBuffer(windowBase + offset, 0);
    if (species != 0) {
        u32 dexNo = Pokedex_ConvertToCurrentDexNo(*((u8 *)work + 0x1858), species);
        BufferIntegerAsString(PTR(work, 0x660), 0, dexNo, 3, 2, 1);
        ov18_021EE3AC(work, PTR(work, 0x65c), index, 9, 1, 0, 4, 0x20100, 0);
        ScheduleWindowCopyToVram(windowBase + offset);
    } else {
        ClearWindowTilemapAndScheduleTransfer(windowBase + offset);
    }
}

void ov18_021EE7DC(void *work, u32 species, u32 index) {
    u8 *windowBase = work;
    u32 offset = index << 4;
    windowBase += 0xc;

    FillWindowPixelBuffer(windowBase + offset, 0);
    if (species != 0) {
        void *string = ov18_021E590C(species, 2, 0x25);
        ov18_021F95FC(windowBase + offset, string, 0, 0, 4, 0x20100, 0);
        String_Delete(string);
        ScheduleWindowCopyToVram(windowBase + offset);
    } else {
        ClearWindowTilemapAndScheduleTransfer(windowBase + offset);
    }
}

void ov18_021EE834(void *work, u32 species, u32 slot, u32 index) {
    u8 *windowBase = work;
    u32 offset = index << 4;
    windowBase += 0xc;

    FillWindowPixelBuffer(windowBase + offset, 0);
    if (species != 0) {
        void *string;
        if (*(u16 *)((u8 *)work + slot * 4 + 0x1032) == 2) {
            string = ov18_021E595C(species, 2, 0x25);
        } else {
            string = ov18_021E595C(0, 2, 0x25);
        }
        s32 x = (GetWindowWidth(windowBase + offset) << 3) - 4;
        ov18_021F95FC(windowBase + offset, string, x, 0, 4, 0x20100, 1);
        String_Delete(string);
        ScheduleWindowCopyToVram(windowBase + offset);
    } else {
        ClearWindowTilemapAndScheduleTransfer(windowBase + offset);
    }
}

void ov18_021EE984(void *work, u32 species, u32 slot, u32 index);

void ov18_021EE8B8(To47Work18 *work, u32 species, u32 slot) {
    ClearWindowTilemapAndScheduleTransfer(&work->windows[12]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[14]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[11]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[13]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[15]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[16]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[17]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[18]);
    ClearWindowTilemapAndScheduleTransfer(&work->windows[19]);

    if (species != 0) {
        ov18_021EE984(work, species, slot, 0xb);
        if (work->language == 2) {
            ov18_021EE9FC(work, 0xc);
            ov18_021EEA40(work, 0xe);
            ov18_021EEAE4(work, species, slot, 0xd);
            ov18_021EEB94(work, species, slot, 0xf);
        } else {
            ov18_021EEBE4(work, 0x10);
            ov18_021EEC34(work, species, 0x11, work->language);
            ov18_021EECB0(work, species, 0x12);
            ov18_021EED00(work, species, slot, 0x13);
        }
    }
}

void ov18_021EE984(void *work, u32 species, u32 slot, u32 index) {
    if (*(u16 *)((u8 *)work + slot * 4 + 0x1032) == 2) {
        u8 *windowBase = (u8 *)work + 0xc;
        u32 offset = index << 4;
        void *string;
        u32 width;

        FillWindowPixelBuffer(windowBase + offset, 0);
        string = ov18_021E59A8(species, *((u8 *)work + 0x185c), 0, 0x25);
        width = GetWindowWidth(windowBase + offset);
        {
            u32 stringWidth = FontID_String_GetWidthMultiline(0, string, 0);
            width = ((width << 3) - stringWidth) >> 1;
        }
        ov18_021F95FC(windowBase + offset, string, width, 0, 0, 0x20100, 0);
        String_Delete(string);
        ScheduleWindowCopyToVram(windowBase + offset);
    }
}
