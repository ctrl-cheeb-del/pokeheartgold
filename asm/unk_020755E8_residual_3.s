#include "constants/items.h"
#include "constants/moves.h"
#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.include "unk_020755E8.inc"
	.include "global.inc"

	.text
	.public sub_020755E8
	.public sub_02075630
	.public sub_02075770
	.public sub_020757AC
	.public sub_02075804
	.public sub_0207584C
	.public sub_020758D0
	.public sub_020759CC
	.public sub_02075A04
	.public sub_02075A7C
	.public sub_02075D08
	.public sub_02075D3C
	.public sub_02075D4C
	.public sub_02075E14
	.public sub_02076C90
	.public sub_02076E64
	.public sub_020771A0
	.public sub_020771E8
	.public sub_02077270
	.public sub_020772F8
	.public sub_02077340
	.public sub_02077394
	.public sub_020755E8
	.public sub_02075630
	.public sub_02075770
	.public sub_020757AC
	.public sub_02075804
	.public sub_0207584C
	.public sub_020758D0
	.public sub_020759CC
	.public sub_02075A04
	.public sub_02075D08
	.public sub_02075D3C
	.public sub_02075D4C
	.public sub_020771A0
	.public sub_020771E8
	.public sub_020772F8
	.public sub_02077340
	.public sub_02077394

	thumb_func_start sub_02077270
sub_02077270: ; 0x02077270
	push {r3, r4, r5, lr}
	add r4, r0, #0
	add r0, #0x75
	ldrb r2, [r0]
	add r0, r4, #0
	add r0, #0x73
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0x72
	ldrb r0, [r0]
	mov r3, #0xff
	lsl r3, r3, #8
	lsl r0, r0, #8
	add r5, r0, #0
	add r0, r4, #0
	add r0, #0x74
	lsl r1, r1, #8
	and r1, r3
	ldrb r0, [r0]
	and r5, r3
	orr r1, r2
	orr r5, r0
	ldr r0, _020772EC ; =0x04000040
	strh r5, [r0]
	strh r1, [r0, #4]
	ldr r0, [r4, #0x18]
	bl PokepicManager_HandleLoadImgAndOrPltt
	add r0, r4, #0
	add r0, #0xb8
	ldr r0, [r0]
	cmp r0, #0
	beq _020772CE
	add r0, r4, #0
	add r0, #0xb0
	ldr r0, [r0]
	cmp r0, #0
	bne _020772C0
	bl GF_AssertFail
_020772C0:
	add r0, r4, #0
	add r0, #0xb0
	ldr r0, [r0]
	bl SpriteSystem_DrawSprites
	bl SpriteSystem_TransferOam
_020772CE:
	bl GF_RunVramTransferTasks
	ldr r0, [r4, #0x14]
	bl PaletteData_PushTransparentBuffers
	ldr r0, [r4]
	bl DoScheduledBgGpuUpdates
	ldr r3, _020772F0 ; =OS_IRQTable
	ldr r1, _020772F4 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	pop {r3, r4, r5, pc}
	.balign 4, 0
_020772EC: .word 0x04000040
_020772F0: .word OS_IRQTable
_020772F4: .word 0x00003FF8
	thumb_func_end sub_02077270
