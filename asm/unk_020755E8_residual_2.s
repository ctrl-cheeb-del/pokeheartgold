#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "unk_020755E8.inc"
	.include "global.inc"

	.public _020FFEC0
	.public _020FFED8
	.public _020FFF34
	.public _020FFF90
	.public _020FFFE4

	.text
	.public sub_020755E8
	.public sub_02075630
	.public sub_02075770
	.public sub_020757AC
	.public sub_02075804
	.public sub_0207584C
	.public sub_020758D0
	.public sub_020759CC
	.public sub_02075A04
	.public sub_02075A7C
	.public sub_02075D08
	.public sub_02075D3C
	.public sub_02075D4C
	.public sub_02075E14
	.public sub_02076C90
	.public sub_02076E64
	.public sub_020771A0
	.public sub_020771E8
	.public sub_02077270
	.public sub_020772F8
	.public sub_02077340
	.public sub_02077394
	.public sub_020755E8
	.public sub_02075630
	.public sub_02075770
	.public sub_020757AC
	.public sub_02075804
	.public sub_0207584C
	.public sub_020758D0
	.public sub_020759CC
	.public sub_02075A04
	.public sub_02075D08
	.public sub_02075D3C
	.public sub_02075D4C
	.public sub_020771A0
	.public sub_020771E8
	.public sub_020772F8
	.public sub_02077340
	.public sub_02077394

	thumb_func_start sub_02075E14
sub_02075E14: ; 0x02075E14
	push {r4, lr}
	sub sp, #0x90
	add r4, r0, #0
	add r0, #0x70
	ldrb r1, [r0]
	cmp r1, #0
	beq _02075EF0
	mov r0, #1
	tst r0, r1
	ldr r0, [r4, #0x1c]
	bne _02075E82
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	mov r1, #0xc
	neg r2, r2
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x1c]
	mov r1, #0xd
	neg r2, r2
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x20]
	mov r1, #0xc
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x20]
	mov r1, #0xd
	bl Pokepic_AddAttr
	ldr r0, [r4, #0x1c]
	mov r1, #0xc
	bl Pokepic_GetAttr
	cmp r0, #0
	bne _02075EF0
	add r0, r4, #0
	add r0, #0x70
	ldrb r1, [r0]
	mov r0, #1
	eor r1, r0
	add r0, r4, #0
	add r0, #0x70
	strb r1, [r0]
	b _02075EF0
_02075E82:
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	mov r1, #0xc
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x1c]
	mov r1, #0xd
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x20]
	mov r1, #0xc
	neg r2, r2
	bl Pokepic_AddAttr
	add r2, r4, #0
	add r2, #0x71
	ldrb r2, [r2]
	ldr r0, [r4, #0x20]
	mov r1, #0xd
	neg r2, r2
	bl Pokepic_AddAttr
	ldr r0, [r4, #0x20]
	mov r1, #0xc
	bl Pokepic_GetAttr
	cmp r0, #0
	bne _02075EF0
	add r0, r4, #0
	add r0, #0x70
	ldrb r1, [r0]
	mov r0, #1
	eor r1, r0
	add r0, r4, #0
	add r0, #0x70
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x71
	ldrb r0, [r0]
	cmp r0, #0x40
	bhs _02075EF0
	add r0, r4, #0
	add r0, #0x71
	ldrb r0, [r0]
	lsl r1, r0, #1
	add r0, r4, #0
	add r0, #0x71
	strb r1, [r0]
_02075EF0:
	ldr r1, [r4, #0x7c]
	mov r0, #1
	tst r0, r1
	beq _02075F2A
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	cmp r0, #8
	bne _02075F2A
	ldr r0, _02076210 ; =gSystem
	ldr r1, [r0, #0x48]
	mov r0, #2
	tst r0, r1
	beq _02075F2A
	mov r3, #0
	str r3, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	ldr r0, _02076214 ; =0x00007FFF
	ldr r2, _02076218 ; =0x0000F3FF
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r1, #0xf
	bl PaletteData_BeginPaletteFade
	add r0, r4, #0
	mov r1, #0x29
	add r0, #0x64
	strb r1, [r0]
_02075F2A:
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	cmp r0, #0x2d
	bhi _0207602A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02075F40: ; jump table
	.short _02075F9C - _02075F40 - 2 ; case 0
	.short _02075FC4 - _02075F40 - 2 ; case 1
	.short _02075FF2 - _02075F40 - 2 ; case 2
	.short _0207601C - _02075F40 - 2 ; case 3
	.short _02076038 - _02075F40 - 2 ; case 4
	.short _020760CE - _02075F40 - 2 ; case 5
	.short _0207611A - _02075F40 - 2 ; case 6
	.short _0207619C - _02075F40 - 2 ; case 7
	.short _02076254 - _02075F40 - 2 ; case 8
	.short _020762F4 - _02075F40 - 2 ; case 9
	.short _02076382 - _02075F40 - 2 ; case 10
	.short _020763FC - _02075F40 - 2 ; case 11
	.short _02076478 - _02075F40 - 2 ; case 12
	.short _020764DE - _02075F40 - 2 ; case 13
	.short _02076558 - _02075F40 - 2 ; case 14
	.short _02076620 - _02075F40 - 2 ; case 15
	.short _0207659C - _02075F40 - 2 ; case 16
	.short _02076620 - _02075F40 - 2 ; case 17
	.short _020765D2 - _02075F40 - 2 ; case 18
	.short _02076620 - _02075F40 - 2 ; case 19
	.short _02076658 - _02075F40 - 2 ; case 20
	.short _02076670 - _02075F40 - 2 ; case 21
	.short _020766BC - _02075F40 - 2 ; case 22
	.short _02076748 - _02075F40 - 2 ; case 23
	.short _020767D0 - _02075F40 - 2 ; case 24
	.short _020768E0 - _02075F40 - 2 ; case 25
	.short _02076620 - _02075F40 - 2 ; case 26
	.short _02076906 - _02075F40 - 2 ; case 27
	.short _02076620 - _02075F40 - 2 ; case 28
	.short _02076958 - _02075F40 - 2 ; case 29
	.short _02076620 - _02075F40 - 2 ; case 30
	.short _0207697E - _02075F40 - 2 ; case 31
	.short _02076808 - _02075F40 - 2 ; case 32
	.short _02076620 - _02075F40 - 2 ; case 33
	.short _0207683C - _02075F40 - 2 ; case 34
	.short _02076854 - _02075F40 - 2 ; case 35
	.short _020768AE - _02075F40 - 2 ; case 36
	.short _02076A06 - _02075F40 - 2 ; case 37
	.short _02076A24 - _02075F40 - 2 ; case 38
	.short _02076A50 - _02075F40 - 2 ; case 39
	.short _02076A84 - _02075F40 - 2 ; case 40
	.short _02076AA4 - _02075F40 - 2 ; case 41
	.short _02076B4A - _02075F40 - 2 ; case 42
	.short _02076BB8 - _02075F40 - 2 ; case 43
	.short _02076C0C - _02075F40 - 2 ; case 44
	.short _02076C66 - _02075F40 - 2 ; case 45
_02075F9C:
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _0207602A
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02075FC4:
	mov r0, #0
	bl SetMasterBrightnessNeutral
	mov r0, #1
	bl SetMasterBrightnessNeutral
	ldr r0, [r4, #0x58]
	mov r1, #0
	bl sub_0201649C
	ldr r1, [r4, #0x7c]
	mov r0, #2
	tst r1, r0
	beq _02075FE8
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02075FE8:
	mov r0, #4
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02075FF2:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _0207602A
	mov r1, #0xe5
	add r0, r4, #0
	lsl r1, r1, #2
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_0207601C:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	beq _0207602E
_0207602A:
	bl _02076C76
_0207602E:
	mov r0, #4
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076038:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076132
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r3, r4, #0
	add r0, r4, #0
	add r3, #0x60
	add r0, #0x84
	ldrh r3, [r3]
	ldr r0, [r0]
	ldr r1, [r4, #0x44]
	ldr r2, [r4, #0x1c]
	bl sub_0207294C
	add r2, r4, #0
	add r0, r4, #0
	add r2, #0x60
	add r0, #0x84
	ldrh r2, [r2]
	ldr r0, [r0]
	add r1, sp, #0x68
	mov r3, #1
	bl NARC_ReadPokepicAnimScript
	ldr r0, [r4, #0x1c]
	add r1, sp, #0x68
	bl Pokepic_SetAnimScript
	ldr r0, [r4, #0x1c]
	mov r1, #0
	bl Pokepic_StartAnim
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x60
	add r1, #0x80
	ldrh r0, [r0]
	ldrb r1, [r1]
	bl PlayCry
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r1, [r4, #0x7c]
	mov r0, #2
	tst r0, r1
	beq _020760B6
	ldr r1, _0207621C ; =0x00000395
	add r0, r4, #0
	bl sub_020772F8
	b _020760BE
_020760B6:
	ldr r1, _02076220 ; =0x00000393
	add r0, r4, #0
	bl sub_020772F8
_020760BE:
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	mov r0, #5
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020760CE:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02076132
	bl IsCryFinished
	cmp r0, #0
	bne _02076132
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl sub_02017068
	cmp r0, #1
	bne _02076132
	ldr r0, [r4, #0x1c]
	bl Pokepic_IsAnimFinished
	cmp r0, #0
	bne _02076132
	ldr r0, [r4, #0x58]
	mov r1, #1
	bl sub_0201649C
	ldr r0, _02076224 ; =0x000003F3
	bl sub_02005D10
	add r0, r4, #0
	mov r1, #0x14
	add r0, #0x66
	strb r1, [r0]
	mov r0, #6
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_0207611A:
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	beq _02076136
_02076132:
	bl _02076C76
_02076136:
	ldr r0, [r4, #0x5c]
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	add r0, sp, #0x10
	bl sub_02077604
	mov r1, #0
	str r0, [r4, #0x30]
	bl sub_02077634
	ldr r0, _02076214 ; =0x00007FFF
	mov r1, #0
	str r0, [sp]
	ldr r0, [r4, #0x1c]
	mov r2, #0x10
	mov r3, #4
	bl Pokepic_StartPaletteFade
	ldr r0, _02076214 ; =0x00007FFF
	mov r1, #0
	str r0, [sp]
	ldr r0, [r4, #0x20]
	mov r2, #0x10
	mov r3, #4
	bl Pokepic_StartPaletteFade
	ldr r0, [r4, #0x5c]
	bl HeapExp_FndGetTotalFreeSize
	mov r1, #2
	lsl r1, r1, #0xe
	cmp r0, r1
	bhi _0207617E
	bl GF_AssertFail
_0207617E:
	ldr r0, _02076228 ; =0x000005F8
	bl PlaySE
	add r0, r4, #0
	mov r1, #0x28
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_0207619C:
	add r0, r4, #0
	add r0, #0x73
	ldrb r0, [r0]
	cmp r0, #0x28
	bhs _020761C2
	add r0, r4, #0
	add r0, #0x73
	ldrb r0, [r0]
	add r1, r0, #2
	add r0, r4, #0
	add r0, #0x73
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x75
	ldrb r0, [r0]
	sub r1, r0, #2
	add r0, r4, #0
	add r0, #0x75
	strb r1, [r0]
_020761C2:
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _0207625E
	ldr r0, [r4, #0x30]
	mov r1, #1
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #2
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #7
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #8
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #9
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #0xb
	bl sub_02077634
	ldr r0, _0207622C ; =0x000005F9
	b _02076230
	nop
_02076210: .word gSystem
_02076214: .word 0x00007FFF
_02076218: .word 0x0000F3FF
_0207621C: .word 0x00000395
_02076220: .word 0x00000393
_02076224: .word 0x000003F3
_02076228: .word 0x000005F8
_0207622C: .word 0x000005F9
_02076230:
	bl PlaySE
	add r0, r4, #0
	mov r1, #0x10
	add r0, #0x70
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #8
	add r0, #0x71
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076254:
	ldr r0, [r4, #0x30]
	bl sub_02077650
	cmp r0, #0
	beq _02076262
_0207625E:
	bl _02076C76
_02076262:
	ldr r0, [r4, #0x30]
	mov r1, #3
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #4
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #5
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #6
	bl sub_02077634
	ldr r0, [r4, #0x30]
	mov r1, #0xa
	bl sub_02077634
	mov r0, #0
	str r0, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	ldr r0, _020765D8 ; =0x00007FFF
	ldr r2, _020765DC ; =0x0000F3FF
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r1, #0xf
	mov r3, #2
	bl PaletteData_BeginPaletteFade
	ldr r0, [r4, #0x1c]
	mov r1, #0xc
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x1c]
	mov r1, #0xd
	mov r2, #0
	bl Pokepic_SetAttr
	mov r1, #0xc
	add r2, r1, #0
	ldr r0, [r4, #0x20]
	add r2, #0xf4
	bl Pokepic_SetAttr
	mov r1, #0xd
	add r2, r1, #0
	ldr r0, [r4, #0x20]
	add r2, #0xf3
	bl Pokepic_SetAttr
	ldr r0, _020765E0 ; =0x000005FA
	bl PlaySE
	add r0, r4, #0
	mov r1, #0
	add r0, #0x70
	strb r1, [r0]
	add r0, r4, #0
	mov r1, #8
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_020762F4:
	add r0, r4, #0
	add r0, #0x73
	ldrb r0, [r0]
	cmp r0, #0
	beq _0207631A
	add r0, r4, #0
	add r0, #0x73
	ldrb r0, [r0]
	sub r1, r0, #2
	add r0, r4, #0
	add r0, #0x73
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x75
	ldrb r0, [r0]
	add r1, r0, #2
	add r0, r4, #0
	add r0, #0x75
	strb r1, [r0]
_0207631A:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076396
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _02076396
	ldr r0, [r4, #0x30]
	mov r1, #0xc
	bl sub_02077634
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, _020765D8 ; =0x00007FFF
	ldr r2, _020765DC ; =0x0000F3FF
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	mov r1, #0xf
	mov r3, #4
	bl PaletteData_BeginPaletteFade
	ldr r0, _020765D8 ; =0x00007FFF
	mov r1, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x18]
	mov r2, #0
	mov r3, #3
	bl Pokepic_StartPaletteFadeAll
	ldr r0, _020765E4 ; =0x000005FB
	bl PlaySE
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076382:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076396
	ldr r0, [r4, #0x30]
	bl sub_02077650
	cmp r0, #0
	beq _0207639A
_02076396:
	bl _02076C76
_0207639A:
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r3, r4, #0
	add r0, r4, #0
	add r3, #0x62
	add r0, #0x84
	ldrh r3, [r3]
	ldr r0, [r0]
	ldr r1, [r4, #0x44]
	ldr r2, [r4, #0x20]
	bl sub_0207294C
	add r2, r4, #0
	add r0, r4, #0
	add r2, #0x62
	add r0, #0x84
	ldrh r2, [r2]
	ldr r0, [r0]
	add r1, sp, #0x40
	mov r3, #1
	bl NARC_ReadPokepicAnimScript
	ldr r0, [r4, #0x20]
	add r1, sp, #0x40
	bl Pokepic_SetAnimScript
	ldr r0, [r4, #0x20]
	mov r1, #0
	bl Pokepic_StartAnim
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x62
	add r1, #0x80
	ldrh r0, [r0]
	ldrb r1, [r1]
	bl PlayCry
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_020763FC:
	bl IsCryFinished
	cmp r0, #0
	bne _020764F4
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl sub_02017068
	cmp r0, #1
	bne _020764F4
	ldr r0, [r4, #0x20]
	bl Pokepic_IsAnimFinished
	cmp r0, #0
	bne _020764F4
	add r2, r4, #0
	ldr r0, [r4, #0x28]
	mov r1, #MON_DATA_SPECIES
	add r2, #0x62
	bl SetMonData
	ldr r0, [r4, #0x28]
	bl UpdateMonAbility
	ldr r0, [r4, #0x28]
	bl CalcMonLevelAndStats
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferBoxMonSpeciesName
	ldr r1, _020765E8 ; =0x00000396
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x28
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076478:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _020764F4
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _020764F4
	ldr r0, [r4, #0x48]
	ldr r1, [r4, #0x28]
	bl Pokedex_SetMonCaughtFlag
	ldr r0, [r4, #0x50]
	mov r1, #0xd ; GAME_STAT_UNIQUE_MONS_CAUGHT
	bl GameStats_Inc
	ldr r0, [r4, #0x50]
	mov r1, #0x15 ; SCORE_EVENT_REGISTER_SPECIES_CAUGHT
	bl GameStats_AddScore
	ldr r0, [r4, #0x28]
	mov r1, #0x4d
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	bne _020764CE
	ldr r0, [r4, #0x28]
	mov r1, #MON_DATA_SPECIES_NAME
	mov r2, #0
	bl SetMonData
_020764CE:
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_020764DE:
	add r1, r4, #0
	ldr r0, [r4, #0x28]
	add r1, #0x68
	add r2, sp, #0xc
	bl MonTryLearnMoveOnLevelUp
	cmp r0, #0
	beq _020764FE
	ldr r1, _020765EC ; =0x0000FFFE
	cmp r0, r1
	bne _020764F6
_020764F4:
	b _02076C76
_020764F6:
	add r1, r1, #1
	cmp r0, r1
	beq _02076508
	b _0207651C
_020764FE:
	mov r0, #0x27
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076508:
	add r0, sp, #0xc
	ldrh r1, [r0]
	add r0, r4, #0
	add r0, #0x6c
	strh r1, [r0]
	mov r0, #0xe
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_0207651C:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	add r2, sp, #0xc
	ldrh r2, [r2]
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferMoveName
	add r0, r4, #0
	mov r1, #4
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	mov r0, #0x25
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076558:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	add r2, r4, #0
	add r2, #0x6c
	ldrh r2, [r2]
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferMoveName
	ldr r1, _020765F0 ; =0x000004A9
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_0207659C:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r1, _020765F4 ; =0x000004AA
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_020765D2:
	ldr r1, _020765F8 ; =0x000004AB
	b _020765FC
	nop
_020765D8: .word 0x00007FFF
_020765DC: .word 0x0000F3FF
_020765E0: .word 0x000005FA
_020765E4: .word 0x000005FB
_020765E8: .word 0x00000396
_020765EC: .word 0x0000FFFE
_020765F0: .word 0x000004A9
_020765F4: .word 0x000004AA
_020765F8: .word 0x000004AB
_020765FC:
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #1
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076620:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02076646
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	beq _02076648
_02076646:
	b _02076C76
_02076648:
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076658:
	add r0, r4, #0
	mov r1, #1
	bl sub_0207584C
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076670:
	add r0, r4, #0
	bl sub_02075A04
	cmp r0, #1
	beq _02076682
	cmp r0, #2
	beq _020766B2
	add sp, #0x90
	pop {r4, pc}
_02076682:
	add r0, r4, #0
	mov r1, #0x16
	add r0, #0x64
	strb r1, [r0]
	mov r1, #0
	str r1, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r2, _020769A0 ; =0x0000FFFF
	mov r1, #0xf
	mov r3, #1
	bl PaletteData_BeginPaletteFade
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4, #0x18]
	mov r2, #0x10
	add r3, r1, #0
	bl Pokepic_StartPaletteFadeAll
	add sp, #0x90
	pop {r4, pc}
_020766B2:
	mov r0, #0x20
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020766BC:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076752
	mov r0, #0
	add r1, r0, #0
	bl sub_0200FBF4
	mov r0, #1
	mov r1, #0
	bl sub_0200FBF4
	ldr r0, [r4]
	bl sub_020771A0
	add r0, r4, #0
	bl sub_02075770
	ldr r0, [r4, #0x1c]
	mov r1, #6
	mov r2, #1
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x20]
	mov r1, #6
	mov r2, #1
	bl Pokepic_SetAttr
	ldr r1, [r4, #0x28]
	ldr r0, [r4, #0x3c]
	mov r2, #1
	str r1, [r0]
	ldr r1, [r4, #0x2c]
	ldr r0, [r4, #0x3c]
	str r1, [r0, #4]
	ldr r1, [r4, #0x3c]
	mov r0, #0
	strb r0, [r1, #0x11]
	ldr r1, [r4, #0x3c]
	strb r0, [r1, #0x14]
	ldr r1, [r4, #0x3c]
	strb r2, [r1, #0x13]
	add r1, r4, #0
	add r1, #0x6c
	ldrh r2, [r1]
	ldr r1, [r4, #0x3c]
	strh r2, [r1, #0x18]
	ldr r1, [r4, #0x3c]
	mov r2, #2
	strb r2, [r1, #0x12]
	ldr r1, [r4, #0x3c]
	str r0, [r1, #0x28]
	ldr r1, [r4, #0x3c]
	str r0, [r1, #0x30]
	ldr r0, [r4, #0x3c]
	ldr r1, _020769A4 ; =_020FFEC0
	bl sub_02089D40
	add r0, r4, #0
	bl sub_02077394
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076748:
	ldr r0, [r4, #0x38]
	bl OverlayManager_Run
	cmp r0, #0
	bne _02076754
_02076752:
	b _02076C76
_02076754:
	ldr r0, [r4, #0x38]
	bl OverlayManager_Delete
	mov r0, #0
	str r0, [r4, #0x38]
	ldr r1, [r4]
	add r0, r4, #0
	bl sub_02076E64
	add r0, r4, #0
	bl sub_02075630
	ldr r0, [r4, #4]
	mov r1, #0
	mov r2, #1
	mov r3, #0xa
	bl DrawFrameAndWindow2
	ldr r0, [r4, #0x1c]
	mov r1, #6
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x20]
	mov r1, #6
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x1c]
	bl Pokepic_ScheduleReloadFromNarc
	ldr r0, [r4, #0x20]
	bl Pokepic_ScheduleReloadFromNarc
	mov r0, #0x10
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r2, _020769A0 ; =0x0000FFFF
	mov r1, #0xf
	mov r3, #1
	bl PaletteData_BeginPaletteFade
	mov r2, #0
	str r2, [sp]
	ldr r0, [r4, #0x18]
	mov r1, #0x10
	add r3, r2, #0
	bl Pokepic_StartPaletteFadeAll
	bl sub_0203A880
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_020767D0:
	mov r0, #0
	bl SetMasterBrightnessNeutral
	mov r0, #1
	bl SetMasterBrightnessNeutral
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _020768D4
	ldr r0, [r4, #0x3c]
	ldrb r1, [r0, #0x16]
	cmp r1, #4
	bne _020767F8
	mov r0, #0x20
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020767F8:
	add r0, r4, #0
	add r0, #0x6e
	strb r1, [r0]
	mov r0, #0x19
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076808:
	add r2, r4, #0
	add r2, #0x6c
	ldrh r2, [r2]
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferMoveName
	ldr r1, _020769A8 ; =0x000004AD
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #1
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_0207683C:
	add r0, r4, #0
	mov r1, #0
	bl sub_0207584C
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076854:
	add r0, r4, #0
	bl sub_02075A04
	cmp r0, #1
	beq _02076866
	cmp r0, #2
	beq _020768A4
	add sp, #0x90
	pop {r4, pc}
_02076866:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	add r2, r4, #0
	add r2, #0x6c
	ldrh r2, [r2]
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferMoveName
	ldr r1, _020769AC ; =0x000004AE
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	mov r0, #0x24
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020768A4:
	mov r0, #0xe
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020768AE:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _020768D4
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	beq _020768D6
_020768D4:
	b _02076C76
_020768D6:
	mov r0, #0xd
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_020768E0:
	ldr r1, _020769B0 ; =0x000004AF
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076906:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	add r1, r4, #0
	add r1, #0x6e
	ldrb r1, [r1]
	ldr r0, [r4, #0x28]
	mov r2, #0
	add r1, #0x36
	bl GetMonData
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferMoveName
	mov r1, #0x4b
	add r0, r4, #0
	lsl r1, r1, #4
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076958:
	ldr r1, _020769B4 ; =0x000004B1
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_0207697E:
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	add r2, r4, #0
	add r2, #0x6c
	ldrh r2, [r2]
	ldr r0, [r4, #0xc]
	mov r1, #1
	bl BufferMoveName
	ldr r1, _020769B8 ; =0x000004B2
	b _020769BC
	.balign 4, 0
_020769A0: .word 0x0000FFFF
_020769A4: .word _020FFEC0
_020769A8: .word 0x000004AD
_020769AC: .word 0x000004AE
_020769B0: .word 0x000004AF
_020769B4: .word 0x000004B1
_020769B8: .word 0x000004B2
_020769BC:
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	add r2, r4, #0
	mov r1, #0
	add r0, #0x66
	strb r1, [r0]
	add r1, r4, #0
	add r1, #0x6e
	ldrb r1, [r1]
	ldr r0, [r4, #0x28]
	add r2, #0x66
	add r1, #MON_DATA_MOVE1_PP_UPS
	bl SetMonData
	add r1, r4, #0
	add r2, r4, #0
	add r1, #0x6c
	add r2, #0x6e
	ldrh r1, [r1]
	ldrb r2, [r2]
	ldr r0, [r4, #0x28]
	bl MonSetMoveInSlot
	add r0, r4, #0
	mov r1, #0x1e
	add r0, #0x66
	strb r1, [r0]
	mov r0, #0x25
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076A06:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02076A44
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076A24:
	bl IsFanfarePlaying
	cmp r0, #0
	bne _02076A44
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	beq _02076A46
_02076A44:
	b _02076C76
_02076A46:
	mov r0, #0xd
	add r4, #0x64
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076A50:
	mov r1, #0
	str r1, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r2, _02076C7C ; =0x0000FFFF
	mov r1, #0xf
	mov r3, #1
	bl PaletteData_BeginPaletteFade
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4, #0x18]
	mov r2, #0x10
	add r3, r1, #0
	bl Pokepic_StartPaletteFadeAll
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076A84:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076B54
	ldr r0, [r4, #0x30]
	bl sub_02077664
	add r0, r4, #0
	bl sub_02076C90
	mov r0, #1
	add r4, #0x67
	add sp, #0x90
	strb r0, [r4]
	pop {r4, pc}
_02076AA4:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076B54
	mov r1, #0xc
	add r2, r1, #0
	ldr r0, [r4, #0x1c]
	add r2, #0xf4
	bl Pokepic_SetAttr
	mov r1, #0xd
	add r2, r1, #0
	ldr r0, [r4, #0x1c]
	add r2, #0xf3
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x20]
	mov r1, #0xc
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x20]
	mov r1, #0xd
	mov r2, #0
	bl Pokepic_SetAttr
	ldr r0, [r4, #0x20]
	mov r1, #6
	mov r2, #1
	bl Pokepic_SetAttr
	mov r0, #0x10
	str r0, [sp]
	mov r3, #0
	ldr r0, _02076C80 ; =0x00007FFF
	str r3, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r2, _02076C84 ; =0x0000F3FF
	mov r1, #0xf
	bl PaletteData_BeginPaletteFade
	ldr r0, _02076C80 ; =0x00007FFF
	mov r2, #0
	str r0, [sp]
	ldr r0, [r4, #0x18]
	mov r1, #0x10
	add r3, r2, #0
	bl Pokepic_StartPaletteFadeAll
	add r0, r4, #0
	mov r1, #0
	add r0, #0x72
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x73
	strb r1, [r0]
	add r0, r4, #0
	mov r2, #0xff
	add r0, #0x74
	strb r2, [r0]
	add r0, r4, #0
	mov r2, #0xa0
	add r0, #0x75
	strb r2, [r0]
	add r0, r4, #0
	add r0, #0x70
	strb r1, [r0]
	ldr r0, _02076C88 ; =0x000003F3
	bl StopBGM
	ldr r0, [r4, #0x30]
	bl sub_02077664
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076B4A:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	beq _02076B56
_02076B54:
	b _02076C76
_02076B56:
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	add r3, r4, #0
	add r0, r4, #0
	add r3, #0x60
	add r0, #0x84
	ldrh r3, [r3]
	ldr r0, [r0]
	ldr r1, [r4, #0x44]
	ldr r2, [r4, #0x1c]
	bl sub_0207294C
	add r2, r4, #0
	add r0, r4, #0
	add r2, #0x60
	add r0, #0x84
	ldrh r2, [r2]
	ldr r0, [r0]
	add r1, sp, #0x18
	mov r3, #1
	bl NARC_ReadPokepicAnimScript
	ldr r0, [r4, #0x1c]
	add r1, sp, #0x18
	bl Pokepic_SetAnimScript
	ldr r0, [r4, #0x1c]
	mov r1, #0
	bl Pokepic_StartAnim
	add r0, r4, #0
	add r1, r4, #0
	add r0, #0x60
	add r1, #0x80
	ldrh r0, [r0]
	ldrb r1, [r1]
	bl PlayCry
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076BB8:
	bl IsCryFinished
	cmp r0, #0
	bne _02076C76
	ldr r0, [r4, #0x44]
	mov r1, #0
	bl sub_02017068
	cmp r0, #1
	bne _02076C76
	ldr r0, [r4, #0x1c]
	bl Pokepic_IsAnimFinished
	cmp r0, #0
	bne _02076C76
	ldr r0, [r4, #0x28]
	bl Mon_GetBoxMon
	add r2, r0, #0
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl BufferBoxMonNickname
	ldr r1, _02076C8C ; =0x00000397
	add r0, r4, #0
	bl sub_020772F8
	add r1, r4, #0
	add r1, #0x65
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #0x14
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076C0C:
	add r0, r4, #0
	add r0, #0x65
	ldrb r0, [r0]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _02076C76
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	sub r1, r0, #1
	add r0, r4, #0
	add r0, #0x66
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x66
	ldrb r0, [r0]
	cmp r0, #0
	bne _02076C76
	mov r1, #0
	str r1, [sp]
	mov r0, #0x10
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r4, #0x14]
	ldr r2, _02076C7C ; =0x0000FFFF
	mov r1, #0xf
	mov r3, #1
	bl PaletteData_BeginPaletteFade
	mov r1, #0
	str r1, [sp]
	ldr r0, [r4, #0x18]
	mov r2, #0x10
	add r3, r1, #0
	bl Pokepic_StartPaletteFadeAll
	add r0, r4, #0
	add r0, #0x64
	ldrb r0, [r0]
	add r4, #0x64
	add sp, #0x90
	add r0, r0, #1
	strb r0, [r4]
	pop {r4, pc}
_02076C66:
	ldr r0, [r4, #0x14]
	bl PaletteData_GetSelectedBuffersBitmask
	cmp r0, #0
	bne _02076C76
	mov r0, #1
	add r4, #0x67
	strb r0, [r4]
_02076C76:
	add sp, #0x90
	pop {r4, pc}
	nop
_02076C7C: .word 0x0000FFFF
_02076C80: .word 0x00007FFF
_02076C84: .word 0x0000F3FF
_02076C88: .word 0x000003F3
_02076C8C: .word 0x00000397
	thumb_func_end sub_02075E14


	thumb_func_start sub_02076C90
sub_02076C90: ; 0x02076C90
	push {r4, r5, r6, lr}
	sub sp, #0x20
	add r4, r0, #0
	ldr r0, [r4, #0x78]
	cmp r0, #6
	bgt _02076CA4
	bne _02076CA0
	b _02076E50
_02076CA0:
	add sp, #0x20
	pop {r4, r5, r6, pc}
_02076CA4:
	sub r0, #0xd
	cmp r0, #6
	bhi _02076CE4
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02076CB6: ; jump table
	.short _02076CC4 - _02076CB6 - 2 ; case 0
	.short _02076CC4 - _02076CB6 - 2 ; case 1
	.short _02076E5E - _02076CB6 - 2 ; case 2
	.short _02076E5E - _02076CB6 - 2 ; case 3
	.short _02076E5E - _02076CB6 - 2 ; case 4
	.short _02076E50 - _02076CB6 - 2 ; case 5
	.short _02076E50 - _02076CB6 - 2 ; case 6
_02076CC4:
	ldr r0, [r4, #0x4c]
	ldr r2, [r4, #0x5c]
	mov r1, #4
	bl Bag_GetQuantity
	cmp r0, #0
	beq _02076CE4
	ldr r0, [r4, #0x24]
	bl Party_GetCount
	add r5, r0, #0
	ldr r0, [r4, #0x24]
	bl Party_GetMaxCount
	cmp r5, r0
	blt _02076CE6
_02076CE4:
	b _02076E5E
_02076CE6:
	ldr r0, [r4, #0x5c]
	bl AllocMonZeroed
	add r5, r0, #0
	ldr r0, [r4, #0x28]
	add r1, r5, #0
	bl CopyPokemonToPokemon
	mov r0, #0x49
	lsl r0, r0, #2
	str r0, [sp]
	add r0, r5, #0
	mov r1, #MON_DATA_SPECIES
	add r2, sp, #0
	bl SetMonData
	mov r0, #4
	str r0, [sp]
	add r0, r5, #0
	mov r1, #MON_DATA_POKEBALL
	add r2, sp, #0
	bl SetMonData
	mov r0, #0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #MON_DATA_HELD_ITEM
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_MARKINGS
	add r2, sp, #0
	bl SetMonData
	mov r1, #MON_DATA_SINNOH_CHAMP_RIBBON
	str r1, [sp, #4]
	add r6, sp, #0
_02076D32:
	add r0, r5, #0
	add r2, r6, #0
	bl SetMonData
	ldr r0, [sp, #4]
	add r1, r0, #1
	str r1, [sp, #4]
	cmp r1, #0x36
	blt _02076D32
	mov r1, #MON_DATA_COOL_RIBBON
	str r1, [sp, #4]
	add r6, sp, #0
_02076D4A:
	add r0, r5, #0
	add r2, r6, #0
	bl SetMonData
	ldr r0, [sp, #4]
	add r1, r0, #1
	str r1, [sp, #4]
	cmp r1, #0x6e
	blt _02076D4A
	mov r1, #MON_DATA_SUPER_COOL_RIBBON
	str r1, [sp, #4]
	add r6, sp, #0
_02076D62:
	add r0, r5, #0
	add r2, r6, #0
	bl SetMonData
	ldr r0, [sp, #4]
	add r1, r0, #1
	str r1, [sp, #4]
	cmp r1, #0x90
	blt _02076D62
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_A
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_B
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_C
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_D
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_E
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_SHINY_LEAF_CROWN
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #MON_DATA_MOOD
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #0xb3
	mov r2, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #0x4d
	add r2, sp, #0
	bl SetMonData
	add r0, r5, #0
	mov r1, #0xa0
	add r2, sp, #0
	bl SetMonData
	ldr r0, [r4, #0x5c]
	bl Mail_New
	add r6, r0, #0
	add r0, r5, #0
	mov r1, #0xaa
	add r2, r6, #0
	bl SetMonData
	add r0, r6, #0
	bl Heap_Free
	add r0, r5, #0
	mov r1, #0xa2
	add r2, sp, #0
	bl SetMonData
	mov r0, #0
	add r1, sp, #8
	mov r2, #0x18
	bl MIi_CpuClearFast
	add r0, r5, #0
	mov r1, #0xab
	add r2, sp, #8
	bl SetMonData
	add r0, r5, #0
	bl UpdateMonAbility
	add r0, r5, #0
	bl CalcMonLevelAndStats
	ldr r0, [r4, #0x24]
	add r1, r5, #0
	bl Party_AddMon
	ldr r0, [r4, #0x48]
	add r1, r5, #0
	bl Pokedex_SetMonCaughtFlag
	ldr r0, [r4, #0x50]
	mov r1, #0xd ; GAME_STAT_UNIQUE_MONS_CAUGHT
	bl GameStats_Inc
	ldr r0, [r4, #0x50]
	mov r1, #0x15 ; SCORE_EVENT_REGISTER_SPECIES_CAUGHT
	bl GameStats_AddScore
	add r0, r5, #0
	bl Heap_Free
	ldr r0, [r4, #0x4c]
	ldr r3, [r4, #0x5c]
	mov r1, #4
	mov r2, #1
	bl Bag_TakeItem
	add sp, #0x20
	pop {r4, r5, r6, pc}
_02076E50:
	mov r0, #0
	str r0, [sp, #4]
	ldr r0, [r4, #0x28]
	mov r1, #6
	add r2, sp, #4
	bl SetMonData
_02076E5E:
	add sp, #0x20
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end sub_02076C90


	thumb_func_start sub_02076E64
sub_02076E64: ; 0x02076E64
	push {r4, r5, r6, lr}
	sub sp, #0xf0
	add r5, r0, #0
	add r4, r1, #0
	bl GfGfx_DisableEngineAPlanes
	ldr r6, _02077180 ; =_020FFF34
	add r3, sp, #0x20
	mov r2, #5
_02076E76:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02076E76
	add r0, sp, #0x20
	bl GfGfx_SetBanks
	mov r1, #6
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x18
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x62
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	mov r1, #0x19
	mov r2, #1
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x12
	bl MIi_CpuClear32
	mov r1, #0x66
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x14
	lsl r2, r2, #0x10
	bl MIi_CpuClear32
	ldr r6, _02077184 ; =_020FFED8
	add r3, sp, #0x10
	add r2, r3, #0
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r6, _02077188 ; =_020FFF90
	add r3, sp, #0x9c
	mov r2, #0xa
_02076ED6:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02076ED6
	ldr r0, [r6]
	mov r1, #1
	str r0, [r3]
	add r0, r4, #0
	add r2, sp, #0x9c
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #2
	add r2, sp, #0xb8
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #3
	add r2, sp, #0xd4
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #3
	bl BgClearTilemapBufferAndCommit
	ldr r1, _0207718C ; =0x04000008
	mov r0, #3
	ldrh r2, [r1]
	bic r2, r0
	mov r0, #1
	orr r2, r0
	strh r2, [r1]
	add r1, r0, #0
	bl GfGfx_EngineATogglePlanes
	ldr r6, _02077190 ; =_020FFFE4
	add r3, sp, #0x48
	mov r2, #0xa
_02076F38:
	ldmia r6!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02076F38
	ldr r0, [r6]
	mov r1, #4
	str r0, [r3]
	add r0, r4, #0
	add r2, sp, #0x48
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #5
	add r2, sp, #0x64
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #5
	bl BgClearTilemapBufferAndCommit
	add r0, r4, #0
	mov r1, #6
	add r2, sp, #0x80
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r4, #0
	mov r1, #6
	bl BgClearTilemapBufferAndCommit
	ldr r0, [r5, #0x2c]
	bl Options_GetFrame
	add r6, r0, #0
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [r5, #0x5c]
	mov r1, #1
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r1, #0
	mov r3, #0xa
	bl sub_0200EB80
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, [r5, #0x5c]
	add r2, r4, #0
	str r0, [sp, #0xc]
	mov r0, #0x73
	mov r3, #3
	bl GfGfxLoader_LoadCharData
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldr r0, [r5, #0x5c]
	add r2, r4, #0
	str r0, [sp, #0xc]
	mov r0, #0x73
	mov r3, #3
	bl GfGfxLoader_LoadScrnData
	mov r1, #0
	str r1, [sp]
	mov r0, #0x40
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0x73
	mov r2, #8
	bl PaletteData_LoadNarc
	add r0, r6, #0
	bl sub_0200E640
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xa0
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0x26
	bl PaletteData_LoadNarc
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xb0
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0x10
	mov r2, #8
	bl PaletteData_LoadNarc
	ldr r0, [r5, #0x5c]
	mov r1, #2
	str r0, [sp]
	ldr r0, [r5]
	mov r2, #1
	mov r3, #0
	bl sub_0200E398
	bl sub_0200E3D8
	add r2, r0, #0
	mov r0, #0
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x80
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0x26
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0xa0
	str r0, [sp, #4]
	mov r2, #0
	str r2, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0xef
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x90
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0xef
	mov r2, #0xf
	bl PaletteData_LoadNarc
	mov r0, #1
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0xf0
	str r0, [sp, #8]
	ldr r0, [r5, #0x14]
	ldr r3, [r5, #0x5c]
	mov r1, #0x10
	mov r2, #9
	bl PaletteData_LoadNarc
	ldr r1, [r5, #0x5c]
	mov r0, #0xef
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	ldr r1, [r5, #0x5c]
	add r2, r4, #0
	str r1, [sp, #0xc]
	mov r1, #0x10
	mov r3, #4
	add r6, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5, #0x5c]
	mov r1, #0x11
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r2, r4, #0
	mov r3, #4
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5, #0x5c]
	mov r1, #1
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	ldr r0, [r5, #0x5c]
	mov r1, #0xa
	str r0, [sp, #0xc]
	add r0, r6, #0
	add r2, r4, #0
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add r0, r6, #0
	bl NARC_Delete
	mov r0, #5
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #1
	lsl r0, r0, #0x1a
	ldr r1, [r0]
	ldr r2, _02077194 ; =0xFFFF1FFF
	add r3, r1, #0
	and r3, r2
	lsr r1, r0, #0xd
	orr r1, r3
	ldr r3, _02077198 ; =0x04001000
	str r1, [r0]
	ldr r1, [r3]
	and r1, r2
	str r1, [r3]
	add r3, r0, #0
	add r3, #0x48
	ldrh r4, [r3]
	mov r1, #0x3f
	mov r2, #0x1f
	bic r4, r1
	orr r2, r4
	strh r2, [r3]
	add r0, #0x4a
	ldrh r2, [r0]
	bic r2, r1
	mov r1, #0x12
	orr r1, r2
	strh r1, [r0]
	add r0, r5, #0
	mov r1, #0
	add r0, #0x72
	strb r1, [r0]
	add r0, r5, #0
	add r0, #0x73
	strb r1, [r0]
	add r0, r5, #0
	mov r1, #0xff
	add r0, #0x74
	strb r1, [r0]
	add r0, r5, #0
	mov r1, #0xa0
	add r0, #0x75
	strb r1, [r0]
	bl GfGfx_BothDispOn
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, _0207719C ; =sub_02077270
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	add sp, #0xf0
	pop {r4, r5, r6, pc}
	nop
_02077180: .word _020FFF34
_02077184: .word _020FFED8
_02077188: .word _020FFF90
_0207718C: .word 0x04000008
_02077190: .word _020FFFE4
_02077194: .word 0xFFFF1FFF
_02077198: .word 0x04001000
_0207719C: .word sub_02077270
	thumb_func_end sub_02076E64
