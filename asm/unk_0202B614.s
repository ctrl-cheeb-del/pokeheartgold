#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "unk_0202B614.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_0202BCAC
sub_0202BCAC: ; 0x0202BCAC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	add r6, r2, #0
	bl sub_02015FCC
	add r1, sp, #0xc
	strh r0, [r1]
	lsr r0, r0, #0x10
	strh r0, [r1, #2]
	ldrh r0, [r1]
	strh r0, [r1, #4]
	ldrh r0, [r1, #2]
	strh r0, [r1, #6]
	ldr r0, [r4, #4]
	bl sub_02015FF8
	add r7, r0, #0
	cmp r6, #0xa
	blt _0202BCDC
	bl GF_AssertFail
_0202BCDC:
	add r1, sp, #0xc
	mov r0, #4
	ldrsh r1, [r1, r0]
	add r0, #0xfc
	cmp r1, r0
	blt _0202BCEC
	bl GF_AssertFail
_0202BCEC:
	add r0, sp, #0xc
	mov r1, #6
	ldrsh r0, [r0, r1]
	add r1, #0xfa
	str r0, [sp, #8]
	ldr r0, [sp, #8]
	cmp r0, r1
	blt _0202BD00
	bl GF_AssertFail
_0202BD00:
	mov r0, #0x7f
	mvn r0, r0
	cmp r7, r0
	bgt _0202BD0C
	bl GF_AssertFail
_0202BD0C:
	mov r0, #1
	lsl r0, r6
	ldr r1, [r5, #0x3c]
	str r0, [sp, #4]
	tst r0, r1
	beq _0202BD1C
	bl GF_AssertFail
_0202BD1C:
	ldr r0, [r5]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BD2A
	bl GF_AssertFail
_0202BD2A:
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r1, r5, #0
	add r3, sp, #0xc
	mov r2, #4
	ldrsh r2, [r3, r2]
	ldr r3, [sp, #8]
	add r1, #0x48
	lsl r0, r6, #2
	add r0, r1, r0
	ldr r1, [r4]
	lsl r2, r2, #0x18
	lsl r1, r1, #0x18
	lsl r3, r3, #0x18
	lsr r1, r1, #0x18
	lsr r2, r2, #0x18
	lsr r3, r3, #0x18
	bl sub_0202B770
	ldr r1, [r5, #0x3c]
	ldr r0, [sp, #4]
	orr r0, r1
	str r0, [r5, #0x3c]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0202BCAC

	thumb_func_start sub_0202BD60
sub_0202BD60: ; 0x0202BD60
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl sub_0202B614
	cmp r0, #0
	bne _0202BD74
	bl GF_AssertFail
_0202BD74:
	add r5, #0x70
	strb r4, [r5]
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0202BD60

	thumb_func_start sub_0202BD7C
sub_0202BD7C: ; 0x0202BD7C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl sub_0202B614
	cmp r0, #0
	bne _0202BD90
	bl GF_AssertFail
_0202BD90:
	add r0, r5, #0
	add r0, #0x40
	bl MailMsg_Init
	add r5, #0x40
	add r0, r5, #0
	mov r1, #0
	add r2, r4, #0
	bl MailMsg_SetFieldI
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0202BD7C

	thumb_func_start sub_0202BDA8
sub_0202BDA8: ; 0x0202BDA8
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl sub_0202B614
	cmp r0, #0
	bne _0202BDBC
	bl GF_AssertFail
_0202BDBC:
	add r0, r5, #0
	add r1, r4, #0
	mov r2, #0x74
	bl memcpy
	pop {r3, r4, r5, pc}
	thumb_func_end sub_0202BDA8

	thumb_func_start sub_0202BDC8
sub_0202BDC8: ; 0x0202BDC8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	add r6, r2, #0
	bl sub_0202B614
	cmp r0, #0
	bne _0202BDDE
	bl GF_AssertFail
_0202BDDE:
	add r0, r5, #4
	add r1, r4, #0
	add r2, r6, #0
	bl sub_0202B718
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_0202BDC8

	thumb_func_start sub_0202BDEC
sub_0202BDEC: ; 0x0202BDEC
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0xa
	blt _0202BDFA
	bl GF_AssertFail
_0202BDFA:
	ldr r0, [r5]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BE08
	bl GF_AssertFail
_0202BE08:
	mov r0, #1
	ldr r1, [r5, #0x3c]
	lsl r0, r4
	and r0, r1
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0202BDEC

	thumb_func_start sub_0202BE14
sub_0202BE14: ; 0x0202BE14
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BE26
	bl GF_AssertFail
_0202BE26:
	add r0, r4, #4
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_0202BE14

	thumb_func_start sub_0202BE2C
sub_0202BE2C: ; 0x0202BE2C
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	cmp r4, #0xa
	blt _0202BE3A
	bl GF_AssertFail
_0202BE3A:
	mov r0, #1
	ldr r1, [r5, #0x3c]
	lsl r0, r4
	tst r0, r1
	bne _0202BE48
	bl GF_AssertFail
_0202BE48:
	ldr r0, [r5]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BE56
	bl GF_AssertFail
_0202BE56:
	add r5, #0x48
	lsl r0, r4, #2
	add r0, r5, r0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0202BE2C

	thumb_func_start sub_0202BE60
sub_0202BE60: ; 0x0202BE60
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	bl sub_0202B614
	cmp r0, #0
	bne _0202BE74
	bl GF_AssertFail
_0202BE74:
	add r0, r5, #4
	add r1, r4, #0
	bl sub_0202BECC
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_0202BE60

	thumb_func_start sub_0202BE80
sub_0202BE80: ; 0x0202BE80
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BE92
	bl GF_AssertFail
_0202BE92:
	add r4, #0x70
	ldrb r0, [r4]
	pop {r4, pc}
	thumb_func_end sub_0202BE80

	thumb_func_start sub_0202BE98
sub_0202BE98: ; 0x0202BE98
	ldr r3, _0202BEA0 ; =MailMsg_GetFieldI
	add r0, #0x40
	mov r1, #0
	bx r3
	.balign 4, 0
_0202BEA0: .word MailMsg_GetFieldI
	thumb_func_end sub_0202BE98

	thumb_func_start sub_0202BEA4
sub_0202BEA4: ; 0x0202BEA4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4]
	bl sub_0202B614
	cmp r0, #0
	bne _0202BEB6
	bl GF_AssertFail
_0202BEB6:
	ldr r1, [r4]
	ldr r0, _0202BEC8 ; =0x00002345
	cmp r1, r0
	bne _0202BEC2
	mov r0, #1
	pop {r4, pc}
_0202BEC2:
	mov r0, #0
	pop {r4, pc}
	nop
_0202BEC8: .word 0x00002345
	thumb_func_end sub_0202BEA4

	thumb_func_start sub_0202BECC
sub_0202BECC: ; 0x0202BECC
	add r2, r0, #0
	ldr r3, _0202BED8 ; =CopyU16ArrayToString
	add r2, #0x20
	add r0, r1, #0
	add r1, r2, #0
	bx r3
	.balign 4, 0
_0202BED8: .word CopyU16ArrayToString
	thumb_func_end sub_0202BECC

	thumb_func_start sub_0202BEDC
sub_0202BEDC: ; 0x0202BEDC
	mov r1, #0x30
	ldrsb r0, [r0, r1]
	bx lr
	.balign 4, 0
	thumb_func_end sub_0202BEDC

	thumb_func_start sub_0202BEE4
sub_0202BEE4: ; 0x0202BEE4
	add r0, #0x31
	ldrb r0, [r0]
	bx lr
	.balign 4, 0
	thumb_func_end sub_0202BEE4

	thumb_func_start sub_0202BEEC
sub_0202BEEC: ; 0x0202BEEC
	add r0, #0x32
	ldrb r0, [r0]
	bx lr
	.balign 4, 0
	thumb_func_end sub_0202BEEC

	thumb_func_start sub_0202BEF4
sub_0202BEF4: ; 0x0202BEF4
	ldr r3, _0202BEF8 ; =sub_0202B730
	bx r3
	.balign 4, 0
_0202BEF8: .word sub_0202B730
	thumb_func_end sub_0202BEF4

	thumb_func_start sub_0202BEFC
sub_0202BEFC: ; 0x0202BEFC
	ldrb r0, [r0]
	bx lr
	thumb_func_end sub_0202BEFC

	thumb_func_start sub_0202BF00
sub_0202BF00: ; 0x0202BF00
	ldrb r0, [r0, #1]
	bx lr
	thumb_func_end sub_0202BF00

	thumb_func_start sub_0202BF04
sub_0202BF04: ; 0x0202BF04
	ldrb r0, [r0, #2]
	bx lr
	thumb_func_end sub_0202BF04

	thumb_func_start sub_0202BF08
sub_0202BF08: ; 0x0202BF08
	mov r1, #3
	ldrsb r0, [r0, r1]
	bx lr
	.balign 4, 0
	thumb_func_end sub_0202BF08

	thumb_func_start sub_0202BF10
sub_0202BF10: ; 0x0202BF10
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0xc
	add r7, r0, #0
	mov r0, #1
	add r4, r1, #0
	str r0, [sp]
	add r0, r4, #0
	bl sub_0202BC10
	cmp r0, #1
	bne _0202BF6E
	ldr r1, _0202BF7C ; =0xEDB88320
	add r0, sp, #4
	bl MATHi_CRC32InitTableRev
	add r0, sp, #4
	add r1, r4, #0
	mov r2, #0x74
	bl MATH_CalcCRC32
	add r6, r0, #0
	mov r5, #0
_0202BF40:
	add r0, r7, #0
	add r1, r5, #0
	bl sub_0202B9B8
	add r4, r0, #0
	ldr r1, _0202BF7C ; =0xEDB88320
	add r0, sp, #4
	bl MATHi_CRC32InitTableRev
	add r0, sp, #4
	add r1, r4, #0
	mov r2, #0x74
	bl MATH_CalcCRC32
	cmp r0, r6
	bne _0202BF66
	mov r0, #0
	str r0, [sp]
	b _0202BF72
_0202BF66:
	add r5, r5, #1
	cmp r5, #0xb
	blt _0202BF40
	b _0202BF72
_0202BF6E:
	mov r0, #0
	str r0, [sp]
_0202BF72:
	ldr r0, [sp]
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0202BF7C: .word 0xEDB88320
	thumb_func_end sub_0202BF10

	thumb_func_start sub_0202BF80
sub_0202BF80: ; 0x0202BF80
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	mov r7, #0
	ldr r0, [sp]
	str r1, [sp, #4]
	add r5, r2, #0
	add r6, r7, #0
	str r3, [sp, #8]
	cmp r0, #0
	ble _0202BFBA
	add r4, r3, #0
_0202BF98:
	ldr r0, [sp, #4]
	cmp r6, r0
	beq _0202BFB0
	ldr r1, [r4]
	cmp r1, #0
	beq _0202BFB0
	add r0, r5, #0
	bl sub_0202BF10
	cmp r0, #1
	bne _0202BFB0
	add r7, r7, #1
_0202BFB0:
	ldr r0, [sp]
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, r0
	blt _0202BF98
_0202BFBA:
	mov r4, #0xa
_0202BFBC:
	add r1, r4, r7
	cmp r1, #0xb
	bge _0202BFDA
	add r0, r5, #0
	bl sub_0202B9B8
	add r6, r0, #0
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0202B9B8
	add r1, r0, #0
	add r0, r6, #0
	bl sub_0202BDA8
_0202BFDA:
	sub r4, r4, #1
	cmp r4, #1
	bge _0202BFBC
	ldr r0, [sp]
	mov r6, #1
	mov r4, #0
	cmp r0, #0
	ble _0202C022
_0202BFEA:
	ldr r0, [sp, #4]
	cmp r4, r0
	beq _0202C014
	ldr r0, [sp, #8]
	ldr r7, [r0]
	cmp r7, #0
	beq _0202C014
	add r0, r5, #0
	add r1, r7, #0
	bl sub_0202BF10
	cmp r0, #1
	bne _0202C014
	add r0, r5, #0
	add r1, r6, #0
	bl sub_0202B9B8
	add r1, r7, #0
	add r6, r6, #1
	bl sub_0202BDA8
_0202C014:
	ldr r0, [sp, #8]
	add r4, r4, #1
	add r0, r0, #4
	str r0, [sp, #8]
	ldr r0, [sp]
	cmp r4, r0
	blt _0202BFEA
_0202C022:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0202BF80

	thumb_func_start Save_FashionData_Get
Save_FashionData_Get: ; 0x0202C028
	ldr r3, _0202C030 ; =SaveArray_Get
	mov r1, #0xc
	bx r3
	nop
_0202C030: .word SaveArray_Get
	thumb_func_end Save_FashionData_Get
