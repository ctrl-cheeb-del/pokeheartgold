#include "sound.h"
#include "sound_02004A44.h"

int sub_02005328(int state);
int GF_NNS_SndPlayerGetSeqNo(NNSSndHandle *handle);
void Sound_ClearBGMPauseFlags(void);
void NNS_SndPlayerPause(NNSSndHandle *handle, BOOL pause);
void NNS_SndPlayerMoveVolume(NNSSndHandle *handle, int volume, int frames);
void NNS_SndPlayerSetInitialVolume(NNSSndHandle *handle, int volume);

int sub_02005328(int state) {
    int *level;
    GetSoundDataPointer();
    if (state >= 7) {
        GF_ASSERT(FALSE);
        return *(int *)GF_SdatGetAttrPtr(27);
    }
    // Valid state IDs are 0 through 6; preserve the original out-of-range behavior.
    switch (state) {
    case 0:
        level = GF_SdatGetAttrPtr(23);
        break;
    case 1:
        level = GF_SdatGetAttrPtr(24);
        break;
    case 2:
        level = GF_SdatGetAttrPtr(25);
        break;
    case 3:
        level = GF_SdatGetAttrPtr(26);
        break;
    case 4:
        level = GF_SdatGetAttrPtr(27);
        break;
    case 5:
        level = GF_SdatGetAttrPtr(28);
        break;
    case 6:
        level = GF_SdatGetAttrPtr(29);
        break;
    }
    return *level;
}

void sub_020053A8(u8 playerNo, u8 pause) {
    u8 *flag;
    enum SoundHandleNo handleNo;
    if (playerNo == 1) {
        flag = GF_SdatGetAttrPtr(12);
        handleNo = SND_HANDLE_FIELD;
    } else if (playerNo == 7) {
        flag = GF_SdatGetAttrPtr(13);
        handleNo = SND_HANDLE_BGM;
    } else {
        return;
    }
    if (pause == 0) {
        sub_02004A60((u16)GF_NNS_SndPlayerGetSeqNo(GF_GetSoundHandle(handleNo)));
    }
    NNS_SndPlayerPause(GF_GetSoundHandle(handleNo), pause);
    *flag = pause;
}

void Sound_ClearBGMPauseFlags(void) {
    u8 *primary = GF_SdatGetAttrPtr(12);
    u8 *secondary = GF_SdatGetAttrPtr(13);
    *primary = 0;
    *secondary = 0;
}

void GF_SndHandleMoveVolume(int handleNo, int volume, int frames) {
    NNS_SndPlayerMoveVolume(GF_GetSoundHandle(handleNo), volume, frames);
    if (handleNo == 0) {
        GF_SndWorkSetGbSoundsVolume((u8)volume);
    }
}

void GF_SndHandleSetInitialVolume(s32 handleNo, s32 volume) {
    if (volume < 0) {
        volume = 0;
    }
    if (volume > 127) {
        volume = 127;
    }
    NNS_SndPlayerSetInitialVolume(GF_GetSoundHandle(handleNo), volume);
}
