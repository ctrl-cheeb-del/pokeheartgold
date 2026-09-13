#include "constants/sndseq.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0010.h"
	.include "asm/macros.inc"
	.include "overlay_15.inc"
	.include "global.inc"

	.text
	.public ov15_021FDD70
	.public ov15_021FDF88
	.public ov15_021FE020
	.extern Bag_Exit
	.extern Bag_Init
	.extern Bag_Main
	.extern ov15_021F9C78
	.extern ov15_021FB680
	.extern ov15_021FBC6C
	.extern ov15_021FBC8C
	.extern ov15_021FBCAC
	.extern ov15_021FC224
	.extern ov15_021FC37C
	.extern ov15_021FC3E0
	.extern ov15_021FC3EC
	.extern ov15_021FD3C0
	.extern ov15_021FD3F0
	.extern ov15_021FE17C
	.extern ov15_021FE1D0
	.extern ov15_021FE204
	.extern ov15_021FE3E0
	.extern ov15_021FE584
	.extern ov15_021FE5A4
	.extern ov15_021FE5C4
	.extern ov15_021FE620

	.public Bag_Exit
	.public Bag_Init
	.public Bag_Main
	.public ov15_021F9C78
	.public ov15_021FB680
	.public ov15_021FBC6C
	.public ov15_021FBC8C
	.public ov15_021FBCAC
	.public ov15_021FC224
	.public ov15_021FC37C
	.public ov15_021FC3E0
	.public ov15_021FC3EC
	.public ov15_021FD3C0
	.public ov15_021FD3F0
	.public ov15_021FE17C
	.public ov15_021FE1D0
	.public ov15_021FE204
	.public ov15_021FE3E0
	.public ov15_021FE584
	.public ov15_021FE5A4
	.public ov15_021FE5C4
	.public ov15_021FE620
	.extern _022004EC
	.extern _02201300
	.extern _02201480
	.extern ov15_021FEA5C
	.extern ov15_021FEB64
	.extern ov15_021FEB84
	.extern ov15_021FECA0
	.extern ov15_021FECC4
	.extern ov15_021FECD8
	.extern ov15_021FED24
	.extern ov15_021FED3C
	.extern ov15_021FED58
	.extern ov15_021FED60
	.extern ov15_021FEDEC
	.extern ov15_021FEEA4
	.extern ov15_021FEF48
	.extern ov15_021FF004
	.extern ov15_021FF058
	.extern ov15_021FF068
	.extern ov15_021FF0FC
	.extern ov15_021FF1E0
	.extern ov15_021FF29C
	.extern ov15_021FF364
	.extern ov15_021FF4EC
	.extern ov15_021FF560
	.extern ov15_021FF6BC
	.extern ov15_021FF758
	.extern ov15_021FF7AC
	.extern ov15_021FF7C4
	.extern ov15_021FF7FC
	.extern ov15_021FF834
	.extern ov15_021FF844
	.extern ov15_021FF850
	.extern ov15_021FF894
	.extern ov15_021FF8D4
	.extern ov15_021FF950
	.extern ov15_021FF964
	.extern ov15_021FFECC
	.extern ov15_021FFF24
	.extern ov15_021FFF34
	.extern ov15_021FFFDC
	.extern ov15_02200030
	.extern ov15_0220005C
	.extern ov15_02200140
	.extern ov15_022001C4
	.extern ov15_0220023C
	.extern ov15_02200294
	.extern ov15_022002B4
	.extern ov15_022002EC
	.extern ov15_02200300
	.extern ov15_02200428
	.extern ov15_02200458
	.extern ov15_022004DC
	.extern ov15_022004F4
	.extern ov15_02200500
	.extern ov15_0220050C
	.extern ov15_02200518
	.extern ov15_02200528
	.extern ov15_02200529
	.extern ov15_0220052A
	.extern ov15_0220052B
	.extern ov15_0220053C
	.extern ov15_02200584
	.extern ov15_02200585
	.extern ov15_02200586
	.extern ov15_02200587
	.extern ov15_022005CC
	.extern ov15_02200618
	.extern ov15_02200640
	.extern ov15_02200641
	.extern ov15_02200642
	.extern ov15_02200643
	.extern ov15_022006CC
	.extern ov15_022006E8
	.extern ov15_02200704
	.extern ov15_02200720
	.extern ov15_0220073C
	.extern ov15_02200758
	.extern ov15_02200774
	.extern ov15_02200790
	.extern ov15_022008B0
	.extern ov15_022008D0
	.extern ov15_022008E8
	.extern ov15_02200908
	.extern ov15_02201304
	.extern ov15_02201314
	.extern ov15_02201328
	.extern ov15_02201340
	.extern ov15_02201368
	.extern ov15_022013A8
	.extern ov15_02201468

	thumb_func_start ov15_021FDD70
ov15_021FDD70: ; 0x021FDD70
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r7, r0, #0
	mov r0, #0xf
	mov r1, #6
	bl NARC_New
	str r0, [sp, #0x10]
	ldr r0, _021FDF14 ; =0x00000808
	mov r1, #6
	add r0, r7, r0
	mov r2, #4
	bl HeapExp_FndInitAllocator
	ldr r0, _021FDF18 ; =0x0000081C
	add r4, r7, r0
	ldr r0, _021FDF1C ; =0x00000615
	ldrb r0, [r7, r0]
	cmp r0, #0
	bne _021FDDA8
	mov r0, #0x39
	str r0, [sp, #8]
	mov r0, #0x41
	str r0, [sp, #4]
	mov r0, #0x49
	mov r1, #0x37
	str r0, [sp]
	b _021FDDB6
_021FDDA8:
	mov r0, #0x4c
	str r0, [sp, #8]
	mov r0, #0x54
	str r0, [sp, #4]
	mov r0, #0x5c
	mov r1, #0x4a
	str r0, [sp]
_021FDDB6:
	ldr r0, [sp, #0x10]
	mov r2, #6
	bl NARC_AllocAndReadWholeMember
	add r1, r4, #0
	add r2, r4, #0
	str r0, [r4, #0x58]
	add r0, r4, #0
	add r1, #0x54
	add r2, #0x58
	bl GF3dRender_InitObjFromHeader
	ldr r0, [r4, #0x58]
	bl NNS_G3dGetTex
	str r0, [sp, #0xc]
	ldr r0, [r4, #0x54]
	mov r1, #1
	mov r2, #0x40
	bl NNSi_G3dModifyMatFlag
	ldr r0, [r4, #0x54]
	mov r1, #1
	mov r2, #0x80
	bl NNSi_G3dModifyMatFlag
	mov r1, #1
	ldr r0, [r4, #0x54]
	lsl r2, r1, #9
	bl NNSi_G3dModifyMatFlag
	mov r1, #1
	ldr r0, [r4, #0x54]
	lsl r2, r1, #0xa
	bl NNSi_G3dModifyMatFlag
	mov r2, #0x3f
	ldr r0, [r4, #0x54]
	mov r1, #1
	lsl r2, r2, #0x18
	bl NNSi_G3dModifyPolygonAttrMask
	mov r6, #0
	add r5, r4, #0
_021FDE0E:
	ldr r1, [sp, #8]
	ldr r0, [sp, #0x10]
	add r1, r1, r6
	mov r2, #6
	bl NARC_AllocAndReadWholeMember
	mov r1, #0
	str r0, [r5, #0x5c]
	bl NNS_G3dGetAnmByIdx
	str r0, [sp, #0x14]
	ldr r0, _021FDF14 ; =0x00000808
	ldr r1, [sp, #0x14]
	ldr r2, [r4, #0x54]
	add r0, r7, r0
	bl NNS_G3dAllocAnmObj
	add r1, r5, #0
	add r1, #0xa0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xa0
	ldr r0, [r0]
	ldr r1, [sp, #0x14]
	ldr r2, [r4, #0x54]
	ldr r3, [sp, #0xc]
	bl NNS_G3dAnmObjInit
	ldr r1, [sp, #4]
	ldr r0, [sp, #0x10]
	add r1, r1, r6
	mov r2, #6
	bl NARC_AllocAndReadWholeMember
	mov r1, #0
	str r0, [r5, #0x7c]
	bl NNS_G3dGetAnmByIdx
	str r0, [sp, #0x18]
	ldr r0, _021FDF14 ; =0x00000808
	ldr r1, [sp, #0x18]
	ldr r2, [r4, #0x54]
	add r0, r7, r0
	bl NNS_G3dAllocAnmObj
	add r1, r5, #0
	add r1, #0xc0
	str r0, [r1]
	add r0, r5, #0
	add r0, #0xc0
	ldr r0, [r0]
	ldr r1, [sp, #0x18]
	ldr r2, [r4, #0x54]
	ldr r3, [sp, #0xc]
	bl NNS_G3dAnmObjInit
	add r6, r6, #1
	add r5, r5, #4
	cmp r6, #8
	blo _021FDE0E
	ldr r0, [sp, #0x10]
	ldr r1, [sp]
	mov r2, #6
	bl NARC_AllocAndReadWholeMember
	add r1, r4, #0
	add r1, #0x9c
	str r0, [r1]
	add r0, r4, #0
	add r0, #0x9c
	ldr r0, [r0]
	mov r1, #0
	bl NNS_G3dGetAnmByIdx
	add r5, r0, #0
	ldr r0, _021FDF14 ; =0x00000808
	ldr r2, [r4, #0x54]
	add r0, r7, r0
	add r1, r5, #0
	bl NNS_G3dAllocAnmObj
	add r1, r4, #0
	add r1, #0xe0
	str r0, [r1]
	add r0, r4, #0
	add r0, #0xe0
	ldr r0, [r0]
	ldr r2, [r4, #0x54]
	ldr r3, [sp, #0xc]
	add r1, r5, #0
	bl NNS_G3dAnmObjInit
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r7, r0]
	add r0, #0x64
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xa0
	ldr r1, [r1]
	bl NNS_G3dRenderObjAddAnmObj
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xc0
	ldr r1, [r1]
	bl NNS_G3dRenderObjAddAnmObj
	add r0, r4, #0
	add r4, #0xe0
	ldr r1, [r4]
	bl NNS_G3dRenderObjAddAnmObj
	ldr r0, [sp, #0x10]
	bl NARC_Delete
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021FDF14: .word 0x00000808
_021FDF18: .word 0x0000081C
_021FDF1C: .word 0x00000615
	thumb_func_end ov15_021FDD70


	thumb_func_start ov15_021FDF20
ov15_021FDF20: ; 0x021FDF20
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _021FDF80 ; =0x0000081C
	ldr r7, _021FDF84 ; =0x00000808
	add r0, r5, r0
	str r0, [sp]
	mov r6, #0
	add r4, r0, #0
_021FDF30:
	add r1, r4, #0
	add r1, #0xa0
	ldr r1, [r1]
	add r0, r5, r7
	bl NNS_G3dFreeAnmObj
	add r1, r4, #0
	add r1, #0xc0
	ldr r1, [r1]
	add r0, r5, r7
	bl NNS_G3dFreeAnmObj
	ldr r0, [r4, #0x5c]
	bl Heap_Free
	ldr r0, [r4, #0x7c]
	bl Heap_Free
	add r6, r6, #1
	add r4, r4, #4
	cmp r6, #8
	blo _021FDF30
	ldr r1, [sp]
	ldr r0, _021FDF84 ; =0x00000808
	add r1, #0xe0
	ldr r1, [r1]
	add r0, r5, r0
	bl NNS_G3dFreeAnmObj
	ldr r0, [sp]
	add r0, #0x9c
	ldr r0, [r0]
	bl Heap_Free
	ldr r0, [sp]
	ldr r0, [r0, #0x58]
	bl Heap_Free
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021FDF80: .word 0x0000081C
_021FDF84: .word 0x00000808
	thumb_func_end ov15_021FDF20


	thumb_func_start ov15_021FDF88
ov15_021FDF88: ; 0x021FDF88
	push {r3, r4, r5, lr}
	add r5, r0, #0
	ldr r0, _021FE01C ; =0x0000081C
	add r4, r5, r0
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xc0
	ldr r1, [r1]
	bl NNS_G3dRenderObjRemoveAnmObj
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xa0
	ldr r1, [r1]
	bl NNS_G3dRenderObjRemoveAnmObj
	mov r0, #0x8d
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	add r0, #0x64
	ldrb r1, [r0]
	add r0, r4, #0
	add r0, #0xe4
	str r1, [r0]
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	mov r0, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xa0
	ldr r1, [r1]
	str r0, [r1]
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xc0
	ldr r1, [r1]
	str r0, [r1]
	add r1, r4, #0
	add r1, #0xe0
	ldr r1, [r1]
	str r0, [r1]
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xa0
	ldr r1, [r1]
	bl NNS_G3dRenderObjAddAnmObj
	add r1, r4, #0
	add r1, #0xe4
	ldr r1, [r1]
	add r0, r4, #0
	lsl r1, r1, #2
	add r1, r4, r1
	add r1, #0xc0
	ldr r1, [r1]
	bl NNS_G3dRenderObjAddAnmObj
	pop {r3, r4, r5, pc}
	.balign 4, 0
_021FE01C: .word 0x0000081C
	thumb_func_end ov15_021FDF88


	thumb_func_start ov15_021FE020
ov15_021FE020: ; 0x021FE020
	push {r3, r4, lr}
	sub sp, #0x14
	add r4, r0, #0
	mov r0, #0x12
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #6
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	mov r2, #1
	str r2, [sp, #0x10]
	ldr r0, [r4]
	add r1, r4, #4
	mov r3, #0
	bl AddWindowParameterized
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0xc1
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0x14
	mov r2, #1
	mov r3, #0
	bl AddWindowParameterized
	mov r1, #1
	str r1, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r3, #2
	str r3, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0x24
	mov r2, #4
	bl AddWindowParameterized
	mov r0, #1
	str r0, [sp]
	mov r0, #0x1b
	str r0, [sp, #4]
	mov r2, #4
	add r1, r4, #0
	str r2, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r0, #0x53
	str r0, [sp, #0x10]
	ldr r0, [r4]
	add r1, #0x34
	mov r3, #2
	bl AddWindowParameterized
	mov r0, #0xd
	str r0, [sp]
	mov r0, #0xc
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	mov r0, #0xdb
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0x44
	mov r2, #1
	mov r3, #0x13
	bl AddWindowParameterized
	mov r0, #0xc
	str r0, [sp]
	mov r0, #0xb
	str r0, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	str r0, [sp, #0xc]
	ldr r0, _021FE150 ; =0x0000012B
	add r1, r4, #0
	str r0, [sp, #0x10]
	mov r2, #1
	ldr r0, [r4]
	add r1, #0x54
	add r3, r2, #0
	bl AddWindowParameterized
	mov r0, #0x15
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r0, #0x37
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0x64
	mov r2, #4
	mov r3, #0xa
	bl AddWindowParameterized
	add r0, r4, #0
	add r0, #0x64
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r0, #0x15
	str r0, [sp]
	mov r0, #7
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #0xb
	str r0, [sp, #0xc]
	mov r0, #0x45
	str r0, [sp, #0x10]
	add r1, r4, #0
	ldr r0, [r4]
	add r1, #0x74
	mov r2, #4
	mov r3, #0x18
	bl AddWindowParameterized
	add r0, r4, #0
	add r0, #0x74
	mov r1, #0
	bl FillWindowPixelBuffer
	mov r2, #0
	add r1, r2, #0
_021FE13E:
	add r0, r4, #0
	add r0, #0xb4
	add r2, r2, #1
	add r4, #0x10
	str r1, [r0]
	cmp r2, #0x18
	blt _021FE13E
	add sp, #0x14
	pop {r3, r4, pc}
	.balign 4, 0
_021FE150: .word 0x0000012B
	thumb_func_end ov15_021FE020
