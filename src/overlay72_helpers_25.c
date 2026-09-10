#include "global.h"

typedef struct Overlay72State {
    u8 data[0x1400];
} Overlay72State;
extern u32 _0223B820[];
void *OverlayManager_GetArgs(void *);
int YesNoPrompt_HandleInput(void *);
void YesNoPrompt_Destroy(void *);
int ov00_021EC9D4(void);
void ov00_021ECD04(void);
void ov72_02237CB0(void *);
void ov00_021EC8D8(void);
void sub_0203A880(void);
void *sub_0200F450(void *);
int IsPaletteFadeFinished(void);
int ov72_0223A8A0(void *);
int ov72_0223AE6C(void *);
void Sprite_SetDrawFlag(void *, int);
void ov72_0223B2FC(void *, int);
void ov72_022387D0(u8 *, u32, u32);
void Save_PrepareForAsyncWrite(void *, int);

void ov72_02238144(u8 *, void *);
int ov72_02238668(void *);
int ov72_02239E9C(u8 *);
void SysTask_Destroy(void *);
void FreeBgTilemapBuffer(void *, int);
void RemoveWindow(void *);
void String_Delete(void *);
int Save_WriteFileAsync(void *);
extern NNSFndHeapHandle ov72_0223B92C;
int ov72_02237B54(void);
void ov72_022383DC(u8 *, u8 *, u32, u32);
void *ov72_02238778(u32, u32);
void ov72_022387A0(u32, void *);
void ov72_02238AEC(void *);
void ov72_02238FFC(u8 *);
void ov72_02239098(u8 *);
int ov72_02239EB4(u8 *);
void ov72_02237B80(u32);
void ov72_0223A420(void *);
void ov72_0223A520(void *, int, u32);
int ov72_0223A588(void *);
void ov72_02237BD0(u32, u32, void *);
int ov72_02239614(u8 *);
int ov72_0223988C(u8 *);
int ov72_02239BC8(u8 *);
int ov72_02239BEC(u8 *);
int ov72_02239C8C(u8 *);
int ov72_02239CB4(u8 *);
int ov72_02239D3C(u8 *);
void ov72_0223A350(u8 *, void *, int, int, int);
void ov72_0223A280(u8 *, void *, int, int, int);
int ov72_022390D8(u8 *);
int ov72_02239168(u8 *);
int ov72_0223985C(u8 *);
int ov72_02239A08(u8 *);
int ov72_02239B98(u8 *);
int ov72_02239ED4(u8 *);
int ov72_02239F30(u8 *);
int ov72_022399CC(u8 *);
int ov72_02239B5C(u8 *);
int ov72_0223897C(u8 *);
void ov72_022378C0(u32, u32, u32);
u32 ov72_02237B74(void);
void ov72_02238160(void);
void ov72_02238680(u8 *, u32, u32);
int ov72_022387C4(void);
void ov72_022387D0(u8 *, u32, u32);
int ov72_022392AC(u8 *);
int ov72_022393B0(u8 *);
int ov72_02239E94(u8 *);
int ov72_02239E9C(u8 *);
int ov72_02239FBC(u8 *);
int ov72_0223A010(void);
void ov72_0223A414(void);
void ov72_0223A41C(u8 *, int, int);
void ov72_0223A444(u8 *);
int ov72_0223A71C(u8 *);
int ov72_0223A8DC(u8 *);
int ov72_0223ABF4(void);
int ov72_0223ABF8(void);
int ov72_0223ABFC(void);
int ov72_0223AC6C(u8 *);
int ov72_0223AC88(u8 *);
int ov72_0223ACA4(void);
int ov72_0223AF70(u8 *);
int ov72_0223B084(void);
void ov72_0223B2E4(u8 *);

int ov72_0223A71C(u8 *p) {
    if (IsPaletteFadeFinished() == 1) {
        p[0x1312] = 3;
    }
    return 0;
}
