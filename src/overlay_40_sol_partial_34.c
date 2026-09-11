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

BOOL ov40_0223D5CC(void *p) {
    if (PTR(p, 0x420) == NULL) {
        return FALSE;
    }
    return ov39_02227DB8(ov40_0223D540(p));
}

void ov40_0223D5E8(void *p) {
    if (PTR(p, 0x420) != NULL) {
        ov39_02227778(ov40_0223D540(p));
    }
}

void ov40_0223D600(void *p) {
    if (PTR(p, 0x420) != NULL) {
        ov39_022272EC(ov40_0223D540(p));
    }
}
