#include "fielddata/script/scr_seq/event_T27GYM0101.h"
#include "constants/sndseq.h"
	.include "asm/macros.inc"
	.include "overlay_04.inc"
	.include "global.inc"
	.extern ov04_022575D4

	.text
	.public ov04_02254190

	thumb_func_start ov04_02254190
ov04_02254190: ; 0x02254190
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r0, #0
	bl FieldSystem_GetSaveData
	bl Save_GetGymmickPtr
	mov r1, #5
	bl Save_Gymmick_AssertMagic_GetData
	add r7, r0, #0
	mov r0, #4
	mov r1, #0x54
	bl Heap_Alloc
	ldr r1, [r4, #4]
	mov r2, #0x54
	str r0, [r1, #0x24]
	ldr r0, [r4, #4]
	mov r1, #0
	ldr r0, [r0, #0x24]
	bl MI_CpuFill8
	ldr r0, [r4, #4]
	mov r6, #0
	ldr r5, [r0, #0x24]
_022541C4:
	mov r1, #0
	add r0, sp, #4
	str r1, [r0]
	str r1, [r0, #4]
	str r1, [r0, #8]
	ldrb r0, [r7, r6]
	ldr r1, _02254400 ; =ov04_022575D4
	mov r3, #0
	lsl r2, r0, #2
	ldr r0, _02254400 ; =ov04_022575D4
	ldrh r1, [r1, r2]
	add r0, r0, r2
	ldrh r0, [r0, #2]
	lsl r2, r1, #0x10
	mov r1, #2
	lsl r1, r1, #0xe
	lsl r0, r0, #0x10
	str r2, [sp, #4]
	add r1, r2, r1
	str r1, [sp, #4]
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x54]
	mov r1, #0x76
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	add r2, sp, #4
	bl MapPropManager_LoadOne
	str r0, [r5, #4]
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #4
	blt _022541C4
	ldr r0, [r7, #4]
	cmp r0, #3
	bls _02254212
	b _022543F6
_02254212:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0225421E: ; jump table
	.short _02254226 - _0225421E - 2 ; case 0
	.short _0225429A - _0225421E - 2 ; case 1
	.short _0225430E - _0225421E - 2 ; case 2
	.short _02254382 - _0225421E - 2 ; case 3
_02254226:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x73
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x74
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x7a
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x75
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0225429A:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x73
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x74
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x7a
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x75
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_0225430E:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x73
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x74
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x7a
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #0
	str r0, [sp]
	mov r0, #0x75
	mov r2, #1
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_02254382:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x73
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x73
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x74
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x74
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x7a
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x7a
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #0x75
	bl Field3dObjectList_GetRenderObjectByID
	add r3, r0, #0
	ldr r0, [r4, #0x54]
	mov r1, #1
	str r0, [sp]
	mov r0, #0x75
	add r2, r1, #0
	bl MapPropAnimationManager_AddAnimationToRenderObj
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
_022543F6:
	bl GF_AssertFail
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02254400: .word ov04_022575D4
	thumb_func_end ov04_02254190
