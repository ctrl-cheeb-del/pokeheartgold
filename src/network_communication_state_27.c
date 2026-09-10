#include "network_communication_state_internal.h"

void sub_02039FB8(void *history, int country, int region) {
    if (WiFiHistory_GetLocationSeenState(history, country, region) == 0) {
        WiFiHistory_SetLocationSeenState(history, country, region, 1);
    }
}
