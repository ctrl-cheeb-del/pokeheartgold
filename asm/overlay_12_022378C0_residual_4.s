#include "config.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_12_022378C0.inc"
	.include "global.inc"

	.text
	.public _0226BFD8
	.public ov12_02237D00
	.public ov12_02237ED0
	.public ov12_02237F18
	.public ov12_02238358
	.public ov12_0223843C
	.public ov12_022387AC
	.public ov12_022389B8
	.public ov12_02238A68
	.public ov12_02239664
	.public ov12_02239730
	.public ov12_022397E4
	.public ov12_02239854
	.public ov12_022399D4
	.public ov12_02239C28
	.public ov12_0223A0D4
	.public ov12_0223A260
	.public ov12_0223A3F0
	.public ov12_0223A664
	.public ov12_0226BFDC
	.public ov12_0226BFE0
	.public ov12_0226BFE8
	.public ov12_0226BFF8
	.public ov12_0226C008
	.public ov12_0226C018
	.public ov12_0226C02C
	.public ov12_0226C044
	.public ov12_0226C060
	.public ov12_0226C080
	.public ov12_0226C0A8
	.public ov12_0226C0D0
	.public ov12_0226C0F8
	.public ov12_0226C120
	.public ov12_0226C174
	.public ov12_0226C1C8
	.public ov12_0226C2DC

	.public ov12_02238A30
	.public ov12_02238A64
	.public ov12_022395BC
	.public ov12_02239644
	.public ov12_022396E8
	.public ov12_022396F0
	.public ov12_02239810
	.public ov12_0223998C
	.public ov12_022399BC
	.public ov12_0223A088
	.public ov12_0223A218
	.public ov12_0223A3A8
	.public ov12_0223A5E4
	.public ov12_0223A620
	.public ov12_0223A7A0

	thumb_func_start ov12_02239730
ov12_02239730: ; 0x02239730
	push {r3, r4, r5, lr}
	sub sp, #0x50
	ldr r1, _022397C8 ; =0x000023FF
	add r4, r0, #0
	ldrb r2, [r4, r1]
	lsl r0, r2, #0x1f
	lsr r0, r0, #0x1f
	beq _02239750
	mov r0, #1
	bic r2, r0
	strb r2, [r4, r1]
	ldr r0, _022397CC ; =0x04000050
	mov r1, #0
	strh r1, [r0]
	ldr r0, _022397D0 ; =0x04001050
	strh r1, [r0]
_02239750:
	ldr r1, _022397C8 ; =0x000023FF
	ldrb r2, [r4, r1]
	lsl r0, r2, #0x1e
	lsr r0, r0, #0x1f
	beq _02239774
	mov r0, #2
	bic r2, r0
	strb r2, [r4, r1]
	ldr r5, _022397D4 ; =ov12_0226C0D0
	add r3, sp, #0x28
	mov r2, #5
_02239766:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _02239766
	add r0, sp, #0x28
	bl GfGfx_SetBanks
_02239774:
	ldr r1, _022397C8 ; =0x000023FF
	ldrb r2, [r4, r1]
	lsl r0, r2, #0x1d
	lsr r0, r0, #0x1f
	beq _02239798
	mov r0, #4
	bic r2, r0
	strb r2, [r4, r1]
	ldr r5, _022397D8 ; =ov12_0226C0F8
	add r3, sp, #0
	mov r2, #5
_0223978A:
	ldmia r5!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0223978A
	add r0, sp, #0
	bl GfGfx_SetBanks
_02239798:
	add r0, r4, #0
	add r0, #0x88
	ldr r0, [r0]
	bl PokepicManager_HandleLoadImgAndOrPltt
	bl GF_RunVramTransferTasks
	bl SpriteSystem_TransferOam
	ldr r0, [r4, #0x28]
	bl PaletteData_PushTransparentBuffers
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _022397DC ; =0x027E0000
	ldr r1, _022397E0 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	add sp, #0x50
	pop {r3, r4, r5, pc}
	nop
_022397C8: .word 0x000023FF
_022397CC: .word 0x04000050
_022397D0: .word 0x04001050
_022397D4: .word ov12_0226C0D0
_022397D8: .word ov12_0226C0F8
_022397DC: .word 0x027E0000
_022397E0: .word 0x00003FF8
	thumb_func_end ov12_02239730


	thumb_func_start ov12_022397E4
ov12_022397E4: ; 0x022397E4
	push {r4, lr}
	add r4, r0, #0
	ldr r0, [r4, #0xc]
	bl PaletteData_PushTransparentBuffers
	bl GF_RunVramTransferTasks
	ldr r0, [r4, #4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _02239808 ; =0x027E0000
	ldr r1, _0223980C ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r4, pc}
	nop
_02239808: .word 0x027E0000
_0223980C: .word 0x00003FF8
	thumb_func_end ov12_022397E4
