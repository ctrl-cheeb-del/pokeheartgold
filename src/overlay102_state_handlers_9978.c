#include "overlay102_state_handlers_9978_private.h"

void ov102_021E9978(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EAF44(w->unk1E0);
        ov102_021EAF7C(w->unk1E0);
        ov102_021EADF8(w->unk1E0, 1);
        ov102_021EAE40(w->unk1E0, 0);
        ov102_021EB664(w->unk1E4);
        ov102_021EBA44(w->unk1E8);
        ov102_021EA71C(w->unk1E0, 0);
        s->state++;
        break;
    case 1: {
        int a = ov102_021EBA5C(w->unk1E8);
        int b = ov102_021EA754(w->unk1E0);
        if (a && b) {
            ov102_021EB9C0(w->unk1E8, ov102_021E8FD0(w->unk18));
            ov102_021EB98C(w->unk1E8, 1);
            ov102_021E94A4(s);
        }
        break;
    }
    }
}

void ov102_021E9A24(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB624(w->unk1E4);
        s->state++;
        break;
    case 1:
        ov102_021EBBF4(w->unk1E8);
        s->state++;
        break;
    case 2:
        if (ov102_021EBC28(w->unk1E8) && ov102_021EB654(w->unk1E4)) {
            ov102_021EBBD0(w->unk1E8);
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9A8C(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB624(w->unk1E4);
        s->state++;
        break;
    case 1:
        ov102_021EB98C(w->unk1E8, 0);
        ov102_021EBBF4(w->unk1E8);
        s->state++;
        break;
    case 2:
        if (ov102_021EBC28(w->unk1E8)) {
            ov102_021EBBD0(w->unk1E8);
            s->state++;
        }
        break;
    case 3:
        if (ov102_021EB654(w->unk1E4)) {
            ov102_021EB9C0(w->unk1E8, ov102_021E8FD0(w->unk18));
            ov102_021EB98C(w->unk1E8, 1);
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9B30(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB67C(w->unk1E4);
        ov102_021EB98C(w->unk1E8, 0);
        ov102_021EBAAC(w->unk1E8);
        ov102_021EADF8(w->unk1E0, 0);
        ov102_021EAE40(w->unk1E0, 0);
        ov102_021EA71C(w->unk1E0, 1);
        s->state++;
        break;
    case 1: {
        int a = ov102_021EBAD0(w->unk1E8);
        int b = ov102_021EA754(w->unk1E0);
        if (a && b) {
            ov102_021EAFAC(w->unk1E0);
            ov102_021EAF50(w->unk1E0);
            w->unk1F4 = 0;
            ov102_021E94A4(s);
        }
        break;
    }
    }
}

void ov102_021E9BD0(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EBDEC(w->unk1EC);
        ov102_021EB98C(w->unk1E8, 0);
        ov102_021EBB50(w->unk1E8);
        s->state++;
        break;
    case 1:
        if (ov102_021EBB6C(w->unk1E8)) {
            ov102_021EBE3C(w->unk1EC);
            s->state++;
        }
        break;
    case 2:
        if (ov102_021EBE80(w->unk1EC)) {
            ov102_021EBF38(w->unk1EC, ov102_021E9028(w->unk18));
            ov102_021EBEF4(w->unk1EC, 1);
            ov102_021EC290(w->unk1F0, 1);
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9C70(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB624(w->unk1E4);
        s->state++;
        break;
    case 1:
        ov102_021EBEF4(w->unk1EC, 0);
        ov102_021EC290(w->unk1F0, 0);
        ov102_021EBEA4(w->unk1EC);
        s->state++;
        break;
    case 2:
        if (ov102_021EBEC8(w->unk1EC)) {
            ov102_021EBBD0(w->unk1E8);
            s->state++;
        }
        break;
    case 3:
        ov102_021EBB88(w->unk1E8);
        s->state++;
        break;
    case 4:
        if (ov102_021EBBC4(w->unk1E8) && ov102_021EB654(w->unk1E4)) {
            ov102_021EB9C0(w->unk1E8, ov102_021E8FD0(w->unk18));
            ov102_021EB98C(w->unk1E8, 1);
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9D44(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB67C(w->unk1E4);
        ov102_021EBEF4(w->unk1EC, 0);
        ov102_021EC290(w->unk1F0, 0);
        ov102_021EBEA4(w->unk1EC);
        ov102_021EADF8(w->unk1E0, 0);
        ov102_021EAE40(w->unk1E0, 0);
        ov102_021EA71C(w->unk1E0, 1);
        s->state++;
        break;
    case 1: {
        int a = ov102_021EBEC8(w->unk1EC);
        int b = ov102_021EA754(w->unk1E0);
        if (a && b) {
            ov102_021EBB1C(w->unk1E8);
            ov102_021EBB88(w->unk1E8);
            s->state++;
        }
        break;
    }
    case 2:
        if (ov102_021EBBC4(w->unk1E8)) {
            ov102_021EBB2C(w->unk1E8);
            s->state++;
        }
        break;
    case 3:
        if (ov102_021EBB44(w->unk1E8)) {
            ov102_021EAA3C(w->unk1E0);
            ov102_021EAF5C(w->unk1E0, 1);
            ov102_021EAFAC(w->unk1E0);
            ov102_021EAF50(w->unk1E0);
            w->unk1F4 = 0;
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9E60(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    switch (s->state) {
    case 0:
        ov102_021EB67C(w->unk1E4);
        ov102_021EBEF4(w->unk1EC, 0);
        ov102_021EC290(w->unk1F0, 0);
        ov102_021EBEA4(w->unk1EC);
        s->state++;
        break;
    case 1:
        if (ov102_021EBEC8(w->unk1EC)) {
            ov102_021EBB1C(w->unk1E8);
            ov102_021EBB88(w->unk1E8);
            s->state++;
        }
        break;
    case 2:
        if (ov102_021EBBC4(w->unk1E8)) {
            ov102_021EBB2C(w->unk1E8);
            s->state++;
        }
        break;
    case 3:
        if (ov102_021EBB44(w->unk1E8)) {
            ov102_021EAA3C(w->unk1E0);
            ov102_021EAF5C(w->unk1E0, 0);
            ov102_021EB524(w->unk1E4, 1);
            ov102_021E94A4(s);
        }
        break;
    }
}

void ov102_021E9F38(void *unused, Ov102StateR16 *s) {
    Ov102WorkR16 *w = s->work;
    u8 value = ov102_021E8FC8(w->unk18);
    if (value == 0) {
        w->unk1F4 = 0;
        ((void (*)(void *))ov102_021EB524)(w->unk1E4);
        ov102_021EAF5C(w->unk1E0, 1);
        ov102_021EAFF0(w->unk1E0, ov102_021E8FC0(w->unk18));
    } else {
        w->unk1F4 = 1;
        ov102_021EAF5C(w->unk1E0, 0);
        ov102_021EB524(w->unk1E4, 1);
        ov102_021EB530(w->unk1E4, value);
    }
    ov102_021E94A4(s);
}
