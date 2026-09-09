#include "heap.h"
#include "sound.h"
#include "sound_02004A44.h"

typedef struct WaveArcInfo {
    u32 fileId : 24;
    u32 flags : 8;
} WaveArcInfo;
const WaveArcInfo *NNS_SndArcGetWaveArcInfo(int waveArcNo);
u32 NNS_SndArcGetFileSize(u32 fileId);
s32 NNS_SndArcReadFile(u32 fileId, void *buffer, u32 size, s32 offset);
BOOL sub_020057AC(int waveArcNo, int volume, int pan, int channel, int heapId);
void sub_02005898(void *buffer, u32 size);

BOOL sub_02005600(int channel);
NNSSndWaveOutHandle NNS_SndWaveOutAllocChannel(int channel);
void NNS_SndWaveOutFreeChannel(NNSSndWaveOutHandle handle);
BOOL NNS_SndWaveOutStart(NNSSndWaveOutHandle handle, NNSSndWaveFormat format, const void *data, u32 loop, u32 loopStart, u32 length, u32 sampleRate, s32 volume, u32 speed, s32 pan);
void NNS_SndWaveOutStop(NNSSndWaveOutHandle handle);
BOOL NNS_SndWaveOutIsPlaying(NNSSndWaveOutHandle handle);
void NNS_SndWaveOutSetPan(NNSSndWaveOutHandle handle, u32 pan);
void NNS_SndWaveOutSetSpeed(NNSSndWaveOutHandle handle, u32 speed);
void NNS_SndWaveOutSetVolume(NNSSndWaveOutHandle handle, int volume);
void sub_02005728(int channel);
void sub_02005748(int channel, u32 pan);
void sub_02005760(int channel, u32 speed);
BOOL sub_020378CC(void);

NNSSndWaveOutHandle *sub_020055AC(int channel) {
    GetSoundDataPointer();
    u8 *first = GF_SdatGetAttrPtr(16);
    u8 *second = GF_SdatGetAttrPtr(17);
    GF_ASSERT(channel == 14 || channel == 15);
    if (channel == 14 && *first == 0) {
        GF_ASSERT(FALSE);
    }
    if (channel == 15 && *second == 0) {
        GF_ASSERT(FALSE);
    }
    if (channel == 14) {
        return GF_SdatGetAttrPtr(0);
    }
    return GF_SdatGetAttrPtr(1);
}
BOOL sub_02005600(int channel) {
    GetSoundDataPointer();
    u8 *first = GF_SdatGetAttrPtr(16);
    u8 *second = GF_SdatGetAttrPtr(17);
    GF_ASSERT(channel == 14 || channel == 15);
    if (channel == 14) {
        if (*first == 0) {
            NNSSndWaveOutHandle *handle = GF_SdatGetAttrPtr(0);
            *handle = NNS_SndWaveOutAllocChannel(channel);
            if (*handle == NULL) {
                return FALSE;
            }
            *first = 1;
        } else {
            GF_ASSERT(FALSE);
        }
    } else {
        if (*second == 0) {
            NNSSndWaveOutHandle *handle = GF_SdatGetAttrPtr(1);
            *handle = NNS_SndWaveOutAllocChannel(channel);
            if (*handle == NULL) {
                return FALSE;
            }
            *second = 1;
        } else {
            GF_ASSERT(FALSE);
        }
    }
    return TRUE;
}
void sub_02005680(int channel) {
    GetSoundDataPointer();
    u8 *first = GF_SdatGetAttrPtr(16);
    u8 *second = GF_SdatGetAttrPtr(17);
    if (channel != 14 && channel != 15) {
        GF_ASSERT(FALSE);
        return;
    }
    if (channel == 14) {
        if (*first == 1) {
            NNS_SndWaveOutFreeChannel(*sub_020055AC(channel));
            *first = 0;
        } else {
            GF_ASSERT(FALSE);
        }
    } else {
        if (*second == 1) {
            NNS_SndWaveOutFreeChannel(*sub_020055AC(channel));
            *second = 0;
        } else {
            GF_ASSERT(FALSE);
        }
    }
}
BOOL sub_020056E8(UnkStruct_02004A44_0 *param, int channel) {
    BOOL success = NNS_SndWaveOutStart(*param->unk00, param->unk04, param->unk08, param->unk0c, param->unk10, param->unk14, param->unk18, param->unk1c, param->unk20, param->unk24);
    if (!success) {
        sub_02005680(channel);
    }
    return success;
}
void sub_02005728(int channel) {
    NNS_SndWaveOutStop(*sub_020055AC(channel));
}
BOOL sub_02005738(int channel) {
    return NNS_SndWaveOutIsPlaying(*sub_020055AC(channel));
}
void sub_02005748(int channel, u32 pan) {
    if (pan > 127) {
        pan = 127;
    }
    NNS_SndWaveOutSetPan(*sub_020055AC(channel), pan);
}
void sub_02005760(int channel, u32 speed) {
    NNS_SndWaveOutSetSpeed(*sub_020055AC(channel), speed);
}
void sub_02005774(int channel, int volume) {
    if (sub_020378CC() == 1) {
        NNS_SndWaveOutSetVolume(*sub_020055AC(channel), volume / 5);
    } else {
        NNS_SndWaveOutSetVolume(*sub_020055AC(channel), volume);
    }
}

BOOL sub_020057AC(int waveArcNo, int volume, int pan, int channel, int heapId) {
    GetSoundDataPointer();
    void **buffer = GF_SdatGetAttrPtr(34);
    const WaveArcInfo *info;
    u32 size;
    UnkStruct_02004A44_0 param;
    BOOL success;
    GF_ASSERT(channel == 14 || channel == 15);
    info = NNS_SndArcGetWaveArcInfo(waveArcNo);
    if (info == NULL) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    size = NNS_SndArcGetFileSize(info->fileId);
    if (size == 0) {
        GF_ASSERT(FALSE);
        return FALSE;
    }
    if (channel == 14) {
        *buffer = Heap_Alloc((enum HeapID)heapId, size);
        if (*buffer == NULL) {
            GF_ASSERT(FALSE);
            return FALSE;
        }
        memset(*buffer, 0, size);
        if (NNS_SndArcReadFile(info->fileId, *buffer, size, 0) == -1) {
            GF_ASSERT(FALSE);
            return FALSE;
        }
        sub_02005898(*buffer, size);
    }
    param.unk00 = sub_020055AC(channel);
    param.unk04 = NNS_SND_WAVE_FORMAT_PCM8;
    param.unk08 = *buffer;
    param.unk0c = 0;
    param.unk10 = 0;
    param.unk14 = size;
    param.unk18 = 13379;
    param.unk1c = volume;
    param.unk20 = 24576;
    param.unk24 = pan;
    success = sub_020056E8(&param, channel);
    sub_02005774(channel, volume);
    *(u8 *)GF_SdatGetAttrPtr(15) = 1;
    return success;
}
void sub_02005898(void *buffer, u32 size) {
    u8 *data = buffer;
    u32 i;
    for (i = 0; i < size / 2; i++) {
        u8 temp = data[i];
        data[i] = data[size - 1 - i];
        data[size - 1 - i] = temp;
    }
}
void sub_020058B8(int channel) {
    GetSoundDataPointer();
    u8 *allocated = GF_SdatGetAttrPtr(15);
    void **buffer = GF_SdatGetAttrPtr(34);
    GF_ASSERT(channel == 14 || channel == 15);
    sub_02005728(channel);
    if (*allocated == 1) {
        *allocated = 0;
        Heap_Free(*buffer);
    }
}
