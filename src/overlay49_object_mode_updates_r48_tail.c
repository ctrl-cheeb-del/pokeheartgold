#include "overlay49_object_mode_updates_r48_tail_private.h"

void ov49_0225E714(Ov49R48 *d)
{
    s32 i;
    for (i = 0; i < d->countB; i++) {
        switch (ov49_0225D1C0(d->objects[i])) {
        case 1: case 2: case 3: case 4:
            ov49_0225D4A0(d->owner, d->objects[i], 1);
            break;
        }
    }
}

void ov49_0225E760(Ov49R48 *d, u32 mode)
{
    s32 i;
    for (i = 0; i < d->countB; i++) {
        u32 type = ov49_0225D1C0(d->objects[i]);
        switch (type) {
        case 0xb:
        case 0xc:
            switch (mode) {
            case 0:
                ov49_0225D214(d->owner, d->objects[i], 0, 2);
                U32_AT(d, 0x244) = 0;
                break;
            case 1:
                ov49_0225D224(d->owner, d->objects[i], 0, 1, ov49_0225EA10);
                U32_AT(d, 0x244) = 1;
                break;
            case 2:
                ov49_0225D224(d->owner, d->objects[i], 0, 4, ov49_0225EA40);
                ov49_0225D328(d->owner, d->objects[i], 1);
                U32_AT(d, 0x244) = 0;
                break;
            case 3:
                ov49_0225D214(d->owner, d->objects[i], 1, 0);
                ov49_0225D328(d->owner, d->objects[i], 0);
                U32_AT(d, 0x244) = 1;
                break;
            }
            break;
        }
    }
}
