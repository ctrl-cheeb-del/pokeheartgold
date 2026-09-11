#ifndef OV43_B1FC_PRIVATE_H
#define OV43_B1FC_PRIVATE_H
#include "global.h"
#include "system.h"
#include "touchscreen.h"
#include "text.h"
#include "pm_string.h"
#include "msgdata.h"
#include "message_format.h"
#include "sprite_system.h"
#include "render_text.h"

extern const TouchscreenHitbox ov43_0222EE1A[];
extern const u8 ov43_0222F0CC[];
extern void PlaySE(u16);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern void ov43_0222B3C4(u32 *, u8 *);
extern void ov43_0222B3A4(u32 *, u8 *);
extern void ov43_0222A318(u8 *, u8, u8);
extern void ov43_0222AA70(u8 *);
extern void ov43_0222AD74(u8 *, int, int);
extern void ov43_0222AD98(u8 *, int, int);
extern void ov43_0222A9F4(u8 *, u8 *, int);
void ov43_0222B1FC(u8 *, u8 *, u8 *);
void ov43_0222B4BC(u8 *, u8 *, int, int);
BOOL ov43_0222B278(u32 *, u32 *, u8 *);
BOOL ov43_0222B324(u32 *, u32 *, u8 *, int *);
BOOL ov43_0222B374(u32 *, u32 *, u8 *);
void ov43_0222B408(u32 *, u8 *);
void ov43_0222B440(u32 *, u8 *);
void ov43_0222B458(u8 *, u8 *);
BOOL ov43_0222B534(u8 *, u32 *);
#endif
