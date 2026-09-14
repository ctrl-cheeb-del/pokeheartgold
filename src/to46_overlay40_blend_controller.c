#include "global.h"

extern void G2x_SetBlendAlpha_(u32, int, int, int, int);
void ov40_0222D910(int *, int *, int, int, int, int, int);
void ov40_0222D980(int *, int *, int, int, int, int, int);

void ov40_0222D910(int *eva, int *evb, int main1, int main2, int sub1, int sub2, int mode) {
    *eva = 0;
    *evb = 31;
    if (mode == 0) {
        G2x_SetBlendAlpha_(0x04000050, main1, main2, *eva, *evb);
        G2x_SetBlendAlpha_(0x04001050, sub1, sub2, *eva, *evb);
    }
    if (mode == 1) {
        G2x_SetBlendAlpha_(0x04000050, main1, main2, *eva, *evb);
    }
    if (mode == 2) {
        G2x_SetBlendAlpha_(0x04001050, sub1, sub2, *eva, *evb);
    }
}

void ov40_0222D980(int *eva, int *evb, int main1, int main2, int sub1, int sub2, int mode) {
    if (mode == 0) {
        G2x_SetBlendAlpha_(0x04000050, main1, main2, *eva, *evb);
        G2x_SetBlendAlpha_(0x04001050, sub1, sub2, *eva, *evb);
    }
    if (mode == 1) {
        G2x_SetBlendAlpha_(0x04000050, main1, main2, *eva, *evb);
    }
    if (mode == 2) {
        G2x_SetBlendAlpha_(0x04001050, sub1, sub2, *eva, *evb);
    }
}
