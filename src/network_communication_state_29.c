#include "network_communication_state_internal.h"

int sub_0203A378(void *saveData, void *friendData) {
    int i;
    void *other;
    void *friends;
    other = sub_0203484C(friendData);
    friends = sub_0202C6F4(saveData);
    for (i = 0; i < 32; i++) {
        if (DWC_IsEqualFriendData(other, sub_0202C23C(friends, i))) {
            return i;
        }
    }
    return 32;
}
