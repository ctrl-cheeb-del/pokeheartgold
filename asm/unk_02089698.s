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
	thumb_func_start sub_02089698
sub_02089698: ; 0x02089698
	push {r3, r4, lr}
	sub sp, #0xc
	ldr r3, _02089788 ; =0x000007BE
	add r4, r0, #0
	ldrb r0, [r4, r3]
	cmp r0, #0
	beq _020896B0
	cmp r0, #1
	beq _020896F6
	cmp r0, #2
	beq _0208975E
	b _02089782
_020896B0:
	add r0, r3, #0
	add r0, #0xc
	ldrb r0, [r4, r0]
	add r1, r3, #0
	add r2, r3, #0
	str r0, [sp]
	add r0, r3, #0
	add r0, #0xd
	ldrb r0, [r4, r0]
	add r1, #0xf
	add r2, #0xa
	str r0, [sp, #4]
	add r0, r3, #0
	add r0, #0xe
	ldrb r0, [r4, r0]
	add r3, #0xb
	lsl r0, r0, #0x1c
	lsr r0, r0, #0x1c
	str r0, [sp, #8]
	ldrb r1, [r4, r1]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	ldr r0, [r4]
	bl BgTilemapRectChangePalette
	ldr r1, _0208978C ; =0x000007CD
	ldr r0, [r4]
	ldrb r1, [r4, r1]
	bl ScheduleBgTilemapBufferTransfer
	ldr r0, _02089788 ; =0x000007BE
	ldrb r1, [r4, r0]
	add r1, r1, #1
	strb r1, [r4, r0]
	b _02089782
_020896F6:
	add r0, r3, #0
	add r0, #0x10
	ldrb r0, [r4, r0]
	add r1, r0, #1
	add r0, r3, #0
	add r0, #0x10
	strb r1, [r4, r0]
	add r0, r3, #0
	add r0, #0x10
	ldrb r0, [r4, r0]
	cmp r0, #4
	bne _02089782
	add r0, r3, #0
	add r0, #0xc
	ldrb r0, [r4, r0]
	add r1, r3, #0
	add r2, r3, #0
	str r0, [sp]
	add r0, r3, #0
	add r0, #0xd
	ldrb r0, [r4, r0]
	add r1, #0xf
	add r2, #0xa
	str r0, [sp, #4]
	add r0, r3, #0
	add r0, #0xe
	ldrb r0, [r4, r0]
	add r3, #0xb
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1c
	str r0, [sp, #8]
	ldrb r1, [r4, r1]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	ldr r0, [r4]
	bl BgTilemapRectChangePalette
	ldr r1, _0208978C ; =0x000007CD
	ldr r0, [r4]
	ldrb r1, [r4, r1]
	bl ScheduleBgTilemapBufferTransfer
	ldr r1, _02089790 ; =0x000007CE
	mov r0, #0
	strb r0, [r4, r1]
	add r0, r1, #0
	sub r0, #0x10
	ldrb r0, [r4, r0]
	sub r1, #0x10
	add r0, r0, #1
	strb r0, [r4, r1]
	b _02089782
_0208975E:
	add r0, r3, #0
	add r0, #0x10
	ldrb r0, [r4, r0]
	add r1, r0, #1
	add r0, r3, #0
	add r0, #0x10
	strb r1, [r4, r0]
	add r0, r3, #0
	add r0, #0x10
	ldrb r0, [r4, r0]
	cmp r0, #2
	bne _02089782
	mov r0, #0
	strb r0, [r4, r3]
	add r3, #0x11
	add sp, #0xc
	ldrb r0, [r4, r3]
	pop {r3, r4, pc}
_02089782:
	mov r0, #0xf
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
_02089788: .word 0x000007BE
_0208978C: .word 0x000007CD
_02089790: .word 0x000007CE
	thumb_func_end sub_02089698
	thumb_func_start sub_02089794
sub_02089794: ; 0x02089794
	push {r4, lr}
	ldr r1, _020897BC ; =0x000007C9
	add r4, r0, #0
	ldrb r1, [r4, r1]
	cmp r1, #5
	bne _020897AA
	mov r1, #0
	mvn r1, r1
	bl sub_0208A2C0
	b _020897B0
_020897AA:
	mov r1, #1
	bl sub_0208A2C0
_020897B0:
	add r0, r4, #0
	bl sub_0208B118
	mov r0, #0x13
	pop {r4, pc}
	nop
_020897BC: .word 0x000007C9
	thumb_func_end sub_02089794
	thumb_func_start sub_020897C0
sub_020897C0: ; 0x020897C0
	push {r4, lr}
	add r4, r0, #0
	bl sub_0208A520
	mov r2, #0x8b
	lsl r2, r2, #2
	add r1, r0, #0
	ldr r0, [r4, r2]
	ldrb r0, [r0, #0x11]
	cmp r0, #2
	bne _020897E2
	add r2, r2, #4
	add r0, r4, #0
	add r2, r4, r2
	bl sub_020897F0
	pop {r4, pc}
_020897E2:
	add r2, r2, #4
	add r0, r4, #0
	add r2, r4, r2
	bl sub_0208981C
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end sub_020897C0
	thumb_func_start sub_020897F0
sub_020897F0: ; 0x020897F0
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	mov r0, #0x13
	add r6, r1, #0
	add r7, r2, #0
	bl AllocMonZeroed
	add r4, r0, #0
	add r0, r6, #0
	add r1, r4, #0
	bl CopyBoxPokemonToPokemon
	add r0, r5, #0
	add r1, r4, #0
	add r2, r7, #0
	bl sub_0208981C
	add r0, r4, #0
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_020897F0
	thumb_func_start sub_0208981C
sub_0208981C: ; 0x0208981C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	add r7, r0, #0
	add r0, r5, #0
	add r4, r2, #0
	bl AcquireMonLock
	str r0, [sp, #4]
	add r0, r5, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0xc]
	add r0, r5, #0
	bl Mon_GetBoxMon
	mov r2, #0x7a
	lsl r2, r2, #4
	add r6, r0, #0
	ldr r0, [r7, r2]
	add r2, #0xc
	ldr r2, [r7, r2]
	mov r1, #0xb
	bl ReadMsgDataIntoString
	ldr r0, _02089BC0 ; =0x000007A8
	mov r1, #0
	ldr r0, [r7, r0]
	add r2, r6, #0
	bl BufferBoxMonSpeciesName
	ldr r2, _02089BC0 ; =0x000007A8
	mov r1, #0x23
	ldr r0, [r7, r2]
	lsl r1, r1, #4
	add r2, r2, #4
	ldr r1, [r7, r1]
	ldr r2, [r7, r2]
	bl StringExpandPlaceholders
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r7, r2]
	add r2, #0xc
	ldr r2, [r7, r2]
	mov r1, #0
	bl ReadMsgDataIntoString
	ldr r0, _02089BC0 ; =0x000007A8
	mov r1, #0
	ldr r0, [r7, r0]
	add r2, r6, #0
	bl BufferBoxMonNickname
	ldr r2, _02089BC0 ; =0x000007A8
	mov r1, #0x8d
	ldr r0, [r7, r2]
	lsl r1, r1, #2
	add r2, r2, #4
	ldr r1, [r7, r1]
	ldr r2, [r7, r2]
	bl StringExpandPlaceholders
	mov r2, #0x7a
	lsl r2, r2, #4
	ldr r0, [r7, r2]
	add r2, #0xc
	ldr r2, [r7, r2]
	mov r1, #0xe
	bl ReadMsgDataIntoString
	ldr r0, _02089BC0 ; =0x000007A8
	mov r1, #0
	ldr r0, [r7, r0]
	add r2, r6, #0
	bl BufferBoxMonOTName
	ldr r2, _02089BC0 ; =0x000007A8
	mov r1, #0x8e
	ldr r0, [r7, r2]
	lsl r1, r1, #2
	add r2, r2, #4
	ldr r1, [r7, r1]
	ldr r2, [r7, r2]
	bl StringExpandPlaceholders
	add r0, r5, #0
	mov r1, #6
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0xe]
	add r0, r5, #0
	mov r1, #0xa1
	mov r2, #0
	bl GetMonData
	ldrb r1, [r4, #0x12]
	mov r2, #0x7f
	lsl r0, r0, #0x18
	bic r1, r2
	lsr r2, r0, #0x18
	mov r0, #0x7f
	and r0, r2
	orr r0, r1
	strb r0, [r4, #0x12]
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	lsl r0, r0, #0x1f
	ldr r2, [r4, #0x50]
	ldr r1, _02089BC4 ; =0xEFFFFFFF
	lsr r0, r0, #3
	and r1, r2
	orr r0, r1
	str r0, [r4, #0x50]
	add r0, r5, #0
	mov r1, #0xb0
	mov r2, #0
	bl GetMonData
	cmp r0, #1
	bne _0208992C
	ldr r0, [r4, #0x50]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	bne _0208992C
	ldrb r1, [r4, #0x12]
	mov r0, #0x80
	bic r1, r0
	strb r1, [r4, #0x12]
	b _02089934
_0208992C:
	ldrb r1, [r4, #0x12]
	mov r0, #0x80
	orr r0, r1
	strb r0, [r4, #0x12]
_02089934:
	add r0, r5, #0
	bl GetMonGender
	ldrb r1, [r4, #0x13]
	mov r2, #3
	bic r1, r2
	mov r2, #3
	and r0, r2
	orr r0, r1
	strb r0, [r4, #0x13]
	add r0, r5, #0
	mov r1, #0x9b
	mov r2, #0
	bl GetMonData
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	lsl r0, r0, #0x1a
	ldrb r1, [r4, #0x13]
	mov r2, #0xfc
	lsr r0, r0, #0x18
	bic r1, r2
	orr r0, r1
	strb r0, [r4, #0x13]
	add r0, r5, #0
	mov r1, #0xb1
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #0x10]
	add r0, r5, #0
	mov r1, #0xb2
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #0x11]
	add r0, r5, #0
	mov r1, #7
	mov r2, #0
	bl GetMonData
	str r0, [r4, #0x14]
	add r0, r5, #0
	mov r1, #8
	mov r2, #0
	bl GetMonData
	str r0, [r4, #0x18]
	add r0, r5, #0
	mov r1, #0x9d
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x44
	strb r0, [r1]
	ldrb r1, [r4, #0x12]
	ldrh r0, [r4, #0xc]
	lsl r1, r1, #0x19
	lsr r1, r1, #0x19
	bl GetMonExpBySpeciesAndLevel
	str r0, [r4, #0x1c]
	ldrb r0, [r4, #0x12]
	lsl r0, r0, #0x19
	lsr r1, r0, #0x19
	cmp r1, #0x64
	bne _020899C0
	ldr r0, [r4, #0x1c]
	b _020899C8
_020899C0:
	ldrh r0, [r4, #0xc]
	add r1, r1, #1
	bl GetMonExpBySpeciesAndLevel
_020899C8:
	str r0, [r4, #0x20]
	add r0, r5, #0
	mov r1, #0xa3
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x24]
	add r0, r5, #0
	mov r1, #0xa4
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x26]
	add r0, r5, #0
	mov r1, #0xa5
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x28]
	add r0, r5, #0
	mov r1, #0xa6
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x2a]
	add r0, r5, #0
	mov r1, #0xa8
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x2c]
	add r0, r5, #0
	mov r1, #0xa9
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x2e]
	add r0, r5, #0
	mov r1, #0xa7
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #0x30]
	add r0, r5, #0
	mov r1, #0xa
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x32
	strb r0, [r1]
	add r0, r5, #0
	bl GetMonNature
	add r1, r4, #0
	add r1, #0x33
	strb r0, [r1]
	mov r6, #0
_02089A3C:
	lsl r0, r6, #1
	add r0, r4, r0
	add r1, r6, #0
	str r0, [sp]
	add r0, r5, #0
	add r1, #0x36
	mov r2, #0
	bl GetMonData
	ldr r1, [sp]
	mov r2, #0
	strh r0, [r1, #0x34]
	add r1, r6, #0
	add r0, r5, #0
	add r1, #0x3a
	bl GetMonData
	add r1, r4, r6
	add r1, #0x3c
	strb r0, [r1]
	add r1, r6, #0
	add r0, r5, #0
	add r1, #0x3e
	mov r2, #0
	bl GetMonData
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp]
	ldrh r0, [r0, #0x34]
	bl GetMoveMaxPP
	add r1, r4, r6
	add r1, #0x40
	strb r0, [r1]
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #4
	blo _02089A3C
	add r0, r5, #0
	mov r1, #0x13
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x45
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0x14
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x46
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0x15
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x47
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0x16
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x48
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0x17
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x49
	strb r0, [r1]
	add r0, r5, #0
	mov r1, #0x18
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x4a
	strb r0, [r1]
	add r0, r4, #0
	mov r1, #5
	add r0, #0x4b
	strb r1, [r0]
	mov r6, #0
_02089AF6:
	add r0, r5, #0
	add r1, r6, #0
	bl MonGetFlavorPreference
	cmp r0, #1
	bne _02089B0A
	add r0, r4, #0
	add r0, #0x4b
	strb r6, [r0]
	b _02089B14
_02089B0A:
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #5
	blo _02089AF6
_02089B14:
	add r0, r5, #0
	mov r1, #0xb
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x4c
	strh r0, [r1]
	add r0, r5, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	add r1, r4, #0
	add r1, #0x4e
	strh r0, [r1]
	add r0, r5, #0
	bl Pokemon_GetStatusIconId
	mov r1, #0xf
	ldr r2, [r4, #0x50]
	lsl r1, r1, #0x1c
	and r2, r1
	ldr r1, _02089BC8 ; =0x0FFFFFFF
	and r0, r1
	orr r0, r2
	str r0, [r4, #0x50]
	add r0, r5, #0
	bl Pokemon_IsImmuneToPokerus
	cmp r0, #1
	bne _02089B64
	ldr r1, [r4, #0x50]
	ldr r0, _02089BCC ; =0x3FFFFFFF
	and r1, r0
	mov r0, #2
	lsl r0, r0, #0x1e
	orr r0, r1
	str r0, [r4, #0x50]
	b _02089B9A
_02089B64:
	add r0, r5, #0
	bl Pokemon_HasPokerus
	cmp r0, #1
	bne _02089B92
	ldr r2, [r4, #0x50]
	ldr r1, _02089BCC ; =0x3FFFFFFF
	add r0, r4, #0
	and r2, r1
	add r1, r1, #1
	orr r1, r2
	str r1, [r4, #0x50]
	lsl r1, r1, #4
	lsr r1, r1, #4
	add r0, #0x50
	cmp r1, #7
	bne _02089B9A
	mov r1, #0xf
	ldr r2, [r0]
	lsl r1, r1, #0x1c
	and r1, r2
	str r1, [r0]
	b _02089B9A
_02089B92:
	ldr r1, [r4, #0x50]
	ldr r0, _02089BCC ; =0x3FFFFFFF
	and r0, r1
	str r0, [r4, #0x50]
_02089B9A:
	add r0, r5, #0
	bl MonIsShiny
	cmp r0, #1
	ldr r1, [r4, #0x50]
	bne _02089BAE
	mov r0, #2
	lsl r0, r0, #0x1c
	orr r0, r1
	b _02089BB2
_02089BAE:
	ldr r0, _02089BD0 ; =0xDFFFFFFF
	and r0, r1
_02089BB2:
	str r0, [r4, #0x50]
	mov r6, #0
	str r6, [r4, #0x54]
	str r6, [r4, #0x58]
	str r6, [r4, #0x5c]
	ldr r0, _02089BD4 ; =0x000007C6
	b _02089BD8
	.balign 4, 0
_02089BC0: .word 0x000007A8
_02089BC4: .word 0xEFFFFFFF
_02089BC8: .word 0x0FFFFFFF
_02089BCC: .word 0x3FFFFFFF
_02089BD0: .word 0xDFFFFFFF
_02089BD4: .word 0x000007C6
_02089BD8:
	str r6, [r4, #0x60]
	strb r6, [r7, r0]
_02089BDC:
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	mov r1, #0
	bl GetRibbonAttr
	add r1, r0, #0
	add r0, r5, #0
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _02089C14
	lsr r0, r6, #5
	lsl r0, r0, #2
	add r0, r4, r0
	mov r1, #0x1f
	add r2, r6, #0
	and r2, r1
	mov r1, #1
	ldr r3, [r0, #0x54]
	lsl r1, r2
	orr r1, r3
	str r1, [r0, #0x54]
	ldr r0, _02089C4C ; =0x000007C6
	ldrb r0, [r7, r0]
	add r1, r0, #1
	ldr r0, _02089C4C ; =0x000007C6
	strb r1, [r7, r0]
_02089C14:
	add r0, r6, #1
	lsl r0, r0, #0x10
	lsr r6, r0, #0x10
	cmp r6, #0x50
	blo _02089BDC
	mov r6, #0xa5
	mov r4, #0
	lsl r6, r6, #2
_02089C24:
	add r1, r4, #0
	add r0, r5, #0
	add r1, #0xb5
	mov r2, #0
	bl GetMonData
	add r1, r7, r4
	strb r0, [r1, r6]
	add r0, r4, #1
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r4, #6
	blo _02089C24
	ldr r1, [sp, #4]
	add r0, r5, #0
	bl ReleaseMonLock
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02089C4C: .word 0x000007C6
	thumb_func_end sub_0208981C
	thumb_func_start sub_02089C50
sub_02089C50: ; 0x02089C50
	push {r4, lr}
	sub sp, #8
	mov r2, #0xa
	add r4, r0, #0
	lsl r2, r2, #6
	ldr r0, [r4, r2]
	lsl r0, r0, #3
	lsr r0, r0, #0x1f
	bne _02089CAA
	ldr r0, _02089CB0 ; =0x000007B8
	sub r2, #0x44
	ldrh r2, [r4, r2]
	ldr r0, [r4, r0]
	add r1, sp, #4
	mov r3, #1
	bl sub_020729A4
	mov r2, #0x8f
	lsl r2, r2, #2
	add r1, r2, #0
	ldrh r0, [r4, r2]
	sub r1, #0x83
	cmp r0, r1
	bne _02089C9A
	add r0, sp, #4
	ldrb r0, [r0]
	mov r1, #0
	sub r2, #0x10
	str r0, [sp]
	ldr r0, [r4, r2]
	mov r2, #0x64
	ldr r0, [r0, #0x28]
	add r3, r1, #0
	bl sub_02006EA0
	add sp, #8
	pop {r4, pc}
_02089C9A:
	add r2, #0x42
	ldrh r2, [r4, r2]
	add r1, sp, #4
	ldrb r1, [r1]
	lsl r2, r2, #0x18
	lsr r2, r2, #0x18
	bl sub_020062E0
_02089CAA:
	add sp, #8
	pop {r4, pc}
	nop
_02089CB0: .word 0x000007B8
	thumb_func_end sub_02089C50
	thumb_func_start sub_02089CB4
sub_02089CB4: ; 0x02089CB4
	push {r4, lr}
	add r4, r0, #0
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #0
	beq _02089CCE
	cmp r0, #1
	beq _02089CCE
	cmp r0, #2
	beq _02089CD6
	b _02089CDC
_02089CCE:
	ldr r0, _02089D3C ; =0x000007BC
	mov r1, #0
	strb r1, [r4, r0]
	b _02089CDC
_02089CD6:
	ldr r0, _02089D3C ; =0x000007BC
	mov r1, #1
	strb r1, [r4, r0]
_02089CDC:
	add r0, r4, #0
	bl sub_0208B448
	add r0, r4, #0
	bl sub_0208B5A8
	add r0, r4, #0
	bl sub_0208C2A0
	add r0, r4, #0
	bl sub_0208BD38
	add r0, r4, #0
	bl sub_0208BCD4
	add r0, r4, #0
	bl sub_0208C42C
	add r0, r4, #0
	bl sub_0208CBD4
	add r0, r4, #0
	bl sub_02089F98
	add r0, r4, #0
	bl sub_0208B9C8
	mov r0, #0x8b
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	ldrb r0, [r0, #0x12]
	cmp r0, #2
	bne _02089D26
	add r0, r4, #0
	bl sub_0208A8F4
	pop {r4, pc}
_02089D26:
	add r0, r4, #0
	bl sub_0208B400
	add r0, r4, #0
	bl sub_0208BF9C
	add r0, r4, #0
	bl sub_0208BFD0
	pop {r4, pc}
	nop
_02089D3C: .word 0x000007BC
	thumb_func_end sub_02089CB4
