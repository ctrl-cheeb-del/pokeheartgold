	.include "asm/macros.inc"
	.include "overlay_113.inc"
	.include "asm/include/overlay_113_split.inc"
	.include "global.inc"

	.text
	.public UnownReport_Exit
	.public ov113_021E59F8
	.public ov113_021E5A48
	.public ov113_021E5B60
	.public ov113_021E5B70
	.public ov113_021E5BB0
	.public ov113_021E5C60
	.public ov113_021E5CF8
	.public ov113_021E5D28
	.public ov113_021E5D4C
	.public ov113_021E5EC4
	.public ov113_021E6274
	.public ov113_021E629C
	.public ov113_021E62E0
	.public ov113_021E64DC
	.public ov113_021E663C
	.public ov113_021E66E4
	.public ov113_021E6754
	.public ov113_021E6930
	.public ov113_021E6988
	.public ov113_021E69A8

	thumb_func_start ov113_021E5ED0
ov113_021E5ED0: ; 0x021E5ED0
	push {r4, lr}
	add r4, r0, #0
	cmp r1, #0
	beq _021E5EE2
	cmp r1, #1
	beq _021E5EF4
	cmp r1, #2
	beq _021E5F16
	b _021E5F3C
_021E5EE2:
	ldr r0, _021E5F40 ; =0x000005DD
	bl PlaySE
	add r0, r4, #0
	mov r1, #1
	bl ov113_021E5E64
	mov r0, #1
	pop {r4, pc}
_021E5EF4:
	ldrb r0, [r4, #0x1a]
	cmp r0, #0
	bne _021E5EFE
	mov r0, #2
	pop {r4, pc}
_021E5EFE:
	sub r0, r0, #1
	strb r0, [r4, #0x1a]
	add r4, #0xbc
	ldr r0, [r4]
	mov r1, #3
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _021E5F44 ; =0x000005DC
	bl PlaySE
	mov r0, #3
	pop {r4, pc}
_021E5F16:
	ldrb r0, [r4, #0x1b]
	ldrb r1, [r4, #0x1a]
	sub r0, r0, #1
	cmp r1, r0
	blt _021E5F24
	mov r0, #2
	pop {r4, pc}
_021E5F24:
	add r0, r1, #1
	strb r0, [r4, #0x1a]
	add r4, #0xc0
	ldr r0, [r4]
	mov r1, #6
	bl Sprite_SetAnimCtrlSeq
	ldr r0, _021E5F44 ; =0x000005DC
	bl PlaySE
	mov r0, #3
	pop {r4, pc}
_021E5F3C:
	mov r0, #2
	pop {r4, pc}
	.balign 4, 0
_021E5F40: .word 0x000005DD
_021E5F44: .word 0x000005DC
	thumb_func_end ov113_021E5ED0


	thumb_func_start ov113_021E5F48
ov113_021E5F48: ; 0x021E5F48
	push {r3, lr}
	ldr r1, _021E5F8C ; =gSystem
	ldr r2, [r1, #0x48]
	ldr r1, _021E5F90 ; =0x00000CF3
	tst r1, r2
	beq _021E5F58
	mov r1, #0
	str r1, [r0, #0x14]
_021E5F58:
	ldr r1, _021E5F8C ; =gSystem
	ldr r3, [r1, #0x48]
	mov r1, #2
	add r2, r3, #0
	tst r2, r1
	beq _021E5F6C
	mov r1, #0
	bl ov113_021E5ED0
	pop {r3, pc}
_021E5F6C:
	mov r2, #0x40
	tst r2, r3
	beq _021E5F7A
	mov r1, #1
	bl ov113_021E5ED0
	pop {r3, pc}
_021E5F7A:
	mov r2, #0x80
	tst r2, r3
	beq _021E5F86
	bl ov113_021E5ED0
	pop {r3, pc}
_021E5F86:
	add r0, r1, #0
	pop {r3, pc}
	nop
_021E5F8C: .word gSystem
_021E5F90: .word 0x00000CF3
	thumb_func_end ov113_021E5F48


	thumb_func_start ov113_021E5F94
ov113_021E5F94: ; 0x021E5F94
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021E5FBC ; =ov113_021E6B82
	add r4, r1, #0
	bl TouchscreenHitbox_FindHitboxAtTouchNew
	add r1, r0, #0
	mov r0, #0
	mvn r0, r0
	cmp r1, r0
	bne _021E5FAE
	mov r0, #2
	pop {r3, r4, r5, pc}
_021E5FAE:
	mov r0, #1
	str r0, [r4]
	str r0, [r5, #0x14]
	add r0, r5, #0
	bl ov113_021E5ED0
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021E5FBC: .word ov113_021E6B82
	thumb_func_end ov113_021E5F94


	thumb_func_start ov113_021E5FC0
ov113_021E5FC0: ; 0x021E5FC0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	mov r1, #0x13
	add r6, r0, #0
	lsl r1, r1, #4
	add r1, r6, r1
	mov r2, #6
	bl ov113_021E6238
	mov r1, #1
	lsl r1, r1, #8
	add r0, r6, #0
	add r1, r6, r1
	mov r2, #2
	bl ov113_021E6238
	mov r4, #0
	add r5, r6, #0
	add r7, r4, #0
_021E5FE6:
	add r0, r5, #0
	add r0, #0xc4
	ldr r0, [r0]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #0xe
	blt _021E5FE6
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x50]
	mov r1, #1
	bl ReadMsgDataIntoString
	add r0, r6, #0
	ldr r1, [r6, #0x50]
	add r0, #0x78
	mov r2, #0
	mov r3, #0x38
	bl ov113_021E629C
	mov r0, #0
	ldr r1, [r6, #0x5c]
	add r2, r0, #0
	bl FontID_String_GetWidth
	add r3, r0, #0
	mov r2, #0xb0
	sub r2, r2, r3
	add r0, r6, #0
	lsl r2, r2, #0x10
	ldr r1, [r6, #0x5c]
	add r0, #0x78
	lsr r2, r2, #0x10
	mov r3, #0x48
	bl ov113_021E629C
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x50]
	mov r1, #3
	bl ReadMsgDataIntoString
	add r0, r6, #0
	ldr r1, [r6, #0x50]
	add r0, #0x88
	mov r2, #4
	mov r3, #0x3c
	bl ov113_021E629C
	ldr r0, [r6, #0x44]
	ldr r2, [r6, #0x4c]
	mov r1, #4
	bl ReadMsgDataIntoString
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldrb r2, [r6, #0x1f]
	ldr r0, [r6, #0x48]
	mov r1, #0
	mov r3, #2
	bl BufferIntegerAsString
	ldr r0, [r6, #0x48]
	ldr r1, [r6, #0x50]
	ldr r2, [r6, #0x4c]
	bl StringExpandPlaceholders
	add r0, r6, #0
	ldr r1, [r6, #0x50]
	add r0, #0x88
	mov r2, #4
	mov r3, #0x4c
	bl ov113_021E629C
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov113_021E5FC0


	thumb_func_start ov113_021E6084
ov113_021E6084: ; 0x021E6084
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r1, #0
	mov r1, #5
	add r5, r0, #0
	lsl r1, r1, #6
	add r1, r5, r1
	mov r2, #6
	bl ov113_021E6238
	mov r1, #0x11
	lsl r1, r1, #4
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #2
	bl ov113_021E6238
	mov r0, #0xe
	mul r0, r4
	str r0, [sp, #4]
	add r0, r5, #0
	str r0, [sp, #0xc]
	add r0, #0x88
	str r0, [sp, #0xc]
	add r0, r5, #0
	mov r4, #0
	str r0, [sp, #8]
	add r0, #0x78
	str r5, [sp]
	add r6, r4, #0
	str r0, [sp, #8]
_021E60C2:
	ldr r0, [sp, #4]
	add r7, r0, r4
	ldrb r0, [r5, #0x1f]
	cmp r7, r0
	blt _021E60DA
	ldr r0, [sp]
	mov r1, #0
	add r0, #0xc4
	ldr r0, [r0]
	bl ManagedSprite_SetDrawFlag
	b _021E612A
_021E60DA:
	ldr r0, [sp]
	mov r1, #1
	add r0, #0xc4
	ldr r0, [r0]
	bl ManagedSprite_SetDrawFlag
	add r2, r5, r7
	add r2, #0x20
	ldrb r2, [r2]
	add r0, r5, #0
	add r1, r4, #0
	bl ov113_021E6AE8
	add r1, r5, r7
	add r1, #0x20
	ldrb r1, [r1]
	ldr r0, [r5, #0x44]
	ldr r2, [r5, #0x50]
	add r1, #0x14
	bl ReadMsgDataIntoString
	cmp r4, #7
	bge _021E6118
	lsl r3, r6, #0x10
	ldr r0, [sp, #8]
	ldr r1, [r5, #0x50]
	mov r2, #0x30
	lsr r3, r3, #0x10
	bl ov113_021E629C
	b _021E612A
_021E6118:
	add r3, r6, #0
	sub r3, #0xa8
	lsl r3, r3, #0x10
	ldr r0, [sp, #0xc]
	ldr r1, [r5, #0x50]
	mov r2, #0x30
	lsr r3, r3, #0x10
	bl ov113_021E629C
_021E612A:
	ldr r0, [sp]
	add r4, r4, #1
	add r0, r0, #4
	add r6, #0x18
	str r0, [sp]
	cmp r4, #0xe
	blt _021E60C2
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov113_021E6084


	thumb_func_start ov113_021E613C
ov113_021E613C: ; 0x021E613C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	str r1, [sp, #4]
	cmp r1, #0
	bne _021E617C
	mov r1, #0x15
	lsl r1, r1, #4
	add r1, r5, r1
	mov r2, #6
	bl ov113_021E6238
	mov r1, #0x12
	lsl r1, r1, #4
	add r0, r5, #0
	add r1, r5, r1
	mov r2, #2
	bl ov113_021E6238
	mov r6, #0
	add r4, r5, #0
	add r7, r6, #0
_021E6168:
	add r0, r4, #0
	add r0, #0xc4
	ldr r0, [r0]
	add r1, r7, #0
	bl ManagedSprite_SetDrawFlag
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #0xe
	blt _021E6168
_021E617C:
	ldr r0, [sp, #4]
	ldr r1, _021E6234 ; =ov113_021E6BD0
	lsl r0, r0, #2
	add r4, r1, r0
	ldrh r1, [r1, r0]
	lsl r0, r1, #0x10
	lsr r2, r0, #0x18
	add r0, r5, #0
	add r0, #0x3c
	ldrb r0, [r0]
	cmp r2, r0
	bgt _021E61E8
	lsl r0, r1, #0x18
	lsr r0, r0, #0x1e
	mov r6, #0
	cmp r0, #0
	ble _021E61E8
	add r7, r5, #0
	add r7, #0x78
_021E61A2:
	ldrh r1, [r4]
	ldr r0, [r5, #0x44]
	ldr r2, [r5, #0x50]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1a
	add r1, r1, r6
	bl ReadMsgDataIntoString
	ldrh r0, [r4]
	lsl r0, r0, #0x1a
	lsr r0, r0, #0x1a
	add r0, r0, r6
	cmp r0, #0xf
	bne _021E61D0
	mov r0, #0
	str r0, [sp]
	ldr r1, [r5, #0x50]
	add r0, r7, #0
	mov r2, #3
	mov r3, #4
	bl ov113_021E6274
	b _021E61DC
_021E61D0:
	ldr r1, [r5, #0x50]
	add r0, r7, #0
	mov r2, #4
	mov r3, #0x18
	bl ov113_021E629C
_021E61DC:
	ldrh r0, [r4]
	add r6, r6, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	cmp r6, r0
	blt _021E61A2
_021E61E8:
	ldrh r1, [r4, #2]
	lsl r0, r1, #0x10
	lsr r2, r0, #0x18
	add r0, r5, #0
	add r0, #0x3c
	ldrb r0, [r0]
	cmp r2, r0
	bgt _021E622E
	lsl r0, r1, #0x18
	lsr r0, r0, #0x1e
	mov r6, #0
	cmp r0, #0
	ble _021E622E
	add r7, r5, #0
	add r7, #0x88
_021E6206:
	ldrh r1, [r4, #2]
	ldr r0, [r5, #0x44]
	ldr r2, [r5, #0x50]
	lsl r1, r1, #0x1a
	lsr r1, r1, #0x1a
	add r1, r1, r6
	bl ReadMsgDataIntoString
	ldr r1, [r5, #0x50]
	add r0, r7, #0
	mov r2, #4
	mov r3, #0x18
	bl ov113_021E629C
	ldrh r0, [r4, #2]
	add r6, r6, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x1e
	cmp r6, r0
	blt _021E6206
_021E622E:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021E6234: .word ov113_021E6BD0
	thumb_func_end ov113_021E613C


	thumb_func_start ov113_021E6238
ov113_021E6238: ; 0x021E6238
	push {r4, r5, lr}
	sub sp, #0x1c
	add r5, r0, #0
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x18
	str r0, [sp, #4]
	ldr r0, [r1, #8]
	add r4, r2, #0
	mov r2, #0
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	str r2, [sp, #0x10]
	ldrb r0, [r1, #0xc]
	add r3, r2, #0
	str r0, [sp, #0x14]
	ldrb r0, [r1, #0xd]
	lsl r1, r4, #0x18
	lsr r1, r1, #0x18
	str r0, [sp, #0x18]
	ldr r0, [r5, #0x40]
	bl CopyToBgTilemapRect
	lsl r1, r4, #0x18
	ldr r0, [r5, #0x40]
	lsr r1, r1, #0x18
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x1c
	pop {r4, r5, pc}
	thumb_func_end ov113_021E6238

