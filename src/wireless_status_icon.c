#include "wireless_status_icon_internal.h"

UnkStruct_0203A3B0 *sub_0203A3B0(int a0, enum HeapID heapId, int a2, int a3, int a4, void *a5, int a6, int a7) {
    UnkStruct_0203A3B0 *p;

    sub_0203A4D4(a6, a4, a7, heapId);
    sub_0203A59C(a6, a4, heapId);
    p = Heap_AllocAtEnd(heapId, sizeof(UnkStruct_0203A3B0));
    p->unk18 = SysTask_CreateOnVWaitQueue(sub_0203A42C, p, 5);
    p->unk0C = a2;
    p->unk0E = a3;
    p->unk00 = 0;
    p->unk20 = a7 / 32;
    p->unk21 = a6;
    p->unk22 = 0;
    p->unk04 = 3;
    p->unk14 = a5;
    p->unk08 = 0;
    p->unk10 = a4;
    p->unk12 = 0;
    p->unk11 = 0;
    p->unk1C = (UnkOamRegs *)0x07000000;
    return p;
}

void sub_0203A42C(SysTask *task, void *data) {
    sub_0203A700(data);
}

void sub_0203A438(UnkStruct_0203A3B0 *p, s32 a1) {
    if (a1 < 4) {
        p->unk04 = a1;
        p->unk08 = 0;
    }
}

void sub_0203A444(UnkStruct_0203A3B0 *p) {
    SysTask_Destroy(p->unk18);
    ((UnkOamRegs *)0x07000000)->unk00 = 0x40000200;
    ((UnkOamRegs *)0x07000000)->unk04 = 0;
    if (p->unk12 != 0) {
        ((UnkOamRegs *)0x07000400)->unk00 = 0x40000200;
        ((UnkOamRegs *)0x07000400)->unk04 = 0;
    }
    Heap_Free(p);
}

void sub_0203A478(UnkStruct_0203A3B0 *p, int a1, enum HeapID a2) {
    sub_0203A4D4(2, p->unk10, 0x1C0, a2);
    sub_0203A59C(2, p->unk10, a2);
    if (a1 != 0) {
        p->unk11 = 1;
    } else {
        p->unk11 = 2;
    }
    p->unk12 = 1;
}

void *sub_0203A4AC(enum HeapID heapId) {
    void *buf;

    buf = Heap_AllocAtEnd(heapId, 0x258);
    sub_0201A3F8(_0210F930, &buf);
    DC_FlushRange(buf, 0x258);
    return buf;
}

void sub_0203A4D4(int engine, int a1, u32 plttBase, enum HeapID heapId) {
    void *buf;
    NNSG2dPaletteData *plttData;

    buf = Heap_AllocAtEnd(heapId, 0x258);
    if (buf != NULL) {
        sub_0201A3F8(_0210F930, &buf);
        DC_FlushRange(buf, 0x258);
        NNS_G2dGetUnpackedPaletteData(buf, &plttData);
        if (engine == 1) {
            GX_LoadOBJPltt(plttData->pRawData, plttBase, 0x20);
        } else {
            GXS_LoadOBJPltt(plttData->pRawData, plttBase, 0x20);
        }
        Heap_Free(buf);
    }
}

NNSG2dCharacterData *sub_0203A534(int a0, u32 bank, u32 sz, void *buf) {
    NNSG2dCharacterData *charData;

    if (a0 != 0) {
        GF_ASSERT(bank != 0x00300010);
        sub_0201A3F8(_0210F940, &buf);
    } else if (bank != 0x00300010) {
        sub_0201A3F8(_0210F954, &buf);
        DC_FlushRange(buf, 0x258);
    } else {
        sub_0201A3F8(_0210F964, &buf);
        DC_FlushRange(buf, 0x4C0);
    }
    NNS_G2dGetUnpackedBGCharacterData(buf, &charData);
    return charData;
}

void sub_0203A59C(int engine, int a1, enum HeapID heapId) {
    s32 bank;
    u32 offs;
    NNSG2dCharacterData *charData;
    void *buf;

    if (engine == 1) {
        bank = *(u32 *)0x04000000 & 0x00300010;
        offs = GX_GetBankForOBJ();
    } else {
        bank = *(u32 *)0x04001000 & 0x00300010;
        offs = GX_GetBankForSubOBJ();
    }
    if (bank == 0x00300010) {
        buf = Heap_AllocAtEnd(heapId, 0x4C0);
    } else {
        buf = Heap_AllocAtEnd(heapId, 0x258);
    }
    if (buf == NULL) {
        return;
    }
    charData = sub_0203A534(a1, bank, heapId, buf);
    switch (bank) {
    case 0x10:
        if (offs == 0x40 || offs == 0x20) {
            offs = 0x3E00;
        } else {
            offs = 0x7E00;
        }
        break;
    case 0x00100010:
        if (offs == 0x40 || offs == 0x20 || offs == (0x00100010 >> 12)) {
            offs = 0x3E00;
        } else {
            offs = 0xFE00;
        }
        break;
    case 0x00200010:
        if (offs == 0x30 || offs == 0x50) {
            offs = 0x00013E00;
        } else if (offs == 0x10) {
            offs = 0xFE00;
        } else {
            offs = 0x0001FE00;
        }
        break;
    case 0x00300010:
        offs = 0x3FC00;
        break;
    default:
        offs = 0xFE00;
        break;
    }
    if (engine == 1) {
        if (bank != 0x00300010) {
            DC_FlushRange(charData->pRawData, 0x200);
            GX_LoadOBJ(charData->pRawData, offs, 0x200);
        } else {
            DC_FlushRange(charData->pRawData, 0x400);
            GX_LoadOBJ(charData->pRawData, offs, 0x400);
        }
    } else {
        if (bank != 0x00300010) {
            DC_FlushRange(charData->pRawData, 0x200);
            GXS_LoadOBJ(charData->pRawData, offs, 0x200);
        } else {
            DC_FlushRange(charData->pRawData, 0x400);
            GXS_LoadOBJ(charData->pRawData, 0x3C00, 0x400);
        }
    }
    Heap_Free(buf);
}
