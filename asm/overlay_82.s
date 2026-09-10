	.include "asm/macros.inc"
	.include "overlay_82.inc"
	.include "global.inc"

	.text
	.public _0223FE20
	.public ov82_0223DD60
	.public ov82_0223DE20
	.public ov82_0223DF74
	.public ov82_0223DFBC
	.public ov82_0223E070
	.public ov82_0223E0B0
	.public ov82_0223E140
	.public ov82_0223E2A4
	.public ov82_0223E2EC
	.public ov82_0223E5D4
	.public ov82_0223E820
	.public ov82_0223E888
	.public ov82_0223E8C4
	.public ov82_0223E974
	.public ov82_0223E9E8
	.public ov82_0223EB3C
	.public ov82_0223EBB8
	.public ov82_0223EC0C
	.public ov82_0223EC68
	.public ov82_0223ED94
	.public ov82_0223EDF0
	.public ov82_0223EE6C
	.public ov82_0223EECC
	.public ov82_0223EF1C
	.public ov82_0223EFCC
	.public ov82_0223F040
	.public ov82_0223F134
	.public ov82_0223F1AC
	.public ov82_0223F224
	.public ov82_0223F300
	.public ov82_0223F488
	.public ov82_0223F5E0
	.public ov82_0223F84C
	.public ov82_0223F95C
	.public ov82_0223FB08
	.public ov82_0223FBBC
	.public ov82_0223FC48
	.public ov82_0223FDC8
	.public ov82_0223FE28
	.public ov82_0223FE38
	.public ov82_0223FE54
	.public ov82_0223FE70
	.public ov82_0223FE8C
	.public ov82_0223FEA8
	.public ov82_0223FEC4
	.public ov82_0223FEEC
	.public ov82_0223FEF0
	.public ov82_0223FF00
	.public ov82_0223E7E8
	.public ov82_0223E9B0
	.public ov82_0223EB9C
	.public ov82_0223EC48
	.public ov82_0223EE38
	.public ov82_0223EF7C
	.public ov82_0223EFB4
	.public ov82_0223F10C
	.public ov82_0223F2F8
	.public ov82_0223F53C
	.public ov82_0223F558
	.public ov82_0223F570
	.public ov82_0223F580
	.public ov82_0223F6C4
	.public ov82_0223F6CC
	.public ov82_0223F6E4
	.public ov82_0223F6E8
	.public ov82_0223F74C
	.public ov82_0223F764
	.public ov82_0223F770
	.public ov82_0223F7B4
	.public ov82_0223F808
	.public ov82_0223F814
	.public ov82_0223F834
	.public ov82_0223F8E4
	.public ov82_0223F90C
	.public ov82_0223F948
	.public ov82_0223FC14
	.public ov82_0223FC9C
	.public ov82_0223FCB0
	.public ov82_0223FCBC
	.public ov82_0223FCFC
	.public ov82_0223FD18
	.public ov82_0223FD2C
	.public ov82_0223FD5C
	.public ov82_0223FD78
	.public ov82_0223FDB8
	.public ov82_0223FDC0
	.public ov82_0223FE18

	thumb_func_start ov82_0223DD60
ov82_0223DD60: ; 0x0223DD60
	push {r4, r5, r6, lr}
	add r4, r0, #0
	add r6, r1, #0
	ldr r0, _0223DE1C ; =FS_OVERLAY_ID(OVY_80)
	mov r1, #2
	bl HandleLoadOverlay
	bl ov82_0223E9B0
	mov r2, #2
	mov r0, #3
	mov r1, #0x69
	lsl r2, r2, #0x10
	bl Heap_Create
	mov r1, #0xa1
	add r0, r4, #0
	lsl r1, r1, #2
	mov r2, #0x69
	bl OverlayManager_CreateAndGetData
	mov r2, #0xa1
	mov r1, #0
	lsl r2, r2, #2
	add r5, r0, #0
	bl memset
	mov r0, #0x69
	bl BgConfig_Alloc
	str r0, [r5, #0x48]
	add r0, r4, #0
	str r4, [r5]
	bl OverlayManager_GetArgs
	add r4, r0, #0
	add r0, r5, #0
	ldr r1, [r4]
	add r0, #0xa0
	str r1, [r0]
	ldrb r0, [r4, #4]
	add r1, r4, #6
	strb r0, [r5, #9]
	mov r0, #0x21
	lsl r0, r0, #4
	str r1, [r5, r0]
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	bl Save_PlayerData_GetOptionsAddr
	add r1, r5, #0
	add r1, #0x9c
	str r0, [r1]
	mov r1, #0x85
	ldr r0, [r4, #0xc]
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r2, [r4, #8]
	add r0, r1, #4
	str r2, [r5, r0]
	add r0, r1, #0
	ldr r2, [r4, #0x14]
	add r0, #8
	str r2, [r5, r0]
	ldrh r0, [r4, #0x18]
	add r1, #0x68
	add r0, r0, #1
	strh r0, [r5, #0x1c]
	ldrb r0, [r4, #5]
	strb r0, [r5, #0xd]
	mov r0, #0xff
	strb r0, [r5, r1]
	strb r0, [r5, #0x18]
	mov r0, #0x75
	strb r0, [r5, #0x1f]
	add r0, r5, #0
	bl ov82_0223E9E8
	ldrb r0, [r5, #9]
	bl ov80_0223792C
	cmp r0, #1
	bne _0223DE0E
	add r0, r5, #0
	bl sub_02096910
_0223DE0E:
	mov r0, #0
	str r0, [r6]
	mov r0, #1
	bl TextFlags_SetCanTouchSpeedUpPrint
	mov r0, #1
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0223DE1C: .word FS_OVERLAY_ID(OVY_80)
	thumb_func_end ov82_0223DD60


	thumb_func_start ov82_0223DE20
ov82_0223DE20: ; 0x0223DE20
	push {r3, r4, r5, lr}
	add r5, r1, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	ldrb r1, [r4, #0x18]
	cmp r1, #0xff
	beq _0223DE4A
	ldr r1, [r5]
	cmp r1, #2
	bne _0223DE4A
	ldrh r1, [r4, #0x10]
	cmp r1, #0
	bne _0223DE4A
	bl ov82_0223F834
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #3
	bl ov82_0223F2F8
_0223DE4A:
	ldr r0, [r5]
	cmp r0, #6
	bls _0223DE52
	b _0223DF68
_0223DE52:
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0223DE5E: ; jump table
	.short _0223DE86 - _0223DE5E - 2 ; case 0
	.short _0223DE6C - _0223DE5E - 2 ; case 1
	.short _0223DE9C - _0223DE5E - 2 ; case 2
	.short _0223DEEE - _0223DE5E - 2 ; case 3
	.short _0223DF30 - _0223DE5E - 2 ; case 4
	.short _0223DF46 - _0223DE5E - 2 ; case 5
	.short _0223DF54 - _0223DE5E - 2 ; case 6
_0223DE6C:
	add r0, r4, #0
	bl ov82_0223E2A4
	cmp r0, #1
	bne _0223DE82
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #0
	bl ov82_0223F2F8
	b _0223DE86
_0223DE82:
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223DE86:
	add r0, r4, #0
	bl ov82_0223DFBC
	cmp r0, #1
	bne _0223DF68
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #2
	bl ov82_0223F2F8
	b _0223DF68
_0223DE9C:
	add r0, r4, #0
	bl ov82_0223E2EC
	cmp r0, #1
	bne _0223DF68
	ldrb r0, [r4, #0x17]
	cmp r0, #1
	bne _0223DEB8
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #3
	bl ov82_0223F2F8
	b _0223DF68
_0223DEB8:
	ldrb r0, [r4, #0xb]
	cmp r0, #1
	bne _0223DECC
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #1
	bl ov82_0223F2F8
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223DECC:
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #1
	bne _0223DEE2
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #4
	bl ov82_0223F2F8
	b _0223DF68
_0223DEE2:
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #5
	bl ov82_0223F2F8
	b _0223DF68
_0223DEEE:
	add r0, r4, #0
	bl ov82_0223E5D4
	cmp r0, #1
	bne _0223DF68
	ldrb r0, [r4, #0x19]
	cmp r0, #1
	bne _0223DF0E
	mov r0, #0
	strb r0, [r4, #0x19]
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #2
	bl ov82_0223F2F8
	b _0223DF68
_0223DF0E:
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #1
	bne _0223DF24
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #4
	bl ov82_0223F2F8
	b _0223DF68
_0223DF24:
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #5
	bl ov82_0223F2F8
	b _0223DF68
_0223DF30:
	add r0, r4, #0
	bl ov82_0223E7E8
	cmp r0, #1
	bne _0223DF68
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #5
	bl ov82_0223F2F8
	b _0223DF68
_0223DF46:
	add r0, r4, #0
	bl ov82_0223E820
	cmp r0, #1
	bne _0223DF68
	mov r0, #1
	pop {r3, r4, r5, pc}
_0223DF54:
	add r0, r4, #0
	bl ov82_0223E888
	cmp r0, #1
	bne _0223DF68
	add r0, r4, #0
	add r1, r5, #0
	mov r2, #4
	bl ov82_0223F2F8
_0223DF68:
	add r4, #0xa8
	ldr r0, [r4]
	bl SpriteList_RenderAndAnimateSprites
	mov r0, #0
	pop {r3, r4, r5, pc}
	thumb_func_end ov82_0223DE20


	thumb_func_start ov82_0223DF74
ov82_0223DF74: ; 0x0223DF74
	push {r4, lr}
	add r4, r0, #0
	bl OverlayManager_GetData
	mov r1, #0x21
	lsl r1, r1, #4
	ldrb r2, [r0, #0xd]
	ldr r1, [r0, r1]
	strh r2, [r1]
	bl ov82_0223E8C4
	add r0, r4, #0
	bl OverlayManager_FreeData
	ldr r2, _0223DFB4 ; =0x04000304
	ldrh r1, [r2]
	lsr r0, r2, #0xb
	orr r0, r1
	strh r0, [r2]
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #0x69
	bl Heap_Destroy
	ldr r0, _0223DFB8 ; =FS_OVERLAY_ID(OVY_80)
	bl UnloadOverlayByID
	mov r0, #1
	pop {r4, pc}
	nop
_0223DFB4: .word 0x04000304
_0223DFB8: .word FS_OVERLAY_ID(OVY_80)
	thumb_func_end ov82_0223DF74


	thumb_func_start ov82_0223DFBC
ov82_0223DFBC: ; 0x0223DFBC
	push {r3, r4, lr}
	sub sp, #0xc
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #3
	bhi _0223E068
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223DFD4: ; jump table
	.short _0223DFDC - _0223DFD4 - 2 ; case 0
	.short _0223DFFE - _0223DFD4 - 2 ; case 1
	.short _0223E030 - _0223DFD4 - 2 ; case 2
	.short _0223E05A - _0223DFD4 - 2 ; case 3
_0223DFDC:
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _0223DFF6
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #1
	bne _0223DFF6
	bl sub_02037BEC
	mov r0, #0x70
	bl sub_02037AC0
_0223DFF6:
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E068
_0223DFFE:
	ldrh r0, [r4, #0x12]
	cmp r0, #0
	bne _0223E028
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #1
	bne _0223E028
	mov r0, #0x70
	bl sub_02037B38
	cmp r0, #1
	bne _0223E068
	bl sub_02037BEC
	mov r0, #1
	strh r0, [r4, #0x12]
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E068
_0223E028:
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E068
_0223E030:
	bl ov82_0223E070
	add r0, r4, #0
	bl ov82_0223E0B0
	mov r0, #6
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	mov r0, #0x69
	str r0, [sp, #8]
	mov r0, #0
	mov r1, #1
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	ldrb r0, [r4, #8]
	add r0, r0, #1
	strb r0, [r4, #8]
	b _0223E068
_0223E05A:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223E068
	add sp, #0xc
	mov r0, #1
	pop {r3, r4, pc}
_0223E068:
	mov r0, #0
	add sp, #0xc
	pop {r3, r4, pc}
	.balign 4, 0
	thumb_func_end ov82_0223DFBC


	thumb_func_start ov82_0223E070
ov82_0223E070: ; 0x0223E070
	push {r4, lr}
	sub sp, #0x10
	mov r1, #0
	str r1, [sp]
	add r4, r0, #0
	str r1, [sp, #4]
	add r1, r4, #0
	add r1, #0x6c
	mov r2, #1
	mov r3, #2
	bl ov82_0223F040
	add r1, r4, #0
	add r0, r4, #0
	add r1, #0x6c
	bl ov82_0223F134
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r2, #0
	add r0, r4, #0
	add r4, #0x5c
	str r2, [sp, #8]
	add r1, r4, #0
	add r3, r2, #0
	str r2, [sp, #0xc]
	bl ov82_0223EFCC
	add sp, #0x10
	pop {r4, pc}
	thumb_func_end ov82_0223E070


	thumb_func_start ov82_0223E0B0
ov82_0223E0B0: ; 0x0223E0B0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r0, #0x7c
	bl GetWindowX
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0x10]
	add r0, r5, #0
	add r0, #0x7c
	bl GetWindowY
	sub r0, r0, #1
	lsl r0, r0, #0x18
	lsr r7, r0, #0x18
	add r0, r5, #0
	add r0, #0x7c
	bl GetWindowWidth
	add r0, r0, #2
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	add r0, #0x7c
	bl GetWindowHeight
	add r0, r0, #2
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	add r0, #0x7c
	bl GetWindowBgId
	str r0, [sp, #0x14]
	mov r0, #1
	str r0, [sp]
	mov r0, #2
	str r0, [sp, #4]
	mov r0, #0xf
	mov r2, #0
	str r0, [sp, #8]
	add r1, r5, #0
	add r0, r5, #0
	add r1, #0x7c
	add r3, r2, #0
	str r2, [sp, #0xc]
	bl ov82_0223F1AC
	add r0, r5, #0
	mov r1, #4
	bl ov82_0223EECC
	str r6, [sp]
	str r4, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, [r5, #0x48]
	ldr r1, [sp, #0x14]
	ldr r2, [sp, #0x10]
	add r3, r7, #0
	bl ov82_0223E140
	ldr r0, [r5, #0x48]
	ldr r1, [sp, #0x14]
	bl ScheduleBgTilemapBufferTransfer
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E0B0


	thumb_func_start ov82_0223E140
ov82_0223E140: ; 0x0223E140
	push {r4, r5, r6, r7, lr}
	sub sp, #0x2c
	str r1, [sp, #0x14]
	str r2, [sp, #0x18]
	ldr r5, [sp, #0x4c]
	add r6, r3, #0
	str r6, [sp]
	mov r2, #1
	str r2, [sp, #4]
	str r2, [sp, #8]
	lsl r2, r5, #0x18
	lsr r2, r2, #0x18
	str r2, [sp, #0xc]
	add r2, sp, #0x30
	ldrh r2, [r2, #0x18]
	ldr r3, [sp, #0x18]
	str r0, [sp, #0x10]
	bl FillBgTilemapRect
	add r1, sp, #0x30
	ldrh r4, [r1, #0x18]
	ldrb r7, [r1, #0x10]
	ldr r0, [sp, #0x18]
	add r2, r4, #2
	add r0, r0, r7
	sub r0, r0, #1
	str r0, [sp, #0x20]
	ldr r3, [sp, #0x20]
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	str r6, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add r0, sp, #0x30
	ldrb r0, [r0, #0x14]
	add r2, r4, #6
	lsl r2, r2, #0x10
	str r0, [sp, #0x28]
	add r0, r6, r0
	sub r0, r0, #1
	str r0, [sp, #0x24]
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r3, [sp, #0x18]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	ldr r0, [sp, #0x24]
	add r2, r4, #0
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r3, [sp, #0x20]
	add r2, #8
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	sub r0, r7, #2
	str r0, [sp, #0x1c]
	ldr r0, [sp, #0x18]
	add r2, r4, #1
	add r7, r0, #1
	ldr r0, [sp, #0x1c]
	lsl r2, r2, #0x10
	lsl r0, r0, #0x18
	lsl r3, r7, #0x18
	str r6, [sp]
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x24]
	add r2, r4, #7
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	ldr r0, [sp, #0x1c]
	lsl r2, r2, #0x10
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	lsl r3, r7, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	ldr r0, [sp, #0x28]
	add r6, r6, #1
	sub r7, r0, #2
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	add r2, r4, #3
	lsl r2, r2, #0x10
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	ldr r3, [sp, #0x18]
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	lsl r0, r6, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	lsl r0, r7, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #8]
	lsl r0, r5, #0x18
	lsr r0, r0, #0x18
	str r0, [sp, #0xc]
	ldr r3, [sp, #0x20]
	add r2, r4, #5
	lsl r2, r2, #0x10
	lsl r3, r3, #0x18
	ldr r0, [sp, #0x10]
	ldr r1, [sp, #0x14]
	lsr r2, r2, #0x10
	lsr r3, r3, #0x18
	bl FillBgTilemapRect
	add sp, #0x2c
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov82_0223E140


	thumb_func_start ov82_0223E2A4
ov82_0223E2A4: ; 0x0223E2A4
	push {r4, lr}
	add r4, r0, #0
	ldrb r0, [r4, #8]
	cmp r0, #0
	bne _0223E2E8
	ldr r0, [r4, #4]
	bl OverlayManager_Run
	cmp r0, #1
	bne _0223E2E8
	add r0, r4, #0
	add r0, #0xa4
	ldr r0, [r0]
	ldrb r1, [r0, #0x14]
	mov r0, #0x83
	lsl r0, r0, #2
	str r1, [r4, r0]
	add r0, r4, #0
	add r0, #0xa4
	ldr r0, [r0]
	bl Heap_Free
	ldr r0, [r4, #4]
	bl Heap_Free
	mov r0, #0
	str r0, [r4, #4]
	add r0, r4, #0
	bl ov82_0223E974
	mov r0, #0
	strh r0, [r4, #0x10]
	mov r0, #1
	pop {r4, pc}
_0223E2E8:
	mov r0, #0
	pop {r4, pc}
	thumb_func_end ov82_0223E2A4


	thumb_func_start ov82_0223E2EC
ov82_0223E2EC: ; 0x0223E2EC
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #7
	bhi _0223E33A
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223E304: ; jump table
	.short _0223E314 - _0223E304 - 2 ; case 0
	.short _0223E31E - _0223E304 - 2 ; case 1
	.short _0223E3EE - _0223E304 - 2 ; case 2
	.short _0223E448 - _0223E304 - 2 ; case 3
	.short _0223E4AA - _0223E304 - 2 ; case 4
	.short _0223E4E4 - _0223E304 - 2 ; case 5
	.short _0223E532 - _0223E304 - 2 ; case 6
	.short _0223E58A - _0223E304 - 2 ; case 7
_0223E314:
	mov r0, #0
	strb r0, [r4, #0xb]
	mov r0, #1
	strb r0, [r4, #8]
	b _0223E5B6
_0223E31E:
	ldr r1, _0223E5BC ; =gSystem
	ldr r1, [r1, #0x48]
	bl ov82_0223F300
	add r0, r4, #0
	bl ov82_0223F53C
	cmp r0, #0
	bne _0223E33C
	add r0, r4, #0
	bl ov82_0223F488
	cmp r0, #0
	bne _0223E33C
_0223E33A:
	b _0223E5B6
_0223E33C:
	ldrb r0, [r4, #0xd]
	bl ov80_02237920
	cmp r0, #0xfe
	bne _0223E36E
	ldr r0, _0223E5C0 ; =0x000005DD
	bl PlaySE
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x69
	str r0, [sp, #8]
	mov r0, #0
	add r1, r0, #0
	add r2, r0, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	mov r0, #1
	strh r0, [r4, #0x10]
	mov r0, #7
	strb r0, [r4, #8]
	b _0223E5B6
_0223E36E:
	add r0, r4, #0
	bl ov82_0223F6E4
	cmp r0, #1
	ldrb r0, [r4, #0xd]
	bne _0223E38E
	bl ov80_02237920
	cmp r0, #9
	beq _0223E3C2
	ldr r0, _0223E5C4 ; =0x000005F3
	bl PlaySE
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223E38E:
	bl ov82_0223F6C4
	mov r1, #0x86
	lsl r1, r1, #2
	ldr r1, [r4, r1]
	bl sub_02030BD0
	cmp r0, #0xa
	blo _0223E3AC
	ldr r0, _0223E5C4 ; =0x000005F3
	bl PlaySE
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223E3AC:
	ldrb r0, [r4, #0xd]
	bl ov80_02237920
	cmp r0, #9
	bne _0223E3C2
	ldr r0, _0223E5C4 ; =0x000005F3
	bl PlaySE
	add sp, #0x18
	mov r0, #0
	pop {r3, r4, r5, pc}
_0223E3C2:
	ldr r0, _0223E5C0 ; =0x000005DD
	bl PlaySE
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #0
	bne _0223E3E4
	ldrb r1, [r4, #0xd]
	ldr r0, [r4, #0x48]
	mov r2, #1
	bl ov82_0223F5E0
	ldr r0, [r4, #0x48]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
_0223E3E4:
	mov r0, #0
	strh r0, [r4, #0x14]
	mov r0, #2
	strb r0, [r4, #8]
	b _0223E5B6
_0223E3EE:
	mov r0, #0x14
	ldrsh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, #0x14]
	ldrsh r0, [r4, r0]
	neg r0, r0
	bl ov82_0223F948
	mov r0, #0x14
	ldrsh r0, [r4, r0]
	cmp r0, #8
	bne _0223E45C
	ldrb r0, [r4, #9]
	bl ov80_0223792C
	cmp r0, #0
	bne _0223E41C
	add r0, r4, #0
	bl ov82_0223F84C
	mov r0, #3
	strb r0, [r4, #8]
	b _0223E5B6
_0223E41C:
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl Options_GetFrame
	add r1, r0, #0
	add r0, r4, #0
	add r0, #0x4c
	bl ov82_0223FD78
	add r0, r4, #0
	mov r1, #0
	mov r2, #1
	bl ov82_0223EF7C
	strb r0, [r4, #0xa]
	ldrb r0, [r4, #0xd]
	add sp, #0x18
	strb r0, [r4, #0x1a]
	mov r0, #1
	strb r0, [r4, #0x17]
	pop {r3, r4, r5, pc}
_0223E448:
	add r0, #0x8c
	ldr r0, [r0]
	bl ov82_0223FE18
	cmp r0, #0
	beq _0223E45C
	cmp r0, #1
	beq _0223E45E
	cmp r0, #2
	beq _0223E49E
_0223E45C:
	b _0223E5B6
_0223E45E:
	add r0, r4, #0
	bl ov82_0223F834
	add r0, r4, #0
	bl ov82_0223F6CC
	cmp r0, #1
	bne _0223E482
	add r0, r4, #0
	bl ov82_0223F6E4
	cmp r0, #0
	bne _0223E482
	ldrb r0, [r4, #0xd]
	strb r0, [r4, #0x1f]
	mov r0, #5
	strb r0, [r4, #8]
	b _0223E5B6
_0223E482:
	ldr r0, _0223E5C8 ; =0x000005DC
	mov r1, #0
	bl StopSE
	ldr r0, _0223E5CC ; =0x00000623
	bl PlaySE
	ldrb r0, [r4, #0x1f]
	cmp r0, #0x75
	beq _0223E498
	strb r0, [r4, #0xd]
_0223E498:
	add sp, #0x18
	mov r0, #1
	pop {r3, r4, r5, pc}
_0223E49E:
	add r0, r4, #0
	bl ov82_0223F834
	mov r0, #4
	strb r0, [r4, #8]
	b _0223E5B6
_0223E4AA:
	mov r0, #0x14
	ldrsh r1, [r4, r0]
	sub r1, r1, #1
	strh r1, [r4, #0x14]
	ldrsh r0, [r4, r0]
	neg r0, r0
	bl ov82_0223F948
	mov r0, #0x14
	ldrsh r0, [r4, r0]
	cmp r0, #0
	bgt _0223E5B6
	add r0, r4, #0
	bl ov82_0223F8E4
	ldrb r0, [r4, #0x1e]
	cmp r0, #1
	bne _0223E4D4
	mov r0, #0
	strb r0, [r4, #8]
	b _0223E5B6
_0223E4D4:
	cmp r0, #0
	bne _0223E4DE
	mov r0, #1
	strb r0, [r4, #8]
	b _0223E5B6
_0223E4DE:
	bl GF_AssertFail
	b _0223E5B6
_0223E4E4:
	add r0, #0x9c
	ldr r0, [r0]
	bl Options_GetFrame
	add r1, r0, #0
	add r0, r4, #0
	add r0, #0x4c
	bl ov82_0223FD78
	add r0, r4, #0
	add r0, #0xa0
	ldr r0, [r0]
	bl Save_PlayerData_GetOptionsAddr
	bl Options_GetTextFrameDelay
	mov r3, #1
	str r3, [sp]
	str r0, [sp, #4]
	add r1, r4, #0
	str r3, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #0xf
	str r0, [sp, #0x10]
	str r3, [sp, #0x14]
	add r0, r4, #0
	add r1, #0x4c
	mov r2, #0x20
	bl ov82_0223EF1C
	strb r0, [r4, #0xa]
	add r0, r4, #0
	add r0, #0x4c
	bl CopyWindowToVram
	mov r0, #6
	strb r0, [r4, #8]
	b _0223E5B6
_0223E532:
	ldrb r0, [r4, #0xa]
	bl TextPrinterCheckActive
	cmp r0, #0
	bne _0223E5B6
	mov r0, #1
	strb r0, [r4, #0x1e]
	add r0, r4, #0
	bl ov82_0223F90C
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl ov82_0223FCFC
	ldr r0, [r4, #0x48]
	mov r1, #0x13
	mov r2, #0
	bl ov82_0223F5E0
	ldr r1, [r4, #0x48]
	add r0, r4, #0
	bl ov82_0223F580
	mov r0, #0x13
	strb r0, [r4, #0xd]
	add r0, r4, #0
	bl ov82_0223F558
	add r5, r0, #0
	add r0, r4, #0
	bl ov82_0223F570
	add r2, r0, #0
	mov r0, #0x81
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	add r1, r5, #0
	bl ov82_0223FCBC
	mov r0, #4
	strb r0, [r4, #8]
	b _0223E5B6
_0223E58A:
	bl IsPaletteFadeFinished
	cmp r0, #1
	bne _0223E5B6
	add r0, r4, #0
	bl ov82_0223F224
	add r0, r4, #0
	bl ov82_0223E8C4
	add r1, r4, #0
	add r1, #0xa4
	ldr r0, _0223E5D0 ; =gOverlayTemplate_PokemonSummary
	ldr r1, [r1]
	mov r2, #0x69
	bl OverlayManager_New
	str r0, [r4, #4]
	mov r0, #1
	add sp, #0x18
	strb r0, [r4, #0xb]
	pop {r3, r4, r5, pc}
_0223E5B6:
	mov r0, #0
	add sp, #0x18
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0223E5BC: .word gSystem
_0223E5C0: .word 0x000005DD
_0223E5C4: .word 0x000005F3
_0223E5C8: .word 0x000005DC
_0223E5CC: .word 0x00000623
_0223E5D0: .word gOverlayTemplate_PokemonSummary
	thumb_func_end ov82_0223E2EC


	thumb_func_start ov82_0223E5D4
ov82_0223E5D4: ; 0x0223E5D4
	push {r4, lr}
	add r4, r0, #0
	ldrb r1, [r4, #8]
	cmp r1, #9
	bhi _0223E632
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0223E5EA: ; jump table
	.short _0223E5FE - _0223E5EA - 2 ; case 0
	.short _0223E620 - _0223E5EA - 2 ; case 1
	.short _0223E708 - _0223E5EA - 2 ; case 2
	.short _0223E666 - _0223E5EA - 2 ; case 3
	.short _0223E6C2 - _0223E5EA - 2 ; case 4
	.short _0223E726 - _0223E5EA - 2 ; case 5
	.short _0223E762 - _0223E5EA - 2 ; case 6
	.short _0223E772 - _0223E5EA - 2 ; case 7
	.short _0223E7AA - _0223E5EA - 2 ; case 8
	.short _0223E7BA - _0223E5EA - 2 ; case 9
_0223E5FE:
	ldrb r0, [r4, #0x1a]
	bl ov82_0223F6C4
	add r2, r0, #0
	add r0, r4, #0
	mov r1, #5
	bl ov82_0223F6E8
	cmp r0, #1
	bne _0223E632
	mov r0, #0
	strb r0, [r4, #0x1b]
	strb r0, [r4, #0x1a]
	strb r0, [r4, #0x17]
	mov r0, #1
	strb r0, [r4, #8]
	b _0223E7D6
_0223E620:
	ldrb r0, [r4, #0x1b]
	cmp r0, #0
	beq _0223E62C
	sub r0, r0, #1
	strb r0, [r4, #0x1b]
	b _0223E7D6
_0223E62C:
	ldrb r0, [r4, #0x16]
	cmp r0, #2
	bhs _0223E634
_0223E632:
	b _0223E7D6
_0223E634:
	mov r0, #0
	strb r0, [r4, #0x16]
	ldrb r0, [r4, #0x18]
	cmp r0, #0x14
	bhs _0223E652
	bl sub_0203769C
	cmp r0, #0
	bne _0223E64C
	mov r0, #2
	strb r0, [r4, #8]
	b _0223E7D6
_0223E64C:
	mov r0, #3
	strb r0, [r4, #8]
	b _0223E7D6
_0223E652:
	bl sub_0203769C
	cmp r0, #0
	bne _0223E660
	mov r0, #3
	strb r0, [r4, #8]
	b _0223E7D6
_0223E660:
	mov r0, #2
	strb r0, [r4, #8]
	b _0223E7D6
_0223E666:
	mov r0, #0
	bl ov82_0223F948
	mov r1, #0
	mov r0, #0x82
	strh r1, [r4, #0x14]
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl ov82_0223FCB0
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	bl Options_GetFrame
	add r1, r0, #0
	add r0, r4, #0
	add r0, #0x4c
	bl ov82_0223FD78
	ldr r0, [r4, #0x24]
	mov r1, #0
	bl ov80_0222A7CC
	add r0, r4, #0
	mov r1, #0xb
	mov r2, #1
	bl ov82_0223EF7C
	strb r0, [r4, #0xa]
	mov r0, #0xa
	mov r1, #0x9f
	strb r0, [r4, #0x1b]
	lsl r1, r1, #2
	ldrb r1, [r4, r1]
	ldr r0, [r4, #0x48]
	mov r2, #2
	bl ov82_0223F5E0
	ldr r0, [r4, #0x48]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #4
	strb r0, [r4, #8]
	b _0223E7D6
_0223E6C2:
	ldr r1, _0223E7DC ; =0x0000027D
	ldrb r2, [r4, r1]
	cmp r2, #0
	beq _0223E73A
	cmp r2, #1
	bne _0223E6D8
	sub r0, r1, #1
	ldrb r0, [r4, r0]
	strb r0, [r4, #0xd]
	mov r0, #1
	pop {r4, pc}
_0223E6D8:
	bl ov82_0223F90C
	mov r1, #0x9f
	lsl r1, r1, #2
	ldrb r1, [r4, r1]
	ldr r0, [r4, #0x48]
	mov r2, #0
	bl ov82_0223F5E0
	ldr r0, [r4, #0x48]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	mov r0, #0x9f
	mov r2, #0xff
	lsl r0, r0, #2
	strb r2, [r4, r0]
	mov r1, #0
	add r0, r0, #1
	strb r1, [r4, r0]
	strb r2, [r4, #0x18]
	mov r0, #1
	strb r0, [r4, #0x19]
	pop {r4, pc}
_0223E708:
	ldrb r1, [r4, #0xd]
	ldr r0, [r4, #0x48]
	mov r2, #1
	bl ov82_0223F5E0
	ldr r0, [r4, #0x48]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
	add r0, r4, #0
	bl ov82_0223F84C
	mov r0, #5
	strb r0, [r4, #8]
	b _0223E7D6
_0223E726:
	add r0, #0x8c
	ldr r0, [r0]
	bl ov82_0223FE18
	cmp r0, #0
	beq _0223E7D6
	cmp r0, #1
	beq _0223E73C
	cmp r0, #2
	beq _0223E756
_0223E73A:
	b _0223E7D6
_0223E73C:
	ldr r0, _0223E7E0 ; =0x000005DC
	mov r1, #0
	bl StopSE
	ldr r0, _0223E7E4 ; =0x00000623
	bl PlaySE
	add r0, r4, #0
	bl ov82_0223F834
	mov r0, #6
	strb r0, [r4, #8]
	b _0223E7D6
_0223E756:
	add r0, r4, #0
	bl ov82_0223F834
	mov r0, #7
	strb r0, [r4, #8]
	b _0223E7D6
_0223E762:
	mov r1, #6
	mov r2, #1
	bl ov82_0223F6E8
	cmp r0, #1
	bne _0223E7D6
	mov r0, #1
	pop {r4, pc}
_0223E772:
	mov r1, #0x14
	ldrsh r2, [r4, r1]
	cmp r2, #0
	ble _0223E788
	sub r0, r2, #1
	strh r0, [r4, #0x14]
	ldrsh r0, [r4, r1]
	neg r0, r0
	bl ov82_0223F948
	b _0223E7D6
_0223E788:
	mov r1, #6
	mov r2, #2
	bl ov82_0223F6E8
	cmp r0, #1
	bne _0223E7D6
	add r0, r4, #0
	bl ov82_0223F8E4
	mov r0, #0x9f
	mov r1, #0xff
	lsl r0, r0, #2
	strb r1, [r4, r0]
	strb r1, [r4, #0x18]
	mov r0, #1
	strb r0, [r4, #0x19]
	pop {r4, pc}
_0223E7AA:
	bl sub_02037BEC
	mov r0, #0x68
	bl sub_02037AC0
	mov r0, #9
	strb r0, [r4, #8]
	b _0223E7D6
_0223E7BA:
	mov r0, #0x68
	bl sub_02037B38
	cmp r0, #1
	bne _0223E7D6
	bl sub_02037BEC
	mov r0, #0x69
	bl sub_020379A0
	mov r0, #0xff
	strb r0, [r4, #0x18]
	mov r0, #1
	pop {r4, pc}
_0223E7D6:
	mov r0, #0
	pop {r4, pc}
	nop
_0223E7DC: .word 0x0000027D
_0223E7E0: .word 0x000005DC
_0223E7E4: .word 0x00000623
	thumb_func_end ov82_0223E5D4
