#include "to46_overlay59_move_gap2_private.h"

void ov59_0223BE44(u8 *owner, int index, u8 sequence, int draw) {
    u32 offset;
    u8 *sprites;

    index += 8;
    offset = index * 4;
    sprites = owner + 0x260;
    Sprite_SetDrawFlag(PTR(sprites, offset), draw);
    if (sequence != 0xff) {
        Sprite_SetAnimCtrlSeq(PTR(sprites, offset), sequence);
        Sprite_ResetAnimCtrlState(PTR(sprites, offset));
    }
}

void ov59_0223BE70(u8 *owner, int row, int direction) {
    Ov59MoveTask *task = Heap_Alloc((enum HeapID) * (u32 *)owner, sizeof(Ov59MoveTask));
    u8 base;
    u8 spriteIndex;
    f32 rounded;
    MI_CpuFill8(task, 0, sizeof(Ov59MoveTask));
    task->owner = owner;
    task->direction = direction;
    task->frames = 30;
    base = (*(u16 *)(owner + 0x2e) >> (row * 3)) & 7;
    if (direction == 0) {
        spriteIndex = base + owner[0x38] + 1;
        task->scale.x = 0x19a;
        task->scale.y = 0x19a;
        task->scale.z = 0;
        if (task->frames != 0) {
            rounded = (f32)(task->frames << 12) + 0.5f;
        } else {
            rounded = (f32)(task->frames << 12) - 0.5f;
        }
        task->step = FX_Div(FX32_ONE, (fx32)rounded);
        task->y = 12;
        task->x = 0;
    } else {
        spriteIndex = base - owner[0x38];
        task->scale.x = 0x119a;
        task->scale.y = 0x119a;
        task->scale.z = FX32_ONE;
        if (task->frames != 0) {
            rounded = (f32)(task->frames << 12) + 0.5f;
        } else {
            rounded = (f32)(task->frames << 12) - 0.5f;
        }
        task->step = -FX_Div(FX32_ONE, (fx32)rounded);
        task->y -= 12;
        task->x = 360;
    }
    spriteIndex += row * 5;
    task->sprite = PTR(owner + 0x260, (spriteIndex + 8) * 4);
    Sprite_SetAffineScale(task->sprite, &task->scale);
    ov59_0223BE44(owner, spriteIndex, *(owner + row + 0x30) + 4, 1);
    SysTask_CreateOnMainQueue(ov59_0223BFC8, task, 0);
    owner[0x4f]++;
    owner[0x38]++;
}
