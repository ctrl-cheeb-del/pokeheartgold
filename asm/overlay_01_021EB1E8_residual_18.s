#include "constants/sndseq.h"
#include "constants/moves.h"
#include "constants/std_script.h"
#include "constants/species.h"
#include "constants/sprites.h"
#include "constants/maps.h"
#include "constants/mmodel.h"
#include "constants/items.h"
#include "msgdata/msg/msg_0096_D31R0201.h"
#include "msgdata/msg/msg_0066_D23R0102.h"
	.include "asm/macros.inc"
	.public WeatherManager_ChangeWeather
	.public WeatherManager_Delete
	.public WeatherManager_New
	.public WeatherManager_SetWeather
	.public _021EB208
	.public _021EB242
	.public _021EB24E
	.public _021EB270
	.public _021EB278
	.public _021EB28E
	.public _021EB2A0
	.public _021EB2B2
	.public _021EB2B4
	.public _021EB2C6
	.public _021EB2D2
	.public _021EB2DC
	.public _021EB2E6
	.public _021EB302
	.public _021EB30E
	.public _021EB314
	.public _021EB318
	.public _021EB336
	.public _021EB342
	.public _021EB354
	.public _021EB35C
	.public _021EB37A
	.public _021EB382
	.public _021EB394
	.public _021EB39C
	.public _021EB3B0
	.public _021EB3C2
	.public _021EB3D2
	.public _021EB3EE
	.public _021EB406
	.public _021EB410
	.public _021EB422
	.public _021EB42A
	.public _021EB43E
	.public _021EB450
	.public _021EB462
	.public _021EB46A
	.public _021EB488
	.public _021EB490
	.public _021EB4B2
	.public _021EB4EE
	.public _021EB564
	.public _021EB568
	.public _021EB574
	.public _021EB5AC
	.public _021EB60A
	.public _021EB614
	.public _021EB62E
	.public _021EB638
	.public _021EB644
	.public _021EB648
	.public _021EB684
	.public _021EB688
	.public _021EB69A
	.public _021EB6F6
	.public _021EB6FC
	.public _021EB710
	.public _021EB720
	.public _021EB736
	.public _021EB740
	.public _021EB74A
	.public _021EB758
	.public _021EB766
	.public _021EB786
	.public _021EB796
	.public _021EB7A0
	.public _021EB7A8
	.public _021EB7B2
	.public _021EB7BA
	.public _021EB7DA
	.public _021EB7FA
	.public _021EB800
	.public _021EB80C
	.public _021EB82C
	.public _021EB866
	.public _021EB8E8
	.public _021EB8F0
	.public _021EB90E
	.public _021EB930
	.public _021EB94A
	.public _021EB962
	.public _021EB97E
	.public _021EB988
	.public _021EB98A
	.public _021EB996
	.public _021EB9A0
	.public _021EB9A4
	.public _021EB9C8
	.public _021EB9E0
	.public _021EB9F4
	.public _021EBA00
	.public _021EBA04
	.public _021EBA1C
	.public _021EBA2A
	.public _021EBA40
	.public _021EBA64
	.public _021EBA6E
	.public _021EBA78
	.public _021EBA92
	.public _021EBAF8
	.public _021EBAFE
	.public _021EBB28
	.public _021EBB2C
	.public _021EBB30
	.public _021EBB34
	.public _021EBB38
	.public _021EBB3C
	.public _021EBB5E
	.public _021EBB64
	.public _021EBB8A
	.public _021EBB8C
	.public _021EBBCE
	.public _021EBBF6
	.public _021EBC10
	.public _021EBC1E
	.public _021EBC36
	.public _021EBC48
	.public _021EBC56
	.public _021EBC64
	.public _021EBC70
	.public _021EBC8C
	.public _021EBC90
	.public _021EBC94
	.public _021EBC98
	.public _021EBC9C
	.public _021EBCA0
	.public _021EBCD8
	.public _021EBCF2
	.public _021EBD06
	.public _021EBD08
	.public _021EBD0C
	.public _021EBD10
	.public _021EBD14
	.public _021EBD56
	.public _021EBD68
	.public _021EBD6C
	.public _021EBD8C
	.public _021EBD9E
	.public _021EBDAC
	.public _021EBDB4
	.public _021EBDC4
	.public _021EBDD2
	.public _021EBDE2
	.public _021EBDF0
	.public _021EBE00
	.public _021EBE0E
	.public _021EBE1E
	.public _021EBE36
	.public _021EBE46
	.public _021EBE48
	.public _021EBE5C
	.public _021EBE70
	.public _021EBEB4
	.public _021EBECE
	.public _021EBEE0
	.public _021EBEE8
	.public _021EBEEC
	.public _021EBF1A
	.public _021EBF20
	.public _021EBF4E
	.public _021EBF54
	.public _021EBF8C
	.public _021EBF90
	.public _021EBFC6
	.public _021EBFCC
	.public _021EC022
	.public _021EC024
	.public _021EC032
	.public _021EC04C
	.public _021EC060
	.public _021EC06C
	.public _021EC0B8
	.public _021EC0BC
	.public _021EC10C
	.public _021EC110
	.public _021EC14A
	.public _021EC1B4
	.public _021EC1B8
	.public _021EC1CC
	.public _021EC1D4
	.public _021EC1DC
	.public _021EC1F0
	.public _021EC208
	.public _021EC22A
	.public _021EC234
	.public _021EC250
	.public _021EC2D6
	.public _021EC2E2
	.public _021EC2F2
	.public _021EC2FC
	.public _021EC398
	.public _021EC3A0
	.public _021EC3C8
	.public _021EC3F0
	.public _021EC416
	.public _021EC43E
	.public _021EC450
	.public _021EC45C
	.public _021EC460
	.public _021EC464
	.public _021EC468
	.public _021EC46C
	.public _021EC494
	.public _021EC4A4
	.public _021EC4C6
	.public _021EC4EC
	.public _021EC4F4
	.public _021EC4FE
	.public _021EC54C
	.public _021EC552
	.public _021EC554
	.public _021EC564
	.public _021EC56C
	.public _021EC572
	.public _021EC57E
	.public _021EC584
	.public _021EC586
	.public _021EC596
	.public _021EC59E
	.public _021EC5A4
	.public _021EC5D2
	.public _021EC5F8
	.public _021EC630
	.public _021EC64C
	.public _021EC666
	.public _021EC674
	.public _021EC77A
	.public _021EC78C
	.public _021EC7A4
	.public _021EC7C4
	.public _021EC7FA
	.public _021EC804
	.public _021EC824
	.public _021EC83A
	.public _021EC848
	.public _021EC856
	.public _021EC88A
	.public _021EC896
	.public _021EC8A6
	.public _021EC8C6
	.public _021EC8D2
	.public _021EC8DC
	.public _021EC8EC
	.public _021EC90E
	.public _021EC91A
	.public _021EC920
	.public _021EC926
	.public _021EC92C
	.public _021EC93A
	.public _021EC940
	.public _021EC946
	.public _021EC948
	.public _021EC96C
	.public _021EC978
	.public _021EC9E2
	.public _021ECA02
	.public _021ECA1A
	.public _021ECA1C
	.public _021ECA24
	.public _021ECA66
	.public _021ECA96
	.public _021ECAB2
	.public _021ECAE0
	.public _021ECAF4
	.public _021ECB14
	.public _021ECB26
	.public _021ECB28
	.public _021ECB42
	.public _021ECB5A
	.public _021ECB60
	.public _021ECB86
	.public _021ECB8C
	.public _021ECB90
	.public _021ECB94
	.public _021ECB98
	.public _021ECB9C
	.public _021ECBA0
	.public _021ECBA4
	.public _021ECBA8
	.public _021ECBAC
	.public _021ECBB0
	.public _021ECBC6
	.public _021ECC0C
	.public _021ECC2C
	.public _021ECC62
	.public _021ECC68
	.public _021ECC6C
	.public _021ECC92
	.public _021ECC96
	.public _021ECCC8
	.public _021ECCD8
	.public _021ECCEA
	.public _021ECCFC
	.public _021ECD02
	.public _021ECD28
	.public _021ECD34
	.public _021ECD94
	.public _021ECDB4
	.public _021ECDCC
	.public _021ECDCE
	.public _021ECDD6
	.public _021ECE1C
	.public _021ECE3E
	.public _021ECE5A
	.public _021ECE88
	.public _021ECE96
	.public _021ECEB6
	.public _021ECEC8
	.public _021ECECA
	.public _021ECEE4
	.public _021ECEFC
	.public _021ECF02
	.public _021ECF28
	.public _021ECF2C
	.public _021ECF30
	.public _021ECF34
	.public _021ECF38
	.public _021ECF3C
	.public _021ECF40
	.public _021ECF44
	.public _021ECF48
	.public _021ECF90
	.public _021ECFBE
	.public _021ED060
	.public _021ED064
	.public _021ED068
	.public _021ED06C
	.public _021ED09A
	.public _021ED0BE
	.public _021ED0DA
	.public _021ED0E6
	.public _021ED110
	.public _021ED11C
	.public _021ED172
	.public _021ED192
	.public _021ED1AA
	.public _021ED1AC
	.public _021ED1B4
	.public _021ED1F6
	.public _021ED212
	.public _021ED22E
	.public _021ED25C
	.public _021ED26A
	.public _021ED28A
	.public _021ED2B4
	.public _021ED2CC
	.public _021ED2D2
	.public _021ED2F8
	.public _021ED2FC
	.public _021ED300
	.public _021ED304
	.public _021ED308
	.public _021ED30C
	.public _021ED310
	.public _021ED314
	.public _021ED318
	.public _021ED330
	.public _021ED33E
	.public _021ED370
	.public _021ED374
	.public _021ED406
	.public _021ED412
	.public _021ED424
	.public _021ED42E
	.public _021ED448
	.public _021ED46E
	.public _021ED492
	.public _021ED49E
	.public _021ED4CE
	.public _021ED4E8
	.public _021ED50E
	.public _021ED518
	.public _021ED532
	.public _021ED53C
	.public _021ED54C
	.public _021ED54E
	.public _021ED55C
	.public _021ED574
	.public _021ED57A
	.public _021ED580
	.public _021ED59A
	.public _021ED5A6
	.public _021ED5B2
	.public _021ED602
	.public _021ED630
	.public _021ED656
	.public _021ED670
	.public _021ED68E
	.public _021ED6A4
	.public _021ED6B8
	.public _021ED6BA
	.public _021ED6DE
	.public _021ED6F6
	.public _021ED6FC
	.public _021ED700
	.public _021ED704
	.public _021ED708
	.public _021ED70C
	.public _021ED72E
	.public _021ED73A
	.public _021ED746
	.public _021ED77A
	.public _021ED79E
	.public _021ED7A8
	.public _021ED7DC
	.public _021ED800
	.public _021ED81A
	.public _021ED82E
	.public _021ED836
	.public _021ED85A
	.public _021ED884
	.public _021ED898
	.public _021ED8F4
	.public _021ED8FA
	.public _021ED900
	.public _021ED904
	.public _021ED908
	.public _021ED90C
	.public _021ED910
	.public _021ED914
	.public _021ED918
	.public _021ED91C
	.public _021ED920
	.public _021ED94C
	.public _021ED958
	.public _021ED98C
	.public _021ED9B2
	.public _021ED9BC
	.public _021ED9F0
	.public _021EDA16
	.public _021EDA2A
	.public _021EDA34
	.public _021EDA3A
	.public _021EDA40
	.public _021EDA44
	.public _021EDA48
	.public _021EDA4C
	.public _021EDA70
	.public _021EDA74
	.public _021EDA78
	.public _021EDAA4
	.public _021EDAA8
	.public _021EDAAC
	.public _021EDAB0
	.public _021EDAC6
	.public _021EDADC
	.public _021EDAF8
	.public ov01_021EB1E8
	.public ov01_021EB31C
	.public ov01_021EB320
	.public ov01_021EB3F0
	.public ov01_021EB4B4
	.public ov01_021EB4B8
	.public ov01_021EB56C
	.public ov01_021EB578
	.public ov01_021EB5A4
	.public ov01_021EB5F4
	.public ov01_021EB64C
	.public ov01_021EB68C
	.public ov01_021EB700
	.public ov01_021EB804
	.public ov01_021EB818
	.public ov01_021EB830
	.public ov01_021EB840
	.public ov01_021EB86C
	.public ov01_021EB898
	.public ov01_021EB968
	.public ov01_021EB9A8
	.public ov01_021EBA08
	.public ov01_021EBA44
	.public ov01_021EBB40
	.public ov01_021EBB68
	.public ov01_021EBB90
	.public ov01_021EBCA4
	.public ov01_021EBD18
	.public ov01_021EBD34
	.public ov01_021EBD70
	.public ov01_021EBE4C
	.public ov01_021EBEB8
	.public ov01_021EBEF0
	.public ov01_021EBF24
	.public ov01_021EBF58
	.public ov01_021EBF94
	.public ov01_021EBFD0
	.public ov01_021EC028
	.public ov01_021EC058
	.public ov01_021EC078
	.public ov01_021EC0C0
	.public ov01_021EC114
	.public ov01_021EC1BC
	.public ov01_021EC1E4
	.public ov01_021EC1F4
	.public ov01_021EC240
	.public ov01_021EC29C
	.public ov01_021EC2CC
	.public ov01_021EC2E4
	.public ov01_021EC300
	.public ov01_021EC304
	.public ov01_021EC31C
	.public ov01_021EC470
	.public ov01_021EC4A8
	.public ov01_021EC504
	.public ov01_021EC52C
	.public ov01_021EC538
	.public ov01_021EC5FC
	.public ov01_021EC650
	.public ov01_021EC678
	.public ov01_021EC6A4
	.public ov01_021EC728
	.public ov01_021EC774
	.public ov01_021EC790
	.public ov01_021EC7AC
	.public ov01_021EC7C8
	.public ov01_021EC7E8
	.public ov01_021EC828
	.public ov01_021EC85C
	.public ov01_021EC8D8
	.public ov01_021EC8F8
	.public ov01_021EC94C
	.public ov01_021ECBB4
	.public ov01_021ECC70
	.public ov01_021ECD08
	.public ov01_021ECF4C
	.public ov01_021ED070
	.public ov01_021ED0F0
	.public ov01_021ED31C
	.public ov01_021ED44C
	.public ov01_021ED474
	.public ov01_021ED584
	.public ov01_021ED710
	.public ov01_021ED924
	.public ov01_021EDA50
	.public ov01_021EDA7C
	.public ov01_021EDAB4
	.public ov01_021EDAE0
	.public ov01_0220673C
	.public ov01_0220674C
	.public ov01_0220675C
	.public ov01_022098B0
	.include "overlay_01_021EB1E8.inc"
	.include "global.inc"

	.text
	.public WeatherManager_ChangeWeather
	.public WeatherManager_Delete
	.public WeatherManager_New
	.public WeatherManager_SetWeather
	.public ov01_021EB1E8
	.public ov01_021EB31C
	.public ov01_021EB4B4
	.public ov01_021EB56C
	.public ov01_021EB578
	.public ov01_021EB5A4
	.public ov01_021EB64C
	.public ov01_021EB804
	.public ov01_021EB818
	.public ov01_021EB830
	.public ov01_021EB840
	.public ov01_021EB86C
	.public ov01_021EB968
	.public ov01_021EBA08
	.public ov01_021EBB40
	.public ov01_021EBB68
	.public ov01_021EBD18
	.public ov01_021EBD34
	.public ov01_021EBEB8
	.public ov01_021EBEF0
	.public ov01_021EBF24
	.public ov01_021EBF58
	.public ov01_021EBF94
	.public ov01_021EBFD0
	.public ov01_021EC028
	.public ov01_021EC058
	.public ov01_021EC1BC
	.public ov01_021EC1E4
	.public ov01_021EC1F4
	.public ov01_021EC29C
	.public ov01_021EC2CC
	.public ov01_021EC2E4
	.public ov01_021EC300
	.public ov01_021EC304
	.public ov01_021EC470
	.public ov01_021EC504
	.public ov01_021EC52C
	.public ov01_021EC650
	.public ov01_021EC678
	.public ov01_021EC728
	.public ov01_021EC774
	.public ov01_021EC790
	.public ov01_021EC7AC
	.public ov01_021EC7C8
	.public ov01_021EC7E8
	.public ov01_021EC828
	.public ov01_021EC8D8
	.public ov01_021EC8F8
	.public ov01_021ED44C
	.public ov01_021EDA50
	.public ov01_021EDA7C
	.public ov01_021EDAB4
	.public ov01_021EDAE0

	thumb_func_start ov01_021ED474
ov01_021ED474: ; 0x021ED474
	push {r4, r5, r6, lr}
	sub sp, #0x10
	add r6, r2, #0
	ldr r2, _021ED580 ; =0x00000F62
	add r4, r0, #0
	ldrh r0, [r4, r2]
	add r5, r1, #0
	cmp r0, #5
	bhi _021ED57A
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_021ED492: ; jump table
	.short _021ED49E - _021ED492 - 2 ; case 0
	.short _021ED4CE - _021ED492 - 2 ; case 1
	.short _021ED4E8 - _021ED492 - 2 ; case 2
	.short _021ED518 - _021ED492 - 2 ; case 3
	.short _021ED53C - _021ED492 - 2 ; case 4
	.short _021ED55C - _021ED492 - 2 ; case 5
_021ED49E:
	str r3, [sp]
	add r0, sp, #0x10
	ldrh r0, [r0, #0x10]
	add r5, #0x30
	str r0, [sp, #4]
	ldr r0, [sp, #0x24]
	str r0, [sp, #8]
	add r0, r2, #2
	ldrh r0, [r4, r0]
	mov r2, #0x41
	lsl r2, r2, #2
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r3, r6, #0
	ldr r2, [r2, #0x4c]
	bl ov01_021EC5FC
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #1
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED4CE:
	add r2, r2, #2
	ldrh r2, [r4, r2]
	add r5, #0x30
	add r0, r5, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED57A
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED4E8:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED50E
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	add r2, r3, #0
	ldr r0, [r0, #0x4c]
	add r3, sp, #0x10
	str r0, [r5]
	ldrh r3, [r3, #0x10]
	add r1, r6, #0
	bl ov01_021EC678
	add r0, r5, #0
	bl ov01_021EC7C8
_021ED50E:
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED518:
	add r0, r2, #4
	ldrh r0, [r4, r0]
	cmp r0, #5
	bne _021ED57A
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED532
	ldr r1, [sp, #0x28]
	add r0, r5, #0
	mov r2, #0
	bl ov01_021EC790
_021ED532:
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #4
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED53C:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED54C
	add r0, r5, #0
	bl ov01_021EC7AC
	b _021ED54E
_021ED54C:
	mov r0, #1
_021ED54E:
	cmp r0, #1
	bne _021ED57A
	ldr r0, _021ED580 ; =0x00000F62
	mov r1, #5
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r4, r5, r6, pc}
_021ED55C:
	add r0, r2, #2
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED574
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED574:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ED57A:
	add sp, #0x10
	pop {r4, r5, r6, pc}
	nop
_021ED580: .word 0x00000F62
	thumb_func_end ov01_021ED474


	thumb_func_start ov01_021ED584
ov01_021ED584: ; 0x021ED584
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	ldr r0, _021ED700 ; =0x00000F58
	add r4, r1, #0
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r4, r1]
	ldr r5, [r4, r0]
	cmp r1, #5
	bls _021ED59A
	b _021ED6FC
_021ED59A:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED5A6: ; jump table
	.short _021ED5B2 - _021ED5A6 - 2 ; case 0
	.short _021ED602 - _021ED5A6 - 2 ; case 1
	.short _021ED630 - _021ED5A6 - 2 ; case 2
	.short _021ED670 - _021ED5A6 - 2 ; case 3
	.short _021ED6A4 - _021ED5A6 - 2 ; case 4
	.short _021ED6DE - _021ED5A6 - 2 ; case 5
_021ED5B2:
	ldr r1, _021ED704 ; =0x00007555
	mov r2, #0x41
	str r1, [sp]
	ldr r1, _021ED708 ; =0x00007FFF
	add r0, #0xc
	str r1, [sp, #4]
	mov r1, #1
	str r1, [sp, #8]
	ldrh r0, [r4, r0]
	add r1, r5, #0
	lsl r2, r2, #2
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r0, #0x44
	ldr r2, [r2, #0x4c]
	add r1, #0x14
	mov r3, #6
	bl ov01_021EC5FC
	add r0, r5, #0
	mov r1, #0
	mov r2, #9
	mov r3, #0x1e
	bl ov01_021EB830
	mov r0, #0
	mov r1, #0x10
	bl ov01_021EB818
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #1
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED602:
	add r0, r5, #0
	add r0, #0x14
	bl ov01_021EC7AC
	add r6, r0, #0
	add r0, r5, #0
	bl ov01_021EB840
	add r7, r0, #0
	ldr r0, [r5]
	mov r1, #0x10
	sub r1, r1, r0
	bl ov01_021EB818
	cmp r6, #1
	bne _021ED6FC
	cmp r7, #1
	bne _021ED6FC
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED630:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED656
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ED704 ; =0x00007555
	ldr r0, [r0, #0x4c]
	ldr r3, _021ED708 ; =0x00007FFF
	mov r1, #6
	str r0, [r5, #0x14]
	bl ov01_021EC678
	add r5, #0x14
	add r0, r5, #0
	bl ov01_021EC7C8
_021ED656:
	mov r0, #9
	mov r1, #7
	bl ov01_021EB818
	mov r0, #4
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #3
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED670:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r4, r1]
	cmp r1, #5
	bne _021ED6FC
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED68E
	add r0, r5, #0
	add r0, #0x14
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ED68E:
	add r0, r5, #0
	mov r1, #9
	mov r2, #0
	mov r3, #0x1e
	bl ov01_021EB830
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #4
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED6A4:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED6B8
	add r0, r5, #0
	add r0, #0x14
	bl ov01_021EC7AC
	add r6, r0, #0
	b _021ED6BA
_021ED6B8:
	mov r6, #1
_021ED6BA:
	add r0, r5, #0
	bl ov01_021EB840
	add r7, r0, #0
	ldr r0, [r5]
	mov r1, #0x10
	sub r1, r1, r0
	bl ov01_021EB818
	cmp r6, #1
	bne _021ED6FC
	cmp r7, #1
	bne _021ED6FC
	ldr r0, _021ED70C ; =0x00000F62
	mov r1, #5
	add sp, #0x10
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, r7, pc}
_021ED6DE:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ED6F6
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5, #0x14]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED6F6:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ED6FC:
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021ED700: .word 0x00000F58
_021ED704: .word 0x00007555
_021ED708: .word 0x00007FFF
_021ED70C: .word 0x00000F62
	thumb_func_end ov01_021ED584


	thumb_func_start ov01_021ED710
ov01_021ED710: ; 0x021ED710
	push {r3, r4, r5, r6, lr}
	sub sp, #0x4c
	add r6, r1, #0
	mov r0, #0x41
	ldr r1, [r6]
	lsl r0, r0, #2
	ldr r5, [r1, r0]
	ldr r0, _021ED900 ; =0x00000F58
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r6, r1]
	ldr r4, [r6, r0]
	cmp r1, #5
	bls _021ED72E
	b _021ED8FA
_021ED72E:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED73A: ; jump table
	.short _021ED746 - _021ED73A - 2 ; case 0
	.short _021ED79E - _021ED73A - 2 ; case 1
	.short _021ED7A8 - _021ED73A - 2 ; case 2
	.short _021ED800 - _021ED73A - 2 ; case 3
	.short _021ED81A - _021ED73A - 2 ; case 4
	.short _021ED8F4 - _021ED73A - 2 ; case 5
_021ED746:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021ED904 ; =0x0000062C
	mov r3, #0
	str r0, [r4, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r5, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r5, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0x2c
	sub r0, r1, #1
_021ED77A:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED77A
	ldr r0, [r5, #0x4c]
	add r1, sp, #0x2c
	bl ov01_021EA8C4
	mov r0, #0x63
	mov r1, #0
	lsl r0, r0, #4
	strh r1, [r4, r0]
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #1
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED79E:
	mov r1, #3
	add r0, #0xa
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED7A8:
	ldr r0, [r5, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021ED904 ; =0x0000062C
	mov r3, #0
	str r0, [r4, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r5, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r5, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0xc
	sub r0, r1, #1
_021ED7DC:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED7DC
	ldr r0, [r5, #0x4c]
	add r1, sp, #0xc
	bl ov01_021EA8C4
	mov r0, #0x63
	mov r1, #0
	lsl r0, r0, #4
	strh r1, [r4, r0]
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #3
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED800:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r6, r1]
	cmp r1, #5
	bne _021ED8FA
	ldr r1, _021ED90C ; =0x00000632
	mov r2, #0
	strh r2, [r4, r1]
	mov r1, #4
	add r0, #0xa
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED81A:
	ldr r0, _021ED90C ; =0x00000632
	ldrh r1, [r4, r0]
	cmp r1, #3
	bhi _021ED8FA
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED82E: ; jump table
	.short _021ED836 - _021ED82E - 2 ; case 0
	.short _021ED85A - _021ED82E - 2 ; case 1
	.short _021ED884 - _021ED82E - 2 ; case 2
	.short _021ED898 - _021ED82E - 2 ; case 3
_021ED836:
	mov r0, #6
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #4
	mov r1, #0
	str r0, [sp, #8]
	ldr r3, _021ED910 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED85A:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021ED8FA
	mov r0, #6
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #4
	str r0, [sp, #8]
	ldr r3, _021ED910 ; =0x00007FFF
	mov r0, #3
	add r2, r1, #0
	bl BeginNormalPaletteFade
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED884:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _021ED8FA
	ldr r0, _021ED90C ; =0x00000632
	add sp, #0x4c
	ldrh r1, [r4, r0]
	add r1, r1, #1
	strh r1, [r4, r0]
	pop {r3, r4, r5, r6, pc}
_021ED898:
	sub r1, r0, #2
	ldrh r1, [r4, r1]
	add r2, r1, #1
	sub r1, r0, #2
	strh r2, [r4, r1]
	sub r0, r0, #2
	ldrh r0, [r4, r0]
	bl _dfltu
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021ED914 ; =0x40080000
	mov r0, #0
	bl _dmul
	ldr r3, _021ED918 ; =0x40380000
	mov r2, #0
	bl _ddiv
	add r3, r1, #0
	add r2, r0, #0
	ldr r1, _021ED91C ; =0x3FF00000
	mov r0, #0
	bl _dadd
	bl _d2f
	add r5, r0, #0
	ldr r0, _021ED904 ; =0x0000062C
	add r1, r5, #0
	ldr r0, [r4, r0]
	bl ov01_02203F2C
	add r0, r5, #0
	bl _f2d
	ldr r3, _021ED920 ; =0x40100000
	mov r2, #0
	bl _dgeq
	blo _021ED8FA
	ldr r0, _021ED908 ; =0x00000F62
	mov r1, #5
	add sp, #0x4c
	strh r1, [r6, r0]
	pop {r3, r4, r5, r6, pc}
_021ED8F4:
	ldr r0, [r6, #4]
	bl ov01_021EBCA4
_021ED8FA:
	add sp, #0x4c
	pop {r3, r4, r5, r6, pc}
	nop
_021ED900: .word 0x00000F58
_021ED904: .word 0x0000062C
_021ED908: .word 0x00000F62
_021ED90C: .word 0x00000632
_021ED910: .word 0x00007FFF
_021ED914: .word 0x40080000
_021ED918: .word 0x40380000
_021ED91C: .word 0x3FF00000
_021ED920: .word 0x40100000
	thumb_func_end ov01_021ED710


	thumb_func_start ov01_021ED924
ov01_021ED924: ; 0x021ED924
	push {r4, r5, r6, lr}
	sub sp, #0x48
	add r5, r1, #0
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r4, [r1, r0]
	ldr r0, _021EDA40 ; =0x00000F58
	add r1, r0, #0
	add r1, #0xa
	ldrh r1, [r5, r1]
	ldr r6, [r5, r0]
	cmp r1, #5
	bhi _021EDA3A
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_021ED94C: ; jump table
	.short _021ED958 - _021ED94C - 2 ; case 0
	.short _021ED9B2 - _021ED94C - 2 ; case 1
	.short _021ED9BC - _021ED94C - 2 ; case 2
	.short _021EDA16 - _021ED94C - 2 ; case 3
	.short _021EDA2A - _021ED94C - 2 ; case 4
	.short _021EDA34 - _021ED94C - 2 ; case 5
_021ED958:
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021EDA44 ; =0x0000062C
	mov r3, #0
	str r0, [r6, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r4, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r4, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #0x28
	sub r0, r1, #1
_021ED98C:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED98C
	ldr r0, [r4, #0x4c]
	add r1, sp, #0x28
	bl ov01_021EA8C4
	ldr r0, _021EDA44 ; =0x0000062C
	ldr r1, _021EDA48 ; =0x40800000
	ldr r0, [r6, r0]
	bl ov01_02203F2C
	ldr r0, _021EDA4C ; =0x00000F62
	mov r1, #1
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021ED9B2:
	mov r1, #3
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021ED9BC:
	ldr r0, [r4, #0x40]
	bl PlayerAvatar_GetMapObject
	bl ov01_02203EA0
	ldr r1, _021EDA44 ; =0x0000062C
	mov r3, #0
	str r0, [r6, r1]
	mov r0, #0xa
	str r0, [sp]
	str r3, [sp, #4]
	ldr r0, [r4, #0x4c]
	sub r1, r3, #1
	mov r2, #1
	bl ov01_021EA864
	mov r1, #0
	mov r2, #0
	ldr r0, [r4, #0x4c]
	mvn r1, r1
	add r3, r2, #0
	bl ov01_021EA89C
	mov r1, #0
	add r2, sp, #8
	sub r0, r1, #1
_021ED9F0:
	add r1, r1, #1
	strb r0, [r2]
	add r2, r2, #1
	cmp r1, #0x20
	blt _021ED9F0
	ldr r0, [r4, #0x4c]
	add r1, sp, #8
	bl ov01_021EA8C4
	ldr r0, _021EDA44 ; =0x0000062C
	ldr r1, _021EDA48 ; =0x40800000
	ldr r0, [r6, r0]
	bl ov01_02203F2C
	ldr r0, _021EDA4C ; =0x00000F62
	mov r1, #3
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA16:
	add r1, r0, #0
	add r1, #0xe
	ldrh r1, [r5, r1]
	cmp r1, #5
	bne _021EDA3A
	mov r1, #4
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA2A:
	mov r1, #5
	add r0, #0xa
	add sp, #0x48
	strh r1, [r5, r0]
	pop {r4, r5, r6, pc}
_021EDA34:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021EDA3A:
	add sp, #0x48
	pop {r4, r5, r6, pc}
	nop
_021EDA40: .word 0x00000F58
_021EDA44: .word 0x0000062C
_021EDA48: .word 0x40800000
_021EDA4C: .word 0x00000F62
	thumb_func_end ov01_021ED924
