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

u32 ECMenuBuild_Pokemon(ECMenu *menu, const u16 *words, u32 count, u16 *dest) {
    u32 n = 0;
    u32 i;
    Pokedex *pokedex = sub_02090D7C(menu->args);

    for (i = 0; i < count; i++) {
        if (Pokedex_CheckMonSeenFlag(pokedex, words[i])) {
            u32 word = words[i];
            menu->flags[word >> 3] |= 1 << (word & 7);
            n++;
            *dest = words[i];
            dest++;
        }
    }
    return n;
}

u32 ECMenuBuild_Move(ECMenu *menu, const u16 *words, u32 count, u16 *dest) {
    u32 i;

    if (sub_02090D84(menu->args)) {
        for (i = 0; i < count; i++) {
            u32 word = words[i];
            menu->flags[word >> 3] |= 1 << (word & 7);
            *dest = words[i];
            dest++;
        }
        return count;
    }
    return 0;
}

u32 ECMenuBuild_TrendySayings(ECMenu *menu, const u16 *words, u32 count, u16 *dest) {
    u32 i;
    u32 n;
    SaveEasyChat *saveEasyChat = sub_02090D80(menu->args);
    u32 base = GetECWordIndexByPair(0x122, 0); // NARC_msg_msg_0290_bin

    i = 0;
    n = i;
    for (; i < count; i++) {
        if (Save_EasyChat_GetTrendySayingFlag(saveEasyChat, words[i] - base)) {
            u32 word = words[i];
            menu->flags[word >> 3] |= 1 << (word & 7);
            n++;
            *dest = words[i];
            dest++;
        }
    }
    return n;
}

u32 ECMenuBuild_Greetings(ECMenu *menu, const u16 *words, u32 count, u16 *dest) {
    u32 n;
    struct {
        u32 i;
        u32 last;
        SaveEasyChat *saveEasyChat;
    } locals;
    locals.saveEasyChat = sub_02090D80(menu->args);
    u16 base = GetECWordIndexByPair(0x11F, 0); // NARC_msg_msg_0289_bin
    locals.last = (u16)(base + 5);

    n = 0;
    for (locals.i = 0; locals.i < count; locals.i++) {
        if (words[locals.i] < base || words[locals.i] > locals.last || Save_EasyChat_GetGreetingsFlag(locals.saveEasyChat, words[locals.i] - base)) {
            u32 word = words[locals.i];
            menu->flags[word >> 3] |= 1 << (word & 7);
            n++;
            *dest = words[locals.i];
            dest++;
        }
    }
    return n;
}

u32 ECMenuBuild_Generic(ECMenu *menu, const u16 *words, u32 count, u16 *dest) {
    u32 i;

    for (i = 0; i < count; i++) {
        if (*words == 0xFFFE) {
            const u16 *groupSizePtr = words + 1;
            u32 groupSize;
            words += 2;
            groupSize = *groupSizePtr;
            *dest = *words;
            while (groupSize != 0) {
                u32 word = *words;
                menu->flags[word >> 3] |= 1 << (word & 7);
                words++;
                groupSize--;
            }
        } else {
            u32 word = *words;
            menu->flags[word >> 3] |= 1 << (word & 7);
            *dest = *words;
            words++;
            dest++;
        }
    }
    return count;
}

void sub_02091B44(ECMenu *menu) {
    u32 total = 0;
    u32 i;

    for (i = 0; i < 27; i++) {
        menu->offsets2[i] = total;
        menu->counts2[i] = sub_02091B8C(menu, _02106C9C[i], menu->words2, total);
        total += menu->counts2[i];
    }
}

u32 sub_02091B8C(ECMenu *menu, const u16 *words, u16 *dest, u32 destIndex) {
    u32 n = 0;

    while (*words != 0xFFFF) {
        if (*words == 0xFFFE) {
            const u16 *groupSizePtr = words + 1;
            u32 groupSize;
            u32 j;
            words += 2;
            groupSize = *groupSizePtr;
            for (j = 0; j < groupSize; j++) {
                u32 word = words[j];
                if (menu->flags[word >> 3] & (1 << (word & 7))) {
                    dest[destIndex++] = words[j];
                    n++;
                    break;
                }
            }
            words += groupSize;
        } else {
            if (menu->flags[(u32)*words >> 3] & (1 << (*words & 7))) {
                dest[destIndex++] = *words;
                n++;
            }
            words++;
        }
    }
    return n;
}

u32 sub_02091C38(ECMenu *menu, u32 category) {
    return menu->counts[category];
}

void sub_02091C40(ECMenu *menu, u32 category, u32 index, String *dest) {
    u32 base = menu->offsets[category];
    EasyChatManager_ReadWordIntoString(menu->manager, menu->words[base + index], dest);
}

u16 sub_02091C60(ECMenu *menu, u32 category, u32 index) {
    u32 base = menu->offsets[category];
    return menu->words[base + index];
}

u32 sub_02091C74(ECMenu *menu, u32 group) {
    return menu->counts2[group];
}

void sub_02091C84(ECMenu *menu, u32 group, u32 index, String *dest) {
    if (menu->counts2[group] != 0) {
        EasyChatManager_ReadWordIntoString(menu->manager, sub_02091CAC(menu, group, index), dest);
    }
}

u16 sub_02091CAC(ECMenu *menu, u32 group, u32 index) {
    if (menu->counts2[group] != 0) {
        return menu->words2[menu->offsets2[group] + index];
    }
    return 0xFFFF;
}
