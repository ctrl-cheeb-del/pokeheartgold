#include "sprite_system.h"
#include "to45_overlay27_r8_private.h"

void ov27_0225B010(Ov27WorkR8 *work);

void ov27_0225AEA8(FieldSystem *fieldSystem, GF_2DGfxResMan **resMans, Ov27ResourcePair *pair, int index, int id, int a5, Bag *bag, int mode) {
    u8 entry = ov27_0225CFC8[mode][index];
    NarcId narcId = NARC_a_0_1_4;
    int charIdx = 18;
    int plttIdx = 14;
    int compressed = TRUE;
    int plttNum = 1;

    if (entry != 13) {
        if (entry == 2 && a5 == 1) {
            charIdx = 27;
        } else {
            charIdx = ov27_0225CF94[entry][0];
            if (charIdx == 0xFFFF) {
                BugContest *contest = FieldSystem_BugContest_Get(fieldSystem);
                GF_ASSERT(contest != NULL);
                if (contest->caught_poke) {
                    compressed = FALSE;
                    narcId = NARC_poketool_icongra_poke_icon;
                    plttNum = 3;
                    plttIdx = sub_02074490();
                    charIdx = Pokemon_GetIconNaix(contest->mon);
                } else {
                    charIdx = 18;
                }
            }
        }
    }

    if (index == 7) {
        compressed = FALSE;
        narcId = NARC_itemtool_itemdata_item_icon;
        plttIdx = GetItemIndexMapping(Bag_GetRegisteredItem1(bag), 2);
        charIdx = GetItemIndexMapping(Bag_GetRegisteredItem1(bag), 1);
    } else if (index == 8) {
        compressed = FALSE;
        narcId = NARC_itemtool_itemdata_item_icon;
        plttIdx = GetItemIndexMapping(Bag_GetRegisteredItem2(bag), 2);
        charIdx = GetItemIndexMapping(Bag_GetRegisteredItem2(bag), 1);
    } else if (index == 9) {
        plttIdx = 7;
        charIdx = 70;
        plttNum = 4;
    } else if (index == 10) {
        u32 item = ov27_0225AE8C(mode);
        compressed = FALSE;
        narcId = NARC_itemtool_itemdata_item_icon;
        plttIdx = GetItemIndexMapping(item, 2);
        charIdx = GetItemIndexMapping(item, 1);
    }

    pair->character = AddCharResObjFromNarc(resMans[0], narcId, charIdx, compressed, id, 2, HEAP_ID_8);
    pair->palette = AddPlttResObjFromNarc(resMans[1], narcId, plttIdx, FALSE, id, 2, plttNum, HEAP_ID_8);
    SpriteTransfer_CreateCharTransferTask_AllocAtEnd(pair->character);
    sub_0200A740(pair->character);
    SpriteTransfer_CreatePlttTransferTask(pair->palette);
    sub_0200A740(pair->palette);
}
