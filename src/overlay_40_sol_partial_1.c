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

void ov40_0222BF64(void *p, u32 value, BOOL valid, u32 *out) {
    if (valid) {
        *out = value;
        ov40_0222BF80(p, 0);
        ov40_0222BF8C(p, 0);
    }
}

void ov40_0222BF80(void *p, int value) {
    WORD(p, 4) = value;
    WORD(p, 8) = 0;
    WORD(p, 0xC) = 0;
}

void ov40_0222BF8C(void *p, u32 value) {
    WORD(p, 8) = value;
    WORD(p, 0xC) = 0;
}

void ov40_0222BF94(void *p) {
    sub_02088030(p);
    ov40_0222CE7C(p);
    WORD(p, 0x6E4) = 0;
}
