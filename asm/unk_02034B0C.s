	.include "asm/macros.inc"
	.include "unk_02034B0C.inc"
	.include "global.inc"

	.bss

	.public _021D4134
_021D4134:
	.space 0xC

	.rodata

	.public _020F6A88
_020F6A88:
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF

	.text

	thumb_func_start sub_02034B0C
sub_02034B0C: ; 0x02034B0C
	push {r3, r4, r5, r6, r7, lr}
	add r4, r0, #0
	ldr r0, _02034BCC ; =_021D4134
	add r7, r1, #0
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02034BCA
	ldr r1, _02034BD0 ; =0x00000D98
	mov r0, #0xf
	bl Heap_Alloc
	ldr r1, _02034BCC ; =_021D4134
	ldr r2, _02034BD0 ; =0x00000D98
	str r0, [r1, #8]
	mov r1, #0
	bl MI_CpuFill8
	bl sub_020335B4
	add r1, r0, #0
	mov r0, #0xf
	bl Heap_Alloc
	ldr r1, _02034BCC ; =_021D4134
	ldr r2, [r1, #8]
	ldr r1, _02034BD4 ; =0x00000D64
	str r0, [r2, r1]
	bl sub_020335B4
	add r2, r0, #0
	ldr r0, _02034BCC ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _02034BD4 ; =0x00000D64
	ldr r0, [r1, r0]
	mov r1, #0
	bl MI_CpuFill8
	bl LinkBattleRuleset_sizeof
	add r1, r0, #0
	mov r0, #0xf
	bl Heap_Alloc
	ldr r1, _02034BCC ; =_021D4134
	ldr r2, [r1, #8]
	ldr r1, _02034BD8 ; =0x00000D7C
	str r0, [r2, r1]
	bl LinkBattleRuleset_sizeof
	add r2, r0, #0
	ldr r0, _02034BCC ; =_021D4134
	ldr r1, [r0, #8]
	ldr r0, _02034BD8 ; =0x00000D7C
	ldr r0, [r1, r0]
	mov r1, #0
	bl MI_CpuFill8
	mov r0, #0xf
	mov r1, #0x90
	bl Heap_Alloc
	ldr r2, _02034BCC ; =_021D4134
	ldr r1, _02034BDC ; =0x00000D84
	ldr r3, [r2, #8]
	str r0, [r3, r1]
	ldr r6, [r2, #8]
	mov r0, #0x1f
	ldr r5, [r6, r1]
	add r3, r5, #0
	and r3, r0
	mov r0, #0x20
	sub r0, r0, r3
	add r3, r0, r5
	add r0, r1, #4
	str r3, [r6, r0]
	ldr r5, _02034BE0 ; =0x00000333
	ldr r3, [r2, #8]
	sub r0, r1, #4
	str r5, [r3, r0]
	add r0, r1, #0
	ldr r3, [r2, #8]
	sub r0, #0xc
	str r4, [r3, r0]
	ldr r0, [r2, #8]
	sub r1, #0x1c
	add r0, r0, r1
	bl MailMsg_Init
	add r0, r7, #0
	bl sub_02034DF0
	bl WM_GetNextTgid
	ldr r1, _02034BCC ; =_021D4134
	strh r0, [r1]
_02034BCA:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02034BCC: .word _021D4134
_02034BD0: .word 0x00000D98
_02034BD4: .word 0x00000D64
_02034BD8: .word 0x00000D7C
_02034BDC: .word 0x00000D84
_02034BE0: .word 0x00000333
	thumb_func_end sub_02034B0C
