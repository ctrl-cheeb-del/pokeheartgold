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
	.include "unk_02061284.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_020613F8
sub_020613F8: ; 0x020613F8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	bl sub_0205F394
	add r4, r0, #0
	mov r0, #0
	ldrsh r0, [r4, r0]
	cmp r0, #4
	bhi _020614EE
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02061416: ; jump table
	.short _02061420 - _02061416 - 2 ; case 0
	.short _0206144A - _02061416 - 2 ; case 1
	.short _02061468 - _02061416 - 2 ; case 2
	.short _0206147E - _02061416 - 2 ; case 3
	.short _020614DA - _02061416 - 2 ; case 4
_02061420:
	add r0, r5, #0
	bl MapObject_ClearSingleMovement
	add r0, r5, #0
	bl MapObject_ClearEndMovement
	add r0, r5, #0
	bl MapObject_GetFacingDirection
	mov r1, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_ForceSetHeldMovement
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4]
	pop {r4, r5, r6, pc}
_0206144A:
	add r0, r5, #0
	bl sub_02062428
	cmp r0, #0
	beq _020614EE
	mov r1, #0
	ldr r0, _020614F0 ; =_020FD7B8
	mvn r1, r1
	bl sub_02061E20
	strh r0, [r4, #2]
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4]
_02061468:
	mov r0, #2
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, #2]
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bne _020614EE
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4]
_0206147E:
	mov r1, #0
	ldr r0, [r4, #0xc]
	mvn r1, r1
	bl sub_02061E44
	add r6, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	bl MapObject_SetOrQueueFacing
	ldr r0, [r4, #4]
	cmp r0, #1
	bne _020614AA
	add r0, r5, #0
	add r1, r6, #0
	bl sub_020615F0
	cmp r0, #0
	bne _020614AA
	mov r0, #0
	strh r0, [r4]
	pop {r4, r5, r6, pc}
_020614AA:
	add r0, r5, #0
	add r1, r6, #0
	bl sub_02060BB8
	cmp r0, #0
	beq _020614BC
	mov r0, #0
	strh r0, [r4]
	pop {r4, r5, r6, pc}
_020614BC:
	ldr r1, [r4, #8]
	add r0, r6, #0
	bl sub_0206234C
	add r1, r0, #0
	add r0, r5, #0
	bl MapObject_ForceSetHeldMovement
	add r0, r5, #0
	bl MapObject_SetSingleMovement
	mov r0, #0
	ldrsh r0, [r4, r0]
	add r0, r0, #1
	strh r0, [r4]
_020614DA:
	add r0, r5, #0
	bl sub_02062428
	cmp r0, #0
	beq _020614EE
	add r0, r5, #0
	bl MapObject_ClearSingleMovement
	mov r0, #0
	strh r0, [r4]
_020614EE:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_020614F0: .word _020FD7B8
	thumb_func_end sub_020613F8
	thumb_func_start sub_020614F4
sub_020614F4: ; 0x020614F4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	str r0, [sp]
	add r4, r1, #0
	bl MapObject_GetInitialX
	add r6, r0, #0
	ldr r0, [sp]
	bl MapObject_GetInitialZ
	add r5, r0, #0
	ldr r0, [sp]
	bl MapObject_GetXRange
	add r7, r0, #0
	ldr r0, [sp]
	bl MapObject_GetYRange
	str r0, [sp, #4]
	ldr r0, [sp]
	bl MapObject_GetMovement
	cmp r0, #0xd
	bhi _020615E8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_02061530: ; jump table
	.short _020615E8 - _02061530 - 2 ; case 0
	.short _020615E8 - _02061530 - 2 ; case 1
	.short _020615E8 - _02061530 - 2 ; case 2
	.short _020615E8 - _02061530 - 2 ; case 3
	.short _020615E8 - _02061530 - 2 ; case 4
	.short _020615E8 - _02061530 - 2 ; case 5
	.short _0206154C - _02061530 - 2 ; case 6
	.short _0206155E - _02061530 - 2 ; case 7
	.short _02061570 - _02061530 - 2 ; case 8
	.short _02061582 - _02061530 - 2 ; case 9
	.short _02061594 - _02061530 - 2 ; case 10
	.short _020615AA - _02061530 - 2 ; case 11
	.short _020615C0 - _02061530 - 2 ; case 12
	.short _020615D4 - _02061530 - 2 ; case 13
_0206154C:
	sub r0, r6, r7
	str r0, [r4]
	ldr r0, [sp, #4]
	str r6, [r4, #8]
	sub r0, r5, r0
	str r0, [r4, #4]
	add sp, #8
	str r5, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_0206155E:
	str r6, [r4]
	add r0, r6, r7
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	add sp, #8
	sub r0, r5, r0
	str r0, [r4, #4]
	str r5, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_02061570:
	sub r0, r6, r7
	str r0, [r4]
	ldr r0, [sp, #4]
	str r6, [r4, #8]
	str r5, [r4, #4]
	add r0, r5, r0
	add sp, #8
	str r0, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_02061582:
	str r6, [r4]
	add r0, r6, r7
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	str r5, [r4, #4]
	add r0, r5, r0
	add sp, #8
	str r0, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_02061594:
	sub r0, r6, r7
	str r0, [r4]
	ldr r0, [sp, #4]
	str r6, [r4, #8]
	sub r0, r5, r0
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	add sp, #8
	add r0, r5, r0
	str r0, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_020615AA:
	str r6, [r4]
	add r0, r6, r7
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	sub r0, r5, r0
	str r0, [r4, #4]
	ldr r0, [sp, #4]
	add sp, #8
	add r0, r5, r0
	str r0, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_020615C0:
	sub r0, r6, r7
	str r0, [r4]
	add r0, r6, r7
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	add sp, #8
	sub r0, r5, r0
	str r0, [r4, #4]
	str r5, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_020615D4:
	sub r0, r6, r7
	str r0, [r4]
	add r0, r6, r7
	str r0, [r4, #8]
	ldr r0, [sp, #4]
	str r5, [r4, #4]
	add r0, r5, r0
	add sp, #8
	str r0, [r4, #0xc]
	pop {r3, r4, r5, r6, r7, pc}
_020615E8:
	bl GF_AssertFail
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_020614F4
	thumb_func_start sub_020615F0
sub_020615F0: ; 0x020615F0
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r1, #0
	add r5, r0, #0
	add r1, sp, #0
	bl sub_020614F4
	add r0, r5, #0
	bl MapObject_GetXCoord
	add r4, r0, #0
	add r0, r6, #0
	bl GetDeltaXByFacingDirection
	add r4, r4, r0
	add r0, r5, #0
	bl MapObject_GetZCoord
	add r5, r0, #0
	add r0, r6, #0
	bl GetDeltaYByFacingDirection
	add r1, r5, r0
	ldr r0, [sp]
	cmp r0, r4
	bgt _0206162A
	ldr r0, [sp, #8]
	cmp r0, r4
	bge _02061630
_0206162A:
	add sp, #0x10
	mov r0, #0
	pop {r4, r5, r6, pc}
_02061630:
	ldr r0, [sp, #4]
	cmp r0, r1
	bgt _0206163C
	ldr r0, [sp, #0xc]
	cmp r0, r1
	bge _02061642
_0206163C:
	add sp, #0x10
	mov r0, #0
	pop {r4, r5, r6, pc}
_02061642:
	mov r0, #1
	add sp, #0x10
	pop {r4, r5, r6, pc}
	thumb_func_end sub_020615F0

	.rodata

	.public _020FD4EC
	.public _020FD4EC
_020FD4EC:
	.word sub_02061C40
	.word sub_02061D50
	.public _020FD4F4
_020FD4F4:
	.word 0, 2, -1
	.public _020FD500
_020FD500:
	.word 1, 2, -1
	.public _020FD50C
_020FD50C:
	.word 2, 3, -1
	.public _020FD518
_020FD518:
	.word 0, 3, -1
	.public _020FD524
_020FD524:
	.word 1, 3, -1
	.public _020FD530
_020FD530:
	.word 0, 1, -1
	.public _020FD53C
_020FD53C:
	.word 2, 3, -1
	.public _020FD548
	.public _020FD548
_020FD548:
	.word sub_020619C0
	.word sub_020619FC
	.word sub_02061ABC
	.public _020FD554
_020FD554:
	.word 0, 1, -1
	.public _020FD560
_020FD560:
	.word 1, 0, 2, 3
	.public _020FD570
_020FD570:
	.word 2, 3, 0, 1
	.public _020FD580
_020FD580:
	.word 0, 1, 2, 3
	.public _020FD590
_020FD590:
	.word 0, 3, 1, 2
	.public _020FD5A0
	.public _020FD5A0
_020FD5A0:
	.word sub_02061874
	.word sub_02061894
	.word sub_020618B0
	.word sub_020618C8
	.public _020FD5B0
_020FD5B0:
	.word 1, 2, 3, 0
	.public _020FD5C0
_020FD5C0:
	.word 1, 3, 0, 2
	.public _020FD5D0
_020FD5D0:
	.word sub_02061720
	.word sub_02061754
	.word sub_02061770
	.word sub_020617AC
	.public _020FD5E0
_020FD5E0:
	.word 0x00000001, 0x00000002, 0x00000000, 0x00000003
	.public _020FD5F0
_020FD5F0:
	.word 0x00000002, 0x00000000, 0x00000003, 0x00000001
	.public _020FD600
_020FD600:
	.word 0x00000002, 0x00000003, 0x00000001, 0x00000000
	.public _020FD610
_020FD610:
	.word 0x00000000, 0x00000002, 0x00000001, 0x00000003
	.public _020FD620
_020FD620:
	.word 0x00000001, 0x00000000, 0x00000003, 0x00000002
	.public _020FD630
_020FD630:
	.word 0x00000002, 0x00000001, 0x00000000, 0x00000003
	.public _020FD640
_020FD640:
	.word 0x00000003, 0x00000002, 0x00000001, 0x00000000
	.public _020FD650
_020FD650:
	.word 0x00000000, 0x00000003, 0x00000002, 0x00000001
	.public _020FD660
_020FD660:
	.word 0x00000002, 0x00000000, 0x00000001, 0x00000003
	.public _020FD670
_020FD670:
	.word 0x00000000, 0x00000001, 0x00000003, 0x00000002
	.public _020FD680
_020FD680:
	.word 0x00000003, 0x00000000, 0x00000001, 0x00000002
	.public _020FD690
_020FD690:
	.word 0x00000002, 0x00000001, 0x00000003, 0x00000000
	.public _020FD6A0
_020FD6A0:
	.word 0x00000000, 0x00000001, 0x00000003, 0xFFFFFFFF
	.public _020FD6B0
_020FD6B0:
	.word 0x00000000, 0x00000002, 0x00000003, 0xFFFFFFFF
	.public _020FD6C0
_020FD6C0:
	.word 0x00000003, 0x00000002, 0x00000000, 0x00000001
	.public _020FD6D0
_020FD6D0:
	.word 0x00000001, 0x00000002, 0x00000003, 0xFFFFFFFF
	.public _020FD6E0
_020FD6E0:
	.word 0x00000000, 0x00000001, 0x00000002, 0xFFFFFFFF
	.public _020FD6F0
_020FD6F0:
	.word 0x00000001, 0x00000003, 0x00000002, 0x00000000
	.public _020FD700
_020FD700:
	.word 0x00000003, 0x00000000, 0x00000002, 0x00000001
	.public _020FD710
_020FD710:
	.word 0x00000003, 0x00000001, 0x00000002, 0x00000000
	.public _020FD720
_020FD720:
	.word 0x00000002, 0x00000003, 0x00000001, 0x00000000
	.public _020FD730
_020FD730:
	.word 0x00000003, 0x00000001, 0x00000000, 0x00000002
	.public _020FD740
_020FD740:
	.word 0x00000000, 0x00000001, 0x00000002, 0x00000003
	.word 0xFFFFFFFF
	.public _020FD754
_020FD754:
	.word 0x00000000, 0x00000002, 0x00000001
	.word 0x00000003, 0xFFFFFFFF
	.public _020FD768
_020FD768:
	.word 0x00000000, 0x00000003
	.word 0x00000001, 0x00000002, 0xFFFFFFFF
	.public _020FD77C
_020FD77C:
	.word 0x00000000
	.word 0x00000002, 0x00000001, 0x00000003, 0xFFFFFFFF
	.public _020FD790
_020FD790:
	.word 0x00000000, 0x00000001, 0x00000002, 0x00000003
	.word 0xFFFFFFFF
	.public _020FD7A4
_020FD7A4:
	.word 0x00000000, 0x00000003, 0x00000001
	.word 0x00000002, 0xFFFFFFFF
	.public _020FD7B8
	.public _020FD7B8
_020FD7B8:
	.word 0x00000010, 0x00000020
	.word 0x00000030, 0x00000040, 0xFFFFFFFF
	.public _020FD7CC
_020FD7CC:
	.word 0x00000000
	.word 0x00000001, 0x00000002, 0x00000003, 0xFFFFFFFF
	.public _020FD7E0
_020FD7E0:
	.byte 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00
	.byte 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00
	.public _020FD800
_020FD800:
	.byte 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00
	.byte 0x09, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00
	.byte 0x0D, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00
	.byte 0x13, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
	.public _020FD838
_020FD838:
	.word 0, _020FD7CC
	.word 0x00000001, _020FD4F4
	.word 0x00000002, _020FD518
	.word 0x00000003, _020FD500
	.word 0x00000004, _020FD524
	.word 0x00000005, _020FD6E0
	.word 0x00000006, _020FD6A0
	.word 0x00000007, _020FD6B0
	.word 0x00000008, _020FD6D0
	.word 0x00000009, _020FD554
	.word 0x0000000A, _020FD53C
	.word 0x0000000B, _020FD740
	.word 0x0000000C, _020FD530
	.word 0x0000000D, _020FD50C
	.word 0x0000000E, _020FD650
	.word 0x0000000F, _020FD640
	.word 0x00000010, _020FD620
	.word 0x00000011, _020FD630
	.word 0x00000012, _020FD720
	.word 0x00000013, _020FD600
	.word 0x00000014, _020FD560
	.word 0x00000015, _020FD730
	.word 0x00000016, _020FD660
	.word 0x00000017, _020FD670
	.word 0x00000018, _020FD6C0
	.word 0x00000019, _020FD6F0
	.word 0x0000001A, _020FD680
	.word 0x0000001B, _020FD580
	.word 0x0000001C, _020FD570
	.word 0x0000001D, _020FD5B0
	.word 0x0000001E, _020FD610
	.word 0x0000001F, _020FD5C0
	.word 0x00000020, _020FD690
	.word 0x00000021, _020FD700
	.word 0x00000022, _020FD590
	.word 0x00000023, _020FD5E0
	.word 0x00000024, _020FD5F0
	.word 0x00000025, _020FD710
	.word 0x00000026, _020FD790
	.word 0x00000027, 0
