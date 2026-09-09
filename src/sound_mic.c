#include "sound.h"
#include "sound_02004A44.h"

extern int _021D05E8[4];
extern MICAutoParam _021D05F8;
MICResult MIC_StartAutoSampling(const MICAutoParam *param);
MICResult MIC_StopAutoSampling(void);

BOOL GF_MIC_StartAutoSampling(MICAutoParam *param) {
    MICResult result = MIC_StartAutoSampling(param);
    ((u8 *)_021D05E8)[0] = 1;
    _021D05F8 = *param;
    return result;
}
void GF_MIC_StopAutoSampling(void) {
    GetSoundDataPointer();
    ((u8 *)_021D05E8)[0] = 0;
    MIC_StopAutoSampling();
}
void GF_MicPauseOnLidClose(void) {
    if (((u8 *)_021D05E8)[0] != 0) {
        if (MIC_StopAutoSampling() != MIC_RESULT_SUCCESS) {
            GF_ASSERT(FALSE);
        }
    }
}
void GF_MicResumeOnLidOpen(void) {
    if (((u8 *)_021D05E8)[0] != 0) {
        if (MIC_StartAutoSampling(&_021D05F8) != MIC_RESULT_SUCCESS) {
            GF_ASSERT(FALSE);
        }
    }
    GF_SndWorkMicCounterReset();
}
