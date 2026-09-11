#include "global.h"

void NNS_SndPlayerSetPlayerVolume(int playerNo, u8 volume);
void GF_SndHandleSetPlayerVolume(u32 playerNo, u8 volume);

void GF_SndHandleSetPlayerVolume(u32 playerNo, u8 volume) {
    NNS_SndPlayerSetPlayerVolume(playerNo, volume);
}
