#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/sndseq.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/std_script.h"
	.include "asm/macros.inc"
	.public ov02_0224DF1C
	.extern ov02_0224DE10
	.extern PlayerAvatar_CopyPositionVector
	.extern FollowMon_GetMapObject
	.extern MapObject_CopyPositionVector
	.extern GF_AssertFail
	.text

	thumb_func_start ov02_0224DF1C
ov02_0224DF1C: ; 0x0224DF1C
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r4, r0, #0
	mov r0, #1
	mov r1, #0x3a
	mov r2, #3
	lsl r0, r0, #0xc
	lsl r1, r1, #6
	str r0, [r4, r1]
	add r0, r1, #4
	lsl r2, r2, #0xc
	sub r1, #8
	str r2, [r4, r0]
	ldr r0, [r4, r1]
	add r1, sp, #0xc
	ldr r0, [r0, #0x40]
	bl PlayerAvatar_CopyPositionVector
	ldr r0, _0224E004 ; =0x00000E9A
	ldrh r1, [r4, r0]
	cmp r1, #0
	beq _0224DFC6
	sub r0, #0x22
	ldr r0, [r4, r0]
	bl FollowMon_GetMapObject
	add r1, sp, #0
	bl MapObject_CopyPositionVector
	mov r5, #0
	add r1, r4, #0
_0224DF5A:
	add r0, r1, #0
	add r0, #0xd8
	ldr r0, [r0]
	cmp r0, #0
	bne _0224DF80
	mov r3, #0x3a
	lsl r3, r3, #6
	add r1, r4, #0
	mov r0, #0xcc
	ldr r2, [r4, r3]
	add r3, r3, #4
	add r1, #0x10
	mul r0, r5
	add r0, r1, r0
	ldr r3, [r4, r3]
	add r1, sp, #0xc
	bl ov02_0224DE10
	b _0224DF88
_0224DF80:
	add r5, r5, #1
	add r1, #0xcc
	cmp r5, #0x12
	blt _0224DF5A
_0224DF88:
	cmp r5, #0x12
	bne _0224DF90
	bl GF_AssertFail
_0224DF90:
	mov r0, #0
	add r2, r4, #0
_0224DF94:
	add r1, r2, #0
	add r1, #0xd8
	ldr r1, [r1]
	cmp r1, #0
	bne _0224DFBC
	add r2, r4, #0
	mov r1, #0xcc
	mov r3, #0x3a
	add r2, #0x10
	mul r1, r0
	add r0, r2, r1
	lsl r3, r3, #6
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r3, [r4, r3]
	add r1, sp, #0
	bl ov02_0224DE10
	add sp, #0x18
	pop {r3, r4, r5, pc}
_0224DFBC:
	add r0, r0, #1
	add r2, #0xcc
	cmp r0, #0x12
	blt _0224DF94
	b _0224DFFA
_0224DFC6:
	mov r0, #0
	add r2, r4, #0
_0224DFCA:
	add r1, r2, #0
	add r1, #0xd8
	ldr r1, [r1]
	cmp r1, #0
	bne _0224DFF2
	add r2, r4, #0
	mov r1, #0xcc
	mov r3, #0x3a
	add r2, #0x10
	mul r1, r0
	add r0, r2, r1
	lsl r3, r3, #6
	ldr r2, [r4, r3]
	add r3, r3, #4
	ldr r3, [r4, r3]
	add r1, sp, #0xc
	bl ov02_0224DE10
	add sp, #0x18
	pop {r3, r4, r5, pc}
_0224DFF2:
	add r0, r0, #1
	add r2, #0xcc
	cmp r0, #0x12
	blt _0224DFCA
_0224DFFA:
	bl GF_AssertFail
	add sp, #0x18
	pop {r3, r4, r5, pc}
	nop
_0224E004: .word 0x00000E9A
	thumb_func_end ov02_0224DF1C
