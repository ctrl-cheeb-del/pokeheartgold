#include "r40_overlay_29_residual_4_candidate_private.h"

typedef struct SystemPrivate {
    u8 pad[0x48];
    u32 newKeys;
} SystemPrivate;
extern SystemPrivate gSystem;
extern const void *ov29_0225E1AC[];
extern int TouchscreenHitbox_FindRectAtTouchNew(const void *);
extern int GridInputHandler_HandleInput_AllowHold(void *);
extern void GridInputHandler_SetNextInput(void *, int);
extern void PlaySE(u16);
extern void SpriteList_RenderAndAnimateSprites(void *);

void ov29_0225DCD0(void *unused, Ov29StatePrivate *state) {
    u32 input;
    u32 rem;

    switch (state->state) {
    case 0:
        input = TouchscreenHitbox_FindRectAtTouchNew(ov29_0225E1AC[state->count]);
        if (input != -1) {
            state->selection = input;
            ov29_0225DC50(state);
            ov29_0225E028(state, input + 5, state->digits[state->selection] + 12, state->digits[state->selection] + 1, 0);
            PlaySE(0x5DD);
        } else if (gSystem.newKeys & 8) {
            GridInputHandler_SetNextInput(state->gridInput, 11);
            ov29_0225DB9C(state, 11);
            PlaySE(0x5DD);
        } else if (gSystem.newKeys & 2) {
            if (ov29_0225DEB8(state, -1) == 1) {
                PlaySE(0x5DD);
            }
        } else {
            input = GridInputHandler_HandleInput_AllowHold(state->gridInput);
            switch (input) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
            case 8:
            case 9:
                ov29_0225DEF4(state, input);
                ov29_0225DEB8(state, 1);
                rem = input % 5;
                ov29_0225E078(state, rem * 6 + 1, (input / 5) * 6 + 7, 0);
                PlaySE(0x5DD);
                break;
            case 10:
                ov29_0225E028(state, 2, 4, 3, 0);
                ov29_0225DEB8(state, -1);
                PlaySE(0x5DD);
                break;
            case 11:
                ov29_0225E0E0(state);
                if (state->computed > *(u32 *)state->output) {
                    ov29_0225E028(state, 3, 4, 3, 0);
                    PlaySE(0x5DD);
                } else {
                    ((u32 *)state->output)[1] = state->computed;
                    ov29_0225E028(state, 3, 4, 3, 2);
                    PlaySE(0x5DD);
                }
                break;
            case 12:
                ((u32 *)state->output)[1] = 0;
                ov29_0225E028(state, 4, 4, 3, 2);
                PlaySE(0x5DD);
                break;
            }
        }
        break;
    case 1:
        if (!ov29_0225DF74(state)) {
            state->state = state->pending;
        }
        break;
    case 2:
        break;
    }
    ov29_0225DB7C(state);
    SpriteList_RenderAndAnimateSprites(state->spriteList);
}
