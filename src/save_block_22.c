#include "global.h"

#include "unk_0202DB34.h"
typedef struct SaveBlock22 {
    u8 data[0xEC];
    u16 value;
    u16 value2;
    u32 word;
    u32 word2;
} SaveBlock22;
int sub_0202DB34(SaveData *save);
u32 sub_0202DB40(void);
void sub_0202DB44(SaveBlock22 *data);
u16 sub_0202DB54(SaveBlock22 *data);
void sub_0202DB5C(SaveBlock22 *data, u16 value);
void sub_0202DB64(SaveBlock22 *data, void *out);
void sub_0202DB70(SaveBlock22 *data, void *src);
u32 sub_0202DB80(SaveBlock22 *data);
void sub_0202DB88(SaveBlock22 *data, u32 value);
u32 sub_0202DB90(SaveBlock22 *data);
void sub_0202DB98(SaveBlock22 *data, u32 value);
u16 sub_0202DBA0(SaveBlock22 *data);
int sub_0202DB34(SaveData *save) {
    return (int)SaveArray_Get(save, 22);
}
u32 sub_0202DB40(void) {
    return sizeof(SaveBlock22);
}
void sub_0202DB44(SaveBlock22 *data) {
    MI_CpuClearFast(data, sizeof(*data));
}
u16 sub_0202DB54(SaveBlock22 *data) {
    return data->value;
}
void sub_0202DB5C(SaveBlock22 *data, u16 value) {
    data->value = value;
}
void sub_0202DB64(SaveBlock22 *data, void *out) {
    MI_CpuCopyFast(data->data, out, 0xEC);
}
void sub_0202DB70(SaveBlock22 *data, void *src) {
    MI_CpuCopyFast(src, data->data, 0xEC);
}
u32 sub_0202DB80(SaveBlock22 *data) {
    return data->word;
}
void sub_0202DB88(SaveBlock22 *data, u32 value) {
    data->word = value;
}
u32 sub_0202DB90(SaveBlock22 *data) {
    return data->word2;
}
void sub_0202DB98(SaveBlock22 *data, u32 value) {
    data->word2 = value;
}
u16 sub_0202DBA0(SaveBlock22 *data) {
    return data->value2;
}
