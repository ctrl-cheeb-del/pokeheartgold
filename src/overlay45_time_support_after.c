#include <nitro/rtc.h>

#include "global.h"

typedef struct R28State {
    void *manager;
    u32 slots[13];
    u8 active;
    u8 unk39;
    u16 heapId;
    void *context;
    void *field40;
    void *field44;
} R28State;
typedef struct R28Place {
    u16 country;
    u8 region;
    u8 value : 4;
    u8 occupied : 4;
} R28Place;
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void GF_AssertFail(void);
extern void ov45_0222CDC4(R28State *, void **, const void *);
extern u8 ov45_02254B44[];
extern u8 ov45_02254BB4[];
extern int ov45_0222A33C(void *);
extern void ov45_0222CE2C(R28State *, u32);
extern int LocationGmmDatRegionCountGetByCountryMsgNo(int);
extern void ov45_0222D638(R28Place *, u32, u32, u32);
extern int ov00_021E6A70(u32, u32);
extern int sub_020393C8(void);
extern int sub_020397FC(void);
extern void ov45_0222DE1C(void *);
extern void ov45_0222DF78(void *, u32);
extern void ov45_0222DFD0(void *);
extern void ov45_0222E000(void *);
extern void ov45_0222DEA4(void *, u32);

void ov45_0222D44C(R28State *, void **, u32);
void ov45_0222D484(R28State *, void **, u32);
void ov45_0222D4C0(void **);
void ov45_0222D4CC(R28State *, void **);
int ov45_0222D4DC(R28State *);
void ov45_0222D500(u8 *, const s64 *);
void ov45_0222D524(const u32 *, const u32 *, u8 *);

void ov45_0222D638(R28Place *, u32, u32, u32);
u16 ov45_0222D6B0(R28Place *, u32);
u8 ov45_0222D6D4(R28Place *, u32);
u8 ov45_0222D6FC(R28Place *, u32);
u8 ov45_0222D724(R28Place *, u32);
void ov45_0222D740(void *);
BOOL ov45_0222D79C(u32, u32);
u8 ov45_0222D7C0(u32);
int ov45_0222D7CC(u32, u32);
BOOL ov45_0222D7FC(u32, u32);
BOOL ov45_0222D844(void);
void *ov45_0222D860(u32);
void ov45_0222D890(void *);
void ov45_0222D8A4(void *);

void ov45_0222D638(R28Place *places, u32 country, u32 region, u32 value) {
    s32 i;
    BOOL use;
    if (country == 0) {
        return;
    }
    if (region > (u32)LocationGmmDatRegionCountGetByCountryMsgNo(country)) {
        return;
    }
    use = FALSE;
    for (i = 0; i < 50; i++) {
        if (places[i].occupied == 0) {
            use = TRUE;
        } else if (places[i].country == country && places[i].region == region) {
            if (value == 1) {
                return;
            }
            use = TRUE;
        }
        if (use) {
            places[i].country = country;
            places[i].region = region;
            places[i].value = value;
            places[i].occupied = 1;
            return;
        }
    }
}

u16 ov45_0222D6B0(R28Place *p, u32 i) {
    if (i >= 50) {
        GF_AssertFail();
    }
    p += i;
    if (p->occupied != 1) {
        GF_AssertFail();
    }
    return p->country;
}
u8 ov45_0222D6D4(R28Place *p, u32 i) {
    if (i >= 50) {
        GF_AssertFail();
    }
    if (p[i].occupied != 1) {
        GF_AssertFail();
    }
    return p[i].region;
}
u8 ov45_0222D6FC(R28Place *p, u32 i) {
    if (i >= 50) {
        GF_AssertFail();
    }
    p += i;
    if (p->occupied != 1) {
        GF_AssertFail();
    }
    return p->value;
}
u8 ov45_0222D724(R28Place *p, u32 i) {
    if (i >= 50) {
        GF_AssertFail();
    }
    return p[i].occupied;
}
void ov45_0222D740(void *file) {
    NNSG3dResMdlSet *set = NNS_G3dGetMdlSet(file);
    NNSG3dResMdl *mat = NNS_G3dGetMdlByIdx(set, 0);
    NNSi_G3dModifyMatFlag(mat, FALSE, NNS_G3D_MATFLAG_DIFFUSE);
    NNSi_G3dModifyMatFlag(mat, FALSE, NNS_G3D_MATFLAG_AMBIENT);
    NNSi_G3dModifyMatFlag(mat, FALSE, NNS_G3D_MATFLAG_SPECULAR);
    NNSi_G3dModifyMatFlag(mat, FALSE, NNS_G3D_MATFLAG_EMISSION);
}
BOOL ov45_0222D79C(u32 country, u32 region) {
    u32 n = LocationGmmDatRegionCountGetByCountryMsgNo(country);
    if (n == 0 && region == 0) {
        return TRUE;
    }
    if (region >= 1 && region <= n) {
        return TRUE;
    }
    return FALSE;
}
u8 ov45_0222D7C0(u32 i) {
    return ov45_02254BB4[i];
}
int ov45_0222D7CC(u32 a, u32 b) {
    int r = ov00_021E6A70(a, b);
    if (r == 11 || a == 25) {
        if (b != 2) {
            return 14;
        }
        return 11;
    }
    if (a == 26) {
        return 13;
    }
    if (r < 0) {
        r = 11;
    }
    return r;
}
BOOL ov45_0222D7FC(u32 a, u32 b) {
    int r = ov00_021E6A70(a, b);
    if (a == 25) {
        r = 11;
    } else if (a == 26) {
        r = 12;
    }
    switch (r) {
    case 1:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 11:
        return FALSE;
    default:
        return TRUE;
    }
}
BOOL ov45_0222D844(void) {
    if (sub_020393C8() || sub_020397FC()) {
        return TRUE;
    }
    return FALSE;
}
void *ov45_0222D860(u32 heap) {
    u8 *p = Heap_Alloc(heap, 0x230);
    memset(p, 0, 0x230);
    ov45_0222DE1C(p + 8);
    ov45_0222DF78(p + 0x5c, heap);
    return p;
}
void ov45_0222D890(void *p) {
    ov45_0222DFD0((u8 *)p + 0x5c);
    Heap_Free(p);
}
void ov45_0222D8A4(void *p) {
    ov45_0222E000((u8 *)p + 0x5c);
    ov45_0222DEA4((u8 *)p + 8, 0);
}
