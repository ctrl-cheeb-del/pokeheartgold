#include "global.h"

extern void GF_3DVramMan_Delete(void *);
extern void Camera_Delete(void *);
extern void sub_02018068(void *);
extern void *ov45_0222E9E0(void *);
extern void FontOAM_Delete(void *);
extern void sub_02021B5C(void *);
extern void Heap_Free(void *);
extern void ClearWindowTilemapAndCopyToVram(void *);
extern void RemoveWindow(void *);
extern int ov89_0225AEA8(void *, void *);
extern void GF_AssertFail(void);
extern int ov45_0222D844(void *);
extern void ov45_0222EFAC(int, void *, int);
extern void FreeBgTilemapBuffer(void *, int);

void ov89_0225A468(void);
int ov89_0225B078(void);
void ov89_02259E10(void *);
void *ov89_02259E48(u8 *);
void ov89_02259BA0(u8 *);
void ov89_02259C00(u8 *);
void ov89_0225A160(u8 *, u32);
void ov89_02259E18(u8 *);
void ov89_0225A46C(void *);
void ov89_0225A354(u8 *);
void ov89_0225AC10(u8 *);
void ov89_0225C818(u8 *, u32);
BOOL ov89_0225B148(void *, u8 *);
BOOL ov89_0225B450(void *, u8 *);
BOOL ov89_0225B604(void *, u8 *);
BOOL ov89_0225B810(void *, u8 *);
BOOL ov89_0225B900(void *, u8 *);
BOOL ov89_0225B978(void *, u8 *);
BOOL ov89_0225BE68(void *, u8 *);
void ov89_02259D50(u8 *);
void ov89_02259E28(void *, u8 *);
void ov89_0225A47C(u8 *);
BOOL ov89_0225C91C(void *);
void ov89_0225AF9C(u8 *);
BOOL ov89_0225AEA8(void *, void *);
BOOL ov89_0225A958(u8 *, void *);
void ov89_0225A988(u8 *, void *);
void ov89_02259230(void *);

void ov89_0225C818(u8 *p, u32 n) {
    if (n >= 8) {
        GF_AssertFail();
    } else {
        ClearWindowTilemapAndCopyToVram(p + n * 16);
    }
}
