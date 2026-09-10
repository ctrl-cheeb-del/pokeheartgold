	.include "asm/macros.inc"
	.include "unk_02037C94.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0203A084
sub_0203A084: ; 0x0203A084
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r4, r0, #0
	add r5, r1, #0
	str r2, [sp]
	bl sub_0202C6F4
	bl sub_0202C08C
	add r6, r0, #0
	add r0, r4, #0
	bl sub_0202C6F4
	mov r1, #0
	bl sub_0202C23C
	add r4, r0, #0
	mov r1, #0
	ldr r0, [sp]
	mvn r1, r1
	str r1, [r0]
	add r0, r5, #0
	bl DWC_IsValidFriendData
	cmp r0, #0
	bne _0203A0BE
	add sp, #8
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_0203A0BE:
	mov r7, #0
_0203A0C0:
	add r0, r5, #0
	add r1, r4, #0
	bl DWC_IsEqualFriendData
	cmp r0, #0
	beq _0203A0D6
	ldr r0, [sp]
	add sp, #8
	str r7, [r0]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0203A0D6:
	add r0, r6, #0
	add r1, r5, #0
	bl DWC_GetGsProfileId
	cmp r0, #0
	ble _0203A104
	add r0, r6, #0
	add r1, r5, #0
	bl DWC_GetGsProfileId
	str r0, [sp, #4]
	add r0, r6, #0
	add r1, r4, #0
	bl DWC_GetGsProfileId
	ldr r1, [sp, #4]
	cmp r1, r0
	bne _0203A104
	ldr r0, [sp]
	add sp, #8
	str r7, [r0]
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0203A104:
	ldr r0, [sp]
	ldr r0, [r0]
	cmp r0, #0
	bge _0203A11A
	add r0, r4, #0
	bl DWC_IsValidFriendData
	cmp r0, #0
	bne _0203A11A
	ldr r0, [sp]
	str r7, [r0]
_0203A11A:
	add r7, r7, #1
	add r4, #0xc
	cmp r7, #0x20
	blt _0203A0C0
	mov r0, #2
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0203A084
	thumb_func_start sub_0203A128
sub_0203A128: ; 0x0203A128
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r4, r0, #0
	str r1, [sp]
	str r2, [sp, #4]
	add r6, r3, #0
	bl sub_0202C6F4
	bl sub_0202C08C
	add r7, r0, #0
	add r0, r4, #0
	bl sub_0202C6F4
	mov r1, #0
	bl sub_0202C23C
	add r5, r0, #0
	ldr r1, [sp]
	ldr r2, [sp, #4]
	add r0, r7, #0
	bl DWC_CheckFriendKey
	cmp r0, #0
	bne _0203A160
	add sp, #0x18
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_0203A160:
	ldr r1, [sp]
	ldr r2, [sp, #4]
	add r0, sp, #0xc
	bl DWC_CreateFriendKeyToken
	add r0, r7, #0
	add r1, sp, #0xc
	bl DWC_GetGsProfileId
	cmp r0, #0
	bgt _0203A17C
	add sp, #0x18
	mov r0, #3
	pop {r3, r4, r5, r6, r7, pc}
_0203A17C:
	mov r0, #0
	mvn r0, r0
	str r0, [r6]
	mov r4, #0
_0203A184:
	add r0, r7, #0
	add r1, sp, #0xc
	bl DWC_GetGsProfileId
	str r0, [sp, #8]
	add r0, r7, #0
	add r1, r5, #0
	bl DWC_GetGsProfileId
	ldr r1, [sp, #8]
	cmp r1, r0
	bne _0203A1A4
	add sp, #0x18
	str r4, [r6]
	mov r0, #0
	pop {r3, r4, r5, r6, r7, pc}
_0203A1A4:
	ldr r0, [r6]
	cmp r0, #0
	bge _0203A1B6
	add r0, r5, #0
	bl DWC_IsValidFriendData
	cmp r0, #0
	bne _0203A1B6
	str r4, [r6]
_0203A1B6:
	add r4, r4, #1
	add r5, #0xc
	cmp r4, #0x20
	blt _0203A184
	mov r0, #2
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0203A128
	thumb_func_start sub_0203A1C4
sub_0203A1C4: ; 0x0203A1C4
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r6, r1, #0
	mov r1, #0
	add r5, r0, #0
	str r2, [sp, #4]
	str r1, [sp, #0xc]
	bl sub_0202C6F4
	mov r1, #0
	bl sub_0202C23C
	str r0, [sp, #8]
	mov r4, #0
	bl sub_02037454
	cmp r0, #0
	ble _0203A278
_0203A1E8:
	bl sub_0203769C
	cmp r4, r0
	beq _0203A26C
	add r0, r4, #0
	bl sub_0203484C
	add r7, r0, #0
	beq _0203A26C
	add r0, r5, #0
	add r1, r7, #0
	add r2, sp, #0x10
	bl sub_0203A084
	str r0, [r6]
	cmp r0, #3
	bne _0203A20E
	bl GF_AssertFail
_0203A20E:
	ldr r0, [r6]
	cmp r0, #0
	bne _0203A22C
	mov r0, #2
	str r0, [sp]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0203A280
	add r0, r5, #0
	bl sub_02034A20
	b _0203A26C
_0203A22C:
	cmp r0, #1
	bne _0203A264
	bl sub_02039998
	cmp r0, #0
	bne _0203A26C
	mov r0, #1
	str r0, [sp]
	ldr r2, [sp, #0x10]
	ldr r3, [sp, #4]
	add r0, r5, #0
	add r1, r4, #0
	bl sub_0203A280
	ldr r2, [sp, #0x10]
	mov r1, #0xc
	add r3, r2, #0
	mul r3, r1
	ldr r1, [sp, #8]
	add r0, r7, #0
	add r1, r1, r3
	mov r2, #0xc
	bl MI_CpuCopy8
	add r0, r5, #0
	bl sub_02034A20
	b _0203A26C
_0203A264:
	cmp r0, #2
	bne _0203A26C
	mov r0, #1
	str r0, [sp, #0xc]
_0203A26C:
	add r6, r6, #4
	add r4, r4, #1
	bl sub_02037454
	cmp r4, r0
	blt _0203A1E8
_0203A278:
	ldr r0, [sp, #0xc]
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end sub_0203A1C4
	thumb_func_start sub_0203A280
sub_0203A280: ; 0x0203A280
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r2, #0
	str r0, [sp]
	add r7, r1, #0
	str r3, [sp, #4]
	bl sub_0202C6F4
	add r1, r5, #0
	add r4, r0, #0
	bl sub_0202C23C
	str r0, [sp, #8]
	add r0, r7, #0
	bl sub_02034818
	add r6, r0, #0
	ldr r0, [sp, #0x28]
	cmp r0, #2
	beq _0203A2B6
	add r0, r7, #0
	bl sub_0203484C
	ldr r1, [sp, #8]
	mov r2, #0xc
	bl MI_CpuCopy8
_0203A2B6:
	ldr r0, [sp, #0x28]
	cmp r0, #0
	bne _0203A2FC
	ldr r1, [sp, #4]
	add r0, r6, #0
	bl PlayerProfile_GetPlayerName_NewString
	str r0, [sp, #0xc]
	ldr r2, [sp, #0xc]
	add r0, r4, #0
	add r1, r5, #0
	bl sub_0202C270
	ldr r0, [sp, #0xc]
	bl String_Delete
	add r0, r6, #0
	bl PlayerProfile_GetTrainerGender
	add r3, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #8
	bl sub_0202C190
	add r0, r6, #0
	bl PlayerProfile_GetTrainerID
	add r3, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0
	bl sub_0202C190
	b _0203A334
_0203A2FC:
	sub r0, r0, #1
	cmp r0, #1
	bhi _0203A334
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #8
	bl sub_0202C090
	cmp r0, #2
	bne _0203A334
	add r0, r6, #0
	bl PlayerProfile_GetTrainerGender
	add r3, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #8
	bl sub_0202C190
	add r0, r6, #0
	bl PlayerProfile_GetTrainerID
	add r3, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0
	bl sub_0202C190
_0203A334:
	ldr r1, [sp, #4]
	mov r0, #0x78
	bl String_New
	str r0, [sp, #0x10]
	add r0, r7, #0
	bl sub_02034884
	add r1, r0, #0
	ldr r0, [sp, #0x10]
	bl CopyU16ArrayToString
	ldr r2, [sp, #0x10]
	add r0, r4, #0
	add r1, r5, #0
	bl sub_0202C2B4
	ldr r0, [sp, #0x10]
	bl String_Delete
	add r0, r6, #0
	bl PlayerProfile_GetAvatar
	add r3, r0, #0
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #7
	bl sub_0202C190
	ldr r0, [sp]
	bl sub_02034A20
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	thumb_func_end sub_0203A280
