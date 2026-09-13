#include "r40_overlay_89_residual_13_private.h"

void ov89_0225C93C(u32 value, u32 unused1, u32 unused2, u8 *context) {
    void *lookup = ov89_02259E48(context);

    if (ov89_0225C8F0(value, lookup)) {
        ov89_0225A148(context, value);
    }
}

void ov89_0225C960(u32 value, u32 unused1, u32 unused2, u8 *context) {
    void *lookup = ov89_02259E48(context);

    if (ov89_0225C8F0(value, lookup)) {
        ov89_0225A160(context, ov45_0222EC7C(value));
    }
}

void ov89_0225C988(u32 value, u32 state, u32 unused, u8 *context) {
    void *result = ov89_02259E48(context);

    if (ov89_0225C8F0(value, result)) {
        ov89_02259EC4(context, state, value);
    }
}
