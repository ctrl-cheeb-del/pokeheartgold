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

	thumb_func_start ov106_021E68F4
ov106_021E68F4: ; 0x021E68F4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r5, r0, #0
	ldr r0, _021E697C ; =0x00000418
	ldr r4, [r5, r0]
	sub r0, r0, #4
	ldr r0, [r5, r0]
	ldr r7, [r4, #0x30]
	str r0, [sp, #8]
	cmp r0, r7
	bne _021E6930
	ldr r6, [r4, #0x2c]
	mov r0, #0xf
	sub r0, r0, r6
	bl abs
	str r0, [sp]
	ldr r0, _021E6980 ; =0x04000050
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x24]
	add r3, r6, #0
	bl G2x_SetBlendAlpha_
	ldr r0, _021E6984 ; =0x00000414
	mov r1, #0
	str r1, [r5, r0]
	sub r0, r0, #4
	add sp, #0xc
	ldr r0, [r5, r0]
	pop {r4, r5, r6, r7, pc}
_021E6930:
	ldr r0, [r4, #0x2c]
	ldr r6, [r4, #0x20]
	str r0, [sp, #4]
	sub r0, r6, r0
	bl abs
	lsl r0, r0, #8
	add r1, r7, #0
	bl _s32_div_f
	ldr r1, [sp, #8]
	mul r0, r1
	lsr r1, r0, #8
	ldr r0, [sp, #4]
	cmp r6, r0
	ble _021E6954
	sub r6, r6, r1
	b _021E6956
_021E6954:
	add r6, r1, r6
_021E6956:
	mov r0, #0xf
	sub r0, r0, r6
	bl abs
	str r0, [sp]
	ldr r0, _021E6980 ; =0x04000050
	ldr r1, [r4, #0x1c]
	ldr r2, [r4, #0x24]
	add r3, r6, #0
	bl G2x_SetBlendAlpha_
	ldr r0, _021E6984 ; =0x00000414
	ldr r1, [r5, r0]
	add r1, r1, #1
	str r1, [r5, r0]
	mov r0, #3
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	nop
_021E697C: .word 0x00000418
_021E6980: .word 0x04000050
_021E6984: .word 0x00000414
	thumb_func_end ov106_021E68F4


	thumb_func_start ov106_021E6988
ov106_021E6988: ; 0x021E6988
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	ldr r0, _021E69E0 ; =0x00000418
	ldr r7, _021E69E4 ; =ov106_021E7044
	ldr r5, [r6, r0]
	add r4, r5, #0
	add r4, #0x14
_021E6996:
	ldr r1, [r5, #0x14]
	ldr r2, [r1]
	cmp r2, #0x13
	bne _021E69A2
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_021E69A2:
	lsl r2, r2, #2
	ldr r2, [r7, r2]
	add r0, r6, #0
	blx r2
	cmp r0, #0
	beq _021E69DA
	cmp r0, #1
	bne _021E69C6
	ldr r1, [r5, #0x14]
	ldr r0, [r4]
	ldr r1, [r1]
	lsl r2, r1, #2
	ldr r1, _021E69E8 ; =ov106_021E7090
	ldr r1, [r1, r2]
	lsl r1, r1, #2
	add r0, r0, r1
	str r0, [r4]
	b _021E6996
_021E69C6:
	cmp r0, #2
	bne _021E6996
	ldr r2, [r5, #0x14]
	ldr r0, [r2]
	lsl r1, r0, #2
	ldr r0, _021E69E8 ; =ov106_021E7090
	ldr r0, [r0, r1]
	lsl r0, r0, #2
	add r0, r2, r0
	str r0, [r5, #0x14]
_021E69DA:
	ldr r0, _021E69EC ; =0x0000040C
	ldr r0, [r6, r0]
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021E69E0: .word 0x00000418
_021E69E4: .word ov106_021E7044
_021E69E8: .word ov106_021E7090
_021E69EC: .word 0x0000040C
	thumb_func_end ov106_021E6988


	thumb_func_start ov106_021E69F0
ov106_021E69F0: ; 0x021E69F0
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	ldr r0, [r5, #4]
	add r2, #0x88
	add r4, r1, #0
	add r1, r2, #0
	add r2, sp, #0
	mov r3, #0x99
	bl GfGfxLoader_GetPlttDataFromOpenNarc
	add r6, r0, #0
	ldr r2, _021E6A30 ; =0x00002004
	add r0, r4, #0
	add r5, #0x34
	mul r0, r2
	add r1, r5, r0
	ldr r0, [sp]
	ldr r3, [r0, #8]
	sub r0, r2, #4
	str r3, [r1, r0]
	ldr r0, [sp]
	sub r2, r2, #4
	ldr r0, [r0, #0xc]
	ldr r2, [r1, r2]
	bl MIi_CpuCopy32
	add r0, r6, #0
	bl Heap_Free
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
_021E6A30: .word 0x00002004
	thumb_func_end ov106_021E69F0


	thumb_func_start ov106_021E6A34
ov106_021E6A34: ; 0x021E6A34
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r7, #0
	add r4, r5, #0
	add r6, r7, #0
	add r4, #0x34
_021E6A40:
	ldr r0, _021E6A78 ; =0x00002034
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _021E6A62
	bl GX_BeginLoadBGExtPltt
	ldr r2, _021E6A78 ; =0x00002034
	add r0, r4, #0
	ldr r2, [r5, r2]
	add r1, r6, #0
	bl GX_LoadBGExtPltt
	bl GX_EndLoadBGExtPltt
	ldr r0, _021E6A78 ; =0x00002034
	mov r1, #0
	str r1, [r5, r0]
_021E6A62:
	ldr r0, _021E6A7C ; =0x00002004
	add r7, r7, #1
	add r5, r5, r0
	sub r0, r0, #4
	add r6, r6, r0
	ldr r0, _021E6A7C ; =0x00002004
	add r4, r4, r0
	cmp r7, #3
	blo _021E6A40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6A78: .word 0x00002034
_021E6A7C: .word 0x00002004
	thumb_func_end ov106_021E6A34
