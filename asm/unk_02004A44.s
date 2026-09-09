#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "unk_02004A44.inc"
	.include "global.inc"

	.rodata

_020F5710:
	.byte 0x00, 0x2A, 0x00, 0x00
	.byte 0x40, 0x6B, 0x00, 0x00
	.byte 0x20, 0x2F, 0x00, 0x00
	.byte 0x40, 0x77, 0x00, 0x00
	.byte 0x00, 0x3E, 0x00, 0x00
	.byte 0x30, 0x7F, 0x00, 0x00
	.byte 0x00, 0x34, 0x00, 0x00
	.byte 0x30, 0x75, 0x00, 0x00
_020F5730:
	.short SEQ_GS_TITLE, SEQ_GS_P_TITLE
	.short SEQ_GS_TITLE01, SEQ_GS_P_TITLE01
	.short SEQ_GS_OPENING_TITLE_G, SEQ_GS_P_OPENING_TITLE_G
	.short SEQ_GS_OPENING_TITLE_S, SEQ_GS_P_OPENING_TITLE_S
	.short SEQ_GS_POKEMON_THEME, SEQ_GS_P_POKEMON_THEME
	.short SEQ_GS_SHINKA, SEQ_GS_P_SHINKA
	.short SEQ_GS_KOUKAN, SEQ_GS_P_KOUKAN
	.short SEQ_GS_BICYCLE, SEQ_GS_P_BICYCLE
	.short SEQ_GS_NAMINORI, SEQ_GS_P_NAMINORI
	.short SEQ_GS_E_DENDOUIRI, SEQ_GS_P_E_DENDOUIRI
	.short SEQ_GS_T_WAKABA, SEQ_GS_P_T_WAKABA
	.short SEQ_GS_C_YOSHINO, SEQ_GS_P_C_YOSHINO
	.short SEQ_GS_C_KIKYOU, SEQ_GS_P_C_KIKYOU
	.short SEQ_GS_T_HIWADA, SEQ_GS_P_T_HIWADA
	.short SEQ_GS_C_KOGANE, SEQ_GS_P_C_KOGANE
	.short SEQ_GS_C_ENJU, SEQ_GS_P_C_ENJU
	.short SEQ_GS_C_ASAGI, SEQ_GS_P_C_ASAGI
	.short SEQ_GS_C_TANBA, SEQ_GS_P_C_TANBA
	.short SEQ_GS_T_CHOUJI, SEQ_GS_P_T_CHOUJI
	.short SEQ_GS_C_FUSUBE, SEQ_GS_P_C_FUSUBE
	.short SEQ_GS_R_1_29, SEQ_GS_P_R_1_29
	.short SEQ_GS_R_1_30, SEQ_GS_P_R_1_30
	.short SEQ_GS_R_2_30, SEQ_GS_P_R_2_30
	.short SEQ_GS_R_3_30, SEQ_GS_P_R_3_30
	.short SEQ_GS_R_4_34, SEQ_GS_P_R_4_34
	.short SEQ_GS_R_5_34, SEQ_GS_P_R_5_34
	.short SEQ_GS_R_6_34, SEQ_GS_P_R_6_34
	.short SEQ_GS_R_8_34, SEQ_GS_P_R_8_34
	.short SEQ_GS_R_6_38, SEQ_GS_P_R_6_38
	.short SEQ_GS_R_7_42, SEQ_GS_P_R_7_42
	.short SEQ_GS_C_KUCHIBA, SEQ_GS_P_C_KUCHIBA
	.short SEQ_GS_C_YAMABUKI, SEQ_GS_P_C_YAMABUKI
	.short SEQ_GS_C_HANADA, SEQ_GS_P_C_HANADA
	.short SEQ_GS_T_CHION, SEQ_GS_P_T_CHION
	.short SEQ_GS_C_TAMAMUSHI, SEQ_GS_P_C_TAMAMUSHI
	.short SEQ_GS_C_SEKICHIKU, SEQ_GS_P_C_SEKICHIKU
	.short SEQ_GS_C_NIBI, SEQ_GS_P_C_NIBI
	.short SEQ_GS_C_TOKIWA, SEQ_GS_P_C_TOKIWA
	.short SEQ_GS_T_MASARA, SEQ_GS_P_T_MASARA
	.short SEQ_GS_T_GUREN, SEQ_GS_P_T_GUREN
	.short SEQ_GS_R_9_01, SEQ_GS_P_R_9_01
	.short SEQ_GS_R_16_01, SEQ_GS_P_R_16_01
	.short SEQ_GS_R_17_01, SEQ_GS_P_R_17_01
	.short SEQ_GS_R_9_03, SEQ_GS_P_R_9_03
	.short SEQ_GS_R_10_03, SEQ_GS_P_R_10_03
	.short SEQ_GS_R_12_03, SEQ_GS_P_R_12_03
	.short SEQ_GS_R_13_03, SEQ_GS_P_R_13_03
	.short SEQ_GS_R_14_03, SEQ_GS_P_R_14_03
	.short SEQ_GS_R_15_03, SEQ_GS_P_R_15_03
	.short SEQ_GS_R_16_03, SEQ_GS_P_R_16_03
	.short SEQ_GS_R_17_03, SEQ_GS_P_R_17_03
	.short SEQ_GS_R_10_11, SEQ_GS_P_R_10_11
	.short SEQ_GS_R_13_11, SEQ_GS_P_R_13_11
	.short SEQ_GS_R_12_24, SEQ_GS_P_R_12_24
	.short SEQ_GS_R_1_26, SEQ_GS_P_R_1_26
	.short SEQ_GS_POKESEN, SEQ_GS_P_POKESEN
	.short SEQ_GS_FS, SEQ_GS_P_FS
	.short SEQ_GS_GYM, SEQ_GS_P_GYM
	.short SEQ_GS_UTSUGI_RABO, SEQ_GS_P_UTSUGI_RABO
	.short SEQ_GS_OHKIDO, SEQ_GS_P_OHKIDO
	.short SEQ_GS_KABURENJOU, SEQ_GS_P_KABURENJOU
	.short SEQ_GS_GAME, SEQ_GS_P_GAME
	.short SEQ_GS_BATTLETOWER, SEQ_GS_P_BATTLETOWER
	.short SEQ_GS_BATTLETOWER2, SEQ_GS_P_BATTLETOWER2
	.short SEQ_GS_TO_MADATSUBOMI1, SEQ_GS_P_TO_MADATSUBOMI1
	.short SEQ_GS_D_CHIKATSUURO, SEQ_GS_P_D_CHIKATSUURO
	.short SEQ_GS_D_UNKNOWN_ISEKI, SEQ_GS_P_D_UNKNOWN_ISEKI
	.short SEQ_GS_D_KOUEN, SEQ_GS_P_D_KOUEN
	.short SEQ_GS_TO_YAKETA, SEQ_GS_P_TO_YAKETA
	.short SEQ_GS_TO_SUZU, SEQ_GS_P_TO_SUZU
	.short SEQ_GS_TO_TOUDAI, SEQ_GS_P_TO_TOUDAI
	.short SEQ_GS_D_AJITO, SEQ_GS_P_D_AJITO
	.short SEQ_GS_D_KOORINONUKE, SEQ_GS_P_D_KOORINONUKE
	.short SEQ_GS_RYUUNOANA, SEQ_GS_P_RYUUNOANA
	.short SEQ_GS_D_IWAYAMA, SEQ_GS_P_D_IWAYAMA
	.short SEQ_GS_D_TOKIWANOMORI3, SEQ_GS_P_D_TOKIWANOMORI3
	.short SEQ_GS_D_CHAMPROAD, SEQ_GS_P_D_CHAMPROAD
	.short SEQ_GS_CHAMPROAD, SEQ_GS_P_CHAMPROAD
	.short SEQ_GS_E_TSURETEKE1, SEQ_GS_P_E_TSURETEKE1
	.short SEQ_GS_E_TSURETEKE2, SEQ_GS_P_E_TSURETEKE2
	.short SEQ_GS_E_RIVAL1, SEQ_GS_P_E_RIVAL1
	.short SEQ_GS_E_RIVAL2, SEQ_GS_P_E_RIVAL2
	.short SEQ_GS_TAIKAIMAE, SEQ_GS_P_TAIKAIMAE
	.short SEQ_GS_TAIKAI, SEQ_GS_P_TAIKAI
	.short SEQ_GS_KAIDENPA, SEQ_GS_P_KAIDENPA
	.short SEQ_GS_SENKYO, SEQ_GS_P_SENKYO
	.short SEQ_GS_E_LINEAR, SEQ_GS_P_E_LINEAR
	.short SEQ_GS_KOUSOKUSEN, SEQ_GS_P_KOUSOKUSEN
	.short SEQ_GS_OTSUKIMI_EVENT, SEQ_GS_P_OTSUKIMI_EVENT
	.short SEQ_GS_RADIO_JINGLE, SEQ_GS_P_RADIO_JINGLE
	.short SEQ_GS_RADIO_KOMORIUTA, SEQ_GS_P_RADIO_KOMORIUTA
	.short SEQ_GS_RADIO_MARCH, SEQ_GS_P_RADIO_MARCH
	.short SEQ_GS_RADIO_UNKNOWN, SEQ_GS_P_RADIO_UNKNOWN
	.short SEQ_GS_HUE, SEQ_GS_P_HUE
	.short SEQ_GS_OHKIDO_RABO, SEQ_GS_P_OHKIDO_RABO
	.short SEQ_GS_AIKOTOBA, SEQ_GS_P_AIKOTOBA
	.short SEQ_GS_E_MINAKI, SEQ_GS_P_E_MINAKI
	.short SEQ_GS_IBUKI, SEQ_GS_P_IBUKI
	.short SEQ_GS_EYE_J_SHOUJO, SEQ_GS_P_EYE_J_SHOUJO
	.short SEQ_GS_EYE_J_SHOUNEN, SEQ_GS_P_EYE_J_SHOUNEN
	.short SEQ_GS_EYE_J_AYASHII, SEQ_GS_P_EYE_J_AYASHII
	.short SEQ_GS_EYE_BOUZU, SEQ_GS_P_EYE_BOUZU
	.short SEQ_GS_EYE_MAIKO, SEQ_GS_P_EYE_MAIKO
	.short SEQ_GS_EYE_ROCKET, SEQ_GS_P_EYE_ROCKET
	.short SEQ_GS_EYE_K_SHOUJO, SEQ_GS_P_EYE_K_SHOUJO
	.short SEQ_GS_EYE_K_SHOUNEN, SEQ_GS_P_EYE_K_SHOUNEN
	.short SEQ_GS_EYE_K_AYASHII, SEQ_GS_P_EYE_K_AYASHII
	.short SEQ_GS_VS_NORAPOKE, SEQ_GS_P_VS_NORAPOKE
	.short SEQ_GS_VS_TRAINER, SEQ_GS_P_VS_TRAINER
	.short SEQ_GS_VS_GYMREADER, SEQ_GS_P_VS_GYMREADER
	.short SEQ_GS_VS_RIVAL, SEQ_GS_P_VS_RIVAL
	.short SEQ_GS_VS_ROCKET, SEQ_GS_P_VS_ROCKET
	.short SEQ_GS_VS_SUICUNE, SEQ_GS_P_VS_SUICUNE
	.short SEQ_GS_VS_ENTEI, SEQ_GS_P_VS_ENTEI
	.short SEQ_GS_VS_RAIKOU, SEQ_GS_P_VS_RAIKOU
	.short SEQ_GS_VS_CHAMP, SEQ_GS_P_VS_CHAMP
	.short SEQ_GS_VS_NORAPOKE_KANTO, SEQ_GS_P_VS_NORAPOKE_KANTO
	.short SEQ_GS_VS_TRAINER_KANTO, SEQ_GS_P_VS_TRAINER_KANTO
	.short SEQ_GS_VS_GYMREADER_KANTO, SEQ_GS_P_VS_GYMREADER_KANTO
	.short SEQ_GS_WIN1, SEQ_GS_P_WIN1
	.short SEQ_GS_WIN2, SEQ_GS_P_WIN2
	.short SEQ_GS_WIN2_NOT_FAN, SEQ_GS_P_WIN2_NOT_FAN
	.short SEQ_GS_WIN3, SEQ_GS_P_WIN3
	.short SEQ_GS_PT_ENTR, SEQ_GS_P_PT_ENTR
	.short SEQ_GS_PT_OPEN, SEQ_GS_P_PT_OPEN
	.short SEQ_GS_PT_TITLE, SEQ_GS_P_PT_TITLE
	.short SEQ_GS_PT_GAME, SEQ_GS_P_PT_GAME
	.short SEQ_GS_PT_GAMEF, SEQ_GS_P_PT_GAMEF
	.short SEQ_GS_PT_RESULT, SEQ_GS_P_PT_RESULT
	.short SEQ_GS_PT_END, SEQ_GS_P_PT_END
	.short SEQ_GS_PT_END_FIELD, SEQ_GS_P_PT_END_FIELD
	.short SEQ_GS_WIFITOWER, SEQ_GS_P_WIFITOWER
	.short SEQ_GS_SAFARI_ROAD, SEQ_GS_P_SAFARI_ROAD
	.short SEQ_GS_SAFARI_HOUSE, SEQ_GS_P_SAFARI_HOUSE
	.short SEQ_GS_SAFARI_FIELD, SEQ_GS_P_SAFARI_FIELD
	.short SEQ_PL_BICYCLE, SEQ_PL_P_BICYCLE

	.bss

	.public _021D05E8
_021D05E8:
	.space 0x10

	.public _021D05F8
_021D05F8:
	.space 0x28

	.public _021D0620
_021D0620:
	.space 0x7D0

	.text

	thumb_func_start GF_NowStartMusicId
GF_NowStartMusicId: ; 0x020059F0
	push {r4, r5, r6, lr}
	sub sp, #8
	add r6, r0, #0
	add r5, r1, #0
	add r4, r2, #0
	str r3, [sp]
	ldr r0, [sp, #0x18]
	add r1, r6, #0
	str r0, [sp, #4]
	mov r0, #4
	add r2, r5, #0
	add r3, r4, #0
	bl sub_02005A10
	add sp, #8
	pop {r4, r5, r6, pc}
	thumb_func_end GF_NowStartMusicId

	thumb_func_start sub_02005A10
sub_02005A10: ; 0x02005A10
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #0x16
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #8]
	bl GF_SdatGetAttrPtr
	add r4, r0, #0
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	ldr r3, [sp, #8]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [sp, #0x24]
	add r2, r7, #0
	str r0, [sp, #4]
	add r0, r5, #0
	bl sub_02005AB0
	mov r0, #0
	strb r0, [r4]
	mov r0, #5
	bl GF_SndSetState
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02005A10

	thumb_func_start GF_FadeStartMusicId
GF_FadeStartMusicId: ; 0x02005A4C
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r6, r0, #0
	str r3, [sp]
	add r0, sp, #0x10
	ldrb r0, [r0, #0x10]
	add r5, r1, #0
	add r4, r2, #0
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	add r1, r6, #0
	str r0, [sp, #8]
	mov r0, #4
	add r2, r5, #0
	add r3, r4, #0
	bl sub_02005A74
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end GF_FadeStartMusicId

	thumb_func_start sub_02005A74
sub_02005A74: ; 0x02005A74
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	mov r0, #9
	add r6, r1, #0
	add r7, r2, #0
	str r3, [sp, #8]
	bl GF_SdatGetAttrPtr
	add r4, r0, #0
	add r0, sp, #0x10
	ldrb r0, [r0, #0x14]
	ldr r3, [sp, #8]
	add r1, r6, #0
	str r0, [sp]
	ldr r0, [sp, #0x28]
	add r2, r7, #0
	str r0, [sp, #4]
	add r0, r5, #0
	bl sub_02005AB0
	ldr r0, [sp, #0x20]
	str r0, [r4]
	mov r0, #6
	bl GF_SndSetState
	mov r0, #1
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02005A74

	thumb_func_start sub_02005AB0
sub_02005AB0: ; 0x02005AB0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r2, #0
	mov r0, #2
	add r5, r1, #0
	add r7, r3, #0
	bl GF_SdatGetAttrPtr
	add r4, r0, #0
	mov r0, #0
	add r1, r6, #0
	bl GF_SndStartFadeOutBGM
	mov r0, #0
	bl sub_02004A60
	add r0, r5, #0
	bl GF_SetCurrentPlayingBGM
	add r0, r7, #0
	bl sub_020059A0
	add r0, r5, #0
	bl GF_GetBankInfoBySeqNo
	str r0, [r4]
	add r0, sp, #8
	ldrb r0, [r0, #0x10]
	bl sub_020059E0
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02005AB0

	thumb_func_start GF_SndSetAllocatableChannelForBGMPlayer
GF_SndSetAllocatableChannelForBGMPlayer: ; 0x02005AEC
	ldr r3, _02005AF4 ; =NNS_SndPlayerSetAllocatableChannel
	add r1, r0, #0
	mov r0, #7
	bx r3
	.balign 4, 0
_02005AF4: .word NNS_SndPlayerSetAllocatableChannel
	thumb_func_end GF_SndSetAllocatableChannelForBGMPlayer

	thumb_func_start sub_02005AF8
sub_02005AF8: ; 0x02005AF8
	push {r3, lr}
	cmp r0, #0
	bne _02005B0C
	ldr r0, _02005B18 ; =0x0000A7FE
	bl GF_SndSetAllocatableChannelForBGMPlayer
	mov r0, #0
	bl sub_02005910
	b _02005B12
_02005B0C:
	ldr r0, _02005B1C ; =0x00003FFF
	bl GF_SndSetAllocatableChannelForBGMPlayer
_02005B12:
	bl sub_020058F4
	pop {r3, pc}
	.balign 4, 0
_02005B18: .word 0x0000A7FE
_02005B1C: .word 0x00003FFF
	thumb_func_end sub_02005AF8

	thumb_func_start sub_02005B20
sub_02005B20: ; 0x02005B20
	push {r3, lr}
	bl GF_SndGetFadeTimer
	cmp r0, #0
	bne _02005B4A
	mov r0, #0
	bl GF_GetSoundHandle
	bl GF_NNS_SndPlayerGetSeqNo
	mov r1, #0
	mvn r1, r1
	cmp r0, r1
	beq _02005B4A
	bl sub_02005FD8
	mov r0, #1
	add r1, r0, #0
	bl sub_020053A8
	pop {r3, pc}
_02005B4A:
	bl Sound_Stop
	pop {r3, pc}
	thumb_func_end sub_02005B20

	thumb_func_start GF_SndHandleSetPlayerVolume
GF_SndHandleSetPlayerVolume: ; 0x02005B50
	ldr r3, _02005B54 ; =NNS_SndPlayerSetPlayerVolume
	bx r3
	.balign 4, 0
_02005B54: .word NNS_SndPlayerSetPlayerVolume
	thumb_func_end GF_SndHandleSetPlayerVolume

	thumb_func_start sub_02005B58
sub_02005B58: ; 0x02005B58
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x35
	bl GF_SdatGetAttrPtr
	strb r4, [r0]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02005B58

	thumb_func_start sub_02005B68
sub_02005B68: ; 0x02005B68
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x36
	bl GF_SdatGetAttrPtr
	strb r4, [r0]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02005B68

	thumb_func_start sub_02005B78
sub_02005B78: ; 0x02005B78
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r1, #0
	add r6, r2, #0
	bne _02005B86
	bl GF_AssertFail
_02005B86:
	cmp r4, #0xf
	bls _02005B8E
	bl GF_AssertFail
_02005B8E:
	add r0, r5, #0
	bl GF_GetPlayerNoBySeq
	bl GF_GetSndHandleByPlayerNo
	bl GF_GetSoundHandle
	add r1, r4, #0
	add r2, r6, #0
	bl NNS_SndPlayerReadVariable
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02005B78

	thumb_func_start sub_02005BA8
sub_02005BA8: ; 0x02005BA8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x37
	bl GF_SdatGetAttrPtr
	add r4, r0, #0
	ldrb r1, [r4]
	add r0, r5, #0
	lsl r2, r1, #2
	ldr r1, _02005BE0 ; =_020F5710 + 1
	ldrb r1, [r1, r2]
	bl GF_SetVolumeBySeqNo
	ldrb r2, [r4]
	ldr r1, _02005BE4 ; =0x0000FFFF
	mov r0, #4
	lsl r3, r2, #2
	ldr r2, _02005BE8 ; =_020F5710
	ldrb r2, [r2, r3]
	bl GF_SndHandleSetTrackPitch
	ldrb r0, [r4, #1]
	cmp r0, #8
	blo _02005BDC
	mov r0, #0
	strb r0, [r4, #1]
_02005BDC:
	pop {r3, r4, r5, pc}
	nop
_02005BE0: .word _020F5710 + 1
_02005BE4: .word 0x0000FFFF
_02005BE8: .word _020F5710
	thumb_func_end sub_02005BA8

	thumb_func_start sub_02005BEC
sub_02005BEC: ; 0x02005BEC
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x38
	bl GF_SdatGetAttrPtr
	strb r4, [r0]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02005BEC

	thumb_func_start sub_02005BFC
sub_02005BFC: ; 0x02005BFC
	push {r3, lr}
	mov r0, #0x38
	bl GF_SdatGetAttrPtr
	ldrb r0, [r0]
	pop {r3, pc}
	thumb_func_end sub_02005BFC

	thumb_func_start sub_02005C08
sub_02005C08: ; 0x02005C08
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x39
	bl GF_SdatGetAttrPtr
	strb r4, [r0]
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02005C08

	thumb_func_start SoundSys_GetGBSoundsState
SoundSys_GetGBSoundsState: ; 0x02005C18
	push {r3, lr}
	mov r0, #0x39
	bl GF_SdatGetAttrPtr
	ldrb r0, [r0]
	pop {r3, pc}
	thumb_func_end SoundSys_GetGBSoundsState

	thumb_func_start SoundSys_ToggleGBSounds
SoundSys_ToggleGBSounds: ; 0x02005C24
	push {r3, r4, r5, lr}
	bl SoundSys_GetGBSoundsState
	cmp r0, #0
	bne _02005C36
	mov r0, #1
	bl sub_02005C08
	b _02005C3C
_02005C36:
	mov r0, #0
	bl sub_02005C08
_02005C3C:
	bl sub_02004AAC
	cmp r0, #0
	bne _02005C6A
	bl GF_GetCurrentPlayingBGM
	add r4, r0, #0
	bl GF_SndWorkGetGbSoundsVolume
	add r5, r0, #0
	add r0, r4, #0
	bl GBSounds_GetGBSeqNoByDSSeqNo
	cmp r4, r0
	beq _02005C60
	add r0, r4, #0
	bl PlayBGM
_02005C60:
	mov r0, #0
	add r1, r5, #0
	add r2, r0, #0
	bl GF_SndHandleMoveVolume
_02005C6A:
	pop {r3, r4, r5, pc}
	thumb_func_end SoundSys_ToggleGBSounds

	thumb_func_start GBSounds_GetGBSeqNoByDSSeqNo
GBSounds_GetGBSeqNoByDSSeqNo: ; 0x02005C6C
	push {r3, r4}
	ldr r2, _02005C90 ; =_020F5730
	mov r4, #0
_02005C72:
	lsl r3, r4, #2
	ldrh r1, [r2, r3]
	cmp r0, r1
	bne _02005C82
	ldr r0, _02005C94 ; =_020F5730 + 2
	ldrh r0, [r0, r3]
	pop {r3, r4}
	bx lr
_02005C82:
	add r1, r4, #1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r4, #0x88
	blo _02005C72
	pop {r3, r4}
	bx lr
	.balign 4, 0
_02005C90: .word _020F5730
_02005C94: .word _020F5730 + 2
	thumb_func_end GBSounds_GetGBSeqNoByDSSeqNo

	thumb_func_start GBSounds_GetDSSeqNoByGBSeqNo
GBSounds_GetDSSeqNoByGBSeqNo: ; 0x02005C98
	push {r3, r4}
	ldr r2, _02005CBC ; =_020F5730
	mov r4, #0
_02005C9E:
	lsl r3, r4, #2
	add r1, r2, r3
	ldrh r1, [r1, #2]
	cmp r0, r1
	bne _02005CAE
	ldrh r0, [r2, r3]
	pop {r3, r4}
	bx lr
_02005CAE:
	add r1, r4, #1
	lsl r1, r1, #0x10
	lsr r4, r1, #0x10
	cmp r4, #0x88
	blo _02005C9E
	pop {r3, r4}
	bx lr
	.balign 4, 0
_02005CBC: .word _020F5730
	thumb_func_end GBSounds_GetDSSeqNoByGBSeqNo

	thumb_func_start GBSounds_SetAllocatableChannels
GBSounds_SetAllocatableChannels: ; 0x02005CC0
	push {r3, lr}
	mov r0, #0 ; HANDLE_FIELD
	bl GF_GetSoundHandle
	ldr r2, _02005CF0 ; =0x0000A7FE
	mov r1, #0xf
	bl NNS_SndPlayerSetTrackAllocatableChannel
	mov r0, #7 ; HANDLE_BGM
	bl GF_GetSoundHandle
	ldr r2, _02005CF0 ; =0x0000A7FE
	mov r1, #0xf
	bl NNS_SndPlayerSetTrackAllocatableChannel
	mov r0, #2 ; HANDLE_ME
	bl GF_GetSoundHandle
	ldr r2, _02005CF0 ; =0x0000A7FE
	mov r1, #0xf
	bl NNS_SndPlayerSetTrackAllocatableChannel
	pop {r3, pc}
	nop
_02005CF0: .word 0x0000A7FE
	thumb_func_end GBSounds_SetAllocatableChannels

	thumb_func_start sub_02005CF4
sub_02005CF4: ; 0x02005CF4
	ldr r1, _02005CFC ; =_021D05E8
	str r0, [r1, #0xc]
	bx lr
	nop
_02005CFC: .word _021D05E8
	thumb_func_end sub_02005CF4

	thumb_func_start sub_02005D00
sub_02005D00: ; 0x02005D00
	ldr r0, _02005D0C ; =_021D05E8
	mov r1, #0
	str r1, [r0, #0xc]
	str r1, [r0, #4]
	bx lr
	nop
_02005D0C: .word _021D05E8
	thumb_func_end sub_02005D00
