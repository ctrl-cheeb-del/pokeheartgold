#include "sound.h"
#include "sound_02004A44.h"

extern int _021D05E8[4];
extern s8 _021D0620[2000];
BOOL NNS_SndCaptureIsActive(void);
int NNS_SndCaptureGetCaptureType(void);
void NNS_SndCaptureStopReverb(int frames);
void NNS_SndPlayerSetTrackPitch(NNSSndHandle *handle, u32 tracks, int pitch);
void NNS_SndPlayerSetTrackPan(NNSSndHandle *handle, u32 tracks, int pan);
void NNS_SndPlayerSetTempoRatio(NNSSndHandle *handle, int ratio);
void NNS_SndSetMonoFlag(int flag);
void NNS_SndSetMasterVolume(int volume);
u8 GF_GetPlayerNoBySeq(u16 seqNo);
BOOL sub_020058F4(void);
int sub_02005908(void);
void sub_02005910(int frames);
void GF_SndHandleSetTrackPitch(int handleNo, u32 tracks, int pitch);
void sub_0200592C(u16 seqNo, u32 tracks, int pitch);
void sub_02005944(int playerNo, u32 tracks, int pitch);
void GF_SndHandleSetTrackPan(int handleNo, u32 tracks, int pan);
void GF_SndHandleSetTempoRatio(int handleNo, int ratio);
void sub_02005990(u32 frames);
void sub_020059A0(u32 frames);
void sub_020059E0(u16 state);

BOOL sub_020058F4(void) {
    BOOL active = NNS_SndCaptureIsActive();
    if (active == 1) {
        sub_02005908();
    }
    return active;
}
int sub_02005908(void) {
    return NNS_SndCaptureGetCaptureType();
}
void sub_02005910(int frames) {
    NNS_SndCaptureStopReverb(frames);
}
void GF_SndHandleSetTrackPitch(int handleNo, u32 tracks, int pitch) {
    NNS_SndPlayerSetTrackPitch(GF_GetSoundHandle(handleNo), tracks, pitch);
}
void sub_0200592C(u16 seqNo, u32 tracks, int pitch) {
    GF_SndHandleSetTrackPitch(GF_GetSndHandleByPlayerNo(GF_GetPlayerNoBySeq(seqNo)), tracks, pitch);
}
void sub_02005944(int playerNo, u32 tracks, int pitch) {
    GF_SndHandleSetTrackPitch(GF_GetSndHandleByPlayerNo(playerNo), tracks, pitch);
}
void GF_SndHandleSetTrackPan(int handleNo, u32 tracks, int pan) {
    NNS_SndPlayerSetTrackPan(GF_GetSoundHandle(handleNo), tracks, pan);
}
void GF_SndHandleSetTempoRatio(int handleNo, int ratio) {
    NNS_SndPlayerSetTempoRatio(GF_GetSoundHandle(handleNo), ratio);
}
void GF_SndSetMonoFlag(int flag) {
    NNS_SndSetMonoFlag(flag);
    _021D05E8[2] = flag;
}
void sub_02005990(u32 frames) {
    *(u32 *)GF_SdatGetAttrPtr(7) = frames;
}
void sub_020059A0(u32 frames) {
    *(u32 *)GF_SdatGetAttrPtr(8) = frames;
}
BOOL GF_SndGetAfterFadeDelayTimer(void) {
    u16 *timer = GF_SdatGetAttrPtr(8);
    if (*timer == 0) {
        *timer = 0;
        return 0;
    }
    --*timer;
    return *timer;
}
void Sound_SetMasterVolume(int volume) {
    NNS_SndSetMasterVolume(volume);
}
s8 *sub_020059D8(void) {
    return _021D0620;
}
void sub_020059E0(u16 state) {
    *(u8 *)GF_SdatGetAttrPtr(19) = state;
}
