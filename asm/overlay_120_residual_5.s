	.include "asm/macros.inc"
	.include "overlay_120.inc"
	.include "global.inc"

	.public ov120_022601BC
	.public ov120_022601D8
	.public ov120_022601F4
	.public ov120_022601F8
	.public ov120_022601FC
	.public ov120_02260200
	.public ov120_022602E4
	.public ov120_022602FC
	.public ov120_02260314
	.public ov120_0226032C

	.public _0226019C

	.text
	.public ov120_0225F020
	.public ov120_0225F038
	.public ov120_0225F040
	.public ov120_0225F08C
	.public ov120_0225F0FC
	.public ov120_0225F118
	.public ov120_0225F120
	.public ov120_0225F14C
	.public ov120_0225F1E8
	.public ov120_0225F240
	.public ov120_0225F268
	.public ov120_0225F294
	.public ov120_0225F2B8
	.public ov120_0225F318
	.public ov120_0225F4DC
	.public ov120_0225F6AC
	.public ov120_0225F6BC
	.public ov120_0225F6FC
	.public ov120_0225F704
	.public ov120_0225F714
	.public ov120_0225F8B0
	.public ov120_0225F90C
	.public ov120_0225F970
	.public ov120_0225F9D4
	.public ov120_0225FA5C
	.public ov120_0225FA68
	.public ov120_0225FA74
	.public ov120_0225FBAC
	.public ov120_0225FBB8
	.public ov120_0225FBC4
	.public ov120_0225FCFC
	.public ov120_0225FD08
	.public ov120_0225FD14
	.public ov120_0225FD2C
	.public ov120_0225FDA0
	.public ov120_0225FE08
	.public ov120_0225FECC
	.public ov120_0225FEE8
	.public ov120_0225FF00
	thumb_func_start ov120_0225FBC4
ov120_0225FBC4: ; 0x0225FBC4
	push {r4, r5, r6, lr}
	sub sp, #0x18
	add r4, r1, #0
	add r6, r0, #0
	ldr r0, [r4]
	ldr r5, [r4, #0xc]
	cmp r0, #5
	bls _0225FBD6
	b _0225FCF6
_0225FBD6:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225FBE2: ; jump table
	.short _0225FBEE - _0225FBE2 - 2 ; case 0
	.short _0225FC60 - _0225FBE2 - 2 ; case 1
	.short _0225FC82 - _0225FBE2 - 2 ; case 2
	.short _0225FC90 - _0225FBE2 - 2 ; case 3
	.short _0225FCAA - _0225FBE2 - 2 ; case 4
	.short _0225FCC4 - _0225FBE2 - 2 ; case 5
_0225FBEE:
	mov r0, #4
	mov r1, #8
	bl Heap_Alloc
	str r0, [r4, #0xc]
	mov r1, #0
	strb r1, [r0]
	strb r1, [r0, #1]
	strb r1, [r0, #2]
	strb r1, [r0, #3]
	strb r1, [r0, #4]
	strb r1, [r0, #5]
	strb r1, [r0, #6]
	strb r1, [r0, #7]
	ldr r5, [r4, #0xc]
	mov r0, #4
	mov r1, #1
	bl AllocWindows
	str r0, [r5]
	mov r3, #0
	str r3, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r0, [r4, #0x10]
	ldr r1, [r5]
	ldr r0, [r0, #8]
	mov r2, #3
	bl AddWindowParameterized
	mov r1, #0
	add r0, sp, #0x14
	strh r1, [r0]
	mov r0, #3
	add r1, sp, #0x14
	mov r2, #2
	mov r3, #0x1e
	bl BG_LoadPlttData
	ldr r0, [r5]
	mov r1, #0
	bl FillWindowPixelBuffer
	ldr r0, [r5]
	bl ScheduleWindowCopyToVram
	mov r0, #4
	bl ov120_0225F268
	str r0, [r5, #4]
	mov r0, #1
	add sp, #0x18
	str r0, [r4]
	pop {r4, r5, r6, pc}
_0225FC60:
	cmp r2, #0
	beq _0225FC68
	mov r1, #0x10
	b _0225FC6C
_0225FC68:
	mov r1, #0xf
	mvn r1, r1
_0225FC6C:
	mov r0, #2
	str r0, [sp]
	mov r0, #1
	add r2, r1, #0
	add r3, r4, #4
	bl ov01_021EFCF8
	mov r0, #2
	add sp, #0x18
	str r0, [r4]
	pop {r4, r5, r6, pc}
_0225FC82:
	ldr r0, [r4, #4]
	cmp r0, #0
	beq _0225FCF6
	mov r0, #3
	add sp, #0x18
	str r0, [r4]
	pop {r4, r5, r6, pc}
_0225FC90:
	mov r0, #0xf
	str r0, [sp]
	str r2, [sp, #4]
	ldr r0, [r5, #4]
	ldr r3, [r5]
	mov r1, #0
	mov r2, #4
	bl ov120_0225F2B8
	mov r0, #4
	add sp, #0x18
	str r0, [r4]
	pop {r4, r5, r6, pc}
_0225FCAA:
	ldr r0, [r5, #4]
	bl ov120_0225F4DC
	add r6, r0, #0
	ldr r0, [r5]
	bl ScheduleWindowCopyToVram
	cmp r6, #0
	beq _0225FCF6
	mov r0, #5
	add sp, #0x18
	str r0, [r4]
	pop {r4, r5, r6, pc}
_0225FCC4:
	mov r0, #0
	bl sub_0200FC20
	ldr r1, [r4, #0x14]
	cmp r1, #0
	beq _0225FCD4
	mov r0, #1
	str r0, [r1]
_0225FCD4:
	ldr r0, [r5, #4]
	bl ov120_0225F294
	ldr r0, [r5]
	bl ClearWindowTilemapAndCopyToVram
	ldr r0, [r5]
	bl RemoveWindow
	ldr r0, [r5]
	mov r1, #1
	bl WindowArray_Delete
	add r0, r4, #0
	add r1, r6, #0
	bl ov01_021EFCDC
_0225FCF6:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov120_0225FBC4

