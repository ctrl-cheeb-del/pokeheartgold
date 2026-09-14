#include "global.h"

#include "overlay49_state_copy_private.h"

void ov49_0225F110(Ov49Residual56Data *data, u32 arg1, u32 arg2) {
    GF_ASSERT(ov49_0225F170(data) == TRUE);
    data->unk14 = data->unk04;
    ov49_0225F190(&data->unk04, arg1, arg2, 0, 0);
}

void ov49_0225F148(Ov49Residual56Data *data) {
    GF_ASSERT(data->unk04.words[1] == 0);
    data->unk04 = data->unk14;
    ov49_0225F19C(&data->unk14);
}
