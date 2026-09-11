#include "heap.h"
#include "math_util.h"
#include "overlay96_sprite_internal.h"

void ov96_021FC214(u8 *work, int arg) {
    ov96_021FC320(work);
    ov96_021FC404(work);
    ov96_021FC450(work, arg);
    G2dRenderer_SetSubSurfaceCoords(work + 8, 0, 0);
    G2dRenderer_SetMainSurfaceCoords(work + 8, 0, 3 << 18);
}

void ov96_021FC248(u8 *raw, int index, int scale) {
    SpriteWork *work = (SpriteWork *)raw;
    VecFx32 matrix;
    matrix.z = 0;
    matrix.x = scale << 12;
    matrix.y = 14 << 12;
    Sprite_SetMatrix(work->sprites[index].a, &matrix);
    Sprite_SetMatrix(work->sprites[index].b, &matrix);
    Sprite_SetMatrix(work->sprites[index].c, &matrix);
}
