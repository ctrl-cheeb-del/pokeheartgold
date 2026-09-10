#ifndef PRIVATE_FRONTIER_SYSTEM_H
#define PRIVATE_FRONTIER_SYSTEM_H
#include "global.h"

typedef struct FrontierScriptContext FrontierScriptContext;
typedef struct {
    void *parent;
    FrontierScriptContext *tasks[8];
    u16 halfwords[8];
    u32 heapId;
    u8 pad38[4];
    void *msgData;
    void *narcData;
    void *messageFormat;
    void *string1;
    void *string2;
    u8 pad50;
    s8 taskCount;
    u16 mode;
    u8 pad54[0x68];
} FrontierSystem;

struct FrontierScriptContext {
    FrontierSystem *system;
    u8 pad04[0x18];
    u32 script;
    u8 pad20[0x60];
    void *msgData;
    void *narcData;
    u8 pad88[8];
};

extern void *ov80_0223B9CC;
extern const u8 gFrontierCommandTable[];
void *Heap_Alloc(u32, u32);
void Heap_Free(void *);
void Heap_FreeExplicit(u32, void *);
void *MessageFormat_New_Custom(u32, u32, u32);
void MessageFormat_Delete(void *);
void *String_New(u32, u32);
void String_Delete(void *);
BOOL FrontierScriptContext_Run(FrontierScriptContext *);
void FrontierScriptContext_Init(FrontierScriptContext *, const void *, void *);
void FrontierScriptContext_Start(FrontierScriptContext *, void *);
u32 FrontierScriptContext_ReadWord(FrontierScriptContext *);
void ov80_02239C54(void *);
u32 ov80_0222ACA0(u32, u32);
void *AllocAndReadWholeNarcMemberByIdPair(u32, u32, u32);
void *NewMsgDataFromNarc(u32, u32, u32, u32);
void DestroyMsgData(void *);
void GF_AssertFail(void);
void *sub_0209680C(void *);

FrontierSystem *FrontierSystem_Create(void *, u32, u32);
BOOL FrontierSystem_Main(FrontierSystem *);
void ov80_0222A920(FrontierSystem *);
void FrontierSystem_AddTask(FrontierSystem *, u16, u32);
BOOL ov80_0222A9DC(FrontierSystem *, FrontierScriptContext *);
void ov80_0222AA0C(FrontierSystem *, FrontierScriptContext *);
void FrontierSystem_deadstripped_0222AA3C(FrontierSystem *, u16, u32, u32);
void ov80_0222AA40(void **, void **, u32, u32);
void ov80_0222AA7C(FrontierSystem *, u16, u32);
u16 *ov80_0222AAD8(FrontierSystem *, u32);
void ov80_0222AAF8(FrontierSystem *, u16 *);
void ov80_0222AB14(FrontierScriptContext *, u32);
u16 *ov80_0222AB2C(FrontierScriptContext *, u32);
void *FrontierSystem_GetFrontierMap(FrontierSystem *);
#endif
