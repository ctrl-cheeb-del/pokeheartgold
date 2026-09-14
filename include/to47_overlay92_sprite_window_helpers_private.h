#ifndef TO47_OVERLAY92_RESIDUAL8_PRIVATE_H
#define TO47_OVERLAY92_RESIDUAL8_PRIVATE_H

#include "global.h"

#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

typedef struct Ov92AnimPair {
    int value[4][2];
} Ov92AnimPair;
typedef struct Ov92Work {
    u8 raw[0x1FE0];
    u8 window[16];
} Ov92Work;
typedef struct Ov92SpriteWork {
    u8 pad00[0x1C];
    void *first[3];
    void *second[3];
    void *third[3];
    u8 pad40[0xB4];
    u16 slot[1];
} Ov92SpriteWork;
extern const Ov92AnimPair ov92_02263BCC;
extern const Ov92AnimPair ov92_02263B8C;
void ManagedSprite_SetAnim(void *, int);
int ManagedSprite_GetActiveAnim(void *);
void ManagedSprite_TickTwoFrames(void *);
void Sprite_DeleteAndFreeResources(void *);
void GF_AssertFail(void);
void InitWindow(void *);
void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void FillWindowPixelBuffer(void *, int);
void *NewMsgDataFromNarc(int, int, int, int);
void *NewString_ReadMsgData(void *, int);
int AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
void String_Delete(void *);
void DestroyMsgData(void *);
void DrawFrameAndWindow1(void *, int, int, int);
void CopyWindowToVram(void *);
void ov92_0225DF58(void *, int, int);
int ov92_0225DFA4(void *, int);
void ov92_0225E008(void *);
void ov92_0225E03C(void *);
void ov92_0225E070(void *);

#endif
