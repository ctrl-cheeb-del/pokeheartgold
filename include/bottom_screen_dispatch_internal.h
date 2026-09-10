#ifndef PRIVATE_OV01_021EAF00_H
#define PRIVATE_OV01_021EAF00_H
#include "global.h"

#include "filesystem.h"
typedef struct LocalFieldSystem {
    u8 pad00[0x18];
    int bottomScreenType;
    u8 pad1C[0xBC];
    void *viewPhotoTask;
} LocalFieldSystem;
typedef void (*BottomScreenVoidFunc)(LocalFieldSystem *);
typedef BOOL (*BottomScreenBoolFunc)(LocalFieldSystem *);
typedef struct BottomScreenOps {
    BottomScreenVoidFunc init;
    BottomScreenBoolFunc running;
    BottomScreenVoidFunc end;
    BottomScreenBoolFunc done;
} BottomScreenOps;
void GF_AssertFail(void);
void HandleLoadOverlay(int, int);
void UnloadOverlayByID(int);
void *FieldSystem_CreateViewPhotoTask(LocalFieldSystem *);
void FieldSystem_DestroyViewPhotoTask(LocalFieldSystem *);
void ov01_021F6894(LocalFieldSystem *);
void ov01_021F68B8(LocalFieldSystem *);
BOOL ov01_021F68C0(LocalFieldSystem *);
void ov01_021F6840(LocalFieldSystem *);
void ov01_021F6864(LocalFieldSystem *);
BOOL ov01_021F6874(LocalFieldSystem *);
void sub_0203DB6C(LocalFieldSystem *);
void sub_0203DB70(LocalFieldSystem *);
BOOL sub_0203DB74(LocalFieldSystem *);
int ov01_021EAF00(LocalFieldSystem *);
void FieldSystem_InitBottomScreen(LocalFieldSystem *);
BOOL FieldSystem_IsBottomScreenRunningDummy(LocalFieldSystem *);
void FieldSystem_EndBottomScreen(LocalFieldSystem *);
BOOL FieldSystem_IsBottomScreenDone(LocalFieldSystem *);
void ov01_021EAF8C(LocalFieldSystem *);
void ov01_021EAF90(LocalFieldSystem *);
BOOL ov01_021EAF94(LocalFieldSystem *);
void ov01_021EAF98(LocalFieldSystem *);
void ov01_021EAFB4(LocalFieldSystem *);
BOOL ov01_021EAFD0(LocalFieldSystem *);
#endif
