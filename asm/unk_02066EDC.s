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
	.include "unk_02066EDC.inc"
	.include "global.inc"

	.text

	thumb_func_start sub_02066EDC
sub_02066EDC: ; 0x02066EDC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	add r0, r2, #0
	mov r1, #0x44
	bl Heap_AllocAtEnd
	ldr r7, [r6, #0xc]
	mov r1, #0
	mov r2, #0x44
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r7, #0
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #0xc]
	add r0, r7, #0
	bl SaveArray_Party_Get
	str r0, [r4]
	add r0, r7, #0
	bl Save_Bag_Get
	str r0, [r4, #4]
	add r0, r4, #0
	mov r2, #0
	add r0, #0x25
	strb r2, [r0]
	add r0, r4, #0
	ldrb r1, [r5, #8]
	add r0, #0x24
	strb r1, [r0]
	add r0, r4, #0
	add r0, #0x36
	ldrb r1, [r0]
	mov r0, #0xf
	ldrb r3, [r5, #0xa]
	bic r1, r0
	mov r0, #0xf
	and r3, r0
	orr r3, r1
	add r1, r4, #0
	add r1, #0x36
	strb r3, [r1]
	add r1, r4, #0
	add r1, #0x36
	add r0, #0xfd
	ldrb r1, [r1]
	mov r3, #0xf0
	add r0, r6, r0
	bic r1, r3
	ldrb r3, [r5, #0xb]
	lsl r3, r3, #0x1c
	lsr r3, r3, #0x18
	orr r3, r1
	add r1, r4, #0
	add r1, #0x36
	strb r3, [r1]
	add r1, r4, #0
	ldrb r3, [r5, #0xc]
	add r1, #0x37
	strb r3, [r1]
	add r1, r4, #0
	ldrb r3, [r5, #0xd]
	add r1, #0x26
	strb r3, [r1]
	str r0, [r4, #0x20]
_02066F64:
	add r0, r5, r2
	ldrb r1, [r0, #0xe]
	add r0, r4, r2
	add r0, #0x30
	strb r1, [r0]
	add r0, r2, #1
	lsl r0, r0, #0x18
	lsr r2, r0, #0x18
	cmp r2, #6
	blo _02066F64
	ldr r1, _02066F8C ; =gOverlayTemplate_PartyMenu
	add r0, r6, #0
	add r2, r4, #0
	bl FieldSystem_LaunchApplication
	ldr r0, [r5, #0x14]
	str r4, [r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02066F8C: .word gOverlayTemplate_PartyMenu
	thumb_func_end sub_02066EDC
	thumb_func_start sub_02066F90
sub_02066F90: ; 0x02066F90
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r0, r1, #0
	bl FieldSystem_ApplicationIsRunning
	cmp r0, #0
	beq _02066FA2
	mov r0, #1
	pop {r3, r4, r5, pc}
_02066FA2:
	ldr r0, [r5, #0x14]
	ldr r4, [r0]
	add r0, r4, #0
	add r0, #0x26
	ldrb r0, [r0]
	cmp r0, #6
	beq _02066FBC
	cmp r0, #7
	bne _02066FC4
	mov r0, #0
	str r0, [r5]
	mov r0, #4
	pop {r3, r4, r5, pc}
_02066FBC:
	mov r0, #1
	str r0, [r5]
	mov r0, #4
	pop {r3, r4, r5, pc}
_02066FC4:
	add r0, r4, #0
	add r1, r5, #0
	add r0, #0x30
	add r1, #0xe
	mov r2, #6
	bl MI_CpuCopy8
	add r0, r4, #0
	add r0, #0x26
	ldrb r0, [r0]
	strb r0, [r5, #0xd]
	add r0, r4, #0
	bl Heap_Free
	ldr r0, [r5, #0x14]
	mov r1, #0
	str r1, [r0]
	mov r0, #2
	pop {r3, r4, r5, pc}
	.balign 4, 0
	thumb_func_end sub_02066F90
	thumb_func_start sub_02066FEC
sub_02066FEC: ; 0x02066FEC
	push {r3, r4, r5, r6, r7, lr}
	add r7, r1, #0
	add r6, r0, #0
	ldr r5, [r7, #0xc]
	add r0, r2, #0
	mov r1, #0x3c
	bl Heap_AllocAtEnd
	mov r1, #0
	mov r2, #0x3c
	add r4, r0, #0
	bl MI_CpuFill8
	add r0, r5, #0
	bl Save_PlayerData_GetOptionsAddr
	str r0, [r4, #4]
	add r0, r5, #0
	bl SaveArray_Party_Get
	str r0, [r4]
	add r0, r5, #0
	bl SaveArray_IsNatDexEnabled
	str r0, [r4, #0x1c]
	add r0, r5, #0
	bl sub_02088288
	str r0, [r4, #0x2c]
	mov r0, #1
	strb r0, [r4, #0x11]
	ldrb r0, [r6, #0xd]
	strb r0, [r4, #0x14]
	ldr r0, [r4]
	bl Party_GetCount
	strb r0, [r4, #0x13]
	mov r0, #0
	strh r0, [r4, #0x18]
	ldrb r0, [r6, #9]
	strb r0, [r4, #0x12]
	add r0, r5, #0
	bl Save_SpecialRibbons_Get
	str r0, [r4, #0x20]
	mov r0, #0x43
	lsl r0, r0, #2
	add r0, r7, r0
	str r0, [r4, #0x30]
	add r0, r5, #0
	bl sub_0208828C
	str r0, [r4, #0x34]
	ldr r1, _02067080 ; =_020FE4B0
	add r0, r4, #0
	bl sub_02089D40
	add r0, r5, #0
	bl Save_PlayerData_GetProfile
	add r1, r0, #0
	add r0, r4, #0
	bl sub_0208AD34
	ldr r1, _02067084 ; =gOverlayTemplate_PokemonSummary
	add r0, r7, #0
	add r2, r4, #0
	bl FieldSystem_LaunchApplication
	ldr r0, [r6, #0x14]
	str r4, [r0]
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02067080: .word _020FE4B0
_02067084: .word gOverlayTemplate_PokemonSummary
	thumb_func_end sub_02066FEC

	.rodata

	.public _020FE4B0
_020FE4B0:
	.byte 0x00, 0x01, 0x02, 0x03, 0x04
	.balign 4, 0
