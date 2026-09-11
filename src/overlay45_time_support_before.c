#include <nitro/rtc.h>

#include "global.h"

typedef struct R28State {
    void *manager;
    u32 slots[13];
    u8 active;
    u8 unk39;
    u16 heapId;
    void *context;
    void *field40;
    void *field44;
} R28State;
typedef struct R28Place {
    u16 country;
    u8 region;
    u8 value : 4;
    u8 occupied : 4;
} R28Place;
extern void *Heap_Alloc(u32, u32);
extern void Heap_Free(void *);
extern void GF_AssertFail(void);
extern void ov45_0222CDC4(R28State *, void **, const void *);
extern u8 ov45_02254B44[];
extern u8 ov45_02254BB4[];
extern int ov45_0222A33C(void *);
extern void ov45_0222CE2C(R28State *, u32);
extern int LocationGmmDatRegionCountGetByCountryMsgNo(int);
extern void ov45_0222D638(R28Place *, u32, u32, u32);
extern int ov00_021E6A70(u32, u32);
extern int sub_020393C8(void);
extern int sub_020397FC(void);
extern void ov45_0222DE1C(void *);
extern void ov45_0222DF78(void *, u32);
extern void ov45_0222DFD0(void *);
extern void ov45_0222E000(void *);
extern void ov45_0222DEA4(void *, u32);

void ov45_0222D44C(R28State *, void **, u32);
void ov45_0222D484(R28State *, void **, u32);
void ov45_0222D4C0(void **);
void ov45_0222D4CC(R28State *, void **);
int ov45_0222D4DC(R28State *);
void ov45_0222D500(u8 *, const s64 *);
void ov45_0222D524(const u32 *, const u32 *, u8 *);

void ov45_0222D638(R28Place *, u32, u32, u32);
u16 ov45_0222D6B0(R28Place *, u32);
u8 ov45_0222D6D4(R28Place *, u32);
u8 ov45_0222D6FC(R28Place *, u32);
u8 ov45_0222D724(R28Place *, u32);
void ov45_0222D740(void *);
BOOL ov45_0222D79C(u32, u32);
u8 ov45_0222D7C0(u32);
int ov45_0222D7CC(u32, u32);
BOOL ov45_0222D7FC(u32, u32);
BOOL ov45_0222D844(void);
void *ov45_0222D860(u32);
void ov45_0222D890(void *);
void ov45_0222D8A4(void *);

void ov45_0222D44C(R28State *st, void **out, u32 heap) {
    u8 *p = Heap_Alloc(heap, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p = *out;
    *(void **)p = st->field40;
    *(void **)(p + 4) = st->context;
    *(u32 *)(p + 8) = 0;
}
void ov45_0222D484(R28State *st, void **out, u32 heap) {
    u8 *p = Heap_Alloc(heap, 12);
    *out = p;
    p[0] = 0;
    p[1] = 0;
    p[2] = 0;
    p[3] = 0;
    p[4] = 0;
    p[5] = 0;
    p[6] = 0;
    p[7] = 0;
    p[8] = 0;
    p[9] = 0;
    p[10] = 0;
    p[11] = 0;
    p = *out;
    *(void **)p = st->field40;
    *(void **)(p + 4) = st->context;
    *(u32 *)(p + 8) = 1;
}
void ov45_0222D4C0(void **p) {
    Heap_Free(*p);
}
void ov45_0222D4CC(R28State *st, void **arg) {
    ov45_0222CDC4(st, arg, ov45_02254B44);
}
int ov45_0222D4DC(R28State *st) {
    if (ov45_0222A33C(st->context)) {
        ov45_0222CE2C(st, 10);
    } else {
        ov45_0222CE2C(st, 0);
    }
    return 0;
}
void ov45_0222D500(u8 *out, const s64 *seconds) {
    RTCDate date;
    RTCTime time;
    RTC_ConvertSecondToDateTime(&date, &time, *seconds);
    out[0] = time.hour;
    out[1] = time.minute;
    out[2] = time.second;
}
