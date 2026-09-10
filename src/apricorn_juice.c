#include "apricorn_internal.h"

int sub_02031FE8(void *data);
int sub_02032004(void *data);
int sub_02032024(SaveApricornBox *box);
void sub_02032058(SaveApricornBox *box, u32 steps);
ApricornRecord *sub_020320E0(SaveApricornBox *box, PlayerProfile *profile, u32 value, enum HeapID heapId);
BOOL sub_02032158(ApricornRecord *a, ApricornRecord *b);

int sub_02031FE8(void *data) {
    struct {
        u16 value : 4;
        u16 padding : 12;
        u8 rest[14];
    } result;
    u32 value;
    sub_02031DA0(data, &result);
    value = result.value;
    if (value >= 5) {
        value = 5;
    }
    return value;
}

int sub_02032004(void *data) {
    u8 result[16];
    sub_02031DA0(data, result);
    if (result[12] == 0) {
        return 0;
    }
    return result[6] + 1;
}

int sub_02032024(SaveApricornBox *box) {
    if (box->unk_09 == 0) {
        return 0;
    }
    box->unk_09--;
    if (box->unk_09 == 0) {
        sub_02031B5C(box->unk_0C);
        box->unk_18 = 0;
        box->unk_14 = 0;
        box->mixProgress = 0;
    }
    return box->unk_09;
}

void sub_02032058(SaveApricornBox *box, u32 steps) {
    u32 difference;
    if ((((u32)box->unk_0A << 16) >> 31) != 0 || box->unk_09 != 0) {
        difference = steps - box->unk_18;
        if (difference >= 100) {
            sub_02032340(box, difference / 100);
            box->unk_18 = steps - difference % 100;
        }
        if ((((u32)box->unk_0A << 16) >> 31) != 0) {
            box->mixProgress = steps - box->unk_14;
            if (box->mixProgress >= 100) {
                if (box->unk_09 != 0) {
                    sub_02031BEC(box, 3);
                } else {
                    sub_02031BEC(box, 2);
                }
                sub_02032354(box);
            }
        }
    }
}

ApricornRecord *sub_020320E0(SaveApricornBox *box, PlayerProfile *profile, u32 value, enum HeapID heapId) {
    ApricornRecord *record = Heap_AllocAtEnd(heapId, sizeof(ApricornRecord));
    MI_CpuFill8(record, 0, sizeof(ApricornRecord));
    record->trainerId = PlayerProfile_GetTrainerID(profile);
    record->gender = PlayerProfile_GetTrainerGender(profile);
    record->language = PlayerProfile_GetLanguage(profile);
    record->version = PlayerProfile_GetVersion(profile);
    StringFillEOS(record->name, 8);
    CopyU16StringArrayN(record->name, PlayerProfile_GetNamePtr(profile), 7);
    sub_02031CEC(box, 8, &record->data);
    if (value > 0xFFFF) {
        record->data.unk0 = 0xFFFF;
    } else {
        record->data.unk0 = value;
    }
    return record;
}

BOOL sub_02032158(ApricornRecord *a, ApricornRecord *b) {
    if (a->trainerId != b->trainerId) {
        return FALSE;
    }
    if (a->gender != b->gender) {
        return FALSE;
    }
    if (a->version != b->version) {
        return FALSE;
    }
    if (a->language != b->language) {
        return FALSE;
    }
    if (StringNotEqual(a->name, b->name) == FALSE) {
        return TRUE;
    }
    return FALSE;
}
