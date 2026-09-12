	.include "asm/macros.inc"
	.include "overlay_75.inc"
	.include "global.inc"
	.public gApplication_TitleScreen

	.text
	.public _02249B20
	.public _02249BE0
	.public ov75_02246960
	.public ov75_022469D8
	.public ov75_02246B00
	.public ov75_02246B48
	.public ov75_02246B98
	.public ov75_02246C3C
	.public ov75_02246D08
	.public ov75_02246D40
	.public ov75_02246DB4
	.public ov75_02246DFC
	.public ov75_02246E3C
	.public ov75_02246E78
	.public ov75_02246F0C
	.public ov75_02247118
	.public ov75_02247180
	.public ov75_0224725C
	.public ov75_02247450
	.public ov75_022476E8
	.public ov75_02247790
	.public ov75_02247890
	.public ov75_022478E0
	.public ov75_02247A98
	.public ov75_02247B98
	.public ov75_02247C70
	.public ov75_02247D24
	.public ov75_02248034
	.public ov75_022480B8
	.public ov75_022483EC
	.public ov75_02248584
	.public ov75_02248684
	.public ov75_022486EC
	.public ov75_0224874C
	.public ov75_02248774
	.public ov75_02248800
	.public ov75_022488BC
	.public ov75_02248994
	.public ov75_02248A20
	.public ov75_02248B8C
	.public ov75_02248C84
	.public ov75_02248D2C
	.public ov75_02248F18
	.public ov75_02248F7C
	.public ov75_02248FE8
	.public ov75_022490D8
	.public ov75_022491CC
	.public ov75_022491F0
	.public ov75_02249278
	.public ov75_0224937C
	.public ov75_02249478
	.public ov75_022494CC
	.public ov75_02249534
	.public ov75_02249550
	.public ov75_022495B0
	.public ov75_0224964C
	.public ov75_02249684
	.public ov75_022496B8
	.public ov75_0224971C
	.public ov75_02249780
	.public ov75_02249838
	.public ov75_02249884
	.public ov75_022498E4
	.public ov75_022498F4
	.public ov75_02249904
	.public ov75_02249974
	.public ov75_02249978
	.public ov75_0224997C
	.public ov75_0224998C
	.public ov75_0224999C
	.public ov75_022499BC
	.public ov75_022499DC
	.public ov75_022499FC
	.public ov75_02249A24
	.public ov75_02249A5C
	.public ov75_02249ACC
	.public ov75_02249AD0
	.public ov75_02249ADC
	.public ov75_02249B24
	.public ov75_02249B30
	.public ov75_App_MainMenu_SelectOption_WiiMessageSettings
	.public ov75_02246BCC
	.public ov75_02246BD8
	.public ov75_02246BE0
	.public ov75_02246BE8
	.public ov75_02246BF0
	.public ov75_02246C18
	.public ov75_02246C68
	.public ov75_02246C8C
	.public ov75_02246CA0
	.public ov75_02246CB8
	.public ov75_02246CCC
	.public ov75_02246CD8
	.public ov75_02246CE0
	.public ov75_02246CE8
	.public ov75_02246CF0
	.public ov75_02246CF8
	.public ov75_02246D00
	.public ov75_02246D04
	.public ov75_02246EAC
	.public ov75_02246EDC
	.public ov75_02247234
	.public ov75_0224741C
	.public ov75_02247838
	.public ov75_02247854
	.public ov75_0224785C
	.public ov75_02247878
	.public ov75_02247A78
	.public ov75_02247D0C
	.public ov75_0224852C
	.public ov75_0224854C
	.public ov75_02248714
	.public ov75_022488AC
	.public ov75_022489F8
	.public ov75_02248C64
	.public ov75_0224921C
	.public ov75_02249258
	.public ov75_02249460
	.public ov75_022494A4
	.public ov75_02249758
	.public ov75_0224976C
	.public ov75_02248034
	.public ov75_022483EC

	thumb_func_start ov75_02247D24
ov75_02247D24: ; 0x02247D24
	push {r3, r4, r5, lr}
	sub sp, #0x10
	add r4, r0, #0
	add r0, #0xbc
	ldr r0, [r0]
	add r1, r0, #1
	add r0, r4, #0
	add r0, #0xbc
	str r1, [r0]
	add r0, r4, #0
	add r0, #0xbc
	ldr r0, [r0]
	cmp r0, #8
	beq _02247D42
	b _02248030
_02247D42:
	add r0, r4, #0
	add r0, #0xc0
	ldr r0, [r0]
	mov r1, #1
	add r2, r0, #0
	add r0, r4, #0
	eor r2, r1
	add r0, #0xc0
	str r2, [r0]
	add r0, r4, #0
	mov r2, #0
	add r0, #0xbc
	str r2, [r0]
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	add r3, r0, #6
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r3, r0
	bne _02247D70
	b _02247EAE
_02247D70:
	mov r0, #0x11
	str r0, [sp]
	str r1, [sp, #4]
	str r1, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #1
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #0x11
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #2
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #0x11
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #3
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r3, #0x11
	add r2, r4, #0
	str r3, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r5, [r2]
	mov r2, #0x14
	mul r2, r5
	add r2, r2, #4
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xb
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xc
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xd
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r0, #0x12
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xe
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	b _02247EC8
_02247EAE:
	mov r0, #0x11
	str r0, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r1, #3
	mov r3, #0xe
	bl FillBgTilemapRect
_02247EC8:
	add r0, r4, #0
	add r0, #0xac
	ldr r0, [r0]
	cmp r0, #0
	bne _02247ED4
	b _0224800E
_02247ED4:
	mov r1, #3
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #5
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #6
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, r2, #7
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r1, #3
	add r2, r4, #0
	str r1, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #8
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0xf
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xe
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x10
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0xf
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x11
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x10
	bl FillBgTilemapRect
	mov r0, #4
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	str r0, [sp, #8]
	mov r0, #9
	add r2, r4, #0
	str r0, [sp, #0xc]
	add r2, #0xc0
	ldr r3, [r2]
	mov r2, #0x14
	mul r2, r3
	add r2, #0x12
	lsl r2, r2, #0x10
	ldr r0, [r4, #4]
	mov r1, #3
	lsr r2, r2, #0x10
	mov r3, #0x11
	bl FillBgTilemapRect
	b _02248028
_0224800E:
	mov r1, #3
	str r1, [sp]
	mov r0, #4
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	mov r0, #9
	str r0, [sp, #0xc]
	ldr r0, [r4, #4]
	mov r2, #0
	mov r3, #0xe
	bl FillBgTilemapRect
_02248028:
	ldr r0, [r4, #4]
	mov r1, #3
	bl ScheduleBgTilemapBufferTransfer
_02248030:
	add sp, #0x10
	pop {r3, r4, r5, pc}
	thumb_func_end ov75_02247D24
