#ifndef OVERLAY49_RESIDUAL_66_PRIVATE_H
#define OVERLAY49_RESIDUAL_66_PRIVATE_H

#include "global.h"

// Overlay45 handle passed through from the caller. Matches the tracked
// definition in src/overlay45_helpers_13.c.
typedef struct Overlay45State Overlay45State;

// Transition record driven by the two functions in this unit.
//   0x00 u16 active   - non-zero while a transition is in flight
//   0x02 u16 value    - value handed to ov45_0222AED8 on arrival
//   0x04 u16 target   - awaited ov45_0222B034 reading
//   0x06 u16 initial  - ov45_0222B034 reading captured at start
//   0x08 u32 current  - most recent ov45_0222B034 reading
typedef struct Ov49Transition Ov49Transition;

void ov49_02265274(Ov49Transition *state, Overlay45State *object, u16 value, u16 target);
void ov49_0226529C(Ov49Transition *state, Overlay45State *object);

#endif // OVERLAY49_RESIDUAL_66_PRIVATE_H
