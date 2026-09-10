	.include "asm/macros.inc"
	.include "overlay_95.inc"
	.include "global.inc"
	.public HatchEggApp_Exit
	.public HatchEggApp_Init
	.public HatchEggApp_Main
	.public ov95_021E5954
	.public ov95_021E5974
	.public ov95_021E59F8
	.public ov95_021E5A38
	.public ov95_021E5BBC
	.public ov95_021E5C44
	.public ov95_021E5CAC
	.public ov95_021E5D44
	.public ov95_021E5D98
	.public ov95_021E5DB4
	.public ov95_021E5DD0
	.public ov95_021E5E18
	.public ov95_021E5E90
	.public ov95_021E5EC0
	.public ov95_021E5EF8
	.public ov95_021E6000
	.public ov95_021E60A4
	.public ov95_021E619C
	.public ov95_021E623C
	.public ov95_021E62A4
	.public ov95_021E6314
	.public ov95_021E65A0
	.public ov95_021E6838
	.public ov95_021E68A8
	.public ov95_021E6900
	.public ov95_021E6964
	.public ov95_021E6B74
	.public ov95_021E7020
	.public ov95_021E70BC
	.public ov95_021E7258
	.public ov95_021E7308
	.public ov95_021E7328
	.public ov95_021E7388
	.public ov95_021E7410
	.public ov95_021E7450
	.public ov95_021E7538
	.public ov95_021E7548
	.public ov95_021E755C
	.public ov95_021E7574
	.public ov95_021E7594
	.public ov95_021E75B4
	.public ov95_021E75DC
	.public ov95_021E762C
	.public ov95_021E767C
	.public ov95_021E76D0
	.public ov95_021E7770
	.public ov95_021E7810
	.public ov95_021E7818
	.public ov95_021E7820
	.public ov95_021E782C
	.public ov95_021E7860


	.text
	.public ov95_021E5900
	.public ov95_021E5928
	.public ov95_021E5B24
	.public ov95_021E5B58
	.public ov95_021E5B7C
	.public ov95_021E5B9C
	.public ov95_021E5D34
	.public ov95_021E5E40
	.public ov95_021E5E58
	.public ov95_021E5EDC
	.public ov95_021E5EF0
	.public ov95_021E6150
	.public ov95_021E6184
	.public ov95_021E6228
	.public ov95_021E62E4
	.public ov95_021E62F0
	.public ov95_021E6300
	.public ov95_021E67F0
	.public ov95_021E6FC4
	.public ov95_021E7078
	.public ov95_021E7208
	.public ov95_021E72B8
	.public ov95_021E7404
	.public ov95_021E7514

	thumb_func_start ov95_021E7258
ov95_021E7258: ; 0x021E7258
	push {r4, lr}
	add r4, r0, #0
	ldrb r1, [r4, #0x18]
	cmp r1, #0
	beq _021E7268
	cmp r1, #1
	beq _021E7278
	b _021E72AE
_021E7268:
	bl ov95_021E7450
	cmp r0, #0
	beq _021E72B2
	ldrb r0, [r4, #0x18]
	add r0, r0, #1
	strb r0, [r4, #0x18]
	b _021E72B2
_021E7278:
	bl ov95_021E7514
	cmp r0, #0
	beq _021E72B2
	ldrb r0, [r4, #0x19]
	cmp r0, #0
	bne _021E728A
	bl GF_AssertFail
_021E728A:
	mov r0, #5
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #0
	bl ToggleBgLayer
	ldr r0, [r4, #0x10]
	mov r1, #0
	bl ManagedSprite_SetDrawFlag
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	ldrb r0, [r4, #0x19]
	pop {r4, pc}
_021E72AE:
	bl GF_AssertFail
_021E72B2:
	mov r0, #0
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov95_021E7258
