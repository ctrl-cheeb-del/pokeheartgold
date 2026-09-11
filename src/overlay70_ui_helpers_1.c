#include "overlay70_ui_helpers_private.h"

int ov70_0223EDE4(u8 *state, u32 value) {
    switch (value) {
    case 0: state[2] = 1; return 1;
    case 0xFE: state[2] = 2; return 1;
    case 0xFF: state[2] = 3; return 1;
    default: return 0;
    }
}
