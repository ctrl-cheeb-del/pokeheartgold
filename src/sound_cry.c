#include "constants/species.h"

#include "sound.h"
#include "sound_02004A44.h"

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
