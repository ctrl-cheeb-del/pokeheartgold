	.include "asm/macros.inc"
	.include "overlay_40.inc"
	.include "global.inc"
	.public BgClearTilemapBufferAndCommit
	.public GfGfxLoader_LoadCharDataFromOpenNarc
	.public GfGfx_EngineATogglePlanes
	.public GfGfx_EngineBTogglePlanes
	.public Heap_Alloc
	.public Heap_Free
	.public MI_CpuFill8
	.public ManagedSprite_SetAnim
	.public ManagedSprite_SetDrawFlag
	.public ManagedSprite_SetPaletteOverrideOffset
	.public PaletteData_BlendPalettes
	.public SetBgPriority
	.public SysTask_CreateOnMainQueue
	.public SysTask_Destroy
	.public TextOBJ_SetSpritesDrawFlag
	.public TouchHitboxController_Create
	.public _s32_div_f
	.public memset
	.public ov40_0222BF80
	.public ov40_0222BFB0
	.public ov40_0222C018
	.public ov40_0222C03C
	.public ov40_0222C4DC
	.public ov40_0222D288
	.public ov40_0222D294
	.public ov40_0222D3E8
	.public ov40_0222D874
	.public ov40_0222D9E8
	.public ov40_0222DA00
	.public ov40_0222DA84
	.public ov40_0222DAC0
	.public ov40_0222DBEC
	.public ov40_0222FB90
	.public ov40_02230410
	.public ov40_02230638
	.public ov40_022306A0
	.public ov40_022307DC
	.public ov40_02230964
	.public ov40_022318C8
	.public ov40_022319A4
	.public ov40_02231C78
	.public ov40_02231EA4
	.public ov40_02232094
	.public ov40_02232288
	.public ov40_022322E0
	.public ov40_02232470
	.public ov40_02232ED4
	.public ov40_02232F50
	.public ov40_02232F88
	.public ov40_02233044
	.public ov40_02245134
	.public sub_020136B4
	.public sub_0203088C
	.public sub_020878B8
	.text


	thumb_func_start ov40_022319A4
ov40_022319A4: ; 0x022319A4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r4, r0, #0
	ldr r1, [r4, #8]
	cmp r1, #0
	beq _022319BC
	cmp r1, #1
	beq _02231A9A
	cmp r1, #2
	bne _022319BA
	b _02231C24
_022319BA:
	b _02231C54
_022319BC:
	mov r0, #0x6d
	mov r1, #0x10
	bl Heap_Alloc
	str r0, [sp, #4]
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r1, #0x86
	ldr r0, [sp, #4]
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r7, #0
	str r7, [r0, #8]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	cmp r0, #0
	ble _02231A8C
	ldr r0, [sp, #4]
	add r6, r4, #0
	add r0, r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	str r0, [sp, #0x10]
	add r0, #0xc
	str r0, [sp, #0x10]
_022319F4:
	mov r0, #0x6d
	mov r1, #0x34
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x34
	add r5, r0, #0
	bl memset
	ldr r0, _02231C5C ; =0x000005FC
	add r1, r5, #0
	ldr r0, [r6, r0]
	add r2, r5, #2
	bl ov40_0222D294
	ldr r0, _02231C5C ; =0x000005FC
	ldr r0, [r6, r0]
	str r0, [r5, #0x20]
	mov r0, #0x61
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	str r0, [r5, #0x24]
	ldr r0, [sp, #0xc]
	str r0, [r5, #0x2c]
	ldr r0, [sp, #0x10]
	str r0, [r5, #0x30]
	ldr r0, _02231C60 ; =0x000006E4
	ldr r0, [r4, r0]
	cmp r7, r0
	bne _02231A4A
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	str r0, [r5, #0x28]
	mov r0, #0
	ldrsh r0, [r5, r0]
	strh r0, [r5, #4]
	mov r0, #0x2f
	mvn r0, r0
	strh r0, [r5, #6]
	mov r0, #8
	strb r0, [r5, #0x1c]
	b _02231A72
_02231A4A:
	mov r0, #0
	str r0, [r5, #0x28]
	ldrsh r0, [r5, r0]
	strh r0, [r5, #4]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r4, r0]
	mov r0, #5
	sub r0, r0, r1
	lsl r0, r0, #4
	add r0, #0xcd
	strh r0, [r5, #6]
	mov r0, #6
	ldrsh r0, [r5, r0]
	cmp r0, #0xdd
	blt _02231A6E
	mov r0, #0xdd
	strh r0, [r5, #6]
_02231A6E:
	mov r0, #8
	strb r0, [r5, #0x1c]
_02231A72:
	mov r2, #2
	ldr r0, _02231C64 ; =ov40_022318C8
	add r1, r5, #0
	lsl r2, r2, #0xc
	bl SysTask_CreateOnMainQueue
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r7, r7, #1
	add r6, #0x28
	cmp r7, r0
	blt _022319F4
_02231A8C:
	ldr r0, [sp, #4]
	mov r1, #0
	str r1, [r0]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02231C54
_02231A9A:
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	str r0, [sp, #8]
	ldr r0, [r0]
	cmp r0, #0x10
	beq _02231AC8
	add r1, r0, #2
	ldr r0, [sp, #8]
	ldr r3, [sp, #8]
	str r1, [r0]
	ldr r0, [r4, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r3]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
_02231AC8:
	ldr r0, [sp, #8]
	ldr r0, [r0, #0xc]
	cmp r0, #1
	beq _02231AD2
	b _02231BDC
_02231AD2:
	ldr r0, [sp, #8]
	mov r7, #0
	ldr r0, [r0, #8]
	cmp r0, #0
	bne _02231BD2
	ldr r0, [sp, #8]
	mov r1, #1
	str r1, [r0, #8]
	ldr r0, _02231C68 ; =0x00000534
	add r6, r4, #0
	add r0, r4, r0
	str r0, [sp, #0x18]
	ldr r0, [sp, #8]
	add r0, r0, #4
	str r0, [sp, #0x14]
_02231AF0:
	mov r0, #0x6d
	mov r1, #0x34
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x34
	add r5, r0, #0
	bl memset
	ldr r0, _02231C68 ; =0x00000534
	add r1, r5, #0
	ldr r0, [r6, r0]
	add r2, r5, #2
	bl ov40_0222D294
	ldr r0, _02231C68 ; =0x00000534
	ldr r0, [r6, r0]
	str r0, [r5, #0x20]
	ldr r0, _02231C6C ; =0x00000548
	ldr r0, [r6, r0]
	str r0, [r5, #0x24]
	ldr r0, [sp, #0x14]
	str r0, [r5, #0x2c]
	mov r0, #0
	str r0, [r5, #0x28]
	ldrsh r0, [r5, r0]
	strh r0, [r5, #4]
	ldr r0, _02231C70 ; =0x000006D8
	ldr r0, [r4, r0]
	cmp r0, r7
	bne _02231B98
	mov r0, #0
	ldrsh r0, [r5, r0]
	ldr r1, _02231C74 ; =0x00000818
	strh r0, [r5, #4]
	mov r0, #0xa9
	strh r0, [r5, #6]
	ldr r3, [r4, r1]
	ldr r1, _02231C60 ; =0x000006E4
	ldr r0, _02231C68 ; =0x00000534
	ldr r2, [r4, r1]
	mov r1, #0x24
	mul r1, r2
	add r1, r3, r1
	ldr r0, [r6, r0]
	ldr r1, [r1, #0xc]
	bl ManagedSprite_SetAnim
	ldr r0, _02231C60 ; =0x000006E4
	mov r2, #0x28
	ldr r1, [r4, r0]
	mov r0, #0x24
	add r3, r1, #0
	ldr r1, _02231C70 ; =0x000006D8
	mul r3, r0
	ldr r0, _02231C74 ; =0x00000818
	ldr r1, [r4, r1]
	ldr r0, [r4, r0]
	mul r2, r1
	ldr r1, [sp, #0x18]
	mov ip, r0
	add r1, r1, r2
	mov r2, ip
	add r3, r2, r3
	ldr r2, [r3, #8]
	add r0, r4, #0
	bl ov40_0222D3E8
	ldr r0, _02231C70 ; =0x000006D8
	ldr r1, [r4, r0]
	mov r0, #0x28
	mul r0, r1
	add r1, r4, r0
	ldr r0, _02231C6C ; =0x00000548
	ldr r0, [r1, r0]
	mov r1, #1
	bl TextOBJ_SetSpritesDrawFlag
	ldr r0, _02231C68 ; =0x00000534
	mov r1, #1
	ldr r0, [r6, r0]
	bl ManagedSprite_SetDrawFlag
	b _02231BB6
_02231B98:
	mov r0, #0
	ldrsh r0, [r5, r0]
	mov r1, #4
	sub r0, r0, #4
	strh r0, [r5, #4]
	ldr r0, _02231C70 ; =0x000006D8
	ldr r0, [r4, r0]
	sub r2, r0, r7
	lsl r0, r2, #4
	sub r2, r1, r2
	mov r1, #0x24
	mul r1, r2
	add r1, #0x19
	add r0, r0, r1
	strh r0, [r5, #6]
_02231BB6:
	mov r0, #4
	strb r0, [r5, #0x1c]
	mov r2, #2
	ldr r0, _02231C64 ; =ov40_022318C8
	add r1, r5, #0
	lsl r2, r2, #0xc
	bl SysTask_CreateOnMainQueue
	ldr r0, _02231C70 ; =0x000006D8
	add r7, r7, #1
	ldr r0, [r4, r0]
	add r6, #0x28
	cmp r7, r0
	ble _02231AF0
_02231BD2:
	ldr r0, [sp, #8]
	ldr r1, [r0, #0xc]
	str r1, [r0, #4]
	mov r1, #0
	str r1, [r0, #0xc]
_02231BDC:
	ldr r0, _02231C70 ; =0x000006D8
	mov r5, #0
	ldr r0, [r4, r0]
	cmp r0, #0
	ble _02231C0E
	ldr r7, _02231C68 ; =0x00000534
	add r6, r4, #0
_02231BEA:
	cmp r5, r0
	bne _02231BF8
	ldr r0, [r6, r7]
	mov r1, #1
	bl ManagedSprite_SetPaletteOverrideOffset
	b _02231C02
_02231BF8:
	ldr r0, _02231C68 ; =0x00000534
	mov r1, #2
	ldr r0, [r6, r0]
	bl ManagedSprite_SetPaletteOverrideOffset
_02231C02:
	ldr r0, _02231C70 ; =0x000006D8
	add r5, r5, #1
	ldr r0, [r4, r0]
	add r6, #0x28
	cmp r5, r0
	blt _02231BEA
_02231C0E:
	ldr r0, [sp, #8]
	ldr r0, [r0, #4]
	cmp r0, #0
	bne _02231C1C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02231C1C:
	ldr r0, [sp, #8]
	mov r1, #0
	str r1, [r0, #4]
	b _02231C54
_02231C24:
	ldr r1, _02231C74 ; =0x00000818
	ldr r3, [r4, r1]
	ldr r1, _02231C60 ; =0x000006E4
	ldr r2, [r4, r1]
	mov r1, #0x24
	mul r1, r2
	add r1, r3, r1
	ldr r1, [r1, #0x20]
	cmp r1, #0
	bne _02231C3E
	bl ov40_0222C03C
	b _02231C44
_02231C3E:
	mov r1, #5
	bl ov40_0222BF80
_02231C44:
	add r0, r4, #0
	bl ov40_0222BFB0
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl Heap_Free
_02231C54:
	mov r0, #0
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_02231C5C: .word 0x000005FC
_02231C60: .word 0x000006E4
_02231C64: .word ov40_022318C8
_02231C68: .word 0x00000534
_02231C6C: .word 0x00000548
_02231C70: .word 0x000006D8
_02231C74: .word 0x00000818
	thumb_func_end ov40_022319A4


	thumb_func_start ov40_02231C78
ov40_02231C78: ; 0x02231C78
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	ldr r1, [r5, #8]
	cmp r1, #0
	beq _02231C90
	cmp r1, #1
	beq _02231D52
	cmp r1, #2
	bne _02231C8E
	b _02231E38
_02231C8E:
	b _02231E72
_02231C90:
	mov r0, #0x6d
	mov r1, #0x10
	bl Heap_Alloc
	str r0, [sp, #8]
	mov r1, #0
	mov r2, #0x10
	bl MI_CpuFill8
	mov r1, #0x86
	ldr r0, [sp, #8]
	lsl r1, r1, #4
	str r0, [r5, r1]
	add r0, r0, #4
	str r0, [sp, #0xc]
	ldr r0, [sp, #8]
	mov r6, #0
	add r0, #0xc
	add r7, r5, #0
	str r0, [sp, #8]
_02231CB8:
	mov r0, #0x6d
	mov r1, #0x34
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x34
	add r4, r0, #0
	bl memset
	ldr r0, _02231E90 ; =0x00000534
	add r1, r4, #0
	ldr r0, [r7, r0]
	add r2, r4, #2
	bl ov40_0222D294
	ldr r0, _02231E90 ; =0x00000534
	ldr r0, [r7, r0]
	str r0, [r4, #0x20]
	ldr r0, _02231E94 ; =0x00000548
	ldr r0, [r7, r0]
	str r0, [r4, #0x24]
	ldr r0, [sp, #0xc]
	str r0, [r4, #0x2c]
	ldr r0, [sp, #8]
	str r0, [r4, #0x30]
	mov r0, #0
	str r0, [r4, #0x28]
	ldrsh r0, [r4, r0]
	strh r0, [r4, #4]
	ldr r0, _02231E98 ; =0x000006D8
	ldr r0, [r5, r0]
	sub r0, r0, #1
	cmp r0, r6
	bne _02231D0E
	mov r0, #0x6f
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	str r0, [r4, #0x28]
	mov r0, #0
	ldrsh r0, [r4, r0]
	strh r0, [r4, #4]
	mov r0, #0xd9
	b _02231D2A
_02231D0E:
	mov r0, #0
	ldrsh r0, [r4, r0]
	mov r1, #0x24
	add r0, r0, #4
	strh r0, [r4, #4]
	ldr r0, _02231E98 ; =0x000006D8
	ldr r0, [r5, r0]
	sub r2, r0, r6
	mov r0, #5
	sub r0, r0, r2
	mul r1, r0
	add r1, #0x1d
	lsl r0, r2, #4
	add r0, r1, r0
_02231D2A:
	strh r0, [r4, #6]
	mov r0, #4
	strb r0, [r4, #0x1c]
	mov r2, #2
	ldr r0, _02231E9C ; =ov40_022318C8
	add r1, r4, #0
	lsl r2, r2, #0xc
	bl SysTask_CreateOnMainQueue
	ldr r0, _02231E98 ; =0x000006D8
	add r6, r6, #1
	ldr r0, [r5, r0]
	add r7, #0x28
	sub r0, r0, #1
	cmp r6, r0
	ble _02231CB8
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	b _02231E88
_02231D52:
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	str r0, [sp, #4]
	ldr r0, [r0, #0xc]
	cmp r0, #1
	bne _02231E36
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r7, #0
	cmp r0, #0
	ble _02231DF2
	ldr r0, [sp, #4]
	add r6, r5, #0
	add r0, r0, #4
	str r0, [sp, #0x10]
	ldr r0, [sp, #4]
	str r0, [sp, #0x14]
	add r0, #0xc
	str r0, [sp, #0x14]
_02231D7C:
	mov r0, #0x6d
	mov r1, #0x34
	bl Heap_Alloc
	mov r1, #0
	mov r2, #0x34
	add r4, r0, #0
	bl memset
	ldr r0, _02231EA0 ; =0x000005FC
	add r1, r4, #0
	ldr r0, [r6, r0]
	add r2, r4, #2
	bl ov40_0222D294
	ldr r0, _02231EA0 ; =0x000005FC
	ldr r0, [r6, r0]
	str r0, [r4, #0x20]
	mov r0, #0x61
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	str r0, [r4, #0x24]
	ldr r0, [sp, #0x10]
	str r0, [r4, #0x2c]
	ldr r0, [sp, #0x14]
	str r0, [r4, #0x30]
	mov r0, #0
	str r0, [r4, #0x28]
	ldrsh r0, [r4, r0]
	strh r0, [r4, #4]
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r1, [r5, r0]
	mov r0, #5
	sub r0, r0, r1
	lsl r0, r0, #4
	add r0, #0xcd
	strh r0, [r4, #6]
	mov r0, #6
	ldrsh r0, [r4, r0]
	cmp r0, #0xdd
	blt _02231DD4
	mov r0, #0xdd
	strh r0, [r4, #6]
_02231DD4:
	mov r0, #8
	strb r0, [r4, #0x1c]
	mov r2, #2
	ldr r0, _02231E9C ; =ov40_022318C8
	add r1, r4, #0
	lsl r2, r2, #0xc
	bl SysTask_CreateOnMainQueue
	mov r0, #0x6e
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	add r7, r7, #1
	add r6, #0x28
	cmp r7, r0
	blt _02231D7C
_02231DF2:
	ldr r0, [sp, #4]
	mov r4, #0
	str r4, [r0]
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
	ldr r0, _02231E98 ; =0x000006D8
	ldr r1, [r5, r0]
	sub r1, r1, #1
	str r1, [r5, r0]
	ldr r0, [r5, r0]
	cmp r0, #0
	ble _02231E88
	ldr r7, _02231E90 ; =0x00000534
	add r6, r5, #0
_02231E10:
	sub r0, r0, #1
	cmp r4, r0
	bne _02231E20
	ldr r0, [r6, r7]
	mov r1, #1
	bl ManagedSprite_SetPaletteOverrideOffset
	b _02231E2A
_02231E20:
	ldr r0, _02231E90 ; =0x00000534
	mov r1, #2
	ldr r0, [r6, r0]
	bl ManagedSprite_SetPaletteOverrideOffset
_02231E2A:
	ldr r0, _02231E98 ; =0x000006D8
	add r4, r4, #1
	ldr r0, [r5, r0]
	add r6, #0x28
	cmp r4, r0
	blt _02231E10
_02231E36:
	b _02231E88
_02231E38:
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r4, [r5, r0]
	ldr r0, [r4]
	cmp r0, #0x10
	beq _02231E60
	add r0, r0, #2
	str r0, [r4]
	ldr r0, [r5, #0x58]
	mov r1, #2
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4]
	ldr r0, [r5, #0x28]
	lsl r3, r3, #0x18
	mov r2, #0xc
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
_02231E60:
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _02231E6C
	ldr r0, [r5, #8]
	add r0, r0, #1
	str r0, [r5, #8]
_02231E6C:
	mov r0, #0
	str r0, [r4, #4]
	b _02231E88
_02231E72:
	bl ov40_0222C018
	mov r0, #0x86
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	bl Heap_Free
	add r0, r5, #0
	mov r1, #5
	bl ov40_0222BF80
_02231E88:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02231E90: .word 0x00000534
_02231E94: .word 0x00000548
_02231E98: .word 0x000006D8
_02231E9C: .word ov40_022318C8
_02231EA0: .word 0x000005FC
	thumb_func_end ov40_02231C78


	thumb_func_start ov40_02231EA4
ov40_02231EA4: ; 0x02231EA4
	push {r3, r4, lr}
	sub sp, #4
	add r4, r0, #0
	ldr r0, [r4, #8]
	cmp r0, #4
	bls _02231EB2
	b _02232080
_02231EB2:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02231EBE: ; jump table
	.short _02231EC8 - _02231EBE - 2 ; case 0
	.short _02231EF8 - _02231EBE - 2 ; case 1
	.short _02231F6E - _02231EBE - 2 ; case 2
	.short _02231FF2 - _02231EBE - 2 ; case 3
	.short _0223200A - _02231EBE - 2 ; case 4
_02231EC8:
	mov r0, #0
	str r0, [r4, #0x54]
	add r0, r4, #0
	add r0, #0x5c
	ldrb r0, [r0]
	cmp r0, #0
	beq _02231EE0
	add r0, r4, #0
	add r0, #0x5c
	ldrb r0, [r0]
	sub r1, r0, #1
	b _02231EE2
_02231EE0:
	mov r1, #6
_02231EE2:
	add r0, r4, #0
	add r0, #0x5c
	strb r1, [r0]
	add r0, r4, #0
	bl ov40_0222DAC0
	str r0, [r4, #0x58]
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232088
_02231EF8:
	add r0, r4, #0
	add r0, #0x54
	mov r1, #1
	bl ov40_0222DA84
	cmp r0, #0
	beq _02231F0C
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_02231F0C:
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #0
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #3
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02232088
_02231F6E:
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r1, r4, #0
	add r1, #0x5c
	ldrb r1, [r1]
	add r0, r4, #0
	bl ov40_0222DBEC
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #0
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #3
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232088
_02231FF2:
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
	b _02232088
_0223200A:
	add r0, r4, #0
	add r0, #0x54
	mov r1, #0
	bl ov40_0222DA84
	cmp r0, #0
	beq _0223201E
	ldr r0, [r4, #8]
	add r0, r0, #1
	str r0, [r4, #8]
_0223201E:
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #2
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #0
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #3
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	ldr r0, [r4, #0x58]
	ldr r2, _02232090 ; =0x0000FFFF
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp]
	ldr r3, [r4, #0x54]
	ldr r0, [r4, #0x28]
	lsl r3, r3, #0x18
	mov r1, #1
	lsr r3, r3, #0x18
	bl PaletteData_BlendPalettes
	b _02232088
_02232080:
	add r0, r4, #0
	mov r1, #0
	bl ov40_0222BF80
_02232088:
	mov r0, #0
	add sp, #4
	pop {r3, r4, pc}
	nop
_02232090: .word 0x0000FFFF
	thumb_func_end ov40_02231EA4
