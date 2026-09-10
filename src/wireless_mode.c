#include "wireless_internal.h"
void sub_02032844(int);
void sub_02033830(void);
BOOL sub_02033080(void);
BOOL sub_02032B0C(void);
void sub_02033858(void);
void sub_02033858(void) {
    int state = _021D4124.work->state;
    if (state == 1) {
        return;
    }
    if (state != 6 && state != 5 && state != 4) {
        sub_02032844(3);
        sub_02033830();
        return;
    }
    sub_02032844(3);
    switch (_021D4124.work->wmState) {
    case 1:
    case 5:
        if (!sub_02033080()) {
            sub_02033830();
        }
        break;
    case 0:
    case 4:
        if (!sub_02032B0C()) {
            sub_02033830();
        }
        break;
    case 2:
    case 3:
        break;
    }
}
