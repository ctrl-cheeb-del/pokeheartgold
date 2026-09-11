#include "ov99_wave37_packet_private.h"

void ov99_021E7450(R26Work *w) {
    s32 count = ov99_021E7158(w);
    R26Packet packet = {0};
    s32 i;
    BgClearTilemapBufferAndCommit(w->bg, 3);
    ov99_021E7428(w, 0);
    for (i = 0; i < count; i++) {
        u16 species = w->species[(((w->flags.raw << 13) >> 27) * 30) + i];
        packet.word0 = (packet.word0 & 0xFFFFFE00) | (species & 0x1FF);
        packet.word0 = (packet.word0 & 0xFFFFC1FF) | ((ov99_021E71E4(w, species) << 27) >> 18);
        R26Work *spriteWork = (R26Work *)((u8 *)w + ((i + 20) * 4));
        ov98_0221E970(w->unk404, spriteWork->all[0], &packet, 1, 0);
        ManagedSprite_SetDrawFlag(spriteWork->all[0], 1);
        ov99_021E73E0(w, (u16)i, species);
    }
}
