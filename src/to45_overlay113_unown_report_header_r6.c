#include "to45_overlay113_unown_report_header_r6_private.h"

void ov113_021E5FC0(To45Ov113State *state) {
    s32 i;
    u32 width;
    u8 *sprite;

    ov113_021E6238(state, state->raw + 0x130, 6);
    ov113_021E6238(state, state->raw + 0x100, 2);
    sprite = state->raw;
    for (i = 0; i < 14; i++, sprite += 4) {
        ManagedSprite_SetDrawFlag(TO45_PTR(sprite, 0xC4), FALSE);
    }
    ReadMsgDataIntoString(TO45_PTR(state, 0x44), 1, TO45_PTR(state, 0x50));
    ov113_021E629C(state->raw + 0x78, TO45_PTR(state, 0x50), 0, 0x38);
    width = FontID_String_GetWidth(0, TO45_PTR(state, 0x5C), 0);
    ov113_021E629C(state->raw + 0x78, TO45_PTR(state, 0x5C), (u16)(0xB0 - width), 0x48);
    ReadMsgDataIntoString(TO45_PTR(state, 0x44), 3, TO45_PTR(state, 0x50));
    ov113_021E629C(state->raw + 0x88, TO45_PTR(state, 0x50), 4, 0x3C);
    ReadMsgDataIntoString(TO45_PTR(state, 0x44), 4, TO45_PTR(state, 0x4C));
    BufferIntegerAsString(TO45_PTR(state, 0x48), 0, state->raw[0x1F], 2, 1, TRUE);
    StringExpandPlaceholders(TO45_PTR(state, 0x48), TO45_PTR(state, 0x50), TO45_PTR(state, 0x4C));
    ov113_021E629C(state->raw + 0x88, TO45_PTR(state, 0x50), 4, 0x4C);
}
