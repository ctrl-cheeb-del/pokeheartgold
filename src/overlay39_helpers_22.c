#include "overlay39_helpers_internal.h"

u32 ov39_02228EA4(Ov39App *app) {
    int res = ov00_021E6A70(-app->unk18, app->unk1C);
    ov39_02228A34(app, res, -app->unk18);
    app->unk08 = 7;
    return 0;
}
