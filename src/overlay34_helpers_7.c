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

void ov34_0225E560(Ov34State *p) {
    *(u32 *)((u8 *)p + 0x294) = 1;
}

void ov34_0225E56C(Ov34State *p) {
    *((u8 *)p + 0x298) = 0;
    *((u8 *)p + 0x29A) = 8;
    *((u8 *)p + 0x29B) = 4;
    *((u8 *)p + 0x299) = *((u8 *)p + 0x29A);
}

void ov34_0225E58C(Ov34State *p) {
    *((u8 *)p + 0x298) = 0;
    if (*(u16 *)(gSystem + 0x64) != 0) {
        *((u8 *)p + 0x298) = 1;
        return;
    }
    if (*(u16 *)(gSystem + 0x66) != 0) {
        *((u8 *)p + 0x299) = *((s8 *)p + 0x299) - 1;
        if (*((s8 *)p + 0x299) < 0) {
            *((u8 *)p + 0x298) = 1;
            *((u8 *)p + 0x299) = *((u8 *)p + 0x29B);
        }
    } else {
        *((u8 *)p + 0x299) = *((u8 *)p + 0x29A);
    }
}

int ov34_0225E5D4(Ov34State *p) {
    return *((u8 *)p + 0x298);
}

void ov34_0225E5DC(Ov34State *p, void *v) {
    *(void **)((u8 *)p + 0x29C) = v;
}

void *ov34_0225E5E4(Ov34State *p) {
    return *(void **)((u8 *)p + 0x29C);
}

void ov34_0225E5EC(Ov34State *p, int i) {
    int frame = Sprite_GetAnimationFrame(*(void **)((u8 *)p + 0x198 + i * 4));
    u16 anim = Sprite_GetAnimationNumber(*(void **)((u8 *)p + 0x198 + i * 4));
    if (frame != 0 || anim != i + 4) {
        Sprite_SetAnimCtrlSeq(*(void **)((u8 *)p + 0x198 + i * 4), i + 4);
    }
    *(u16 *)((u8 *)p + 0x2A0 + i * 2) = 1;
}
