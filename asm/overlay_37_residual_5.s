	.include "asm/macros.inc"
	.include "overlay_37.inc"
	.include "global.inc"

	.text
	.public _021E7968
	.public ov37_021E5900
	.public ov37_021E5A84
	.public ov37_021E5B94
	.public ov37_021E5CC8
	.public ov37_021E5CF0
	.public ov37_021E5D10
	.public ov37_021E5E30
	.public ov37_021E5F98
	.public ov37_021E6090
	.public ov37_021E60C0
	.public ov37_021E6244
	.public ov37_021E6418
	.public ov37_021E657C
	.public ov37_021E65EC
	.public ov37_021E69DC
	.public ov37_021E6B64
	.public ov37_021E6D14
	.public ov37_021E6F5C
	.public ov37_021E6FC8
	.public ov37_021E70BC
	.public ov37_021E713C
	.public ov37_021E72B4
	.public ov37_021E72E8
	.public ov37_021E73B4
	.public ov37_021E741C
	.public ov37_021E7478
	.public ov37_021E755C
	.public ov37_021E762C
	.public ov37_021E76F0
	.public ov37_021E78E0
	.public ov37_021E7970
	.public ov37_021E7978
	.public ov37_021E7988
	.public ov37_021E7998
	.public ov37_021E79B4
	.public ov37_021E79D0
	.public ov37_021E79EC
	.public ov37_021E7A08
	.public ov37_021E7A24
	.public ov37_021E7A4C
	.public ov37_021E7A80
	.public ov37_021E7AC8
	.public ov37_021E7D20

	.public ov37_021E5F20
	.public ov37_021E5F5C
	.public ov37_021E6540
	.public ov37_021E6818
	.public ov37_021E6848
	.public ov37_021E6860
	.public ov37_021E68AC
	.public ov37_021E68D0
	.public ov37_021E6928
	.public ov37_021E694C
	.public ov37_021E6980
	.public ov37_021E6B40
	.public ov37_021E6BFC
	.public ov37_021E6C38
	.public ov37_021E6C58
	.public ov37_021E6C84
	.public ov37_021E6CC0
	.public ov37_021E6DD0
	.public ov37_021E6E04
	.public ov37_021E6E2C
	.public ov37_021E6E6C
	.public ov37_021E6E70
	.public ov37_021E6E90
	.public ov37_021E6EB4
	.public ov37_021E6F14
	.public ov37_021E745C
	.public ov37_021E75C4
	.public ov37_021E75E0
	.public ov37_021E75E8
	.public ov37_021E76A0
	.public ov37_021E76C0
	.public ov37_021E76D0
	.public ov37_021E7844
	.public ov37_021E784C
	.public ov37_021E7880
	.public ov37_021E78A4
	.public ov37_021E78C4

	thumb_func_start ov37_021E6B64
ov37_021E6B64: ; 0x021E6B64
	push {r3, r4, r5, lr}
	add r4, r1, #0
	add r5, r0, #0
	ldr r1, _021E6BF0 ; =0x00004380
	mov r0, #0x38
	ldrb r2, [r5, r1]
	bic r2, r0
	strb r2, [r5, r1]
	bl sub_02037454
	ldr r1, _021E6BF4 ; =0x000093B8
	ldrh r1, [r5, r1]
	cmp r1, r0
	bne _021E6B8C
	bl ov37_021E75C4
	ldr r1, _021E6BF4 ; =0x000093B8
	ldrh r2, [r5, r1]
	cmp r2, r0
	beq _021E6BA4
_021E6B8C:
	ldr r0, _021E6BF8 ; =0x000093BA
	mov r1, #0
	strh r1, [r5, r0]
	add r0, r5, #0
	mov r1, #9
	bl ov37_021E7844
	add r0, r5, #0
	bl ov37_021E68AC
	add r0, r4, #0
	pop {r3, r4, r5, pc}
_021E6BA4:
	add r0, r1, #2
	ldrsh r0, [r5, r0]
	add r2, r0, #1
	add r0, r1, #2
	strh r2, [r5, r0]
	ldrsh r0, [r5, r0]
	cmp r0, #0x1e
	ble _021E6BE4
	add r0, sp, #0
	mov r1, #0
	mov r2, #4
	bl MI_CpuFill8
	mov r1, #1
	add r0, sp, #0
	strb r1, [r0, #2]
	bl sub_0203769C
	add r1, sp, #0
	strb r0, [r1]
	mov r0, #0x7e
	add r1, sp, #0
	mov r2, #4
	bl sub_02037030
	ldr r0, _021E6BF8 ; =0x000093BA
	mov r1, #0
	strh r1, [r5, r0]
	add r0, r5, #0
	mov r1, #0xa
	bl ov37_021E7844
_021E6BE4:
	add r0, r5, #0
	bl ov37_021E68AC
	add r0, r4, #0
	pop {r3, r4, r5, pc}
	nop
_021E6BF0: .word 0x00004380
_021E6BF4: .word 0x000093B8
_021E6BF8: .word 0x000093BA
	thumb_func_end ov37_021E6B64
