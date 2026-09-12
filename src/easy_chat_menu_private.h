#ifndef PRIVATE_UNK_02091880_H
#define PRIVATE_UNK_02091880_H

#include "global.h"

#include "easy_chat.h"
#include "heap.h"
#include "mail_misc.h"
#include "pokedex.h"

typedef struct ECMenu ECMenu;

typedef u32 (*ECMenuBuildFunc)(ECMenu *menu, const u16 *words, u32 count, u16 *dest);

typedef struct ECMenuSpec {
    ECMenuBuildFunc func;
    const u16 *words;
    u32 count;
} ECMenuSpec;

// Total 0x195C. Field offsets pinned by the literal pool of the original:
//   flags at 0x189E (sub_02091880), counts2 at 0xC18, offsets2 at 0xC84,
//   words2 at 0xCF0 (sub_02091B44 / sub_02091CAC), words at 0x68 (sub_020918D4).
struct ECMenu {
    EasyChatArgs *args;       // 0x0000
    EasyChatManager *manager; // 0x0004
    u32 counts[12];           // 0x0008
    u32 offsets[12];          // 0x0038
    u16 words[1496];          // 0x0068
    u32 counts2[27];          // 0x0C18
    u32 offsets2[27];         // 0x0C84
    u16 words2[1495];         // 0x0CF0
    u8 flags[0xBB];           // 0x189E .. 0x1958, padded to 0x195C
};

#endif // PRIVATE_UNK_02091880_H
