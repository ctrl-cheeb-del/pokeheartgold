#include "overlay102_ui_layout_r20_private.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov102_021EA270(u8 *base, u8 *out, u32 index, u8 value) {
    PTR(out, 0) = base + 0x150 + index * 0x24;
    PTR(out, 8) = base + 0x198 + index * 0x14;
    PTR(out, 0xC) = PTR(base, 0x1C0 + index * 4);
    PTR(out, 0x10) = PTR(base, 0x1C8 + index * 4);
    U8(out, 0x20) = value;
    U32(out, 4) = 0;
    U32(out, 0x14) = 0;
    U32(out, 0x18) = 0;
    U32(out, 0x1C) = 0;
}

void *ov102_021EA2B4(u8 *base, void *list, s32 x, s32 y, u32 anim, u32 kind) {
    struct {
        void *resource;
        void *list;
        fx32 x;
        fx32 y;
        fx32 z;
        u32 anim;
        u32 kind;
        u32 heapId;
    } template;
    OSIntrMode irq;
    void *sprite;

    template.resource = PTR(base, 0x24);
    template.list = list;
    template.x = x << FX32_SHIFT;
    template.y = y << FX32_SHIFT;
    template.z = 0;
    template.anim = anim;
    template.kind = kind;
    template.heapId = 0x23;
    if (kind == 2) {
        template.y += 3 << 18;
    }
    irq = OS_DisableInterrupts();
    sprite = Sprite_Create(&template);
    OS_RestoreInterrupts(irq);
    if (sprite != NULL) {
        Sprite_SetAnimActiveFlag(sprite, TRUE);
        Sprite_SetAnimSpeed(sprite, FX32_ONE);
    }
    return sprite;
}
