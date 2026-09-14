#include "to47_overlay49_object_pool_r6_private.h"

void ov49_02258C28(void *p, int value) {
    u16 coords[2];
    if (!ov49_022589D8(PTR(p, 0x14), 3, &coords[1], &coords[0], 0)) {
        GF_AssertFail();
    }
    ov49_02258C5C(p, value, coords[1], coords[0]);
}

void *ov49_02258C5C(void *p, int id, int x, int y) {
    SolCfg6 cfg;
    void *obj = ov49_022593C0(p);
    cfg.x = x << 4;
    cfg.y = y << 4;
    cfg.id = id;
    cfg.a = 0;
    cfg.b = 0;
    if (U16(p, 0xE) == 0) {
        cfg.c = 0;
    } else {
        cfg.c = 0x61;
    }
    PTR(obj, 0) = ov42_022280B8(PTR(p, 0), &cfg);
    PTR(obj, 4) = ov45_0223070C(PTR(p, 4), PTR(obj, 0));
    PTR(p, 0x20) = obj;
    ov49_02258EEC(p, obj, 0);
    return obj;
}

void *ov49_02258CB8(void *p, int id, int value) {
    SolCfg6 cfg;
    u16 coords[2];
    void *obj;
    void *check;
    u16 i;
    BOOL found;

    obj = ov49_022593C0(p);
    found = FALSE;
    i = 0;
    do {
        if (!ov49_022589D8(PTR(p, 0x14), id + 4, &coords[1], &coords[0], i)) {
            return NULL;
        }
        check = ov49_02258DAC(p);
        if (check == NULL) {
            found = TRUE;
        } else if (!ov49_02258FDC(check, coords[1], coords[0])) {
            found = TRUE;
        }
        i++;
    } while (!found);

    cfg.x = coords[1] << 4;
    cfg.y = coords[0] << 4;
    cfg.id = id;
    cfg.a = 0;
    cfg.b = 1;
    cfg.c = value;
    PTR(obj, 0) = ov42_022280B8(PTR(p, 0), &cfg);
    PTR(obj, 4) = ov45_0223070C(PTR(p, 4), PTR(obj, 0));
    ov49_02258EEC(p, obj, 0);
    return obj;
}

void ov49_02258D54(void *p) {
    ov45_02230884(PTR(p, 4));
    ov42_02228100(PTR(p, 0));
    memset(p, 0, 0x28);
}

void *ov49_02258D70(void *p, int target) {
    int i;
    void *obj;
    int result;
    for (i = 0; i < U16(p, 0xC); i++) {
        obj = PTR(PTR(p, 8), i * 0x28);
        if (obj != 0) {
            result = ov42_02228188(obj, 4);
            if (result == target) {
                return (u8 *)PTR(p, 8) + 0x28 * i;
            }
        }
    }
    return 0;
}
