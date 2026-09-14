#include "global.h"

typedef struct RenderPokemonPicState {
    void *spriteList;
    u8 filler_004[0x160];
    void *managedSprite;
    void *bgConfig;
    u8 layer;
    u8 x;
    u8 y;
    u8 state;
} RenderPokemonPicState;

extern RenderPokemonPicState *sub_0200F5C4(void *, u8, u8, u8, u32);
extern void sub_0200F600(RenderPokemonPicState *, u32);
extern void sub_0200F62C(RenderPokemonPicState *);
extern void sub_0200F684(RenderPokemonPicState *, int, int);
extern void sub_0200F6D4(RenderPokemonPicState *, u16, u8);
extern void sub_0200F714(RenderPokemonPicState *, void *);
extern void sub_0200F82C(RenderPokemonPicState *, u8, u16);
extern void BgCommitTilemapBufferToVram(void *, int);
extern void sub_0200F9DC(RenderPokemonPicState *);
extern void Sprite_DeleteAndFreeResources(void *);
extern void FieldSpriteManager_ReleaseWithoutResDat(RenderPokemonPicState *);
extern void DestroySysTaskAndEnvironment(void *);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern u16 Sprite_GetAnimationFrame(void *);
extern void Sprite_UpdateAnim(void *, fx32);
extern void SpriteList_RenderAndAnimateSprites(void *);

void *DrawPokemonPicFromSpecies(void *, u8, u8, u8, u8, u16, u16, u8, u32);
void *DrawPokemonPicFromMon(void *, u8, u8, u8, u8, u16, void *, u32);
void sub_0200F54C(void *, RenderPokemonPicState *);

void *DrawPokemonPicFromSpecies(void *bgConfig, u8 layer, u8 x, u8 y, u8 paletteNum, u16 baseTile, u16 species, u8 gender, u32 heapId) {
    s32 heap = heapId;
    RenderPokemonPicState *state = sub_0200F5C4(bgConfig, layer, x, y, heap);

    sub_0200F600(state, heap);
    sub_0200F62C(state);
    sub_0200F684(state, x, y);
    sub_0200F6D4(state, species, gender);
    sub_0200F82C(state, paletteNum, baseTile);
    BgCommitTilemapBufferToVram(bgConfig, layer);
    return &state->state;
}

void *DrawPokemonPicFromMon(void *bgConfig, u8 layer, u8 x, u8 y, u8 paletteNum, u16 baseTile, void *mon, u32 heapId) {
    s32 heap = heapId;
    RenderPokemonPicState *state = sub_0200F5C4(bgConfig, layer, x, y, heap);

    sub_0200F600(state, heap);
    sub_0200F62C(state);
    sub_0200F684(state, x, y);
    sub_0200F714(state, mon);
    sub_0200F82C(state, paletteNum, baseTile);
    BgCommitTilemapBufferToVram(bgConfig, layer);
    return &state->state;
}

void sub_0200F54C(void *task, RenderPokemonPicState *state) {
    switch (state->state) {
    case 1:
        sub_0200F9DC(state);
        Sprite_DeleteAndFreeResources(state->managedSprite);
        FieldSpriteManager_ReleaseWithoutResDat(state);
        DestroySysTaskAndEnvironment(task);
        return;
    case 2:
        state->state = 3;
        Sprite_SetAnimCtrlSeq(*(void **)state->managedSprite, 1);
        break;
    case 3:
        if (Sprite_GetAnimationFrame(*(void **)state->managedSprite) == 6) {
            state->state = 0;
        }
        break;
    }

    Sprite_UpdateAnim(*(void **)state->managedSprite, FX32_ONE);
    SpriteList_RenderAndAnimateSprites(state->spriteList);
}
