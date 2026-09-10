#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
#include "constants/ribbon.h"
#include "constants/field_move_response.h"
#include "msgdata/msg/msg_0300.h"
	.include "asm/macros.inc"
	.include "unk_02088288.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020887C4
sub_020887C4: ; 0x020887C4
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r5, r0, #0
	mov r0, #2
	lsl r0, r0, #8
	str r0, [sp]
	mov r0, #0x13
	mov r1, #0
	add r4, r2, #0
	str r0, [sp, #4]
	add r0, r4, #0
	add r2, r1, #0
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0
	mov r0, #0x11
	str r1, [sp]
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x13
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #2
	mov r3, #3
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x13
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #0xd
	mov r3, #3
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #2
	lsl r0, r0, #8
	str r0, [sp]
	mov r0, #0x13
	mov r1, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #4
	add r3, r1, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r1, #0
	mov r0, #0x11
	str r1, [sp]
	lsl r0, r0, #0xa
	str r0, [sp, #4]
	str r1, [sp, #8]
	mov r0, #0x13
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #1
	mov r3, #6
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x13
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #0x14
	mov r3, #5
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #0x13
	str r0, [sp, #0xc]
	ldr r2, [r5]
	add r0, r4, #0
	mov r1, #0x15
	mov r3, #5
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end sub_020887C4
