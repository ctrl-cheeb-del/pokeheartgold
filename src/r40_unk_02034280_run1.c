#include "r40_unk_02034280_private.h"

void *sub_02034280(int index, void *arg, int size) {
    if (index < 22) {
        return _020F6980[index].aux(arg, NULL, size);
    }
    return _021D412C->table[index - 22].aux(arg, _021D412C->context, size);
}
