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

void ov40_0222F9C0(void *p) {
    Sprite_DeleteAndFreeResources(PTR(p, 0x18));
    Sprite_DeleteAndFreeResources(PTR(p, 0x1C));
}

void ov40_0222F9D4(void *p, int value) {
    ov40_0222F9E0(p, value, 5);
}
