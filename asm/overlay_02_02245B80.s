#include "constants/abilities.h"
#include "constants/species.h"
#include "constants/sndseq.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/std_script.h"
	.include "asm/macros.inc"
	.public ov02_02245B80
	.public ov02_02245B9C
	.public ov02_02245BC8
	.public ov02_02245D18
	.public ov02_02245DB0
	.public ov02_02245DE0
	.public ov02_02245E04
	.public ov02_02245E68
	.public ov02_02245ED8
	.public ov02_02245FD0
	.public ov02_02246048
	.public ov02_022460AC
	.public ov02_022460CC
	.public ov02_022460FC
	.public ShowLegendaryWing
	.public ov02_022461AC
	.public ov02_022461DC
	.public ov02_022462DC
	.public ov02_022462E8
	.public ov02_02246304
	.public ov02_02246330
	.public ov02_02246398
	.public ov02_02246444
	.public ov02_02246490
	.public ov02_0224650C
	.public ov02_02246534
	.public ov02_02246548
	.public ov02_0224662C
	.public ov02_0224663C
	.public ov02_02246714
	.public ov02_02246744
	.public ov02_02246798
	.public OpenAlphHiddenRoom
	.public ov02_022467E8
	.public ov02_02246818
	.public ov02_0224686C
	.public ov02_02246964
	.public ov02_022469A0
	.public ov02_022469B4
	.public ov02_022469D8
	.public ov02_02246A34
	.public ov02_0225321C
	.public ov02_0225321E
	.public ov02_02253222
	.public ov02_02253228
	.public ov02_0225322E
	.public ov02_02253234
	.public ov02_0225323A
	.public ov02_02253240
	.public ov02_02253246
	.public ov02_0225324C
	.public ov02_02253254
	.public ov02_02253264
	.public ov02_02253D80
	.public ov02_02253D84
	.include "overlay_02.inc"
	.include "global.inc"

	.text

	thumb_func_start ov02_02245BC8
ov02_02245BC8: ; 0x02245BC8
	push {r3, r4, lr}
	sub sp, #0xc
	bl TaskManager_GetEnvironment
	add r4, r0, #0
	ldrh r1, [r4, #8]
	cmp r1, #4
	bls _02245BDA
	b _02245D06
_02245BDA:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_02245BE6: ; jump table
	.short _02245BF0 - _02245BE6 - 2 ; case 0
	.short _02245C06 - _02245BE6 - 2 ; case 1
	.short _02245C98 - _02245BE6 - 2 ; case 2
	.short _02245CB0 - _02245BE6 - 2 ; case 3
	.short _02245CF2 - _02245BE6 - 2 ; case 4
_02245BF0:
	bl ov02_02245D18
	mov r1, #0
	add r0, r4, #0
	strh r1, [r4, #0xa]
	add r0, #0xcc
	str r1, [r0]
	ldrh r0, [r4, #8]
	add r0, r0, #1
	strh r0, [r4, #8]
	b _02245D06
_02245C06:
	add r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0xff
	beq _02245C68
	cmp r0, #0
	beq _02245C26
	cmp r0, #0x1e
	beq _02245C26
	cmp r0, #0x32
	beq _02245C26
	cmp r0, #0x3c
	beq _02245C26
	cmp r0, #0x46
	beq _02245C26
	cmp r0, #0x50
	bne _02245C5A
_02245C26:
	ldr r0, _02245D0C ; =SEQ_SE_DP_FW411
	bl PlaySE
	add r0, r4, #0
	add r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0x32
	bne _02245C3C
	ldr r0, _02245D10 ; =SEQ_SE_DP_F207
	bl PlaySE
_02245C3C:
	add r0, r4, #0
	add r0, #0xcc
	ldr r0, [r0]
	cmp r0, #0x3c
	blt _02245C5A
	mov r1, #0xa
	bl _s32_div_f
	add r1, r0, #0
	sub r1, r1, #5
	lsl r1, r1, #0x16
	ldr r0, _02245D0C ; =SEQ_SE_DP_FW411
	asr r1, r1, #0x10
	bl PlaySE_SetPitch
_02245C5A:
	add r0, r4, #0
	add r0, #0xcc
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xcc
	str r1, [r0]
_02245C68:
	add r0, r4, #0
	bl ov02_02245DE0
	ldrh r1, [r4, #0xa]
	add r0, r1, #1
	strh r0, [r4, #0xa]
	cmp r1, #0x5a
	blo _02245D06
	mov r0, #0x18
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	ldr r0, [r4]
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _02245D14 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #8]
	add r0, r0, #1
	strh r0, [r4, #8]
	b _02245D06
_02245C98:
	bl ov02_02245DE0
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02245D06
	mov r0, #0
	strh r0, [r4, #0xa]
	ldrh r0, [r4, #8]
	add r0, r0, #1
	strh r0, [r4, #8]
	b _02245D06
_02245CB0:
	ldrh r2, [r4, #0xa]
	add r1, r2, #1
	strh r1, [r4, #0xa]
	cmp r2, #0x3c
	blo _02245D06
	bl ov02_02245DB0
	ldr r0, [r4, #4]
	add r0, #0x50
	bl AreaLightManager_Free
	ldr r0, [r4, #4]
	mov r1, #4
	ldr r0, [r0, #0x48]
	bl AreaLightManager_New
	ldr r1, [r4, #4]
	ldr r3, _02245D14 ; =0x00007FFF
	str r0, [r1, #0x50]
	mov r0, #0x12
	mov r1, #1
	str r0, [sp]
	str r1, [sp, #4]
	ldr r0, [r4]
	add r2, r1, #0
	str r0, [sp, #8]
	mov r0, #3
	bl BeginNormalPaletteFade
	ldrh r0, [r4, #8]
	add r0, r0, #1
	strh r0, [r4, #8]
	b _02245D06
_02245CF2:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _02245D06
	add r0, r4, #0
	bl Heap_Free
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_02245D06:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_02245D0C: .word SEQ_SE_DP_FW411
_02245D10: .word SEQ_SE_DP_F207
_02245D14: .word 0x00007FFF
	thumb_func_end ov02_02245BC8
