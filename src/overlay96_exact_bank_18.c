#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021E99F4(void) {
    return 4;
}

int ov96_021E99F8(void) {
    return 0x7C;
}

int ov96_021E99FC(void) {
    return 0x1F0;
}

u32 ov96_021E9A04(void) {
    return PlayerProfile_sizeof() * 4;
}

int ov96_021E9A10(void) {
    return 0x74;
}

int ov96_021E9A14(void) {
    return 0x26;
}

int ov96_021E9A18(void) {
    return 0x60;
}

int ov96_021E9A1C(void) {
    return 0x180;
}

void *ov96_021E9A24(void) {
    return sub_02031B10();
}

void *ov96_021E9A2C(int unused, void *course) {
    return PokeathlonCourse_GetField3A4(course);
}

void *ov96_021E9A38(int i, void *course) {
    return PokeathlonCourse_GetField974_AtIndex(course, i);
}

void *ov96_021E9A48(int unused, void *course) {
    return PokeathlonCourse_GetFieldData_AtIndex(course, 0);
}

void *ov96_021E9A54(int stride, void *course, int i) {
    return (u8 *)PokeathlonCourse_GetFieldBA4(course) + stride * i;
}

void *ov96_021E9A68(int i, void *p) {
    return ov96_021E86FC(p, (u8)i);
}
