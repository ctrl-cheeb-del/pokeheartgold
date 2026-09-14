#include "to45_overlay96_r43_private.h"

void ov96_021EDF84(Ov96R43Record *dst, const Ov96R43Record *src) {
    int i;
    u32 sum = 0;

    for (i = 0; i < 10; i++) {
        sum += src->field44[i];
    }
    dst->field00 = src->field04;
    dst->field04 = src->field08;
    dst->field08 = src->field0C;
    dst->field0C = sum;
    dst->field10 = src->field6C;
    dst->field14 = src->field10;
    dst->field18 = src->field14;
    dst->field1C = src->field18;
    dst->field20 = src->field1C;
    dst->field24 = src->field20;
    dst->field28 = src->field24;
    dst->field2C = src->field28;
    dst->field30 = src->field2C;
    dst->field34 = src->field30;
    dst->field38 = src->field38;
    dst->field3C = src->field3C;
    dst->field40 = src->field40;
    for (i = 0; i < 10; i++) {
        dst->field44[i] = src->field44[i];
    }
    dst->field6C = src->field34;
    dst->field70 = src->field70;
}

void ov96_021EDFFC(u8 *dst, const u32 *values) {
    int i;
    for (i = 0; i < 29; i++) {
        if (ov96_0221B124[i] == 0) {
            GF_AssertFail();
        }
        dst[i] = MTRandom() % 3;
        if (values[i] != 0) {
            dst[i] = dst[i] + values[i] / ov96_0221B124[i];
        }
    }
}

int ov96_021EE040(const u8 *values, u8 *rank) {
    u8 indices[29] = { 0 };
    u32 max = 0;
    int count = 0;
    int i;
    u8 *p;

    for (i = 0; i < 29; i++) {
        if (max < values[i]) {
            max = values[i];
        }
    }
    i = 0;
    p = indices;
    while (i < 29) {
        if (max == values[i]) {
            *p++ = i;
            count++;
        }
        i++;
    }
    for (i = 0; i < 4; i++) {
        if ((u32)max >= ov96_0221AF54[i]) {
            *rank = 3 - i;
            break;
        }
    }
    return indices[MTRandom() % count];
}

void ov96_021EE0AC(Ov96R43Result *result, void *course) {
    Ov96R43Record record = { 0 };
    u8 scores[29] = { 0 };
    u8 rank;
    Ov96R43Record *source;
    u8 selection;

    source = PokeathlonSave_GetAgainUnkB00(Save_Pokeathlon_Get(PokeathlonCourse_GetSaveData(course)));
    ov96_021EDF84(&record, source);
    ov96_021EDFFC(scores, (u32 *)&record);
    selection = ov96_021EE040(scores, &rank);
    result->field00 = rank + ov96_021EDF7C(selection);
    result->field04 = (result->field04 & 0xFF000000) | (((u32 *)&record)[selection] & 0x00FFFFFF);
    result->field04 = (result->field04 & 0x00FFFFFF) | (ov96_021EDF5C(source->field70) << 24);
}

void ov96_021EE144(Ov96R43Result *result, void *course, int index) {
    Ov96R43Record record = { 0 };
    u8 scores[29] = { 0 };
    u8 rank;
    Ov96R43Record *source;
    u8 selection;

    source = PokeathlonCourse_GetField974_AtIndex(course, index);
    ov96_021EDF84(&record, source);
    ov96_021EDFFC(scores, (u32 *)&record);
    selection = ov96_021EE040(scores, &rank);
    result->field00 = rank + ov96_021EDF7C(selection);
    result->field04 = (result->field04 & 0xFF000000) | (((u32 *)&record)[selection] & 0x00FFFFFF);
    result->field04 = (result->field04 & 0x00FFFFFF) | (ov96_021EDF5C(source->field70) << 24);
}
