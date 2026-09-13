#include "overlay96_records_r7_private.h"

void ov96_021E7718(Ov96R7Work *w);

void ov96_021E7718(Ov96R7Work *w) {
    void *pokeathlon = Save_Pokeathlon_Get(*(void **)OV96_R7_U32(w, 0x1f8));
    u8 *field = PokeathlonCourse_GetFieldData(w);
    void *varsFlags = Save_VarsFlags_Get(*(void **)OV96_R7_U32(w, 0x1f8));
    u16 points;
    void *records;

    if (((Ov96R7FieldDataBits *)field)->flag) {
        ov96_021E7FA8(w);
        if (!Save_VarsFlags_CheckFlagInArray(varsFlags, 0xf0) && ov96_021E8084(w)) {
            Save_VarsFlags_SetFlagInArray(varsFlags, 0xf0);
        }
    }
    points = OV96_R7_U16(field, 0x1d2);
    if (OV96_R7_U8((void *)OV96_R7_U32(w, 0x1f8), 0xc) == 10) {
        points *= 2;
    }
    PokeathlonSave_AddAthletePoints(pokeathlon, points);
    if (OV96_R7_U32((void *)OV96_R7_U32(w, 0x1f8), 4) == 1) {
        records = PokeathlonSave_GetRecordsLink2(pokeathlon);
        ov96_021E7A2C(w, records);
    } else {
        records = PokeathlonSave_GetRecordsSolo(pokeathlon);
        ov96_021E7BA8(w, records, PokeathlonSave_GetUnkAEC(pokeathlon));
        if (((Ov96R7FieldDataBits *)field)->flag) {
            ov96_021E786C(w, PokeathlonSave_dummy2(pokeathlon));
            if (!Save_VarsFlags_CheckFlagInArray(varsFlags, 0xef) && ov96_021E8060(PokeathlonSave_dummy2(pokeathlon))) {
                Save_VarsFlags_SetFlagInArray(varsFlags, 0xef);
            }
        }
        ov96_021E7938(w, PokeathlonSave_GetRecordsSolo2(pokeathlon));
    }
    ov96_021E7D6C(w, PokeathlonSave_GetAgainUnkB00(pokeathlon));
    if (OV96_R7_U32((void *)OV96_R7_U32(w, 0x1f8), 4) == 0 && !Save_VarsFlags_CheckFlagInArray(varsFlags, 0xf1) && ov96_021E80C4(w)) {
        Save_VarsFlags_SetFlagInArray(varsFlags, 0xf1);
    }
    OV96_R7_U16((void *)OV96_R7_U32(w, 0x1f8), 0xa) = OV96_R7_U16(field, 0x1d2);
    OV96_R7_U16((void *)OV96_R7_U32(w, 0x1f8), 8) = points;
    OV96_R7_U8((void *)OV96_R7_U32(w, 0x1f8), 0xd) = ((Ov96R7FieldDataBits *)field)->value;
}
