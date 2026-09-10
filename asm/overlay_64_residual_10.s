	.include "asm/macros.inc"
	.include "overlay_64.inc"
	.include "global.inc"
	.public HallOfFameShowcase_Init
	.public HallOfFameShowcase_Main
	.public _021E6E7C
	.public ov64_021E5B10
	.public ov64_021E5CD0
	.public ov64_021E607C
	.public ov64_021E6170
	.public ov64_021E62C8
	.public ov64_021E652C
	.public ov64_021E677C
	.public ov64_021E6B84
	.public ov64_021E6C1C
	.public ov64_021E6E88
	.public ov64_021E6E98
	.public ov64_021E6EA8
	.public ov64_021E6EB8
	.public ov64_021E6ECC
	.public ov64_021E6ECE
	.public ov64_021E6EE4
	.public ov64_021E6EFC
	.public ov64_021E6F18
	.public ov64_021E6F34
	.public ov64_021E6F50
	.public ov64_021E6F6C
	.public ov64_021E6F8C
	.public ov64_021E6FAC
	.public ov64_021E6FD4
	.public ov64_021E7008
	.public ov64_021E7040
	.public ov64_021E70C8
	.public ov64_021E70FC
	.public ov64_021E73A0
	.public ov64_021E73D4
	.public ov64_021E7408
	.public ov64_021E743C


	.text
	.public HallOfFameShowcase_Exit
	.public ov64_021E5A88
	.public ov64_021E5AAC
	.public ov64_021E5AC8
	.public ov64_021E5AE4
	.public ov64_021E5B00
	.public ov64_021E5CA4
	.public ov64_021E6010
	.public ov64_021E602C
	.public ov64_021E605C
	.public ov64_021E6118
	.public ov64_021E620C
	.public ov64_021E622C
	.public ov64_021E6260
	.public ov64_021E6270
	.public ov64_021E6274
	.public ov64_021E6278
	.public ov64_021E6280
	.public ov64_021E6288
	.public ov64_021E62A8
	.public ov64_021E64F8
	.public ov64_021E6754
	.public ov64_021E6BD8
	.public ov64_021E6E30

	thumb_func_start ov64_021E6C1C
ov64_021E6C1C: ; 0x021E6C1C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x68
	add r5, r0, #0
	mov r0, #0x66
	lsl r0, r0, #2
	ldrh r0, [r5, r0]
	str r1, [sp, #0xc]
	str r2, [sp, #0x10]
	add r7, r3, #0
	bl SpeciesToOverworldModelIndexOffset
	add r2, r0, #0
	add r0, sp, #0x30
	mov r1, #0x8d
	bl ReadWholeNarcMemberByIdPair
	mov r0, #0x61
	mov r1, #0x3b
	bl NARC_New
	add r4, r0, #0
	add r0, sp, #0x30
	ldrb r0, [r0, #1]
	cmp r0, #0
	beq _021E6C58
	ldr r0, _021E6E18 ; =0x0000DCC2
	mov r3, #0xd
	str r0, [sp, #0x20]
	mov r6, #8
	b _021E6C60
_021E6C58:
	ldr r0, _021E6E1C ; =0x0000DCC1
	mov r3, #0xa
	str r0, [sp, #0x20]
	mov r6, #4
_021E6C60:
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	mov r1, #0x13
	str r7, [sp, #8]
	lsl r1, r1, #4
	ldr r0, [r5, r1]
	add r1, r1, #4
	ldr r1, [r5, r1]
	add r2, r4, #0
	bl SpriteSystem_LoadCharResObjFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	ldr r4, _021E6E20 ; =ov64_021E6FD4
	add r3, sp, #0x34
	mov r2, #6
_021E6C84:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E6C84
	ldr r0, [r4]
	str r0, [r3]
	ldr r0, [sp, #0x80]
	str r7, [sp, #0x48]
	str r0, [sp, #0x4c]
	ldr r0, [sp, #0x20]
	str r0, [sp, #0x50]
	str r0, [sp, #0x54]
	ldr r0, [sp, #0x10]
	lsl r2, r0, #2
	ldr r0, _021E6E24 ; =ov64_021E6ECC
	ldrsh r1, [r0, r2]
	add r0, sp, #0x30
	strh r1, [r0, #4]
	ldr r1, _021E6E28 ; =ov64_021E6ECE
	ldrsh r1, [r1, r2]
	add r2, sp, #0x34
	strh r1, [r0, #6]
	mov r1, #0x4e
	lsl r1, r1, #2
	add r0, r5, r1
	str r0, [sp, #0x24]
	ldr r0, [sp, #0xc]
	lsl r0, r0, #2
	str r0, [sp, #0x28]
	add r0, r1, #0
	sub r0, #8
	sub r1, r1, #4
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	bl SpriteSystem_NewSprite
	ldr r2, [sp, #0x24]
	ldr r1, [sp, #0x28]
	str r0, [r2, r1]
	ldr r0, [sp, #0x28]
	add r1, r2, #0
	ldr r0, [r1, r0]
	ldr r0, [r0]
	bl Sprite_GetImageProxy
	mov r1, #1
	bl NNS_G2dGetImageLocation
	mov r1, #0x66
	str r0, [sp, #0x2c]
	lsl r0, r6, #5
	add r4, r6, #0
	lsl r1, r1, #2
	mul r4, r0
	ldrh r0, [r5, r1]
	sub r1, #8
	ldr r1, [r5, r1]
	bl GetGenderBySpeciesAndPersonality
	mov r1, #0x66
	lsl r1, r1, #2
	add r2, r0, #0
	ldrh r0, [r5, r1]
	add r1, r1, #3
	ldrb r1, [r5, r1]
	bl ov64_021E6E30
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	mov r0, #0x51
	mov r2, #0x3b
	bl AllocAndReadWholeNarcMemberByIdPair
	str r0, [sp, #0x1c]
	bl NNS_G3dGetTex
	ldr r1, [r0, #0x14]
	str r0, [sp, #0x18]
	add r0, r0, r1
	str r0, [sp, #0x14]
	mov r0, #0x3b
	add r1, r4, #0
	bl Heap_Alloc
	add r7, r0, #0
	mov r0, #0x66
	lsl r0, r0, #2
	ldrh r1, [r5, r0]
	ldr r0, _021E6E2C ; =0x0000FF9E
	add r0, r1, r0
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	cmp r0, #1
	str r6, [sp]
	bhi _021E6D8C
	mov r0, #6
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x14]
	mov r2, #0
	str r6, [sp, #4]
	add r0, r0, r1
	add r1, r6, #0
	add r3, r2, #0
	str r7, [sp, #8]
	bl sub_020145B4
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	add r2, r4, #0
	bl ov64_021E5AAC
	str r6, [sp]
	mov r2, #0
	str r6, [sp, #4]
	mov r0, #7
	add r1, r4, #0
	mul r1, r0
	ldr r0, [sp, #0x14]
	add r3, r2, #0
	add r0, r0, r1
	add r1, r6, #0
	str r7, [sp, #8]
	bl sub_020145B4
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	add r1, r1, r4
	add r2, r4, #0
	bl ov64_021E5AAC
	b _021E6DCE
_021E6D8C:
	ldr r0, [sp, #0x14]
	lsl r1, r4, #1
	mov r2, #0
	str r6, [sp, #4]
	add r0, r0, r1
	add r1, r6, #0
	add r3, r2, #0
	str r7, [sp, #8]
	bl sub_020145B4
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	add r2, r4, #0
	bl ov64_021E5AAC
	lsl r0, r4, #1
	add r1, r4, r0
	ldr r0, [sp, #0x14]
	str r6, [sp]
	mov r2, #0
	str r6, [sp, #4]
	add r0, r0, r1
	add r1, r6, #0
	add r3, r2, #0
	str r7, [sp, #8]
	bl sub_020145B4
	ldr r1, [sp, #0x2c]
	add r0, r7, #0
	add r1, r1, r4
	add r2, r4, #0
	bl ov64_021E5AAC
_021E6DCE:
	add r0, r7, #0
	bl Heap_Free
	ldr r1, [sp, #0x24]
	ldr r0, [sp, #0x28]
	ldr r0, [r1, r0]
	ldr r0, [r0]
	bl Sprite_GetPaletteProxy
	mov r1, #1
	bl NNS_G2dGetImagePaletteLocation
	add r6, r0, #0
	ldr r0, [sp, #0x18]
	ldr r1, [r0, #0x38]
	add r4, r0, r1
	mov r1, #0x65
	lsl r1, r1, #2
	ldr r0, [r5, r1]
	sub r1, r1, #4
	ldr r1, [r5, r1]
	bl CalcShininessByOtIdAndPersonality
	cmp r0, #0
	beq _021E6E02
	add r4, #0x20
_021E6E02:
	add r0, r4, #0
	add r1, r6, #0
	mov r2, #0x20
	bl ov64_021E5AE4
	ldr r0, [sp, #0x1c]
	bl Heap_Free
	add sp, #0x68
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6E18: .word 0x0000DCC2
_021E6E1C: .word 0x0000DCC1
_021E6E20: .word ov64_021E6FD4
_021E6E24: .word ov64_021E6ECC
_021E6E28: .word ov64_021E6ECE
_021E6E2C: .word 0x0000FF9E
	thumb_func_end ov64_021E6C1C
