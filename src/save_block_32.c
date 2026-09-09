#include "global.h"

#include "save.h"
typedef struct SaveBlock32 {
    u32 value;
    u32 flags;
} SaveBlock32;
u32 sub_020318C8(void);
void sub_020318CC(SaveBlock32 *data);
SaveBlock32 *sub_020318E8(SaveData *save);
u32 sub_020318F4(SaveBlock32 *data);
u32 sub_020318F8(SaveBlock32 *data);
void sub_020318FC(SaveBlock32 *data, u32 value);
void sub_02031900(SaveBlock32 *data, u32 value);
u32 sub_020318C8(void) {
    return sizeof(SaveBlock32);
}
void sub_020318CC(SaveBlock32 *data) {
    MI_CpuClear32(data, sub_020318C8());
    data->value = 0xFFFFFFFF;
}
SaveBlock32 *sub_020318E8(SaveData *save) {
    return SaveArray_Get(save, 32);
}
u32 sub_020318F4(SaveBlock32 *data) {
    return data->value;
}
u32 sub_020318F8(SaveBlock32 *data) {
    return data->flags;
}
void sub_020318FC(SaveBlock32 *data, u32 value) {
    data->value = value;
}
void sub_02031900(SaveBlock32 *data, u32 value) {
    data->flags = value;
}
