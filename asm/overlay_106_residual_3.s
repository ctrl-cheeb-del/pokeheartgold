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

	thumb_func_start ov106_021E5E0C
ov106_021E5E0C: ; 0x021E5E0C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _021E5E54 ; =ov106_021E5EE4
	ldr r3, [r5, #0x28]
	mov r1, #0x38
	mov r2, #5
	bl CreateSysTaskAndEnvironment
	add r6, r0, #0
	bl SysTask_GetData
	add r4, r0, #0
	add r2, r4, #4
	mov r3, #5
_021E5E28:
	ldmia r5!, {r0, r1}
	stmia r2!, {r0, r1}
	sub r3, r3, #1
	bne _021E5E28
	ldr r0, [r5]
	str r0, [r2]
	str r6, [r4, #0x34]
	mov r0, #0
	str r0, [r4, #0x30]
	bl GX_GetBankForLCDC
	str r0, [r4]
	add r0, r4, #4
	bl ov106_021E5F84
	ldr r0, _021E5E58 ; =ov106_021E5F24
	add r1, r4, #0
	mov r2, #0
	bl SysTask_CreateOnVWaitQueue
	add r0, r4, #0
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E5E54: .word ov106_021E5EE4
_021E5E58: .word ov106_021E5F24
	thumb_func_end ov106_021E5E0C


	thumb_func_start ov106_021E5E5C
ov106_021E5E5C: ; 0x021E5E5C
	push {r4, lr}
	add r4, r0, #0
	add r0, r1, #0
	add r1, r2, #0
	add r2, r3, #0
	bl GX_SetGraphicsMode
	ldr r0, [r4]
	bl GX_SetBankForLCDC
	ldr r0, [r4, #4]
	cmp r0, #0xa
	bgt _021E5E88
	bge _021E5EAC
	cmp r0, #6
	bgt _021E5EC8
	cmp r0, #2
	blt _021E5EC8
	beq _021E5E8E
	cmp r0, #6
	beq _021E5E9E
	b _021E5EC8
_021E5E88:
	cmp r0, #0xe
	beq _021E5EBA
	b _021E5EC8
_021E5E8E:
	mov r1, #0x1a
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5ECE
_021E5E9E:
	mov r2, #2
	ldr r1, _021E5ED8 ; =0x06820000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5ECE
_021E5EAC:
	mov r2, #2
	ldr r1, _021E5EDC ; =0x06840000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5ECE
_021E5EBA:
	mov r2, #2
	ldr r1, _021E5EE0 ; =0x06860000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5ECE
_021E5EC8:
	mov r0, #0
	bl GX_SetBankForLCDC
_021E5ECE:
	ldr r0, [r4, #0x34]
	bl DestroySysTaskAndEnvironment
	pop {r4, pc}
	nop
_021E5ED8: .word 0x06820000
_021E5EDC: .word 0x06840000
_021E5EE0: .word 0x06860000
	thumb_func_end ov106_021E5E5C


	thumb_func_start ov106_021E5EE4
ov106_021E5EE4: ; 0x021E5EE4
	push {r4, r5, r6, r7}
	ldr r0, [r1, #0x30]
	cmp r0, #0
	beq _021E5F1C
	ldr r6, [r1, #0x20]
	ldr r5, [r1, #0x10]
	ldr r4, [r1, #0x1c]
	ldr r3, [r1, #0x18]
	ldr r2, [r1, #0x14]
	ldr r0, [r1, #0x24]
	ldr r1, [r1, #0x28]
	lsl r5, r5, #0x14
	lsl r7, r1, #8
	lsl r1, r3, #0x18
	lsl r3, r2, #0x1d
	mov r2, #2
	lsl r2, r2, #0x1e
	orr r3, r2
	lsl r2, r4, #0x19
	orr r2, r3
	orr r1, r2
	lsl r6, r6, #0x10
	orr r1, r5
	orr r1, r6
	orr r1, r7
	orr r1, r0
	ldr r0, _021E5F20 ; =0x04000064
	str r1, [r0]
_021E5F1C:
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_021E5F20: .word 0x04000064
	thumb_func_end ov106_021E5EE4


	thumb_func_start ov106_021E5F24
ov106_021E5F24: ; 0x021E5F24
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r0, [r4, #4]
	cmp r0, #0xa
	bgt _021E5F42
	bge _021E5F58
	cmp r0, #6
	bgt _021E5F68
	cmp r0, #2
	blt _021E5F68
	beq _021E5F48
	cmp r0, #6
	beq _021E5F50
	b _021E5F68
_021E5F42:
	cmp r0, #0xe
	beq _021E5F60
	b _021E5F68
_021E5F48:
	mov r0, #1
	bl GX_SetBankForLCDC
	b _021E5F6E
_021E5F50:
	mov r0, #2
	bl GX_SetBankForLCDC
	b _021E5F6E
_021E5F58:
	mov r0, #4
	bl GX_SetBankForLCDC
	b _021E5F6E
_021E5F60:
	mov r0, #8
	bl GX_SetBankForLCDC
	b _021E5F6E
_021E5F68:
	mov r0, #0
	bl GX_SetBankForLCDC
_021E5F6E:
	ldr r0, [r4, #4]
	ldr r1, [r4, #8]
	ldr r2, [r4, #0xc]
	bl GX_SetGraphicsMode
	mov r0, #1
	str r0, [r4, #0x30]
	add r0, r5, #0
	bl SysTask_Destroy
	pop {r3, r4, r5, pc}
	thumb_func_end ov106_021E5F24


	thumb_func_start ov106_021E5F84
ov106_021E5F84: ; 0x021E5F84
	push {r4, r5, r6, lr}
	add r4, r0, #0
	ldr r0, [r4]
	cmp r0, #0xa
	bgt _021E5FA0
	bge _021E5FC4
	cmp r0, #6
	bgt _021E5FDE
	cmp r0, #2
	blt _021E5FDE
	beq _021E5FA6
	cmp r0, #6
	beq _021E5FB6
	b _021E5FDE
_021E5FA0:
	cmp r0, #0xe
	beq _021E5FD2
	b _021E5FDE
_021E5FA6:
	mov r1, #0x1a
	mov r2, #2
	mov r0, #0
	lsl r1, r1, #0x16
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5FDE
_021E5FB6:
	mov r2, #2
	ldr r1, _021E600C ; =0x06820000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5FDE
_021E5FC4:
	mov r2, #2
	ldr r1, _021E6010 ; =0x06840000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
	b _021E5FDE
_021E5FD2:
	mov r2, #2
	ldr r1, _021E6014 ; =0x06860000
	mov r0, #0
	lsl r2, r2, #0x10
	bl MIi_CpuClearFast
_021E5FDE:
	ldr r5, [r4, #0x10]
	ldr r1, [r4, #0x1c]
	ldr r3, [r4, #0x18]
	ldr r6, [r4, #0x14]
	ldr r0, [r4, #0xc]
	mov r4, #2
	lsl r2, r1, #0x10
	lsl r1, r0, #0x14
	lsl r5, r5, #0x1d
	lsl r4, r4, #0x1e
	orr r4, r5
	lsl r3, r3, #0x19
	lsl r0, r6, #0x18
	orr r3, r4
	orr r0, r3
	orr r0, r1
	add r1, r2, #0
	orr r1, r0
	mov r0, #0x10
	orr r1, r0
	ldr r0, _021E6018 ; =0x04000064
	str r1, [r0]
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021E600C: .word 0x06820000
_021E6010: .word 0x06840000
_021E6014: .word 0x06860000
_021E6018: .word 0x04000064
	thumb_func_end ov106_021E5F84
