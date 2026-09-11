	.include "asm/macros.inc"
	.public _0225D5C0
	.public _0225D5C4
	.public _0225D5C8
	.public _0225D62C
	.public _0225D630
	.public _0225D796
	.public _0225D82C
	.public _0225D830
	.public _0225D980
	.public _0225D984
	.public _0225D99C
	.public _0225D9A0
	.public _0225D9D4
	.public _0225DA7C
	.public _0225DA80
	.public _0225DA84
	.public _0225DCB2
	.public _0225DCCC
	.public _0225DCD0
	.public _0225DD64
	.public _0225DDA0
	.public _0225DDA4
	.public _0225DDA8
	.public _0225DDDE
	.public _0225DDE6
	.public _0225DDF4
	.public _0225DE02
	.public _0225DE18
	.public _0225DE22
	.public _0225DE56
	.public _0225DE6C
	.public _0225DE8E
	.public _0225DEA0
	.public _0225DEA8
	.public _0225DEB2
	.public _0225DEBA
	.public _0225DEEA
	.public _0225DF0A
	.public _0225DF2A
	.public _0225DF3A
	.public _0225DF50
	.public _0225DF62
	.public _0225DF68
	.public _0225DF6C
	.public _0225DF70
	.public _0225DF74
	.public _0225DF78
	.public _0225DF7C
	.public _0225DFB0
	.public _0225DFBC
	.public _0225DFC6
	.public _0225DFCA
	.public _0225DFE4
	.public _0225E00C
	.public _0225E05E
	.public _0225E070
	.public _0225E092
	.public _0225E0A2
	.public _0225E0F4
	.public _0225E0F8
	.public _0225E158
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D60C
	.public ov32_0225D788
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.public ov32_0225E168
	.public ov32_0225E178
	.public ov32_0225E188
	.public ov32_0225E1A4
	.public ov32_0225E1C0
	.public ov32_0225E1DC
	.public ov32_0225E204
	.public ov32_0225E24C
	.public _0225E15C
	.public ov32_0225D520
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D60C
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D788
	.public ov32_0225D834
	.public ov32_0225D84C
	.public ov32_0225D988
	.public ov32_0225DA88
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DB1C
	.public ov32_0225DBAC
	.public ov32_0225DC0C
	.public ov32_0225DC68
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DD24
	.public ov32_0225DD74
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DDC4
	.public ov32_0225DE34
	.public ov32_0225DF80
	.public ov32_0225DF9C
	.public ov32_0225DFE8
	.public ov32_0225E048
	.public ov32_0225E0A8
	.public ov32_0225E0FC
	.include "overlay_32.inc"
	.include "global.inc"

	.text
	.public ov32_0225D5CC
	.public ov32_0225D608
	.public ov32_0225D634
	.public ov32_0225D6C4
	.public ov32_0225D6E0
	.public ov32_0225D748
	.public ov32_0225D76C
	.public ov32_0225D834
	.public ov32_0225DAC0
	.public ov32_0225DADC
	.public ov32_0225DB00
	.public ov32_0225DCD4
	.public ov32_0225DD04
	.public ov32_0225DDAC
	.public ov32_0225DDB8
	.public ov32_0225DDBC
	.public ov32_0225DF80

	thumb_func_start ov32_0225D520
ov32_0225D520: ; 0x0225D520
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r6, r0, #0
	str r1, [sp]
	mov r0, #3
	str r2, [sp, #4]
	mov r1, #8
	lsl r2, r0, #0xf
	add r4, r3, #0
	bl Heap_Create
	ldr r0, _0225D5C0 ; =0x04001050
	mov r1, #0
	strh r1, [r0]
	mov r1, #0xad
	ldr r0, _0225D5C4 ; =ov32_0225DDC4
	lsl r1, r1, #2
	mov r2, #0xa
	mov r3, #8
	bl CreateSysTaskAndEnvironment
	add r7, r0, #0
	bl SysTask_GetData
	add r5, r0, #0
	ldr r0, [sp]
	str r6, [r5]
	str r0, [r5, #4]
	ldr r0, [sp, #4]
	str r0, [r5, #8]
	str r4, [r5, #0xc]
	str r7, [r5, #0x10]
	ldr r0, [r0, #0xc]
	bl sub_0202C6F4
	str r0, [r5, #0x14]
	mov r0, #0x2b
	lsl r0, r0, #4
	str r4, [r5, r0]
	mov r1, #0
	ldr r0, [r5, r0]
	mvn r1, r1
	str r1, [r0]
	mov r0, #4
	mov r1, #8
	bl FontID_Alloc
	ldr r0, _0225D5C8 ; =0x00000105
	mov r1, #8
	bl NARC_New
	add r4, r0, #0
	bl ov32_0225D60C
	add r0, r6, #0
	bl ov32_0225D634
	add r0, r5, #0
	add r1, r4, #0
	bl ov32_0225D6E0
	add r0, r5, #0
	bl ov32_0225D748
	add r0, r5, #0
	bl ov32_0225D788
	add r0, r5, #0
	add r1, r4, #0
	bl ov32_0225DA88
	add r0, r5, #0
	bl ov32_0225DD74
	add r0, r4, #0
	bl NARC_Delete
	add r0, r7, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0225D5C0: .word 0x04001050
_0225D5C4: .word ov32_0225DDC4
_0225D5C8: .word 0x00000105
	thumb_func_end ov32_0225D520
