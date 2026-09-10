	.include "asm/macros.inc"
	.include "unk_02032844.inc"
	.include "global.inc"

	.text
	thumb_func_start sub_02032B84
sub_02032B84: ; 0x02032B84
	push {r3, r4, r5, r6, r7, lr}
	add r7, r2, #0
	ldr r2, _02032C10 ; =_021D4124
	add r5, r0, #0
	add r4, r1, #0
	mov r3, #2
	ldr r0, [r2, #4]
	ldr r1, _02032C14 ; =0x00001308
	lsl r3, r3, #8
	str r3, [r0, r1]
	ldr r2, [r2, #4]
	mov r0, #0x40
	sub r1, r1, #4
	str r0, [r2, r1]
	mov r0, #2
	bl sub_02032844
	ldr r2, _02032C10 ; =_021D4124
	ldr r1, _02032C18 ; =0x00001256
	ldr r3, [r2, #4]
	mov r0, #1
	strh r0, [r3, r1]
	add r0, r1, #0
	ldrh r6, [r4, #4]
	ldr r3, [r2, #4]
	add r0, #0x96
	strh r6, [r3, r0]
	add r0, r1, #0
	ldrh r6, [r4, #2]
	ldr r3, [r2, #4]
	add r0, #0x94
	strh r6, [r3, r0]
	add r0, r1, #0
	ldrh r4, [r4]
	ldr r3, [r2, #4]
	add r0, #0x92
	strh r4, [r3, r0]
	add r0, r1, #0
	ldr r3, [r2, #4]
	add r0, #0xbe
	str r5, [r3, r0]
	add r3, r1, #0
	ldr r4, [r2, #4]
	mov r0, #0
	add r3, #0xaa
	str r0, [r4, r3]
	add r3, r1, #0
	ldr r4, [r2, #4]
	add r3, #0xb6
	strh r7, [r4, r3]
	add r3, r1, #0
	ldr r4, [r2, #4]
	add r3, #0x8e
	strh r0, [r4, r3]
	ldr r2, [r2, #4]
	add r1, #0xb8
	mov r0, #1
	strh r0, [r2, r1]
	bl sub_02032C84
	cmp r0, #0
	bne _02032C0A
	mov r0, #9
	bl sub_02032844
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02032C0A:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02032C10: .word _021D4124
_02032C14: .word 0x00001308
_02032C18: .word 0x00001256
	thumb_func_end sub_02032B84
	thumb_func_start sub_02032C1C
sub_02032C1C: ; 0x02032C1C
	push {r4, r5, r6, lr}
	add r5, r0, #0
	mov r0, #2
	add r4, r1, #0
	add r6, r2, #0
	bl sub_02032844
	ldr r1, _02032C80 ; =_021D4124
	mov r0, #0x13
	ldr r2, [r1, #4]
	lsl r0, r0, #8
	str r5, [r2, r0]
	add r2, r0, #0
	ldr r3, [r1, #4]
	add r2, #0xc
	strh r6, [r3, r2]
	add r3, r0, #0
	ldr r5, [r1, #4]
	mov r2, #0
	sub r3, #0x1c
	strh r2, [r5, r3]
	add r3, r0, #0
	ldr r5, [r1, #4]
	add r3, #0xe
	strh r2, [r5, r3]
	add r2, r0, #0
	ldrh r5, [r4, #4]
	ldr r3, [r1, #4]
	sub r2, #0x14
	strh r5, [r3, r2]
	add r2, r0, #0
	ldrh r5, [r4, #2]
	ldr r3, [r1, #4]
	sub r2, #0x16
	strh r5, [r3, r2]
	ldrh r2, [r4]
	ldr r1, [r1, #4]
	sub r0, #0x18
	strh r2, [r1, r0]
	bl sub_02032C84
	cmp r0, #0
	bne _02032C7C
	mov r0, #9
	bl sub_02032844
	mov r0, #0
	pop {r4, r5, r6, pc}
_02032C7C:
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
_02032C80: .word _021D4124
	thumb_func_end sub_02032C1C
	thumb_func_start sub_02032C84
sub_02032C84: ; 0x02032C84
	push {r3, r4, r5, r6, r7, lr}
	bl WM_GetAllowedChannel
	add r5, r0, #0
	mov r0, #2
	lsl r0, r0, #0xe
	cmp r5, r0
	bne _02032CA4
	mov r0, #3
	bl sub_02032858
	mov r0, #1
	bl sub_02039AD8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02032CA4:
	cmp r5, #0
	bne _02032CB8
	mov r0, #0x16
	bl sub_02032858
	mov r0, #1
	bl sub_02039AD8
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02032CB8:
	ldr r1, _02032D38 ; =_021D4124
	ldr r0, _02032D3C ; =0x0000130C
	ldr r3, [r1, #4]
	ldrh r2, [r3, r0]
	cmp r2, #0
	bne _02032CF8
	add r7, r0, #0
	mov r3, #1
	add r2, r3, #0
	sub r7, #0x28
	sub r0, #0x28
_02032CCE:
	ldr r4, [r1, #4]
	ldr r6, _02032D40 ; =0x000012E4
	ldrh r6, [r4, r6]
	add r6, r6, #1
	strh r6, [r4, r7]
	ldr r4, [r1, #4]
	ldrh r6, [r4, r0]
	cmp r6, #0x10
	bls _02032CE4
	ldr r6, _02032D40 ; =0x000012E4
	strh r3, [r4, r6]
_02032CE4:
	ldr r6, [r1, #4]
	ldr r4, _02032D40 ; =0x000012E4
	ldrh r4, [r6, r4]
	add r6, r2, #0
	sub r4, r4, #1
	lsl r6, r4
	add r4, r5, #0
	tst r4, r6
	bne _02032CFC
	b _02032CCE
_02032CF8:
	sub r0, #0x28
	strh r2, [r3, r0]
_02032CFC:
	bl WM_GetDispersionScanPeriod
	mov r1, #3
	bl _s32_div_f
	ldr r2, _02032D38 ; =_021D4124
	ldr r1, _02032D44 ; =0x000012E6
	ldr r3, [r2, #4]
	strh r0, [r3, r1]
	add r0, r1, #0
	ldr r3, [r2, #4]
	sub r0, #0xc6
	add r4, r3, r0
	sub r0, r1, #6
	str r4, [r3, r0]
	ldr r2, [r2, #4]
	sub r1, r1, #6
	ldr r0, _02032D48 ; =sub_02032D4C
	add r1, r2, r1
	bl WM_StartScan
	cmp r0, #2
	beq _02032D32
	bl sub_02032858
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_02032D32:
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
	nop
_02032D38: .word _021D4124
_02032D3C: .word 0x0000130C
_02032D40: .word 0x000012E4
_02032D44: .word 0x000012E6
_02032D48: .word sub_02032D4C
	thumb_func_end sub_02032C84
	thumb_func_start sub_02032D4C
sub_02032D4C: ; 0x02032D4C
	push {r4, lr}
	add r4, r0, #0
	ldrh r0, [r4, #2]
	cmp r0, #0
	beq _02032D62
	bl sub_02032858
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032D62:
	ldr r0, _02032E14 ; =_021D4124
	ldr r2, [r0, #4]
	ldr r0, _02032E18 ; =0x00001310
	ldr r1, [r2, r0]
	cmp r1, #2
	beq _02032D84
	mov r1, #0
	sub r0, r0, #2
	strh r1, [r2, r0]
	bl sub_02032E48
	cmp r0, #0
	bne _02032E10
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032D84:
	ldrh r1, [r4, #8]
	cmp r1, #3
	beq _02032E10
	cmp r1, #4
	beq _02032E02
	cmp r1, #5
	bne _02032E02
	sub r0, #0xf0
	add r0, r2, r0
	mov r1, #0xc0
	bl DC_InvalidateRange
	ldr r0, _02032E14 ; =_021D4124
	ldr r1, [r0, #4]
	ldr r0, _02032E1C ; =0x00001320
	ldr r2, [r1, r0]
	cmp r2, #0
	beq _02032DB8
	ldrh r0, [r4, #0x36]
	cmp r0, #8
	blo _02032DB8
	add r1, r4, #0
	add r1, #0x48
	ldrb r1, [r1, #4]
	ldr r0, [r4, #0x3c]
	blx r2
_02032DB8:
	ldrh r0, [r4, #0x36]
	cmp r0, #8
	blo _02032E02
	ldr r0, _02032E14 ; =_021D4124
	ldr r2, [r4, #0x3c]
	ldr r0, [r0, #4]
	ldr r1, [r0, #8]
	cmp r2, r1
	bne _02032E02
	add r4, #0x43
	ldrb r2, [r4]
	mov r1, #3
	and r1, r2
	cmp r1, #1
	bne _02032E02
	mov r1, #0x13
	lsl r1, r1, #8
	ldr r2, [r0, r1]
	cmp r2, #0
	beq _02032DE6
	sub r1, #0xe0
	add r0, r0, r1
	blx r2
_02032DE6:
	ldr r0, _02032E14 ; =_021D4124
	ldr r1, [r0, #4]
	ldr r0, _02032E20 ; =0x0000130E
	ldrh r0, [r1, r0]
	cmp r0, #0
	beq _02032E02
	bl sub_02032E48
	cmp r0, #0
	bne _02032E10
	mov r0, #9
	bl sub_02032844
	pop {r4, pc}
_02032E02:
	bl sub_02032C84
	cmp r0, #0
	bne _02032E10
	mov r0, #9
	bl sub_02032844
_02032E10:
	pop {r4, pc}
	nop
_02032E14: .word _021D4124
_02032E18: .word 0x00001310
_02032E1C: .word 0x00001320
_02032E20: .word 0x0000130E
	thumb_func_end sub_02032D4C
