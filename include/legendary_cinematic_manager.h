#ifndef POKEHEARTGOLD_LEGENDARY_CINEMATIC_MANAGER_H
#define POKEHEARTGOLD_LEGENDARY_CINEMATIC_MANAGER_H

#include "field/model_attributes.h"

#include "overlay_manager.h"
#include "save.h"

typedef struct LegendaryCinematicArgs {
    SaveData *saveData;
    ModelAttributes modelAttributes;
    u16 scene;
    u16 timeOfDay;
} LegendaryCinematicArgs;

BOOL LegendaryCinematic_Init(OverlayManager *man, int *state);
BOOL LegendaryCinematic_Main(OverlayManager *man, int *state);
BOOL LegendaryCinematic_Exit(OverlayManager *man, int *state);

#endif // POKEHEARTGOLD_LEGENDARY_CINEMATIC_MANAGER_H
