#include "global.h"

#include "r40_overlay_64_residual_10_candidate_private.h"

typedef struct ManagedSpriteTemplatePrivate {
    s16 x, y, z;
    u16 animation;
    int drawPriority;
    int pal;
    int vram;
    int resIdList[6];
    int bgPriority;
    int vramTransfer;
} ManagedSpriteTemplatePrivate;

typedef struct TexPrivate {
    u8 pad00[0x14];
    u32 ofsTex;
    u8 pad18[0x20];
    u32 ofsPltt;
} TexPrivate;

extern const ManagedSpriteTemplatePrivate ov64_021E6FD4;
extern const s16 ov64_021E6ECC[];
extern const s16 ov64_021E6ECE[];
extern int SpeciesToOverworldModelIndexOffset(u16);
extern void ReadWholeNarcMemberByIdPair(void *, int, int);
extern void *NARC_New(int, int);
extern void NARC_Delete(void *);
extern void SpriteSystem_LoadCharResObjFromOpenNarc(void *, void *, void *, int, int, int, int);
extern void *SpriteSystem_NewSprite(void *, void *, const void *);
extern void *Sprite_GetImageProxy(void *);
extern u8 GetGenderBySpeciesAndPersonality(u16, u32);
extern int ov64_021E6E30(int, int, int);
extern void *AllocAndReadWholeNarcMemberByIdPair(int, int, int);
extern void *Heap_Alloc(int, u32);
extern void Heap_Free(void *);
extern void sub_020145B4(const void *, int, int, int, int, int, void *);
extern void ov64_021E5AAC(const void *, u32, u32);
extern void *Sprite_GetPaletteProxy(void *);
extern u8 CalcShininessByOtIdAndPersonality(u32, u32);
extern void ov64_021E5AE4(const void *, u32, u32);

#define PTR(p, o)  (*(void **)((u8 *)(p) + (o)))
#define U32_(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U16_(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U8_(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void ov64_021E6C1C(void *state, u32 slot, u32 form, int vram, u32 charResId) {
    u8 modelInfo[4];
    ManagedSpriteTemplatePrivate template;
    void *narc;
    int dim;
    int charFile;
    int sharedResId;
    u32 imageLocation;
    u32 tileSize;
    void *modelFile;
    TexPrivate *tex;
    u8 *texData;
    u8 *buffer;
    u8 *plttData;
    u32 plttLocation;
    void **spriteBase;
    u32 spriteOffset;
    u16 member;

    ReadWholeNarcMemberByIdPair(modelInfo, 0x8D, SpeciesToOverworldModelIndexOffset(U16_(state, 0x198)));
    narc = NARC_New(0x61, 0x3B);
    if (modelInfo[1]) {
        sharedResId = 0xDCC2;
        charFile = 0xD;
        dim = 8;
    } else {
        sharedResId = 0xDCC1;
        charFile = 0xA;
        dim = 4;
    }
    SpriteSystem_LoadCharResObjFromOpenNarc(PTR(state, 0x130), PTR(state, 0x134), narc, charFile, 1, 1, vram);
    NARC_Delete(narc);

    template = ov64_021E6FD4;
    template.resIdList[0] = vram;
    template.resIdList[1] = charResId;
    template.resIdList[2] = sharedResId;
    template.resIdList[3] = sharedResId;
    template.x = *(s16 *)((u8 *)ov64_021E6ECC + form * 4);
    template.y = *(s16 *)((u8 *)ov64_021E6ECE + form * 4);
    spriteBase = (void **)((u8 *)state + 0x138);
    spriteOffset = slot * 4;
    *(void **)((u8 *)spriteBase + spriteOffset) = SpriteSystem_NewSprite(PTR(state, 0x130), PTR(state, 0x134), &template);
    imageLocation = NNS_G2dGetImageLocation((NNSG2dImageProxy *)Sprite_GetImageProxy(**(void ***)((u8 *)spriteBase + spriteOffset)), NNS_G2D_VRAM_TYPE_2DMAIN);

    tileSize = dim * (dim << 5);
    member = ov64_021E6E30(U16_(state, 0x198), U8_(state, 0x19B), GetGenderBySpeciesAndPersonality(U16_(state, 0x198), U32_(state, 0x190)));
    modelFile = AllocAndReadWholeNarcMemberByIdPair(0x51, member, 0x3B);
    tex = (TexPrivate *)NNS_G3dGetTex((NNSG3dResFileHeader *)modelFile);
    texData = (u8 *)tex + tex->ofsTex;
    buffer = Heap_Alloc(0x3B, tileSize);
    if ((u16)(U16_(state, 0x198) + 0xFF9E) <= 1) {
        sub_020145B4(texData + tileSize * 6, dim, 0, 0, dim, dim, buffer);
        ov64_021E5AAC(buffer, imageLocation, tileSize);
        sub_020145B4(texData + tileSize * 7, dim, 0, 0, dim, dim, buffer);
        ov64_021E5AAC(buffer, imageLocation + tileSize, tileSize);
    } else {
        sub_020145B4(texData + tileSize * 2, dim, 0, 0, dim, dim, buffer);
        ov64_021E5AAC(buffer, imageLocation, tileSize);
        sub_020145B4(texData + tileSize * 3, dim, 0, 0, dim, dim, buffer);
        ov64_021E5AAC(buffer, imageLocation + tileSize, tileSize);
    }
    Heap_Free(buffer);
    plttLocation = NNS_G2dGetImagePaletteLocation((NNSG2dImagePaletteProxy *)Sprite_GetPaletteProxy(**(void ***)((u8 *)spriteBase + spriteOffset)), NNS_G2D_VRAM_TYPE_2DMAIN);
    plttData = (u8 *)tex + tex->ofsPltt;
    if (CalcShininessByOtIdAndPersonality(U32_(state, 0x194), U32_(state, 0x190))) {
        plttData += 0x20;
    }
    ov64_021E5AE4(plttData, plttLocation, 0x20);
    Heap_Free(modelFile);
}
