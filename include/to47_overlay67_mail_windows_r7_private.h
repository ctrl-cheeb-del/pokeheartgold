#include "global.h"

#define U8(p, n) (*(u8 *)((u8 *)(p) + (n)))
#define U16(p, n) (*(u16 *)((u8 *)(p) + (n)))
#define U32(p, n) (*(u32 *)((u8 *)(p) + (n)))
#define PTR(p, n) ((void *)((u8 *)(p) + (n)))

extern void FillWindowPixelBuffer(void *, int);
extern void ScheduleWindowCopyToVram(void *);
extern void BufferIntegerAsString(void *, int, int, int, int, int);
extern void ov67_021E6118(void *, void *, int, int, int, int, int);
extern void ov67_021E61A0(void *, int, int, int, int, int, int, int);
extern void ov67_021E6164(void *, int, int, int, int, int, int, int);
extern void ov67_021E61E8(void *);
extern void sub_0202D8D0(void *, void *);
extern void ov67_021E6688(void *, int);
extern void BufferString(void *, int, void *, int, int, int);
extern void BufferCountryName(void *, int, int);
extern void BufferCityName(void *, int, int, int);
extern void *MailMsg_GetExpandedString(void *, int);
extern void String_Delete(void *);

void ov67_021E6490(void *);
void ov67_021E6530(void *);
void ov67_021E65C0(void *);
void ov67_021E6688(void *, int);
