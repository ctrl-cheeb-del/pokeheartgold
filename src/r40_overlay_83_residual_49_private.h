#ifndef R40_OV83_R49_H
#define R40_OV83_R49_H
#include "global.h"
extern const u8 ov83_02248610[];
extern const u8 ov83_02248611[];
extern const u32 ov83_02248570[];
extern const u32 ov83_0224858C[];
extern const void *ov83_022484F4;
extern void ov83_022485C8(void);
extern const u8 ov83_02248520[];
void *GridInputHandler_Create(const void *, const void *, const void *, void *, int, int, int);
int GridInputHandler_HandleInput_NoHold(void *);
int GridInputHandler_GetNextInput(void *);
int TouchscreenHitbox_FindRectAtTouchNew(const void *);
void ov83_02242AC0(void *, int, int, int);
void ov83_02242AE0(void *, int);
void *ov83_02247B7C(void *);
void ov83_02247C58(void *, int);
void ov83_02247C88(void *, int);
#endif
