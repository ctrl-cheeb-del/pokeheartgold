#include "remote_player_positions_private.h"
#define BASE (_021D41C4->raw)
#define AVATAR (*(PlayerAvatar **)(*(u8 **)(BASE + 0x30) + 0x40))

void sub_02056EF4(void) {
    u32 slot;
    slot = sub_0203769C();
    *(PlayerAvatar **)(BASE + 4 + slot * 4) = AVATAR;
    BASE[0x24 + sub_0203769C()] = 1;
    slot = sub_0203769C();
    *(u16 *)(BASE + 0x74 + slot * 8) = PlayerAvatar_GetXCoord(AVATAR);
    slot = sub_0203769C();
    *(u16 *)(BASE + 0x76 + slot * 8) = PlayerAvatar_GetZCoord(AVATAR);
    slot = sub_0203769C();
    BASE[0x78 + slot * 8] = PlayerAvatar_GetFacingDirection(AVATAR);
    slot = sub_0203769C();
    *(u16 *)(BASE + 0x34 + slot * 8) = PlayerAvatar_GetXCoord(AVATAR);
    slot = sub_0203769C();
    *(u16 *)(BASE + 0x36 + slot * 8) = PlayerAvatar_GetZCoord(AVATAR);
    slot = sub_0203769C();
    BASE[0x38 + slot * 8] = PlayerAvatar_GetFacingDirection(AVATAR);
}
