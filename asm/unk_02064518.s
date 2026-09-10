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
	.include "unk_020632B0.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02064518
sub_02064518: ; 0x02064518
	ldr r3, _0206451C ; =MapObject_GetTrainerNum
	bx r3
	.balign 4, 0
_0206451C: .word MapObject_GetTrainerNum
	thumb_func_end sub_02064518
	thumb_func_start sub_02064520
sub_02064520: ; 0x02064520
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	mov r0, #0
	add r4, r2, #0
	add r6, r3, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, sp, #0
	add r2, sp, #4
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #0
	beq _02064570
	add r7, sp, #0
_02064540:
	ldr r0, [sp]
	cmp r0, r4
	beq _02064560
	bl sub_02064298
	sub r0, r0, #1
	cmp r0, #1
	bhi _02064560
	ldr r0, [sp]
	bl MapObject_GetTrainerNum
	cmp r6, r0
	bne _02064560
	ldr r0, [sp]
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_02064560:
	add r0, r5, #0
	add r1, r7, #0
	add r2, sp, #4
	mov r3, #1
	bl MapObjectManager_GetNextObjectWithFlagFromIndex
	cmp r0, #0
	bne _02064540
_02064570:
	bl GF_AssertFail
	mov r0, #0
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_02064520
	thumb_func_start sub_0206457C
sub_0206457C: ; 0x0206457C
	push {r4, lr}
	sub sp, #0x10
	ldr r4, [sp, #0x18]
	str r4, [sp]
	ldr r4, [sp, #0x1c]
	str r4, [sp, #4]
	ldr r4, [sp, #0x20]
	str r4, [sp, #8]
	ldr r4, [sp, #0x24]
	str r4, [sp, #0xc]
	bl sub_020645B4
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end sub_0206457C
	thumb_func_start sub_02064598
sub_02064598: ; 0x02064598
	push {r4, lr}
	add r4, r0, #0
	bne _020645A2
	bl GF_AssertFail
_020645A2:
	add r0, r4, #0
	bl sub_0206460C
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_02064598
	thumb_func_start sub_020645AC
sub_020645AC: ; 0x020645AC
	ldr r3, _020645B0 ; =sub_02064618
	bx r3
	.balign 4, 0
_020645B0: .word sub_02064618
	thumb_func_end sub_020645AC
	thumb_func_start sub_020645B4
sub_020645B4: ; 0x020645B4
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #4
	mov r1, #0x30
	add r7, r2, #0
	str r3, [sp]
	bl Heap_AllocAtEnd
	add r4, r0, #0
	bne _020645CE
	bl GF_AssertFail
_020645CE:
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x30
	bl memset
	ldr r0, [sp]
	add r1, r4, #0
	str r0, [r4, #8]
	ldr r0, [sp, #0x18]
	mov r2, #0xff
	str r0, [r4, #0xc]
	ldr r0, [sp, #0x1c]
	str r0, [r4, #0x10]
	ldr r0, [sp, #0x20]
	str r0, [r4, #0x14]
	ldr r0, [sp, #0x24]
	str r0, [r4, #0x18]
	str r5, [r4, #0x2c]
	str r6, [r4, #0x24]
	ldr r0, _02064608 ; =sub_02064630
	str r7, [r4, #0x28]
	bl SysTask_CreateOnMainQueue
	add r4, r0, #0
	bne _02064604
	bl GF_AssertFail
_02064604:
	add r0, r4, #0
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_02064608: .word sub_02064630
	thumb_func_end sub_020645B4
	thumb_func_start sub_0206460C
sub_0206460C: ; 0x0206460C
	push {r3, lr}
	bl SysTask_GetData
	ldr r0, [r0, #4]
	pop {r3, pc}
	.balign 4, 0
	thumb_func_end sub_0206460C
	thumb_func_start sub_02064618
sub_02064618: ; 0x02064618
	push {r4, lr}
	add r4, r0, #0
	bl SysTask_GetData
	add r1, r0, #0
	mov r0, #4
	bl Heap_FreeExplicit
	add r0, r4, #0
	bl SysTask_Destroy
	pop {r4, pc}
	thumb_func_end sub_02064618
	thumb_func_start sub_02064630
sub_02064630: ; 0x02064630
	push {r3, r4, r5, lr}
	ldr r4, _02064648 ; =_020FE1A4
	add r5, r1, #0
_02064636:
	ldr r1, [r5]
	add r0, r5, #0
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	blx r1
	cmp r0, #1
	beq _02064636
	pop {r3, r4, r5, pc}
	nop
_02064648: .word _020FE1A4
	thumb_func_end sub_02064630
