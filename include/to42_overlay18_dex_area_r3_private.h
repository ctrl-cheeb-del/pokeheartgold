#ifndef POKEHEARTGOLD_OVERLAY_18_RESIDUAL_3_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY_18_RESIDUAL_3_PRIVATE_H

#include "global.h"

#include "application/pokedex/pokedex_internal.h"

#include "message_format.h"

void String_Delete(String *str);
void sub_02019B1C(UnkStruct_0201956C *a0, int a1, s8 *a2, s8 *a3);

void ov18_021EE3AC(PokedexAppData *pokedexApp, MsgData *msgData, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7, u32 a8);
void ov18_021F9648(Window *window, MsgData *msgData, u32 a2, u32 a3, u32 a4, u32 a5, u32 a6, u32 a7);

u32 ov18_021F09D8(PokedexAppData *pokedexApp, int idx);
void ov18_021F0C50(PokedexAppData *pokedexApp);
void ov18_021F0D7C(PokedexAppData *pokedexApp);

#endif
