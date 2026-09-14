#include "to45_overlay96_r93_r7_private.h"

typedef struct Ov96PackedResult {
    u32 field00 : 8;
    u32 field08 : 8;
    u32 field10 : 8;
    u32 field18 : 2;
    u32 field1A : 1;
    u32 field1B : 1;
    u32 field1C : 1;
    u32 field1D : 3;
} Ov96PackedResult;

typedef union Ov96PackedInput {
    struct {
        u32 field00 : 8;
        u32 field08 : 8;
        u32 field10 : 8;
        u32 field18_2 : 2;
        u32 field1A_2 : 2;
        u32 field1C : 1;
        u32 : 3;
    } multi;
    struct {
        u32 : 26;
        u32 field1A_1 : 1;
        u32 : 5;
    } single26;
} Ov96PackedInput;

typedef struct Ov96TouchBits {
    u32 counter : 8;
    u32 startY : 8;
    u32 currentY : 8;
    u32 active : 1;
    u32 : 7;
} Ov96TouchBits;

typedef struct Ov96TouchWork {
    u8 pad[0x264];
    Ov96TouchBits touch;
} Ov96TouchWork;

void ov96_0220A424(void *course) {
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    Ov96PackedResult *out = ov96_021E8A20(PokeathlonCourse_GetDataCopyArea(course));
    u32 *input = ov96_0220B758(PTR(work, 0x4c));
    u32 mode = ov96_0220B730(PTR(work, 0x4c));

    out->field00 = ov96_0220AD4C(PTR(work, 0x40));
    out->field08 = (*input << 6) >> 24;
    out->field10 = ov96_0220B79C(PTR(work, 0x4c));
    out->field1A = ov96_0220B774(PTR(work, 0x4c));
    out->field1C = mode == 3;
    out->field18 = ov96_0220B7B4(PTR(work, 0x4c));
}

typedef struct Ov96NineWords {
    u32 words[9];
} Ov96NineWords;

void ov96_0220A4DC(void *course) {
    void *mode = ov96_021E5F24(course);
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    Ov96PackedResult *out;
    int i;

    if (work == NULL) {
        GF_AssertFail();
    }
    if (PTR(work, 0x4c) == NULL) {
        GF_AssertFail();
    }
    if (PTR(work, 0x40) == NULL) {
        GF_AssertFail();
    }
    if (mode == NULL) {
        out = ov96_021E8A20(data + 0x28);
        *(Ov96NineWords *)ov96_021E8A20(data + 0x50) = *(Ov96NineWords *)ov96_021E8A20(data);
        data += 0x50;
        for (i = 0; i < 4; i++, data += 0x28, out++) {
            Ov96PackedInput *input = ov96_021E8A20(data);
            out->field00 = input->multi.field00;
            out->field08 = input->multi.field08;
            out->field10 = input->multi.field10;
            out->field18 = input->multi.field18_2;
            out->field1A = input->single26.field1A_1;
            out->field1B = input->multi.field1C;
        }
    }
    ov96_0220A424(course);
}
