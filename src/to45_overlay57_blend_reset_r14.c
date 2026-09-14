#include "global.h"

void G2x_SetBlendAlpha_(u32 reg, int plane1, int plane2, int eva, int evb);
void ov57_0223BB5C(void);

void ov57_0223BB5C(void) {
    G2x_SetBlendAlpha_(0x04000050, 0, 0, 0x1F, 0x1F);
    G2x_SetBlendAlpha_(0x04001050, 0, 0, 0x1F, 0x1F);
}
