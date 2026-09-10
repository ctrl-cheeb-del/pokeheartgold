#include "overlay_98_helpers_internal.h"

void ov98_0221E784(SpriteSystem *system, SpriteManager *manager, const int *resourceIds, int vram) {
    SpriteSystem_LoadCharResObj(system, manager, (NarcId)8, 76, FALSE, vram, resourceIds[0]);
    SpriteSystem_LoadPlttResObj(system, manager, (NarcId)8, 75, FALSE, 1, vram, resourceIds[1]);
    SpriteSystem_LoadCellResObj(system, manager, (NarcId)8, 77, FALSE, resourceIds[2]);
    SpriteSystem_LoadAnimResObj(system, manager, (NarcId)8, 78, FALSE, resourceIds[3]);
}
