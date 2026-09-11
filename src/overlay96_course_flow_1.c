#include "global.h"

typedef struct Work {
    u8 d[0xe00];
} Work;

#define U32(w, o) (*(u32 *)((w)->d + (o)))
#define U8(w, o) ((w)->d[(o)])

typedef void (*WorkCallback)(Work *, u32);
typedef struct Ops8 {
    void *f0;
    void *f4;
    WorkCallback callback;
} Ops8;
typedef struct OpsC {
    void *f0;
    void *f4;
    void *f8;
    WorkCallback end;
} OpsC;
typedef struct Ops10 {
    void *f0;
    void *f4;
    void *f8;
    void *fc;
    void *f10;
} Ops10;
typedef BOOL (*StateCallback)(Work *, void *);

extern void *PokeathlonCourse_GetDataCopyArea(Work *);
extern void *PokeathlonCourse_GetSystem(Work *);
extern void *PokeathlonCourse_GetFieldData_AtIndex(Work *, u32);
extern u32 PokeathlonCourse_GetParticipantCount(Work *);
extern u32 PokeathlonCourse_GetUnkConstant4(Work *);
extern void PokeathlonCourse_ResetDataCopyArea(Work *);
extern BOOL PokeathlonCourse_RunSubStateLoop(Work *);
extern void PokeathlonCourse_InitStateInfo(const void *, void *);
extern void PokeathlonCourse_SetStateField07(Work *, u32);
extern void PokeathlonCourse_SetStateTransitionType(Work *, u32);
extern void ov96_021E7658(Work *, u8);
extern void ov96_021E7718(Work *);
extern BOOL ov96_021E87B4(u32, void *, void *, void *);
extern void ov96_021E87B0(void *, u32);
extern BOOL ov96_021E87EC(u32, void *, void *, void *);
extern void *ov96_021E8A20(void *);
extern void *ov96_021E9A14(void);
extern void *ov96_021E9A18(void);
extern void *ov96_021E9A1C(void);
extern u32 ov96_021E5F24(Work *);
extern BOOL ov96_021E75E4(Work *);
extern void PokeathlonCourse_SetField1F4(Work *, u32);
extern u32 sub_02031B10(void);
extern u32 sub_0203769C(void);
extern void *Save_ApricornBox_Get(void *);
extern void *Save_PlayerData_GetProfile(void *);
extern void *Save_Pokeathlon_Get(void *);
extern void *PokeathlonSave_GetUnkB00(void *);
extern void *Heap_AllocAtEnd(u32, u32);
extern u32 sub_020320E0(void *, void *, u32, u32);
extern void sub_020321A0(void *, void *, u32, u32);
extern const u8 ov96_0221A86C[];
extern const u8 ov96_0221DC24[];
extern const u8 ov96_0221A844[];
extern const u8 ov96_0221DA5C[];
extern BOOL GF_heap_c_dummy_return_true(u32);
extern void GF_AssertFail(void);
extern void Sound_SetScene(u32);
extern void Sound_SetSceneAndPlayBGM(u32, u32, u32);

u32 ov96_021E6FFC(Work *);
u32 ov96_021E6F2C(Work *);
u32 ov96_021E7030(Work *);
u32 ov96_021E7080(Work *);
u32 ov96_021E70F0(Work *);
u32 ov96_021E711C(Work *);
u32 ov96_021E7150(Work *);
u32 ov96_021E7190(Work *);
u32 ov96_021E7268(Work *);
u32 ov96_021E7294(Work *);
u32 ov96_021E72CC(Work *);
u32 ov96_021E7320(Work *);
u32 ov96_021E73F8(Work *);
u32 ov96_021E74AC(Work *);
u32 ov96_021E74E0(Work *);
u32 ov96_021E7514(Work *);
u32 ov96_021E7544(Work *);
u32 ov96_021E7590(Work *);

u32 ov96_021E6FFC(Work *w) {
    void *data = PokeathlonCourse_GetDataCopyArea(w);
    void *desc = ov96_021E9A14();
    void *system = PokeathlonCourse_GetSystem(w);
    if (ov96_021E87B4(0x1e, (u8 *)data + 0x28, desc, system)) {
        PokeathlonCourse_SetStateField07(w, 0x26);
    }
    return 0;
}

u32 ov96_021E7030(Work *w) {
    u16 *src = ov96_021E8A20(w->d + 0x37c);
    u16 *dst = (u16 *)(w->d + 0x5f0);
    u32 n = 0x12;
    do {
        *dst++ = *src++;
    } while (--n != 0);
    if (((Ops8 *)U32(w, 0x1e0))->callback != NULL) {
        ((Ops8 *)U32(w, 0x1e0))->callback(w, 0);
    }
    ov96_021E7658(w, (u8)U32(w, 0x1f0));
    PokeathlonCourse_SetStateField07(w, 0x17);
    return 0;
}

u32 ov96_021E7080(Work *w) {
    if (!GF_heap_c_dummy_return_true(0x5c)) {
        GF_AssertFail();
    }
    ((OpsC *)U32(w, 0x1e0))->end(w, 0);
    if (U32(w, 0x1e4) != 0) {
        GF_AssertFail();
    }
    if ((s32)U32(w, 0x1f0) < U8(w, 0x72a)) {
        if (((Ops8 *)U32(w, 0x1e0))->callback != NULL) {
            PokeathlonCourse_SetStateField07(w, 0x19);
        } else {
            PokeathlonCourse_SetStateField07(w, 0x18);
        }
    } else {
        U32(w, 0x1f0)++;
        PokeathlonCourse_SetStateField07(w, 0x1d);
    }
    return 0;
}

u32 ov96_021E70F0(Work *w) {
    U32(w, 0x1f0)++;
    if ((s32)U32(w, 0x1f0) >= U8(w, 0x72a)) {
        PokeathlonCourse_SetStateField07(w, 0x1d);
    } else {
        PokeathlonCourse_SetStateField07(w, 0xb);
    }
    return 0;
}

u32 ov96_021E711C(Work *w) {
    U32(w, 0x1e0) = (u32)ov96_0221A86C;
    U8(w, 0x1ed) = 0;
    PokeathlonCourse_InitStateInfo(ov96_0221DC24, w->d + 0x3cc);
    PokeathlonCourse_SetStateField07(w, 0x1a);
    return 0;
}

u32 ov96_021E7150(Work *w) {
    if (PokeathlonCourse_RunSubStateLoop(w)) {
        u8 *data = PokeathlonCourse_GetDataCopyArea(w);
        data[0x24] = 0;
        data[0x4c] = 1;
        ov96_021E87B0(PokeathlonCourse_GetSystem(w), 1);
        PokeathlonCourse_SetStateTransitionType(w, 0xb);
        PokeathlonCourse_SetStateField07(w, 0x1b);
    }
    return 0;
}

u32 ov96_021E7190(Work *w) {
    StateCallback *callbacks;
    if (U32(w, 0x3cc) == 0) {
        PokeathlonCourse_SetStateField07(w, 0x1c);
        return 0;
    }
    if ((void *)U32(w, 0x3b4) == w->d + 0x3c4) {
        U32(w, 0x3b4) = (u32)(w->d + 0x3cc);
        U32(w, 0x3c0) = 0;
    }
    callbacks = (StateCallback *)U32(w, 0x3cc);
    if (callbacks[U8(w, 0x3d2)](w, w->d + 0x3d1)) {
        PokeathlonCourse_SetField1F4(w, 0);
        U32(w, 0x3b4) = (u32)(w->d + 0x3c4);
        U32(w, 0x3c0) = 0;
        PokeathlonCourse_SetStateField07(w, 0x1c);
    } else if (!ov96_021E5F24(w)) {
        ov96_021E87B4(0x1b, w->d + 0x2b4, ov96_021E9A14(), (void *)U32(w, 0x288));
        u8 *dst = ov96_021E8A20(w->d + 0x2dc);
        u8 *src = ov96_021E8A20(w->d + 0x28c);
        u32 n = 0x28;
        do {
            *dst++ = *src++;
        } while (--n != 0);
    } else {
        ov96_021E87B4(0x1b, w->d + 0x28c, ov96_021E9A14(), (void *)U32(w, 0x288));
    }
    return 0;
}

u32 ov96_021E7268(Work *w) {
    ((OpsC *)U32(w, 0x1e0))->end(w, 0);
    if (U32(w, 0x1e4) != 0) {
        GF_AssertFail();
    }
    PokeathlonCourse_SetStateField07(w, 0x18);
    return 0;
}

u32 ov96_021E7294(Work *w) {
    PokeathlonCourse_ResetDataCopyArea(w);
    U32(w, 0x1e0) = (u32)ov96_0221A844;
    U8(w, 0x1ed) = 0;
    PokeathlonCourse_InitStateInfo(ov96_0221DA5C, w->d + 0x3cc);
    PokeathlonCourse_SetStateField07(w, 0x20);
    return 0;
}

u32 ov96_021E72CC(Work *w) {
    if (PokeathlonCourse_RunSubStateLoop(w)) {
        u8 *data = PokeathlonCourse_GetDataCopyArea(w);
        data[0x24] = 0;
        data[0x4c] = 1;
        ov96_021E87B0(PokeathlonCourse_GetSystem(w), 1);
        PokeathlonCourse_SetStateTransitionType(w, 0xc);
        PokeathlonCourse_SetStateField07(w, 0x21);
        Sound_SetScene(0);
        Sound_SetSceneAndPlayBGM(0x19, 0x474, 0);
    }
    return 0;
}

u32 ov96_021E7320(Work *w) {
    StateCallback *callbacks;
    if (U32(w, 0x3cc) == 0) {
        PokeathlonCourse_SetStateField07(w, 0x22);
        return 0;
    }
    if ((void *)U32(w, 0x3b4) == w->d + 0x3c4) {
        U32(w, 0x3b4) = (u32)(w->d + 0x3cc);
        U32(w, 0x3c0) = 0;
    }
    callbacks = (StateCallback *)U32(w, 0x3cc);
    if (callbacks[U8(w, 0x3d2)](w, w->d + 0x3d1)) {
        PokeathlonCourse_SetField1F4(w, 0);
        U32(w, 0x3b4) = (u32)(w->d + 0x3c4);
        U32(w, 0x3c0) = 0;
        PokeathlonCourse_SetStateField07(w, 0x22);
    } else if (!ov96_021E5F24(w)) {
        ov96_021E87B4(0x1b, w->d + 0x2b4, ov96_021E9A14(), (void *)U32(w, 0x288));
        u8 *dst = ov96_021E8A20(w->d + 0x2dc);
        u8 *src = ov96_021E8A20(w->d + 0x28c);
        u32 n = 0x28;
        do {
            *dst++ = *src++;
        } while (--n != 0);
    } else {
        ov96_021E87B4(0x1b, w->d + 0x28c, ov96_021E9A14(), (void *)U32(w, 0x288));
    }
    return 0;
}

u32 ov96_021E73F8(Work *w) {
    void *box;
    void *profile;
    void *pokeathlon;
    u32 size;
    ((OpsC *)U32(w, 0x1e0))->end(w, 0);
    if (U32(w, 0x1e4) != 0) {
        GF_AssertFail();
    }
    box = Save_ApricornBox_Get(*(void **)U32(w, 0x1f8));
    profile = Save_PlayerData_GetProfile(*(void **)U32(w, 0x1f8));
    pokeathlon = PokeathlonSave_GetUnkB00(Save_Pokeathlon_Get(*(void **)U32(w, 0x1f8)));
    size = sub_02031B10() * 4;
    U32(w, 0xd68) = (u32)Heap_AllocAtEnd(U32(w, 0x284), size);
    memset((void *)U32(w, 0xd68), 0, size);
    U32(w, 0xd64) = sub_020320E0(box, profile, U32((Work *)pokeathlon, 0x70), U32(w, 0x284));
    if (*(u32 *)((u8 *)U32(w, 0x1f8) + 4) == 1) {
        PokeathlonCourse_SetStateTransitionType(w, 0xe);
        PokeathlonCourse_SetStateField07(w, 0x23);
    } else {
        PokeathlonCourse_SetStateField07(w, 0x25);
    }
    return 0;
}

u32 ov96_021E74AC(Work *w) {
    ov96_021E5F24(w);
    if (ov96_021E87EC(0x1f, w->d + 0xb44, ov96_021E9A18(), (void *)U32(w, 0x288))) {
        PokeathlonCourse_SetStateField07(w, 0x26);
    }
    return 0;
}

u32 ov96_021E74E0(Work *w) {
    void *data = PokeathlonCourse_GetFieldData_AtIndex(w, 0);
    void *desc = ov96_021E9A1C();
    void *system = PokeathlonCourse_GetSystem(w);
    if (ov96_021E87EC(0x20, data, desc, system)) {
        PokeathlonCourse_SetStateField07(w, 0x26);
    }
    return 0;
}

u32 ov96_021E7514(Work *w) {
    u32 size = sub_02031B10();
    if (ov96_021E87EC(0x21, (void *)U32(w, 0xd64), (void *)size, (void *)U32(w, 0x288))) {
        PokeathlonCourse_SetStateField07(w, 0x26);
    }
    return 0;
}

u32 ov96_021E7544(Work *w) {
    void *box = Save_ApricornBox_Get(*(void **)U32(w, 0x1f8));
    u32 count = PokeathlonCourse_GetParticipantCount(w);
    u32 value = sub_0203769C();
    sub_020321A0(box, (void *)U32(w, 0xd68), count, value);
    if (!GF_heap_c_dummy_return_true(0x5c)) {
        GF_AssertFail();
    }
    PokeathlonCourse_SetStateField07(w, 0x25);
    return 0;
}

u32 ov96_021E7590(Work *w) {
    if (!GF_heap_c_dummy_return_true(0x5c)) {
        GF_AssertFail();
    }
    if (((u8 *)U32(w, 0x1f8))[0xe] == 0) {
        ov96_021E7718(w);
    }
    return 1;
}
