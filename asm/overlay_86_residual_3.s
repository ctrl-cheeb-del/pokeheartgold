	.include "asm/macros.inc"
	.public _021E7E98
	.public ov86_021E5900
	.public ov86_021E5A40
	.public ov86_021E5AA4
	.public ov86_021E5B38
	.public ov86_021E5BA0
	.public ov86_021E5C94
	.public ov86_021E5CDC
	.public ov86_021E5D10
	.public ov86_021E5D30
	.public ov86_021E5E0C
	.public ov86_021E5E54
	.public ov86_021E5E90
	.public ov86_021E5E98
	.public ov86_021E5ECC
	.public ov86_021E5F58
	.public ov86_021E5FBC
	.public ov86_021E5FD8
	.public ov86_021E6024
	.public ov86_021E6064
	.public ov86_021E60B8
	.public ov86_021E6114
	.public ov86_021E62F4
	.public ov86_021E6484
	.public ov86_021E64E0
	.public ov86_021E668C
	.public ov86_021E66D0
	.public ov86_021E68B8
	.public ov86_021E690C
	.public ov86_021E6A34
	.public ov86_021E6A88
	.public ov86_021E6BA8
	.public ov86_021E6DD8
	.public ov86_021E6E30
	.public ov86_021E6E98
	.public ov86_021E6FF4
	.public ov86_021E703C
	.public ov86_021E705C
	.public ov86_021E707C
	.public ov86_021E7094
	.public ov86_021E71C0
	.public ov86_021E71FC
	.public ov86_021E720C
	.public ov86_021E723C
	.public ov86_021E7258
	.public ov86_021E7344
	.public ov86_021E73CC
	.public ov86_021E73E8
	.public ov86_021E73EC
	.public ov86_021E7418
	.public ov86_021E74D0
	.public ov86_021E74F0
	.public ov86_021E752C
	.public ov86_021E757C
	.public ov86_021E7598
	.public ov86_021E75EC
	.public ov86_021E7630
	.public ov86_021E7678
	.public ov86_021E7680
	.public ov86_021E7688
	.public ov86_021E7710
	.public ov86_021E77BC
	.public ov86_021E781C
	.public ov86_021E7860
	.public ov86_021E78A8
	.public ov86_021E78B0
	.public ov86_021E78B8
	.public ov86_021E792C
	.public ov86_021E7984
	.public ov86_021E7B54
	.public ov86_021E7B68
	.public ov86_021E7C70
	.public ov86_021E7CA0
	.public ov86_021E7CF8
	.public ov86_021E7D8C
	.public ov86_021E7DA8
	.public ov86_021E7DD4
	.public ov86_021E7DF8
	.public ov86_021E7E40
	.public ov86_021E7E68
	.public ov86_021E7E90
	.public ov86_021E7E9C
	.public ov86_021E7EA8
	.public ov86_021E7EB8
	.public ov86_021E7EC8
	.public ov86_021E7ED8
	.public ov86_021E7EEC
	.public ov86_021E7F04
	.public ov86_021E7F20
	.public ov86_021E7F3C
	.public ov86_021E7F58
	.public ov86_021E7F74
	.public ov86_021E7F94
	.public ov86_021E7FBC
	.public ov86_021E7FE4
	.public ov86_021E802C
	.public ov86_021E8094
	.public ov86_021E8104
	.public ov86_021E81DC
	.public ov86_021E81F8
	.public ov86_021E8210
	.public ov86_021E8230
	.public ov86_021E8258
	.public ov86_021E8290
	.public ov86_021E82D8
	.include "overlay_86.inc"
	.include "global.inc"

	.text
	.public ov86_021E5D10
	.public ov86_021E5E54
	.public ov86_021E5E90
	.public ov86_021E5FBC
	.public ov86_021E668C
	.public ov86_021E703C
	.public ov86_021E705C
	.public ov86_021E707C
	.public ov86_021E71FC
	.public ov86_021E720C
	.public ov86_021E723C
	.public ov86_021E73CC
	.public ov86_021E73E8
	.public ov86_021E74D0
	.public ov86_021E74F0
	.public ov86_021E757C
	.public ov86_021E75EC
	.public ov86_021E7678
	.public ov86_021E7680
	.public ov86_021E781C
	.public ov86_021E78A8
	.public ov86_021E78B0
	.public ov86_021E7B54
	.public ov86_021E7C70
	.public ov86_021E7D8C
	.public ov86_021E7DD4
	.public ov86_021E7E40
	.public ov86_021E7E68
	.public ov86_021E7E90

	thumb_func_start ov86_021E5E98
ov86_021E5E98: ; 0x021E5E98
	mov r1, #0
	cmp r0, #6
	bhi _021E5EC8
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021E5EAA: ; jump table
	.short _021E5EC8 - _021E5EAA - 2 ; case 0
	.short _021E5EC6 - _021E5EAA - 2 ; case 1
	.short _021E5EB8 - _021E5EAA - 2 ; case 2
	.short _021E5EB8 - _021E5EAA - 2 ; case 3
	.short _021E5EBE - _021E5EAA - 2 ; case 4
	.short _021E5EBA - _021E5EAA - 2 ; case 5
	.short _021E5EC2 - _021E5EAA - 2 ; case 6
_021E5EB8:
	b _021E5EC8
_021E5EBA:
	mov r1, #1
	b _021E5EC8
_021E5EBE:
	mov r1, #2
	b _021E5EC8
_021E5EC2:
	mov r1, #3
	b _021E5EC8
_021E5EC6:
	mov r1, #4
_021E5EC8:
	add r0, r1, #0
	bx lr
	thumb_func_end ov86_021E5E98


	thumb_func_start ov86_021E5ECC
ov86_021E5ECC: ; 0x021E5ECC
	push {r3, r4, r5, r6, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #0xb7
	mov r1, #0x79
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	mov r1, #0x79
	str r1, [sp, #0xc]
	ldr r2, [r5, #0xc]
	mov r1, #0x8c
	add r3, r6, #0
	add r4, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0x60
	str r0, [sp]
	mov r0, #0x79
	mov r2, #0
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xc3
	add r3, r2, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x79
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #0x8b
	add r3, r6, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x79
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0x8f
	mov r2, #1
	add r3, sp, #0x10
	bl GfGfxLoader_GetScrnDataFromOpenNarc
	add r6, r0, #0
	ldr r0, [sp, #0x10]
	mov r1, #0xcd
	lsl r1, r1, #2
	add r0, #0xc
	add r1, r5, r1
	mov r2, #0x60
	bl MIi_CpuCopy16
	add r0, r6, #0
	bl Heap_Free
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x14
	pop {r3, r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov86_021E5ECC


	thumb_func_start ov86_021E5F58
ov86_021E5F58: ; 0x021E5F58
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r5, r0, #0
	add r6, r1, #0
	mov r0, #0xb7
	mov r1, #0x79
	bl NARC_New
	mov r1, #0
	str r1, [sp]
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	mov r1, #0x79
	str r1, [sp, #0xc]
	ldr r2, [r5, #0xc]
	mov r1, #0x8e
	add r3, r6, #0
	add r4, r0, #0
	bl GfGfxLoader_LoadCharDataFromOpenNarc
	mov r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	mov r0, #0x79
	str r0, [sp, #0xc]
	ldr r2, [r5, #0xc]
	add r0, r4, #0
	mov r1, #0x8d
	add r3, r6, #0
	bl GfGfxLoader_LoadScrnDataFromOpenNarc
	mov r0, #0x20
	str r0, [sp]
	mov r0, #0x79
	str r0, [sp, #4]
	add r0, r4, #0
	mov r1, #0xc4
	mov r2, #4
	mov r3, #0
	bl GfGfxLoader_GXLoadPalFromOpenNarc
	add r0, r4, #0
	bl NARC_Delete
	add sp, #0x10
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov86_021E5F58
