#include "save_arrays.h"
#include "system.h"
#include "unk_0202FBCC.h"
extern struct UnkStruct_0202FBCC *_021D2AF8;
u32 sub_0202FBCC(void);
void sub_0202FBD4(struct UnkStruct_0202FBCC *record);
void sub_0202FC24(void);
struct UnkStruct_0202FBCC *sub_0202FC5C(void);
void *sub_0202FC74(void);

u32 sub_0202FBCC(void) {
    return sizeof(struct UnkStruct_0202FBCC);
}
void sub_0202FBD4(struct UnkStruct_0202FBCC *record) {
    MI_CpuClear32(record, sizeof(*record));
    record->unk_0000 = -1;
}
void sub_0202FBF0(SaveData *save, enum HeapID heapId, u32 *out) {
    if (_021D2AF8 != NULL) {
        Heap_Free(_021D2AF8);
        _021D2AF8 = NULL;
    }
    _021D2AF8 = sub_0202711C(save, heapId, (int *)out, 0);
    sub_0202FBD4(_021D2AF8);
}
void sub_0202FC24(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    Heap_Free(_021D2AF8);
    _021D2AF8 = NULL;
}
BOOL sub_0202FC48(void) {
    return _021D2AF8 != NULL;
}
struct UnkStruct_0202FBCC *sub_0202FC5C(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return _021D2AF8;
}
void *sub_0202FC74(void) {
    GF_ASSERT(_021D2AF8 != NULL);
    return (u8 *)_021D2AF8 + 4;
}

BOOL sub_0202FC90(SaveData *save, enum HeapID heapId, int *out, void *battle, int index);
BOOL sub_0202FD28(SaveData *save, enum HeapID heapId, int *out, int index);
void sub_02030258(void *data, u32 size, u32 seed);
BOOL sub_02030154(SaveData *save, struct UnkStruct_0202FBCC *record);
BOOL sub_0203018C(SaveData *save, struct UnkStruct_0202FBCC *record);
void sub_020304F0(void *battle, SaveData *save);
BOOL sub_0202FC90(SaveData *save, enum HeapID heapId, int *out, void *battle, int index) {
    if (_021D2AF8 != NULL) {
        Heap_Free(_021D2AF8);
        _021D2AF8 = NULL;
    }
    _021D2AF8 = sub_0202711C(save, heapId, out, index);
    if (*out != 1) {
        *out = 3;
        return TRUE;
    }
    void *data = (u8 *)_021D2AF8 + 0xe8;
    u32 crc = *(u16 *)((u8 *)data + 0x1c64);
    sub_02030258(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
    if (sub_02030154(save, _021D2AF8) == TRUE) {
        *out = 0;
        return TRUE;
    }
    if (!sub_0203018C(save, _021D2AF8)) {
        *out = 2;
        return TRUE;
    }
    if (battle != NULL) {
        sub_020304F0(battle, save);
    }
    *out = 1;
    return TRUE;
}
BOOL sub_0202FD28(SaveData *save, enum HeapID heapId, int *out, int index) {
    struct UnkStruct_0202FBCC *record = sub_0202711C(save, heapId, out, index);
    if (*out != 1) {
        *out = 3;
        Heap_Free(record);
        return FALSE;
    }
    void *data = (u8 *)record + 0xe8;
    u32 crc = *(u16 *)((u8 *)data + 0x1c64);
    sub_02030258(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
    if (sub_02030154(save, record) == TRUE) {
        *out = 0;
        Heap_Free(record);
        return FALSE;
    }
    if (!sub_0203018C(save, record)) {
        *out = 2;
        Heap_Free(record);
        return FALSE;
    }
    *out = 1;
    Heap_Free(record);
    return TRUE;
}

int sub_0202FDA4(SaveData *save, struct UnkStruct_0202FBCC *record, int index, u16 *state);
int sub_0202FDA4(SaveData *save, struct UnkStruct_0202FBCC *record, int index, u16 *state) {
    switch (*state) {
    case 0: {
        sub_0201A728(8);
        sub_0201A748((enum HeapID)11);
        int result = sub_02027134(save, record, index);
        if (result == 2) {
            Save_PrepareForAsyncWrite(save, 2);
            (*state)++;
            return 0;
        }
        sub_0201A738(8);
        return result;
    }
    case 1: {
        int result = Save_WriteFileAsync(save);
        if (result == 2 || result == 3) {
            *state = 0;
            sub_0201A774();
            sub_0201A738(8);
        }
        return result;
    }
    }
    return 0;
}

int sub_0202FE14(SaveData *save, int type, int arg, int index, u16 *state, u16 *writeState);
void sub_0202FF08(SaveData *save, void *header, void *data, int type, int arg);
void sub_02030250(void *data, u32 size, u32 seed);
int sub_0202FE14(SaveData *save, int type, int arg, int index, u16 *state, u16 *writeState) {
    switch (*state) {
    case 0: {
        if (_021D2AF8 == NULL) {
            return 3;
        }
        u8 *header = (u8 *)_021D2AF8 + 0x84;
        u8 *data = (u8 *)_021D2AF8 + 0xe8;
        sub_0202FF08(save, header, data, type, arg);
        *(u16 *)(header + 0x48) = 0xe281;
        *(u16 *)(header + 0x60) = SaveArray_CalcCRC16(save, header, 0x58);
        *(u16 *)(data + 0x1c62) = 0xe281;
        *(u16 *)(data + 0x1c64) = SaveArray_CalcCRC16(save, data, 0x1c64);
        u32 crc = *(u16 *)(data + 0x1c64);
        sub_02030250(data, 0x1c64, crc + ((crc ^ 0xffff) << 16));
        *writeState = 0;
        (*state)++;
        break;
    }
    case 1:
        return sub_0202FDA4(save, _021D2AF8, index, writeState);
    }
    return 0;
}
void sub_0202FEB8(int type, int *count, int *last);
void sub_0202FEB8(int type, int *count, int *last) {
    switch (type) {
    case 14:
    case 17:
    case 20:
    case 23:
    case 26:
    case 29:
    case 32:
        *count = 4;
        *last = 3;
        break;
    default:
        *count = 2;
        *last = 6;
        break;
    }
}
