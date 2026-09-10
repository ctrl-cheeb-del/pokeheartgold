#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020607D8
sub_020607D8: ; 0x020607D8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r1, #0
	ldrh r1, [r3]
	add r5, r0, #0
	lsl r1, r1, #0x13
	lsr r1, r1, #0x1e
	beq _020607F0
	bl MapObject_CheckFlag24
	cmp r0, #1
	bne _020607F2
_020607F0:
	b _020609CE
_020607F2:
	bl GetMetatileBehavior_None
	add r4, r0, #0
	add r0, r5, #0
	bl MapObject_GetID
	cmp r0, #0xfd
	beq _02060804
	b _0206096A
_02060804:
	add r0, r5, #0
	bl ov01_022055DC
	cmp r0, #0
	beq _02060902
	add r0, r5, #0
	bl MapObject_CheckFlag24
	cmp r0, #0
	beq _0206081A
	b _020609CE
_0206081A:
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060828
	add r4, r6, #0
	b _020608CA
_02060828:
	add r0, r5, #0
	mov r1, #1
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r1, #3
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #2
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #4
	bl ov01_022056C4
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r0, r5, #0
	mov r1, #5
	bl ov01_022056C4
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	ldr r0, [sp, #0xc]
	mov r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060880
	ldr r0, [sp, #0xc]
	mov r6, #1
	str r0, [sp, #0x10]
	b _020608C4
_02060880:
	ldr r0, [sp, #8]
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060892
	ldr r0, [sp, #8]
	mov r6, #1
	str r0, [sp, #0x10]
	b _020608C4
_02060892:
	ldr r0, [sp, #4]
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _020608A4
	ldr r0, [sp, #4]
	mov r6, #1
	str r0, [sp, #0x10]
	b _020608C4
_020608A4:
	ldr r0, [sp]
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _020608B6
	ldr r0, [sp]
	mov r6, #1
	str r0, [sp, #0x10]
	b _020608C4
_020608B6:
	add r0, r7, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _020608C4
	str r7, [sp, #0x10]
	mov r6, #1
_020608C4:
	cmp r6, #1
	bne _020608CA
	ldr r4, [sp, #0x10]
_020608CA:
	bl GetMetatileBehavior_None
	cmp r4, r0
	beq _020609CE
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetFlag24
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #1
	bne _020608E8
	mov r1, #5
	b _020608F8
_020608E8:
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	bne _020608F6
	mov r1, #3
	b _020608F8
_020608F6:
	mov r1, #4
_020608F8:
	add r0, r5, #0
	bl ov01_021FDF88
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_02060902:
	add r0, r5, #0
	bl MapObject_CheckFlag24
	cmp r0, #0
	bne _020609CE
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _0206091A
	add r4, r6, #0
	b _02060932
_0206091A:
	add r0, r5, #0
	mov r1, #1
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060932
	add r4, r6, #0
_02060932:
	bl GetMetatileBehavior_None
	cmp r4, r0
	beq _020609CE
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetFlag24
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #1
	bne _02060950
	mov r1, #2
	b _02060960
_02060950:
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	bne _0206095E
	mov r1, #0
	b _02060960
_0206095E:
	mov r1, #1
_02060960:
	add r0, r5, #0
	bl ov01_021FDF88
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
_0206096A:
	add r0, r5, #0
	bl MapObject_CheckFlag24
	cmp r0, #0
	bne _020609CE
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060982
	add r4, r6, #0
	b _0206099A
_02060982:
	add r0, r5, #0
	mov r1, #1
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _0206099A
	add r4, r6, #0
_0206099A:
	bl GetMetatileBehavior_None
	cmp r4, r0
	beq _020609CE
	add r0, r5, #0
	mov r1, #1
	bl MapObject_SetFlag24
	add r0, r4, #0
	bl MetatileBehavior_IsReflective
	cmp r0, #1
	bne _020609B8
	mov r1, #2
	b _020609C8
_020609B8:
	add r0, r4, #0
	bl MetatileBehavior_IsPuddle
	cmp r0, #1
	bne _020609C6
	mov r1, #0
	b _020609C8
_020609C6:
	mov r1, #1
_020609C8:
	add r0, r5, #0
	bl ov01_021FDA74
_020609CE:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020607D8
	thumb_func_start sub_020609D4
sub_020609D4: ; 0x020609D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	ldrh r1, [r3]
	add r5, r0, #0
	lsl r1, r1, #0x13
	lsr r1, r1, #0x1e
	beq _02060AB2
	bl MapObject_CheckFlag24
	cmp r0, #0
	beq _02060AB2
	add r0, r5, #0
	bl MapObject_GetID
	cmp r0, #0xfd
	bne _02060A96
	add r0, r5, #0
	bl ov01_022055DC
	cmp r0, #0
	beq _02060A96
	add r0, r5, #0
	mov r1, #1
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	add r0, r5, #0
	mov r1, #3
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #2
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	add r0, r5, #0
	mov r1, #4
	bl ov01_022056C4
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r5, #0
	mov r1, #5
	bl ov01_022056C4
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	ldr r0, [sp, #8]
	mov r4, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060A50
	mov r4, #1
	b _02060A86
_02060A50:
	ldr r0, [sp, #4]
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060A5E
	mov r4, #1
	b _02060A86
_02060A5E:
	ldr r0, [sp]
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060A6C
	mov r4, #1
	b _02060A86
_02060A6C:
	add r0, r7, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060A7A
	mov r4, #1
	b _02060A86
_02060A7A:
	add r0, r6, #0
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #1
	bne _02060A86
	mov r4, #1
_02060A86:
	cmp r4, #0
	bne _02060AB2
	add r0, r5, #0
	mov r1, #0
	bl MapObject_SetFlag24
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_02060A96:
	add r0, r5, #0
	mov r1, #1
	bl sub_02060FA8
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	bl MetatileBehavior_HasReflectiveSurface
	cmp r0, #0
	bne _02060AB2
	add r0, r5, #0
	mov r1, #0
	bl MapObject_SetFlag24
_02060AB2:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020609D4
