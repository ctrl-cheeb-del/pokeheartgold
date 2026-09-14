#ifndef PRIVATE_H
#define PRIVATE_H
#include "global.h"

BOOL MapObjectManager_GetNextObjectWithFlagFromIndex(void *, void **, u32 *, u32);
u32 MapObject_GetSpriteID(void *);
typedef struct RenderFlags {
    u16 low : 4;
    u16 rest : 12;
} RenderFlags;
RenderFlags *ov01_021F9318(void *);
u8 ov01_021FA28C(u32);
u8 ov01_021FA2A0(u32);
void *sub_0205F1A0(void *);
int ov01_021F9EEC(void *, u32);
int ov01_021F9F14(void *, u32);
int ov01_021F9EC4(void *, u32);
BOOL ov01_021FA01C(void *, u32, void *);
BOOL ov01_021FA094(void *, u32, void *);
BOOL ov01_021F9FCC(void *, u32, void *);
void ov01_021FC588(void *, u32);
void ov01_021F9BAC(void *, u32);
void ov01_021F9CD0(void *, u32);
void *ov01_021FA1F4(void *);
void GF3dGfxRawResMan_FreeObjById(void *, u32);
void ov01_021F9E04(void *, u32);
void ov01_021FA4F0(void *, u32);
void ov01_021FA6A4(void *, u32);
void ov01_021FA108(void *, u32, void *);

#endif
