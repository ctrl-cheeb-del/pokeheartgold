#include "global.h"

extern void *Heap_AllocAtEnd(int heapId, u32 size);
extern void *Save_PlayerData_GetProfile(void *saveData);
extern void sub_0208AD34(void *, void *);
extern BOOL SaveArray_IsNatDexEnabled(void *);
extern int sub_02088288(void *);
extern void *Save_PlayerData_GetOptionsAddr(void *saveData);
extern int Party_GetCount(void *);
extern void *Save_SpecialRibbons_Get(void *);
extern BOOL sub_0208828C(void *);
extern void sub_02089D40(void *, const u8 *);
extern void FieldSystem_LaunchApplication(void *, const void *, void *);
ALIGN(4)
const u8 _020FC7CC[8] = { 0, 1, 2, 3, 4, 0, 0, 0 };
ALIGN(4)
u8 _021D41CC[0xC] = { 0 };
ALIGN(4)
u8 _021D41D8[0x40] = { 0 };
extern const u8 gOverlayTemplate_PokemonSummary[];
extern void *Heap_Alloc(int heapId, u32 size);
extern void *SaveArray_Party_Get(void *saveData);
extern void *Save_Bag_Get(void *saveData);
extern int LinkBattleRuleset_GetRuleValue(void *, int);
extern const u8 gOverlayTemplate_PartyMenu[];

typedef struct PartyMenuArgs58 {
    u8 raw_00[0x30];
    u8 choices[6];
    u8 ruleA : 4;
    u8 ruleB : 4;
    u8 level;
    u8 raw_38[0xC];
} PartyMenuArgs58;

typedef struct Context58 {
    u8 raw_00[0x3D];
    u8 choices[6];
} Context58;

void sub_02058AEC(void **result, void *fieldSystem, void *party, int slot, int kind, int heapId);
void sub_02058B84(u8 *context, int heapId);

void sub_02058AEC(void **result, void *fieldSystem, void *party, int slot, int kind, int heapId) {
    void *saveData = *(void **)((u8 *)fieldSystem + 0xC);
    u8 *args = Heap_AllocAtEnd(heapId, 0x3C);
    MI_CpuFill8(args, 0, 0x3C);
    sub_0208AD34(args, Save_PlayerData_GetProfile(*(void **)((u8 *)fieldSystem + 0xC)));
    *(u32 *)(args + 0x1C) = SaveArray_IsNatDexEnabled(saveData);
    *(u32 *)(args + 0x2C) = sub_02088288(saveData);
    *(void **)(args + 4) = Save_PlayerData_GetOptionsAddr(saveData);
    *(void **)args = party;
    args[0x11] = 1;
    args[0x14] = slot;
    args[0x13] = Party_GetCount(*(void **)args);
    *(u16 *)(args + 0x18) = 0;
    args[0x12] = kind;
    *(void **)(args + 0x20) = Save_SpecialRibbons_Get(saveData);
    *(u32 *)(args + 0x30) = 0;
    *(u32 *)(args + 0x34) = sub_0208828C(saveData);
    sub_02089D40(args, _020FC7CC);
    FieldSystem_LaunchApplication(fieldSystem, gOverlayTemplate_PokemonSummary, args);
    *result = args;
}

void sub_02058B84(u8 *context, int heapId) {
    PartyMenuArgs58 *args = Heap_Alloc(heapId, 0x44);
    int i;
    MI_CpuFill8(args, 0, 0x44);
    *(void **)((u8 *)args + 0xC) = Save_PlayerData_GetOptionsAddr(*(void **)(*(u8 **)(context + 0x24) + 0xC));
    *(void **)((u8 *)args + 0x14) = *(void **)(*(u8 **)(context + 0x24) + 0xA4);
    *(void **)((u8 *)args + 0x00) = SaveArray_Party_Get(*(void **)(*(u8 **)(context + 0x24) + 0xC));
    *(void **)((u8 *)args + 0x04) = Save_Bag_Get(*(void **)(*(u8 **)(context + 0x24) + 0xC));
    *(void **)((u8 *)args + 0x20) = *(u8 **)(context + 0x24) + 0x10C;
    *((u8 *)args + 0x25) = 0;
    *((u8 *)args + 0x24) = 2;
    if (*(void **)(*(u8 **)(context + 0x24) + 0xA4) != NULL) {
        args->ruleA = LinkBattleRuleset_GetRuleValue(*(void **)(*(u8 **)(context + 0x24) + 0xA4), 1);
        args->ruleB = args->ruleA;
    } else {
        args->ruleA = 3;
        args->ruleB = 3;
    }
    args->level = 100;
    *((u8 *)args + 0x26) = context[0x3C];
    for (i = 0; i < 6; i++) {
        args->choices[i] = context[i + 0x3D];
    }
    FieldSystem_LaunchApplication(*(void **)(context + 0x24), gOverlayTemplate_PartyMenu, args);
    *(void **)(context + 4) = args;
}
