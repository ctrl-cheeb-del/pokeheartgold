	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038A10
sub_02038A10: ; 0x02038A10
	push {r3, lr}
	ldr r0, _02038A84 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4d
	ldrb r0, [r0]
	bl sub_020351AC
	cmp r0, #0
	beq _02038A3C
	ldr r0, _02038A84 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4d
	ldrb r0, [r0]
	bl sub_020360E4
	cmp r0, #0
	beq _02038A3C
	ldr r0, _02038A88 ; =sub_02038A94
	mov r1, #0x64
	bl sub_020381C0
	pop {r3, pc}
_02038A3C:
	bl sub_02037700
	cmp r0, #0
	bne _02038A4E
	ldr r0, _02038A84 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	bne _02038A7C
_02038A4E:
	ldr r1, _02038A84 ; =_021D4150
	ldr r2, [r1]
	add r0, r2, #0
	add r0, #0x48
	ldrh r0, [r0]
	add r2, #0x48
	sub r0, r0, #1
	strh r0, [r2]
	ldr r0, [r1]
	add r0, #0x48
	ldrh r0, [r0]
	cmp r0, #0
	bne _02038A72
	ldr r0, _02038A8C ; =sub_02038800
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038A72:
	ldr r0, _02038A90 ; =sub_020389BC
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038A7C:
	beq _02038A82
	sub r0, r0, #1
	str r0, [r1, #0x44]
_02038A82:
	pop {r3, pc}
	.balign 4, 0
_02038A84: .word _021D4150
_02038A88: .word sub_02038A94
_02038A8C: .word sub_02038800
_02038A90: .word sub_020389BC
	thumb_func_end sub_02038A10
	thumb_func_start sub_02038A94
sub_02038A94: ; 0x02038A94
	push {r3, lr}
	ldr r0, _02038B2C ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0x5a
	ble _02038AA6
	sub r0, r0, #1
	str r0, [r1, #0x44]
	pop {r3, pc}
_02038AA6:
	bl sub_02037700
	cmp r0, #0
	beq _02038ADC
	ldr r1, _02038B2C ; =_021D4150
	ldr r2, [r1]
	add r0, r2, #0
	add r0, #0x48
	ldrh r0, [r0]
	add r2, #0x48
	sub r0, r0, #1
	strh r0, [r2]
	ldr r0, [r1]
	add r0, #0x48
	ldrh r0, [r0]
	cmp r0, #0
	bne _02038AD2
	ldr r0, _02038B30 ; =sub_02038800
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038AD2:
	ldr r0, _02038B34 ; =sub_020389BC
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038ADC:
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	beq _02038AF2
	ldr r0, _02038B38 ; =sub_020387E8
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038AF2:
	ldr r1, _02038B2C ; =_021D4150
	ldr r2, [r1]
	ldr r0, [r2, #0x44]
	cmp r0, #0
	beq _02038B02
	sub r0, r0, #1
	str r0, [r2, #0x44]
	pop {r3, pc}
_02038B02:
	add r0, r2, #0
	add r0, #0x48
	ldrh r0, [r0]
	add r2, #0x48
	sub r0, r0, #1
	strh r0, [r2]
	ldr r0, [r1]
	add r0, #0x48
	ldrh r0, [r0]
	cmp r0, #0
	bne _02038B22
	ldr r0, _02038B30 ; =sub_02038800
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038B22:
	ldr r0, _02038B34 ; =sub_020389BC
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
	.balign 4, 0
_02038B2C: .word _021D4150
_02038B30: .word sub_02038800
_02038B34: .word sub_020389BC
_02038B38: .word sub_020387E8
	thumb_func_end sub_02038A94
	thumb_func_start sub_02038B3C
sub_02038B3C: ; 0x02038B3C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r4, r2, #0
	bl sub_0203769C
	cmp r0, #0
	bne _02038B8A
	ldr r6, _02038B8C ; =_0210F90C
	mov r3, #1
	mov r2, #0
_02038B50:
	ldrb r1, [r6]
	ldrb r0, [r4, r2]
	cmp r1, r0
	beq _02038B5C
	mov r3, #0
	b _02038B64
_02038B5C:
	add r2, r2, #1
	add r6, r6, #1
	cmp r2, #6
	blo _02038B50
_02038B64:
	cmp r3, #0
	beq _02038B80
	ldr r0, _02038B90 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x57
	ldrb r0, [r0]
	cmp r0, #0
	bne _02038B80
	ldr r1, _02038B94 ; =_0210F904
	mov r0, #7
	strb r5, [r1]
	bl sub_02037184
	pop {r4, r5, r6, pc}
_02038B80:
	ldr r1, _02038B98 ; =_0210F914
	mov r0, #7
	strb r5, [r1]
	bl sub_02037184
_02038B8A:
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02038B8C: .word _0210F90C
_02038B90: .word _021D4150
_02038B94: .word _0210F904
_02038B98: .word _0210F914
	thumb_func_end sub_02038B3C
	thumb_func_start sub_02038B9C
sub_02038B9C: ; 0x02038B9C
	push {r3, r4, r5, lr}
	mov r4, #1
	ldr r5, _02038C0C ; =_0210F904 + 1
	add r3, r4, #0
_02038BA4:
	ldrb r1, [r5]
	ldrb r0, [r2, r3]
	cmp r1, r0
	beq _02038BB0
	mov r4, #0
	b _02038BB8
_02038BB0:
	add r3, r3, #1
	add r5, r5, #1
	cmp r3, #6
	blo _02038BA4
_02038BB8:
	cmp r4, #0
	beq _02038BD2
	ldrb r4, [r2]
	bl sub_0203769C
	cmp r4, r0
	bne _02038C08
	ldr r0, _02038C10 ; =_021D4150
	mov r1, #1
	ldr r0, [r0]
	add r0, #0x4c
	strb r1, [r0]
	pop {r3, r4, r5, pc}
_02038BD2:
	mov r4, #1
	ldr r3, _02038C14 ; =_0210F914 + 1
	add r5, r4, #0
_02038BD8:
	ldrb r1, [r3]
	ldrb r0, [r2, r5]
	cmp r1, r0
	beq _02038BE4
	mov r4, #0
	b _02038BEC
_02038BE4:
	add r5, r5, #1
	add r3, r3, #1
	cmp r5, #6
	blo _02038BD8
_02038BEC:
	cmp r4, #0
	beq _02038C08
	ldrb r4, [r2]
	bl sub_0203769C
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	cmp r4, r0
	bne _02038C08
	ldr r0, _02038C10 ; =_021D4150
	mov r1, #2
	ldr r0, [r0]
	add r0, #0x4c
	strb r1, [r0]
_02038C08:
	pop {r3, r4, r5, pc}
	nop
_02038C0C: .word _0210F904 + 1
_02038C10: .word _021D4150
_02038C14: .word _0210F914 + 1
	thumb_func_end sub_02038B9C
