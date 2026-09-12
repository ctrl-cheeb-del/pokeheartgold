#include "easy_chat_menu_private.h"

ECMenu *sub_02091880(enum HeapID heapID, EasyChatArgs *args);
void sub_020918C0(ECMenu *menu);
void sub_020918D4(ECMenu *menu);
u32 ECMenuBuild_Pokemon(ECMenu *menu, const u16 *words, u32 count, u16 *dest);
u32 ECMenuBuild_Move(ECMenu *menu, const u16 *words, u32 count, u16 *dest);
u32 ECMenuBuild_TrendySayings(ECMenu *menu, const u16 *words, u32 count, u16 *dest);
u32 ECMenuBuild_Greetings(ECMenu *menu, const u16 *words, u32 count, u16 *dest);
u32 ECMenuBuild_Generic(ECMenu *menu, const u16 *words, u32 count, u16 *dest);
void sub_02091B44(ECMenu *menu);
u32 sub_02091B8C(ECMenu *menu, const u16 *words, u16 *dest, u32 destIndex);
u32 sub_02091C38(ECMenu *menu, u32 category);
void sub_02091C40(ECMenu *menu, u32 category, u32 index, String *dest);
u16 sub_02091C60(ECMenu *menu, u32 category, u32 index);
u32 sub_02091C74(ECMenu *menu, u32 group);
void sub_02091C84(ECMenu *menu, u32 group, u32 index, String *dest);
u16 sub_02091CAC(ECMenu *menu, u32 group, u32 index);

extern const u16 *const _02106C9C[];

ECMenu *sub_02091880(enum HeapID heapID, EasyChatArgs *args) {
    ECMenu *menu = Heap_Alloc(heapID, sizeof(ECMenu));
    s32 i;

    menu->args = args;
    menu->manager = EasyChatManager_New(heapID);
    for (i = 0; i < 0xBB; i++) {
        menu->flags[i] = 0;
    }
    sub_020918D4(menu);
    sub_02091B44(menu);
    return menu;
}

void sub_020918C0(ECMenu *menu) {
    if (menu != NULL) {
        EasyChatManager_Delete(menu->manager);
        Heap_Free(menu);
    }
}
