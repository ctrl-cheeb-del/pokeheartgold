	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BeginNormalPaletteFade
	.public BgClearTilemapBufferAndCommit
	.public GfGfxLoader_LoadScrnDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Free
	.public IsPaletteFadeFinished
	.public PaletteData_BlendPalettes
	.public SaveGameNormal
	.public Save_NumModifiedPCBoxesIsMany
	.public TouchHitboxController_Create
	.public TouchHitboxController_Destroy
	.public TouchscreenHitbox_TouchNewIsIn
	.public ov40_0222BF64
	.public ov40_0222BF80
	.public ov40_0222C4B8
	.public ov40_0222C4E8
	.public ov40_0222D88C
	.public ov40_0222D8C8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAA8
	.public ov40_0222DD08
	.public ov40_0222DED0
	.public ov40_0222DF60
	.public ov40_0222DFB0
	.public ov40_0222E7B8
	.public ov40_0222FB90
	.public ov40_0222FBB4
	.public ov40_0222FCCC
	.public ov40_0222FDC4
	.public ov40_02230410
	.public ov40_02230638
	.public ov40_0223064C
	.public ov40_022306A0
	.public ov40_022307DC
	.public ov40_02230944
	.public ov40_02230964
	.public ov40_022326DC
	.public ov40_022327BC
	.public ov40_022327F0
	.public ov40_02232A48
	.public ov40_02232AF8
	.public ov40_02232BD8
	.public ov40_02232D44
	.public ov40_02232ED4
	.public ov40_02232F50
	.public ov40_02232F88
	.public ov40_02232FCC
	.public ov40_02233044
	.public ov40_022330B8
	.public ov40_02244BBC
	.public ov40_0224512C
	.public ov40_02245130
	.public ov40_02245134
	.public sub_0202FC24
	.public sub_0202FC90
	.public sub_0203088C
	.public sub_02087A84
	.text

	thumb_func_start ov40_022327F0
ov40_022327F0: ; 0x022327F0
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	mov r1, #0x86
	lsl r1, r1, #4
	ldr r2, [r4, #8]
	ldr r5, [r4, r1]
	cmp r2, #7
	bls _02232804
	b _02232A0E
_02232804:
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_02232810: ; jump table
	.short _02232820 - _02232810 - 2 ; case 0
	.short _0223287C - _02232810 - 2 ; case 1
	.short _022328CC - _02232810 - 2 ; case 2
	.short _0223290A - _02232810 - 2 ; case 3
	.short _02232954 - _02232810 - 2 ; case 4
	.short _022329B2 - _02232810 - 2 ; case 5
	.short _022329C2 - _02232810 - 2 ; case 6
	.short _022329D4 - _02232810 - 2 ; case 7
_02232820:
	mov r0, #0x5d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl TouchHitboxController_Destroy
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	mov r0, #4
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	ldr r0, [r5, #0xc]
	cmp r0, #0
	bne _02232854
	add r0, r5, #0
	add r0, #0x9c
	add r1, r4, #0
	bl ov40_0223064C
	b _0223285E
_02232854:
	add r0, r5, #0
	add r0, #0x10
	add r1, r4, #0
	bl ov40_0222E7B8
_0223285E:
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_02232FCC
	mov r0, #0x66
	mov r1, #0
	lsl r0, r0, #2
	str r1, [r5, r0]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232A30
_0223287C:
	add r0, r5, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #0
	bl ov40_0222DA00
	cmp r0, #0
	beq _022328B2
	add r0, r4, #0
	mov r1, #1
	bl ov40_02230964
	add r0, r4, #0
	bl ov40_022330B8
	add r0, r4, #0
	mov r1, #0
	bl ov40_02230964
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_022328B2:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02232A30
_022328CC:
	bl ov40_022326DC
	mov r1, #0x4a
	add r0, r4, #0
	lsl r1, r1, #2
	bl ov40_0222DED0
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x6d
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x14]
	ldr r2, [r4, #0x24]
	mov r1, #0x54
	mov r3, #7
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #8
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232A30
_0223290A:
	add r0, r5, #0
	add r0, #8
	mov r1, #0
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #0
	mov r3, #2
	bl ov40_0222DA00
	cmp r0, #0
	beq _0223293A
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223293A:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02232A30
_02232954:
	ldr r0, _02232A38 ; =ov40_0224512C
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _02232994
	mov r0, #0x66
	mov r1, #1
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r0, r4, #0
	bl ov40_02230944
	mov r0, #0x83
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Save_NumModifiedPCBoxesIsMany
	cmp r0, #0
	beq _02232984
	ldr r1, _02232A3C ; =0x0000012A
	add r0, r4, #0
	bl ov40_0222DF60
	b _0223298C
_02232984:
	ldr r1, _02232A40 ; =0x0000012B
	add r0, r4, #0
	bl ov40_0222DF60
_0223298C:
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232A30
_02232994:
	ldr r0, _02232A44 ; =ov40_02245130
	bl TouchscreenHitbox_TouchNewIsIn
	cmp r0, #0
	beq _02232A30
	mov r0, #0x66
	mov r1, #2
	lsl r0, r0, #2
	str r1, [r5, r0]
	add r0, r4, #0
	bl ov40_02230944
	mov r0, #6
	str r0, [r4, #8]
	b _02232A30
_022329B2:
	sub r1, #0x30
	ldr r0, [r4, r1]
	bl SaveGameNormal
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232A30
_022329C2:
	bl ov40_0222DFB0
	add r0, r4, #0
	bl ov40_022327BC
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232A30
_022329D4:
	add r0, r5, #0
	add r0, #8
	mov r1, #1
	bl ov40_0222DA84
	add r0, r5, #0
	add r1, r5, #4
	mov r2, #1
	mov r3, #2
	bl ov40_0222DA00
	cmp r0, #0
	beq _022329F4
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_022329F4:
	ldr r0, [r4, #0x58]
	mov r1, #3
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r5, #8]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02232A30
_02232A0E:
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r1, [r5, r0]
	cmp r1, #1
	bne _02232A22
	add r0, r4, #0
	mov r1, #7
	bl ov40_0222BF80
	b _02232A30
_02232A22:
	mov r1, #0
	str r1, [r5, r0]
	str r1, [r5, #0xc]
	add r0, r4, #0
	mov r1, #2
	bl ov40_0222BF80
_02232A30:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, pc}
	nop
_02232A38: .word ov40_0224512C
_02232A3C: .word 0x0000012A
_02232A40: .word 0x0000012B
_02232A44: .word ov40_02245130
	thumb_func_end ov40_022327F0
