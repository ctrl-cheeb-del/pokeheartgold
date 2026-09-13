#ifndef R40_OV103_R11_PRIVATE_H
#define R40_OV103_R11_PRIVATE_H
#include "global.h"
typedef struct R40Ov103Work11 {
    u8 pad00[0xC];
    u8 *ctx;
    u8 pad10[8];
    u32 field18;
    u8 pad1c[3];
    u8 selected;
    u8 pad20[8];
    u32 field28;
} R40Ov103Work11;
extern int TouchscreenListMenu_HandleInput(void *);
extern void ov103_021ECFFC(void *);
extern void ov103_021EE888(void *);
extern void ov103_021EE0CC(void *, u32, u32);
extern void ov103_021EE60C(void *);
extern void ov103_021EE374(void *);
extern void ov103_021EDBB0(void *);
extern void ov103_021EE8A8(void *, u32);
extern u32 ov103_021EDA70(void *, u32, u32);
extern u32 Mail_GetType(void *);
extern u32 MailToItemId(u32);
extern void ov103_021EDC68(void *, u32, u32, u32);
extern u32 ov103_021EDA40(void *, u32);
extern void sub_0201980C(void *, u32);
extern void ov103_021EDB60(void *, u32);
u32 ov103_021ED7E4(R40Ov103Work11 *);
#endif
