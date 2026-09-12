#include "overlay96_results_ui_r49_private.h"

void ov96_021EF8C0(Ov96ResultsUiR49 *work) {
    void *system = work->spriteSystem;
    void *manager = work->spriteManager;

    SpriteSystem_LoadPlttResObjFromOpenNarc(system, manager, work->narc, 0, 0, 0x10, 1, 0);
    SpriteSystem_LoadCharResObjFromOpenNarc(system, manager, work->narc, 1, 1, 1, 0);
    SpriteSystem_LoadCellResObjFromOpenNarc(system, manager, work->narc, 2, 1, 0);
    SpriteSystem_LoadAnimResObjFromOpenNarc(system, manager, work->narc, 3, 1, 0);
}
