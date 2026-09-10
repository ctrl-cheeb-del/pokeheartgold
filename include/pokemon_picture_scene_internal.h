#ifndef POKEHEARTGOLD_POKEMON_PICTURE_SCENE_INTERNAL_H
#define POKEHEARTGOLD_POKEMON_PICTURE_SCENE_INTERNAL_H
#include "global.h"

typedef struct UnkStruct_0208DE40 {
    u8 pad_000[0x22C];
    void *unk_22C; // 0x22C
    u8 pad_230[0x23C - 0x230];
    u16 unk_23C; // 0x23C
    u8 pad_23E[0x280 - 0x23E];
    u32 unk_280_0 : 28; // 0x280
    u32 unk_280_28 : 1;
    u32 unk_280_29 : 3;
    u8 pad_284[0x29C - 0x284];
    void *unk_29C;  // 0x29C  camera
    void *unk_2A0;  // 0x2A0  pokepic manager
    u32 unk_2A4[2]; // 0x2A4
    u8 pad_2AC[0x2CC - 0x2AC];
    void *unk_2CC; // 0x2CC
    void *unk_2D0; // 0x2D0
    u32 unk_2D4;   // 0x2D4
    u8 pad_2D8[0x7B8 - 0x2D8];
    void *unk_7B8; // 0x7B8
    u8 pad_7BC[3];
    u8 unk_7BF_0 : 4; // 0x7BF
    u8 unk_7BF_4 : 4;
} UnkStruct_0208DE40;

typedef struct UnkAnimVec {
    u16 a[3]; // 0x00
    u16 b[3]; // 0x06
    u16 c[3]; // 0x0C
} UnkAnimVec;

typedef struct UnkAnimVecS {
    s16 a[3];
    s16 b[3];
    s16 c[3];
} UnkAnimVecS;

typedef struct UnkVec3s {
    s16 x, y, z;
} UnkVec3s;

struct UnkStruct22C {
    u8 pad_00[0x11];
    u8 unk_11;
};

void NNS_G2dSetupSoftwareSpriteCamera(void);
void PokepicManager_DrawAll(void *mgr);
void PokepicManager_Delete(void *mgr);
void Camera_Delete(void *camera);
void sub_02017088(void *a, int b);
void sub_02016F2C(void *a);
void Pokepic_StartAnim(void *p, int a);
void sub_0207294C(void *a, void *b, void *c, int d, int e, u32 f, int g);
void *PokepicManager_Create(int heapId);
int sub_0208A520(UnkStruct_0208DE40 *a);
void GetPokemonSpriteCharAndPlttNarcIds(u32 *dest, int species, int c);
void GetBoxmonSpriteCharAndPlttNarcIds(u32 *dest, int species, int c, int d);
void NARC_ReadPokepicAnimScript(void *narc, void *dest, u16 species, int d);
void *PokepicManager_CreatePokepic(void *mgr, u32 *a, int x, int y, int e, int f, void *g, int h);
void Pokepic_SetAttr(void *pic, int attr, int value);
int TouchscreenHitbox_FindRectAtTouchNew(const void *hitboxes);

extern const u8 _02104FD0[][4];

extern const u8 _02104FFC[][4];

void sub_0208DEDC(UnkStruct_0208DE40 *a);
void sub_0208DEFC(UnkStruct_0208DE40 *a);
void sub_0208DF9C(const UnkAnimVec *src, UnkVec3s *dst, int t);
void sub_0208DFF8(const UnkVec3s *from, const UnkVec3s *to, UnkVec3s *out);
void sub_0208E174(UnkStruct_0208DE40 *summary);
void sub_0208E3AC(UnkStruct_0208DE40 *a);
void sub_0208E444(UnkStruct_0208DE40 *a);
void sub_0208E4B4(UnkStruct_0208DE40 *a);
int sub_0208E4DC(UnkStruct_0208DE40 *a);
u8 sub_0208E544(UnkStruct_0208DE40 *a);

typedef char AssertAnimVecSize[(sizeof(UnkAnimVec) == 0x12) ? 1 : -1];
typedef char AssertAnimVecSignedSize[(sizeof(UnkAnimVecS) == 0x12) ? 1 : -1];
typedef char AssertPicture22C[(offsetof(UnkStruct_0208DE40, unk_22C) == 0x22C) ? 1 : -1];
typedef char AssertPicture23C[(offsetof(UnkStruct_0208DE40, unk_23C) == 0x23C) ? 1 : -1];
typedef char AssertPicture29C[(offsetof(UnkStruct_0208DE40, unk_29C) == 0x29C) ? 1 : -1];
typedef char AssertPicture2A0[(offsetof(UnkStruct_0208DE40, unk_2A0) == 0x2A0) ? 1 : -1];
typedef char AssertPicture2A4[(offsetof(UnkStruct_0208DE40, unk_2A4) == 0x2A4) ? 1 : -1];
typedef char AssertPicture2CC[(offsetof(UnkStruct_0208DE40, unk_2CC) == 0x2CC) ? 1 : -1];
typedef char AssertPicture2D0[(offsetof(UnkStruct_0208DE40, unk_2D0) == 0x2D0) ? 1 : -1];
typedef char AssertPicture2D4[(offsetof(UnkStruct_0208DE40, unk_2D4) == 0x2D4) ? 1 : -1];
typedef char AssertPicture7B8[(offsetof(UnkStruct_0208DE40, unk_7B8) == 0x7B8) ? 1 : -1];

#endif
