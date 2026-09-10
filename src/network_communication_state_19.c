#include "network_communication_state_internal.h"

void sub_0203957C(void) {
    if (_021D4150 != NULL) {
        sub_0201A738(1);
        sub_020398D4(0, 0);
        Heap_Free(_021D4150);
        _021D4150 = NULL;
        Heap_Destroy(15);
    }
}
