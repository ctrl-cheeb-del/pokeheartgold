#include "constants/mmodel.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "overlay_106.inc"
	.include "global.inc"
	.public _021E6D70
	.public ov106_021E5A44
	.public ov106_021E5A74
	.public ov106_021E5AA8
	.public ov106_021E5BBC
	.public ov106_021E5C30
	.public ov106_021E5CD0
	.public ov106_021E5D70
	.public ov106_021E5E0C
	.public ov106_021E5E5C
	.public ov106_021E5EE4
	.public ov106_021E5F24
	.public ov106_021E5F84
	.public ov106_021E6280
	.public ov106_021E62F4
	.public ov106_021E6418
	.public ov106_021E6520
	.public ov106_021E6634
	.public ov106_021E66B0
	.public ov106_021E66FC
	.public ov106_021E6814
	.public ov106_021E68F4
	.public ov106_021E6988
	.public ov106_021E69F0
	.public ov106_021E6A34
	.public ov106_021E6B30
	.public ov106_021E6D7C
	.public ov106_021E6D8C
	.public ov106_021E6DB0
	.public ov106_021E6DD8
	.public ov106_021E6E04
	.public ov106_021E6E2C
	.public ov106_021E6E50
	.public ov106_021E6E74
	.public ov106_021E6E9C
	.public ov106_021E6EC4
	.public ov106_021E6EE4
	.public ov106_021E6EFC
	.public ov106_021E6F24
	.public ov106_021E6F48
	.public ov106_021E6F5C
	.public ov106_021E6F74
	.public ov106_021E6F90
	.public ov106_021E6FAC
	.public ov106_021E6FC8
	.public ov106_021E6FE8
	.public ov106_021E7010
	.public ov106_021E7044
	.public ov106_021E7090
	.public ov106_021E70E0
	.public sScriptCinematicSubs_Arceus
	.public sScriptCinematicSubs_HoOh
	.public sScriptCinematicSubs_Lugia


	.text
	.public ScriptCinematic_Arceus
	.public ScriptCinematic_HoOh
	.public ScriptCinematic_Lugia
	.public ov106_021E5900
	.public ov106_021E594C
	.public ov106_021E5954
	.public ov106_021E597C
	.public ov106_021E59A4
	.public ov106_021E59D0
	.public ov106_021E59FC
	.public ov106_021E5D08
	.public ov106_021E5D38
	.public ov106_021E5D48
	.public ov106_021E5DFC
	.public ov106_021E601C
	.public ov106_021E6064
	.public ov106_021E60B0
	.public ov106_021E6104
	.public ov106_021E6118
	.public ov106_021E6130
	.public ov106_021E61B8
	.public ov106_021E61F8
	.public ov106_021E62C8
	.public ov106_021E62DC
	.public ov106_021E63E0
	.public ov106_021E6408
	.public ov106_021E64FC
	.public ov106_021E664C
	.public ov106_021E6668
	.public ov106_021E6678
	.public ov106_021E6694
	.public ov106_021E68A8
	.public ov106_021E68DC
	.public ov106_021E6A80
	.public ov106_021E6AB0
	.public ov106_021E6AD0
	.public ov106_021E6AF0
	.public ov106_021E6B10
	.public ov106_021E6B50
	.public ov106_021E6BB0
	.public ov106_021E6BD4
	.public ov106_021E6BF8
	.public ov106_021E6C28
	.public ov106_021E6C5C
	.public ov106_021E6C88
	.public ov106_021E6CA8
	.public ov106_021E6CC4
	.public ov106_021E6CF8
	.public ov106_021E6D1C
	.public ov106_021E6D48
	.public ov106_021E6D6C

	thumb_func_start ov106_021E62F4
ov106_021E62F4: ; 0x021E62F4
	push {r4, lr}
	add r4, r0, #0
	bl ov106_021E5D08
	cmp r0, #0
	bne _021E631E
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _021E631E
	ldr r0, _021E6398 ; =0x00000414
	mov r1, #0
	str r1, [r4, r0]
	ldr r0, _021E639C ; =0x00000868
	bl StopSE
	ldr r0, [r4, #4]
	bl ov106_021E6064
	mov r0, #1
	pop {r4, pc}
_021E631E:
	ldr r0, _021E6398 ; =0x00000414
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _021E6330
	ldr r0, _021E639C ; =0x00000868
	mov r1, #0
	bl sub_02006118
	b _021E6364
_021E6330:
	cmp r0, #0x73
	bne _021E633C
	ldr r0, _021E63A0 ; =0x00000931
	bl PlaySE
	b _021E6364
_021E633C:
	cmp r0, #0x91
	bne _021E6354
	mov r0, #0xf9
	mov r1, #0
	bl PlayCry
	mov r0, #5
	mov r1, #0xd
	bl ov106_021E601C
	str r0, [r4, #4]
	b _021E6364
_021E6354:
	cmp r0, #0xe8
	bne _021E6364
	mov r2, #1
	add r0, r4, #0
	mov r1, #6
	add r3, r2, #0
	bl ov106_021E597C
_021E6364:
	ldr r0, _021E6398 ; =0x00000414
	ldr r2, [r4, r0]
	cmp r2, #0
	beq _021E638A
	cmp r2, #0xa
	bne _021E637A
	ldr r0, _021E639C ; =0x00000868
	mov r1, #0x1e
	bl GF_SetVolumeBySeqNo
	b _021E638A
_021E637A:
	bhs _021E638A
	lsl r1, r2, #1
	add r1, r2, r1
	lsl r1, r1, #8
	ldr r0, _021E639C ; =0x00000868
	lsr r1, r1, #8
	bl GF_SetVolumeBySeqNo
_021E638A:
	ldr r0, _021E6398 ; =0x00000414
	ldr r1, [r4, r0]
	add r1, r1, #1
	str r1, [r4, r0]
	mov r0, #3
	pop {r4, pc}
	nop
_021E6398: .word 0x00000414
_021E639C: .word 0x00000868
_021E63A0: .word 0x00000931
	thumb_func_end ov106_021E62F4
