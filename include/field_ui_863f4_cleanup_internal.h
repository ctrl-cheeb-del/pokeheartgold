#ifndef POKEHEARTGOLD_FIELD_UI_863F4_CLEANUP_INTERNAL_H
#define POKEHEARTGOLD_FIELD_UI_863F4_CLEANUP_INTERNAL_H

#include "global.h"

typedef struct ManagedSprite ManagedSprite;
typedef struct Window Window;

typedef struct FieldUi863F4CleanupState {
    u8 raw[0x400];
} FieldUi863F4CleanupState;

void sub_020866CC(FieldUi863F4CleanupState *state);

void Sprite_DeleteAndFreeResources(ManagedSprite *sprite);
void RemoveWindow(Window *window);
void sub_02086FE8(FieldUi863F4CleanupState *state);

#endif
