#include "to46_overlay15_gap11_private.h"

void ov15_021FFDD8(BagWorkRaw *work) {
    const ManagedSpriteTemplate *template = ov15_02200B0C;
    u32 i;
    BagWorkRaw *walker;
    i = 0;
    walker = work;
    for (; i < 0x27; i++) {
        *(ManagedSprite **)&walker->raw[0x250] = SpriteSystem_NewSpriteWithYOffset(*(SpriteSystem **)&work->raw[0x248], *(SpriteManager **)&work->raw[0x24C], template, 1 << 20);
        template++;
        walker = (BagWorkRaw *)((u8 *)walker + 4);
    }
    ManagedSprite_SetPriority(*(ManagedSprite **)&work->raw[0x29C], 1);
    {
        BagWorkRaw *p;
        u32 j;
        j = 0;
        p = work;
        for (; j < 4; j++) {
            ManagedSprite_SetPriority(*(ManagedSprite **)&p->raw[0x2C0], 1);
            p = (BagWorkRaw *)((u8 *)p + 4);
        }
    }
    {
        BagWorkRaw *p;
        u32 j;
        j = 0;
        p = work;
        for (; j < 8; j++) {
            ManagedSprite_SetPriority(*(ManagedSprite **)&p->raw[0x274], 1);
            p = (BagWorkRaw *)((u8 *)p + 4);
        }
    }
    ov15_02200458(work, TRUE);
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x250], FALSE);
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x26C], FALSE);
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x270], FALSE);
    {
        BagWorkRaw *p;
        u32 j;
        j = 0;
        p = work;
        for (; j < 4; j++) {
            ManagedSprite_SetDrawFlag(*(ManagedSprite **)&p->raw[0x2C0], FALSE);
            p = (BagWorkRaw *)((u8 *)p + 4);
        }
    }
    {
        BagWorkRaw *p;
        u32 j;
        j = 0;
        p = work;
        for (; j < 6; j++) {
            ManagedSprite_SetDrawFlag(*(ManagedSprite **)&p->raw[0x2D0], FALSE);
            p = (BagWorkRaw *)((u8 *)p + 4);
        }
    }
    ManagedSprite_SetDrawFlag(*(ManagedSprite **)&work->raw[0x2E8], FALSE);
    ManagedSprite_SetPriority(*(ManagedSprite **)&work->raw[0x2E8], 1);
}
