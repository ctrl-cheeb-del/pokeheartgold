#include "overlay75_flow_r39_private.h"

int ov75_022483EC(void *p) {
    int input;

    if (ov75_02249534(U32_AT(p, 0x44)) == 1) {
        return 0;
    }
    switch (U32_AT(p, 0x94)) {
    case 0:
        U32_AT(p, 0x94) = 3;
        break;
    case 1:
        U32_AT(p, 0x94)
        ++;
        break;
    case 2:
        input = YesNoPrompt_HandleInput(PTR_AT(p, 0x88));
        if (input == 1) {
            YesNoPrompt_Destroy(PTR_AT(p, 0x88));
            ov75_022494CC(p, PTR_AT(p, 0x34), 9, 1, 0xF0F);
            U32_AT(p, 0x94) = 4;
        } else if (input == 2) {
            YesNoPrompt_Destroy(PTR_AT(p, 0x88));
            U32_AT(p, 0x94)
            ++;
        }
        break;
    case 3:
        input = ov75_022480B8(p);
        if (input == 1) {
            ov75_022494CC(p, PTR_AT(p, 0x34), 9, 1, 0xF0F);
            U32_AT(p, 0x94)
            ++;
        } else if (input == 2) {
            ov75_02247854(p, 0x22, 0);
        }
        break;
    case 4:
        PTR_AT(p, 0x88) = ov75_02247890(PTR_AT(p, 4), 0x234, 0);
        U32_AT(p, 0x94)
        ++;
        break;
    default:
        input = YesNoPrompt_HandleInput(PTR_AT(p, 0x88));
        if (input == 1) {
            YesNoPrompt_Destroy(PTR_AT(p, 0x88));
            U32_AT(p, 8) = 5;
        } else if (input == 2) {
            YesNoPrompt_Destroy(PTR_AT(p, 0x88));
            ov75_022494CC(p, PTR_AT(p, 0x34), 0xA, 1, 0xF0F);
            ov75_02247854(p, 0x22, 0);
        }
        break;
    }
    return 0;
}
