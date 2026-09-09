#include "sound.h"
#include "sound_02004A44.h"

u16 GBSounds_GetDSSeqNoByGBSeqNo(u16 seqNo);
void sub_02005318(void);

void GF_SND_BGM_DisableSet(u8 disabled) {
    u8 *value = GF_SdatGetAttrPtr(5);
    *value = disabled;
}

BOOL GF_SND_BGM_DisableCheck(void) {
    u8 *value = GF_SdatGetAttrPtr(5);
    return *value;
}

void sub_02004A60(u16 seqNo) {
    u16 *currentSeqNo = GF_SdatGetAttrPtr(10);
    if (seqNo > SEQ_GS_P_START) {
        sub_02004AB8(seqNo);
        *currentSeqNo = GBSounds_GetDSSeqNoByGBSeqNo(seqNo);
    } else {
        *currentSeqNo = seqNo;
    }
    GF_SetCurrentPlayingBGM(0);
}

u16 GF_GetCurrentPlayingBGM(void) {
    u16 *seqNo = GF_SdatGetAttrPtr(10);
    return *seqNo;
}

void GF_SetCurrentPlayingBGM(u16 seqNo) {
    u16 *queuedSeqNo = GF_SdatGetAttrPtr(11);
    *queuedSeqNo = seqNo;
}

u16 sub_02004AAC(void) {
    u16 *queuedSeqNo = GF_SdatGetAttrPtr(11);
    return *queuedSeqNo;
}

void sub_02004AB8(u16 seqNo) {
    u16 *value = GF_SdatGetAttrPtr(58);
    *value = seqNo;
}

void Sound_SetFieldBGM(u16 seqNo) {
    u16 *fieldSeqNo = GF_SdatGetAttrPtr(32);
    *fieldSeqNo = seqNo;
}

void Sound_SetScene(int scene) {
    u8 *primaryScene = GF_SdatGetAttrPtr(21);
    u8 *secondaryScene = GF_SdatGetAttrPtr(22);
    if ((u32)scene < 51) {
        *primaryScene = scene;
        *secondaryScene = 0;
    } else {
        *secondaryScene = scene;
    }
}

void sub_02004AFC(u8 scene) {
    GF_SdatGetAttrPtr(21);
    u8 *secondaryScene = GF_SdatGetAttrPtr(22);
    *secondaryScene = scene;
}

void sub_02004B10(void) {
    u8 *secondaryScene = GF_SdatGetAttrPtr(22);
    sub_02005318();
    *secondaryScene = 0;
}
