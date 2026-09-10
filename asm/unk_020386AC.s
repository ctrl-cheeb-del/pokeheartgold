	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_020386AC
sub_020386AC: ; 0x020386AC
	push {r3, lr}
	ldr r0, _02038704 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4d
	ldrb r0, [r0]
	bl sub_020351AC
	cmp r0, #0
	beq _020386D8
	ldr r0, _02038704 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4d
	ldrb r0, [r0]
	bl sub_020360E4
	cmp r0, #0
	beq _020386D8
	ldr r0, _02038708 ; =sub_02038710
	mov r1, #0x64
	bl sub_020381C0
	pop {r3, pc}
_020386D8:
	bl sub_02037700
	cmp r0, #0
	beq _020386EA
	ldr r0, _0203870C ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_020386EA:
	ldr r0, _02038704 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	beq _020386FA
	sub r0, r0, #1
	str r0, [r1, #0x44]
	pop {r3, pc}
_020386FA:
	ldr r0, _0203870C ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
	.balign 4, 0
_02038704: .word _021D4150
_02038708: .word sub_02038710
_0203870C: .word sub_02038804
	thumb_func_end sub_020386AC
	thumb_func_start sub_02038710
sub_02038710: ; 0x02038710
	push {r3, lr}
	bl sub_02037700
	cmp r0, #0
	beq _02038724
	ldr r0, _02038760 ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038724:
	bl sub_0203769C
	bl sub_020373B4
	cmp r0, #0
	beq _02038744
	ldr r0, _02038764 ; =_021D4150
	mov r1, #0
	ldr r0, [r0]
	add r0, #0x4c
	strb r1, [r0]
	ldr r0, _02038768 ; =sub_0203876C
	mov r1, #0x78
	bl sub_020381C0
	pop {r3, pc}
_02038744:
	ldr r0, _02038764 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	beq _02038754
	sub r0, r0, #1
	str r0, [r1, #0x44]
	pop {r3, pc}
_02038754:
	ldr r0, _02038760 ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
	nop
_02038760: .word sub_02038804
_02038764: .word _021D4150
_02038768: .word sub_0203876C
	thumb_func_end sub_02038710
	thumb_func_start sub_0203876C
sub_0203876C: ; 0x0203876C
	push {r3, lr}
	bl sub_02037700
	cmp r0, #0
	beq _02038780
	ldr r0, _020387D4 ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038780:
	ldr r0, _020387D8 ; =_021D4150
	ldr r1, [r0]
	add r0, r1, #0
	add r0, #0x4c
	ldrb r0, [r0]
	cmp r0, #2
	bne _02038798
	ldr r0, _020387DC ; =sub_02038800
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_02038798:
	cmp r0, #1
	bne _020387AA
	bl sub_02034434
	ldr r0, _020387E0 ; =sub_020387E8
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_020387AA:
	ldr r0, [r1, #0x44]
	cmp r0, #0x6e
	ble _020387B8
	ldr r1, _020387E4 ; =_0210F90C
	mov r0, #6
	bl sub_020376E0
_020387B8:
	ldr r0, _020387D8 ; =_021D4150
	ldr r1, [r0]
	ldr r0, [r1, #0x44]
	cmp r0, #0
	beq _020387C8
	sub r0, r0, #1
	str r0, [r1, #0x44]
	pop {r3, pc}
_020387C8:
	ldr r0, _020387D4 ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
	nop
_020387D4: .word sub_02038804
_020387D8: .word _021D4150
_020387DC: .word sub_02038800
_020387E0: .word sub_020387E8
_020387E4: .word _0210F90C
	thumb_func_end sub_0203876C
