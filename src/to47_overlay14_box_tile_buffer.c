#include "to47_overlay14_box_tile_buffer_private.h"

typedef union BoxTilePtrSlot {
    void *ptr;
    u32 raw;
} BoxTilePtrSlot;

void ov14_021F4A64(void *p, u32 box, void *dst);

void ov14_021F4A64(void *p, u32 box, void *dst) {
    BoxTilePtrSlot mon;
    u32 lock;
    u8 row;
    u8 col;
    u8 x;
    u32 rowbase;
    u32 y;
    u16 tile;
    u32 yy;
    u32 type;
    u32 species;
    u16 form;

    tile = 0xb;
    y = (u8)tile;
    for (row = 0; row < 5; row++) {
        x = 0xa;
        col = 0;
        rowbase = row * 6;
        for (; col < 6; col++) {
            mon.ptr = PCStorage_GetMonByIndexPair(PTR_AT(p, 4), box, col + rowbase);
            lock = AcquireBoxMonLock(mon.ptr);
            species = GetBoxMonData((void *)mon.raw, 5, NULL);
            if (GetBoxMonData(mon.ptr, 0xac, NULL)) {
                if (!GetBoxMonData((void *)mon.raw, 0x4c, NULL)) {
                    form = (u16)GetBoxMonData(mon.ptr, 0x70, NULL);
                    type = (u16)GetMonBaseStatEx_HandleAlternateForm(PTR_AT(PTR_AT(p, 0x34), 0x450), species, form, 0x1b);
                } else if (species == 0x1ea) {
                    type = 1;
                } else {
                    type = 8;
                }
                tile = (u16)(ov14_021F8080[type] + 0x20);
                tile = (u16)((tile << 8) | tile);
                for (yy = y; (s32)yy < (s32)(y + 2); yy = (u8)(yy + 1)) {
                    MIi_CpuClear16(tile, (u16 *)((u8 *)dst + ((x & 7) + ((yy & 7) * 8 + (u32)((u8 *)(((s32)yy >> 3) * 4) + (x >> 3)) * 64))), 2);
                }
            }
            ReleaseBoxMonLock((void *)mon.raw, lock);
            x += 2;
        }
        y = (u8)(y + 2);
    }
}
