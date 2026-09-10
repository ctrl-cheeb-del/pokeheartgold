#include "constants/gx.h"

#include "apricorn_box_overlay_internal.h"

FS_EXTERN_OVERLAY(OVY_59);

BOOL ov59_02237D40(OverlayManager *man, int *state);
BOOL ov59_02237DA8(OverlayManager *man, int *state);
BOOL ov59_02237E68(OverlayManager *man, int *state);
BOOL ov59_0223A8E0(OverlayManager *man, int *state);
BOOL ov59_0223A948(OverlayManager *man, int *state);
BOOL ov59_0223A9B8(OverlayManager *man, int *state);

BOOL ov58_022378C0(OverlayManager **pMan);
BOOL ApricornBox_Init(OverlayManager *man, int *state);
BOOL ApricornBox_Main(OverlayManager *man, int *state);
BOOL ApricornBox_Exit(OverlayManager *man, int *state);
void ov58_022379C0(UnkStruct_02031CEC *record, Party *party, int slot);
void ov58_02237B40(ApricornBoxApp *app);
void ov58_02237B94(ApricornBoxApp *app);
int ov58_02237B98(ApricornBoxApp *app);
int ov58_02237BB0(ApricornBoxApp *app);
int ov58_02237BD4(ApricornBoxApp *app);
int ov58_02237C4C(ApricornBoxApp *app);
int ov58_02237C88(ApricornBoxApp *app);
int ov58_02237CA0(ApricornBoxApp *app);
void ov58_02237CCC(void);

static const OverlayManagerTemplate _02237D1C = {
    ov59_02237D40,
    ov59_02237DA8,
    ov59_02237E68,
    FS_OVERLAY_ID(OVY_59),
};

static const OverlayManagerTemplate ov58_02237D2C = {
    ov59_0223A8E0,
    ov59_0223A948,
    ov59_0223A9B8,
    FS_OVERLAY_ID(OVY_59),
};

BOOL ov58_022378C0(OverlayManager **pMan) {
    if (*pMan != NULL && OverlayManager_Run(*pMan)) {
        OverlayManager_Delete(*pMan);
        *pMan = NULL;
        return TRUE;
    }
    return FALSE;
}

BOOL ApricornBox_Init(OverlayManager *man, int *state) {
    ApricornBoxApp *app;

    ov58_02237CCC();
    Heap_Create(HEAP_ID_3, HEAP_ID_133, 0x2000);
    app = OverlayManager_CreateAndGetData(man, sizeof(ApricornBoxApp), HEAP_ID_133);
    MI_CpuFill8(app, 0, sizeof(ApricornBoxApp));
    app->heapId = HEAP_ID_133;
    app->args = OverlayManager_GetArgs(man);
    ov58_02237B40(app);
    return TRUE;
}

BOOL ApricornBox_Main(OverlayManager *man, int *state) {
    ApricornBoxApp *app = OverlayManager_GetData(man);

    switch (*state) {
    case 0:
        if (app->args->unk0 == 3) {
            *state = 3;
        } else {
            *state = 1;
        }
        break;
    case 1:
        *state = ov58_02237B98(app);
        break;
    case 2:
        *state = ov58_02237BB0(app);
        break;
    case 3:
        *state = ov58_02237BD4(app);
        break;
    case 4:
        *state = ov58_02237C4C(app);
        break;
    case 5:
        *state = ov58_02237C88(app);
        break;
    case 6:
        *state = ov58_02237CA0(app);
        break;
    case 7:
        return TRUE;
    }
    return FALSE;
}

BOOL ApricornBox_Exit(OverlayManager *man, int *state) {
    ApricornBoxApp *app = OverlayManager_GetData(man);

    ov58_02237CCC();
    ov58_02237B94(app);
    OverlayManager_FreeData(man);
    Heap_Destroy(HEAP_ID_133);
    return TRUE;
}

void ov58_022379C0(UnkStruct_02031CEC *record, Party *party, int slot) {
    s8 newMods[5];
    PartyExtraSub modifiers;
    ApricornJuiceData juice;
    u32 statA;
    u32 statB;
    u32 amtA;
    u32 amtB;
    u32 total;
    u8 penalty;
    u8 level;
    int i;

    MI_CpuFill8(newMods, 0, 5);
    sub_02031DA0(record, &juice);
    level = record->unk2;
    if (juice.entries[0].stat >= 5) {
        statA = juice.statOverride[0];
    } else {
        statA = (u8)juice.entries[0].stat;
    }
    if (juice.entries[1].stat >= 5) {
        statB = juice.statOverride[1];
    } else {
        statB = (u8)juice.entries[1].stat;
    }
    Party_GetMonAprijuiceModifiers(party, &modifiers, slot);
    amtA = juice.entries[0].amount;
    newMods[statA] = (u8)(1.5f * (float)amtA);
    if (amtA != 0) {
        newMods[statA] += 10;
    }
    amtB = juice.entries[1].amount;
    newMods[statB] = (u8)(1.5f * (float)amtB);
    total = (u8)(amtA + amtB);
    if (level == 0xFF) {
        penalty = (u8)(0.1f * (float)total);
    } else if (level >= 0xC8) {
        penalty = (u8)(0.2f * (float)total);
    } else {
        penalty = (u8)((float)total * (1.0f - 0.1f * (float)(u8)(level / 25)));
    }
    newMods[juice.penaltyStat] -= penalty;
    for (i = 0; i < 5; i++) {
        int v = newMods[i];
        if (v < -127) {
            v = -127;
        } else if (v > 127) {
            v = 127;
        }
        modifiers.unk_00[i] = v;
    }
    Party_SetMonAprijuiceModifiers(party, &modifiers, slot);
    ApplyMonMoodModifier(Party_GetMonByIndex(party, slot), 7);
}

void ov58_02237B40(ApricornBoxApp *app) {
    if (app->args->unk8 != NULL) {
        *app->args->unk8 = 0;
    }
    switch (app->args->unk0) {
    case 0:
        app->unk_18 = 0;
        break;
    case 1:
        app->unk_18 = 1;
        break;
    case 2:
        app->unk_18 = 2;
        break;
    case 3:
        app->unk_19 = 1;
        app->unk_18 = 0;
        app->unk_14 = app->args->unkC;
        return;
    }
    app->unk_19 = 0;
    app->unk_14 = 8;
}

void ov58_02237B94(ApricornBoxApp *app) {
}

int ov58_02237B98(ApricornBoxApp *app) {
    app->child = OverlayManager_New(&_02237D1C, app, app->heapId);
    return 2;
}

int ov58_02237BB0(ApricornBoxApp *app) {
    if (!ov58_022378C0(&app->child)) {
        return 2;
    }
    if (app->unk_18 == 3) {
        app->unk_1C = 0;
        return 3;
    }
    return 7;
}

int ov58_02237BD4(ApricornBoxApp *app) {
    PartyMenuArgs *args = Heap_Alloc(app->heapId, sizeof(PartyMenuArgs));

    MI_CpuFill8(args, 0, sizeof(PartyMenuArgs));
    args->party = SaveArray_Party_Get(app->args->saveData);
    args->bag = Save_Bag_Get(app->args->saveData);
    args->unk_25 = 0;
    args->context = PARTY_MENU_CONTEXT_20;
    args->options = Save_PlayerData_GetOptionsAddr(app->args->saveData);
    args->mailbox = Save_Mailbox_Get(app->args->saveData);
    args->fieldSystem = NULL;
    args->menuInputStatePtr = app->args->menuInputStatePtr;
    args->partySlot = app->unk_1C;
    app->child = OverlayManager_New(&gOverlayTemplate_PartyMenu, args, app->heapId);
    app->partyMenuArgs = args;
    return 4;
}

int ov58_02237C4C(ApricornBoxApp *app) {
    u8 slot;

    if (!ov58_022378C0(&app->child)) {
        return 4;
    }
    slot = app->partyMenuArgs->partySlot;
    app->unk_1C = slot;
    Heap_Free(app->partyMenuArgs);
    app->partyMenuArgs = NULL;
    if (slot == 7) {
        if (app->args->unk0 == 3) {
            return 7;
        }
        return 1;
    }
    return 5;
}

int ov58_02237C88(ApricornBoxApp *app) {
    app->child = OverlayManager_New(&ov58_02237D2C, app, app->heapId);
    return 6;
}

int ov58_02237CA0(ApricornBoxApp *app) {
    if (!ov58_022378C0(&app->child)) {
        return 6;
    }
    if (app->unk_18 == 3) {
        return 3;
    }
    if (app->args->unk0 == 3) {
        return 7;
    }
    return 1;
}

void ov58_02237CCC(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
    sub_0200FBF4(PM_LCD_TOP, RGB_BLACK);
    sub_0200FBF4(PM_LCD_BOTTOM, RGB_BLACK);
    ResetVisibleHardwareWindows(PM_LCD_TOP);
    ResetVisibleHardwareWindows(PM_LCD_BOTTOM);
}
