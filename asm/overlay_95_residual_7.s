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

	thumb_func_start ov95_021E623C
ov95_021E623C: ; 0x021E623C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x4c
	add r5, r0, #0
	ldr r0, [r5]
	mov r1, #5
	ldr r4, [r0, #0xc]
	mov r2, #0
	add r0, r4, #0
	bl GetMonData
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #2
	bl sub_0207083C
	add r7, r0, #0
	mov r0, #0
	str r0, [sp, #0x10]
	add r0, r4, #0
	mov r1, #0x4c
	add r2, sp, #0x10
	bl SetMonData
	add r0, sp, #0x3c
	add r1, r4, #0
	mov r2, #2
	bl GetPokemonSpriteCharAndPlttNarcIds
	lsl r2, r6, #0x10
	ldr r0, [r5, #0x40]
	add r1, sp, #0x14
	lsr r2, r2, #0x10
	mov r3, #1
	bl NARC_ReadPokepicAnimScript
	mov r1, #0
	str r1, [sp]
	add r7, #0x60
	str r1, [sp, #4]
	add r0, sp, #0x14
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	ldr r0, [r5, #0x3c]
	add r1, sp, #0x3c
	mov r2, #0x80
	add r3, r7, #0
	bl PokepicManager_CreatePokepic
	str r0, [r5, #0x70]
	add sp, #0x4c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov95_021E623C


	thumb_func_start ov95_021E62A4
ov95_021E62A4: ; 0x021E62A4
	push {r4, r5, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, [r5]
	mov r1, #5
	ldr r0, [r0, #0xc]
	mov r2, #0
	bl GetMonData
	add r4, r0, #0
	ldr r0, [r5]
	ldr r0, [r0, #0xc]
	bl GetMonNature
	ldr r0, [r5, #0x70]
	mov r1, #1
	bl Pokepic_StartAnim
	mov r0, #2
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r3, r4, #0x10
	ldr r0, [r5, #0x40]
	ldr r1, [r5, #0x58]
	ldr r2, [r5, #0x70]
	lsr r3, r3, #0x10
	bl sub_0207294C
	add sp, #0xc
	pop {r4, r5, pc}
	thumb_func_end ov95_021E62A4
