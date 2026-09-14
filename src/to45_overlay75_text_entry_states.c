#include "pm_string.h"
#include "to45_overlay75_text_entry_states_private.h"
extern void *Save_PlayerData_GetOptionsAddr(void *);
extern void *sub_02085400(u32, u32, const u32 *, u32, u32, u32);
extern void *sub_0208541C(u32, u32, const u32 *, u32, u32, u32, u32, u32);
extern void sub_02085438(void *);
extern void GF_AssertFail(void);
extern u32 ov75_02249838(void *, u32);
extern void ov75_02246CF0(State *, u8);
extern u8 ov75_02246CF8(State *);
extern void ov75_02246BCC(State *, s32, s32);
void *ov75_02246D08(State *);
void ov75_02246D40(State *);
void *ov75_02246DB4(State *);
void ov75_02246DFC(State *);
void *ov75_02246E3C(State *);
void ov75_02246E78(State *);
void *ov75_02246D08(State *p) {
    u32 v[4];
    v[0] = 4;
    v[1] = 4;
    v[2] = 4;
    v[3] = 4;
    PTR(p, 0x94) = sub_02085400(0x73, 0x10, v, (u32)Save_PlayerData_GetOptionsAddr(PTR(p, 4)), 4, 0);
    return PTR(p, 0x94);
}
void ov75_02246D40(State *p) {
    void *x = PTR(p, 0x94);
    if (ov75_02249838(PTR(x, 0x1c), 0x73)) {
        ov75_02246CF0(p, 1);
    } else if (ov75_02246CF8(p) == 2) {
        if (String_Compare(PTR(p, 0x110), PTR(x, 0x1c))) {
            ov75_02246CF0(p, 3);
        } else {
            ov75_02246CF0(p, 0);
        }
    } else {
        String_Copy(PTR(p, 0x110), PTR(x, 0x1c));
        ov75_02246CF0(p, 2);
    }
    sub_02085438(x);
    ov75_02246BCC(p, 0, 0);
}
void *ov75_02246DB4(State *p) {
    u32 v[4];
    v[0] = 3;
    v[1] = 4;
    v[2] = 0;
    v[3] = 0;
    PTR(p, 0x94) = sub_0208541C(0x73, 7, v, (u32)Save_PlayerData_GetOptionsAddr(PTR(p, 4)), 5, 1, 1, U16(p, 0x78));
    return PTR(p, 0x94);
}
void ov75_02246DFC(State *p) {
    BOOL ok;
    void *x = PTR(p, 0x94);
    U32(p, 0x108) = (u64)String_atoi(PTR(x, 0x1c), &ok) % 10000;
    if (!ok) {
        GF_AssertFail();
    }
    sub_02085438(x);
    ov75_02246BCC(p, 0, 0);
}
void *ov75_02246E3C(State *p) {
    u32 v[4];
    v[0] = 4;
    v[1] = 0;
    v[2] = 0;
    v[3] = 0;
    PTR(p, 0x94) = sub_02085400(0x73, 4, v, (u32)Save_PlayerData_GetOptionsAddr(PTR(p, 4)), 6, 0);
    return PTR(p, 0x94);
}
void ov75_02246E78(State *p) {
    BOOL ok;
    void *x = PTR(p, 0x94);
    U32(p, 0x104) = String_atoi(PTR(x, 0x1c), &ok);
    if (!ok) {
        GF_AssertFail();
    }
    sub_02085438(x);
    ov75_02246BCC(p, 0, 0);
}
