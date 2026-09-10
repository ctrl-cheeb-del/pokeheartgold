	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_02038804
sub_02038804: ; 0x02038804
	push {r3, lr}
	ldr r0, _02038848 ; =_021D4150
	mov r1, #0
	ldr r0, [r0]
	add r0, #0x4c
	strb r1, [r0]
	bl sub_02034FE8
	cmp r0, #0
	beq _02038844
	ldr r0, _02038848 ; =_021D4150
	ldr r1, [r0]
	add r0, r1, #0
	add r0, #0x48
	ldrh r0, [r0]
	cmp r0, #0
	beq _0203883C
	add r0, r1, #0
	add r0, #0x48
	ldrh r0, [r0]
	add r1, #0x48
	sub r0, r0, #1
	strh r0, [r1]
	ldr r0, _0203884C ; =sub_02038680
	mov r1, #0
	bl sub_020381C0
	pop {r3, pc}
_0203883C:
	ldr r0, _02038850 ; =sub_02038800
	mov r1, #0
	bl sub_020381C0
_02038844:
	pop {r3, pc}
	nop
_02038848: .word _021D4150
_0203884C: .word sub_02038680
_02038850: .word sub_02038800
	thumb_func_end sub_02038804
	thumb_func_start sub_02038854
sub_02038854: ; 0x02038854
	push {r3, lr}
	bl sub_020376F8
	cmp r0, #0
	bne _02038878
	bl sub_02039918
	cmp r0, #0
	bne _02038884
	bl sub_02034FE8
	cmp r0, #0
	beq _02038884
	ldr r0, _020388A0 ; =sub_02038610
	mov r1, #0
	bl sub_020381C0
	b _02038884
_02038878:
	bl sub_0203769C
	cmp r0, #0
	bne _02038884
	bl sub_02034638
_02038884:
	bl sub_02037700
	cmp r0, #0
	beq _0203889C
	bl sub_02039918
	cmp r0, #0
	bne _0203889C
	ldr r0, _020388A4 ; =sub_02038804
	mov r1, #0
	bl sub_020381C0
_0203889C:
	pop {r3, pc}
	nop
_020388A0: .word sub_02038610
_020388A4: .word sub_02038804
	thumb_func_end sub_02038854
