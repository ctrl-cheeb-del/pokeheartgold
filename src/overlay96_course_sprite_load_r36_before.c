#include "overlay96_course_sprite_load_r36_before_private.h"

void ov96_021EC82C(void *course) {
    Ov96R36Work *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    void *sys = work->spriteSystem;
    void *mgr = work->spriteManager;
    u8 i;
    u8 value;

    for (i = 0; i < 5; i++) {
        SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, 9, 1, 2, 0x64 + i);
        SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, 8, 0, 1, 2, 0x64 + i);
    }
    SpriteSystem_LoadCellResObj(sys, mgr, 0x9a, 0xa, 1, 0x64);
    SpriteSystem_LoadAnimResObj(sys, mgr, 0x9a, 0xb, 1, 0x64);
    SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, 0xd, 1, 2, 0x69);
    SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, 0xc, 0, 5, 2, 0x69);
    SpriteSystem_LoadCellResObj(sys, mgr, 0x9a, 0xe, 1, 0x65);
    SpriteSystem_LoadAnimResObj(sys, mgr, 0x9a, 0xf, 1, 0x65);
    ov96_021ECA18(work);
    SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, 0x10, 1, 1, 0x6a);
    SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, 0xc, 0, 1, 1, 0x6a);
    SpriteSystem_LoadCellResObj(sys, mgr, 0x9a, 0x11, 1, 0x66);
    SpriteSystem_LoadAnimResObj(sys, mgr, 0x9a, 0x12, 1, 0x66);
    value = *((u8 *)work + 0xb1);
    SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, ov96_021EDC38(value, 0) + 0x17, 0, 1, 1, 0x6b);
    SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, ov96_021EDC38(value, 1) + 0x17, 0, 1, 1, 0x6c);
    SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, ov96_021EDC38(value, 0) + 0x1c, 1, 1, 0x6b);
    SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, ov96_021EDC38(value, 1) + 0x1c, 1, 1, 0x6c);
    SpriteSystem_LoadCellResObj(sys, mgr, 0x9a, 0x21, 1, 0x67);
    SpriteSystem_LoadAnimResObj(sys, mgr, 0x9a, 0x22, 1, 0x67);
}
