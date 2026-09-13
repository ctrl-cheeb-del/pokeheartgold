#ifndef TO40_R10_OVERLAY65_RESIDUAL_3_H
#define TO40_R10_OVERLAY65_RESIDUAL_3_H

#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov65Vec3 {
    fx32 x;
    fx32 y;
    fx32 z;
} Ov65Vec3;

typedef struct Ov65SpriteTemplate {
    void *spriteList; // 0x00
    void *header;     // 0x04
    fx32 x;           // 0x08
    fx32 y;           // 0x0c
    fx32 z;           // 0x10
    fx32 scaleX;      // 0x14
    fx32 scaleY;      // 0x18
    fx32 scaleZ;      // 0x1c
    u16 rotation;     // 0x20
    u32 drawPriority; // 0x24
    u32 whichScreen;  // 0x28
    u32 heapId;       // 0x2c
} Ov65SpriteTemplate;

extern const s32 ov65_0221FEA4[][3];
extern const s32 ov65_0221FEA8[][3];
extern const s32 ov65_0221FF4C[][2];
extern const s32 ov65_0221FF50[][2];
extern const u32 ov65_0221FD68[][3];
extern const u32 ov65_0221FD6C[][3];
extern const u32 ov65_0221FD70[][3];
extern const u8 ov65_0221FFB4[][4][6];
extern const u8 ov65_0221FE6C[];
extern u8 gSystem[];

extern void *Party_GetMonByIndex(void *, u32);
extern u32 GetMonData(void *, u32, void *);
extern u8 sub_0207083C(void *, u8);
extern void Sprite_SetDrawFlag(void *, u32);
extern void Sprite_SetFlipMode(void *, u32);
extern void Sprite_SetAnimCtrlSeq(void *, u32);
extern void Sprite_SetAnimActiveFlag(void *, u32);
extern void Sprite_SetDrawPriority(void *, u32);
extern void Sprite_SetOamMode(void *, u32);
extern void Sprite_SetMatrix(void *, void *);
extern void *Sprite_CreateAffine(const Ov65SpriteTemplate *);
extern void CreateSpriteResourcesHeader(void *, s32, s32, s32, s32, s32, s32, u32, u32, void *, void *, void *, void *, void *, void *);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void String16_FormatInteger(void *, int, u32, int, int);
extern void GetItemNameIntoString(void *, u32, u32);
extern void FillWindowPixelBuffer(void *, u32);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void ReadMsgDataIntoString(void *, u32, void *);
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern void *Save_Chatot_Get(void *);
extern void sub_02006E4C(void *, u32, u32, s32);
extern void PlayCry(u16, u8);
extern void PlaySE(u32);
extern void GF_AssertFail(void);
extern fx32 GF_SinDeg(u16);
extern void ov65_0221CA64(void *, int, int);
extern void ov65_0221D5FC(void *, void *, u32, u32, u32);
extern int ov65_0221D648(u16 *, void *, u32, int);
extern void ov65_0221F748(void *, s32, s32);
extern void ov65_0221FB4C(void *, void *, u32, u32, u32, u32);

void ov65_0221D674(void *windows, int side, void *party, int index, void *work);
void ov65_0221D8C4(void *windows, int side, void *work);
void ov65_0221D930(void *work);
void ov65_0221DBF4(void *p);
void ov65_0221DC34(void *work);
void ov65_0221DCBC(void *state);
int ov65_0221DCFC(int idx, int dir, void *summaries);
void ov65_0221DD34(int idx, void *sprite, int form);
int ov65_0221DDC0(void *input, void *state, void *sprite, void *summaries, int side);

#endif
