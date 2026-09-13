#include "global.h"

#include "r40_overlay_103_residual_5_private.h"
#define PTR(c, o) (*(void **)((c) + (o)))

void ov103_021ECF68(R40Ov103Work5 *work) {
    TouchscreenListMenuHeader header;
    TouchscreenListMenuTemplate template = _021EEB34;
    header.template = template;
    header.listMenuItems = PTR(work->ctx, 0x248);
    header.bgConfig = PTR(work->ctx, 0);
    header.numWindows = ov103_021ED2B8(work);
    if (header.numWindows == 4) {
        PTR(work->ctx, 0x244) = TouchscreenListMenu_Create((TouchscreenListMenuSpawner *)PTR(work->ctx, 0x240), &header, 0, 0x12, 5, 0xB, 0);
    } else {
        PTR(work->ctx, 0x244) = TouchscreenListMenu_Create((TouchscreenListMenuSpawner *)PTR(work->ctx, 0x240), &header, 0, 0x12, 0xB, 0xB, 0);
    }
}
