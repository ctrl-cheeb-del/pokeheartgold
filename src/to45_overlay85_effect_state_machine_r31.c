#include "global.h"

#include "to45_overlay85_effect_r31_private.h"
#include "unk_02005D10.h"

extern void ov85_021E6DF0(BattleArcadeWork *work);
extern void ov85_021E6DFC(BattleArcadeWork *work);
extern void ov85_021E6E08(BattleArcadeWork *work);

void ov85_021E825C(BattleArcadeWork *work, Ov85EffectStateR31 *state) {
    switch (state->state) {
    case 1:
        ov85_021E6DF0(work);
        PlaySE(0x5E4);
        state->timer = 0;
        state->state++;
    case 2:
        state->timer++;
        if (state->timer >= 2) {
            state->timer = 0;
            state->state++;
            ov85_021E6E08(work);
        }
        break;
    case 3:
        state->timer++;
        if (state->timer >= 4) {
            ov85_021E6DF0(work);
            state->timer = 0;
            state->state++;
        }
        break;
    case 4:
        state->timer++;
        if (state->timer >= 2) {
            ov85_021E6DFC(work);
            state->done = 0;
            state->state = 0;
        }
        break;
    }
}
