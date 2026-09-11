#include "heap.h"
#include "math_util.h"
#include "overlay96_sprite_internal.h"

void ov96_021FC144(u8 *work) {
    u8 random = LCRandom() % 3;
    ReadWholeNarcMemberByIdPair(work + 0x18, 0xE4, (u8)random);
}
