#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_0208DE40.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0208DFF8
sub_0208DFF8: ; 0x0208DFF8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	mov r0, #0
	ldrsh r1, [r4, r0]
	ldrsh r0, [r5, r0]
	add r6, r2, #0
	sub r7, r1, r0
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	mov r1, #0
	bl _fgr
	bls _0208E04C
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	bl _ffix
	b _0208E072
_0208E04C:
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	bl _ffix
_0208E072:
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	strh r0, [r6]
	mov r0, #2
	ldrsh r1, [r4, r0]
	ldrsh r0, [r5, r0]
	sub r7, r1, r0
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	mov r1, #0
	bl _fgr
	bls _0208E0C4
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	bl _ffix
	b _0208E0EA
_0208E0C4:
	add r0, r7, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	bl _ffix
_0208E0EA:
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	strh r0, [r6, #2]
	mov r0, #4
	ldrsh r1, [r4, r0]
	ldrsh r0, [r5, r0]
	sub r4, r1, r0
	add r0, r4, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	mov r1, #0
	bl _fgr
	bls _0208E13C
	add r0, r4, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	add r1, r0, #0
	mov r0, #0x3f
	lsl r0, r0, #0x18
	bl _fadd
	bl _ffix
	b _0208E162
_0208E13C:
	add r0, r4, #0
	bl _fflt
	ldr r1, _0208E16C ; =0x45800000
	bl _fdiv
	ldr r1, _0208E170 ; =0x40800000
	bl _fdiv
	add r1, r0, #0
	ldr r0, _0208E16C ; =0x45800000
	bl _fmul
	mov r1, #0x3f
	lsl r1, r1, #0x18
	bl _fsub
	bl _ffix
_0208E162:
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	strh r0, [r6, #4]
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0208E16C: .word 0x45800000
_0208E170: .word 0x40800000
	thumb_func_end sub_0208DFF8
	thumb_func_start sub_0208E174
sub_0208E174: ; 0x0208E174
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x28
	ldr r2, _0208E33C ; =0x00000275
	add r5, r0, #0
	mov r1, #0xe6
	lsl r1, r1, #2
	ldrb r2, [r5, r2]
	ldr r0, _0208E340 ; =_02104EB0
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r2, _0208E344 ; =0x00000276
	ldr r1, _0208E348 ; =0x0000039E
	ldrb r2, [r5, r2]
	ldr r0, _0208E34C ; =_02104EC2
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r2, _0208E350 ; =0x00000277
	ldr r1, _0208E354 ; =0x000003AA
	ldrb r2, [r5, r2]
	ldr r0, _0208E358 ; =_02104ED4
	add r1, r5, r1
	bl sub_0208DF9C
	mov r1, #0xe9
	lsl r1, r1, #2
	ldr r0, _0208E35C ; =_02104EE6
	add r1, r5, r1
	mov r2, #0
	bl sub_0208DF9C
	ldr r2, _0208E360 ; =0x00000279
	mov r1, #0x3b
	lsl r1, r1, #4
	ldrb r2, [r5, r2]
	ldr r0, _0208E364 ; =_02104EF8
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r2, _0208E33C ; =0x00000275
	ldr r1, _0208E368 ; =0x000003B6
	ldrb r2, [r5, r2]
	ldr r0, _0208E36C ; =_02104F0A
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r1, _0208E370 ; =0x000003C2
	ldr r0, _0208E374 ; =_02104F1C
	add r1, r5, r1
	mov r2, #0
	bl sub_0208DF9C
	mov r2, #0x9e
	lsl r2, r2, #2
	mov r1, #0xef
	lsl r1, r1, #2
	ldrb r2, [r5, r2]
	ldr r0, _0208E378 ; =_02104F2E
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r2, _0208E360 ; =0x00000279
	mov r1, #0xf2
	lsl r1, r1, #2
	ldrb r2, [r5, r2]
	ldr r0, _0208E37C ; =_02104F40
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r1, _0208E380 ; =0x000003CE
	ldr r0, _0208E384 ; =_02104F52
	add r1, r5, r1
	mov r2, #0
	bl sub_0208DF9C
	ldr r2, _0208E350 ; =0x00000277
	ldr r1, _0208E388 ; =0x000003DA
	ldrb r2, [r5, r2]
	ldr r0, _0208E38C ; =_02104F64
	add r1, r5, r1
	bl sub_0208DF9C
	mov r2, #0x9e
	lsl r2, r2, #2
	mov r1, #0xf5
	lsl r1, r1, #2
	ldrb r2, [r5, r2]
	ldr r0, _0208E390 ; =_02104F76
	add r1, r5, r1
	bl sub_0208DF9C
	mov r1, #0x3e
	lsl r1, r1, #4
	ldr r0, _0208E394 ; =_02104F88
	add r1, r5, r1
	mov r2, #0
	bl sub_0208DF9C
	ldr r2, _0208E344 ; =0x00000276
	ldr r1, _0208E398 ; =0x000003E6
	ldrb r2, [r5, r2]
	ldr r0, _0208E39C ; =_02104F9A
	add r1, r5, r1
	bl sub_0208DF9C
	ldr r2, _0208E350 ; =0x00000277
	ldr r1, _0208E3A0 ; =0x000003F2
	ldrb r2, [r5, r2]
	ldr r0, _0208E3A4 ; =_02104FAC
	add r1, r5, r1
	bl sub_0208DF9C
	mov r2, #0x9e
	lsl r2, r2, #2
	mov r1, #0xfb
	lsl r1, r1, #2
	ldrb r2, [r5, r2]
	ldr r0, _0208E3A8 ; =_02104FBE
	add r1, r5, r1
	bl sub_0208DF9C
	mov r0, #0
	str r0, [sp, #0x24]
	mov r0, #0xce
	lsl r0, r0, #2
	add r1, r5, r0
	str r1, [sp, #0x20]
	add r1, r0, #0
	add r1, #0x60
	add r1, r5, r1
	str r1, [sp, #0x1c]
	add r1, r0, #0
	sub r1, #0x60
	add r1, r5, r1
	str r1, [sp, #0x18]
	add r1, r0, #6
	add r1, r5, r1
	str r1, [sp, #0x14]
	add r1, r0, #0
	add r1, #0x66
	add r1, r5, r1
	str r1, [sp, #0x10]
	add r1, r0, #0
	sub r1, #0x5a
	add r1, r5, r1
	str r1, [sp, #0xc]
	add r1, r0, #0
	add r1, #0xc
	add r1, r5, r1
	str r1, [sp, #8]
	add r1, r0, #0
	add r1, #0x6c
	add r1, r5, r1
	str r1, [sp, #4]
	add r1, r0, #0
	sub r1, #0x54
	add r1, r5, r1
	str r1, [sp]
	add r1, r0, #0
	add r1, #0x12
	add r7, r5, r1
	add r1, r0, #0
	add r1, #0x72
	sub r0, #0x4e
	add r6, r5, r1
	add r4, r5, r0
_0208E2C2:
	ldr r0, [sp, #0x18]
	ldr r1, [sp, #0x1c]
	ldr r2, [sp, #0x20]
	bl sub_0208DFF8
	ldr r0, [sp, #0xc]
	ldr r1, [sp, #0x10]
	ldr r2, [sp, #0x14]
	bl sub_0208DFF8
	ldr r0, [sp]
	ldr r1, [sp, #4]
	ldr r2, [sp, #8]
	bl sub_0208DFF8
	add r0, r4, #0
	add r1, r6, #0
	add r2, r7, #0
	bl sub_0208DFF8
	ldr r0, [sp, #0x20]
	add r7, #0x18
	add r0, #0x18
	str r0, [sp, #0x20]
	ldr r0, [sp, #0x1c]
	add r6, #0x18
	add r0, #0x18
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r4, #0x18
	add r0, #0x18
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	add r0, #0x18
	str r0, [sp, #0x14]
	ldr r0, [sp, #0x10]
	add r0, #0x18
	str r0, [sp, #0x10]
	ldr r0, [sp, #0xc]
	add r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	add r0, #0x18
	str r0, [sp, #8]
	ldr r0, [sp, #4]
	add r0, #0x18
	str r0, [sp, #4]
	ldr r0, [sp]
	add r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x24]
	add r0, r0, #1
	str r0, [sp, #0x24]
	cmp r0, #4
	blo _0208E2C2
	mov r0, #0xfe
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	add sp, #0x28
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0208E33C: .word 0x00000275
_0208E340: .word _02104EB0
_0208E344: .word 0x00000276
_0208E348: .word 0x0000039E
_0208E34C: .word _02104EC2
_0208E350: .word 0x00000277
_0208E354: .word 0x000003AA
_0208E358: .word _02104ED4
_0208E35C: .word _02104EE6
_0208E360: .word 0x00000279
_0208E364: .word _02104EF8
_0208E368: .word 0x000003B6
_0208E36C: .word _02104F0A
_0208E370: .word 0x000003C2
_0208E374: .word _02104F1C
_0208E378: .word _02104F2E
_0208E37C: .word _02104F40
_0208E380: .word 0x000003CE
_0208E384: .word _02104F52
_0208E388: .word 0x000003DA
_0208E38C: .word _02104F64
_0208E390: .word _02104F76
_0208E394: .word _02104F88
_0208E398: .word 0x000003E6
_0208E39C: .word _02104F9A
_0208E3A0: .word 0x000003F2
_0208E3A4: .word _02104FAC
_0208E3A8: .word _02104FBE
	thumb_func_end sub_0208E174
