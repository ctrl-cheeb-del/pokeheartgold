#include "r40_overlay_86_residual_4_residual_2_candidate_private.h"

void ov86_021E64E0(Work *w) {
    FrontierSave *frontier;
    u32 stat;
    u32 value;
    u32 flag;
    u32 *record;
    FillWindowPixelBuffer(&w->windows[0], 0);
    FillWindowPixelBuffer(&w->windows[1], 0);
    FillWindowPixelBuffer(&w->windows[2], 0);
    FillWindowPixelBuffer(&w->windows[3], 0);
    ov86_021E6024(w, 0, 0x18, 0, 0, 0, 0xF0200, 0);
    if (w->mode == 0) {
        value = 0x1A;
    } else if (w->mode == 1) {
        value = 0x1B;
    } else {
        value = 0x1C;
    }
    ov86_021E6024(w, 0, value, 0xE0, 0, 0, 0xF0200, 1);
    ov86_021E668C(w, w->unk8);
    ov86_021E6064(w, 1, 0x33, 0, 0, 0, 0x10200, 0);
    ov86_021E6024(w, 2, 0x1D, 0, 0, 0, 0x10200, 0);
    frontier = Save_Frontier_GetStatic(w->saveData);
    stat = sub_0205C11C(w->mode);
    value = FrontierSave_GetStat(frontier, stat, sub_0205C268(sub_0205C11C(w->mode)));
    if (w->unk8 != value) {
        value = 0;
    } else {
        value = FrontierSave_GetStat(w->frontier, sub_0205C0CC(w->mode), 0xFF);
    }
    ov86_021E5FBC(w, 0, value);
    ov86_021E6064(w, 2, 0x32, 0x70, 0, 0, 0x10200, 2);
    ov86_021E6024(w, 3, 0x2B, 0, 0, 0, 0x10200, 0);
    record = sub_020312C4(w->saveData, 0xB, &flag);
    if (flag != 1) {
        value = 0;
    } else {
        value = sub_020312E0(w->saveData, record, sub_0205C144(w->mode), w->unk8);
    }
    if (record != NULL) {
        Heap_Free(record);
    }
    ov86_021E5FBC(w, 0, value);
    ov86_021E6064(w, 3, 0x32, 0x70, 0, 0, 0x10200, 2);
    ScheduleWindowCopyToVram(&w->windows[0]);
    ScheduleWindowCopyToVram(&w->windows[1]);
    ScheduleWindowCopyToVram(&w->windows[2]);
    ScheduleWindowCopyToVram(&w->windows[3]);
}
