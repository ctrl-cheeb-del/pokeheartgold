#include "constants/easy_chat.h"
#include "constants/items.h"
#include "constants/maps.h"
#include "constants/moves.h"
#include "constants/species.h"
	.include "asm/macros.inc"
	.include "unk_02091880.inc"
	.include "global.inc"
	.public sECMenuSpecs

	.text

	thumb_func_start sub_020918D4
sub_020918D4: ; 0x020918D4
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	mov r4, #0
	str r0, [sp]
	add r7, r0, #0
	str r0, [sp, #8]
	add r0, #0x68
	ldr r5, _02091910 ; =sECMenuSpecs
	str r4, [sp, #4]
	str r0, [sp, #8]
_020918E8:
	ldr r3, [sp, #8]
	str r4, [r7, #0x38]
	lsl r6, r4, #1
	add r3, r3, r6
	ldr r0, [sp]
	ldr r1, [r5, #4]
	ldr r2, [r5, #8]
	ldr r6, [r5]
	blx r6
	str r0, [r7, #8]
	add r4, r4, r0
	ldr r0, [sp, #4]
	add r7, r7, #4
	add r0, r0, #1
	add r5, #0xc
	str r0, [sp, #4]
	cmp r0, #0xc
	blt _020918E8
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_02091910: .word sECMenuSpecs
	thumb_func_end sub_020918D4
