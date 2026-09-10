#include "overlay_48_helpers_internal.h"

/* Data owned by assembly this candidate deliberately does NOT define:
   the 24x2 u8 table at ov48_0225B238 (ov48_0225B239 is that same array + 1). */
extern const u8 ov48_0225B238[24][2];

u32 ov48_02259188(void *p, void *out);
s32 ov48_022592E0(void *p, void *q);
void ov48_02259824(void *p, void *q, u32 heapId);
u32 ov48_0225A244(void *p, void *q);
void ov48_0225A2A0(void *p, VecFx32 *v);
u32 ov48_0225ADF8(void *p, u32 i, void *a);
u32 ov48_0225AE60(void *p, void *a);
void ov48_02259050(void *p);
void ov48_022594A8(void *p);
void ov48_02259724(void *p);
void ov48_02259874(void *p);
u16 ov48_02259AD0(void *p, u16 a, u16 b, void *out);
s32 ov48_02259B10(void *p, u16 a, u16 b);
void ov48_02259B3C(void *p, void *out, u32 idx);
void ov48_02259C4C(void *p);
void ov48_02259F14(void *p);
u32 ov48_0225A30C(void *p, VecFx32 *out, u32 i);
void ov48_0225A768(void *p);
void ov48_0225A868(void *p, u32 i, u32 j, void *arg);
void ov48_0225A928(void *p);
void ov48_0225ACAC(void *p);
u32 ov48_0225ADBC(void *p, u32 i, void *a);
void ov48_0225B010(void *p, u32 i);
void ov48_0225B068(void *p, enum HeapID heapId);
String *ov48_0225B0E0(void *p, u32 country);
String *ov48_0225B108(void *p, u32 country, u32 city);
s32 ov48_0225B13C(void *p);
void ov48_02259030(void *p);
void ov48_02259090(void *p);
void ov48_022594D0(void *p);
void ov48_022594DC(void *p);
void ov48_02259788(void *p);
void ov48_02259868(void *p);
void ov48_022598AC(VecFx32 *src, VecFx32 *dst);
void ov48_022598BC(void *p, void *a);
void ov48_022598CC(void *p, VecFx32 *dst);
void ov48_022598DC(void *p, VecFx32 *src);
void ov48_02259984(void *p);
u16 ov48_02259B68(void *p, u32 idx);
u16 ov48_02259B84(void *p, u32 idx);
u16 ov48_02259BA0(void *p, u32 idx);
u32 ov48_02259BBC(void *p);
void ov48_02259C38(void *p);
void ov48_02259C44(void *camera);
u16 ov48_02259CFC(void *p);
void ov48_02259D94(void *p);
u32 ov48_02259E5C(void *p, s32 sel);
void ov48_02259E78(void *p);
void ov48_02259E90(void *p);
void ov48_02259FEC(void *p);
void ov48_0225A1D0(void *p);
void ov48_0225A1EC(void *p);
void ov48_0225A288(void *p);
void ov48_0225A294(void *p);
void ov48_0225A2EC(void *p);
void ov48_0225A338(void *p, void *a);
void ov48_0225A41C(void *p, void *a);
void ov48_0225A428(void *p);
void ov48_0225A430(void *p, void *a);
void ov48_0225A4B4(void *p, s32 i);
void ov48_0225A634(void *p);
void ov48_0225A650(void *p, s32 x, s32 y);
void ov48_0225A668(void *p, s32 x, s32 y);
void *ov48_0225A834(void *p, u32 i, u32 j);
void *ov48_0225A858(void *p, u32 i);
void ov48_0225AA38(void *p, u32 i, u8 v);
void ov48_0225AA50(void *p);
void ov48_0225AD38(void *p);
void ov48_0225AE3C(void *p, void *q);
void ov48_0225AE58(void *p, u16 v);
void ov48_0225AE5C(void *p, u16 v);
void ov48_0225AEA8(void *p, void *a);
void ov48_0225AEC4(void *p, fx32 *out);
u8 ov48_0225B038(u32 i);
u8 ov48_0225B050(u32 i);
void ov48_0225B0A4(void *p);
String *ov48_0225B0C4(void *p, s32 msgId);
void ov48_0225B0D4(void *p, s32 msgId, String *dest);

void ov48_02259984(void *p) {
    s32 i;
    void *q = ADD(p, 0xC178);
    for (i = 0; i < 3; i++) {
        sub_02018068(q);
        q = ADD(q, 0x10);
    }
}
