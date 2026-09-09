#include "sound.h"
#include "sound_02004A44.h"

u8 GF_GetPlayerNoBySeq(u16 seqNo);
u16 GBSounds_GetGBSeqNoByDSSeqNo(u16 seqNo);
void GBSounds_SetAllocatableChannels(void);
BOOL NNS_SndArcPlayerStartSeqEx(NNSSndHandle *handle, int playerNo, int bankNo, int playerPrio, int seqNo);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds) {
    u16 playingSeqNo = seqNo;
    if (useGBSounds == 1 && SoundSys_GetGBSoundsState() == 1) {
        u16 gbSeqNo = GBSounds_GetGBSeqNoByDSSeqNo(seqNo);
        if (seqNo != gbSeqNo) {
            playingSeqNo = gbSeqNo;
            bankNo = 701;
            sub_02004AB8(gbSeqNo);
            int seqPlayerNo = GF_GetPlayerNoBySeq(gbSeqNo);
            if (playerNo != -1) {
                seqPlayerNo = (u8)playerNo;
            }
            if (seqPlayerNo == 7) {
                GF_Snd_LoadSeqEx(gbSeqNo, 1);
            }
        }
    }
    BOOL success = NNS_SndArcPlayerStartSeqEx(GF_GetSoundHandle(handleNo), playerNo, bankNo, playerPrio, playingSeqNo);
    GBSounds_SetAllocatableChannels();
    return success;
}
