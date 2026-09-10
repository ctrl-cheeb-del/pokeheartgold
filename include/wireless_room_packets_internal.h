#ifndef POKEHEARTGOLD_WIRELESS_ROOM_PACKETS_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_ROOM_PACKETS_INTERNAL_H

#include "global.h"
typedef struct Work {
    u8 raw[0x9400];
} Work;
typedef struct TenBytes {
    u8 data[10];
} TenBytes;
typedef struct WorkProgress {
    u8 pad[0x43cc];
    int progress;
} WorkProgress;
typedef struct FourBytes {
    u8 data[4];
} FourBytes;

#define U8(p, o)  (((u8 *)(p))[o])
#define U16(p, o) (*(u16 *)&((u8 *)(p))[o])
#define U32(p, o) (*(u32 *)&((u8 *)(p))[o])
#define S32(p, o) (*(int *)&((u8 *)(p))[o])
#define PTR(p, o) (*(void **)&((u8 *)(p))[o])

extern const u8 _021054B4[];
void *sub_0203410C(const void *, int, void *);
int sub_0203769C(void);
void sub_02037108(int, const void *, int);
void CopyWindowToVram(void *);
void ov37_021E6FC8(void *, int, int);
int sub_02037454(void);
int sub_02033250(void);
int ov37_021E75E0(void);
int MATH_CountPopulation(u32);
void sub_02038C1C(int);
void GF_AssertFail(void);
void sub_020398D4(int, int);
void sub_02037088(int, const void *, int);

void *sub_0208F814(void *);
void sub_0208F828(void *, void *, void *, Work *);
void sub_0208F8BC(int, void *, const u8 *, Work *);
void sub_0208F8E4(int, void *, const u8 *, Work *);
void sub_0208F918(void *, void *, void *, Work *);
void sub_0208F960(int, void *, const FourBytes *, Work *);
void sub_0208FA50(void);
void sub_0208FA54(void *, void *, const u8 *, Work *);
void sub_0208FA88(void);
void sub_0208FA8C(void);
void sub_0208FA90(void *, void *, void *, Work *);
void sub_0208FAA8(int, void *, void *, Work *);
void sub_0208FAEC(void *, void *, void *, Work *);
void sub_0208FAF8(Work *, int);
void *sub_0208FB4C(int, void *);
int sub_0208FB5C(void);
int sub_0208FB60(void);

#endif
