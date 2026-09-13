#ifndef TO41_OVERLAY74_THUMB_PRIVATE_H
#define TO41_OVERLAY74_THUMB_PRIVATE_H

#include "global.h"

#define OV74_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define OV74_U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define OV74_U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define OV74_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern u8 ov74_0223C920[];
extern u8 ov74_0223D0C4[];

void *ov74_02231054(void);
void *ov74_0223105C(void);
void *ov74_02231148(void);
void *ov74_02231154(void);
void *ov74_0223115C(void);
void *ov74_02231184(void);
void *ov74_02231048(void);
u8 ov74_02231064(void);
void ov74_02231070(u8 value);
u8 ov74_0223107C(void);
void ov74_02231088(u8 value);
u8 ov74_02231094(void);
void ov74_022310A0(u8 value);
u8 ov74_022310AC(void);
void ov74_022310B8(u16 value);
void *ov74_022310C4(void);
void *ov74_022310D0(void);
void *ov74_022310DC(void);
void *ov74_022310E8(void);
void *ov74_022310F4(void);
void *ov74_02231100(void);
void ov74_0223110C(u16 value);
void *ov74_02231118(void);
void ov74_02231124(void *value);
void ov74_02231130(void *value);
void ov74_0223113C(void *value);
void ov74_02231194(void);
void *ov74_022311A0(void);
u8 ov74_022311AC(void);
u32 ov74_022311BC(void);
u32 ov74_022311CC(void);
u32 ov74_022311D8(void);
void *ov74_022311DC(void);
void *ov74_022311E8(void);
u32 ov74_02231260(void);

#endif
