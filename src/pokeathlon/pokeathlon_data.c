#include "pokeathlon/pokeathlon.h"

extern void PokeathlonDiscCatch_Intro(void);
extern void PokeathlonDiscCatch_Play(void);
extern void PokeathlonDiscCatch_Finish(void);
extern void PokeathlonGoalRoll_State_Play(void);
extern void PokeathlonGoalRoll_State_Finish(void);
extern void PokeathlonRingDrop_State_FadeIn(void);
extern void PokeathlonRingDrop_State_Play(void);
extern void PokeathlonRingDrop_State_Finish(void);

u8 gPokeathlonGoalRollBounceOffsets[] = { 0x00, 0x04, 0x02, 0x01, 0x00, 0x01, 0x00, 0x01 };

void *gPokeathlonGoalRollStates[] = {
    PokeathlonGoalRoll_State_Play,
    PokeathlonGoalRoll_State_Finish
};

void *gPokeathlonRingDropStates[] = {
    PokeathlonRingDrop_State_FadeIn,
    PokeathlonRingDrop_State_Play,
    PokeathlonRingDrop_State_Finish,
    NULL
};

// u8 gPokeathlonCirclePushContacts[0x900]; // Non-matching yet if moved here (not sure why)

int gPokeathlonLampJumpTrampolineRed;
u8 gPokeathlonBlockSmashFramesSinceHit[0x1c];
