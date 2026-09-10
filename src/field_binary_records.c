#include "field_binary_records_internal.h"

LocalAreaPairs *ov01_021EA724(void) {
    LocalAreaPairs *pairs = Heap_Alloc(HEAP_ID_FIELD1, sizeof(LocalAreaPairs));
    if (pairs == NULL) {
        GF_AssertFail();
    }
    return pairs;
}

void ov01_021EA73C(const char *path, LocalAreaPairs *pairs) {
    u16 counts[2];
    FSFile file;
    u32 firstSize;
    u32 secondSize;
    FS_InitFile(&file);
    if (FS_OpenFile(&file, path)) {
        if (FS_ReadFile(&file, &counts[1], sizeof(u16)) < 0) {
            GF_AssertFail();
        }
        if (FS_ReadFile(&file, &counts[0], sizeof(u16)) < 0) {
            GF_AssertFail();
        }
        firstSize = counts[1] * sizeof(*pairs->first);
        secondSize = counts[0] * sizeof(*pairs->second);
        pairs->first = Heap_Alloc(HEAP_ID_FIELD1, firstSize);
        if (pairs->first == NULL) {
            GF_AssertFail();
        }
        pairs->second = Heap_Alloc(HEAP_ID_FIELD1, secondSize);
        if (pairs->second == NULL) {
            GF_AssertFail();
        }
        if (FS_ReadFile(&file, pairs->first, firstSize) < 0) {
            GF_AssertFail();
        }
        if (FS_ReadFile(&file, pairs->second, secondSize) < 0) {
            GF_AssertFail();
        }
        FS_CloseFile(&file);
        return;
    }
    GF_AssertFail();
}

void ov01_021EA7E0(LocalAreaPairs *pairs) {
    Heap_Free(pairs->second);
    Heap_Free(pairs->first);
    Heap_Free(pairs);
}

void ov01_021EA7F8(int index, LocalAreaPairs *pairs, u16 *out) {
    *out = pairs->first[index][0];
}

void ov01_021EA804(int index, LocalAreaPairs *pairs, u16 *out0, u16 *out1) {
    *out0 = pairs->first[index][0];
    *out1 = pairs->first[index][1];
}

u16 (*ov01_021EA81C(int index, LocalAreaPairs *pairs))[2] {
    return &pairs->second[index];
}
