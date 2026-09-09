#include "global.h"

#include "save.h"
#include "unk_0202E41C.h"

u32 sub_0202E41C(void);
void sub_0202E424(UnkStruct_0202E474 *data);
void sub_0202E43C(UnkStruct_0202E474 *data);

void sub_0202E48C(UnkStruct_0202E474 *data, u8 value);
void sub_0202E498(UnkStruct_0202E474 *data);
void sub_0202E474(UnkStruct_0202E474 *data);

u32 sub_0202E41C(void) {
    return sizeof(UnkStruct_0202E474);
}
void sub_0202E424(UnkStruct_0202E474 *data) {
    MI_CpuClearFast(data, sizeof(*data));
    SaveSubstruct_UpdateCRC(23);
}
void sub_0202E43C(UnkStruct_0202E474 *data) {
    MI_CpuClearFast(data->unk_00C, sizeof(data->unk_00C));
    MI_CpuClearFast(data->unk_0CC, sizeof(data->unk_0CC));
    MI_CpuClearFast(data->unk_18C, sizeof(data->unk_18C));
    sub_0202E474(data);
    SaveSubstruct_UpdateCRC(23);
}
void sub_0202E474(UnkStruct_0202E474 *data) {
    sub_0202E48C(data, 0);
    sub_0202E498(data);
    SaveSubstruct_UpdateCRC(23);
}
void sub_0202E48C(UnkStruct_0202E474 *data, u8 value) {
    data->filler_000[8] = value;
    SaveSubstruct_UpdateCRC(23);
}
void sub_0202E498(UnkStruct_0202E474 *data) {
    int i;
    for (i = 0; i < 4; i++) {
        data->filler_000[i] = 0;
    }
    SaveSubstruct_UpdateCRC(23);
}
