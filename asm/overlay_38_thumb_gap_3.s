.include "asm/macros.inc"
.include "overlay_38_thumb.inc"
.include "global.inc"

.public _02225040
.public ov38_0221BB44
.public ov38_0222508C
.public ov38_02225094
.public ov38_0222512C

	.text

	thumb_func_start ov38_0221BEA8
ov38_0221BEA8: ; 0x0221BEA8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	ldr r1, _0221BF38 ; =_02225040
	add r4, r3, #0
	ldr r3, [r1]
	add r7, r0, #0
	cmp r3, #2
	beq _0221BEBC
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0221BEBC:
	str r5, [r1, #0x10]
	str r2, [r1, #0x14]
	str r4, [r1, #0x18]
	ldr r2, [sp, #0x18]
	add r4, #8
	str r2, [r1, #0x1c]
	ldr r2, [sp, #0x1c]
	str r2, [r1, #0x20]
	bl strlen
	add r6, r0, #0
	add r0, r4, #0
	bl ov38_0221BB44
	add r1, r0, #0
	add r6, #0x45
	mov r0, #0xa
	add r1, r6, r1
	bl ov00_021EC2A8
	ldr r1, _0221BF38 ; =_02225040
	cmp r0, #0
	str r0, [r1, #0x24]
	bne _0221BEF0
	mov r0, #2
	pop {r3, r4, r5, r6, r7, pc}
_0221BEF0:
	ldr r1, _0221BF3C ; =ov38_0222512C
	add r2, r7, #0
	add r3, r5, #0
	bl sprintf
	ldr r0, _0221BF38 ; =_02225040
	ldr r6, [r0, #0x24]
	add r0, r6, #0
	bl strlen
	add r5, r0, #0
	ldr r0, _0221BF40 ; =ov38_0222508C
	bl strlen
	add r1, r6, r5
	add r1, r1, r0
	ldr r0, _0221BF38 ; =_02225040
	str r1, [r0, #0x28]
	ldr r0, _0221BF44 ; =ov38_02225094
	bl strlen
	ldr r1, _0221BF38 ; =_02225040
	ldr r2, [r1, #0x28]
	add r2, #0x28
	add r0, r2, r0
	str r0, [r1, #0x2c]
	add r0, r4, #0
	bl ov38_0221BB44
	add r1, r0, #1
	ldr r0, _0221BF38 ; =_02225040
	str r1, [r0, #0x30]
	mov r1, #3
	str r1, [r0]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221BF38: .word _02225040
_0221BF3C: .word ov38_0222512C
_0221BF40: .word ov38_0222508C
_0221BF44: .word ov38_02225094
	thumb_func_end ov38_0221BEA8
