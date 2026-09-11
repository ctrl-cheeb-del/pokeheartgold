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

	thumb_func_start ov01_021EC94C
ov01_021EC94C: ; 0x021EC94C
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ECB8C ; =0x00000F58
	add r4, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r4, r2]
	ldr r5, [r4, r0]
	cmp r2, #5
	bhi _021ECA1A
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021EC96C: ; jump table
	.short _021EC978 - _021EC96C - 2 ; case 0
	.short _021EC9E2 - _021EC96C - 2 ; case 1
	.short _021ECA24 - _021EC96C - 2 ; case 2
	.short _021ECA96 - _021EC96C - 2 ; case 3
	.short _021ECAF4 - _021EC96C - 2 ; case 4
	.short _021ECB42 - _021EC96C - 2 ; case 5
_021EC978:
	mov r0, #0x14
	str r0, [sp]
	mov r2, #1
	str r2, [sp, #4]
	sub r0, r2, #2
	str r0, [sp, #8]
	str r2, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _021ECB90 ; =ov01_021ECBB4
	mov r3, #8
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl ov01_021EC504
	ldr r0, _021ECB94 ; =0x0000726F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ECB98 ; =0x00006B5A
	lsl r2, r2, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021ECB9C ; =0x00000F64
	add r1, r5, #0
	ldrh r0, [r4, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r4]
	add r0, r5, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	mov r0, #0
	add r5, #0xb4
	str r0, [r5]
	ldr r0, _021ECBA0 ; =ov01_021EDA7C
	add r1, r4, #0
	mov r2, #0x64
	bl SysTask_CreateOnMainQueue
	ldr r1, _021ECBA4 ; =0x00000F6C
	mov r2, #0x1e
	str r0, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	mov r0, #1
	sub r1, #0xa
	strh r0, [r4, r1]
	b _021ECB60
_021EC9E2:
	add r0, r5, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECA02
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r5, #0xb4
	sub r0, r0, #1
	str r0, [r5]
	b _021ECB60
_021ECA02:
	ldr r2, _021ECB9C ; =0x00000F64
	add r0, r5, #0
	ldrh r2, [r4, r2]
	add r5, #0x1c
	add r0, #0x4c
	add r1, r5, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ECA1A
	cmp r6, #3
	beq _021ECA1C
_021ECA1A:
	b _021ECB60
_021ECA1C:
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #3
	strh r1, [r4, r0]
	b _021ECB60
_021ECA24:
	mov r2, #0x14
	mov r3, #1
	str r2, [sp]
	str r3, [sp, #4]
	sub r0, r3, #2
	str r0, [sp, #8]
	str r3, [sp, #0xc]
	mov r0, #2
	str r0, [sp, #0x10]
	ldr r0, _021ECB90 ; =ov01_021ECBB4
	str r0, [sp, #0x14]
	add r0, r5, #0
	bl ov01_021EC504
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECA66
	mov r0, #0x41
	ldr r1, [r4]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ECB94 ; =0x0000726F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ECB98 ; =0x00006B5A
	mov r1, #3
	str r0, [r5, #0x1c]
	bl ov01_021EC678
	add r5, #0x1c
	add r0, r5, #0
	bl ov01_021EC7C8
_021ECA66:
	mov r0, #1
	str r0, [sp]
	ldr r0, _021ECBAC ; =ov01_021ECC70
	ldr r1, _021ECB90 ; =ov01_021ECBB4
	str r0, [sp, #4]
	add r0, r4, #0
	mov r2, #0x14
	mov r3, #0xa
	bl ov01_021EC85C
	ldr r0, _021ECBA0 ; =ov01_021EDA7C
	add r1, r4, #0
	mov r2, #0x64
	bl SysTask_CreateOnMainQueue
	ldr r1, _021ECBA4 ; =0x00000F6C
	mov r2, #0x1e
	str r0, [r4, r1]
	sub r0, r1, #4
	str r2, [r4, r0]
	mov r0, #3
	sub r1, #0xa
	strh r0, [r4, r1]
	b _021ECB60
_021ECA96:
	mov r0, #6
	ldrsh r1, [r5, r0]
	sub r0, r1, #1
	strh r0, [r5, #6]
	cmp r1, #0
	bgt _021ECAB2
	mov r1, #4
	ldrsh r1, [r5, r1]
	add r0, r4, #0
	bl ov01_021ECBB4
	mov r0, #8
	ldrsh r0, [r5, r0]
	strh r0, [r5, #6]
_021ECAB2:
	ldr r0, _021ECBB0 ; =0x00000F66
	ldrh r0, [r4, r0]
	cmp r0, #5
	bne _021ECB60
	mov r0, #1
	mvn r0, r0
	str r0, [sp]
	add r0, r5, #0
	mov r1, #0
	mov r2, #8
	mov r3, #1
	bl ov01_021EC52C
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECAE0
	add r0, r5, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ECAE0:
	mov r0, #0
	add r5, #0xb4
	str r0, [r5]
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #4
	strh r1, [r4, r0]
	add r0, r4, #0
	bl ov01_021EDAE0
	b _021ECB60
_021ECAF4:
	add r0, r5, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECB14
	add r0, r5, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r5, #0xb4
	sub r0, r0, #1
	str r0, [r5]
	b _021ECB60
_021ECB14:
	ldr r0, _021ECB9C ; =0x00000F64
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECB26
	add r5, #0x1c
	add r0, r5, #0
	bl ov01_021EC7AC
	b _021ECB28
_021ECB26:
	mov r0, #1
_021ECB28:
	cmp r0, #1
	bne _021ECB60
	cmp r6, #3
	bne _021ECB60
	add r0, r4, #0
	ldr r1, [r4, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ECB60
	ldr r0, _021ECBA8 ; =0x00000F62
	mov r1, #5
	strh r1, [r4, r0]
	b _021ECB60
_021ECB42:
	add r0, #0xc
	ldrh r0, [r4, r0]
	cmp r0, #0
	beq _021ECB5A
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r5, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ECB5A:
	ldr r0, [r4, #4]
	bl ov01_021EBCA4
_021ECB60:
	ldr r0, _021ECBA8 ; =0x00000F62
	ldrh r0, [r4, r0]
	cmp r0, #5
	beq _021ECB86
	cmp r0, #0
	beq _021ECB86
	add r0, r4, #0
	ldr r1, _021ECBAC ; =ov01_021ECC70
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r4, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r4, #0
	bl ov01_021EC300
_021ECB86:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	nop
_021ECB8C: .word 0x00000F58
_021ECB90: .word ov01_021ECBB4
_021ECB94: .word 0x0000726F
_021ECB98: .word 0x00006B5A
_021ECB9C: .word 0x00000F64
_021ECBA0: .word ov01_021EDA7C
_021ECBA4: .word 0x00000F6C
_021ECBA8: .word 0x00000F62
_021ECBAC: .word ov01_021ECC70
_021ECBB0: .word 0x00000F66
	thumb_func_end ov01_021EC94C


	thumb_func_start ov01_021ECBB4
ov01_021ECBB4: ; 0x021ECBB4
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x18
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #8]
	add r0, r1, #0
	str r1, [sp, #4]
	cmp r0, #0
	ble _021ECC62
_021ECBC6:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r6, r0, #0
	beq _021ECC62
	ldr r4, [r6, #8]
	bl MTRandom
	mov r1, #0
	str r1, [r4]
	mov r1, #3
	add r7, r0, #0
	bl _u32_div_f
	add r5, r1, #0
	lsl r1, r5, #0x10
	ldr r0, [r6, #4]
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	add r0, r7, #0
	mov r1, #0x14
	bl _u32_div_f
	add r2, r5, #1
	mov r0, #0xa
	mul r0, r2
	add r0, r1, r0
	str r0, [r4, #8]
	cmp r5, #2
	bne _021ECC0C
	ldr r0, [r4, #8]
	add r0, #0xa
	str r0, [r4, #8]
_021ECC0C:
	add r0, r1, #0
	mov r1, #4
	mvn r1, r1
	bl _s32_div_f
	mov r1, #4
	add r2, r5, #1
	mvn r1, r1
	mul r1, r2
	add r0, r0, r1
	str r0, [r4, #0x10]
	cmp r5, #2
	bne _021ECC2C
	ldr r0, [r4, #0x10]
	sub r0, r0, #5
	str r0, [r4, #0x10]
_021ECC2C:
	mov r0, #0
	str r0, [r4, #0xc]
	add r0, r5, #1
	str r0, [r4, #4]
	ldr r1, _021ECC68 ; =0x0000010E
	add r0, r7, #0
	bl _u32_div_f
	mov r0, #0xf
	mul r0, r5
	add r0, r1, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0xc]
	ldr r0, _021ECC6C ; =0xFFFA0000
	add r1, sp, #0xc
	str r0, [sp, #0x10]
	mov r0, #0
	str r0, [sp, #0x14]
	ldr r0, [r6, #4]
	bl ov01_021EB5F4
	ldr r0, [sp, #8]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #8]
	cmp r1, r0
	blt _021ECBC6
_021ECC62:
	add sp, #0x18
	pop {r3, r4, r5, r6, r7, pc}
	nop
_021ECC68: .word 0x0000010E
_021ECC6C: .word 0xFFFA0000
	thumb_func_end ov01_021ECBB4


	thumb_func_start ov01_021ECC70
ov01_021ECC70: ; 0x021ECC70
	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	add r6, r0, #0
	ldr r5, [r6, #8]
	add r0, sp, #0
	add r1, r6, #0
	bl ov01_021EC304
	ldr r0, [r5, #0xc]
	cmp r0, #0
	beq _021ECC92
	cmp r0, #1
	beq _021ECCEA
	cmp r0, #2
	beq _021ECCFC
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_021ECC92:
	mov r4, #0
	mov r7, #2
_021ECC96:
	ldr r0, [r5, #0x10]
	ldr r1, [sp]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp]
	ldr r0, [r5, #8]
	ldr r1, [sp, #4]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #4]
	ldr r1, [r5]
	add r0, r1, #1
	str r0, [r5]
	ldr r0, [r5, #4]
	cmp r1, r0
	ble _021ECCD8
	bl MTRandom
	mov r1, #0xa
	bl _u32_div_f
	cmp r1, #7
	bhs _021ECCC8
	str r7, [r5, #0xc]
	b _021ECCD8
_021ECCC8:
	mov r0, #1
	str r0, [r5, #0xc]
	mov r0, #4
	str r0, [r5]
	ldr r0, [r6, #4]
	mov r1, #3
	bl Sprite_SetAnimationFrame
_021ECCD8:
	add r4, r4, #1
	cmp r4, #2
	blt _021ECC96
	ldr r0, [r6, #4]
	add r1, sp, #0
	bl ov01_021EB5F4
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
_021ECCEA:
	ldr r1, [r5]
	sub r0, r1, #1
	str r0, [r5]
	cmp r1, #0
	bgt _021ECD02
	mov r0, #2
	add sp, #0xc
	str r0, [r5, #0xc]
	pop {r4, r5, r6, r7, pc}
_021ECCFC:
	add r0, r6, #0
	bl ov01_021EC29C
_021ECD02:
	add sp, #0xc
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov01_021ECC70


	thumb_func_start ov01_021ECD08
ov01_021ECD08: ; 0x021ECD08
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ECF2C ; =0x00000F58
	add r5, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r5, r2]
	ldr r4, [r5, r0]
	cmp r2, #5
	bhi _021ECDCC
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021ECD28: ; jump table
	.short _021ECD34 - _021ECD28 - 2 ; case 0
	.short _021ECD94 - _021ECD28 - 2 ; case 1
	.short _021ECDD6 - _021ECD28 - 2 ; case 2
	.short _021ECE3E - _021ECD28 - 2 ; case 3
	.short _021ECE96 - _021ECD28 - 2 ; case 4
	.short _021ECEE4 - _021ECD28 - 2 ; case 5
_021ECD34:
	mov r0, #6
	str r0, [sp]
	mov r0, #3
	str r0, [sp, #4]
	sub r0, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r2, #1
	ldr r0, _021ECF30 ; =ov01_021ECF4C
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r3, #0x1e
	bl ov01_021EC504
	ldr r0, _021ECF34 ; =0x0000726F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ECF38 ; =0x00006318
	add r1, r4, #0
	str r0, [sp, #4]
	mov r0, #2
	str r0, [sp, #8]
	ldr r0, _021ECF3C ; =0x00000F64
	lsl r2, r2, #2
	ldrh r0, [r5, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r5]
	add r0, r4, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	add r0, r4, #0
	mov r1, #8
	add r0, #0xb4
	str r1, [r0]
	mov r0, #0
	add r4, #0xb8
	str r0, [r4]
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #1
	strh r1, [r5, r0]
	b _021ECF02
_021ECD94:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECDB4
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ECF02
_021ECDB4:
	ldr r2, _021ECF3C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ECDCC
	cmp r6, #3
	beq _021ECDCE
_021ECDCC:
	b _021ECF02
_021ECDCE:
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ECF02
_021ECDD6:
	mov r2, #6
	mov r3, #3
	str r2, [sp]
	add r0, r3, #0
	str r3, [sp, #4]
	sub r0, #8
	str r0, [sp, #8]
	mov r0, #2
	str r0, [sp, #0xc]
	mov r0, #1
	str r0, [sp, #0x10]
	ldr r0, _021ECF30 ; =ov01_021ECF4C
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov01_021EC504
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECE1C
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ECF34 ; =0x0000726F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ECF38 ; =0x00006318
	mov r1, #3
	str r0, [r4, #0x1c]
	bl ov01_021EC678
	add r0, r4, #0
	add r0, #0x1c
	bl ov01_021EC7C8
_021ECE1C:
	mov r0, #0
	add r4, #0xb8
	str r0, [r4]
	mov r0, #3
	str r0, [sp]
	ldr r0, _021ECF44 ; =ov01_021ED070
	ldr r1, _021ECF30 ; =ov01_021ECF4C
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0x14
	mov r3, #2
	bl ov01_021EC85C
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ECF02
_021ECE3E:
	mov r0, #6
	ldrsh r1, [r4, r0]
	sub r0, r1, #1
	strh r0, [r4, #6]
	cmp r1, #0
	bgt _021ECE5A
	mov r1, #4
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	bl ov01_021ECF4C
	mov r0, #8
	ldrsh r0, [r4, r0]
	strh r0, [r4, #6]
_021ECE5A:
	ldr r0, _021ECF48 ; =0x00000F66
	ldrh r0, [r5, r0]
	cmp r0, #5
	bne _021ECF02
	mov r0, #2
	mvn r0, r0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x1e
	mov r3, #5
	bl ov01_021EC52C
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECE88
	add r0, r4, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ECE88:
	mov r0, #0
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #4
	strh r1, [r5, r0]
	b _021ECF02
_021ECE96:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ECEB6
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ECF02
_021ECEB6:
	ldr r0, _021ECF3C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECEC8
	add r4, #0x1c
	add r0, r4, #0
	bl ov01_021EC7AC
	b _021ECECA
_021ECEC8:
	mov r0, #1
_021ECECA:
	cmp r0, #1
	bne _021ECF02
	cmp r6, #3
	bne _021ECF02
	add r0, r5, #0
	ldr r1, [r5, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ECF02
	ldr r0, _021ECF40 ; =0x00000F62
	mov r1, #5
	strh r1, [r5, r0]
	b _021ECF02
_021ECEE4:
	add r0, #0xc
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ECEFC
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r4, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ECEFC:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021ECF02:
	ldr r0, _021ECF40 ; =0x00000F62
	ldrh r0, [r5, r0]
	cmp r0, #5
	beq _021ECF28
	cmp r0, #0
	beq _021ECF28
	add r0, r5, #0
	ldr r1, _021ECF44 ; =ov01_021ED070
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r5, #0
	bl ov01_021EC300
_021ECF28:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021ECF2C: .word 0x00000F58
_021ECF30: .word ov01_021ECF4C
_021ECF34: .word 0x0000726F
_021ECF38: .word 0x00006318
_021ECF3C: .word 0x00000F64
_021ECF40: .word 0x00000F62
_021ECF44: .word ov01_021ED070
_021ECF48: .word 0x00000F66
	thumb_func_end ov01_021ECD08


	thumb_func_start ov01_021ECF4C
ov01_021ECF4C: ; 0x021ECF4C
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x58
	ldr r3, _021ED064 ; =ov01_0220673C
	add r2, sp, #0x48
	str r0, [sp]
	str r1, [sp, #4]
	ldmia r3!, {r0, r1}
	str r2, [sp, #0x10]
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r3, _021ED068 ; =ov01_0220674C
	add r2, sp, #0x38
	str r2, [sp, #0x14]
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldmia r3!, {r0, r1}
	stmia r2!, {r0, r1}
	ldr r1, _021ED06C ; =0x00000F58
	ldr r0, [sp]
	ldr r6, [r0, r1]
	mov r0, #0
	str r0, [sp, #0xc]
	ldr r0, [sp, #4]
	cmp r0, #0
	ble _021ED060
	add r0, r6, #0
	str r0, [sp, #0x18]
	add r0, #0xb8
	str r0, [sp, #0x18]
	mov r0, #7
	mvn r0, r0
	lsl r0, r0, #0xc
	str r0, [sp, #0x1c]
_021ECF90:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r4, r0, #0
	beq _021ED060
	ldr r0, [sp, #0x18]
	ldr r5, [r4, #8]
	ldr r0, [r0]
	add r1, r0, #1
	ldr r0, [sp, #0x18]
	str r1, [r0]
	add r0, r6, #0
	add r0, #0xb8
	ldr r1, [r0]
	mov r0, #0x32
	lsl r0, r0, #4
	cmp r1, r0
	blt _021ECFBE
	add r1, r6, #0
	add r1, #0xb8
	mov r0, #0
	str r0, [r1]
_021ECFBE:
	add r0, r6, #0
	add r0, #0xb8
	ldr r0, [r0]
	mov r1, #0xc8
	bl _s32_div_f
	lsl r0, r0, #2
	ldr r1, [sp, #0x10]
	str r0, [sp, #8]
	ldr r0, [r1, r0]
	str r0, [r5, #0x14]
	mov r0, #0
	str r0, [r5]
	bl MTRandom
	mov r1, #0x2a
	bl _u32_div_f
	add r0, r1, #4
	str r0, [r5, #4]
	sub r0, r0, #4
	mov r1, #0xf
	bl _s32_div_f
	add r7, r0, #0
	lsl r1, r7, #0x10
	ldr r0, [r4, #4]
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	add r0, r7, #1
	neg r1, r0
	str r1, [r5, #0x10]
	ldr r2, [sp, #0x14]
	ldr r1, [sp, #8]
	ldr r1, [r2, r1]
	mul r1, r0
	str r1, [r5, #8]
	mov r0, #0
	str r0, [r5, #0xc]
	add r0, sp, #0x20
	add r1, r4, #0
	bl ov01_021EC304
	add r3, sp, #0x20
	ldmia r3!, {r0, r1}
	add r2, sp, #0x2c
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	bl MTRandom
	mov r1, #0x69
	lsl r1, r1, #2
	bl _u32_div_f
	mov r0, #1
	sub r2, r0, r7
	sub r0, #0x15
	mul r0, r2
	add r1, r0, r1
	mov r0, #7
	mvn r0, r0
	str r0, [sp, #0x30]
	mov r0, #0
	str r0, [sp, #0x34]
	str r1, [sp, #0x2c]
	lsl r0, r1, #0xc
	str r0, [sp, #0x2c]
	ldr r0, [sp, #0x1c]
	add r1, sp, #0x2c
	str r0, [sp, #0x30]
	ldr r0, [r4, #4]
	bl ov01_021EB5F4
	ldr r0, [sp, #0xc]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #0xc]
	cmp r1, r0
	blt _021ECF90
_021ED060:
	add sp, #0x58
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021ED064: .word ov01_0220673C
_021ED068: .word ov01_0220674C
_021ED06C: .word 0x00000F58
	thumb_func_end ov01_021ECF4C


	thumb_func_start ov01_021ED070
ov01_021ED070: ; 0x021ED070
	push {r3, r4, r5, lr}
	sub sp, #0x18
	add r5, r0, #0
	add r0, sp, #0
	add r1, r5, #0
	ldr r4, [r5, #8]
	bl ov01_021EC304
	add r3, sp, #0
	ldmia r3!, {r0, r1}
	add r2, sp, #0xc
	stmia r2!, {r0, r1}
	ldr r0, [r3]
	str r0, [r2]
	ldr r0, [r4, #0xc]
	cmp r0, #0
	beq _021ED09A
	cmp r0, #1
	beq _021ED0E6
	add sp, #0x18
	pop {r3, r4, r5, pc}
_021ED09A:
	ldr r0, [r4, #0x10]
	ldr r1, [sp, #0xc]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #0xc]
	ldr r0, [r4, #8]
	ldr r1, [sp, #0x10]
	lsl r0, r0, #0xc
	add r0, r1, r0
	str r0, [sp, #0x10]
	ldr r1, [r4]
	add r0, r1, #1
	str r0, [r4]
	ldr r0, [r4, #4]
	cmp r1, r0
	ble _021ED0BE
	mov r0, #1
	str r0, [r4, #0xc]
_021ED0BE:
	ldr r0, [r4]
	ldr r1, [r4, #0x14]
	bl _s32_div_f
	cmp r1, #0
	bne _021ED0DA
	ldr r0, [r4, #0x10]
	sub r0, r0, #1
	str r0, [r4, #0x10]
	ldr r0, [r4, #8]
	cmp r0, #1
	ble _021ED0DA
	sub r0, r0, #1
	str r0, [r4, #8]
_021ED0DA:
	ldr r0, [r5, #4]
	add r1, sp, #0xc
	bl ov01_021EB5F4
	add sp, #0x18
	pop {r3, r4, r5, pc}
_021ED0E6:
	add r0, r5, #0
	bl ov01_021EC29C
	add sp, #0x18
	pop {r3, r4, r5, pc}
	thumb_func_end ov01_021ED070


	thumb_func_start ov01_021ED0F0
ov01_021ED0F0: ; 0x021ED0F0
	push {r4, r5, r6, lr}
	sub sp, #0x18
	ldr r0, _021ED2FC ; =0x00000F58
	add r5, r1, #0
	add r2, r0, #0
	add r2, #0xa
	ldrh r2, [r5, r2]
	ldr r4, [r5, r0]
	cmp r2, #5
	bhi _021ED1AA
	add r2, r2, r2
	add r2, pc
	ldrh r2, [r2, #6]
	lsl r2, r2, #0x10
	asr r2, r2, #0x10
	add pc, r2
_021ED110: ; jump table
	.short _021ED11C - _021ED110 - 2 ; case 0
	.short _021ED172 - _021ED110 - 2 ; case 1
	.short _021ED1B4 - _021ED110 - 2 ; case 2
	.short _021ED212 - _021ED110 - 2 ; case 3
	.short _021ED26A - _021ED110 - 2 ; case 4
	.short _021ED2B4 - _021ED110 - 2 ; case 5
_021ED11C:
	mov r0, #0x14
	str r0, [sp]
	mov r2, #2
	str r2, [sp, #4]
	sub r0, r2, #4
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r0, _021ED300 ; =ov01_021ED31C
	str r2, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	mov r3, #0x10
	bl ov01_021EC504
	ldr r0, _021ED304 ; =0x0000716F
	mov r2, #0x41
	str r0, [sp]
	ldr r0, _021ED308 ; =0x00006B5A
	lsl r2, r2, #2
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r0, _021ED30C ; =0x00000F64
	add r1, r4, #0
	ldrh r0, [r5, r0]
	add r1, #0x1c
	str r0, [sp, #0xc]
	ldr r3, [r5]
	add r0, r4, #0
	ldr r2, [r3, r2]
	add r0, #0x4c
	ldr r2, [r2, #0x4c]
	mov r3, #3
	bl ov01_021EC5FC
	mov r0, #0
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #1
	strh r1, [r5, r0]
	b _021ED2D2
_021ED172:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ED192
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ED2D2
_021ED192:
	ldr r2, _021ED30C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED1AA
	cmp r6, #3
	beq _021ED1AC
_021ED1AA:
	b _021ED2D2
_021ED1AC:
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ED2D2
_021ED1B4:
	mov r2, #0x14
	mov r3, #2
	str r2, [sp]
	str r3, [sp, #4]
	sub r0, r3, #4
	str r0, [sp, #8]
	mov r0, #4
	str r0, [sp, #0xc]
	ldr r0, _021ED300 ; =ov01_021ED31C
	str r3, [sp, #0x10]
	str r0, [sp, #0x14]
	add r0, r4, #0
	bl ov01_021EC504
	ldr r0, _021ED30C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED1F6
	mov r0, #0x41
	ldr r1, [r5]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r2, _021ED304 ; =0x0000716F
	ldr r0, [r0, #0x4c]
	ldr r3, _021ED308 ; =0x00006B5A
	mov r1, #3
	str r0, [r4, #0x1c]
	bl ov01_021EC678
	add r4, #0x1c
	add r0, r4, #0
	bl ov01_021EC7C8
_021ED1F6:
	mov r0, #1
	str r0, [sp]
	ldr r0, _021ED314 ; =ov01_021ED44C
	ldr r1, _021ED300 ; =ov01_021ED31C
	str r0, [sp, #4]
	add r0, r5, #0
	mov r2, #0x14
	mov r3, #0xa
	bl ov01_021EC85C
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #3
	strh r1, [r5, r0]
	b _021ED2D2
_021ED212:
	mov r0, #6
	ldrsh r1, [r4, r0]
	sub r0, r1, #1
	strh r0, [r4, #6]
	cmp r1, #0
	bgt _021ED22E
	mov r1, #4
	ldrsh r1, [r4, r1]
	add r0, r5, #0
	bl ov01_021ED31C
	mov r0, #8
	ldrsh r0, [r4, r0]
	strh r0, [r4, #6]
_021ED22E:
	ldr r0, _021ED318 ; =0x00000F66
	ldrh r0, [r5, r0]
	cmp r0, #5
	bne _021ED2D2
	mov r0, #9
	mvn r0, r0
	str r0, [sp]
	add r0, r4, #0
	mov r1, #0
	mov r2, #0x10
	mov r3, #6
	bl ov01_021EC52C
	ldr r0, _021ED30C ; =0x00000F64
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED25C
	add r0, r4, #0
	add r0, #0x1c
	mov r1, #1
	mov r2, #0
	bl ov01_021EC790
_021ED25C:
	mov r0, #0x14
	add r4, #0xb4
	str r0, [r4]
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #4
	strh r1, [r5, r0]
	b _021ED2D2
_021ED26A:
	add r0, r4, #0
	bl ov01_021EC538
	add r6, r0, #0
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	cmp r0, #0
	ble _021ED28A
	add r0, r4, #0
	add r0, #0xb4
	ldr r0, [r0]
	add r4, #0xb4
	sub r0, r0, #1
	str r0, [r4]
	b _021ED2D2
_021ED28A:
	ldr r2, _021ED30C ; =0x00000F64
	add r0, r4, #0
	ldrh r2, [r5, r2]
	add r4, #0x1c
	add r0, #0x4c
	add r1, r4, #0
	bl ov01_021EC650
	cmp r0, #1
	bne _021ED2D2
	cmp r6, #3
	bne _021ED2D2
	add r0, r5, #0
	ldr r1, [r5, #0x40]
	add r0, #0xc
	cmp r1, r0
	bne _021ED2D2
	ldr r0, _021ED310 ; =0x00000F62
	mov r1, #5
	strh r1, [r5, r0]
	b _021ED2D2
_021ED2B4:
	add r0, #0xc
	ldrh r0, [r5, r0]
	cmp r0, #0
	beq _021ED2CC
	mov r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	ldr r0, [r4, #0x1c]
	mov r1, #1
	add r3, r2, #0
	bl ov01_021EA864
_021ED2CC:
	ldr r0, [r5, #4]
	bl ov01_021EBCA4
_021ED2D2:
	ldr r0, _021ED310 ; =0x00000F62
	ldrh r0, [r5, r0]
	cmp r0, #5
	beq _021ED2F8
	cmp r0, #0
	beq _021ED2F8
	add r0, r5, #0
	ldr r1, _021ED314 ; =ov01_021ED44C
	add r0, #0xc
	bl ov01_021EC2E4
	mov r1, #0
	add r0, r5, #0
	add r2, r1, #0
	bl ov01_021EC470
	add r0, r5, #0
	bl ov01_021EC300
_021ED2F8:
	add sp, #0x18
	pop {r4, r5, r6, pc}
	.balign 4, 0
_021ED2FC: .word 0x00000F58
_021ED300: .word ov01_021ED31C
_021ED304: .word 0x0000716F
_021ED308: .word 0x00006B5A
_021ED30C: .word 0x00000F64
_021ED310: .word 0x00000F62
_021ED314: .word ov01_021ED44C
_021ED318: .word 0x00000F66
	thumb_func_end ov01_021ED0F0


	thumb_func_start ov01_021ED31C
ov01_021ED31C: ; 0x021ED31C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #0xc]
	add r0, r1, #0
	str r1, [sp, #4]
	cmp r0, #0
	bgt _021ED330
	b _021ED448
_021ED330:
	ldr r0, [sp]
	mov r1, #0x20
	bl ov01_021EC1F4
	add r4, r0, #0
	bne _021ED33E
	b _021ED448
_021ED33E:
	ldr r5, [r4, #8]
	mov r0, #0
	str r0, [r5]
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	add r0, r1, #7
	str r0, [r5, #4]
	bl MTRandom
	mov r1, #0xfa
	lsl r1, r1, #2
	bl _u32_div_f
	lsr r2, r1, #0x1f
	lsl r1, r1, #0x1f
	sub r1, r1, r2
	mov r0, #0x1f
	ror r1, r0
	add r0, r2, r1
	bne _021ED370
	mov r0, #1
	b _021ED374
_021ED370:
	mov r0, #0
	mvn r0, r0
_021ED374:
	str r0, [r5, #8]
	mov r0, #1
	str r0, [r5, #0xc]
	bl MTRandom
	mov r1, #6
	bl _u32_div_f
	add r0, r1, #3
	str r0, [r5, #0x10]
	bl MTRandom
	mov r1, #5
	bl _u32_div_f
	add r0, r1, #4
	str r0, [r5, #0x14]
	bl MTRandom
	mov r1, #0x14
	bl _u32_div_f
	str r1, [sp, #8]
	add r0, sp, #0x10
	add r1, r4, #0
	bl ov01_021EC304
	bl MTRandom
	mov r1, #6
	lsl r1, r1, #6
	bl _u32_div_f
	sub r1, #0x40
	str r1, [sp, #0x10]
	bl MTRandom
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	ldr r0, [sp, #0x10]
	sub r1, #8
	lsl r0, r0, #0xc
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	lsl r0, r1, #0xc
	str r0, [sp, #0x14]
	mov r0, #0
	str r0, [sp, #0x18]
	ldr r0, [r4, #4]
	add r1, sp, #0x10
	bl ov01_021EB5F4
	ldr r1, [sp, #0x14]
	ldr r0, [sp, #0x10]
	asr r1, r1, #0xc
	asr r0, r0, #0xc
	str r1, [sp, #0x14]
	mov r1, #3
	str r0, [sp, #0x10]
	bl _s32_div_f
	mov r1, #0x32
	sub r6, r1, r0
	mov r1, #0xce
	sub r7, r1, r0
	bpl _021ED406
	bl MTRandom
	neg r1, r7
	bl _u32_div_f
	sub r1, r6, r1
	b _021ED412
_021ED406:
	bl MTRandom
	add r1, r7, #0
	bl _u32_div_f
	add r1, r6, r1
_021ED412:
	ldr r0, [sp, #0x14]
	cmp r6, r0
	bgt _021ED424
	cmp r1, r0
	blt _021ED424
	ldr r0, [r5, #4]
	lsl r0, r0, #1
	str r0, [r5, #4]
	b _021ED42E
_021ED424:
	bl MTRandom
	mov r1, #3
	and r0, r1
	str r0, [sp, #8]
_021ED42E:
	ldr r1, [sp, #8]
	ldr r0, [r4, #4]
	lsl r1, r1, #0x10
	lsr r1, r1, #0x10
	bl Sprite_SetAnimationFrame
	ldr r0, [sp, #0xc]
	add r1, r0, #1
	ldr r0, [sp, #4]
	str r1, [sp, #0xc]
	cmp r1, r0
	bge _021ED448
	b _021ED330
_021ED448:
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	thumb_func_end ov01_021ED31C
