	.include "asm/macros.inc"
	.include "unk_02016EDC.inc"
	.include "global.inc"

	.rodata

	.public _020F61BC
_020F61BC:
	.word sub_02017D20
	.public _020F61C0
_020F61C0:
	.word 0x00000006
	.public _020F61C4
_020F61C4:
	.word 0x00000001
	.word sub_02017DD8, 0x00000006, 0x00000001
	.word sub_02017E98, 0x00000004, 0x00000000
	.word sub_02017ED4, 0x00000003, 0x00000000
	.word sub_02017F10, 0x00000004, 0x00000000
	.public _020F61F8
_020F61F8:
	.word sub_020174A4
	.word sub_020174B4
	.word sub_020174BC
	.word sub_020175EC
	.word sub_020176CC
	.word sub_02017504
	.word sub_0201752C
	.word sub_02017550
	.word sub_02017578
	.word sub_0201759C
	.word sub_020175C4
	.word sub_020176F0
	.word sub_02017714
	.word sub_02017730
	.word sub_0201775C
	.word sub_02017788
	.word sub_02017808
	.word sub_0201783C
	.word sub_02017874
	.word sub_020178BC
	.word sub_0201790C
	.word sub_020179D4
	.word sub_02017A1C
	.word sub_02017A84
	.word sub_02017B48
	.word sub_02017B54
	.word sub_02017B8C
	.word sub_02017B98
	.word sub_02017BA4
	.word sub_02017BB0
	.word sub_02017BBC
	.word sub_02017AD8
	.word sub_02017AEC
	.word sub_02017B2C

	.text

	thumb_func_start sub_02016F40
sub_02016F40: ; 0x02016F40
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	str r3, [sp, #4]
	add r0, r2, #0
	ldrh r6, [r0]
	ldrh r0, [r0, #2]
	add r7, r1, #0
	ldrb r1, [r5, #9]
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	str r2, [sp]
	cmp r0, r1
	blo _02016F60
	bl GF_AssertFail
_02016F60:
	ldr r0, [sp, #4]
	mov r1, #0x1d
	add r4, r0, #0
	lsl r1, r1, #4
	ldr r0, [r5]
	mul r4, r1
	add r0, r0, r4
	ldr r0, [r0, #0x10]
	cmp r0, #0
	beq _02016F78
	bl GF_AssertFail
_02016F78:
	ldr r0, [r5]
	mov r2, #0x1d
	add r0, r0, r4
	mov r1, #0
	lsl r2, r2, #4
	bl MI_CpuFill8
	ldr r0, [r5]
	mov r1, #1
	add r0, r0, r4
	str r1, [r0, #0x10]
	ldr r0, [r5]
	cmp r6, #0x8f
	str r7, [r0, r4]
	blt _02016F9A
	mov r6, #0
	str r6, [sp, #8]
_02016F9A:
	ldr r0, [r5]
	add r0, r0, r4
	str r6, [r0, #0x14]
	ldrb r0, [r5, #8]
	cmp r0, #0
	beq _02016FAC
	ldr r0, [sp]
	ldrb r2, [r0, #4]
	b _02016FAE
_02016FAC:
	mov r2, #0
_02016FAE:
	ldr r0, [r5]
	add r1, r0, r4
	mov r0, #0x73
	lsl r0, r0, #2
	strb r2, [r1, r0]
	ldr r1, [r5]
	ldr r2, [r5, #4]
	add r1, r1, r4
	ldr r1, [r1, #0x14]
	mov r0, #0x5a
	bl AllocAtEndAndReadWholeNarcMemberByIdPair
	ldr r1, [r5]
	mov r2, #0
	add r1, r1, r4
	str r0, [r1, #8]
	ldr r0, [r5]
	mov r6, #0x1c
	add r1, r0, r4
	ldr r0, [r1, #8]
	str r0, [r1, #0xc]
	ldr r0, [r5]
	add r0, r0, r4
	str r2, [r0, #0x1c]
	ldr r0, [r5]
	add r0, r0, r4
	str r2, [r0, #0x20]
	ldr r0, [r5]
	add r1, r0, r4
	ldr r0, _02017060 ; =0x000001CD
	strb r2, [r1, r0]
	ldr r1, [r5]
	add r3, r1, r4
	add r1, r0, #1
	strb r6, [r3, r1]
	ldr r1, [r5]
	add r0, r0, #2
	add r1, r1, r4
	strb r2, [r1, r0]
	ldr r1, [r5]
	ldr r0, _02017064 ; =sub_020170C4
	add r1, r1, r4
	bl SysTask_CreateOnMainQueue
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #4]
	ldr r0, [r5]
	add r1, r0, r4
	ldr r0, [sp, #8]
	str r0, [r1, #0x54]
	add r0, r7, #0
	mov r1, #0
	bl Pokepic_GetAttr
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x58]
	add r0, r7, #0
	mov r1, #1
	bl Pokepic_GetAttr
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x5c]
	ldr r1, [r5]
	mov r0, #0
	add r1, r1, r4
	str r0, [r1, #0x60]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x64]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x68]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x6c]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x70]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x74]
	ldr r1, [r5]
	add r1, r1, r4
	str r0, [r1, #0x78]
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02017060: .word 0x000001CD
_02017064: .word sub_020170C4
	thumb_func_end sub_02016F40
