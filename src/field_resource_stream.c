#include "field_resource_stream_internal.h"

void ov01_021FB04C(NARC *narc, Ov01FB04C_Counts *counts);
void ov01_021FB0B0(Ov01FB04C_Counts *counts, Ov01FB04C_Buffers *bufs, u8 **pBuf);
void ov01_021FB110(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB120(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB134(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB144(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB154(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB164(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts);
void ov01_021FB174(SysTask *task, void *data);
Ov01FB04C_Buffers *ov01_021FB254(void);
void ov01_021FB270(NARC *narc, u32 unused, Ov01FB04C_Buffers *bufs, u8 *buf);
void ov01_021FB2E8(void *ptr);
void ov01_021FB2F4(Ov01FB04C_Buffers *bufs);
SysTask *ov01_021FB308(NARC *narc, u32 a1, Ov01FB04C_Buffers *bufs, void **a3, u8 **a4, void **a5);
void ov01_021FB354(SysTask *task);
void ov01_021FB360(Ov01FB04C_Buffers *bufs);

void ov01_021FB04C(NARC *narc, Ov01FB04C_Counts *counts) {
    u32 header[2];

    MIi_CpuClear32(0, (u32 *)counts, sizeof(Ov01FB04C_Counts));
    NARC_ReadFile(narc, 4, header);
    NARC_ReadFile(narc, 2, &counts->unk00);
    NARC_ReadFile(narc, 2, &counts->unk04);
    NARC_ReadFile(narc, 2, &counts->unk08);
    NARC_ReadFile(narc, 2, &counts->unk0C);
    NARC_ReadFile(narc, 2, &counts->unk10);
    NARC_ReadFile(narc, 2, &counts->unk14);
}

void ov01_021FB0B0(Ov01FB04C_Counts *counts, Ov01FB04C_Buffers *bufs, u8 **pBuf) {
    s32 offset = 0;

    bufs->unk10 = *pBuf;
    offset += counts->unk00 * 8;
    bufs->unk14 = *pBuf + offset;
    offset += counts->unk04 * 12;
    bufs->unk04 = *pBuf + offset;
    offset += counts->unk08 * 4;
    bufs->unk00 = *pBuf + offset;
    offset += counts->unk0C * 8;
    bufs->unk08 = *pBuf + offset;
    offset += counts->unk10 * 8;
    bufs->unk0C = *pBuf + offset;
    offset += counts->unk14 * 2;
    GF_ASSERT(offset <= 0x9000);
}

void ov01_021FB110(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk00 * 8, bufs->unk10);
}

void ov01_021FB120(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk04 * 12, bufs->unk14);
}

void ov01_021FB134(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk08 * 4, bufs->unk04);
}

void ov01_021FB144(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk0C * 8, bufs->unk00);
}

void ov01_021FB154(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk10 * 8, bufs->unk08);
}

void ov01_021FB164(NARC *narc, Ov01FB04C_Buffers *bufs, Ov01FB04C_Counts *counts) {
    NARC_ReadFile(narc, counts->unk14 * 2, bufs->unk0C);
}

void ov01_021FB174(SysTask *task, void *data) {
    Ov01FB04C_Work *work = data;
    BOOL advance;

    if (work->unk74 == 1) {
        work->state = 2;
    }

    switch (work->state) {
    case 0:
        if (*work->unk84 != NULL) {
            advance = FALSE;
            break;
        }
        ov01_021FB04C(work->unk7C, &work->counts);
        work->unk70->unk1C = work->counts.unk10;
        ov01_021FB0B0(&work->counts, work->unk70, &work->unk6C);
        advance = TRUE;
        break;
    case 1:
        ov01_021FB110(work->unk7C, work->unk70, &work->counts);
        ov01_021FB120(work->unk7C, work->unk70, &work->counts);
        ov01_021FB134(work->unk7C, work->unk70, &work->counts);
        ov01_021FB144(work->unk7C, work->unk70, &work->counts);
        ov01_021FB154(work->unk7C, work->unk70, &work->counts);
        ov01_021FB164(work->unk7C, work->unk70, &work->counts);
        advance = TRUE;
        break;
    case 2:
        *work->unk78 = NULL;
        Heap_Free(work);
        SysTask_Destroy(task);
        return;
    }

    if (advance == TRUE) {
        work->state++;
        if (work->state == 2) {
            work->unk70->unk18 = TRUE;
        }
    }
}

Ov01FB04C_Buffers *ov01_021FB254(void) {
    Ov01FB04C_Buffers *bufs = Heap_Alloc(HEAP_ID_FIELD1, sizeof(Ov01FB04C_Buffers));

    bufs->unk10 = NULL;
    bufs->unk14 = NULL;
    bufs->unk00 = NULL;
    bufs->unk08 = NULL;
    bufs->unk0C = NULL;
    bufs->unk18 = FALSE;
    bufs->unk1C = 0;
    return bufs;
}

void ov01_021FB270(NARC *narc, u32 unused, Ov01FB04C_Buffers *bufs, u8 *buf) {
    Ov01FB04C_Counts *counts = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(Ov01FB04C_Counts));

    ov01_021FB04C(narc, counts);
    bufs->unk1C = counts->unk10;
    ov01_021FB0B0(counts, bufs, &buf);
    ov01_021FB110(narc, bufs, counts);
    ov01_021FB120(narc, bufs, counts);
    ov01_021FB134(narc, bufs, counts);
    ov01_021FB144(narc, bufs, counts);
    ov01_021FB154(narc, bufs, counts);
    ov01_021FB164(narc, bufs, counts);
    Heap_Free(counts);
    bufs->unk18 = TRUE;
}

void ov01_021FB2E8(void *ptr) {
    if (ptr != NULL) {
        Heap_Free(ptr);
    }
}

void ov01_021FB2F4(Ov01FB04C_Buffers *bufs) {
    if (bufs != NULL) {
        bufs->unk18 = FALSE;
        bufs->unk10 = NULL;
        bufs->unk14 = NULL;
        bufs->unk00 = NULL;
        bufs->unk08 = NULL;
        bufs->unk0C = NULL;
    }
}

SysTask *ov01_021FB308(NARC *narc, u32 a1, Ov01FB04C_Buffers *bufs, void **a3, u8 **a4, void **a5) {
    Ov01FB04C_Work *work = Heap_AllocAtEnd(HEAP_ID_FIELD1, sizeof(Ov01FB04C_Work));

    work->state = 0;
    work->unk7C = narc;
    work->unk80 = a1;
    work->unk70 = bufs;
    work->unk78 = a3;
    work->unk74 = 0;
    work->unk64 = 0;
    work->unk48 = 0;
    work->unk6C = *a4;
    work->unk84 = a5;
    return SysTask_CreateOnMainQueue(ov01_021FB174, work, 1);
}

void ov01_021FB354(SysTask *task) {
    Ov01FB04C_Work *work = SysTask_GetData(task);

    work->unk74 = 1;
}

void ov01_021FB360(Ov01FB04C_Buffers *bufs) {
    bufs->unk18 = FALSE;
}
