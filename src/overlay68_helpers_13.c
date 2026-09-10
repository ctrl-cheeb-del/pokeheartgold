#include "overlay68_helpers_internal.h"

void ov68_021E7388(Ov68Pokepic *p) {
    Camera_Delete(p->camera);
    PokepicManager_Delete(p->pokepicMan);
    MI_CpuFill8(p, 0, sizeof(Ov68Pokepic));
}
