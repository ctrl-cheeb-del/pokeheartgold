#include "global.h"

typedef struct {
    u8 raw[0x200];
} State;

typedef struct {
    u32 unk0;
    u32 unk4;
} Ov95Params;

extern void ov95_021E5D44(void *, void *);
extern void ov95_021E5BBC(void *bg, void *palette, int frame);
extern void ov95_021E5C44(void *bg, void *window, int x, int y, int width, int height, int palette, int baseTile, int arg8);
extern void ov95_021E5EF8(State *);
extern void ov95_021E6000(State *);
extern void ov95_021E70BC(void *, void *, int, int, int, int);
extern void ov95_021E623C(State *);
extern void ov95_021E62F0(State *, int);
extern void *ov95_021E5E90(Ov95Params *);
extern void ov95_021E5B7C(void);
extern void ov95_021E5B9C(void);
extern int ov95_021E67F0(State *);
extern int ov95_021E6838(State *);
extern int ov95_021E68A8(State *);
extern int ov95_021E6900(State *);
extern int ov95_021E6964(State *);
extern int ov95_021E6B74(State *);
extern void ov95_021E62A4(State *);
extern int ov95_021E5CAC(void *window, int messageId, void *pokemon, int y);
extern void ov95_021E7208(void *, int, int);
extern int ov95_021E7258(void *);
extern void ov95_021E62E4(State *);
extern void ov95_021E6184(State *);
extern void ov95_021E5D34(void *);
extern void ov95_021E5E40(void *);
extern void ov95_021E5EF0(void *);
extern void ManagedSprite_SetDrawFlag(void *, int);
extern void GF_AssertFail(void);
extern BOOL IsPaletteFadeFinished(void);
extern void Sound_Stop(void);
extern void Sound_SetSceneAndPlayBGM(int, int, int);
extern u32 GetMonData(void *mon, int attr, void *dest);
extern BOOL PlayCry(u16 species, u8 form);
extern BOOL IsCryFinished(void);
extern void PlayFanfare(int);
extern BOOL IsFanfarePlaying(void);
extern BOOL TextPrinterCheckActive(u8 printerId);
extern int sub_02017068(void *, int);
extern BOOL Pokepic_IsAnimFinished(void *);
extern void SpriteSystem_DrawSprites(void *);

int ov95_021E6314(State *p);
int ov95_021E65A0(State *p);

int ov95_021E6314(State *p) {
    int ret = 1;

    switch (*(u32 *)((u8 *)p + 0x60)) {
    case 0: {
        Ov95Params params;
        ov95_021E5D44(*(void **)((u8 *)p + 4), *(void **)((u8 *)p + 8));
        ov95_021E5BBC(*(void **)((u8 *)p + 4), *(void **)((u8 *)p + 8), *(u32 *)((u8 *)p + 0x14));
        ov95_021E5C44(*(void **)((u8 *)p + 4), (u8 *)p + 0x18, 1, 2, 19, 27, 4, 59, 14);
        ov95_021E5EF8(p);
        ov95_021E6000(p);
        ov95_021E70BC(*(void **)((u8 *)p + 0x88), *(void **)((u8 *)p + 8), 0x5208, 0x5209, 0x520A, 0x520B);
        ov95_021E623C(p);
        ov95_021E62F0(p, 1);
        params.unk0 = 0x46;
        params.unk4 = 0;
        *(void **)((u8 *)p + 0x44) = ov95_021E5E90(&params);
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    }
    case 1:
        ov95_021E5B7C();
        (*(u32 *)((u8 *)p + 0x60))++;
    case 2:
        if (IsPaletteFadeFinished() == 1) {
            Sound_Stop();
            Sound_SetSceneAndPlayBGM(13, 0x3F3, 1);
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 3:
        if (ov95_021E67F0(p) == 0) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 4:
        if (ov95_021E6838(p) == 0) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 5:
        if (ov95_021E68A8(p) == 0) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 6:
        if (ov95_021E6900(p) == 0) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 7:
        if (ov95_021E6964(p) == 0) {
            ov95_021E62A4(p);
            PlayCry(GetMonData(*(void **)((u8 *)*(void **)p + 0xC), 5, NULL), GetMonData(*(void **)((u8 *)*(void **)p + 0xC), 0x70, NULL));
            *(u32 *)((u8 *)p + 0xC) = ov95_021E5CAC((u8 *)p + 0x18, 0, *(void **)((u8 *)*(void **)p + 0xC), *(u32 *)((u8 *)p + 0x10));
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 8:
        if (IsCryFinished()) {
            break;
        }
        PlayFanfare(0x4A4);
        (*(u32 *)((u8 *)p + 0x60))++;
    case 9:
        if (IsFanfarePlaying()) {
            break;
        }
        (*(u32 *)((u8 *)p + 0x60))++;
    case 10:
        if (TextPrinterCheckActive(*(u32 *)((u8 *)p + 0xC))) {
            break;
        }
        *(u32 *)((u8 *)p + 0xC) = ov95_021E5CAC((u8 *)p + 0x18, 1, *(void **)((u8 *)*(void **)p + 0xC), *(u32 *)((u8 *)p + 0x10));
        (*(u32 *)((u8 *)p + 0x60))++;
    case 11:
        if (TextPrinterCheckActive(*(u32 *)((u8 *)p + 0xC))) {
            break;
        }
        if (sub_02017068(*(void **)((u8 *)p + 0x58), 0) != 1) {
            break;
        }
        if (Pokepic_IsAnimFinished(*(void **)((u8 *)p + 0x70))) {
            break;
        }
        ov95_021E7208(*(void **)((u8 *)p + 0x88), 2, 3);
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 12:
        switch (ov95_021E7258(*(void **)((u8 *)p + 0x88))) {
        case 1:
            *(u32 *)((u8 *)*(void **)p + 4) = 1;
            (*(u32 *)((u8 *)p + 0x60))++;
            break;
        case 2:
            *(u32 *)((u8 *)*(void **)p + 4) = 0;
            (*(u32 *)((u8 *)p + 0x60))++;
            break;
        }
        break;
    case 13:
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 14:
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 15:
        ov95_021E5B9C();
        (*(u32 *)((u8 *)p + 0x60))++;
    case 16:
        if (IsPaletteFadeFinished() == 1) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 17:
    default:
        ov95_021E62E4(p);
        ov95_021E6184(p);
        ov95_021E5D34((u8 *)p + 0x18);
        ov95_021E5E40(*(void **)((u8 *)*(void **)((u8 *)p + 0x44) + 0xC));
        ov95_021E5EF0(*(void **)((u8 *)p + 0x44));
        ret = 0;
        break;
    }

    SpriteSystem_DrawSprites(*(void **)((u8 *)p + 0x50));
    return ret;
}

int ov95_021E65A0(State *p) {
    int ret = 1;

    switch (*(u32 *)((u8 *)p + 0x60)) {
    case 0: {
        Ov95Params params;
        ov95_021E5D44(*(void **)((u8 *)p + 4), *(void **)((u8 *)p + 8));
        ov95_021E5BBC(*(void **)((u8 *)p + 4), *(void **)((u8 *)p + 8), *(u32 *)((u8 *)p + 0x14));
        ov95_021E5C44(*(void **)((u8 *)p + 4), (u8 *)p + 0x18, 1, 2, 19, 27, 4, 59, 14);
        ov95_021E5EF8(p);
        ov95_021E6000(p);
        ManagedSprite_SetDrawFlag(*(void **)((u8 *)p + 0x74), 0);
        ov95_021E70BC(*(void **)((u8 *)p + 0x88), *(void **)((u8 *)p + 8), 0x5208, 0x5209, 0x520A, 0x520B);
        ov95_021E623C(p);
        ov95_021E62F0(p, 1);
        params.unk0 = 0x46;
        params.unk4 = 1;
        *(void **)((u8 *)p + 0x44) = ov95_021E5E90(&params);
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    }
    case 1:
        ov95_021E5B7C();
        (*(u32 *)((u8 *)p + 0x60))++;
    case 2:
        if (IsPaletteFadeFinished() == 1) {
            Sound_SetSceneAndPlayBGM(13, 0x3F3, 1);
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 3:
        if (ov95_021E6B74(p) == 0) {
            ov95_021E62A4(p);
            PlayCry(GetMonData(*(void **)((u8 *)*(void **)p + 0xC), 5, NULL), GetMonData(*(void **)((u8 *)*(void **)p + 0xC), 0x70, NULL));
            *(u32 *)((u8 *)p + 0xC) = ov95_021E5CAC((u8 *)p + 0x18, 0, *(void **)((u8 *)*(void **)p + 0xC), *(u32 *)((u8 *)p + 0x10));
            *(u32 *)((u8 *)p + 0x60) = 8;
        }
        break;
    case 4:
    case 5:
    case 6:
    case 7:
        GF_AssertFail();
        break;
    case 8:
        if (IsCryFinished()) {
            break;
        }
        PlayFanfare(0x4A4);
        (*(u32 *)((u8 *)p + 0x60))++;
    case 9:
        if (IsFanfarePlaying()) {
            break;
        }
        (*(u32 *)((u8 *)p + 0x60))++;
    case 10:
        if (TextPrinterCheckActive(*(u32 *)((u8 *)p + 0xC))) {
            break;
        }
        *(u32 *)((u8 *)p + 0xC) = ov95_021E5CAC((u8 *)p + 0x18, 1, *(void **)((u8 *)*(void **)p + 0xC), *(u32 *)((u8 *)p + 0x10));
        (*(u32 *)((u8 *)p + 0x60))++;
    case 11:
        if (TextPrinterCheckActive(*(u32 *)((u8 *)p + 0xC))) {
            break;
        }
        if (sub_02017068(*(void **)((u8 *)p + 0x58), 0) != 1) {
            break;
        }
        if (Pokepic_IsAnimFinished(*(void **)((u8 *)p + 0x70))) {
            break;
        }
        ov95_021E7208(*(void **)((u8 *)p + 0x88), 2, 3);
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 12:
        switch (ov95_021E7258(*(void **)((u8 *)p + 0x88))) {
        case 1:
            *(u32 *)((u8 *)*(void **)p + 4) = 1;
            (*(u32 *)((u8 *)p + 0x60))++;
            break;
        case 2:
            *(u32 *)((u8 *)*(void **)p + 4) = 0;
            (*(u32 *)((u8 *)p + 0x60))++;
            break;
        }
        break;
    case 13:
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 14:
        (*(u32 *)((u8 *)p + 0x60))++;
        break;
    case 15:
        ov95_021E5B9C();
        (*(u32 *)((u8 *)p + 0x60))++;
    case 16:
        if (IsPaletteFadeFinished() == 1) {
            (*(u32 *)((u8 *)p + 0x60))++;
        }
        break;
    case 17:
    default:
        ov95_021E62E4(p);
        ov95_021E6184(p);
        ov95_021E5D34((u8 *)p + 0x18);
        ov95_021E5E40(*(void **)((u8 *)*(void **)((u8 *)p + 0x44) + 0xC));
        ov95_021E5EF0(*(void **)((u8 *)p + 0x44));
        ret = 0;
        break;
    }

    SpriteSystem_DrawSprites(*(void **)((u8 *)p + 0x50));
    return ret;
}
