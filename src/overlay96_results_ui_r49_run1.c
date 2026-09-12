#include "overlay96_results_ui_r49_private.h"

u16 ov96_021EF5F4(Ov96ResultsUiR49 *work, int index) {
    u16 *records = PokeathlonSave_GetRecordsSolo2(Save_Pokeathlon_Get(PokeathlonCourse_GetSaveData(work->course)));
    return *(u16 *)((u8 *)records + index * 0x2C);
}
