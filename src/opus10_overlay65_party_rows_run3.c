#include "opus10_overlay65_party_rows_private.h"

void ov65_0221D674(void *windows, int side, void *party, int index, void *work);
void ov65_0221D8C4(void *windows, int side, void *work);
void ov65_0221D930(void *work);
void ov65_0221DBF4(void *p);
void ov65_0221DC34(void *work);
int ov65_0221DCFC(int idx, int dir, void *summaries);
void ov65_0221DD34(int idx, void *sprite, int form);
int ov65_0221DDC0(void *input, void *state, void *sprite, void *summaries, int side);

void ov65_0221DCBC(void *state) {
    u16 color;

    U16(state, 0) += 0x14;
    if (U16(state, 0) > 360) {
        U16(state, 0) = 0;
    }
    color = (u16)(((GF_SinDeg(U16(state, 0)) * 10 / FX32_ONE) + 0xf) * 32 | 0x1d);
    GX_LoadOBJPltt(&color, 0x3a, 2);
}
