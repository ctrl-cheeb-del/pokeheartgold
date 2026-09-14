#include "overlay96_to46_r36_suffix_private.h"

void ov96_021ECAC4(void *course) {
    void *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    void *slot;
    int i = 0;
    u8 *cursor = work;
    slot = (u8 *)work + 0x20;

    for (; i < 5; i++) {
        int count = PokeathlonCourse_GetParticipantCount(course);
        if (i == 4) {
            int value = ov96_021EEBC8(2);
            ov96_021EEA88(PTR(cursor, 0x20), value, 11, *(u32 *)work);
        } else if (i < count) {
            ov96_021EEB74(slot, course, (u8)i, 0);
        } else {
            u8 id = *(u32 *)PokeathlonCourse_GetParticipantData(course, i);
            int value = ov96_021EEDCC(ov96_021E8424(id));
            ov96_021EEA88(PTR(cursor, 0x20), value, 0, *(u32 *)work);
        }
        cursor += 4;
    }
}

void ov96_021ECB38(void **slots, void *course, int index, int state, u32 owner) {
    int populated;
    int code;

    populated = *(int *)PokeathlonCourse_GetParticipantData(course, index) > 0;
    switch (state) {
    case 1:
        code = 0;
        break;
    case 2:
        code = populated ? 11 : 27;
        break;
    default:
        GF_AssertFail();
        break;
    }
    if (populated) {
        u8 id = *(u32 *)PokeathlonCourse_GetParticipantData(course, index);
        int value = ov96_021EEDCC(ov96_021E8424(id));
        ov96_021EEA88(slots[index], value, (u8)code, owner);
    } else {
        ov96_021EEB74(slots, course, (u8)index, code);
    }
}

Ov96R38Result *ov96_021ECBB8(u32 heap, Ov96R38Source *src) {
    Ov96R38Result *out = Heap_Alloc(heap, sizeof(Ov96R38Result));
    int i;
    int j;
    u32 *dst;
    int offset;

    MI_CpuFill8(out, 0, sizeof(Ov96R38Result));
    dst = &out->values[0][0];
    i = 0;
    offset = 5;
    for (; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            dst[j] = ((u32 *)src)[offset + j];
        }
        dst += 7;
        offset += 4;
    }
    return out;
}
