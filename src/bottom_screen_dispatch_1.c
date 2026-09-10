#include "bottom_screen_dispatch_internal.h"

FS_EXTERN_OVERLAY(OVY_19);

static const BottomScreenOps sBottomScreenOps[];

int ov01_021EAF00(LocalFieldSystem *fieldSystem) {
    int type = fieldSystem->bottomScreenType;
    if (type == 0) {
        GF_AssertFail();
    }
    if (type >= 7) {
        GF_AssertFail();
    }
    return type - 1;
}

void FieldSystem_InitBottomScreen(LocalFieldSystem *fieldSystem) {
    sBottomScreenOps[ov01_021EAF00(fieldSystem)].init(fieldSystem);
}

BOOL FieldSystem_IsBottomScreenRunningDummy(LocalFieldSystem *fieldSystem) {
    BottomScreenBoolFunc func = sBottomScreenOps[ov01_021EAF00(fieldSystem)].running;
    if (func == NULL) {
        return TRUE;
    }
    return func(fieldSystem);
}

void FieldSystem_EndBottomScreen(LocalFieldSystem *fieldSystem) {
    sBottomScreenOps[ov01_021EAF00(fieldSystem)].end(fieldSystem);
}

BOOL FieldSystem_IsBottomScreenDone(LocalFieldSystem *fieldSystem) {
    return sBottomScreenOps[ov01_021EAF00(fieldSystem)].done(fieldSystem);
}

void ov01_021EAF8C(LocalFieldSystem *fieldSystem) {
}

void ov01_021EAF90(LocalFieldSystem *fieldSystem) {
}

BOOL ov01_021EAF94(LocalFieldSystem *fieldSystem) {
    return TRUE;
}

void ov01_021EAF98(LocalFieldSystem *fieldSystem) {
    HandleLoadOverlay(FS_OVERLAY_ID(OVY_19), 2);
    fieldSystem->viewPhotoTask = FieldSystem_CreateViewPhotoTask(fieldSystem);
}

void ov01_021EAFB4(LocalFieldSystem *fieldSystem) {
    FieldSystem_DestroyViewPhotoTask(fieldSystem);
    fieldSystem->viewPhotoTask = NULL;
    UnloadOverlayByID(FS_OVERLAY_ID(OVY_19));
}

BOOL ov01_021EAFD0(LocalFieldSystem *fieldSystem) {
    return TRUE;
}

static const BottomScreenOps sBottomScreenOps[] = {
    { ov01_021F6894, NULL, ov01_021F68B8, ov01_021F68C0 },
    { ov01_021EAF8C, NULL, ov01_021EAF90, ov01_021EAF94 },
    { ov01_021F6894, NULL, ov01_021F68B8, ov01_021F68C0 },
    { ov01_021F6840, NULL, ov01_021F6864, ov01_021F6874 },
    { sub_0203DB6C,  NULL, sub_0203DB70,  sub_0203DB74  },
    { ov01_021EAF98, NULL, ov01_021EAFB4, ov01_021EAFD0 },
};
