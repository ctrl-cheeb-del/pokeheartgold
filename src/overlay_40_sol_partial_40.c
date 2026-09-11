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

void ov40_022439B8(void *p) {
    WORD(p, 0x29C) = 0;
    WORD(p, 0x2A0) = 0;
    WORD(p, 0x2A4) = 0;
}
