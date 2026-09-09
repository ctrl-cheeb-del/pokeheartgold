#include "sound.h"
#include "sound_02004A44.h"

extern int _021D05E8[4];
extern const u8 _020F5710[8][4];
extern const u16 _020F5730[136][2];
BOOL NNS_SndPlayerReadVariable(NNSSndHandle *handle, u32 variable, s16 *value);
void NNS_SndPlayerSetTrackAllocatableChannel(NNSSndHandle *handle, u32 tracks, u32 channels);
u8 GF_GetPlayerNoBySeq(u16 seqNo);
void GF_SndHandleSetTrackPitch(int handleNo, u32 tracks, int pitch);
void sub_02005B58(u8 value);
void sub_02005B68(u8 value);
BOOL sub_02005B78(u16 seqNo, u32 variable, s16 *value);
void sub_02005BA8(u16 seqNo);
int sub_02005BFC(void);
void sub_02005C08(u8 enabled);
u16 GBSounds_GetGBSeqNoByDSSeqNo(u16 seqNo);
u16 GBSounds_GetDSSeqNoByGBSeqNo(u16 seqNo);
void GBSounds_SetAllocatableChannels(void);
void sub_02005CF4(BOOL enabled);

void sub_02005B58(u8 value) {
    *(u8 *)GF_SdatGetAttrPtr(53) = value;
}
void sub_02005B68(u8 value) {
    *(u8 *)GF_SdatGetAttrPtr(54) = value;
}
BOOL sub_02005B78(u16 seqNo, u32 variable, s16 *value) {
    GF_ASSERT(value != NULL);
    GF_ASSERT(variable <= 15);
    return NNS_SndPlayerReadVariable(GF_GetSoundHandle(GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo))), variable, value);
}
void sub_02005BA8(u16 seqNo) {
    u8 *state = GF_SdatGetAttrPtr(55);
    GF_SetVolumeBySeqNo(seqNo, _020F5710[state[0]][1]);
    GF_SndHandleSetTrackPitch(4, 65535, _020F5710[state[0]][0]);
    if (state[1] >= 8) {
        state[1] = 0;
    }
}
void sub_02005BEC(BOOL enabled) {
    *(u8 *)GF_SdatGetAttrPtr(56) = enabled;
}
int sub_02005BFC(void) {
    return *(u8 *)GF_SdatGetAttrPtr(56);
}
void sub_02005C08(u8 enabled) {
    *(u8 *)GF_SdatGetAttrPtr(57) = enabled;
}
BOOL SoundSys_GetGBSoundsState(void) {
    return *(u8 *)GF_SdatGetAttrPtr(57);
}
void SoundSys_ToggleGBSounds(void) {
    if (SoundSys_GetGBSoundsState() == 0) {
        sub_02005C08(1);
    } else {
        sub_02005C08(0);
    }
    if (sub_02004AAC() == 0) {
        u16 seqNo = GF_GetCurrentPlayingBGM();
        u8 volume = GF_SndWorkGetGbSoundsVolume();
        if (seqNo != GBSounds_GetGBSeqNoByDSSeqNo(seqNo)) {
            PlayBGM(seqNo);
        }
        GF_SndHandleMoveVolume(0, volume, 0);
    }
}
u16 GBSounds_GetGBSeqNoByDSSeqNo(u16 seqNo) {
    u16 i;
    for (i = 0; i < 136; i++) {
        if (seqNo == _020F5730[i][0]) {
            return _020F5730[i][1];
        }
    }
    return seqNo;
}
u16 GBSounds_GetDSSeqNoByGBSeqNo(u16 seqNo) {
    u16 i;
    for (i = 0; i < 136; i++) {
        if (seqNo == _020F5730[i][1]) {
            return _020F5730[i][0];
        }
    }
    return seqNo;
}
void GBSounds_SetAllocatableChannels(void) {
    NNS_SndPlayerSetTrackAllocatableChannel(GF_GetSoundHandle(0), 15, 0xA7FE);
    NNS_SndPlayerSetTrackAllocatableChannel(GF_GetSoundHandle(7), 15, 0xA7FE);
    NNS_SndPlayerSetTrackAllocatableChannel(GF_GetSoundHandle(2), 15, 0xA7FE);
}
void sub_02005CF4(BOOL enabled) {
    _021D05E8[3] = enabled;
}
void sub_02005D00(void) {
    _021D05E8[3] = 0;
    _021D05E8[1] = 0;
}
