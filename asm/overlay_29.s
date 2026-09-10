	.include "asm/macros.inc"
	.public ov29_0225D520
	.public ov29_0225D5EC
	.public ov29_0225D61C
	.public ov29_0225D620
	.public ov29_0225D648
	.public ov29_0225D6B4
	.public ov29_0225D6C8
	.public ov29_0225D714
	.public ov29_0225D7D4
	.public ov29_0225D7F0
	.public ov29_0225D828
	.public ov29_0225D840
	.public ov29_0225D864
	.public ov29_0225D880
	.public ov29_0225D910
	.public ov29_0225D970
	.public ov29_0225D9C8
	.public ov29_0225DB38
	.public ov29_0225DB7C
	.public ov29_0225DB9C
	.public ov29_0225DBF0
	.public ov29_0225DC34
	.public ov29_0225DC44
	.public ov29_0225DC48
	.public ov29_0225DC50
	.public ov29_0225DC84
	.public ov29_0225DCD0
	.public ov29_0225DEB8
	.public ov29_0225DEF4
	.public ov29_0225DF18
	.public ov29_0225DF74
	.public ov29_0225E028
	.public ov29_0225E078
	.public ov29_0225E0E0
	.public ov29_0225E114
	.public ov29_0225E115
	.public ov29_0225E11D
	.public ov29_0225E129
	.public ov29_0225E13C
	.public ov29_0225E14C
	.public ov29_0225E160
	.public ov29_0225E178
	.public ov29_0225E190
	.public ov29_0225E1AC
	.public ov29_0225E1C8
	.public ov29_0225E1E4
	.public ov29_0225E200
	.public ov29_0225E21C
	.public ov29_0225E220
	.public ov29_0225E224
	.public ov29_0225E228
	.public ov29_0225E22C
	.public ov29_0225E230
	.public ov29_0225E234
	.public ov29_0225E238
	.public ov29_0225E23C
	.public ov29_0225E240
	.public ov29_0225E244
	.public ov29_0225E248
	.public ov29_0225E280
	.public ov29_0225E2E8
	.public ov29_0225E2EC
	.public ov29_0225E2F0
	.public ov29_0225E2F4
	.public ov29_0225E2FC
	.include "overlay_29.inc"
	.include "global.inc"

	.text

	thumb_func_start ov29_0225D520
ov29_0225D520: ; 0x0225D520
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	add r6, r1, #0
	mov r0, #3
	add r7, r2, #0
	mov r1, #8
	lsl r2, r0, #0xf
	add r5, r3, #0
	bl Heap_Create
	ldr r0, _0225D5E0 ; =0x04001050
	mov r1, #0
	strh r1, [r0]
	mov r1, #0x81
	ldr r0, _0225D5E4 ; =ov29_0225DCD0
	lsl r1, r1, #2
	mov r2, #0xa
	mov r3, #8
	bl CreateSysTaskAndEnvironment
	str r0, [sp, #4]
	bl SysTask_GetData
	add r4, r0, #0
	ldr r0, [sp]
	mov r1, #0x7f
	str r0, [r4]
	str r6, [r4, #4]
	str r7, [r4, #8]
	ldr r0, [sp, #4]
	str r5, [r4, #0xc]
	str r0, [r4, #0x14]
	mov r0, #0
	str r5, [r4, #0x10]
	mvn r0, r0
	str r0, [r5, #4]
	mov r5, #0
	lsl r1, r1, #2
	str r5, [r4, r1]
	ldr r1, [r4, #0x10]
	ldr r0, _0225D5E8 ; =0x000186A0
	ldr r6, [r1]
	mov r7, #0xa
_0225D578:
	cmp r6, r0
	blo _0225D588
	mov r0, #6
	sub r1, r0, r5
	mov r0, #0x7f
	lsl r0, r0, #2
	str r1, [r4, r0]
	b _0225D594
_0225D588:
	add r1, r7, #0
	bl _u32_div_f
	add r5, r5, #1
	cmp r5, #6
	blo _0225D578
_0225D594:
	mov r0, #0x7f
	lsl r0, r0, #2
	ldr r1, [r4, r0]
	cmp r1, #0
	bne _0225D5A2
	mov r1, #1
	str r1, [r4, r0]
_0225D5A2:
	mov r0, #0xee
	mov r1, #8
	bl NARC_New
	add r5, r0, #0
	bl ov29_0225D620
	ldr r0, [sp]
	bl ov29_0225D648
	add r0, r4, #0
	add r1, r5, #0
	bl ov29_0225D6C8
	add r0, r4, #0
	bl ov29_0225D714
	add r0, r4, #0
	add r1, r5, #0
	bl ov29_0225D7F0
	add r0, r4, #0
	bl ov29_0225DBF0
	add r0, r5, #0
	bl NARC_Delete
	ldr r0, [sp, #4]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0225D5E0: .word 0x04001050
_0225D5E4: .word ov29_0225DCD0
_0225D5E8: .word 0x000186A0
	thumb_func_end ov29_0225D520
