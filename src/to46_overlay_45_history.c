#include "to46_overlay_45_history_private.h"

extern void GF_AssertFail(void);
extern u16 SaveArray_CalcCRC16(void *saveData, const void *data, u32 size);

void ov45_0222CB44(Ov45History *history, void *saveData) {
    int i;

    for (i = 0; i < 13; i++) {
        history->ids[i] = 24;
        history->values[i] = -1;
    }
    history->oldest = 0;
    history->next = 0;
    history->saveData = saveData;
    ov45_0222CCA4(history);
}

void ov45_0222CB74(Ov45History *history, u8 id, s32 value) {
    ov45_0222CCB8(history);
    if ((history->next + 1) % 13 == history->oldest) {
        ov45_0222CC00(history);
    }
    history->ids[history->next] = id;
    history->values[history->next] = value;
    history->next = (history->next + 1) % 13;
    ov45_0222CCA4(history);
}

BOOL ov45_0222CBD0(Ov45History *history, s32 oldValue, s32 newValue) {
    int i;
    BOOL found = FALSE;

    ov45_0222CCB8(history);
    for (i = 0; i < 13; i++) {
        if (history->values[i] == oldValue) {
            history->values[i] = newValue;
            found = TRUE;
        }
    }
    ov45_0222CCA4(history);
    return found;
}

u8 ov45_0222CC00(Ov45History *history) {
    u8 id;

    ov45_0222CCB8(history);
    if (history->next == history->oldest) {
        return 24;
    }
    id = history->ids[history->oldest];
    history->ids[history->oldest] = 24;
    history->values[history->next] = -1;
    history->oldest = (history->oldest + 1) % 13;
    ov45_0222CCA4(history);
    return id;
}

u8 ov45_0222CC50(Ov45History *history, u32 index) {
    int slot;

    if (index >= 12) {
        GF_AssertFail();
    }
    ov45_0222CCB8(history);
    slot = history->next - (index + 1);
    if (slot < 0) {
        slot += 13;
    }
    return history->ids[slot];
}

s32 ov45_0222CC7C(Ov45History *history, u32 index) {
    int slot;

    if (index >= 12) {
        GF_AssertFail();
    }
    ov45_0222CCB8(history);
    slot = history->next - (index + 1);
    if (slot < 0) {
        slot += 13;
    }
    return history->values[slot];
}

void ov45_0222CCA4(Ov45History *history) {
    history->crc = SaveArray_CalcCRC16(history->saveData, history, 0x44);
}

void ov45_0222CCB8(Ov45History *history) {
    u16 crc = SaveArray_CalcCRC16(history->saveData, history, 0x44);

    if (crc != history->crc) {
        GF_AssertFail();
        history->corrupt = TRUE;
    }
}
