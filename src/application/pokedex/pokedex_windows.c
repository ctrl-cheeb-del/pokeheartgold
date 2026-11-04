#include "global.h"

#include "constants/species.h"

#include "application/pokedex/pokedex_internal.h"
#include "application/pokedex/pokedex_text_util.h"
#include "graphic/zukan_gra.naix"
#include "msgdata/msg.naix"
#include "msgdata/msg/msg_0802.h"

#include "bg_window.h"
#include "dex_mon_measures.h"
#include "font.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "map_header.h"
#include "message_format.h"
#include "message_printer.h"
#include "msgdata.h"
#include "pokedex.h"
#include "pokedex_language.h"
#include "pokedex_util.h"
#include "text.h"

static const WindowTemplate sPokedexEntryMenuWindowTemplates[] = {
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 9,  .height = 2, .palette = 2, .baseTile = 0x3EE },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 10, .top = 10, .width = 15, .height = 2, .palette = 1, .baseTile = 0x1E2 },
};

static const u16 sSearchTypeMsgIds[] = { 58, 50, 60, 56, 54, 48, 63, 53, 59, 61, 62, 51, 55, 49, 52, 57, 47, 64 };

static const WindowTemplate sSizeCheckWindowTemplates[] = {
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 9,  .height = 2, .palette = 2, .baseTile = 0x3EE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 4,  .top = 3,  .width = 8,  .height = 2, .palette = 1, .baseTile = 0x3DE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 20, .top = 3,  .width = 8,  .height = 2, .palette = 1, .baseTile = 0x3CE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 10, .top = 6,  .width = 12, .height = 2, .palette = 1, .baseTile = 0x3B6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 21, .width = 4,  .height = 2, .palette = 2, .baseTile = 0x3AE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 21, .width = 8,  .height = 2, .palette = 2, .baseTile = 0x39E },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 17, .top = 21, .width = 4,  .height = 2, .palette = 2, .baseTile = 0x396 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 22, .top = 21, .width = 8,  .height = 2, .palette = 2, .baseTile = 0x386 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 10, .top = 1,  .width = 12, .height = 2, .palette = 1, .baseTile = 0x1E8 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 2,  .top = 17, .width = 4,  .height = 2, .palette = 1, .baseTile = 0x1E0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 7,  .top = 17, .width = 8,  .height = 2, .palette = 1, .baseTile = 0x1D0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 17, .top = 17, .width = 4,  .height = 2, .palette = 1, .baseTile = 0x1C8 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 22, .top = 17, .width = 8,  .height = 2, .palette = 1, .baseTile = 0x1B0 },
};

static const WindowTemplate sAreaWindowTemplates[] = {
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 9,  .height = 2, .palette = 2, .baseTile = 0x1EE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 3,  .width = 7,  .height = 2, .palette = 1, .baseTile = 0x1E0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 0,  .top = 16, .width = 9,  .height = 2, .palette = 1, .baseTile = 0x1CE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 13, .top = 12, .width = 14, .height = 2, .palette = 1, .baseTile = 0x1B2 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 1,  .top = 5,  .width = 6,  .height = 2, .palette = 1, .baseTile = 0x1F4 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 9,  .top = 1,  .width = 7,  .height = 2, .palette = 1, .baseTile = 0x1E6 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 18, .top = 1,  .width = 7,  .height = 2, .palette = 1, .baseTile = 0x1E6 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 24, .top = 1,  .width = 7,  .height = 2, .palette = 1, .baseTile = 0x1D8 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 5,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x1DC },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 8,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x1B8 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 11, .width = 18, .height = 2, .palette = 1, .baseTile = 0x194 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 14, .width = 18, .height = 2, .palette = 1, .baseTile = 0x170 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 17, .width = 18, .height = 2, .palette = 1, .baseTile = 0x14C },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 10, .top = 20, .width = 18, .height = 2, .palette = 1, .baseTile = 0x128 },
};

static const WindowTemplate sFormsWindowTemplates[] = {
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 9,  .height = 2, .palette = 2, .baseTile = 0x3EE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 4,  .top = 5,  .width = 9,  .height = 2, .palette = 1, .baseTile = 0x3DC },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 13, .top = 5,  .width = 15, .height = 2, .palette = 1, .baseTile = 0x3BE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 5,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x39A },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 21, .top = 17, .width = 10, .height = 2, .palette = 1, .baseTile = 0x1EC },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 13, .top = 2,  .width = 6,  .height = 2, .palette = 1, .baseTile = 0x1E0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 0,  .top = 12, .width = 16, .height = 2, .palette = 1, .baseTile = 0x1C0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 16, .top = 12, .width = 16, .height = 2, .palette = 1, .baseTile = 0x1A0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 3,  .top = 20, .width = 12, .height = 3, .palette = 1, .baseTile = 0x17C },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 18, .top = 20, .width = 12, .height = 3, .palette = 1, .baseTile = 0x158 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 1,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x1DC },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 4,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x1B8 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 7,  .width = 18, .height = 2, .palette = 1, .baseTile = 0x194 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 10, .width = 18, .height = 2, .palette = 1, .baseTile = 0x170 },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 13, .width = 18, .height = 2, .palette = 1, .baseTile = 0x14C },
    { .bgId = GF_BG_LYR_MAIN_2, .left = 8,  .top = 16, .width = 18, .height = 2, .palette = 1, .baseTile = 0x128 },
};

static const WindowTemplate sListWindowTemplates[] = {
    { .bgId = GF_BG_LYR_MAIN_0, .left = 2,  .top = 9,  .width = 12, .height = 2, .palette = 9, .baseTile = 0x3E8 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 9,  .width = 12, .height = 2, .palette = 9, .baseTile = 0x3D0 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 11, .top = 11, .width = 3,  .height = 2, .palette = 9, .baseTile = 0x3CA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 11, .top = 11, .width = 3,  .height = 2, .palette = 9, .baseTile = 0x3C4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 27, .top = 11, .width = 3,  .height = 2, .palette = 9, .baseTile = 0x3BE },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 27, .top = 11, .width = 3,  .height = 2, .palette = 9, .baseTile = 0x3B8 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 10, .top = 16, .width = 11, .height = 2, .palette = 0, .baseTile = 0x1EA },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 8,  .height = 2, .palette = 2, .baseTile = 0x3F0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 3,  .width = 4,  .height = 2, .palette = 0, .baseTile = 0x3E8 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 19, .top = 3,  .width = 9,  .height = 2, .palette = 0, .baseTile = 0x3D6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 13, .top = 5,  .width = 18, .height = 2, .palette = 0, .baseTile = 0x3B2 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 17, .width = 28, .height = 6, .palette = 1, .baseTile = 0x30A },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 18, .top = 11, .width = 5,  .height = 2, .palette = 1, .baseTile = 0x300 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 23, .top = 11, .width = 8,  .height = 2, .palette = 1, .baseTile = 0x2F0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 18, .top = 13, .width = 5,  .height = 2, .palette = 1, .baseTile = 0x2E6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 23, .top = 13, .width = 8,  .height = 2, .palette = 1, .baseTile = 0x2D6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 16, .top = 8,  .width = 14, .height = 2, .palette = 1, .baseTile = 0x2B6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 16, .top = 11, .width = 3,  .height = 2, .palette = 1, .baseTile = 0x2B0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 20, .top = 11, .width = 8,  .height = 2, .palette = 1, .baseTile = 0x2A0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 13, .width = 16, .height = 2, .palette = 1, .baseTile = 0x280 },
};

static const WindowTemplate sSearchWindowTemplates[] = {
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 19, .width = 28, .height = 5,  .palette = 2, .baseTile = 0x174 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 4,  .top = 1,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0x162 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 4,  .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x158 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 7,  .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x14E },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 10, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x144 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 13, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x13A },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 1,  .top = 16, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x130 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 25, .top = 4,  .width = 6,  .height = 2,  .palette = 2, .baseTile = 0x124 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 16, .top = 1,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x10E },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 4,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xFC  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 7,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xEC  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 7,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xDC  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 10, .width = 6,  .height = 2,  .palette = 2, .baseTile = 0xD0  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 10, .width = 6,  .height = 2,  .palette = 2, .baseTile = 0xC4  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 13, .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xB2  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 18, .top = 13, .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xA0  },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 7,  .top = 16, .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x92  },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 1,  .top = 1,  .width = 8,  .height = 2,  .palette = 4, .baseTile = 0x1F0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 12, .top = 1,  .width = 8,  .height = 2,  .palette = 4, .baseTile = 0x1E0 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 23, .top = 1,  .width = 8,  .height = 2,  .palette = 4, .baseTile = 0x1D0 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 4,  .top = 1,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0x162 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 4,  .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x158 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 7,  .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x14E },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 10, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x144 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 13, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x13A },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 16, .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x130 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 25, .top = 4,  .width = 6,  .height = 2,  .palette = 2, .baseTile = 0x124 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 1,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x10E },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 4,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xFC  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 7,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xEC  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 15, .top = 7,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xDC  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 10, .width = 6,  .height = 2,  .palette = 2, .baseTile = 0xD0  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 15, .top = 10, .width = 6,  .height = 2,  .palette = 2, .baseTile = 0xC4  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 13, .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xB2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 13, .width = 9,  .height = 2,  .palette = 2, .baseTile = 0xA0  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 16, .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x92  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 1,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x1EA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 1,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x1D4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 6,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x1BE },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 6,  .width = 11, .height = 2,  .palette = 2, .baseTile = 0x1A8 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 10, .width = 11, .height = 2,  .palette = 2, .baseTile = 0x192 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 10, .width = 11, .height = 2,  .palette = 2, .baseTile = 0x17C },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 14, .width = 11, .height = 2,  .palette = 2, .baseTile = 0x166 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 14, .width = 11, .height = 2,  .palette = 2, .baseTile = 0x150 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 1,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1F2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 13, .top = 1,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x1E2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 21, .top = 1,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x1D2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 0,  .top = 5,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x1C2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 5,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x1B2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 5,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x1A2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 24, .top = 5,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x192 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 0,  .top = 8,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x182 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 8,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x172 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 8,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x162 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 24, .top = 8,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x152 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 0,  .top = 11, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x142 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 11, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x132 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 11, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x122 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 24, .top = 11, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x112 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 0,  .top = 14, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x102 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 14, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xF2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 14, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xE2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 24, .top = 14, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xD2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 0,  .top = 17, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xC2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 17, .width = 8,  .height = 2,  .palette = 2, .baseTile = 0xB2  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 1,  .width = 6,  .height = 2,  .palette = 2, .baseTile = 0x1F4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 15, .top = 1,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0x1E2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 5,  .width = 29, .height = 14, .palette = 2, .baseTile = 0x4C  },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 3,  .top = 1,  .width = 5,  .height = 2,  .palette = 2, .baseTile = 0x1F6 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 10, .top = 1,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1E8 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 19, .top = 1,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1DA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 1,  .top = 1,  .width = 6,  .height = 2,  .palette = 2, .baseTile = 0x1F4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 1,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0x1E2 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 19, .top = 1,  .width = 9,  .height = 2,  .palette = 2, .baseTile = 0x1D0 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 7,  .top = 1,  .width = 6,  .height = 2,  .palette = 2, .baseTile = 0x1F4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 16, .top = 1,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1E6 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 6,  .top = 8,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1D8 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 19, .top = 8,  .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1CA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 6,  .top = 15, .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1BC },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 19, .top = 15, .width = 7,  .height = 2,  .palette = 2, .baseTile = 0x1AE },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 8,  .top = 1,  .width = 6,  .height = 3,  .palette = 2, .baseTile = 0x1EE },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 0,  .width = 8,  .height = 2,  .palette = 2, .baseTile = 0x3F0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 3,  .width = 4,  .height = 2,  .palette = 0, .baseTile = 0x3E8 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 19, .top = 3,  .width = 9,  .height = 2,  .palette = 0, .baseTile = 0x3D6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 13, .top = 5,  .width = 18, .height = 2,  .palette = 0, .baseTile = 0x3B2 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 2,  .top = 17, .width = 28, .height = 6,  .palette = 1, .baseTile = 0x30A },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 18, .top = 11, .width = 5,  .height = 2,  .palette = 1, .baseTile = 0x300 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 23, .top = 11, .width = 8,  .height = 2,  .palette = 1, .baseTile = 0x2F0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 18, .top = 13, .width = 5,  .height = 2,  .palette = 1, .baseTile = 0x2E6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 23, .top = 13, .width = 8,  .height = 2,  .palette = 1, .baseTile = 0x2D6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 16, .top = 8,  .width = 14, .height = 2,  .palette = 1, .baseTile = 0x2B6 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 16, .top = 11, .width = 3,  .height = 2,  .palette = 1, .baseTile = 0x2B0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 20, .top = 11, .width = 8,  .height = 2,  .palette = 1, .baseTile = 0x2A0 },
    { .bgId = GF_BG_LYR_SUB_1,  .left = 15, .top = 13, .width = 16, .height = 2,  .palette = 1, .baseTile = 0x280 },
    { .bgId = GF_BG_LYR_MAIN_1, .left = 10, .top = 16, .width = 11, .height = 2,  .palette = 0, .baseTile = 0x1BA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 2,  .top = 9,  .width = 12, .height = 2,  .palette = 9, .baseTile = 0x3E8 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 18, .top = 9,  .width = 12, .height = 2,  .palette = 9, .baseTile = 0x3D0 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 11, .top = 11, .width = 3,  .height = 2,  .palette = 9, .baseTile = 0x3CA },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 11, .top = 11, .width = 3,  .height = 2,  .palette = 9, .baseTile = 0x3C4 },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 27, .top = 11, .width = 3,  .height = 2,  .palette = 9, .baseTile = 0x3BE },
    { .bgId = GF_BG_LYR_MAIN_0, .left = 27, .top = 11, .width = 3,  .height = 2,  .palette = 9, .baseTile = 0x3B8 },
};

// Window ids of the list screen: 0-1 seen / caught labels, 2-5 the counts (two of each, alternating),
// 7-10 entry header, 11-19 entry details. The search screen's entry windows are 81-93 (header 81-84,
// details 85-93).

void PokedexApp_AddWindows(PokedexAppData *pokedexApp, const WindowTemplate *templates, u32 count) {
    u32 i;
    const WindowTemplate *template = templates;

    for (i = 0; i < count; i++) {
        AddWindow(pokedexApp->bgConfig, &pokedexApp->windows[i], template);
        template ++;
    }
}

void PokedexApp_RemoveAllWindows(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 101; i++) {
        if (pokedexApp->windows[i].pixelBuffer) {
            RemoveWindow(&pokedexApp->windows[i]);
        }
    }
}

// Prints message msgNo (expanded with msgFormat) into window windowId.
void PokedexApp_PrintFormattedMessage(PokedexAppData *pokedexApp, MsgData *msgData, int windowId, int msgNo, int x, int y, int fontId, int color, int align) {
    String *string = NewString_ReadMsgData(msgData, msgNo);
    StringExpandPlaceholders(pokedexApp->msgFormat, pokedexApp->strBufFormatted, string);
    PokedexApp_PrintString(&pokedexApp->windows[windowId], pokedexApp->strBufFormatted, x, y, fontId, color, align);
    String_Delete(string);
}

void PokedexApp_SetupListWindows(PokedexAppData *pokedexApp) {
    u32 cursor;
    u32 species;

    PokedexApp_AddWindows(pokedexApp, sListWindowTemplates, 20);
    PokedexApp_DrawCountLabelAndCopy(pokedexApp, 0, msg_0802_00000);
    PokedexApp_DrawCountLabelAndCopy(pokedexApp, 1, msg_0802_00001);
    PokedexApp_DrawSeenAndCaughtCounts(pokedexApp);
    cursor = PokedexApp_GetListCursorIndex(pokedexApp);
    species = PokedexApp_GetCursorSpecies(pokedexApp);
    PokedexApp_DrawListEntryHeader(pokedexApp, species, cursor);
    PokedexApp_DrawListEntryDetails(pokedexApp, species, cursor);
}

// A count label: a 12-tile bar from the graphics NARC with the message right-aligned on it.
void PokedexApp_DrawCountLabel(PokedexAppData *pokedexApp, int windowId, u32 msgNo) {
    NNSG2dCharacterData *charData;
    void *allocation = GfGfxLoader_GetCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000001_NCGR_lz, TRUE, &charData, HEAP_ID_POKEDEX_APP);
    u8 *pixels = charData->pRawData;
    u32 i;
    int x;

    i = 0;
    x = 0;
    pixels += 32;
    for (; i < 12; i++, x += 8) {
        BlitBitmapRect(&pokedexApp->windows[windowId], pixels, 0, 0, 8, 8, x, 0, 8, 8, 0xFF);
        BlitBitmapRect(&pokedexApp->windows[windowId], pixels, 0, 0, 8, 8, x, 8, 8, 8, 0xFF);
    }
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msgNo, 96, 0, 0, MAKE_TEXT_COLOR(15, 8, 0), POKEDEX_TEXT_ALIGN_RIGHT);
    Heap_Free(allocation);
}

void PokedexApp_DrawCountLabelAndCopy(PokedexAppData *pokedexApp, u32 windowId, u32 msgNo) {
    PokedexApp_DrawCountLabel(pokedexApp, windowId, msgNo);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

// A three-digit count on a 3-tile background.
void PokedexApp_DrawCountNumber(PokedexAppData *pokedexApp, u32 windowId, u32 value) {
    NNSG2dCharacterData *charData;
    void *allocation;
    u8 *pixels;
    MessagePrinter *printer;
    u32 i;

    allocation = GfGfxLoader_GetCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000001_NCGR_lz, TRUE, &charData, HEAP_ID_POKEDEX_APP);
    pixels = charData->pRawData;
    for (i = 0; i < 3; i++) {
        BlitBitmapRect(&pokedexApp->windows[windowId], pixels + 0x300, 0, 0, 8, 8, i * 8, 0, 8, 8, 0xFF);
        BlitBitmapRect(&pokedexApp->windows[windowId], pixels + 0x20, 0, 0, 8, 8, i * 8, 8, 8, 8, 0xFF);
    }
    Heap_Free(allocation);
    printer = MessagePrinter_New(15, 8, 7, HEAP_ID_POKEDEX_APP);
    PrintUIntOnWindow(printer, value, 3, PRINTING_MODE_LEADING_ZEROS, &pokedexApp->windows[windowId], 0, 4);
    MessagePrinter_Delete(printer);
}

void PokedexApp_DrawCountNumberAndCopy(PokedexAppData *pokedexApp, u32 windowId, u32 value) {
    PokedexApp_DrawCountNumber(pokedexApp, windowId, value);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

// The counts are drawn into the hidden one of two window pairs (countWindowSwap), then the pairs swap.
void PokedexApp_DrawSeenAndCaughtCounts(PokedexAppData *pokedexApp) {
    PokedexApp_DrawCountNumberAndCopy(pokedexApp, pokedexApp->countWindowSwap + 2, pokedexApp->searchResults.count);
    PokedexApp_DrawCountNumberAndCopy(pokedexApp, pokedexApp->countWindowSwap + 4, pokedexApp->searchResults.caughtCount);
    pokedexApp->countWindowSwap ^= 1;
}

void PokedexApp_DrawCenteredSpeciesName(PokedexAppData *pokedexApp, u32 species, int windowId) {
    if (species) {
        Window *windows = pokedexApp->windows;
        String *string;

        FillWindowPixelBuffer(&windows[windowId], 0);
        string = PokedexApp_GetSpeciesNameString(species, pokedexApp->language, HEAP_ID_POKEDEX_APP);
        if (Pokedex_GetInternationalViewFlag(pokedexApp->args->pokedex) == TRUE) {
            PokedexApp_PrintString(&windows[windowId], string, 56, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        } else {
            PokedexApp_PrintString(&windows[windowId], string, 44, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        }
        String_Delete(string);
        ScheduleWindowCopyToVram(&windows[windowId]);
    } else {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[windowId]);
    }
}

void PokedexApp_DrawListEntryHeader(PokedexAppData *pokedexApp, u32 species, u32 entry) {
    PokedexApp_DrawInfoLabel(pokedexApp, 7);
    PokedexApp_DrawDexNumber(pokedexApp, species, 8);
    PokedexApp_DrawSpeciesName(pokedexApp, species, 9);
    PokedexApp_DrawCategory(pokedexApp, species, entry, 10);
}

void PokedexApp_DrawSearchEntryHeader(PokedexAppData *pokedexApp, u32 species, u32 entry) {
    PokedexApp_DrawInfoLabel(pokedexApp, 81);
    PokedexApp_DrawDexNumber(pokedexApp, species, 82);
    PokedexApp_DrawSpeciesName(pokedexApp, species, 83);
    PokedexApp_DrawCategory(pokedexApp, species, entry, 84);
}

void PokedexApp_DrawInfoLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00008, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawDexNumber(PokedexAppData *pokedexApp, u32 species, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    if (species != SPECIES_NONE) {
        u32 dexNo = Pokedex_ConvertToCurrentDexNo(pokedexApp->dexMode, species);
        BufferIntegerAsString(pokedexApp->msgFormat, 0, dexNo, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
        PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, windowId, msg_0802_00009, 1, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
        ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
    } else {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[windowId]);
    }
}

void PokedexApp_DrawSpeciesName(PokedexAppData *pokedexApp, u32 species, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    if (species != SPECIES_NONE) {
        String *string = PokedexApp_GetSpeciesNameString(species, 2, HEAP_ID_POKEDEX_APP);
        PokedexApp_PrintString(&pokedexApp->windows[windowId], string, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
        String_Delete(string);
        ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
    } else {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[windowId]);
    }
}

// The category only shows for caught species.
void PokedexApp_DrawCategory(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    if (species != SPECIES_NONE) {
        String *string;
        if (pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
            string = PokedexApp_GetCategoryString(species, 2, HEAP_ID_POKEDEX_APP);
        } else {
            string = PokedexApp_GetCategoryString(SPECIES_NONE, 2, HEAP_ID_POKEDEX_APP);
        }
        s32 x = (GetWindowWidth(&pokedexApp->windows[windowId]) << 3) - 4;
        PokedexApp_PrintString(&pokedexApp->windows[windowId], string, x, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_RIGHT);
        String_Delete(string);
        ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
    } else {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[windowId]);
    }
}

// Flavor text plus height / weight, or for a foreign language its dex number, name and category.
void PokedexApp_DrawListEntryDetails(PokedexAppData *pokedexApp, u32 species, u32 entry) {
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[12]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[14]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[11]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[13]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[15]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[16]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[17]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[18]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[19]);
    if (species != SPECIES_NONE) {
        PokedexApp_DrawFlavorText(pokedexApp, species, entry, 11);
        if (pokedexApp->language == LANGUAGE_ENGLISH) {
            PokedexApp_DrawHeightLabel(pokedexApp, 12);
            PokedexApp_DrawWeightLabel(pokedexApp, 14);
            PokedexApp_DrawHeight(pokedexApp, species, entry, 13);
            PokedexApp_DrawWeight(pokedexApp, species, entry, 15);
        } else {
            PokedexApp_DrawForeignDexLabel(pokedexApp, 16);
            PokedexApp_DrawForeignDexNumber(pokedexApp, species, 17, pokedexApp->language);
            PokedexApp_DrawForeignSpeciesName(pokedexApp, species, 18);
            PokedexApp_DrawForeignCategory(pokedexApp, species, entry, 19);
        }
    }
}

void PokedexApp_DrawFlavorText(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId) {
    if (pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
        String *string;
        u32 x;

        FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
        string = PokedexApp_GetFlavorTextString(species, pokedexApp->language, 0, HEAP_ID_POKEDEX_APP);
        x = GetWindowWidth(&pokedexApp->windows[windowId]);
        {
            u32 stringWidth = FontID_String_GetWidthMultiline(0, string, 0);
            x = ((x << 3) - stringWidth) >> 1;
        }
        PokedexApp_PrintString(&pokedexApp->windows[windowId], string, x, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
        String_Delete(string);
        ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
    }
}

void PokedexApp_DrawHeightLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00010, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawWeightLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00011, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

// The height text of species (caught: the species, else the SPECIES_NONE placeholder).
void PokedexApp_PrintHeight(PokedexAppData *pokedexApp, u32 species, u32 state, u32 windowId, u32 x, u32 y, u32 color, u32 align) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, GetDexHeightMsgBank(), HEAP_ID_POKEDEX_APP);
    String *string;

    if (state == POKEDEXAPP_ENTRY_CAUGHT) {
        string = NewString_ReadMsgData(msgData, species);
    } else {
        string = NewString_ReadMsgData(msgData, SPECIES_NONE);
    }
    PokedexApp_PrintString(&pokedexApp->windows[windowId], string, x, y, 0, color, align);
    String_Delete(string);
    DestroyMsgData(msgData);
}

void PokedexApp_DrawHeight(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintHeight(pokedexApp, species, pokedexApp->listEntries[entry].caughtState, windowId, 4, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_PrintWeight(PokedexAppData *pokedexApp, u32 species, u32 state, u32 windowId, u32 x, u32 y, u32 color, u32 align) {
    MsgData *msgData = NewMsgDataFromNarc(MSGDATA_LOAD_DIRECT, NARC_msgdata_msg, GetDexWeightMsgBank(), HEAP_ID_POKEDEX_APP);
    String *string;

    if (state == POKEDEXAPP_ENTRY_CAUGHT) {
        string = NewString_ReadMsgData(msgData, species);
    } else {
        string = NewString_ReadMsgData(msgData, SPECIES_NONE);
    }
    PokedexApp_PrintString(&pokedexApp->windows[windowId], string, x, y, 0, color, align);
    String_Delete(string);
    DestroyMsgData(msgData);
}

void PokedexApp_DrawWeight(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintWeight(pokedexApp, species, pokedexApp->listEntries[entry].caughtState, windowId, 4, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawForeignDexLabel(PokedexAppData *pokedexApp, u32 windowId) {
    u32 msgNo;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    msgNo = LanguageToDexFlag(pokedexApp->language);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msgNo + 122, 56, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

// Japanese uses the other digit charset.
void PokedexApp_DrawForeignDexNumber(PokedexAppData *pokedexApp, u32 species, u32 windowId, u32 language) {
    int charset;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    switch (language) {
    case LANGUAGE_JAPANESE:
        charset = 0;
        break;
    default:
        charset = 1;
        break;
    }
    BufferIntegerAsString(pokedexApp->msgFormat, 0, Pokedex_ConvertToCurrentDexNo(pokedexApp->dexMode, species), 3, PRINTING_MODE_LEADING_ZEROS, charset);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, windowId, msg_0802_00009, 0, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawForeignSpeciesName(PokedexAppData *pokedexApp, u32 species, u32 windowId) {
    String *string;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    string = PokedexApp_GetSpeciesNameString(species, pokedexApp->language, HEAP_ID_POKEDEX_APP);
    PokedexApp_PrintString(&pokedexApp->windows[windowId], string, 0, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    String_Delete(string);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawForeignCategory(PokedexAppData *pokedexApp, u32 species, u32 entry, u32 windowId) {
    String *string;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    if (pokedexApp->listEntries[entry].caughtState == POKEDEXAPP_ENTRY_CAUGHT) {
        string = PokedexApp_GetCategoryString(species, pokedexApp->language, HEAP_ID_POKEDEX_APP);
    } else {
        string = PokedexApp_GetCategoryString(SPECIES_NONE, pokedexApp->language, HEAP_ID_POKEDEX_APP);
    }
    PokedexApp_PrintString(&pokedexApp->windows[windowId], string, 124, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_RIGHT);
    String_Delete(string);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}

void PokedexApp_DrawSearchEntryDetails(PokedexAppData *pokedexApp, u32 species, u32 entry) {
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[86]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[88]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[85]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[87]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[89]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[90]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[91]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[92]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[93]);
    if (species != SPECIES_NONE) {
        PokedexApp_DrawFlavorText(pokedexApp, species, entry, 85);
        if (pokedexApp->language == LANGUAGE_ENGLISH) {
            PokedexApp_DrawHeightLabel(pokedexApp, 86);
            PokedexApp_DrawWeightLabel(pokedexApp, 88);
            PokedexApp_DrawHeight(pokedexApp, species, entry, 87);
            PokedexApp_DrawWeight(pokedexApp, species, entry, 89);
        } else {
            PokedexApp_DrawForeignDexLabel(pokedexApp, 90);
            PokedexApp_DrawForeignDexNumber(pokedexApp, species, 91, pokedexApp->language);
            PokedexApp_DrawForeignSpeciesName(pokedexApp, species, 92);
            PokedexApp_DrawForeignCategory(pokedexApp, species, entry, 93);
        }
    }
}

void PokedexApp_SetupSearchWindows(PokedexAppData *pokedexApp) {
    PokedexApp_AddWindows(pokedexApp, sSearchWindowTemplates, 101);
    PokedexApp_DrawSearchMessage(pokedexApp, 0);
    PokedexApp_DrawSearchMenuPage(pokedexApp);
    PokedexApp_DrawSearchCriteria(pokedexApp);
    PokedexApp_PutSearchWindowCellTiles(pokedexApp);
}

void PokedexApp_PutSearchWindowCellTiles(PokedexAppData *pokedexApp) {
    BgCellManager_PutWindowTiles(pokedexApp->bgCellManager, 6, &pokedexApp->windows[17]);
    BgCellManager_PutWindowTiles(pokedexApp->bgCellManager, 6, &pokedexApp->windows[18]);
    BgCellManager_PutWindowTiles(pokedexApp->bgCellManager, 6, &pokedexApp->windows[19]);
    BgCellManager_PutWindowTiles(pokedexApp->bgCellManager, 7, &pokedexApp->windows[17]);
    BgCellManager_PutWindowTiles(pokedexApp->bgCellManager, 7, &pokedexApp->windows[19]);
}

// The search screen's two-line help text for each page; page 1 shows the result count.
void PokedexApp_DrawSearchMessage(PokedexAppData *pokedexApp, u32 page) {
    Window *window = &pokedexApp->windows[0];

    FillWindowPixelBuffer(window, 0);
    switch (page) {

    case 0:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00013, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 1:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00014, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        BufferIntegerAsString(pokedexApp->msgFormat, 0, pokedexApp->searchResults.count, 3, PRINTING_MODE_LEADING_ZEROS, TRUE);
        PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, 0, msg_0802_00015, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 2:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00016, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 3:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00017, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 4:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00018, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 5:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00020, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 6:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00019, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 7:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00022, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 8:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00021, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 9:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00012, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00025, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    case 10:
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00023, 112, 6, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msg_0802_00024, 112, 22, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        break;
    }
    ScheduleWindowCopyToVram(window);
}

void PokedexApp_DrawSearchOrderLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00026, 36, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchNameLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00027, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchTypeLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00028, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchHeightLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00029, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchWeightLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00030, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchAreaLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00031, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchFormLabel(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msg_0802_00032, 24, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// A search screen button: an 8-tile frame with the label centred on it.
void PokedexApp_DrawSearchButton(PokedexAppData *pokedexApp, int windowId, int msgNo) {
    u8 *windows = (u8 *)pokedexApp->windows;
    int offset = windowId * sizeof(Window);
    NNSG2dCharacterData *charData;
    void *allocation = GfGfxLoader_GetCharDataFromOpenNarc(pokedexApp->gfxNarc, NARC_zukan_gra_zukan_gra_00000004_NCGR_lz, TRUE, &charData, HEAP_ID_POKEDEX_APP);
    u8 *pixels = charData->pRawData;
    u32 i;
    int x = 0;

    for (i = 0; i < 8; i++, x += 8) {
        BlitBitmapRect((Window *)(windows + offset), pixels + 0xC40, 0, 0, 8, 8, x, 0, 8, 8, 0xFF);
        BlitBitmapRect((Window *)(windows + offset), pixels + 0xCA0, 0, 0, 8, 8, x, 8, 8, 8, 0xFF);
    }
    Heap_Free(allocation);
    {
        int width = GetWindowWidth((Window *)(windows + offset));
        x = width * 8;
        PokedexApp_PrintMessage((Window *)(windows + offset), pokedexApp->msgData, msgNo, x / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    }
    CopyWindowPixelsToVram_TextMode((Window *)(windows + offset));
}

// Search menu: labels 20-26, buttons 17-19.
void PokedexApp_DrawSearchMenuPage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[20], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[21], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[22], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[23], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[24], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[25], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[26], 0);
    PokedexApp_DrawSearchOrderLabel(pokedexApp, 20);
    PokedexApp_DrawSearchNameLabel(pokedexApp, 21);
    PokedexApp_DrawSearchTypeLabel(pokedexApp, 22);
    PokedexApp_DrawSearchHeightLabel(pokedexApp, 23);
    PokedexApp_DrawSearchWeightLabel(pokedexApp, 24);
    PokedexApp_DrawSearchAreaLabel(pokedexApp, 25);
    PokedexApp_DrawSearchFormLabel(pokedexApp, 26);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00035);
    PokedexApp_DrawSearchButton(pokedexApp, 18, msg_0802_00036);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00037);
    i = 20;
    window = &pokedexApp->windows[20];
    for (; i <= 26; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

// The values of the current criteria, windows 27-35.
void PokedexApp_DrawSearchCriteria(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_DrawSearchOrderValue(pokedexApp, 27);
    PokedexApp_DrawSearchNameValue(pokedexApp, 28);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE1], 29, 29);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE2], 30, 29);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MIN]].height, 31);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MAX]].height, 32);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MIN]].weight, 33);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MAX]].weight, 34);
    PokedexApp_DrawSearchAreaValue(pokedexApp, 35);
    i = 27;
    window = &pokedexApp->windows[27];
    for (; i <= 35; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

// Sort order page: windows 36-43.
void PokedexApp_DrawSearchOrderPage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[36], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[38], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[39], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[40], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[41], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[42], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[43], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[36], pokedexApp->msgData, msg_0802_00026, 44, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[38], pokedexApp->msgData, msg_0802_00041, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[39], pokedexApp->msgData, msg_0802_00042, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[40], pokedexApp->msgData, msg_0802_00043, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[41], pokedexApp->msgData, msg_0802_00044, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[42], pokedexApp->msgData, msg_0802_00045, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[43], pokedexApp->msgData, msg_0802_00046, 44, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawSearchOrderValue(pokedexApp, 37);
    i = 36;
    window = &pokedexApp->windows[36];
    for (; i <= 43; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

// Name page: the 27 letter buttons in a 7-column grid (window 67), title 66, value 66.
void PokedexApp_DrawSearchNamePage(PokedexAppData *pokedexApp) {
    u16 i;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[65], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[67], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[65], pokedexApp->msgData, msg_0802_00027, 24, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    for (i = 0; i < 27; i++) {
        u16 position = ((int (*)(int))PokedexApp_GetLetterGridCell)(i);
        int msgNo;
        if (i == 26) {
            msgNo = 113;
        } else {
            msgNo = i + 69;
        }
        int column = position % 7;
        PokedexApp_PrintMessage(&pokedexApp->windows[67], pokedexApp->msgData, msgNo, column * 32 + 24, (position / 7) * 32, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    }
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawSearchNameValue(pokedexApp, 66);
    ScheduleWindowCopyToVram(&pokedexApp->windows[65]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[67]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[66]);
}

// Type page: title 44, the 18 type buttons 47-64, values 45-46.
void PokedexApp_DrawSearchTypePage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;
    const u16 *msgNo;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[44], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[44], pokedexApp->msgData, msg_0802_00028, 28, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    // the type names' message ids (u16) are addressed relative to the window template table after them
    msgNo = (const u16 *)&sSizeCheckWindowTemplates[7].top;
    i = 47;
    window = &pokedexApp->windows[47];
    for (; i <= 64; i++) {
        FillWindowPixelBuffer(window, 0);
        PokedexApp_PrintMessage(window, pokedexApp->msgData, msgNo[-47], 32, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        window++;
        msgNo++;
    }
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE1], 45, 29);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE2], 46, 35);
    i = 44;
    window = &pokedexApp->windows[44];
    for (; i <= 64; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

void PokedexApp_DrawSearchHeightPage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[68], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[68], pokedexApp->msgData, msg_0802_00029, 20, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MIN]].height, 69);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MAX]].height, 70);
    i = 68;
    window = &pokedexApp->windows[68];
    for (; i <= 70; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

void PokedexApp_DrawSearchWeightPage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[71], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[71], pokedexApp->msgData, msg_0802_00030, 24, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MIN]].weight, 72);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MAX]].weight, 73);
    i = 71;
    window = &pokedexApp->windows[71];
    for (; i <= 73; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

// Area page: Johto, Kanto (national dex only), all, cancel.
void PokedexApp_DrawSearchAreaPage(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[74], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[76], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[77], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[78], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[79], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[74], pokedexApp->msgData, msg_0802_00031, 24, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[76], pokedexApp->msgData, msg_0802_00065, 28, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    if (pokedexApp->nationalDex == 1) {
        PokedexApp_PrintMessage(&pokedexApp->windows[77], pokedexApp->msgData, msg_0802_00066, 28, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    }
    PokedexApp_PrintMessage(&pokedexApp->windows[78], pokedexApp->msgData, msg_0802_00067, 28, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[79], pokedexApp->msgData, msg_0802_00068, 28, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    PokedexApp_DrawSearchAreaValue(pokedexApp, 75);
    i = 74;
    window = &pokedexApp->windows[74];
    for (; i <= 79; i++) {
        ScheduleWindowCopyToVram(window);
        window++;
    }
}

void PokedexApp_DrawSearchFormPage(PokedexAppData *pokedexApp) {
    PokedexApp_ClearBgTilemap(pokedexApp, GF_BG_LYR_MAIN_0);
    FillWindowPixelBuffer(&pokedexApp->windows[80], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[80], pokedexApp->msgData, msg_0802_00032, 24, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_DrawSearchButton(pokedexApp, 17, msg_0802_00039);
    PokedexApp_DrawSearchButton(pokedexApp, 19, msg_0802_00040);
    ScheduleWindowCopyToVram(&pokedexApp->windows[80]);
}

void PokedexApp_DrawSearchOrderValue(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_SORT_ORDER] + 41, GetWindowWidth(&pokedexApp->windows[windowId]) * 8 / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// The selected letter (26: any).
void PokedexApp_DrawSearchNameValue(PokedexAppData *pokedexApp, int windowId) {
    int msgNo, width;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    msgNo = pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_LETTER];
    if (msgNo == 26) {
        msgNo = 113;
    } else {
        msgNo += 69;
    }
    width = GetWindowWidth(&pokedexApp->windows[windowId]);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, msgNo, (width * 8) / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// x -1: centred.
void PokedexApp_DrawSearchTypeValue(PokedexAppData *pokedexApp, u32 type, u32 windowId, s32 x) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    if (x == -1) {
        x = GetWindowWidth(&pokedexApp->windows[windowId]) * 8 / 2;
    }
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, sSearchTypeMsgIds[type], x, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// height in 0.1 m, shown in feet and inches (999: the slider's maximum).
void PokedexApp_DrawHeightValue(PokedexAppData *pokedexApp, u32 height, u32 windowId) {
    u32 inches;

    if (height == 999) {
        inches = 1188;
    } else {
        inches = (10000 * height / 254 + 5) / 10;
    }
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    BufferIntegerAsString(pokedexApp->msgFormat, 0, inches / 12, 3, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(pokedexApp->msgFormat, 1, inches % 12, 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, windowId, msg_0802_00175, GetWindowWidth(&pokedexApp->windows[windowId]) * 8 / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// weight in 0.1 kg, shown in 0.1 lbs (9999: the slider's maximum).
void PokedexApp_DrawWeightValue(PokedexAppData *pokedexApp, u32 weight, u32 windowId) {
    u32 pounds;

    if (weight == 9999) {
        pounds = 99990;
    } else {
        pounds = (220462 * weight + 50000) / 100000;
    }
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    BufferIntegerAsString(pokedexApp->msgFormat, 0, pounds / 10, 4, PRINTING_MODE_LEFT_ALIGN, TRUE);
    BufferIntegerAsString(pokedexApp->msgFormat, 1, pounds % 10, 1, PRINTING_MODE_LEADING_ZEROS, TRUE);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, windowId, msg_0802_00038, GetWindowWidth(&pokedexApp->windows[windowId]) * 8 / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

void PokedexApp_DrawSearchAreaValue(PokedexAppData *pokedexApp, u32 windowId) {
    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[windowId], pokedexApp->msgData, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_AREA] + 65, GetWindowWidth(&pokedexApp->windows[windowId]) * 8 / 2, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
}

// The criteria summary on the search results screen (windows 1-16).
void PokedexApp_DrawSearchCriteriaSummary(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window;

    FillWindowPixelBuffer(&pokedexApp->windows[1], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[2], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[3], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[4], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[5], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[6], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[7], 0);
    PokedexApp_DrawSearchOrderLabel(pokedexApp, 1);
    PokedexApp_DrawSearchNameLabel(pokedexApp, 2);
    PokedexApp_DrawSearchTypeLabel(pokedexApp, 3);
    PokedexApp_DrawSearchHeightLabel(pokedexApp, 4);
    PokedexApp_DrawSearchWeightLabel(pokedexApp, 5);
    PokedexApp_DrawSearchAreaLabel(pokedexApp, 6);
    PokedexApp_DrawSearchFormLabel(pokedexApp, 7);
    PokedexApp_DrawSearchOrderValue(pokedexApp, 8);
    PokedexApp_DrawSearchNameValue(pokedexApp, 9);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE1], 10, 29);
    PokedexApp_DrawSearchTypeValue(pokedexApp, pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_TYPE2], 11, 29);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MIN]].height, 12);
    PokedexApp_DrawHeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_HEIGHT_MAX]].height, 13);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MIN]].weight, 14);
    PokedexApp_DrawWeightValue(pokedexApp, pokedexApp->sliderValues[pokedexApp->dexSearchCriteria[DEX_SEARCH_CRITERIA_WEIGHT_MAX]].weight, 15);
    PokedexApp_DrawSearchAreaValue(pokedexApp, 16);
    i = 1;
    window = &pokedexApp->windows[1];
    for (; i <= 16; i++, window++) {
        CopyWindowPixelsToVram_TextMode(window);
    }
}

// The search results screen's counts (labels 95-96, counts 97-100 alternating as on the list screen).
void PokedexApp_DrawSearchResultCounts(PokedexAppData *pokedexApp) {
    BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 15);
    PokedexApp_DrawCountLabel(pokedexApp, 95, msg_0802_00000);
    PokedexApp_DrawCountLabel(pokedexApp, 96, msg_0802_00001);
    PokedexApp_DrawCountNumber(pokedexApp, pokedexApp->countWindowSwap + 97, pokedexApp->searchResults.count);
    PokedexApp_DrawCountNumber(pokedexApp, pokedexApp->countWindowSwap + 99, pokedexApp->searchResults.caughtCount);
    PokedexApp_PutWindowTilemap(pokedexApp, 95);
    PokedexApp_PutWindowTilemap(pokedexApp, 96);
    PokedexApp_PutWindowTilemap(pokedexApp, pokedexApp->countWindowSwap + 97);
    PokedexApp_PutWindowTilemap(pokedexApp, pokedexApp->countWindowSwap + 99);
    pokedexApp->countWindowSwap = 1 ^ pokedexApp->countWindowSwap;
}

// Writes the window's tiles into cell 15's tilemap (keeping the palette bits) and copies its pixels.
void PokedexApp_PutWindowTilemap(PokedexAppData *pokedexApp, u32 windowId) {
    u16 *tilemap;
    Window *windows;
    u16 baseTile;
    u8 x, y, width, height;
    u32 i, j;

    tilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, 15);
    windows = pokedexApp->windows;
    baseTile = GetWindowBaseTile(&windows[windowId]);
    x = GetWindowX(&windows[windowId]);
    y = GetWindowY(&windows[windowId]);
    width = GetWindowWidth(&windows[windowId]);
    height = GetWindowHeight(&windows[windowId]);
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            tilemap[(y + j) * 32 + x + i] = (tilemap[(y + j) * 32 + x + i] & 0xF000) + baseTile + j * width + i;
        }
    }
    CopyWindowPixelsToVram_TextMode(&windows[windowId]);
}

void PokedexApp_SetSearchSummaryVisible(PokedexAppData *pokedexApp, BOOL visible) {
    u32 i;

    if (visible == TRUE) {
        for (i = 0; i <= 16; i++) {
            ScheduleWindowCopyToVram(&pokedexApp->windows[i]);
        }
    } else {
        for (i = 0; i <= 16; i++) {
            ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[i]);
        }
    }
}

void PokedexApp_ClearSearchEntryWindows(PokedexAppData *pokedexApp) {
    u32 i;
    Window *window = &pokedexApp->windows[81];

    for (i = 81; i <= 93; i++) {
        ClearWindowTilemapAndScheduleTransfer(window);
        window++;
    }
}

void PokedexApp_InitAreaListCells(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 6; i++) {
        BgCellManager_InitCell(pokedexApp->bgCellManager, i + 17, 2, 18, 2);
    }
}

// Cells 17-22 show the list windows 8-13: their tilemaps point at the windows' tiles (palette 1).
void PokedexApp_SetAreaWindowCellTiles(PokedexAppData *pokedexApp) {
    u16 i;
    u16 *tilemap;
    u16 baseTile;
    u16 j;

    for (i = 0; i < 6; i++) {
        tilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, i + 17);
        baseTile = sAreaWindowTemplates[i + 8].baseTile;
        for (j = 0; j < 36; j++) {
            tilemap[j] = (baseTile + j) | 0x1000;
        }
    }
}

void PokedexApp_SetFormsWindowCellTiles(PokedexAppData *pokedexApp) {
    u16 i;
    u16 *tilemap;
    u16 baseTile;
    u16 j;

    for (i = 0; i < 6; i++) {
        tilemap = BgCellManager_GetCellTilemap(pokedexApp->bgCellManager, i + 17);
        baseTile = sFormsWindowTemplates[i + 10].baseTile;
        for (j = 0; j < 36; j++) {
            tilemap[j] = (baseTile + j) | 0x1000;
        }
    }
}

// Area screen: title, species, region labels (Johto, plus Kanto in the national dex), time of day, the list.
void PokedexApp_SetupAreaWindows(PokedexAppData *pokedexApp) {
    String *string;

    PokedexApp_AddWindows(pokedexApp, sAreaWindowTemplates, 14);
    FillWindowPixelBuffer(&pokedexApp->windows[0], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[2], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[4], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[0], pokedexApp->msgData, msg_0802_00142, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    string = PokedexApp_GetSpeciesNameString(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    PokedexApp_PrintString(&pokedexApp->windows[2], string, 36, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    String_Delete(string);
    PokedexApp_PrintMessage(&pokedexApp->windows[4], pokedexApp->msgData, msg_0802_00132, 24, 0, 0, MAKE_TEXT_COLOR(5, 9, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[0]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[2]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[4]);
    if (pokedexApp->nationalDex == 1) {
        FillWindowPixelBuffer(&pokedexApp->windows[5], 0);
        FillWindowPixelBuffer(&pokedexApp->windows[7], 0);
        PokedexApp_PrintMessage(&pokedexApp->windows[5], pokedexApp->msgData, msg_0802_00065, 28, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(&pokedexApp->windows[7], pokedexApp->msgData, msg_0802_00066, 28, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
        ScheduleWindowCopyToVram(&pokedexApp->windows[5]);
        ScheduleWindowCopyToVram(&pokedexApp->windows[7]);
    } else {
        FillWindowPixelBuffer(&pokedexApp->windows[6], 0);
        PokedexApp_PrintMessage(&pokedexApp->windows[6], pokedexApp->msgData, msg_0802_00065, 28, 0, 0, MAKE_TEXT_COLOR(5, 9, 0), POKEDEX_TEXT_ALIGN_CENTER);
        ScheduleWindowCopyToVram(&pokedexApp->windows[6]);
    }
    FillWindowPixelBuffer(&pokedexApp->windows[3], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[3], pokedexApp->msgData, msg_0802_00128, 56, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[3]);
    PokedexApp_DrawTimeOfDayLabel(pokedexApp);
    PokedexApp_DrawAreaList(pokedexApp);
}

void PokedexApp_FreeAreaWindows(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 14; i++) {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[i]);
    }
    PokedexApp_RemoveAllWindows(pokedexApp);
}

void PokedexApp_DrawTimeOfDayLabel(PokedexAppData *pokedexApp) {
    FillWindowPixelBuffer(&pokedexApp->windows[1], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[1], pokedexApp->msgData, pokedexApp->areaTimeOfDay + 129, 28, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[1]);
}

// The area list: six rows (windows 8-13 on cells 17-22) around the selected area areaListPos.
void PokedexApp_DrawAreaList(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 6; i++) {
        int index, x, y;

        FillWindowPixelBuffer(&pokedexApp->windows[i + 8], 0);
        index = pokedexApp->areaListPos + i - 2;
        if (index >= 0 && index < pokedexApp->areaList.areas.nMaps) {
            PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, i + 8, PokedexApp_GetAreaListEntryMsg(pokedexApp, index), 72, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
        }
        CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[i + 8]);
        x = GetWindowX(&pokedexApp->windows[i + 8]);
        y = GetWindowY(&pokedexApp->windows[i + 8]);
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, i + 17, (s8)x, (s8)y);
    }
}

// The message for area list entry index: the map's location name, or "Johto" / "Kanto" for the region entry (-2).
u32 PokedexApp_GetAreaListEntryMsg(PokedexAppData *pokedexApp, int index) {
    int map = pokedexApp->areaList.areas.maps[index];

    if (map == -2) {
        return pokedexApp->areaRegion == 0 ? 134 : 135;
    }
    BufferLandmarkName(pokedexApp->msgFormat, 0, MapHeader_GetMapSec(PokedexApp_GetAreaMapId(pokedexApp, index)));
    return 133;
}

// Redraws the row that scrolled out (cell row 2 or 20) with the entry coming in.
void PokedexApp_ScrollAreaList(PokedexAppData *pokedexApp, int direction) {
    u32 i = 0;
    s8 x;
    s8 y;
    PokedexAppData *app = pokedexApp;

    do {
        BgCellManager_GetCellPosition(app->bgCellManager, i + 17, &x, &y);
        if (y == 2 || y == 20) {
            break;
        }
        i++;
    } while (i < 6);
    FillWindowPixelBuffer(&app->windows[i + 8], 0);
    if (direction < 0) {
        int next;
        BgCellManager_DrawCellAt(app->bgCellManager, i + 17, 10, 20);
        next = app->areaListPos + 2;
        if (next < app->areaList.areas.nMaps) {
            PokedexApp_PrintFormattedMessage(app, app->msgData, i + 8, PokedexApp_GetAreaListEntryMsg(app, next), 72, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
        }
    } else {
        int previous;
        BgCellManager_DrawCellAt(app->bgCellManager, i + 17, 10, 2);
        previous = app->areaListPos;
        previous -= 2;
        if (previous >= 0) {
            PokedexApp_PrintFormattedMessage(app, app->msgData, i + 8, PokedexApp_GetAreaListEntryMsg(app, previous), 72, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
        }
    }
    CopyWindowPixelsToVram_TextMode(&app->windows[i + 8]);
}

// Size check: the species and the player, their heights (top) and weights (bottom).
void PokedexApp_SetupSizeCheckWindows(PokedexAppData *pokedexApp) {
    PokedexApp_AddWindows(pokedexApp, sSizeCheckWindowTemplates, 13);
    for (u32 i = 0; i < 13; i++) {
        FillWindowPixelBuffer(&pokedexApp->windows[i], 0);
    }
    int state = Pokedex_CheckMonCaughtFlag(pokedexApp->args->pokedex, pokedexApp->curSpecies) ? 2 : 1;
    PokedexApp_PrintMessage(&pokedexApp->windows[0], pokedexApp->msgData, msg_0802_00143, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    PokedexApp_PrintMessage(&pokedexApp->windows[3], pokedexApp->msgData, msg_0802_00136, 48, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[4], pokedexApp->msgData, msg_0802_00010, 16, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[6], pokedexApp->msgData, msg_0802_00010, 16, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    String *string = PokedexApp_GetSpeciesNameString(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    PokedexApp_PrintString(&pokedexApp->windows[1], string, 32, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    String_Delete(string);
    string = PlayerProfile_GetPlayerName_NewString(pokedexApp->args->playerProfile, HEAP_ID_POKEDEX_APP);
    PokedexApp_PrintString(&pokedexApp->windows[2], string, 32, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    String_Delete(string);
    PokedexApp_PrintHeight(pokedexApp, pokedexApp->curSpecies, state, 5, 32, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[8], pokedexApp->msgData, msg_0802_00137, 48, 0, 0, MAKE_TEXT_COLOR(5, 9, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[9], pokedexApp->msgData, msg_0802_00011, 16, 0, 0, MAKE_TEXT_COLOR(15, 5, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[11], pokedexApp->msgData, msg_0802_00011, 16, 0, 0, MAKE_TEXT_COLOR(15, 5, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintWeight(pokedexApp, pokedexApp->curSpecies, state, 10, 32, 0, MAKE_TEXT_COLOR(15, 5, 0), POKEDEX_TEXT_ALIGN_CENTER);
    if (PlayerProfile_GetTrainerGender(pokedexApp->args->playerProfile) == PLAYER_GENDER_MALE) {
        PokedexApp_PrintMessage(&pokedexApp->windows[7], pokedexApp->msgData, msg_0802_00138, 32, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(&pokedexApp->windows[12], pokedexApp->msgData, msg_0802_00140, 32, 0, 0, MAKE_TEXT_COLOR(15, 5, 0), POKEDEX_TEXT_ALIGN_CENTER);
    } else {
        PokedexApp_PrintMessage(&pokedexApp->windows[7], pokedexApp->msgData, msg_0802_00139, 32, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
        PokedexApp_PrintMessage(&pokedexApp->windows[12], pokedexApp->msgData, msg_0802_00141, 32, 0, 0, MAKE_TEXT_COLOR(15, 5, 0), POKEDEX_TEXT_ALIGN_CENTER);
    }
    for (u32 i = 0; i < 13; i++) {
        ScheduleWindowCopyToVram(&pokedexApp->windows[i]);
    }
}

void PokedexApp_FreeSizeCheckWindows(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 13; i++) {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[i]);
    }
    PokedexApp_RemoveAllWindows(pokedexApp);
}

// Screen 4 (unidentified species): title and message.
void PokedexApp_SetupEntryMenuWindows(PokedexAppData *pokedexApp) {
    u32 i;

    PokedexApp_AddWindows(pokedexApp, sPokedexEntryMenuWindowTemplates, 2);
    for (i = 0; i < 2; i++) {
        FillWindowPixelBuffer(&pokedexApp->windows[i], 0);
    }
    PokedexApp_PrintMessage(&pokedexApp->windows[0], pokedexApp->msgData, msg_0802_00173, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    PokedexApp_PrintMessage(&pokedexApp->windows[1], pokedexApp->msgData, msg_0802_00174, 60, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
    for (i = 0; i < 2; i++) {
        ScheduleWindowCopyToVram(&pokedexApp->windows[i]);
    }
}

void PokedexApp_FreeEntryMenuWindows(PokedexAppData *pokedexApp) {
    u32 i;

    for (i = 0; i < 2; i++) {
        ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[i]);
    }
    PokedexApp_RemoveAllWindows(pokedexApp);
}

void PokedexApp_SetupFormsWindows(PokedexAppData *pokedexApp) {
    PokedexApp_AddWindows(pokedexApp, sFormsWindowTemplates, 16);
    PokedexApp_DrawFormsWindows(pokedexApp);
}

void PokedexApp_FreeFormsWindows(PokedexAppData *pokedexApp) {
    PokedexApp_ClearFormsWindows(pokedexApp);
    PokedexApp_RemoveAllWindows(pokedexApp);
}

void PokedexApp_DrawFormsWindows(PokedexAppData *pokedexApp) {
    PokedexApp_DrawFormList(pokedexApp);
    PokedexApp_DrawFormsTitle(pokedexApp);
    PokedexApp_DrawSelectedFormName(pokedexApp);
}

// The form list: six rows (windows 10-15 on cells 17-22) around the selected form selectedForm.
void PokedexApp_DrawFormList(PokedexAppData *pokedexApp) {
    u32 i;
    int index;

    for (i = 0; i < 6; i++) {
        FillWindowPixelBuffer(&pokedexApp->windows[i + 10], 0);
        index = pokedexApp->selectedForm + i - 2;
        if (index >= 0 && index < pokedexApp->numSeenForms) {
            PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, i + 10, PokedexApp_GetFormNameMsg(pokedexApp, index), 0, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_LEFT);
        }
        CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[i + 10]);
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, i + 17, (s8)GetWindowX(&pokedexApp->windows[i + 10]), (s8)GetWindowY(&pokedexApp->windows[i + 10]));
    }
}

// The message naming seen form index of the current species (msgFormat holds the species name for the
// generic entries).
u32 PokedexApp_GetFormNameMsg(PokedexAppData *pokedexApp, int index) {
    String *string;

    switch (pokedexApp->curSpecies) {
    case SPECIES_UNOWN:
        return 121;
    case SPECIES_SHELLOS:
    case SPECIES_GASTRODON:
        return (pokedexApp->seenForms[index] ^ 0x80) + 116;
    case SPECIES_BURMY:
    case SPECIES_WORMADAM:
        return (pokedexApp->seenForms[index] ^ 0x80) + 118;
    case SPECIES_DEOXYS:
        return (pokedexApp->seenForms[index] ^ 0x80) + 145;
    case SPECIES_SHAYMIN:
        return (pokedexApp->seenForms[index] ^ 0x80) + 149;
    case SPECIES_GIRATINA:
        return (pokedexApp->seenForms[index] ^ 0x80) + 151;
    case SPECIES_ROTOM:
        return (pokedexApp->seenForms[index] ^ 0x80) + 153;
    case SPECIES_CASTFORM:
        return (pokedexApp->seenForms[index] ^ 0x80) + 160;
    case SPECIES_CHERRIM:
        return (pokedexApp->seenForms[index] ^ 0x80) + 164;
    case SPECIES_PICHU:
        if ((pokedexApp->seenForms[index] ^ 0x80) == 0) {
            return 114;
        }
        if ((pokedexApp->seenForms[index] ^ 0x80) == 1) {
            return 115;
        }
        return 166;
    default:
        if (pokedexApp->seenForms[index] == 1) {
            return 114;
        }
        if (pokedexApp->seenForms[index] == 2) {
            return 115;
        }
        string = PokedexApp_GetSpeciesNameString(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
        BufferString(pokedexApp->msgFormat, 0, string, 2, 1, 2);
        String_Delete(string);
        return 159;
    }
}

// Redraws the row that scrolled out (cell row -2 or 16) with the form coming in.
void PokedexApp_ScrollFormList(PokedexAppData *pokedexApp, int direction) {
    u32 i;
    s8 x;
    s8 y;

    for (i = 0; i < 6; i++) {
        BgCellManager_GetCellPosition(pokedexApp->bgCellManager, i + 17, &x, &y);
        if (y == -2 || y == 16) {
            break;
        }
    }
    FillWindowPixelBuffer(&pokedexApp->windows[i + 10], 0);
    if (direction < 0) {
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, i + 17, 8, 16);
        if (pokedexApp->selectedForm + 2 < pokedexApp->numSeenForms) {
            PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, i + 10, PokedexApp_GetFormNameMsg(pokedexApp, pokedexApp->selectedForm + 2), 0, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_LEFT);
        }
    } else {
        BgCellManager_DrawCellAt(pokedexApp->bgCellManager, i + 17, 8, -2);
        if (pokedexApp->selectedForm - 2 >= 0) {
            PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, i + 10, PokedexApp_GetFormNameMsg(pokedexApp, pokedexApp->selectedForm - 2), 0, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_LEFT);
        }
    }
    CopyWindowPixelsToVram_TextMode(&pokedexApp->windows[i + 10]);
}

void PokedexApp_DrawFormsTitle(PokedexAppData *pokedexApp) {
    String *string;

    FillWindowPixelBuffer(&pokedexApp->windows[0], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[4], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[1], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[0], pokedexApp->msgData, msg_0802_00170, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    if (pokedexApp->numSeenForms != 1) {
        PokedexApp_PrintMessage(&pokedexApp->windows[4], pokedexApp->msgData, msg_0802_00168, 0, 0, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_LEFT);
    }
    string = PokedexApp_GetSpeciesNameString(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    BufferString(pokedexApp->msgFormat, 0, string, 2, 1, 2);
    String_Delete(string);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, 1, msg_0802_00167, 72, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_RIGHT);
    ScheduleWindowCopyToVram(&pokedexApp->windows[0]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[4]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[1]);
}

void PokedexApp_DrawSelectedFormName(PokedexAppData *pokedexApp) {
    FillWindowPixelBuffer(&pokedexApp->windows[2], 0);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, 2, PokedexApp_GetFormNameMsg(pokedexApp, pokedexApp->selectedForm), 60, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[2]);
}

void PokedexApp_ClearFormsWindows(PokedexAppData *pokedexApp) {
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[0]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[1]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[2]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[4]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[10]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[11]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[12]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[13]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[14]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[15]);
}

void PokedexApp_DrawFormCompareWindows(PokedexAppData *pokedexApp) {
    String *string;

    PokedexApp_ClearFormsWindows(pokedexApp);
    FillWindowPixelBuffer(&pokedexApp->windows[0], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[3], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[5], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[8], 0);
    FillWindowPixelBuffer(&pokedexApp->windows[9], 0);
    PokedexApp_PrintMessage(&pokedexApp->windows[0], pokedexApp->msgData, msg_0802_00170, 0, 0, 4, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_LEFT);
    string = PokedexApp_GetSpeciesNameString(pokedexApp->curSpecies, 2, HEAP_ID_POKEDEX_APP);
    BufferString(pokedexApp->msgFormat, 0, string, 2, 1, 2);
    String_Delete(string);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, 3, msg_0802_00169, 72, 0, 0, MAKE_TEXT_COLOR(2, 1, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[5], pokedexApp->msgData, msg_0802_00170, 24, 0, 0, MAKE_TEXT_COLOR(5, 9, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[8], pokedexApp->msgData, msg_0802_00171, 48, 4, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
    PokedexApp_PrintMessage(&pokedexApp->windows[9], pokedexApp->msgData, msg_0802_00172, 48, 4, 4, MAKE_TEXT_COLOR(15, 12, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[0]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[3]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[5]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[8]);
    ScheduleWindowCopyToVram(&pokedexApp->windows[9]);
    PokedexApp_DrawCenteredFormName(pokedexApp, 6, pokedexApp->selectedForm);
    PokedexApp_DrawCenteredFormName(pokedexApp, 7, pokedexApp->compareForm);
}

void PokedexApp_ClearFormCompareWindows(PokedexAppData *pokedexApp) {
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[0]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[3]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[5]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[8]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[9]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[6]);
    ClearWindowTilemapAndScheduleTransfer(&pokedexApp->windows[7]);
}

void PokedexApp_DrawCenteredFormName(PokedexAppData *pokedexApp, int windowId, int index) {
    int msgNo, width;

    FillWindowPixelBuffer(&pokedexApp->windows[windowId], 0);
    msgNo = PokedexApp_GetFormNameMsg(pokedexApp, index);
    width = GetWindowWidth(&pokedexApp->windows[windowId]);
    PokedexApp_PrintFormattedMessage(pokedexApp, pokedexApp->msgData, windowId, msgNo, (width * 8) / 2, 0, 0, MAKE_TEXT_COLOR(5, 9, 0), POKEDEX_TEXT_ALIGN_CENTER);
    ScheduleWindowCopyToVram(&pokedexApp->windows[windowId]);
}
