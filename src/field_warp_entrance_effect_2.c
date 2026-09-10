#include "field_warp_entrance_effect_internal.h"

Ov01_02200858_Work *ov01_02200858(FieldEffectManager *a0);
void ov01_02200874(Ov01_02200858_Work *work);
void ov01_02200884(Ov01_02200858_Work *work);
void ov01_022008A8(Ov01_02200858_Work *work);
void ov01_022008B4(PlayerAvatar *a0);
BOOL ov01_02200900(void *a0, Ov01_02200858_Inst *inst);
void ov01_02200938(void *a0, Ov01_02200858_Inst *inst);
void ov01_0220093C(void *a0, Ov01_02200858_Inst *inst);
void ov01_02200A08(void *a0, Ov01_02200858_Inst *inst);
int ov01_02200AB0(u8 tile);

extern const UnkOv01_02209280 ov01_02209340;

int ov01_02200AB0(u8 tile) {
    if (MetatileBehavior_IsWarpEntranceNorth(tile)) {
        return 0;
    }
    if (MetatileBehavior_IsWarpEntranceSouth(tile)) {
        return 1;
    }
    if (MetatileBehavior_IsWarpEntranceWest(tile)) {
        return 2;
    }
    if (MetatileBehavior_IsWarpEntranceEast(tile)) {
        return 3;
    }
    return -1;
}
