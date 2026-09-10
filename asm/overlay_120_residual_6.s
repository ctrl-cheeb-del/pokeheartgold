	.include "asm/macros.inc"
	.include "overlay_120.inc"
	.include "global.inc"

	.public ov120_022601BC
	.public ov120_022601D8
	.public ov120_022601F4
	.public ov120_022601F8
	.public ov120_022601FC
	.public ov120_02260200
	.public ov120_022602E4
	.public ov120_022602FC
	.public ov120_02260314
	.public ov120_0226032C

	.public _0226019C

	.text
	.public ov120_0225F020
	.public ov120_0225F038
	.public ov120_0225F040
	.public ov120_0225F08C
	.public ov120_0225F0FC
	.public ov120_0225F118
	.public ov120_0225F120
	.public ov120_0225F14C
	.public ov120_0225F1E8
	.public ov120_0225F240
	.public ov120_0225F268
	.public ov120_0225F294
	.public ov120_0225F2B8
	.public ov120_0225F318
	.public ov120_0225F4DC
	.public ov120_0225F6AC
	.public ov120_0225F6BC
	.public ov120_0225F6FC
	.public ov120_0225F704
	.public ov120_0225F714
	.public ov120_0225F8B0
	.public ov120_0225F90C
	.public ov120_0225F970
	.public ov120_0225F9D4
	.public ov120_0225FA5C
	.public ov120_0225FA68
	.public ov120_0225FA74
	.public ov120_0225FBAC
	.public ov120_0225FBB8
	.public ov120_0225FBC4
	.public ov120_0225FCFC
	.public ov120_0225FD08
	.public ov120_0225FD14
	.public ov120_0225FD2C
	.public ov120_0225FDA0
	.public ov120_0225FE08
	.public ov120_0225FECC
	.public ov120_0225FEE8
	.public ov120_0225FF00
	thumb_func_start ov120_0225FD2C
ov120_0225FD2C: ; 0x0225FD2C
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #4
	add r4, r3, #0
	str r0, [sp]
	add r0, r1, #0
	add r1, r2, #0
	mov r2, #0
	add r3, sp, #0xc
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	ldr r2, [sp, #0xc]
	mov r3, #0
	lsl r1, r4, #0x18
	str r3, [sp]
	add r6, r0, #0
	ldrh r0, [r2]
	lsr r1, r1, #0x18
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	ldrh r0, [r2, #2]
	add r2, #0xc
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	bl LoadRectToBgTilemapRect
	ldr r1, [sp, #0xc]
	mov r2, #0
	ldrh r0, [r1]
	add r3, r2, #0
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp]
	ldrh r0, [r1, #2]
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	lsl r0, r0, #0x15
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	add r0, r5, #0
	str r2, [sp, #8]
	bl BgTilemapRectChangePalette
	add r0, r6, #0
	bl Heap_Free
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov120_0225FD2C

