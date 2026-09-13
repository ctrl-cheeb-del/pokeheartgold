#include "r40_unk_02033FC4_private.h"

int sub_02033FC4(u16 index) {
    LookupTable02033FC4 table = _020F692C;
    GF_ASSERT(index < 41);
    return table.values[index];
}

int sub_02033FF0(u16 index) {
    LookupTable02033FC4 table = _020F6955;
    GF_ASSERT(index < 41);
    return table.values[index];
}
