#include "ov70_wave42_prompt_private.h"
int ov70_022446D0(void *w) {
    ov70_02244FA4(w, PTR(w, 0xbac), 0x11, 1, 0xf0f);
    ov70_02238D84(w, 0xd, 1);
    U16(w, 0x11fa) = 1;
    return 3;
}
int ov70_02244708(void *w) {
    int r = ov70_02238C8C(w);
    if (r == 1) {
        YesNoPrompt_Destroy(PTR(w, 0x11c8));
        ov70_02244FA4(w, PTR(w, 0xba8), 1, 1, 0xf0f);
        ov70_02238D84(w, 0xc, 2);
        ov70_02238F64(w);
    } else if (r == 2) {
        YesNoPrompt_Destroy(PTR(w, 0x11c8));
        sub_0203946C();
        ov70_02238E50(w, 0, 0);
        U32(w, 0x2c) = 0xb;
    }
    return 3;
}
int ov70_02244774(void *w) {
    ov70_02244FA4(w, PTR(w, 0xba0), 7, 1, 0xf0f);
    ov70_02238D84(w, 0xd, 0x10);
    return 3;
}
int ov70_022447A0(void *w) {
    int r = Handle2dMenuInput_DeleteOnFinish(PTR(w, 0x11b0), 0x3d);
    if (r == -1) {
        goto done;
    }
    if (r == -2) {
        if (ov00_021EC5B4() == 0) {
            U32(w, 0x2c) = 0;
            goto done;
        }
        ov70_02238E50(w, 7, 0xb);
        U32(w, 0x1c) = 1;
        U32(w, 0x2c) = 0xb;
        goto done;
    }
    if (ov00_021EC5B4() != 0) {
        ov00_021EC8D8();
    }
    sub_0203946C();
    ov70_02238E50(w, 0, 0);
    U32(w, 0x2c) = 0xb;
done:
    return 3;
}
int ov70_02244804(void *w) {
    ov70_02244FA4(w, PTR(w, 0xbac), 0x1a, 1, 0xf0f);
    ov70_02238D84(w, 0xc, 0x12);
    return 3;
}
