#include "field_bgm.h"
#include "field_system.h"
#include "sav_chatot.h"
#include "scrcmd.h"
#include "sound.h"
#include "sound_system.h"
#include "sound_playback.h"

BOOL ScrNative_GetFadeTimer(ScriptContext *ctx);
BOOL ScrNative_SEPlaying(ScriptContext *ctx);
BOOL ScrNative_WaitCry(ScriptContext *ctx);
BOOL ScrNative_WaitFanfare(ScriptContext *ctx);

BOOL ScrCmd_CountPlayingSeq(ScriptContext *ctx) {
    u16 seqNo = ScriptReadHalfword(ctx);
    u16 *retPtr = ScriptGetVarPointer(ctx);
    *retPtr = GF_SndCountPlayingSeqBySeqNo(seqNo);
    return FALSE;
}

BOOL ScrCmd_PlayBGM(ScriptContext *ctx) {
    u16 seqno = ScriptReadHalfword(ctx);
    PlayBGM(seqno);
    return FALSE;
}

BOOL ScrCmd_StopBGM(ScriptContext *ctx) {
    u16 var0 = ScriptReadHalfword(ctx);
    u16 bgm = GF_GetCurrentPlayingBGM();
    StopBGM(bgm, 0);
    return FALSE;
}

BOOL ScrCmd_ResetBGM(ScriptContext *ctx) {
    u16 seqno = FieldBGM_GetForMapHeader(ctx->fieldSystem, ctx->fieldSystem->location->mapId);
    PlayBGM(seqno);
    return FALSE;
}

BOOL ScrCmd_SetBGMOverride(ScriptContext *ctx) {
    u16 seqno = ScriptReadHalfword(ctx);
    FieldBGM_SetOverride(ctx->fieldSystem, seqno);
    return FALSE;
}

BOOL ScrCmd_FadeOutBGM(ScriptContext *ctx) {
    u16 seqno = ScriptReadHalfword(ctx);
    u16 length = ScriptReadHalfword(ctx);
    GF_SndStartFadeOutBGM(seqno, length);
    SetupNativeScript(ctx, ScrNative_GetFadeTimer);
    return TRUE;
}

BOOL ScrNative_GetFadeTimer(ScriptContext *ctx) {
    if (!GF_SndGetFadeTimer()) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_FadeInBGM(ScriptContext *ctx) {
    u16 frames = ScriptReadHalfword(ctx);
    GF_SndStartFadeInBGM(0x7f, frames, 0);
    SetupNativeScript(ctx, ScrNative_GetFadeTimer);
    return TRUE;
}

BOOL ScrCmd_SetSoundPlayerPause(ScriptContext *ctx) {
    u8 playerNo = ScriptReadByte(ctx);
    u8 paused = ScriptReadByte(ctx);
    Sound_SetPlayerPause(playerNo, paused);
    return FALSE;
}

BOOL ScrCmd_TempBGM(ScriptContext *ctx) {
    u16 seqNo = ScriptReadHalfword(ctx);
    PlayBGMOnBGMPlayerInField(seqNo);
    return FALSE;
}

BOOL ScrCmd_SetBGMDisabled(ScriptContext *ctx) {
    u8 disabled = ScriptReadByte(ctx);
    GF_SND_BGM_DisableSet(disabled);
    return FALSE;
}

BOOL ScrCmd_PlaySE(ScriptContext *ctx) {
    u16 sndseq = ScriptGetVar(ctx);
    PlaySE(sndseq);
    return FALSE;
}

BOOL ScrCmd_StopSE(ScriptContext *ctx) {
    u16 sndseq = ScriptGetVar(ctx);
    StopSE(sndseq, 0);
    return FALSE;
}

BOOL ScrCmd_WaitSE(ScriptContext *ctx) {
    u16 sndseq = ScriptGetVar(ctx);
    ctx->data[0] = sndseq;
    SetupNativeScript(ctx, ScrNative_SEPlaying);
    return TRUE;
}

BOOL ScrNative_SEPlaying(ScriptContext *ctx) {
    if (!IsSEPlaying(ctx->data[0])) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_PlayCry(ScriptContext *ctx) {
    u16 species = ScriptGetVar(ctx);
    u16 pattern = ScriptGetVar(ctx);
    PlayCryEx(pattern, species, 0, 100, 0x20, 0);
    return FALSE;
}

BOOL ScrCmd_WaitCry(ScriptContext *ctx) {
    SetupNativeScript(ctx, ScrNative_WaitCry);
    return TRUE;
}

BOOL ScrNative_WaitCry(ScriptContext *ctx) {
    if (!IsCryPlaying()) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_PlayFanfare(ScriptContext *ctx) {
    u16 seqNo = ScriptGetVar(ctx);
    PlayFanfare(seqNo);
    return FALSE;
}

BOOL ScrCmd_WaitFanfare(ScriptContext *ctx) {
    SetupNativeScript(ctx, ScrNative_WaitFanfare);
    return TRUE;
}

BOOL ScrNative_WaitFanfare(ScriptContext *ctx) {
    if (!IsFanfarePlaying()) {
        return TRUE;
    } else {
        return FALSE;
    }
}

BOOL ScrCmd_ChatotHasCry(ScriptContext *ctx) {
    u16 *retPtr = ScriptGetVarPointer(ctx);
    SOUND_CHATOT *chatot = Save_Chatot_Get(ctx->fieldSystem->saveData);
    if (Chatot_CheckCry(chatot) == TRUE) {
        *retPtr = TRUE;
        return FALSE;
    } else {
        *retPtr = FALSE;
        return FALSE;
    }
}

BOOL ScrCmd_ChatotStartRecording(ScriptContext *ctx) {
    u16 *retPtr = ScriptGetVarPointer(ctx);
    GF_ASSERT(Sound_IsMicCounterFull());
    if (!Chatot_StartRecording()) {
        *retPtr = TRUE;
        return FALSE;
    } else {
        *retPtr = FALSE;
        return FALSE;
    }
}

BOOL ScrCmd_ChatotStopRecording(ScriptContext *ctx) {
    Chatot_StopRecording();
    return TRUE;
}

BOOL ScrCmd_ChatotSaveRecording(ScriptContext *ctx) {
    SOUND_CHATOT *chatot = Save_Chatot_Get(ctx->fieldSystem->saveData);
    Chatot_SaveRecording(chatot);
    return TRUE;
}

BOOL ScrCmd_SetSoundScene63(ScriptContext *ctx) {
    Sound_SetSceneAndPlayBGM(0x3f, 0, 0);
    return TRUE;
}

BOOL ScrCmd_SetSeqVolume(ScriptContext *ctx) {
    u16 seqNo = ScriptGetVar(ctx);
    u16 volume = ScriptGetVar(ctx);
    GF_SetVolumeBySeqNo(seqNo, volume);
    return FALSE;
}

BOOL ScrCmd_Dummy664(ScriptContext *ctx) {
    return TRUE;
}

BOOL ScrCmd_FieldBGMPlay(ScriptContext *ctx) {
    u16 seqNo = ScriptGetVar(ctx);
    FieldBGM_Play(ctx->fieldSystem, seqNo);
    return TRUE;
}

BOOL ScrCmd_GetCurrentBGM(ScriptContext *ctx) {
    u16 *retPtr = ScriptGetVarPointer(ctx);
    *retPtr = GF_GetCurrentPlayingBGM();
    return FALSE;
}
