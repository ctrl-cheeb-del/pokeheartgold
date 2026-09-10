#include "overlay_27_helpers_internal.h"

void ov27_0225C01C(Ov27Work *work) {
    ov27_0225BED8(work, 0x20, 11, 21, 9, 2, 372, -1, 0);
}

void ov27_0225C044(Ov27Work *work) {
    ov27_0225BF84(work, 14, 19, *LocalFieldData_GetSafariBallsCounter(Save_LocalFieldData_Get(work->unk10->saveData)));
    ov27_0225C01C(work);
}

void ov27_0225C06C(Ov27Work *work) {
    ov27_0225BF84(work, 14, 14, FieldSystem_GetParkBallCount(work->unk10));
}
