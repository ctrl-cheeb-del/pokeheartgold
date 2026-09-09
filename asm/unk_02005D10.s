	.include "asm/macros.inc"
	.include "unk_02005D10.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_02006AC0
sub_02006AC0: ; 0x02006AC0
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #0x12
	add r4, r1, #0
	add r6, r2, #0
	bl GF_SdatGetAttrPtr
	mov r1, #1
	strb r1, [r0]
	add r0, r1, #0
	bl sub_02006E3C
	add r0, r5, #0
	add r1, r6, #0
	bl PlayCry
	add r5, r0, #0
	ldr r1, _02006AF0 ; =0x0000FFFF
	mov r0, #8
	add r2, r4, #0
	bl GF_SndHandleSetTrackPitch
	add r0, r5, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02006AF0: .word 0x0000FFFF
	thumb_func_end sub_02006AC0

	thumb_func_start sub_02006AF4
sub_02006AF4: ; 0x02006AF4
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	mov r0, #0x12
	add r4, r2, #0
	add r6, r3, #0
	bl GF_SdatGetAttrPtr
	mov r1, #1
	strb r1, [r0]
	mov r0, #0xf
	bl sub_02005600
	ldr r0, [sp, #0x18]
	add r1, r4, #0
	str r0, [sp]
	add r0, r5, #0
	add r2, r6, #0
	mov r3, #0xf
	bl sub_020057AC
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02006AF4

	thumb_func_start PlayFanfare
PlayFanfare: ; 0x02006B24
	push {r3, r4, r5, lr}
	sub sp, #8
	add r4, r0, #0
	bl GF_GetBankInfoBySeqNo
	add r0, r4, #0
	bl sub_02006C04
	bl GF_GetCurrentPlayingBGM
	bl GF_GetPlayerNoBySeq
	cmp r0, #0xff
	beq _02006B48
	mov r1, #1
	bl sub_020053A8
	b _02006B4E
_02006B48:
	mov r0, #1
	bl SndRadio_PausePlayer
_02006B4E:
	mov r0, #0x1d
	bl GF_SdatGetAttrPtr
	bl GF_Snd_SaveState
	add r0, r4, #0
	mov r1, #3
	bl GF_Snd_LoadSeqEx
	str r4, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r0, #2
	sub r1, r0, #3
	add r2, r1, #0
	add r3, r1, #0
	bl sub_02006C14
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #2
	bl sub_02005464
	add r0, r5, #0
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end PlayFanfare

	thumb_func_start sub_02006B84
sub_02006B84: ; 0x02006B84
	push {r4, lr}
	mov r0, #0xe
	bl GF_SdatGetAttrPtr
	add r4, r0, #0
	mov r0, #2
	bl GF_SndPlayerCountPlayingSeqByPlayerNo
	cmp r0, #0
	beq _02006B9C
	mov r0, #1
	pop {r4, pc}
_02006B9C:
	ldrh r0, [r4]
	cmp r0, #0
	beq _02006BAA
	sub r0, r0, #1
	strh r0, [r4]
	mov r0, #1
	pop {r4, pc}
_02006BAA:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02006B84

	thumb_func_start sub_02006BB0
sub_02006BB0: ; 0x02006BB0
	push {r4, lr}
	add r4, r0, #0
	mov r0, #2
	bl GF_GetSoundHandle
	add r1, r4, #0
	bl NNS_SndPlayerStopSeq
	mov r0, #6
	bl sub_02005328
	bl GF_Snd_LoadState
	pop {r4, pc}
	thumb_func_end sub_02006BB0

	thumb_func_start IsFanfarePlaying
IsFanfarePlaying: ; 0x02006BCC
	push {r3, lr}
	mov r0, #0xe
	bl GF_SdatGetAttrPtr
	bl sub_02006B84
	cmp r0, #1
	bne _02006BE0
	mov r0, #1
	pop {r3, pc}
_02006BE0:
	mov r0, #0
	bl sub_02006BB0
	bl GF_GetCurrentPlayingBGM
	bl GF_GetPlayerNoBySeq
	cmp r0, #0xff
	beq _02006BF8
	mov r1, #0
	bl sub_020053A8
_02006BF8:
	mov r0, #0
	bl SndRadio_PausePlayer
	mov r0, #0
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end IsFanfarePlaying

	thumb_func_start sub_02006C04
sub_02006C04: ; 0x02006C04
	push {r3, lr}
	mov r0, #0xe
	bl GF_SdatGetAttrPtr
	mov r1, #0xf
	strh r1, [r0]
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_02006C04

	thumb_func_start sub_02006C14
sub_02006C14: ; 0x02006C14
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp, #4]
	add r0, sp, #0x10
	ldrh r6, [r0, #0x10]
	ldrb r0, [r0, #0x14]
	add r5, r1, #0
	add r7, r2, #0
	str r3, [sp, #8]
	cmp r0, #1
	bne _02006C6A
	bl SoundSys_GetGBSoundsState
	cmp r0, #1
	bne _02006C6A
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	bl GBSounds_GetGBSeqNoByDSSeqNo
	add r1, sp, #0x10
	ldrh r1, [r1, #0x10]
	add r4, r0, #0
	cmp r1, r4
	beq _02006C6A
	add r6, r4, #0
	ldr r7, _02006C88 ; =0x000002BD
	bl sub_02004AB8
	add r0, r4, #0
	bl GF_GetPlayerNoBySeq
	mov r1, #0
	mvn r1, r1
	cmp r5, r1
	beq _02006C5E
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
_02006C5E:
	cmp r0, #7
	bne _02006C6A
	add r0, r4, #0
	mov r1, #1
	bl GF_Snd_LoadSeqEx
_02006C6A:
	ldr r0, [sp, #4]
	bl GF_GetSoundHandle
	ldr r3, [sp, #8]
	add r1, r5, #0
	add r2, r7, #0
	str r6, [sp]
	bl NNS_SndArcPlayerStartSeqEx
	add r4, r0, #0
	bl GBSounds_SetAllocatableChannels
	add r0, r4, #0
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02006C88: .word 0x000002BD
	thumb_func_end sub_02006C14
