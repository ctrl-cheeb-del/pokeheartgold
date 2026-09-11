#include "overlay_14_sol_partial_internal.h"

void ov14_021E5A50(void *, void *);
void ov14_021E5A44(void *, void *);
void ov14_021E5A54(void *);
void ov14_021E5A60(void);
void ov14_021E7468(void *);
u32 ov14_021E7930(void *);
void ov14_021E7AD4(void *, u32, u32, u32);
u32 ov14_021E7B8C(void *);
u32 ov14_021E7B98(void *);
void ov14_021E7D7C(void *);
void ov14_021E7D8C(void *, u32, u32);
void ov14_021E81A8(void *, u32);
void ov14_021E954C(void *);
void ov14_021EBDE0(void *);
u32 ov14_021EBF8C(void *);
u32 ov14_021EC344(void *);
u32 ov14_021ED350(void *);
u32 ov14_021ED620(void *);
u32 ov14_021ED6C4(void *);
u32 ov14_021ED960(void *);
u32 ov14_021EDA3C(void *);
u32 ov14_021EDF90(void *);
u32 ov14_021EE328(void *);
u32 ov14_021EE4D8(void *);
u32 ov14_021F0244(void *, u32);
u32 ov14_021F1534(void *);
void ov14_021F1F38(void *);
u32 ov14_021F2610(void *);
void ov14_021F261C(void *);
void ov14_021F2624(void *);
void ov14_021F262C(void *);
void ov14_021F2634(void *);
u32 ov14_021F2728(void *);
u32 ov14_021F2760(void *);
u32 ov14_021F276C(void *);
void ov14_021F27CC(void *);
void ov14_021F2810(void *);
void ov14_021F2890(void *);
void ov14_021F34DC(void *, u32);
void ov14_021F395C(void *, s32, s32);
u32 ov14_021F40DC(void *);
void ov14_021F604C(void *);
void ov14_021F63A8(void *);
void ov14_021F63B8(void *);
void *ov14_021F6628(void);
void ov14_021F6678(void *, u32);
void ov14_021F6688(void *, u32);
s32 ov14_021F6A14(void);
s32 ov14_021F6A24(void);
s32 ov14_021F6A34(void);
void ov14_021F6B7C(void *);
void ov14_021E5E94(void *);
void ov14_021E5ED0(void *);
void ov14_021E5EE8(void *);
void ov14_021E7264(void *);
void ov14_021E821C(void *);
void ov14_021E827C(void *);
void ov14_021E94A8(void *);
u32 ov14_021E9518(void *);
void ov14_021E95B4(void *);
void ov14_021E9604(void *);
u32 ov14_021EB18C(void *);
u32 ov14_021EB27C(void *);
u32 ov14_021EBDCC(void *);
u32 ov14_021ED2C8(void *);
u32 ov14_021ED60C(void *);
void ov14_021F1F24(void *);
u32 ov14_021F2A04(void *, u32);
void ov14_021F2A60(void *, u32, u32);
void ov14_021F2C04(void *);
void ov14_021F33E8(void *);
void ov14_021F34C8(void *, u32, u32);
void ov14_021F4940(void *, u32, s32 *, s32 *);
void ov14_021F62CC(void *);
void ov14_021F62E4(void *);
void ov14_021F62FC(void *);
void ov14_021F63F0(void *);
void ov14_021F6844(void *, u32, u32);
void ov14_021F6B10(void *);
void ov14_021E76B8(void *);
void ov14_021E7DF8(void *);
void ov14_021F2700(void *);
void ov14_021F28FC(void *);
void ov14_021F29AC(void *);
void ov14_021EDE20(void *);
void ov14_021F49C8(void *);

#define CALL_196E8(name, a, b, c) \
    void name(void *p) {          \
        sub_020196E8(p, a, b, c); \
    }

#define FREE_RETURN(name, value)                 \
    u32 name(void *p) {                          \
        Heap_Free(PTR_AT(PTR_AT(p, 0x34), 0xc)); \
        return value;                            \
    }

#define TWO_CALLS(name, second) \
    void name(void *p) {        \
        ov14_021E76B8(p);       \
        second(p);              \
    }

#define CALL_5950(name, a, b)      \
    void name(void *p, u32 v) {    \
        ov14_021F5950(p, a, b, v); \
    }

#define CALL_6698(name, id)      \
    void name(void *p, u32 v) {  \
        ov14_021F6698(p, id, v); \
    }

#define CALL_198FC(name, a, b, c, d) \
    void name(void *p) {             \
        sub_020198FC(p, a, b, c, d); \
    }

#define CALL_67B0(name, a, next)   \
    u32 name(void *p) {            \
        ov14_021F67B0(p, a, 0x25); \
        U32_AT(p, 0x30) = next;    \
        return 6;                  \
    }

#define CALL_5BD8(name, id)               \
    void name(void *p) {                  \
        ov14_021F5BD8(p, 0x29, id, 0, 3); \
    }

#define PREP_196E8(name, a, b, c) \
    void name(void *p) {          \
        sub_0201980C(p, a);       \
        sub_020196E8(p, a, b, c); \
    }

#define RESET_7AC4(name)                               \
    void name(void *p) {                               \
        ov14_021F7AC4(PTR_AT(p, 0x34));                \
        ov14_021E5A50(PTR_AT(p, 0x34), ov14_021E9F20); \
    }

void ov14_021E76B8(void *p) {
    ov14_021E765C(p);
    ov14_021F40E8(p, 0);
    U8_AT(p, 0x21) = 0xff;
}
