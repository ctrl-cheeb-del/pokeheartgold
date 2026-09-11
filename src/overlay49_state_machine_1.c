#include "overlay49_state_machine_private.h"

void ov49_0225ECF0(Ov49Small *work, void *arg) {
    switch (work->state) {
    case 0: break;
    case 1: ov49_0225ED68(work, arg); work->state = 2; break;
    case 2: if (ov49_0225D3BC(arg, work->unk0, 0) == 0) work->state = 3; break;
    case 3: ov49_0225EC28(work); work->state = 4; break;
    case 4: if (ov49_0225EC30(work) == 1) { ov49_0225D494(work->unk0, 0); ov49_0225D4E8(work->unk0); ov49_0225D4F0(work->unk0, 0x1000, 0x1000, 0x1000); work->state = 0; } break;
    default: GF_ASSERT(FALSE); break;
    }
}

void ov49_0225ED68(Ov49Small *work, void *ctx)
{
    ov49_0225D4C8(work->unk0, work->unk8);
    ov49_0225D214(ctx, work->unk0, 0, 1);
    ov49_0225D214(ctx, work->unk0, 1, 1);
    ov49_0225D494(work->unk0, 1);
}

void ov49_0225ED98(Ov49Small *work, void *arg) {
    switch (work->state) {
    case 0: break;
    case 1: ov49_0225EE10(work, arg); work->state = 2; break;
    case 2: if (ov49_0225D3BC(arg, work->unk0, 0) == 0) work->state = 3; break;
    case 3: ov49_0225EC28(work); work->state = 4; break;
    case 4: if (ov49_0225EC30(work) == 1) { ov49_0225D494(work->unk0, 0); ov49_0225D4E8(work->unk0); ov49_0225D4F0(work->unk0, 0x1000, 0x1000, 0x1000); work->state = 0; } break;
    default: GF_ASSERT(FALSE); break;
    }
}

void ov49_0225EE10(Ov49Small *work, void *ctx)
{
    ov49_0225D4C8(work->unk0, work->unk8);
    ov49_0225D214(ctx, work->unk0, 0, 1);
    ov49_0225D214(ctx, work->unk0, 1, 1);
    ov49_0225D214(ctx, work->unk0, 2, 1);
    ov49_0225D494(work->unk0, 1);
}
