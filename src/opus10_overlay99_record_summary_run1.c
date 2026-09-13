#include "global.h"

typedef struct Ov99Summary {
    void *profile;   // 0x00
    u16 courseTotal; // 0x04
    u16 unk06;       // 0x06
    u16 total;       // 0x08
    u16 unk0A;       // 0x0A
    u16 courses[5];  // 0x0C
    u8 unk16;        // 0x16
    u8 unk17;        // 0x17
    u8 gender;       // 0x18
} Ov99Summary;       // size 0x1C

typedef struct Ov99Work {
    Ov99Summary *summary; // 0x00
    void *unk04;          // 0x04
    void *unk08;          // 0x08
    int heapId;           // 0x0C
    void *text;           // 0x10
    void *sprites;        // 0x14
    void *sprite[128];    // 0x18
} Ov99Work;

typedef struct Ov99SpriteTemplate {
    s16 x;
    s16 y;
    s16 z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} Ov99SpriteTemplate; // size 0x34

typedef struct Ov99CourseRecord {
    u8 unk00[6];
    u16 score;
    u8 unk08[0x24];
} Ov99CourseRecord; // size 0x2C

typedef struct Ov99Params {
    void *save;    // 0x00
    void *profile; // 0x04
} Ov99Params;

extern void GF_AssertFail(void);
extern void *Heap_Alloc(int, u32);
extern void MI_CpuCopy8(const void *, void *, u32);
extern void MI_CpuFill8(void *, u8, u32);
extern u32 MATH_CountPopulation(u32);

extern void *ov98_0221E6E0(void *, const void *);
extern void ov98_0221E6F0(void *, void **, const int *, u32, u32, s16, s16, BOOL);
extern void ov98_0221EBD8(void *, u32, u32, u32);
extern void ov98_0221EBEC(void *, u32, u32, u32, u8, u32);
extern void ov98_0221EC08(void *, u32, u32, u32, u8);
extern void ov98_0221ECD0(void *, u32, u32, s32, u32, u32);
extern void *ov98_0221EEFC(void *);
extern u8 ov98_0221EF80(s32);
extern u32 ov98_0221F024(const void *);
extern u8 ov98_0221F058(const void *);
extern u32 ov98_0221F120(u32, u32);
extern u8 ov98_0221F150(s32);

extern void ManagedSprite_SetAnim(void *, int);
extern void ManagedSprite_SetAnimateFlag(void *, BOOL);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void ManagedSprite_SetPaletteOverride(void *, int);

extern void BufferPlayersName(void *, u32, void *);
extern u8 PlayerProfile_GetTrainerGender(void *);
extern u16 *PokeathlonSave_GetUnkAEC(void *);
extern void *PokeathlonSave_GetUnkDC(void *);
extern void *PokeathlonSave_GetRecordsSolo(void *);
extern Ov99CourseRecord *PokeathlonSave_dummy1(void *);

extern void ov99_021E6C14(Ov99Work *);
extern u8 ov99_021E7068(const void *);
extern u8 ov99_021E7078(const void *);
extern u8 ov99_021E7088(const void *);
extern void *ov99_021E7098(const void *);
extern u16 ov99_021E70A8(const void *);
extern u16 ov99_021E70B8(const void *);
extern u16 ov99_021E70C8(const void *);
extern u16 ov99_021E70D8(const void *);
extern int ov99_021E7100(int);
extern int ov99_021E7124(Ov99Work *);

extern const int ov99_021E9D8C[];
extern const int ov99_021E9DAC[];
extern const int ov99_021E9DBC[];
extern const int ov99_021E9DD4[];

void ov99_021E6C30(Ov99Work *w, s32 value, u32 index, u32 count, s16 x, s16 y, u8 spacing, BOOL mainScreen);
void ov99_021E6CF4(Ov99Work *w, u32 value);
void ov99_021E6D14(Ov99Work *w, u32 value);
void ov99_021E6D34(Ov99Work *w);
u16 ov99_021E6F70(void *save);
u16 ov99_021E6FA0(const u8 *bits);
void ov99_021E6FD0(Ov99Work *w, Ov99Params *params);

void ov99_021E6C30(Ov99Work *w, s32 value, u32 index, u32 count, s16 x, s16 y, u8 spacing, BOOL mainScreen) {
    Ov99SpriteTemplate template = { 0 };
    u32 i;
    u32 digits = ov98_0221F150(value);

    for (i = 0; i < count; i++) {
        void *sprite;
        template.animation = ov98_0221F120(value, (u8)(count - i));
        MI_CpuCopy8(mainScreen ? ov99_021E9DBC : ov99_021E9DD4, template.resIdList, sizeof(template.resIdList));
        template.vram = mainScreen ? NNS_G2D_VRAM_TYPE_2DMAIN : NNS_G2D_VRAM_TYPE_2DSUB;
        template.x = x + i * spacing;
        template.y = y;
        sprite = ov98_0221E6E0(w->sprites, &template);
        w->sprite[index + i] = sprite;
        ManagedSprite_SetAnimateFlag(sprite, TRUE);
        if (count - digits > i) {
            ManagedSprite_SetDrawFlag(w->sprite[index + i], FALSE);
        }
    }
}

void ov99_021E6CF4(Ov99Work *w, u32 value) {
    if (value > 40) {
        GF_AssertFail();
    }
    ov98_0221EBD8(w->text, 6, value / 2 + 0x21, 0);
}

void ov99_021E6D14(Ov99Work *w, u32 value) {
    if (value > 10) {
        GF_AssertFail();
    }
    ov98_0221EBD8(w->text, 9, value + 0x11, 0);
}

void ov99_021E6D34(Ov99Work *w) {
    void *msgFormat;
    int gender;
    int stat0A;
    int stat06;
    int stat04;
    int stat08;
    int countA;
    int countB;
    int countC;
    int countD;
    u8 total;

    stat04 = ov99_021E70C8(w->summary);
    stat06 = ov99_021E70B8(w->summary);
    stat0A = ov99_021E70A8(w->summary);
    stat08 = ov99_021E70D8(w->summary);
    gender = ov99_021E7088(w->summary);
    countA = ov99_021E7124(w);
    countB = ov98_0221EF80(ov99_021E7078(w->summary));
    countC = ov99_021E7068(w->summary);
    countD = ov99_021E7100(stat08);
    total = countA + countB + countC + countD;

    msgFormat = ov98_0221EEFC(w->text);
    BufferPlayersName(msgFormat, 0, ov99_021E7098(w->summary));
    ov98_0221EC08(w->text, 0, 0xB, 1, 0);
    ov98_0221EBD8(w->text, 1, 0xC, 0);
    ov98_0221EBD8(w->text, 2, 0xD, 0);
    ov98_0221EBD8(w->text, 3, 0xE, 0);
    ov98_0221EBD8(w->text, 4, 0xF, 0);
    ov98_0221EC08(w->text, 5, 0x20, 2, 0);
    ov98_0221EBEC(w->text, 7, 0, 1, 0, 4);
    ov99_021E6CF4(w, total);
    ov98_0221EBD8(w->text, 8, 0x10, 0);
    ov98_0221EBD8(w->text, 0xD, 0x1F, 0);
    ov98_0221EBD8(w->text, 0xE, 1, 0);
    ov98_0221ECD0(w->text, 0xA, 0x1C, stat04, 4, 0);
    ov98_0221ECD0(w->text, 0xB, 0x1D, stat06, 4, 0);
    ov98_0221ECD0(w->text, 0xC, 0x1E, stat0A, 4, 0);
    ov99_021E6D14(w, countD);
    ov99_021E6C14(w);
    if (gender == 1) {
        ManagedSprite_SetAnim(w->sprite[0], 1);
        ManagedSprite_SetPaletteOverride(w->sprite[0], 1);
    }
    ov99_021E6C30(w, total, 1, 2, 0xC8, 0x70, 0x20, TRUE);
    ov99_021E6C30(w, stat08, 3, 4, 0x50, 0xA0, 0x20, FALSE);
    ov98_0221E6F0(w->sprites, w->sprite, ov99_021E9DAC, countA, 7, 0x10, 0x28, TRUE);
    ov98_0221E6F0(w->sprites, w->sprite, ov99_021E9DAC, countB, 0x11, 0x10, 0x48, TRUE);
    ov98_0221E6F0(w->sprites, w->sprite, ov99_021E9DAC, countC, 0x1B, 0x10, 0x68, TRUE);
    ov98_0221E6F0(w->sprites, w->sprite, ov99_021E9DAC, countD, 0x25, 0x10, 0x88, TRUE);
    ov98_0221E6F0(w->sprites, w->sprite, ov99_021E9D8C, countD, 0x39, 0x60, 0x78, FALSE);
}

u16 ov99_021E6F70(void *save) {
    u16 sum = 0;
    u8 i;
    const u16 *values;

    if (save == NULL) {
        GF_AssertFail();
    }
    values = PokeathlonSave_GetUnkAEC(save);
    for (i = 0; i < 10; i++) {
        sum += values[i];
    }
    return sum;
}

u16 ov99_021E6FA0(const u8 *bits) {
    int i;
    u16 count = 0;

    if (bits == NULL) {
        GF_AssertFail();
    }
    for (i = 0; i < 0x1ED; i++) {
        count += MATH_CountPopulation(bits[i]);
    }
    return count;
}

void ov99_021E6FD0(Ov99Work *w, Ov99Params *params) {
    Ov99Summary *summary;
    void *save;
    void *profile;
    void *recordsSolo;
    void *unkDC;
    Ov99CourseRecord *records;
    int i;

    summary = Heap_Alloc(w->heapId, sizeof(Ov99Summary));
    MI_CpuFill8(summary, 0, sizeof(Ov99Summary));
    save = params->save;
    profile = params->profile;
    records = PokeathlonSave_dummy1(save);
    recordsSolo = PokeathlonSave_GetRecordsSolo(save);
    unkDC = PokeathlonSave_GetUnkDC(save);
    for (i = 0; i < 5; i++) {
        u16 score = records[i].score;
        summary->courses[i] = score;
        summary->courseTotal += score;
    }
    summary->profile = profile;
    summary->unk06 = ov99_021E6F70(save);
    summary->unk0A = ov99_021E6FA0(unkDC);
    summary->unk16 = ov98_0221F024(unkDC);
    summary->unk17 = ov98_0221F058(recordsSolo);
    summary->total = summary->courseTotal + summary->unk06 + summary->unk0A;
    summary->gender = PlayerProfile_GetTrainerGender(profile);
    w->summary = summary;
}
