	.include "asm/macros.inc"
	.include "overlay_82.inc"
	.include "global.inc"

	.text
	.public _0223FE20
	.public ov82_0223DD60
	.public ov82_0223DE20
	.public ov82_0223DF74
	.public ov82_0223DFBC
	.public ov82_0223E070
	.public ov82_0223E0B0
	.public ov82_0223E140
	.public ov82_0223E2A4
	.public ov82_0223E2EC
	.public ov82_0223E5D4
	.public ov82_0223E820
	.public ov82_0223E888
	.public ov82_0223E8C4
	.public ov82_0223E974
	.public ov82_0223E9E8
	.public ov82_0223EB3C
	.public ov82_0223EBB8
	.public ov82_0223EC0C
	.public ov82_0223EC68
	.public ov82_0223ED94
	.public ov82_0223EDF0
	.public ov82_0223EE6C
	.public ov82_0223EECC
	.public ov82_0223EF1C
	.public ov82_0223EFCC
	.public ov82_0223F040
	.public ov82_0223F134
	.public ov82_0223F1AC
	.public ov82_0223F224
	.public ov82_0223F300
	.public ov82_0223F488
	.public ov82_0223F5E0
	.public ov82_0223F84C
	.public ov82_0223F95C
	.public ov82_0223FB08
	.public ov82_0223FBBC
	.public ov82_0223FC48
	.public ov82_0223FDC8
	.public ov82_0223FE28
	.public ov82_0223FE38
	.public ov82_0223FE54
	.public ov82_0223FE70
	.public ov82_0223FE8C
	.public ov82_0223FEA8
	.public ov82_0223FEC4
	.public ov82_0223FEEC
	.public ov82_0223FEF0
	.public ov82_0223FF00
	.public ov82_0223E7E8
	.public ov82_0223E9B0
	.public ov82_0223EB9C
	.public ov82_0223EC48
	.public ov82_0223EE38
	.public ov82_0223EF7C
	.public ov82_0223EFB4
	.public ov82_0223F10C
	.public ov82_0223F2F8
	.public ov82_0223F53C
	.public ov82_0223F558
	.public ov82_0223F570
	.public ov82_0223F580
	.public ov82_0223F6C4
	.public ov82_0223F6CC
	.public ov82_0223F6E4
	.public ov82_0223F6E8
	.public ov82_0223F74C
	.public ov82_0223F764
	.public ov82_0223F770
	.public ov82_0223F7B4
	.public ov82_0223F808
	.public ov82_0223F814
	.public ov82_0223F834
	.public ov82_0223F8E4
	.public ov82_0223F90C
	.public ov82_0223F948
	.public ov82_0223FC14
	.public ov82_0223FC9C
	.public ov82_0223FCB0
	.public ov82_0223FCBC
	.public ov82_0223FCFC
	.public ov82_0223FD18
	.public ov82_0223FD2C
	.public ov82_0223FD5C
	.public ov82_0223FD78
	.public ov82_0223FDB8
	.public ov82_0223FDC0
	.public ov82_0223FE18

	thumb_func_start ov82_0223EBB8
ov82_0223EBB8: ; 0x0223EBB8
	push {r4, lr}
	mov r2, #1
	lsl r2, r2, #0x1a
	add r4, r0, #0
	ldr r1, [r2]
	ldr r0, _0223EC08 ; =0xFFFF1FFF
	and r0, r1
	str r0, [r2]
	mov r0, #0x1f
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	mov r0, #0x1f
	mov r1, #0
	bl GfGfx_EngineBTogglePlanes
	add r0, r4, #0
	mov r1, #3
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #1
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #0
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #5
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #4
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	bl Heap_Free
	pop {r4, pc}
	.balign 4, 0
_0223EC08: .word 0xFFFF1FFF
	thumb_func_end ov82_0223EBB8


	thumb_func_start ov82_0223EC0C
ov82_0223EC0C: ; 0x0223EC0C
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #0
	bne _0223EC3E
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	cmp r0, #0
	beq _0223EC24
	bl PaletteData_PushTransparentBuffers
_0223EC24:
	ldr r0, [r4, #0x48]
	bl DoScheduledBgGpuUpdates
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r3, _0223EC40 ; =0x027E0000
	ldr r1, _0223EC44 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
_0223EC3E:
	pop {r4, pc}
	.balign 4, 0
_0223EC40: .word 0x027E0000
_0223EC44: .word 0x00003FF8
	thumb_func_end ov82_0223EC0C
