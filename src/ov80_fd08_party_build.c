#include "ov80_fd08_party_build_internal.h"

void ov80_02230270(void *arg0) {
    Ov80PartyBuildWork *work = arg0;
    u8 *raw = arg0;
    u16 ids[6];
    u8 attrs[6];
    u32 values[6];
    Ov80PartyRecord records[6];
    void *mon;
    u16 *cursor;
    int i;

    ov80_02236DD4(raw[4]);
    i = 0;
    cursor = (u16 *)work;
    do {
        cursor[12] = sub_02030A24(*(void **)(raw + 0x4F4), 3, (u8)i, 0);
        i++;
        cursor++;
    } while (i < 14);

    for (i = 0; i < 4; i++) {
        ids[i] = sub_02030A24(*(void **)(raw + 0x4F4), 4, (u8)i, 0);
        values[i] = sub_02030A24(*(void **)(raw + 0x4F4), 6, (u8)i, 0);
        attrs[i] = sub_02030A24(*(void **)(raw + 0x4F4), 5, (u8)i, 0);
        work->firstIds[i] = ids[i];
    }
    ov80_0222A52C(records, ids, attrs, values, 0, 4, 11, 0xCD);
    mon = AllocMonZeroed(11);
    for (i = 0; i < 4; i++) {
        ov80_0222A140(&records[i], mon, ov80_02237120(work));
        ov80_0222A3BC(*(void **)(raw + 0x4F8), *(void **)(raw + 0x4D4), mon);
    }
    Heap_Free(mon);

    for (i = 0; i < 4; i++) {
        ids[i] = sub_02030A24(*(void **)(raw + 0x4F4), 7, (u8)i, 0);
        values[i] = sub_02030A24(*(void **)(raw + 0x4F4), 9, (u8)i, 0);
        attrs[i] = sub_02030A24(*(void **)(raw + 0x4F4), 8, (u8)i, 0);
        work->secondIds[i] = ids[i];
    }
    ov80_0222A52C(records, ids, attrs, values, 0, 4, 11, 0xCD);
    mon = AllocMonZeroed(11);
    for (i = 0; i < 4; i++) {
        ov80_0222A140(&records[i], mon, ov80_02237120(work));
        ov80_0222A3BC(*(void **)(raw + 0x4F8), *(void **)(raw + 0x4D8), mon);
    }
    Heap_Free(mon);
}
