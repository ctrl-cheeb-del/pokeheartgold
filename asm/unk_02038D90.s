	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038D90
sub_02038D90: ; 0x02038D90
	push {r3, lr}
	bl sub_02037988
	ldr r0, _02038DF0 ; =_021D4150
	ldr r0, [r0]
	cmp r0, #0
	bne _02038DA2
	mov r0, #1
	pop {r3, pc}
_02038DA2:
	add r0, #0x4e
	ldrb r0, [r0]
	cmp r0, #0x18
	beq _02038DB2
	cmp r0, #0x19
	beq _02038DB2
	cmp r0, #0x24
	bne _02038DBA
_02038DB2:
	bl ov00_021E6CB8
	mov r0, #1
	pop {r3, pc}
_02038DBA:
	bl sub_02039998
	cmp r0, #0
	beq _02038DE2
	ldr r0, _02038DF0 ; =_021D4150
	ldr r0, [r0]
	add r0, #0x4e
	ldrb r0, [r0]
	cmp r0, #0x21
	bne _02038DD8
	ldr r0, _02038DF4 ; =sub_02039D78
	mov r1, #0
	bl sub_020381C0
	b _02038DEA
_02038DD8:
	ldr r0, _02038DF8 ; =sub_020392F4
	mov r1, #0
	bl sub_020381C0
	b _02038DEA
_02038DE2:
	ldr r0, _02038DFC ; =sub_020381FC
	mov r1, #0
	bl sub_020381C0
_02038DEA:
	mov r0, #0
	pop {r3, pc}
	nop
_02038DF0: .word _021D4150
_02038DF4: .word sub_02039D78
_02038DF8: .word sub_020392F4
_02038DFC: .word sub_020381FC
	thumb_func_end sub_02038D90
