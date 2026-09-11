#include "remote_player_coords_1_private.h"

int sub_02057A34(int player) {
 u8 *p;
 if (_021D41C4 == 0) return 0xFFFF;
 if (player == sub_0203769C()) return *(u16 *)(_021D41C4->raw + player*8 + 0x74);
 if (sub_02057A0C()) {
  p=(u8 *)_021D41C4;
  if (*(p + player + 0x24) != 0) goto success;
 }
 return 0xFFFF;
success:
 return *(u16 *)(p + player*8 + 0x74);
}

int sub_02057A88(int player) {
 u8 *p;
 if (_021D41C4 == 0) return 0xFFFF;
 if (player == sub_0203769C()) return *(u16 *)(_021D41C4->raw + player*8 + 0x76);
 if (sub_02057A0C()) {
  p=(u8 *)_021D41C4;
  if (*(p + player + 0x24) != 0) goto success;
 }
 return 0xFFFF;
success:
 return *(u16 *)(p + player*8 + 0x76);
}

int sub_02057ADC(int player) {
 int x=sub_02057A34(player); if(x==0xFFFF)return 0xFFFF;
 return *(u16 *)(_021D41C4->raw+player*8+0x74)+GetDeltaXByFacingDirection(*(s8 *)(_021D41C4->raw+player*8+0x78));
}

int sub_02057B14(int player) {
 int z=sub_02057A88(player); if(z==0xFFFF)return 0xFFFF;
 return *(u16 *)(_021D41C4->raw+player*8+0x76)+GetDeltaYByFacingDirection(*(s8 *)(_021D41C4->raw+player*8+0x78));
}
