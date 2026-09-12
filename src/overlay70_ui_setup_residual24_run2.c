#include "overlay70_ui_setup_residual24_private.h"

void ov70_0223EBD4(Ov70Work24 *work) {
    int i;
    u8 *window;
    RemoveWindow((u8 *)work + 0x1198);
    window = &work->windows1058[0][0];
    for (i = 0; i < 6; i++) {
        RemoveWindow(window);
        window += 0x10;
    }
    RemoveWindow(work->windowF18);
}

void ov70_0223EC0C(Ov70Work24 *work) {
    Ov70SpriteTemplate24 template;

    ov70_02238B54(&template, work, (u8 *)work + 0xD60, 1);
    template.x = 0xA0000;
    template.y = 0x20000;
    work->spriteDD0 = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(work->spriteDD0, 0x2F);
    Sprite_SetDrawFlag(work->spriteDD0, 0);

    template.x = 0xE4000;
    template.y = 0x75000;
    work->spriteF04 = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(work->spriteF04, 0x26);
    Sprite_SetDrawFlag(work->spriteF04, 0);

    template.x = 0x8C000;
    work->spriteF08 = Sprite_CreateAffine(&template);
    Sprite_SetAnimCtrlSeq(work->spriteF08, 0x27);
    Sprite_SetDrawFlag(work->spriteF08, 0);
}
