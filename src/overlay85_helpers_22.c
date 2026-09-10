#include "overlay85_helpers_internal.h"

// ---- callees implemented elsewhere in the overlay ----
void ov85_021E7194(BattleArcadeWork *work, u32 a1);
BOOL ov85_021E8628(BattleArcadeWork *work);
u32 ov85_021E8614(BattleArcadeWork *work, u32 a1);
void ov85_021E84EC(BattleArcadeWork *work, u32 a1);
void ov85_021E81E0(BattleArcadeWork *work);
void ov85_021E6DAC(BattleArcadeWork *work, u32 a1);
void ov85_021E8530(void *a0);
void ov85_021E7660(BattleArcadeWork *work);
void ov85_021E7734(BattleArcadeWork *work);
void ov85_021E8008(BattleArcadeWork *work, BattleArcadeSub_C30 *sub);
void ov85_021E825C(BattleArcadeWork *work, u16 *a1);
void sub_020699D0(u32 *a0, u32 *a1, u32 *a2, u32 *a3);
int ov85_021E8660(BattleArcadeWork *work);
u32 ov85_021E8898(BattleArcadeWork *work);
u32 ov85_021E8878(BattleArcadeWork *work);
void ov85_021E692C(BattleArcadeWork *work);
void ov85_021E7148(BattleArcadeWork *work);
void ov85_021E6D68(BattleArcadeWork *work);
void ov85_021E6E6C(BattleArcadeWork *work);
void ov85_021E7C70(BattleArcadeWork *work, BattleArcadeSlotA *p);
void ov85_021E7DC8(BattleArcadeSlotB *p);
void ov85_021E7ED0(BattleArcadeSlotC *p);
void ov85_021E8374(BattleArcadeWork *work, BattleArcadeSlotD *p);

// ---- implemented here ----
void ov85_021E5AF0(BattleArcadeWork *work);
BOOL ov85_021E5AF8(BattleArcadeWork *work);
BOOL ov85_021E5B0C(BattleArcadeWork *work);
BOOL ov85_021E5B30(BattleArcadeWork *work);
BOOL ov85_021E5B78(BattleArcadeWork *work);
BOOL ov85_021E5C58(BattleArcadeWork *work);
BOOL ov85_021E5C80(BattleArcadeWork *work);
BOOL ov85_021E5CA4(BattleArcadeWork *work);
BOOL ov85_021E5CD0(BattleArcadeWork *work);
BOOL ov85_021E5CE4(BattleArcadeWork *work);
BOOL ov85_021E5CFC(BattleArcadeWork *work);
BOOL ov85_021E5D20(BattleArcadeWork *work);
BOOL ov85_021E5D84(BattleArcadeWork *work);
BOOL ov85_021E5EE8(BattleArcadeWork *work);
BOOL ov85_021E5F10(BattleArcadeWork *work);
BOOL ov85_021E5F3C(BattleArcadeWork *work);
BOOL ov85_021E5F58(BattleArcadeWork *work);
BOOL ov85_021E5F6C(BattleArcadeWork *work);
BOOL ov85_021E5F84(BattleArcadeWork *work);
BOOL ov85_021E5FD0(BattleArcadeWork *work);
BOOL ov85_021E62A0(BattleArcadeWork *work);
BOOL ov85_021E62B4(BattleArcadeWork *work);
BOOL ov85_021E6474(BattleArcadeWork *work);
BOOL ov85_021E652C(BattleArcadeWork *work);
BOOL ov85_021E6550(BattleArcadeWork *work);
BOOL ov85_021E657C(BattleArcadeWork *work);
BOOL ov85_021E6644(BattleArcadeWork *work);
BOOL ov85_021E6658(BattleArcadeWork *work);
BOOL ov85_021E6674(BattleArcadeWork *work);
BOOL ov85_021E66F4(BattleArcadeWork *work);
BOOL ov85_021E6748(BattleArcadeWork *work);
u32 ov85_021E6760(BattleArcadeWork *work);
void ov85_021E6764(BattleArcadeWork *work);
void ov85_021E67CC(BattleArcadeWork *work);
void ov85_021E6DF0(BattleArcadeWork *work);
void ov85_021E6DFC(BattleArcadeWork *work);
void ov85_021E6E08(BattleArcadeWork *work);
void ov85_021E6EA8(BattleArcadeWork *work, u32 cur);
void ov85_021E7024(BattleArcadeWork *work);
ManagedSprite *ov85_021E7044(BattleArcadeWork *work, const ManagedSpriteTemplate *tmpl);
void ov85_021E72E8(BattleArcadeWork *work);
void ov85_021E7400(BattleArcadeWork *work, u32 idx);
void ov85_021E749C(BattleArcadeWork *work);
BOOL ov85_021E74F0(BattleArcadePoint *pt);
BOOL ov85_021E750C(BattleArcadeWork *work);
void ov85_021E75B8(BattleArcadeWork *work);
void ov85_021E7628(BattleArcadeWork *work);
void ov85_021E7644(BattleArcadeWork *work);
void ov85_021E7650(BattleArcadeWork *work);
void ov85_021E7658(BattleArcadeWork *work);
void ov85_021E7CE0(void *task, BattleArcadeWork *work);
void ov85_021E7D40(BattleArcadeWork *work);
void ov85_021E7D50(BattleArcadeWork *work, u32 a1);
BOOL ov85_021E7DA8(BattleArcadeWork *work);
void ov85_021E7E18(void *task, BattleArcadeWork *work);
void ov85_021E7E78(BattleArcadeWork *work);
void ov85_021E7F50(void *task, BattleArcadeWork *work);
void ov85_021E7FB0(BattleArcadeWork *work);
void ov85_021E80D0(void *task, BattleArcadeWork *work);
void ov85_021E8118(BattleArcadeWork *work);
void ov85_021E8128(BattleArcadeWork *work);
u32 ov85_021E8144(BattleArcadeWork *work);
u32 ov85_021E8150(BattleArcadeWork *work);
void ov85_021E82E4(void *task, BattleArcadeWork *work);
void ov85_021E833C(BattleArcadeWork *work);
u16 ov85_021E834C(BattleArcadeWork *work);
void ov85_021E8358(BattleArcadeWork *work);
void ov85_021E83C0(void *task, BattleArcadeWork *work);

void ov85_021E7CE0(void *task, BattleArcadeWork *work) {
    s32 i;
    BattleArcadeSlotA *p = (BattleArcadeSlotA *)&work->unk_AB4;
    for (i = 0; i < 5; i++, p++) {
        if (p->unk_00 != 0) {
            ov85_021E7C70(work, p);
        }
    }
}
