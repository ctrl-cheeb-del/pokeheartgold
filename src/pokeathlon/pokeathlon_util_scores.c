#include "global.h"

#include "constants/species.h"

#include "pokeathlon/pokeathlon_course_types_def.h"
#include "pokeathlon/pokeathlon_util.h"

#include "MATH_pop.h"
#include "screen_fade.h"
#include "touchscreen.h"

static void PokeathlonUtil_SetGfxBanks(void);

static const TouchscreenHitbox sPokeathlonExitHitbox = {
    .rect = { 160, 192, 192, 0 }
};

static const u32 sPokeathlonPowersOfTen[] = { 1, 10, 100, 1000, 10000 };

static const u16 sPokeathlonEventThresholds[][2] = {
    { 3000,   2400   },
    { 35,     50     },
    { 40,     60     },
    { 80,     130    },
    { 40,     70     },
    { 350,    500    },
    { 0x3000, 0x4000 },
    { 70,     100    },
    { 30,     55     },
    { 3,      9      },
};

static const s32 sPokeathlonMedalistTrophyThresholds[] = { 200, 150, 100, 75, 50, 25, 10, 5, 2, 1 };

static const GraphicsBanks sPokeathlonUtilGraphicsBanks = {
    .bg = GX_VRAM_BG_128_A,
    .bgextpltt = GX_VRAM_BGEXTPLTT_NONE,
    .subbg = GX_VRAM_SUB_BG_128_C,
    .subbgextpltt = GX_VRAM_SUB_BGEXTPLTT_NONE,
    .obj = GX_VRAM_OBJ_128_B,
    .objextpltt = GX_VRAM_OBJEXTPLTT_NONE,
    .subobj = GX_VRAM_SUB_OBJ_16_I,
    .subobjextpltt = GX_VRAM_SUB_OBJEXTPLTT_NONE,
    .tex = GX_VRAM_TEX_NONE,
    .texpltt = GX_VRAM_TEXPLTT_NONE,
};

BOOL PokeathlonUtil_CheckExitInput(void) {
    TouchscreenHitbox hitbox = sPokeathlonExitHitbox;
    BOOL result = FALSE;
    if (TouchscreenHitbox_TouchNewIsIn(&hitbox) || (gSystem.newKeys & PAD_BUTTON_B)) {
        result = TRUE;
    }
    return result;
}

u32 PokeathlonUtil_GetCourseMedal(u32 value) {
    if (value >= 450) {
        return 2;
    }
    if (value >= 420) {
        return 1;
    }
    return 0;
}

u8 PokeathlonUtil_GetMedalistTrophyCount(s32 value) {
    u8 i;
    for (i = 0; i < NELEMS(sPokeathlonMedalistTrophyThresholds); i++) {
        if (sPokeathlonMedalistTrophyThresholds[i] <= value) {
            break;
        }
    }
    return NELEMS(sPokeathlonMedalistTrophyThresholds) - i;
}

u16 PokeathlonUtil_GetEventThreshold(u32 row, u32 column) {
    return sPokeathlonEventThresholds[row][column];
}

BOOL PokeathlonUtil_BeatsEventThreshold(u32 direction, u32 column, u16 value) {
    u16 limit = PokeathlonUtil_GetEventThreshold(direction, column);
    if (value == POKEATHLON_NO_RECORD) {
        return FALSE;
    }
    if (direction == 0) {
        return value < limit;
    }
    return value > limit;
}

BOOL PokeathlonUtil_ReachesEventThreshold(u32 direction, u32 column, u16 value) {
    u16 limit = PokeathlonUtil_GetEventThreshold(direction, column);
    if (value == POKEATHLON_NO_RECORD) {
        return FALSE;
    }
    if (direction == 0) {
        return value <= limit;
    }
    return value >= limit;
}

u16 PokeathlonUtil_GetRecordScore(const PokeathlonEventRecordEntry *records, u32 index) {
    return records[index].score;
}

u32 PokeathlonUtil_CountSpeciesWithAllMedals(const u8 *data) {
    int i;
    u16 count = 0;
    GF_ASSERT(data != NULL);
    for (i = 0; i < NATIONAL_DEX_COUNT; i++) {
        if (MATH_CountPopulation(data[i]) == POKEATHLON_MEDALS) {
            count++;
        }
    }
    return count;
}

u8 PokeathlonUtil_CountEventTrophies(const Pokeathlon_RecordsSolo *records) {
    u8 i;
    u8 count = 0;
    for (i = 0; i < POKEATHLON_EVENT_COUNT; i++) {
        u16 value = PokeathlonUtil_GetRecordScore(records[i].entries, 0);
        if (PokeathlonUtil_ReachesEventThreshold(i, 1, value)) {
            count++;
        }
    }
    return count;
}

void PokeathlonUtil_ResetDisplay(void) {
    SetMasterBrightnessByColor(PM_LCD_TOP, RGB_BLACK);
    SetMasterBrightnessByColor(PM_LCD_BOTTOM, RGB_BLACK);
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= ~REG_GX_DISPCNT_DISPLAY_MASK;
    reg_GXS_DB_DISPCNT &= ~REG_GXS_DB_DISPCNT_DISPLAY_MASK;
    reg_GX_POWCNT &= 0xFFFF7FFF;
    PokeathlonUtil_SetGfxBanks();
}

void PokeathlonUtil_DisableDisplay(void) {
    Main_SetVBlankIntrCB(NULL, NULL);
    HBlankInterruptDisable();
    GfGfx_DisableEngineAPlanes();
    GfGfx_DisableEngineBPlanes();
    reg_GX_DISPCNT &= 0xFFFFE0FF;
    reg_GXS_DB_DISPCNT &= 0xFFFFE0FF;
}

u32 PokeathlonUtil_GetDecimalDigit(u32 value, u32 digit) {
    u32 remainder;
    GF_ASSERT(digit != 0 && digit < NELEMS(sPokeathlonPowersOfTen));
    remainder = value % sPokeathlonPowersOfTen[digit];
    digit--;
    return remainder / sPokeathlonPowersOfTen[digit];
}

u8 PokeathlonUtil_CountDecimalDigits(s32 value) {
    u8 count = 0;
    if (value == 0) {
        return 1;
    }
    while (1) {
        if (value == 0) {
            break;
        }
        value /= 10;
        count++;
    }
    return count;
}

static void PokeathlonUtil_SetGfxBanks(void) {
    GraphicsBanks banks = sPokeathlonUtilGraphicsBanks;
    GfGfx_SetBanks(&banks);
}
