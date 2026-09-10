#include "field_save_stats_printer_internal.h"

void ov01_021F3F50(struct SaveStatsPrinterStats *stats, FieldSystem *fieldSystem) {
    SaveData *saveData = fieldSystem->saveData;
    Location *position = LocalFieldData_GetCurrentPosition(Save_LocalFieldData_Get(saveData));
    Pokedex *pokedex = Save_Pokedex_Get(saveData);

    stats->mapSec = MapHeader_GetMapSec(position->mapId);
    if (Pokedex_IsEnabled(pokedex)) {
        stats->dexOwned = Pokedex_CountDexOwned(pokedex);
    } else {
        stats->dexOwned = 0;
    }
    stats->profile = Save_PlayerData_GetProfile(saveData);
    stats->igt = Save_PlayerData_GetIGTAddr(saveData);
}

void ov01_021F3F9C(MessageFormat *msgFmt, struct SaveStatsPrinterStats *stats) {
    int value;
    int numDigits;
    PrintingMode mode;

    BufferLandmarkName(msgFmt, 0, stats->mapSec);
    BufferPlayersName(msgFmt, 1, stats->profile);
    BufferIntegerAsString(msgFmt, 2, PlayerProfile_CountBadges(stats->profile), 2, PRINTING_MODE_LEFT_ALIGN, TRUE);

    value = stats->dexOwned;
    if (value >= 100) {
        numDigits = 3;
        mode = PRINTING_MODE_LEFT_ALIGN;
    } else if (value >= 10) {
        numDigits = 3;
        mode = PRINTING_MODE_RIGHT_ALIGN;
    } else {
        numDigits = 2;
        mode = PRINTING_MODE_RIGHT_ALIGN;
    }
    BufferIntegerAsString(msgFmt, 3, value, numDigits, mode, TRUE);

    value = GetIGTHours(stats->igt);
    if (value >= 100) {
        numDigits = 3;
        mode = PRINTING_MODE_LEFT_ALIGN;
    } else if (value >= 10) {
        numDigits = 3;
        mode = PRINTING_MODE_RIGHT_ALIGN;
    } else {
        numDigits = 2;
        mode = PRINTING_MODE_RIGHT_ALIGN;
    }
    BufferIntegerAsString(msgFmt, 4, value, numDigits, mode, TRUE);

    BufferIntegerAsString(msgFmt, 5, GetIGTMinutes(stats->igt), 2, PRINTING_MODE_LEADING_ZEROS, TRUE);
}

int ov01_021F4044(struct SaveStatsPrinterStats *stats) {
    return 10;
}
