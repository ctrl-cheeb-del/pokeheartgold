#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02087A78.inc"
	.include "global.inc"

	.public gOverlayTemplate_Battle
	.public _021028B4
	.public _021028C4
	.public gNatureStatMods

	.text

	thumb_func_start sub_02087C38
sub_02087C38: ; 0x02087C38
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r0, #0
	ldr r0, [r5]
	add r4, r1, #0
	cmp r0, #0
	beq _02087C50
	cmp r0, #1
	beq _02087C6A
	cmp r0, #2
	beq _02087D0C
	b _02087D5A
_02087C50:
	ldr r0, [r5, #0x14]
	ldr r0, [r0]
	cmp r0, #0
	beq _02087C62
	ldr r0, _02087DF4 ; =FS_OVERLAY_ID(OVY_39)
	bl UnloadOverlayByID
	bl UnloadOVY38
_02087C62:
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02087DEC
_02087C6A:
	add r0, r4, #0
	mov r1, #0
	bl BattleSetup_New
	str r0, [r5, #0x10]
	bl sub_0202FC48
	cmp r0, #0
	bne _02087C92
	ldr r1, [r5, #0x14]
	ldr r0, _02087DF8 ; =0x0000086C
	add r2, sp, #4
	ldr r0, [r1, r0]
	add r1, r4, #0
	str r0, [sp]
	ldr r0, [r5, #0xc]
	ldr r3, [r5, #0x10]
	bl sub_0202FC90
	b _02087C9E
_02087C92:
	ldr r0, [r5, #0x10]
	ldr r1, [r5, #0xc]
	bl sub_020304F0
	mov r0, #1
	str r0, [sp, #4]
_02087C9E:
	add r0, r4, #0
	bl BagCursor_New
	mov r1, #0x43
	ldr r2, [r5, #0x10]
	lsl r1, r1, #2
	str r0, [r2, r1]
	ldr r0, [r5, #0xc]
	bl Save_GameStats_Get
	mov r1, #0x51
	ldr r2, [r5, #0x10]
	lsl r1, r1, #2
	str r0, [r2, r1]
	ldr r6, _02087DFC ; =FS_OVERLAY_ID(OVY_40)
	mov r1, #2
	add r0, r6, #0
	bl HandleLoadOverlay
	cmp r0, #1
	bne _02087CDA
	bl sub_0202FC5C
	ldr r1, [r5, #0x10]
	add r2, r4, #0
	bl ov40_02244920
	add r0, r6, #0
	bl UnloadOverlayByID
_02087CDA:
	ldr r1, [r5, #0x14]
	ldr r0, _02087E00 ; =0x00000874
	mov r2, #1
	str r2, [r1, r0]
	ldr r0, [sp, #4]
	cmp r0, #1
	beq _02087D04
	mov r0, #0x43
	ldr r1, [r5, #0x10]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl Heap_Free
	ldr r0, [r5, #0x10]
	bl BattleSetup_Delete
	mov r0, #0
	str r0, [r5]
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_02087D04:
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02087DEC
_02087D0C:
	mov r0, #1
	mov r1, #0x7f
	bl GF_SndHandleSetPlayerVolume
	mov r0, #7
	mov r1, #0x7f
	bl GF_SndHandleSetPlayerVolume
	mov r0, #1
	bl sub_02005B68
	ldr r0, [r5, #0x10]
	add r0, #0x5d
	ldrb r0, [r0]
	bl sub_02087E34
	cmp r0, #1
	bne _02087D3C
	ldr r1, _02087E04 ; =0x0000047B
	mov r0, #5
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
	b _02087D46
_02087D3C:
	ldr r1, _02087E08 ; =0x0000045D
	mov r0, #5
	mov r2, #1
	bl Sound_SetSceneAndPlayBGM
_02087D46:
	ldr r0, _02087E0C ; =gOverlayTemplate_Battle
	ldr r1, [r5, #0x10]
	add r2, r4, #0
	bl OverlayManager_New
	str r0, [r5, #8]
	ldr r0, [r5]
	add r0, r0, #1
	str r0, [r5]
	b _02087DEC
_02087D5A:
	ldr r0, [r5, #8]
	bl OverlayManager_Run
	cmp r0, #0
	beq _02087DEC
	mov r0, #0x71
	ldr r1, [r5, #0x10]
	lsl r0, r0, #2
	ldr r2, [r1, r0]
	ldr r1, [r5, #0x14]
	ldr r0, _02087E00 ; =0x00000874
	str r2, [r1, r0]
	ldr r2, [r5, #0x14]
	ldr r1, [r2]
	cmp r1, #0
	beq _02087D88
	ldr r1, [r2, r0]
	cmp r1, #0
	bne _02087D88
	add r0, r0, #4
	ldr r0, [r2, r0]
	mov r1, #1
	strb r1, [r0]
_02087D88:
	mov r0, #0x43
	ldr r1, [r5, #0x10]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	bl Heap_Free
	ldr r0, [r5, #0x10]
	bl BattleSetup_Delete
	ldr r0, [r5, #8]
	bl OverlayManager_Delete
	mov r0, #0
	bl sub_02005B68
	mov r0, #0
	bl Sound_SetScene
	ldr r0, [r5, #0x28]
	ldr r1, [r0, #0x20]
	ldr r1, [r1]
	bl FieldBGM_GetEffective
	add r4, r0, #0
	ldr r0, [r5, #0x28]
	ldr r1, [r0, #0x20]
	ldr r1, [r1]
	bl FieldBGM_GetForMapHeader
	bl Sound_SetFieldBGM
	mov r0, #0
	add r1, r4, #0
	bl sub_02055198
	mov r0, #0
	str r0, [r5]
	ldr r0, [r5, #0x14]
	ldr r0, [r0]
	cmp r0, #0
	beq _02087DE6
	bl LoadOVY38
	ldr r0, _02087DF4 ; =FS_OVERLAY_ID(OVY_39)
	mov r1, #2
	bl HandleLoadOverlay
_02087DE6:
	add sp, #8
	mov r0, #1
	pop {r4, r5, r6, pc}
_02087DEC:
	mov r0, #0
	add sp, #8
	pop {r4, r5, r6, pc}
	nop
_02087DF4: .word FS_OVERLAY_ID(OVY_39)
_02087DF8: .word 0x0000086C
_02087DFC: .word FS_OVERLAY_ID(OVY_40)
_02087E00: .word 0x00000874
_02087E04: .word 0x0000047B
_02087E08: .word 0x0000045D
_02087E0C: .word gOverlayTemplate_Battle
	thumb_func_end sub_02087C38

	.rodata

	.public _02102830
	.public _02102830
_02102830:
	.word sub_02087B10, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102840
_02102840:
	.word sub_02087B58, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102850
_02102850:
	.word sub_02087B4C, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102860
_02102860:
	.word sub_02087B40, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102870
_02102870:
	.word sub_02087B34, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102880
_02102880:
	.word sub_02087B28, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _02102890
_02102890:
	.word sub_02087B1C, sub_02087B64, sub_02087BAC, 0xFFFFFFFF
	.public _021028A0
_021028A0:
	.word 0x61
	.word 0x63
	.word 0x64
	.word 0x65
	.word 0x66

	.data

	.public _02110594
_02110594:
	.word _02102830
	.word _02102890
	.word _02102880
	.word _02102870
	.word _02102860
	.word _02102850
	.word _02102840
