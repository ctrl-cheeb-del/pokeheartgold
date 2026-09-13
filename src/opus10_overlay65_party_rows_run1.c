#include "opus10_overlay65_party_rows_private.h"

void ov65_0221D674(void *windows, int side, void *party, int index, void *work);
void ov65_0221D930(void *work);
void ov65_0221DBF4(void *p);
void ov65_0221DC34(void *work);
void ov65_0221DCBC(void *state);
int ov65_0221DCFC(int idx, int dir, void *summaries);
void ov65_0221DD34(int idx, void *sprite, int form);
int ov65_0221DDC0(void *input, void *state, void *sprite, void *summaries, int side);

void ov65_0221D8C4(void *windows, int side, void *work) {
    Sprite_SetDrawFlag(PTR((u8 *)work + side * 4, 0x40c), FALSE);
    Sprite_SetDrawFlag(PTR((u8 *)work + (side + 2) * 4, 0x40c), FALSE);
    Sprite_SetDrawFlag(PTR((u8 *)work + (side + 4) * 4, 0x40c), FALSE);
    ClearWindowTilemapAndCopyToVram((u8 *)windows + (side + 0x1a) * 0x10);
    ClearWindowTilemapAndCopyToVram((u8 *)windows + (side + 0x1c) * 0x10);
    ClearWindowTilemapAndCopyToVram((u8 *)windows + (side + 0x1e) * 0x10);
    ClearWindowTilemapAndCopyToVram((u8 *)windows + (side + 0x20) * 0x10);
}
