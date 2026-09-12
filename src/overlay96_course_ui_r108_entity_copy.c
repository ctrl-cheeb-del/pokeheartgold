#include "overlay96_course_ui_r108_private.h"

extern void ov96_02212F94(void *, void *, int);

void ov96_02212F0C(void *arg0, void *arg1) {
    Ov96R108Entity *src = arg0;
    Ov96R108Entity *dst = arg1;
    Ov96R108Entity temp;

    temp.vec14 = src->vec14;
    temp.vec20 = src->vec20;
    temp.unk39 = src->unk39;
    temp.unk3B = src->unk3B;
    temp.unk3C = src->unk3C;
    temp.unk3D = src->unk3D;
    temp.unk3E = src->unk3E;
    temp.unk40 = src->unk40;
    temp.unk41 = src->unk41;
    temp.vec08 = src->vec08;
    ov96_02212F94(src, dst, 0);
    ov96_02212F94(dst, &temp, 1);
}
