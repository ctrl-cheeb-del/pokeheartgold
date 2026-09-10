#include "summary_screen_helpers_internal.h"

int sub_02088D18(void *data) {
    if (sub_0208A564(data) == 1) {
        sub_0208AFA0(data, 1);
        return 5;
    }
    return 3;
}

int sub_02088D34(void *data) {
    if (sub_0208A63C(data) == 1) {
        return 2;
    }
    return 4;
}
