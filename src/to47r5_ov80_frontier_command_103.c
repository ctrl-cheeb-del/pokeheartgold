#include "to47r5_ov80_frontier_command_103_private.h"

int FrtCmd_103(void *c) {
    u8 cmd;
    u8 b;
    void *data;
    void *map;
    int c3;
    u16 *dest;

    cmd = READ_U8(c);
    b = READ_U8(c);
    c3 = READ_U8(c);
    dest = FrontierScript_ReadVarPtr(c);
    data = Frontier_GetData(SYS(c));
    map = FrontierSystem_GetFrontierMap(PTR(c, 0));

    switch (cmd) {
    case 0:
        U8(data, 7) = b;
        break;
    case 1:
        U8(data, 5) = b;
        break;
    case 2:
        U8(data, 4) = b;
        break;
    case 3:
        *dest = U16((u8 *)data + b * 2, 0x4dc);
        break;
    case 4:
        *dest = U16(data, 0xc);
        break;
    case 5: {
        u16 v = U16(data, 0xc);
        if (v < 9999) {
            U16(data, 0xc) = v + 1;
        }
        break;
    }
    case 7:
        OS_ResetSystem(0);
        break;
    case 9:
        *dest = sub_0203095C(PTR(data, 0x4f4));
        break;
    case 10:
        ov80_0223049C(data, 2);
        break;
    case 14:
        *dest = ov80_02230784(data);
        break;
    case 15:
        *dest = ((Bits11 *)((u8 *)data + b * 0x38 + 0x3f0))->lo;
        break;
    case 16: {
        u8 *p = (u8 *)data + b * 0x38;
        p += c3 * 2;
        *dest = U16(p, 0x3f4);
        break;
    }
    case 17: {
        void *mon = AllocMonZeroed(11);
        ov80_0222A140((u8 *)data + 0x3f0 + b * 0x38, mon, ov80_02237120(data));
        *dest = GetMonData(mon, 0xb1, NULL);
        Heap_Free(mon);
        break;
    }
    case 18: {
        int n;
        int i;
        int types[18];
        int j;
        int zero;
        int *p;
        void *mon;
        int type1;
        int type2;
        int best;

        n = ov80_02236DF8(U8(data, 4), 1);
        j = 0;
        zero = j;
        p = types;
        do {
            j++;
            *p = zero;
            p++;
        } while (j < 18);
        mon = AllocMonZeroed(11);
        for (i = 0; i < n; i++) {
            ov80_0222A140(((Rec38 *)((u8 *)data + 0x3f0)) + i, mon, ov80_02237120(data));
            type1 = GetMonData(mon, 0xb1, NULL);
            type2 = GetMonData(mon, 0xb2, NULL);
            if (type1 == type2) {
                type2 = 0xff;
            }
            types[type1]++;
            if (type2 != 0xff) {
                types[type2]++;
            }
        }
        Heap_Free(mon);
        best = 0;
        for (j = 0; j < 18; j++) {
            if (types[best] < types[j]) {
                best = j;
            }
        }
        if (types[best] <= 1) {
            *dest = 0xff;
        } else {
            *dest = best;
        }
        break;
    }
    case 19:
        *dest = ov80_022372B4(data);
        break;
    case 20:
        *dest = ov80_02230794(data, b);
        break;
    case 21:
        ov80_022307C8(data);
        break;
    case 22:
        ov80_022307D4(data);
        break;
    case 23:
        *dest = ov80_02230790(data);
        break;
    case 24:
        *dest = U8(data, 0x57c);
        break;
    case 26:
        *dest = U8(data, 0x57d);
        break;
    case 27:
        sub_02096910(data);
        break;
    case 28:
        *dest = ov80_02237254(U8(data, 4));
        break;
    case 29:
        *dest = U8(data, 4);
        break;
    case 30:
        BgTilemapRectChangePalette(PTR(map, 0), 3, 3, 10, 26, 11, b);
        ScheduleBgTilemapBufferTransfer(PTR(map, 0), 3);
        break;
    case 31:
        PTR(data, 0x500) = SysTask_CreateOnMainQueue(ov80_0222FC08, FrontierSystem_GetFrontierMap(PTR(c, 0)), 5);
        break;
    case 32:
        if (PTR(data, 0x500) != NULL) {
            SysTask_Destroy(PTR(data, 0x500));
            PTR(data, 0x500) = NULL;
        }
        break;
    case 33:
        ov80_0222A474((u8 *)data + 0x34, U16((u8 *)data + U8(data, 6) * 2, 0x18), 11, 204);
        ov80_0222A474((u8 *)data + 0x144, U16((u8 *)data + (U8(data, 6) + 7) * 2, 0x18), 11, 204);
        break;
    case 34: {
        int n = ov80_02236DD4(U8(data, 4));
        int i;
        for (i = 0; i < n; i++) {
            BufferBoxMonSpeciesName(PTR(PTR(c, 0), 0x44), i, Mon_GetBoxMon(Party_GetMonByIndex(PTR(data, 0x4d4), i)));
        }
        break;
    }
    case 35:
        *dest = ov80_02230B4C(data);
        break;
    case 36:
        ov80_02230AE4(data);
        break;
    case 37:
        *dest = 0;
        if (U8(data, 4) == 0) {
            int v = U16(data, 0xc) + 1;
            if (v == 21) {
                *dest = 1;
            } else if (v == 49) {
                *dest = 2;
            }
        }
        break;
    case 38:
        ov80_022371B0(data);
        break;
    case 39:
        ov80_0222A52C((u8 *)data + 0x3f0, (u8 *)data + 0x3d2, (u8 *)data + 0x3da, (u8 *)data + 0x3e0, 0, 4, 11, 205);
        break;
    case 40:
        ov80_02237130(data);
        break;
    case 41:
        *dest = U8(data, 0xb);
        U8(data, 0xb) = 1;
        break;
    }
    return 0;
}
