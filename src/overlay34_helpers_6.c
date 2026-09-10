#include "global.h"

typedef struct {
    u8 raw[0x400];
} Ov34State;
extern u8 gSystem[];
extern void *NewString_ReadMsgData(void *, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, void *);
extern void String_Delete(void *);
extern int ov01_021F6B10(void *);
extern void ov34_0225E58C(Ov34State *);
extern void ov34_0225E4F8(Ov34State *);
extern void ov34_0225DE04(Ov34State *);
extern void ov34_0225E164(Ov34State *);
extern void ov34_0225DD04(Ov34State *);
extern void ov34_0225E630(Ov34State *);
extern void RemoveWindow(void *);
extern void FreeBgTilemapBuffer(void *, int);
extern int Sprite_GetAnimationFrame(void *);
extern int Sprite_GetAnimationNumber(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern int Sprite_GetAnimActiveFlag(void *);
extern void Sprite_SetAnimActiveFlag(void *, int);
extern void Sprite_SetAnimationFrame(void *, int);
extern void *MessageFormat_New(int);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *GfGfxLoader_GetScrnData(int, int, int, void **, int);
extern void FontID_SetAccessLazy(int);
extern void SpriteTransfer_DeleteCharTransferTask(void *);
extern void SpriteTransfer_DeletePlttTransferTask(void *);
extern void Destroy2DGfxResObjMan(void *);
extern void SpriteList_Delete(void *);
extern void DestroyMsgData(void *);
extern void MessageFormat_Delete(void *);
extern void Heap_Free(void *);
extern void DestroySysTaskAndEnvironment(void *);
extern void GF_AssertFail(void);
extern void Sprite_SetMatrix(void *, const VecFx32 *);
extern void *CreateSysTaskAndEnvironment(void (*)(void *, void *), int, int, int);
extern void *SysTask_GetData(void *);
extern void *Save_PlayerData_GetProfile(void *);
extern void ov34_0225D5A0(void *, Ov34State *);
extern void ov34_0225D924(void *);
extern void SetKeyRepeatTimers(int, int);
extern void ov34_0225DA50(Ov34State *);
extern void ov34_0225DB20(Ov34State *);
extern void FontID_SetAccessDirect(int, int);
extern void ov34_0225D650(void *, void *, void *);
extern void GfGfx_EngineBTogglePlanes(int, int);
extern int FieldSystem_TaskIsRunning(void *);
extern void SpriteList_RenderAndAnimateSprites(void *);
extern void ov01_021F6A9C(void *, int, int);
extern void PlaySE(int);
extern void ov34_0225E348(Ov34State *, u32, u32, u32);

void ov34_0225D520(Ov34State *);
void ov34_0225D558(Ov34State *);
void ov34_0225D5A0(void *, Ov34State *);
void ov34_0225D77C(void *, void *);
void ov34_0225D5F8(Ov34State *);
void *ov34_0225D7A8(void *);
void ov34_0225D87C(Ov34State *);
void ov34_0225DDB8(void *, int);
void ov34_0225D900(void *);
int ov34_0225DC00(int, int);
int ov34_0225DC0C(int, int);
void ov34_0225E560(Ov34State *);
void ov34_0225E56C(Ov34State *);
void ov34_0225E58C(Ov34State *);
int ov34_0225E5D4(Ov34State *);
void ov34_0225E5DC(Ov34State *, void *);
void *ov34_0225E5E4(Ov34State *);
void ov34_0225E5EC(Ov34State *, int);
void ov34_0225E630(Ov34State *);
void ov34_0225E0E4(Ov34State *);
void ov34_0225E4A8(Ov34State *, u32, u32, u32);

void ov34_0225E0E4(Ov34State *p) {
    u32 held = *(u32 *)(gSystem + 0x44);
    if (held & 0x200) {
        ov34_0225E5EC(p, 0);
        if ((*(u32 *)(gSystem + 0x4C) & 0x200) && *(u16 *)((u8 *)p + 0x288)) {
            --*(u16 *)((u8 *)p + 0x288);
            PlaySE(0x5E5);
        }
    } else if (held & 0x100) {
        ov34_0225E5EC(p, 1);
        if ((*(u32 *)(gSystem + 0x4C) & 0x100) && *(u16 *)((u8 *)p + 0x288) < *(u16 *)((u8 *)p + 0x284) - 3) {
            ++*(u16 *)((u8 *)p + 0x288);
            PlaySE(0x5E5);
        }
    }
}
