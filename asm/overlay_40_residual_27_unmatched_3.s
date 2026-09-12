	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BeginNormalPaletteFade
	.public GfGfxLoader_LoadScrnDataFromOpenNarc
	.public IsPaletteFadeFinished
	.public PaletteData_BlendPalettes
	.public PlaySE
	.public System_GetTouchHeld
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222C4DC
	.public ov40_0222C750
	.public ov40_0222C884
	.public ov40_0222CAD8
	.public ov40_0222CCAC
	.public ov40_0222CE7C
	.public ov40_0222CF10
	.public ov40_0222D2A0
	.public ov40_0222DAF0
	.public ov40_02230964
	.public ov40_02230E34
	.public ov40_02230EB4
	.public ov40_02230ED8
	.public ov40_02231100
	.public ov40_0223131C
	.public sub_020878B0
	.public sub_020878B8
	.public sub_02087948
	.public sub_020879E0
	.public sub_02087A30
	.public sub_02087A54
	.text

	thumb_func_start ov40_02230ED8
ov40_02230ED8: ; 0x02230ED8
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #6
	bls _02230EE6
	b _022310DA
_02230EE6:
	add r2, r1, r1
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_02230EF2: ; jump table
	.short _02230F00 - _02230EF2 - 2 ; case 0
	.short _02230FA2 - _02230EF2 - 2 ; case 1
	.short _02230FE6 - _02230EF2 - 2 ; case 2
	.short _02231032 - _02230EF2 - 2 ; case 3
	.short _02231056 - _02230EF2 - 2 ; case 4
	.short _0223107E - _02230EF2 - 2 ; case 5
	.short _022310A6 - _02230EF2 - 2 ; case 6
_02230F00:
	bl ov40_0222C4DC
	cmp r0, #1
	bne _02230F12
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222BF80
	b _022310E2
_02230F12:
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x6d
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	ldr r2, _022310E8 ; =0x0000FFFE
	mov r1, #2
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	ldr r2, _022310EC ; =0x0000BFFF
	mov r1, #0
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	ldr r2, _022310F0 ; =0x00003FFE
	mov r1, #3
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	ldr r2, _022310F4 ; =0x0000FFFF
	mov r1, #1
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	ldr r0, _022310F8 ; =0x000006F4
	ldr r0, [r4, r0]
	bl sub_02087A30
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_02087A30
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022310E2
_02230FA2:
	bl IsPaletteFadeFinished
	cmp r0, #0
	bne _02230FAC
	b _022310E2
_02230FAC:
	ldr r0, _022310F8 ; =0x000006F4
	mov r1, #0x80
	ldr r0, [r4, r0]
	mov r2, #0x10
	bl sub_02087948
	ldr r0, _022310F8 ; =0x000006F4
	mov r1, #0x80
	ldr r0, [r4, r0]
	mov r2, #0xd8
	bl sub_020878B8
	ldr r0, _022310F8 ; =0x000006F4
	mov r1, #1
	ldr r0, [r4, r0]
	bl sub_020879E0
	ldr r0, _022310F8 ; =0x000006F4
	mov r1, #1
	ldr r0, [r4, r0]
	bl sub_020878B0
	ldr r0, _022310FC ; =0x00000576
	bl PlaySE
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022310E2
_02230FE6:
	ldr r0, [r4, #0xc]
	add r0, r0, #1
	str r0, [r4, #0xc]
	cmp r0, #0x19
	blt _022310E2
	mov r0, #0
	str r0, [r4, #0xc]
	mov r0, #0x6f
	lsl r0, r0, #4
	mov r1, #0x80
	add r2, r1, #0
	ldr r0, [r4, r0]
	sub r2, #0x90
	bl sub_02087948
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0x60
	bl sub_020878B8
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020878B0
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022310E2
_02231032:
	ldr r1, [r4, #0xc]
	add r1, r1, #1
	str r1, [r4, #0xc]
	cmp r1, #0x12
	blt _022310E2
	bl ov40_02230E34
	ldr r0, _022310F8 ; =0x000006F4
	mov r1, #0
	ldr r0, [r4, r0]
	bl sub_020879E0
	mov r0, #0
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022310E2
_02231056:
	ldr r0, [r4, #0xc]
	cmp r0, #0x10
	bge _02231078
	add r0, r0, #4
	str r0, [r4, #0xc]
	ldr r0, _022310F4 ; =0x0000FFFF
	mov r2, #0xf
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #0
	lsl r2, r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _022310E2
_02231078:
	add r0, r1, #1
	str r0, [r4, #8]
	b _022310E2
_0223107E:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	ble _022310A0
	sub r0, r0, #4
	str r0, [r4, #0xc]
	ldr r0, _022310F4 ; =0x0000FFFF
	mov r2, #0xf
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #0
	lsl r2, r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _022310E2
_022310A0:
	add r0, r1, #1
	str r0, [r4, #8]
	b _022310E2
_022310A6:
	bl System_GetTouchHeld
	cmp r0, #1
	bne _022310E2
	add r0, r4, #0
	bl ov40_02230EB4
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	ldr r0, _022310F8 ; =0x000006F4
	ldr r0, [r4, r0]
	bl sub_02087A54
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl sub_02087A54
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022310E2
_022310DA:
	add r0, r4, #0
	mov r1, #1
	bl ov40_0222BF80
_022310E2:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_022310E8: .word 0x0000FFFE
_022310EC: .word 0x0000BFFF
_022310F0: .word 0x00003FFE
_022310F4: .word 0x0000FFFF
_022310F8: .word 0x000006F4
_022310FC: .word 0x00000576
	thumb_func_end ov40_02230ED8


	thumb_func_start ov40_02231100
ov40_02231100: ; 0x02231100
	push {r4, lr}
	sub sp, #0x10
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _02231118
	cmp r1, #1
	beq _022311E8
	cmp r1, #2
	bne _02231116
	b _022312AE
_02231116:
	b _022312EE
_02231118:
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0222C750
	add r0, r4, #0
	bl ov40_0222C884
	add r0, r4, #0
	bl ov40_0222CAD8
	add r0, r4, #0
	bl ov40_0222CCAC
	add r0, r4, #0
	bl ov40_0222D2A0
	add r0, r4, #0
	bl ov40_0222CE7C
	add r0, r4, #0
	bl ov40_0222CF10
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_0222C4DC
	cmp r0, #1
	bne _022311D6
	ldr r0, [r4]
	cmp r0, #0
	bne _0223117A
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x45
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	b _02231192
_0223117A:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x37
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
_02231192:
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0xe0
	bl sub_02087948
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0xe0
	bl sub_020878B8
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020878B0
	ldr r1, _02231304 ; =0x0000083C
	ldr r3, [r4, #0x10]
	ldr r1, [r4, r1]
	add r0, r4, #0
	mov r2, #1
	bl ov40_0222BF64
	b _022312FC
_022311D6:
	ldr r0, _02231308 ; =0x00000573
	bl PlaySE
	mov r0, #0x10
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022312FC
_022311E8:
	bl ov40_0222C4DC
	cmp r0, #1
	bne _02231202
	bl IsPaletteFadeFinished
	cmp r0, #1
	beq _022311FA
	b _022312FC
_022311FA:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022312FC
_02231202:
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _0223127E
	sub r0, r0, #2
	str r0, [r4, #0xc]
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _0223130C ; =0x0000FFFE
	mov r1, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231310 ; =0x0000FFFF
	mov r1, #0
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231314 ; =0x00003FFE
	mov r1, #3
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	add r0, r4, #0
	bl ov40_0222DAF0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	ldr r2, _02231310 ; =0x0000FFFF
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _022312FC
_0223127E:
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #2
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r0, [r4, #0x28]
	mov r2, #0xc
	mov r3, #0x10
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022312FC
_022312AE:
	ldr r0, [r4]
	cmp r0, #0
	bne _022312CE
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x45
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	b _022312E6
_022312CE:
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x37
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
_022312E6:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022312FC
_022312EE:
	ldr r1, _02231318 ; =0x00000724
	ldr r1, [r4, r1]
	cmp r1, #3
	blt _022312FC
	mov r1, #2
	bl ov40_0222BF80
_022312FC:
	mov r0, #0
	add sp, #0x10
	pop {r4, pc}
	nop
_02231304: .word 0x0000083C
_02231308: .word 0x00000573
_0223130C: .word 0x0000FFFE
_02231310: .word 0x0000FFFF
_02231314: .word 0x00003FFE
_02231318: .word 0x00000724
	thumb_func_end ov40_02231100


	thumb_func_start ov40_0223131C
ov40_0223131C: ; 0x0223131C
	push {r3, r4, r5, lr}
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _02231330
	cmp r1, #1
	beq _02231398
	cmp r1, #2
	beq _022313B8
	b _022313E4
_02231330:
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0x60
	bl sub_02087948
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #0x80
	mov r2, #0x60
	bl sub_020878B8
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020879E0
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	mov r1, #1
	bl sub_020878B0
	ldr r0, [r4, #0xc]
	mov r3, #0x10
	add r0, r0, #1
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r5, [r4, #0xc]
	ldr r0, [r4, #0x28]
	sub r3, r3, r5
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0xc]
	cmp r0, #2
	bne _022313EA
	mov r0, #0xf
	str r0, [r4, #0xc]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022313EA
_02231398:
	ldr r0, [r4, #0x58]
	mov r1, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022313EA
_022313B8:
	ldr r0, [r4, #0xc]
	mov r1, #1
	sub r0, r0, #1
	str r0, [r4, #0xc]
	ldr r0, [r4, #0x58]
	mov r2, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0xc]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0xc]
	cmp r0, #0
	bne _022313EA
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _022313EA
_022313E4:
	mov r1, #3
	bl ov40_0222BF80
_022313EA:
	mov r0, #0
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end ov40_0223131C
