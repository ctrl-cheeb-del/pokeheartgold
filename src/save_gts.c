#include "save_gts.h"

#include "global.h"

#include "constants/save_arrays.h"

GtsSave *Save_Gts_Get(SaveData *save) {
    return SaveArray_Get(save, SAVE_GTS);
}
u32 Save_Gts_sizeof(void) {
    return sizeof(GtsSave);
}
void Save_Gts_Init(GtsSave *data) {
    MI_CpuClearFast(data, sizeof(*data));
}
u16 GtsSave_HasStoredMon(GtsSave *data) {
    return data->hasStoredMon;
}
void GtsSave_SetHasStoredMon(GtsSave *data, u16 value) {
    data->hasStoredMon = value;
}
void GtsSave_GetStoredMon(GtsSave *data, Pokemon *out) {
    MI_CpuCopyFast(data->storedMon, out, 0xEC);
}
void GtsSave_SetStoredMon(GtsSave *data, Pokemon *src, int box) {
    MI_CpuCopyFast(src, data->storedMon, 0xEC);
}
u32 GtsSave_GetDepositDate(GtsSave *data) {
    return data->depositDate;
}
void GtsSave_SetDepositDate(GtsSave *data, u32 value) {
    data->depositDate = value;
}
u32 GtsSave_GetTradeDate(GtsSave *data) {
    return data->tradeDate;
}
void GtsSave_SetTradeDate(GtsSave *data, u32 value) {
    data->tradeDate = value;
}
u16 GtsSave_GetStoredMonBox(GtsSave *data) {
    return data->storedMonBox;
}
