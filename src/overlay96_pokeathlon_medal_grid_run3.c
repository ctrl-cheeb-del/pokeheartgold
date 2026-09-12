#include "overlay96_pokeathlon_medal_grid_private.h"

u32 ov96_021FB514(Ov96R71Node *a, Ov96R71Node *b) {
    if (b->hE != 0) {
        if (b->hC > a->hC) {
            OV96_R71_INS(a, b);
            return 1;
        } else if (b->hC == a->hC) {
            if (b->hA > a->hA) {
                OV96_R71_INS(a, b);
                b->w10 = 1;
                return 1;
            } else {
                a->w10 = 1;
            }
        }
    } else {
        OV96_R71_INS(a, b);
        return 1;
    }
    return 0;
}

u32 ov96_021FB56C(Ov96R71Node *a, Ov96R71Node *b) {
    if (b->h8 < a->h8) {
        OV96_R71_INS(a, b);
        return 1;
    } else if (b->h8 == a->h8) {
        if (b->hC > a->hC) {
            OV96_R71_INS(a, b);
            return 1;
        } else if (b->hC == a->hC) {
            if (b->hA > a->hA) {
                OV96_R71_INS(a, b);
                b->w10 = 1;
                return 1;
            } else {
                a->w10 = 1;
            }
        }
    }
    return 0;
}
