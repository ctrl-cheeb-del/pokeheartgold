#include "constants/species.h"

#include "heap.h"
#include "sound.h"
#include "sound_02004A44.h"
#include "sys_task_api.h"

typedef struct CryStopTaskData {
    int frames;
    SysTask *task;
} CryStopTaskData;

// Cry-bank numbering extends beyond the ordinary species IDs.
#define CRY_BANK_SHAYMIN_SKY 494
#define CRY_BANK_MAX         495

BOOL sub_02006A0C(u16 species, u8 form);
void sub_02006300(int fadeFrames);
void sub_02005464(int seqNo, enum SoundHandleNo handleNo);
BOOL sub_02006C14(enum SoundHandleNo handleNo, int playerNo, int bankNo, int playerPrio, u16 seqNo, u8 useGBSounds);

BOOL sub_020062E0(u16 species, u8 delay, u8 form);
BOOL IsCryFinished(void);
void NNS_SndPlayerStopSeq(NNSSndHandle *handle, int fadeFrames);
void sub_020058B8(int handleNo);
void sub_02005680(int handleNo);
BOOL sub_02005738(int handleNo);
void sub_02006DB8(void);
void sub_02006A30(void);

void GF_SndHandleSetTrackPan(int handleNo, u32 trackMask, int pan);
void GF_SndHandleSetTrackPitch(int handleNo, u32 trackMask, int pitch);
void sub_02006820(int species, int handleNo, int volume);
void sub_02005748(int handleNo, u8 pan);
void sub_02005774(int handleNo, int volume);
void sub_02006838(int frames, int heapId);
BOOL sub_02006AC0(u16 species, int pitch, u8 form);
void sub_02005600(int handleNo);
void sub_020057AC(u16 species, int volume, int pan, int handleNo, int heapId);
void sub_02005760(int handleNo, int speed);
void sub_02006AF4(u16 species, int pitch, int volume, int pan, int heapId);

void sub_02006884(SysTask *task, void *data);
void sub_020068F8(void);

BOOL PlayCry(u16 species, u8 form) {
    u8 *useChorus = GF_SdatGetAttrPtr(18);
    SOUND_CHATOT **chatot = GF_SdatGetAttrPtr(36);
    u8 *keepPlaying = GF_SdatGetAttrPtr(53);
    BOOL success;
    if (sub_02006A0C(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != CRY_BANK_SHAYMIN_SKY && (species > CRY_BANK_MAX || species == 0)) {
        species = SPECIES_BULBASAUR;
    }
    if (species == SPECIES_CHATOT && sub_02006D04(*chatot, 0, 127, 0) == 1) {
        sub_02006E3C(0);
        return TRUE;
    }
    if (*useChorus == 0) {
        if (*keepPlaying == 0) {
            sub_02006300(0);
        }
        success = sub_02006C14(SND_HANDLE_PV, -1, species, -1, 2, 0);
        sub_02005464(species, SND_HANDLE_PV);
    } else {
        success = sub_02006C14(SND_HANDLE_CHORUS, -1, species, -1, 2, 0);
        sub_02005464(species, SND_HANDLE_CHORUS);
    }
    sub_02006E3C(0);
    return success;
}

BOOL sub_020062E0(u16 species, u8 delay, u8 form) {
    sub_02006920(0, species, 0, 127, 11, delay, form);
    return TRUE;
}

void sub_02006300(int fadeFrames) {
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    GF_SdatGetAttrPtr(15);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_PV), fadeFrames);
    NNS_SndPlayerStopSeq(GF_GetSoundHandle(SND_HANDLE_CHORUS), fadeFrames);
    if (*firstActive == 1) {
        sub_020058B8(14);
        sub_02005680(14);
    }
    if (*secondActive == 1) {
        sub_020058B8(15);
        sub_02005680(15);
    }
    sub_02006DB8();
    sub_02006A30();
}

BOOL IsCryFinished(void) {
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    GF_SdatGetAttrPtr(15);
    GF_SdatGetAttrPtr(46);
    if (*firstActive == 1) {
        return sub_02005738(14);
    }
    if (*secondActive == 1) {
        return sub_02005738(15);
    }
    return GF_SndPlayerCountPlayingSeqByPlayerNo(0);
}

BOOL PlayCryEx(u32 pattern, u16 species, int pan, int volume, int heapId, u8 form) {
    int wavePan;
    int chorusVolume;
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    u8 *useChorus = GF_SdatGetAttrPtr(18);
    u8 *chatotMode = GF_SdatGetAttrPtr(30);
    GF_SdatGetAttrPtr(36);
    if (sub_02006A0C(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != CRY_BANK_SHAYMIN_SKY && (species > CRY_BANK_MAX || species == 0)) {
        species = SPECIES_BULBASAUR;
    }
    wavePan = pan / 2 + 64;
    chorusVolume = volume - 30;
    if (chorusVolume <= 0) {
        chorusVolume = 1;
    }
    *useChorus = 0;
    if (*firstActive == 1) {
        sub_020058B8(14);
        sub_02005680(14);
    }
    if (*secondActive == 1) {
        sub_020058B8(15);
        sub_02005680(15);
    }
    if (species == SPECIES_CHATOT) {
        switch (pattern) {
        case 0:
        case 1:
        case 2:
        case 5:
        case 11:
        case 12:
            PlayCry(SPECIES_CHATOT, form);
            if (*chatotMode == 0) {
                GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
                sub_02006820(species, 1, volume);
            } else if (*firstActive == 1) {
                sub_02005748(14, wavePan);
                sub_02005774(14, volume);
            } else {
                GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
                sub_02006820(species, 1, volume);
            }
            return TRUE;
        default:
            sub_02006E3C(1);
            break;
        }
    }
    switch (pattern) {
    case 0:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        break;
    case 1:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(20, heapId);
        break;
    case 2:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, 64);
        sub_02006AC0(species, 20, form);
        GF_SndHandleSetTrackPan(8, 0xFFFF, pan);
        sub_02006820(species, 8, chorusVolume);
        break;
    case 3:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(30, heapId);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, 192);
        sub_02006AC0(species, 16, form);
        GF_SndHandleSetTrackPan(8, 0xFFFF, pan);
        sub_02006820(species, 8, chorusVolume);
        break;
    case 4:
        sub_02005600(14);
        sub_020057AC(species, volume, wavePan, 14, heapId);
        sub_02005748(14, wavePan);
        sub_02006838(15, heapId);
        sub_02005760(14, 34304);
        sub_02006AF4(species, -64, chorusVolume, wavePan, heapId);
        sub_02005760(15, 34304);
        break;
    case 5:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, -224);
        break;
    case 6:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, 44);
        sub_02006AC0(species, -64, form);
        GF_SndHandleSetTrackPan(8, 0xFFFF, pan);
        sub_02006820(species, 8, chorusVolume);
        break;
    case 7:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(11, heapId);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, -128);
        break;
    case 8:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(60, heapId);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, 60);
        break;
    case 9:
        sub_02005600(14);
        sub_020057AC(species, volume, wavePan, 14, heapId);
        sub_02005748(14, wavePan);
        sub_02006838(13, heapId);
        sub_02005760(14, 26624);
        break;
    case 10:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(100, heapId);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, -44);
        break;
    case 11:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, -96);
        break;
    case 12:
        PlayCry(species, form);
        GF_SndHandleSetTrackPan(1, 0xFFFF, pan);
        sub_02006820(species, 1, volume);
        sub_02006838(20, heapId);
        GF_SndHandleSetTrackPitch(1, 0xFFFF, -96);
        break;
    case 13:
        PlayCry(species, form);
        sub_02006820(species, 1, 127);
        sub_02006AC0(species, 20, form);
        GF_SndHandleSetTrackPan(8, 0xFFFF, pan);
        GF_SndHandleMoveVolume(8, volume, 0);
        break;
    case 14:
        PlayCry(species, form);
        break;
    }
    return TRUE;
}

void sub_02006820(int species, int handleNo, int volume) {
    GF_SndHandleSetInitialVolume(handleNo, volume);
    sub_02005464(species, (enum SoundHandleNo)handleNo);
}

void sub_02006838(int frames, int heapId) {
    SysTask **task = GF_SdatGetAttrPtr(35);
    sub_020068F8();
    CryStopTaskData *data = Heap_Alloc((enum HeapID)heapId, sizeof(CryStopTaskData));
    if (data == NULL) {
        GF_ASSERT(FALSE);
        return;
    }
    memset(data, 0, sizeof(CryStopTaskData));
    data->frames = frames;
    data->task = SysTask_CreateOnMainQueue(sub_02006884, data, 0);
    *task = data->task;
}

void sub_02006884(SysTask *task, void *arg) {
    CryStopTaskData *data = arg;
    u8 *firstActive = GF_SdatGetAttrPtr(16);
    u8 *secondActive = GF_SdatGetAttrPtr(17);
    if (data->frames == 10) {
        GF_SndHandleMoveVolume(SND_HANDLE_PV, 0, data->frames);
        GF_SndHandleMoveVolume(SND_HANDLE_CHORUS, 0, data->frames);
    }
    data->frames--;
    if (IsCryFinished() == 0) {
        data->frames = 0;
    }
    if (data->frames <= 0) {
        sub_02006300(0);
        if (*firstActive == 1) {
            sub_020058B8(14);
            sub_02005680(14);
        }
        if (*secondActive == 1) {
            sub_020058B8(15);
            sub_02005680(15);
        }
        sub_020068F8();
    }
}

void sub_020068F8(void) {
    SysTask **task = GF_SdatGetAttrPtr(35);
    if (*task != NULL) {
        void *data = SysTask_GetData(*task);
        SysTask_Destroy(*task);
        Heap_Free(data);
    }
    *task = NULL;
}

void sub_02006920(int pattern, u16 species, int pan, int volume, int heapId, u8 delay, u8 form) {
    int *queuedPattern;
    u16 *queuedSpecies;
    int *queuedPan;
    int *queuedVolume;
    int *queuedHeapId;
    u8 *queuedDelay;
    u8 *queueNo = GF_SdatGetAttrPtr(6);
    u8 *alternateQueue = GF_SdatGetAttrPtr(53);
    if (*queueNo == 0) {
        queuedPattern = GF_SdatGetAttrPtr(41);
        queuedSpecies = GF_SdatGetAttrPtr(45);
        queuedPan = GF_SdatGetAttrPtr(42);
        queuedVolume = GF_SdatGetAttrPtr(43);
        queuedHeapId = GF_SdatGetAttrPtr(44);
        queuedDelay = GF_SdatGetAttrPtr(46);
    } else {
        queuedPattern = GF_SdatGetAttrPtr(47);
        queuedSpecies = GF_SdatGetAttrPtr(51);
        queuedPan = GF_SdatGetAttrPtr(48);
        queuedVolume = GF_SdatGetAttrPtr(49);
        queuedHeapId = GF_SdatGetAttrPtr(50);
        queuedDelay = GF_SdatGetAttrPtr(52);
    }
    if (*alternateQueue == 1) {
        *queueNo ^= 1;
    }
    if (sub_02006A0C(species, form) == 1) {
        species = CRY_BANK_SHAYMIN_SKY;
    }
    if (species != 0) {
        if (delay == 0) {
            PlayCryEx(pattern, species, pan, volume, heapId, form);
            return;
        }
        *queuedPattern = pattern;
        *queuedSpecies = species;
        *queuedPan = pan;
        *queuedVolume = volume;
        *queuedHeapId = heapId;
        *queuedDelay = delay;
    }
}

BOOL sub_02006A0C(u16 species, u8 form) {
    if (species == SPECIES_SHAYMIN && form == 1) {
        return TRUE;
    }
    if (species == CRY_BANK_SHAYMIN_SKY) {
        return TRUE;
    }
    return FALSE;
}

void sub_02006A30(void) {
    int *pattern0 = GF_SdatGetAttrPtr(41);
    u16 *species0 = GF_SdatGetAttrPtr(45);
    int *pan0 = GF_SdatGetAttrPtr(42);
    int *volume0 = GF_SdatGetAttrPtr(43);
    int *heap0 = GF_SdatGetAttrPtr(44);
    u8 *delay0 = GF_SdatGetAttrPtr(46);
    int *pattern1 = GF_SdatGetAttrPtr(47);
    u16 *species1 = GF_SdatGetAttrPtr(51);
    int *pan1 = GF_SdatGetAttrPtr(48);
    int *volume1 = GF_SdatGetAttrPtr(49);
    int *heap1 = GF_SdatGetAttrPtr(50);
    u8 *delay1 = GF_SdatGetAttrPtr(52);
    *pattern0 = 0;
    *species0 = 0;
    *pan0 = 0;
    *volume0 = 0;
    *heap0 = 0;
    *delay0 = 0;
    *pattern1 = 0;
    *species1 = 0;
    *pan1 = 0;
    *volume1 = 0;
    *heap1 = 0;
    *delay1 = 0;
}

BOOL sub_02006AC0(u16 species, int pitch, u8 form) {
    u8 *useChorus = GF_SdatGetAttrPtr(18);
    *useChorus = 1;
    sub_02006E3C(1);
    BOOL success = PlayCry(species, form);
    GF_SndHandleSetTrackPitch(SND_HANDLE_CHORUS, 0xFFFF, pitch);
    return success;
}

void sub_02006AF4(u16 species, int unused, int volume, int pan, int heapId) {
    u8 *useChorus = GF_SdatGetAttrPtr(18);
    *useChorus = 1;
    sub_02005600(15);
    sub_020057AC(species, volume, pan, 15, heapId);
}
