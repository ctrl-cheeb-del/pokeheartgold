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

	thumb_func_start ov106_021E5A44
ov106_021E5A44: ; 0x021E5A44
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r4, #0
	add r6, r5, #0
	mov r7, #4
_021E5A4E:
	mov r1, #0
	mov r2, #2
	ldrsh r1, [r5, r1]
	ldrsh r2, [r5, r2]
	ldrsh r3, [r5, r7]
	add r0, r4, #0
	bl NNS_G3dGlbLightVector
	ldrh r1, [r6, #0x18]
	add r0, r4, #0
	bl NNS_G3dGlbLightColor
	add r4, r4, #1
	add r5, r5, #6
	add r6, r6, #2
	cmp r4, #4
	blo _021E5A4E
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov106_021E5A44


	thumb_func_start ov106_021E5A74
ov106_021E5A74: ; 0x021E5A74
	push {r3, lr}
	cmp r0, #0
	bne _021E5A86
	ldr r2, _021E5A9C ; =0x04000060
	ldr r0, _021E5AA0 ; =0x0000CFDF
	ldrh r1, [r2]
	and r0, r1
	strh r0, [r2]
	pop {r3, pc}
_021E5A86:
	ldr r3, _021E5A9C ; =0x04000060
	ldr r1, _021E5AA4 ; =0xFFFFCFFF
	ldrh r2, [r3]
	and r2, r1
	mov r1, #0x20
	orr r1, r2
	strh r1, [r3]
	bl G3X_SetEdgeColorTable
	pop {r3, pc}
	nop
_021E5A9C: .word 0x04000060
_021E5AA0: .word 0x0000CFDF
_021E5AA4: .word 0xFFFFCFFF
	thumb_func_end ov106_021E5A74


	thumb_func_start ov106_021E5AA8
ov106_021E5AA8: ; 0x021E5AA8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp, #4]
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	add r0, #8
	mov r1, #0x99
	mov r2, #4
	str r3, [sp, #0x10]
	bl HeapExp_FndInitAllocator
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	cmp r0, #0
	bls _021E5BAE
_021E5AC8:
	ldr r2, [sp, #4]
	ldr r0, [sp, #0x18]
	mov r1, #0x7c
	add r2, #0x1c
	mul r1, r0
	add r4, r2, r1
	mov r1, #0xc
	mul r1, r0
	ldr r0, [sp, #0xc]
	mov r2, #1
	add r0, r0, r1
	str r0, [sp, #0x14]
	ldr r3, [sp, #0xc]
	str r2, [sp]
	ldr r1, [r3, r1]
	ldr r0, [sp, #8]
	mov r3, #0x99
	bl GfGfxLoader_LoadFromNarc
	add r1, r4, #0
	add r2, r4, #0
	str r0, [r4, #0x58]
	add r0, r4, #0
	add r1, #0x54
	add r2, #0x58
	bl GF3dRender_InitObjFromHeader
	ldr r0, [r4, #0x58]
	bl NNS_G3dGetTex
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x14]
	ldr r0, [r0, #8]
	cmp r0, #1
	bne _021E5B3A
	ldr r0, [r4, #0x54]
	mov r1, #0
	mov r2, #0x40
	bl NNSi_G3dModifyMatFlag
	ldr r0, [r4, #0x54]
	mov r1, #0
	mov r2, #0x80
	bl NNSi_G3dModifyMatFlag
	mov r2, #2
	ldr r0, [r4, #0x54]
	mov r1, #0
	lsl r2, r2, #8
	bl NNSi_G3dModifyMatFlag
	mov r2, #1
	ldr r0, [r4, #0x54]
	mov r1, #0
	lsl r2, r2, #0xa
	bl NNSi_G3dModifyMatFlag
_021E5B3A:
	ldr r0, [sp, #4]
	mov r5, #0
	str r0, [sp, #0x20]
	add r0, #8
	str r0, [sp, #0x20]
_021E5B44:
	ldr r0, [sp, #0x14]
	add r0, r0, r5
	ldrb r1, [r0, #4]
	cmp r1, #0xff
	bne _021E5B5A
	lsl r0, r5, #2
	add r1, r4, r0
	mov r0, #0
	str r0, [r1, #0x5c]
	str r0, [r1, #0x6c]
	b _021E5B94
_021E5B5A:
	lsl r0, r5, #2
	add r6, r4, r0
	mov r0, #1
	str r0, [sp]
	ldr r0, [sp, #8]
	mov r2, #1
	mov r3, #0x99
	bl GfGfxLoader_LoadFromNarc
	str r0, [r6, #0x5c]
	mov r1, #0
	bl NNS_G3dGetAnmByIdx
	add r7, r0, #0
	ldr r0, [sp, #0x20]
	ldr r2, [r4, #0x54]
	add r1, r7, #0
	bl NNS_G3dAllocAnmObj
	str r0, [r6, #0x6c]
	ldr r2, [r4, #0x54]
	ldr r3, [sp, #0x1c]
	add r1, r7, #0
	bl NNS_G3dAnmObjInit
	ldr r1, [r6, #0x6c]
	add r0, r4, #0
	bl NNS_G3dRenderObjAddAnmObj
_021E5B94:
	add r0, r5, #1
	lsl r0, r0, #0x10
	lsr r5, r0, #0x10
	cmp r5, #4
	blo _021E5B44
	ldr r0, [sp, #0x18]
	add r0, r0, #1
	lsl r0, r0, #0x10
	lsr r1, r0, #0x10
	ldr r0, [sp, #0x10]
	str r1, [sp, #0x18]
	cmp r1, r0
	blo _021E5AC8
_021E5BAE:
	mov r2, #0xff
	ldr r1, [sp, #0x10]
	ldr r0, [sp, #4]
	lsl r2, r2, #2
	str r1, [r0, r2]
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov106_021E5AA8


	thumb_func_start ov106_021E5BBC
ov106_021E5BBC: ; 0x021E5BBC
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	mov r1, #0xff
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	cmp r0, #0
	bls _021E5C2C
	ldr r0, [sp]
	ldr r7, [sp]
	str r0, [sp, #8]
	add r0, #0x1c
	add r7, #8
	str r0, [sp, #8]
_021E5BDE:
	ldr r1, [sp, #4]
	mov r0, #0x7c
	add r2, r1, #0
	mul r2, r0
	ldr r0, [sp, #8]
	mov r4, #0
	add r6, r0, r2
_021E5BEC:
	lsl r0, r4, #2
	add r5, r6, r0
	ldr r0, [r5, #0x5c]
	cmp r0, #0
	beq _021E5C04
	ldr r1, [r5, #0x6c]
	add r0, r7, #0
	bl NNS_G3dFreeAnmObj
	ldr r0, [r5, #0x5c]
	bl Heap_Free
_021E5C04:
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #4
	blo _021E5BEC
	ldr r0, [r6, #0x58]
	bl Heap_Free
	ldr r0, [sp, #4]
	ldr r1, [sp]
	add r0, r0, #1
	lsl r0, r0, #0x10
	lsr r0, r0, #0x10
	str r0, [sp, #4]
	mov r0, #0xff
	lsl r0, r0, #2
	ldr r1, [r1, r0]
	ldr r0, [sp, #4]
	cmp r0, r1
	blo _021E5BDE
_021E5C2C:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov106_021E5BBC


	thumb_func_start ov106_021E5C30
ov106_021E5C30: ; 0x021E5C30
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x40
	ldr r4, _021E5CC8 ; =ov106_021E6D8C
	str r0, [sp]
	add r3, sp, #0x1c
	mov r2, #4
_021E5C3C:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _021E5C3C
	ldr r0, [r4]
	add r2, sp, #0x10
	str r0, [r3]
	ldr r3, _021E5CCC ; =_021E6D70
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	add r1, sp, #4
	str r0, [r2]
	mov r0, #0
	str r0, [r1]
	str r0, [r1, #4]
	str r0, [r1, #8]
	bl Thunk_G3X_Reset
	bl Camera_PushLookAtToNNSGlb
	mov r1, #0xff
	ldr r0, [sp]
	lsl r1, r1, #2
	ldr r0, [r0, r1]
	mov r7, #0
	cmp r0, #0
	bls _021E5CBA
	ldr r4, [sp]
	mov r5, #1
	add r4, #0x1c
	lsl r5, r5, #0xc
_021E5C7C:
	mov r2, #0
	add r3, r4, #0
_021E5C80:
	ldr r1, [r3, #0x6c]
	cmp r1, #0
	beq _021E5C96
	ldr r6, [r1, #8]
	ldr r0, [r1]
	ldrh r6, [r6, #4]
	add r0, r0, r5
	lsl r6, r6, #0xc
	cmp r0, r6
	bge _021E5C96
	str r0, [r1]
_021E5C96:
	add r2, r2, #1
	add r3, r3, #4
	cmp r2, #4
	blo _021E5C80
	add r0, r4, #0
	add r1, sp, #4
	add r2, sp, #0x1c
	add r3, sp, #0x10
	bl GF3dRender_DrawModel
	mov r0, #0xff
	ldr r1, [sp]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r7, r7, #1
	add r4, #0x7c
	cmp r7, r0
	blo _021E5C7C
_021E5CBA:
	mov r0, #0
	add r1, r0, #0
	bl RequestSwap3DBuffers
	add sp, #0x40
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E5CC8: .word ov106_021E6D8C
_021E5CCC: .word _021E6D70
	thumb_func_end ov106_021E5C30


	thumb_func_start ov106_021E5CD0
ov106_021E5CD0: ; 0x021E5CD0
	push {r4, r5}
	mov r3, #0x7c
	mul r3, r1
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	add r0, r0, r3
	lsl r1, r1, #0xc
_021E5CE0:
	ldr r5, [r0, #0x6c]
	cmp r5, #0
	beq _021E5CFA
	ldr r3, [r5]
	add r4, r3, r1
	ldr r3, [r5, #8]
	ldrh r3, [r3, #4]
	lsl r3, r3, #0xc
	cmp r4, r3
	bge _021E5CFA
	mov r0, #1
	pop {r4, r5}
	bx lr
_021E5CFA:
	add r2, r2, #1
	add r0, r0, #4
	cmp r2, #4
	blo _021E5CE0
	mov r0, #0
	pop {r4, r5}
	bx lr
	thumb_func_end ov106_021E5CD0
