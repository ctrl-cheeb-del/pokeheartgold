#include "r40_overlay_68_residual_15_private.h"

u32 ov68_021E74D8(MoveRelearner *work) {
    u8 values[2];

    values[0] = _021E7BE8[0];
    values[1] = _021E7BE8[1];
    ov68_021E5B14(work);
    work->summary.party = work->args->unk00;
    work->summary.options = work->args->unk08;
    work->summary.unk11 = 0;
    work->summary.partySlot = 0;
    work->summary.partyCount = 1;
    work->summary.moveToLearn = ov68_021E6BEC(work);
    work->summary.unk12 = 2;
    work->summary.unk2C = 1;
    work->summary.unk28 = 0;
    work->summary.menuInputStatePtr = NULL;
    sub_02089D40(&work->summary, values);
    work->summaryManager = OverlayManager_New(&gOverlayTemplate_PokemonSummary, &work->summary, (enum HeapID)0x42);
    return 0xC;
}

u32 ov68_021E7568(MoveRelearner *work) {
    if (OverlayManager_Run(work->summaryManager)) {
        OverlayManager_Delete(work->summaryManager);
        ov68_021E5A58(work);
        ov68_021E7A18(work, work->args->unk14);
        ov68_021E73A4(work, (u8)work->args->unk14, 3);
        work->args->unk1B = *((u8 *)work + 0x186);
        work->state = 7;
        return 0;
    }
    return 0xC;
}

void ov68_021E75C0(MoveRelearner *work) {
    work->gridInput = GridInputHandler_Create(ov68_021E7CF0, ov68_021E7D64, &ov68_021E7C08, work, TRUE, 0, (enum HeapID)0x42);
    ov68_021E7898(work, 0);
    ov68_021E7910(work);
}
