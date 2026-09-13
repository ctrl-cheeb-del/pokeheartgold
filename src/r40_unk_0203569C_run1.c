#include "r40_unk_0203569C_private.h"

BOOL sub_0203569C(void);

BOOL sub_0203569C(void) {
    if (_021D4134.state != NULL) {
        if (_021D4134.state->active != 0) {
            return TRUE;
        }
    }
    return FALSE;
}
