#ifndef R40_OV103_R19_PRIVATE_H
#define R40_OV103_R19_PRIVATE_H
#include "global.h"

#include "bg_window.h"
typedef struct R40Ov103Work19 {
    u8 pad[0xC];
    u8 *ctx;
} R40Ov103Work19;
extern const u16 *Mail_GetAuthorNamePtr(void *);
extern u32 Mail_GetAuthorGender(void *);
extern void CopyU16ArrayToString(void *, const u16 *);
extern void ov103_021EE3E4(void *, void *, u32, u32, u32, u32, u32);
extern void sub_02019A60(void *, u32, void *);
extern void ov103_021EE430(void *, void *, u32, u32, u32, u32, u32, u32, u32);
void ov103_021EE468(R40Ov103Work19 *, u32, u32, u32);
void ov103_021EE550(R40Ov103Work19 *);
#endif
