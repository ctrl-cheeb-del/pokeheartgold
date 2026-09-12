#include "global.h"

#include <nitro/card.h>
#include <nitro/fs.h>
#include <nitro/hw/ARM9/mmap.h>
#include <nitro/mi.h>
#include <nitro/os.h>

#include "unk_02027010.h"

#define HW_ROM_HEADER_MIRROR   ((void *)0x027FF000)
#define HW_ROM_HEADER_MIRROR_2 ((void *)0x027FFA80)
#define HW_ROM_HEADER_VALID    ((u32 *)0x027FF00C)
#define ROM_GAME_CODE          0x4A414441
#define ROM_MAKER_CODE         0x3130

typedef struct RomHeaderFields {
    u8 pad00[0x0C];
    u32 gameCode;
    u16 makerCode;
    u8 pad12[0x2E];
    u32 fntOffset;
    u32 fntSize;
    u32 fatOffset;
    u32 fatSize;
} RomHeaderFields;

extern const char sRomArchiveName[];

void sub_02027010(void) {
    FSArchive *archive;
    RomHeaderFields *header = HW_ROM_HEADER_MIRROR;

    if (!FS_IsAvailable()) {
        OS_Terminate();
        return;
    }

    if (*HW_ROM_HEADER_VALID == 0) {
        CARD_Init();
        MI_CpuCopy8((const void *)HW_ROM_HEADER_BUF, HW_ROM_HEADER_MIRROR, 0x160);
        MI_CpuCopy8((const void *)HW_ROM_HEADER_BUF, HW_ROM_HEADER_MIRROR_2, 0x160);
        *HW_ROM_HEADER_VALID = ROM_GAME_CODE;
    }

    archive = FS_FindArchive(sRomArchiveName, 3);
    archive->fat = header->fatOffset;
    archive->fat_size = header->fatSize;
    archive->fnt = header->fntOffset;
    archive->fnt_size = header->fntSize;
    if (header->gameCode != ROM_GAME_CODE || header->makerCode != ROM_MAKER_CODE) {
        OS_Terminate();
    }
}

void sub_02027098(const char *path) {
    FSFile file;

    FS_InitFile(&file);
    if (FS_OpenFile(&file, path)) {
        *(u32 *)0x027FFC2C = file.prop.file.top;
        OS_ResetSystem(0);
    }
}
