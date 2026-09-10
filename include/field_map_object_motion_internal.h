#ifndef POKEHEARTGOLD_FIELD_MAP_OBJECT_MOTION_INTERNAL_H
#define POKEHEARTGOLD_FIELD_MAP_OBJECT_MOTION_INTERNAL_H
#include "global.h"
typedef struct LocalConfig {
    u32 a, b, c;
} LocalConfig;
void MapObject_SetFacingVector(void *, const VecFx32 *);
fx32 sub_02023F70(void *);
void sub_02023F40(void *, fx32);
void sub_02023F04(void *, fx32);
void sub_02023EE0(void *, u32);
BOOL MapObject_TestFlagsBits(void *, u32);
void sub_02023EA4(void *, u8);
void *sub_0205F3E8(void *, int);
void *sub_0205F40C(void *);
u32 MapObject_GetSpriteID(void *);
void *ov01_021FD2EC(void *, const LocalConfig *);
void ov01_021F1640(void *);
void GF_AssertFail(void);
s32 _s32_div_f(s32, s32);
void ov01_021F8C00(void *, int);
void ov01_021F8C30(void *);
void ov01_021F8CC8(u32, LocalConfig *);
void ov01_021F8BE0(void *);
void ov01_021F8C3C(void *, u32, int);
void ov01_021F8C64(void *, u32);
void ov01_021F8C88(void *, void *);
void ov01_021F8CFC(void *);
void ov01_021F8D24(void);
void ov01_021F8D28(void *);
void ov01_021F8D40(void *);
void ov01_021F8D58(void *);
void ov01_021F73F4(void *);
void ov01_021F74B4(void *);
void ov01_021F7704(void *);
void ov01_021F73CC(void *);
void ov01_021F7408(void *);
void ov01_021F7478(void *);
void ov01_021F74C8(void *);
void ov01_021F7434(void *);
void *ov01_021F771C(void *);
void ov01_021F77A4(void *);
void ov01_021F77D0(void *);
void ov01_021F95A8(void *, void *);
void *MapObject_GetFacingVector(void *);
void *MapObjectManager_GetFirstActiveObjectByID(void *, int);
BOOL ov01_021FA2D4(void *);
void ov01_021FA3E8(void *, void *);
void ov01_021F9510(void *, void *);
void sub_0205F484(void *);
void ov01_021F9610(void *, void *);
void MapObject_SetFlagsBits(void *, u32);
void MapObject_ClearFlagsBits(void *, u32);
void ov01_021F9630(void *, void *);
void ov01_021F7CBC(void *, void *, const s8 *, int);
void ov01_021F7DA8(void *);
void ov01_021F7DD0(void *);
void ov01_021F7DFC(void *);
void ov01_021F85BC(void *, void *, const s8 *, int);
void ov01_021F8804(void *, void *, const s8 *, int);
void ov01_021F883C(void *, void *, const s8 *, int);
void ov01_021F8BA8(void *, void *, const s8 *, int);
u32 ov01_021FA44C(int);
BOOL ov01_021F9344(void *);
void ov01_021F796C(void *, void *, const s8 *, int);
void ov01_021F79A0(void *, void *, const s8 *, int);
void ov01_021F79DC(void *, void *, const s8 *, int);
void ov01_021F7A18(void *, void *, const s8 *, int);
void ov01_021F7A54(void *, void *, const s8 *, int);
void ov01_021F7C80(void *, void *, const s8 *, int);
void ov01_021F7E28(void *);
void ov01_021F856C(void *, void *, const s8 *, int);
void ov01_021F86B8(void *, void *, const s8 *, int);
fx32 sub_02023F30(void *);
void ov01_021F8708(void *, void *, u32);
void ov01_021F8874(void *, void *, u32);
int MapObject_GetFacingDirection(void *);
int sub_0205F330(void *);
void ov01_021F88F0(void *);
BOOL sub_02023EF4(void *);
void ov01_021F894C(void *);
void ov01_021F8A4C(void *);
void ov01_021F8AB0(void *);
void ov01_021F7FC8(void *, void *, const s8 *, int);
void ov01_021F801C(void *, void *, const s8 *, int);
void ov01_021F8070(void *, void *, const s8 *, int);
void ov01_021F7EE4(void *, void *, s8 *, int);
void ov01_021F7F54(void *, void *, s8 *, int);
u32 ov01_021FA464(int);
void ov01_021F847C(void *, void *, const s8 *, int);
u32 ov01_021FA458(int);
void ov01_021F829C(void *, void *, const s8 *, int);
void ov01_021F8400(void *, void *, const s8 *, int);
void ov01_021F8374(void *, void *, s8 *, int);
void ov01_021F7B14(void *, void *, s8 *, int);
void ov01_021F7A90(void *, void *, s8 *, int);
void ov01_021F7B90(void *, void *, s8 *, int);
void ov01_021F80C4(void *, void *, s8 *, int);
void ov01_021F8164(void *, void *, s8 *, int);
void ov01_021F81FC(void *, void *, s8 *, int);
void ov01_021F84F4(void *);
void ov01_021F878C(void *);
extern const u32 ov01_022089F8[];
extern const u32 ov01_02208A18[];
extern const u32 ov01_02208A28[];
extern const u32 ov01_022073D8[];
static inline void LocalMotion(void *obj, const s8 *state, int index, int expected, const u32 *table) {
    if (index != state[0] || state[2] != expected) {
        sub_02023EE0(obj, table[index]);
        sub_02023F40(obj, 0);
    }
    sub_02023F04(obj, FX32_ONE);
}

static inline void LocalFalling(void *obj, const s8 *state, int index, int expected) {
    fx32 value;
    if (index != state[0] || state[2] != expected) {
        sub_02023EE0(obj, ov01_022089F8[index]);
        sub_02023F40(obj, 15 * FX32_ONE);
    }
    value = sub_02023F70(obj) - FX32_ONE;
    if (value < 0) {
        value = 0;
    }
    sub_02023F40(obj, value);
    sub_02023F04(obj, 0);
}

static inline void LocalTrackedMotion(void *owner, void *obj, const s8 *s, int i, fx32 speed) {
    if (i != s[0]) {
        sub_02023EE0(obj, ov01_021FA44C(i));
        sub_02023F40(obj, 0);
    } else if (s[2] == 9) {
        ov01_021F8C64(obj, ov01_021FA44C(i));
    }
    if (!ov01_021F9344(owner)) {
        sub_02023F04(obj, speed);
    }
}

#endif
