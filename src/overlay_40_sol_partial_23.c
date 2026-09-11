#include "overlay_40_sol_partial_internal.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))
#define HALF(p, off) (*(u16 *)((u8 *)(p) + (off)))

#define TRIGGER_FN(name, off)                               \
    int name(void *p) {                                     \
        void *inner = PTR(p, 0x860);                        \
        TouchHitboxController_IsTriggered(PTR(inner, off)); \
        return 0;                                           \
    }

#define STEP_FN(name, check, state)  \
    int name(void *p) {              \
        if (check(p)) {              \
            ov40_0222BF80(p, state); \
        }                            \
        return 0;                    \
    }

void ov40_022306A0(void *p, BOOL draw) {
    int i;
    for (i = 0; i < 12; i++, p = (u8 *)p + 4) {
        void *sprite = PTR(p, 0xC);
        if (sprite != NULL) {
            ManagedSprite_SetDrawFlag(sprite, draw);
        }
    }
}
