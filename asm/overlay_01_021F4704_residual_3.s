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
	.public MapLoadManager_End
	.public MapLoadManager_ForgetTrackedTarget
	.public MapLoadManager_FreeNARCAndLoadedMapBuffers
	.public MapLoadManager_HasEnded
	.public MapLoadManager_InitialLoad
	.public MapLoadManager_New
	.public MapLoadManager_RenderLoadedMap
	.public MapLoadManager_RenderLoadedMaps
	.public MapLoadManager_Tick
	.public MapLoadManager_TrackTarget
	.public _021F4722
	.public _021F4746
	.public _021F4764
	.public _021F4772
	.public _021F478C
	.public _021F4798
	.public _021F47DA
	.public _021F47E2
	.public _021F47FC
	.public _021F4808
	.public _021F4824
	.public _021F4830
	.public _021F484A
	.public _021F485A
	.public _021F4876
	.public _021F4886
	.public _021F488A
	.public _021F4894
	.public _021F4944
	.public _021F4964
	.public _021F4968
	.public _021F496C
	.public _021F4970
	.public _021F4974
	.public _021F4978
	.public _021F4982
	.public _021F49EC
	.public _021F49F0
	.public _021F49F4
	.public _021F49F8
	.public _021F4A22
	.public _021F4A38
	.public _021F4A6C
	.public _021F4A72
	.public _021F4A7E
	.public _021F4A82
	.public _021F4A9E
	.public _021F4AA4
	.public _021F4AA8
	.public _021F4ADC
	.public _021F4AE0
	.public _021F4B0C
	.public _021F4B1A
	.public _021F4B56
	.public _021F4B70
	.public _021F4BA6
	.public _021F4BAC
	.public _021F4BE4
	.public _021F4C5E
	.public _021F4C64
	.public _021F4C68
	.public _021F4C9C
	.public _021F4CD8
	.public _021F4CFE
	.public _021F4D04
	.public _021F4D08
	.public _021F4D0C
	.public _021F4D7C
	.public _021F4D80
	.public _021F4D84
	.public _021F4E04
	.public _021F4E10
	.public _021F4E14
	.public _021F4E18
	.public _021F4E80
	.public _021F4E84
	.public _021F4EFE
	.public _021F4F04
	.public _021F4F08
	.public _021F4F96
	.public _021F4FA4
	.public _021F4FA8
	.public _021F4FAC
	.public _021F501A
	.public _021F5020
	.public _021F5034
	.public _021F5060
	.public _021F50B6
	.public _021F5128
	.public _021F513A
	.public _021F513C
	.public _021F517A
	.public _021F518E
	.public _021F5198
	.public _021F51AE
	.public _021F51BA
	.public _021F51D8
	.public _021F51DE
	.public _021F51F8
	.public _021F520E
	.public _021F5230
	.public _021F523C
	.public _021F5258
	.public _021F525A
	.public _021F526E
	.public _021F5276
	.public _021F5282
	.public _021F528E
	.public _021F5296
	.public _021F52D6
	.public _021F52EC
	.public _021F5324
	.public _021F534A
	.public _021F5352
	.public _021F5386
	.public _021F5388
	.public _021F5392
	.public _021F5394
	.public _021F53A8
	.public _021F53E6
	.public _021F53FA
	.public _021F541C
	.public _021F5472
	.public _021F5482
	.public _021F54A4
	.public _021F54A8
	.public _021F54C6
	.public _021F5528
	.public _021F5544
	.public _021F5564
	.public _021F55D8
	.public _021F55E4
	.public _021F55E8
	.public _021F55EC
	.public _021F55F0
	.public _021F563E
	.public _021F564A
	.public _021F5654
	.public _021F5688
	.public _021F5698
	.public _021F569E
	.public _021F56BE
	.public _021F56D0
	.public _021F56D4
	.public _021F56F2
	.public _021F572E
	.public _021F5734
	.public _021F574A
	.public _021F5750
	.public _021F5778
	.public _021F577E
	.public _021F579C
	.public _021F57A2
	.public _021F57A6
	.public _021F57C4
	.public _021F5808
	.public _021F580E
	.public _021F582C
	.public _021F5832
	.public _021F5862
	.public _021F5868
	.public _021F587E
	.public _021F5882
	.public _021F58A0
	.public _021F58DE
	.public _021F58F0
	.public _021F591A
	.public _021F592A
	.public _021F5930
	.public _021F5934
	.public _021F5952
	.public _021F59A8
	.public _021F59C6
	.public _021F59EE
	.public _021F59F4
	.public _021F59F8
	.public _021F59FC
	.public _021F5A00
	.public _021F5A5E
	.public _021F5A66
	.public _021F5A6E
	.public _021F5A76
	.public _021F5A96
	.public _021F5AA0
	.public _021F5AB2
	.public _021F5AB6
	.public _021F5AC4
	.public _021F5AD4
	.public _021F5AD8
	.public _021F5AE0
	.public _021F5AE6
	.public _021F5AF8
	.public _021F5B02
	.public _021F5B0A
	.public _021F5B12
	.public _021F5B1A
	.public _021F5B20
	.public _021F5B42
	.public _021F5B50
	.public _021F5B56
	.public _021F5B6A
	.public _021F5B78
	.public _021F5B7E
	.public _021F5B82
	.public _021F5B9A
	.public _021F5BA4
	.public _021F5BA8
	.public _021F5BAC
	.public _021F5BB0
	.public _021F5BB4
	.public _021F5BC6
	.public _021F5BE2
	.public _021F5C0C
	.public _021F5CC8
	.public _021F5CD6
	.public _021F5D24
	.public _021F5D48
	.public _021F5D52
	.public _021F5D60
	.public _021F5D6E
	.public _021F5D7C
	.public _021F5D88
	.public _021F5DBC
	.public _021F5E1C
	.public _021F5E4E
	.public _021F5E9C
	.public _021F5ED0
	.public _021F5F30
	.public _021F5F50
	.public _021F601A
	.public _021F6054
	.public _021F6064
	.public _021F6074
	.public _021F6078
	.public _021F610C
	.public _021F6110
	.public _021F6114
	.public _021F61A4
	.public _021F61B2
	.public _021F61CE
	.public _021F620E
	.public _021F6226
	.public _021F6272
	.public _021F62A4
	.public _021F62A8
	.public _021F62AC
	.public _021F62E2
	.public _021F631C
	.public _021F634C
	.public _021F6350
	.public _021F6358
	.public _021F6372
	.public _021F637E
	.public _021F638A
	.public _021F6396
	.public _021F639E
	.public _021F63B8
	.public _021F63D2
	.public _021F63FC
	.public _021F6400
	.public _021F641A
	.public _021F6436
	.public _021F6460
	.public _021F6464
	.public _021F647E
	.public _021F649A
	.public _021F64C2
	.public _021F64C6
	.public _021F64E0
	.public _021F64FC
	.public _021F6524
	.public _021F6528
	.public _021F653A
	.public _021F658A
	.public _021F65A0
	.public _021F65C2
	.public _021F65CA
	.public _021F65E0
	.public _021F6610
	.public _021F6630
	.public _021F6638
	.public _021F6644
	.public _021F6650
	.public _021F6662
	.public _021F6666
	.public _021F6680
	.public _021F6694
	.public _021F6696
	.public _021F66AE
	.public _021F66B6
	.public _021F66CE
	.public _021F66D4
	.public _021F66E8
	.public _021F6700
	.public _021F6702
	.public _021F670C
	.public _021F670E
	.public _021F6716
	.public _021F672A
	.public _021F674C
	.public _021F6758
	.public _021F676A
	.public _021F67B0
	.public _021F67DE
	.public _021F67EE
	.public _021F680C
	.public _021F680E
	.public _021F6818
	.public _021F681A
	.public _021F6822
	.public ov01_021F4704
	.public ov01_021F4728
	.public ov01_021F474C
	.public ov01_021F477C
	.public ov01_021F47A0
	.public ov01_021F488C
	.public ov01_021F497C
	.public ov01_021F49FC
	.public ov01_021F4A50
	.public ov01_021F4AAC
	.public ov01_021F4AE4
	.public ov01_021F4B1C
	.public ov01_021F4BE8
	.public ov01_021F4C6C
	.public ov01_021F4D10
	.public ov01_021F4D88
	.public ov01_021F4E1C
	.public ov01_021F4E88
	.public ov01_021F4F0C
	.public ov01_021F4FB0
	.public ov01_021F5024
	.public ov01_021F5038
	.public ov01_021F54AC
	.public ov01_021F5568
	.public ov01_021F55F4
	.public ov01_021F562C
	.public ov01_021F5A04
	.public ov01_021F5A28
	.public ov01_021F5A30
	.public ov01_021F5A54
	.public ov01_021F5A80
	.public ov01_021F5AE8
	.public ov01_021F5B24
	.public ov01_021F5B88
	.public ov01_021F5BBC
	.public ov01_021F5BF0
	.public ov01_021F5CB4
	.public ov01_021F5D10
	.public ov01_021F5D20
	.public ov01_021F5D38
	.public ov01_021F5D8C
	.public ov01_021F5E20
	.public ov01_021F5EA0
	.public ov01_021F5F34
	.public ov01_021F5F64
	.public ov01_021F5FB8
	.public ov01_021F613C
	.public ov01_021F61DC
	.public ov01_021F630C
	.public ov01_021F6320
	.public ov01_021F6328
	.public ov01_021F635C
	.public ov01_021F652C
	.public ov01_021F654C
	.public ov01_021F65D0
	.public ov01_021F65E4
	.public ov01_021F65F0
	.public ov01_021F6600
	.public ov01_021F6614
	.public ov01_021F6620
	.public ov01_021F676C
	.public ov01_021F67B4
	.public ov01_02206BC0
	.public ov01_02206BC8
	.public ov01_02206BD0
	.public ov01_02206BD8
	.public ov01_02206BE4
	.include "overlay_01_021F4704.inc"
	.include "global.inc"

	.text
	.public MapLoadManager_ForgetTrackedTarget
	.public MapLoadManager_FreeNARCAndLoadedMapBuffers
	.public MapLoadManager_HasEnded
	.public MapLoadManager_InitialLoad
	.public MapLoadManager_RenderLoadedMaps
	.public MapLoadManager_TrackTarget
	.public ov01_021F4704
	.public ov01_021F4728
	.public ov01_021F474C
	.public ov01_021F477C
	.public ov01_021F497C
	.public ov01_021F4AAC
	.public ov01_021F4AE4
	.public ov01_021F4E88
	.public ov01_021F4F0C
	.public ov01_021F4FB0
	.public ov01_021F5024
	.public ov01_021F55F4
	.public ov01_021F5A04
	.public ov01_021F5A28
	.public ov01_021F5A30
	.public ov01_021F5A54
	.public ov01_021F5AE8
	.public ov01_021F5B88
	.public ov01_021F5CB4
	.public ov01_021F5D10
	.public ov01_021F5D20
	.public ov01_021F5D38
	.public ov01_021F5D8C
	.public ov01_021F5E20
	.public ov01_021F5EA0
	.public ov01_021F5F34
	.public ov01_021F5F64
	.public ov01_021F61DC
	.public ov01_021F630C
	.public ov01_021F6320
	.public ov01_021F6328
	.public ov01_021F652C
	.public ov01_021F65D0
	.public ov01_021F65E4
	.public ov01_021F65F0
	.public ov01_021F6600
	.public ov01_021F6614
	.public ov01_021F676C

	thumb_func_start ov01_021F4B1C
ov01_021F4B1C: ; 0x021F4B1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	add r5, r0, #0
	add r0, #0xc4
	ldr r0, [r0]
	add r7, r1, #0
	str r0, [sp, #0xc]
	add r4, r3, #0
	ldr r1, [sp, #0xc]
	add r0, r4, #0
	str r2, [sp, #8]
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r6, r0, #0x10
	ldr r1, [sp, #0xc]
	add r0, r4, #0
	bl _s32_div_f
	lsl r0, r0, #0x10
	lsr r4, r0, #0x10
	cmp r6, #1
	blo _021F4B56
	cmp r6, #3
	bhi _021F4B56
	cmp r4, #1
	blo _021F4B56
	cmp r4, #2
	bls _021F4B70
_021F4B56:
	mov r0, #1
	lsl r0, r0, #8
	ldr r1, [sp, #8]
	ldr r2, _021F4BE4 ; =0x00000868
	ldr r0, [r5, r0]
	add r5, #0xf4
	ldr r1, [r1, #0xc]
	ldr r2, [r7, r2]
	ldr r3, [r5]
	bl MapPropManager_LoadFromNARC
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
_021F4B70:
	mov r0, #0x41
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Save_SafariZone_Get
	str r0, [sp, #0x14]
	bl sub_0202F620
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x14]
	ldr r1, [sp, #0x18]
	bl SafariZone_GetAreaSet
	str r0, [sp, #0x10]
	ldr r0, [sp, #0x18]
	cmp r0, #0
	bne _021F4BA6
	mov r0, #0x41
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	bl Save_PlayerData_GetProfile
	bl PlayerProfile_GetTrainerGender
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	b _021F4BAC
_021F4BA6:
	ldr r0, [sp, #0x14]
	bl SafariZone_GetLinkLeaderGender
_021F4BAC:
	str r7, [sp]
	str r0, [sp, #4]
	mov r0, #1
	lsl r0, r0, #8
	sub r4, r4, #1
	ldr r0, [r5, r0]
	add r5, #0xf4
	sub r3, r6, #1
	lsl r3, r3, #0x10
	ldr r1, _021F4BE4 ; =0x00000868
	lsl r4, r4, #0x10
	ldr r2, [r5]
	lsr r5, r4, #0x10
	lsl r4, r5, #1
	lsr r3, r3, #0x10
	add r4, r5, r4
	add r4, r3, r4
	mov r3, #0x7a
	add r5, r4, #0
	mul r5, r3
	ldr r3, [sp, #0x10]
	ldr r1, [r7, r1]
	add r3, r3, r5
	bl MapPropManager_LoadFromSafariZone
	add sp, #0x1c
	pop {r4, r5, r6, r7, pc}
	nop
_021F4BE4: .word 0x00000868
	thumb_func_end ov01_021F4B1C


	thumb_func_start ov01_021F4BE8
ov01_021F4BE8: ; 0x021F4BE8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	ldr r4, [sp, #0x28]
	add r6, r0, #0
	ldr r0, [r4, #0x10]
	add r5, r1, #0
	add r0, r0, #1
	str r0, [r4, #0x10]
	add r0, r3, #0
	add r7, r2, #0
	bl AreaDataManager_GetMapTexture
	ldr r1, _021F4C64 ; =0x00000854
	mov r3, #1
	add r2, r5, r1
	str r2, [sp]
	str r0, [sp, #4]
	add r0, r6, #0
	add r0, #0xf8
	ldr r0, [r0]
	add r1, #0x10
	str r0, [sp, #8]
	add r0, r5, r1
	str r0, [sp, #0xc]
	add r0, r4, #0
	add r0, #0x10
	str r0, [sp, #0x10]
	lsl r3, r3, #8
	ldr r0, [r6, r3]
	lsl r3, r3, #3
	ldr r1, [sp, #0x2c]
	ldr r2, [r7, #4]
	add r3, r5, r3
	bl ov01_021F676C
	str r0, [r4, #8]
	ldr r0, [sp, #0x30]
	cmp r0, #0
	beq _021F4C5E
	ldr r0, [r4, #0x14]
	ldr r2, _021F4C68 ; =0x00000858
	add r0, r0, #1
	str r0, [r4, #0x14]
	add r0, r5, r2
	str r0, [sp]
	add r0, r4, #0
	add r0, #0x10
	str r0, [sp, #4]
	mov r0, #1
	lsl r0, r0, #8
	add r2, r2, #4
	add r3, r4, #0
	ldr r0, [r6, r0]
	ldr r1, [r7, #8]
	ldr r2, [r5, r2]
	add r3, #0x14
	bl ov01_021FB308
	str r0, [r4, #0xc]
_021F4C5E:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	nop
_021F4C64: .word 0x00000854
_021F4C68: .word 0x00000858
	thumb_func_end ov01_021F4BE8


	thumb_func_start ov01_021F4C6C
ov01_021F4C6C: ; 0x021F4C6C
	push {r3, r4, r5, r6, lr}
	sub sp, #4
	add r5, r0, #0
	add r0, r3, #0
	add r4, r1, #0
	add r6, r2, #0
	bl AreaDataManager_GetMapTexture
	mov r2, #1
	str r0, [sp]
	lsl r2, r2, #8
	ldr r3, _021F4D04 ; =0x00000854
	ldr r0, [r5, r2]
	lsl r2, r2, #3
	ldr r1, [r6, #4]
	add r2, r4, r2
	add r3, r4, r3
	bl ov01_021F67B4
	ldr r1, [sp, #0x20]
	cmp r1, #0
	beq _021F4C9C
	bl ov01_021EA3B0
_021F4C9C:
	ldr r3, _021F4D08 ; =0x00000864
	mov r0, #1
	ldr r2, [sp, #0x1c]
	str r0, [r4, r3]
	sub r1, r3, #4
	str r2, [r4, r1]
	ldr r1, [sp, #0x24]
	cmp r1, #0
	beq _021F4CFE
	add r2, r3, #0
	add r0, #0xff
	sub r2, #8
	sub r3, #0xc
	ldr r0, [r5, r0]
	ldr r1, [r6, #8]
	ldr r2, [r4, r2]
	ldr r3, [r4, r3]
	bl ov01_021FB270
	mov r0, #0x42
	lsl r0, r0, #2
	ldr r3, [r5, r0]
	cmp r3, #0
	beq _021F4CD8
	ldr r2, _021F4D0C ; =0x00000868
	add r0, r0, #4
	ldr r0, [r5, r0]
	ldr r1, [sp, #0x1c]
	ldr r2, [r4, r2]
	blx r3
_021F4CD8:
	add r0, r5, #0
	add r0, #0xf8
	ldr r0, [r0]
	bl ov01_02204698
	cmp r0, #0
	beq _021F4CFE
	ldr r0, [sp, #0x18]
	bl sub_02054E20
	cmp r0, #0
	bne _021F4CFE
	add r5, #0xf8
	mov r1, #2
	lsl r1, r1, #0xa
	ldr r0, [r5]
	add r1, r4, r1
	bl ov01_02204678
_021F4CFE:
	add sp, #4
	pop {r3, r4, r5, r6, pc}
	nop
_021F4D04: .word 0x00000854
_021F4D08: .word 0x00000864
_021F4D0C: .word 0x00000868
	thumb_func_end ov01_021F4C6C


	thumb_func_start ov01_021F4D10
ov01_021F4D10: ; 0x021F4D10
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x20
	ldr r5, [sp, #0x40]
	lsl r4, r0, #2
	add r0, r5, r4
	ldr r0, [r0, #0x18]
	ldr r6, [sp, #0x3c]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	str r1, [sp, #0xc]
	mul r0, r3
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r3, [r5, r4]
	add r0, sp, #0x10
	add r1, r6, #0
	bl ov01_021F4A50
	add r7, r0, #0
	ldr r0, _021F4D80 ; =0x0000FFFF
	cmp r7, r0
	beq _021F4D7C
	ldr r1, [r5, r4]
	add r0, r6, #0
	bl ov01_021F4AAC
	ldr r1, [r5, r4]
	ldr r2, [sp, #0x10]
	add r0, r6, #0
	bl ov01_021F4AE4
	mov r0, #1
	lsl r0, r0, #8
	ldr r3, [r5, r4]
	ldr r2, _021F4D84 ; =0x00000868
	ldr r0, [r6, r0]
	ldr r2, [r3, r2]
	add r3, r6, #0
	add r3, #0xf4
	ldr r1, [sp, #0x1c]
	ldr r3, [r3]
	bl MapPropManager_LoadFromNARC
	str r5, [sp]
	str r7, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r1, [r5, r4]
	ldr r3, [sp, #0xc]
	add r0, r6, #0
	add r2, sp, #0x10
	bl ov01_021F4BE8
_021F4D7C:
	add sp, #0x20
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F4D80: .word 0x0000FFFF
_021F4D84: .word 0x00000868
	thumb_func_end ov01_021F4D10


	thumb_func_start ov01_021F4D88
ov01_021F4D88: ; 0x021F4D88
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x1fc
	sub sp, #0x30
	str r1, [sp, #0xc]
	ldr r1, _021F4E10 ; =0x00000828
	lsl r6, r0, #2
	add r1, sp
	ldr r4, [r1, #0x18]
	ldr r5, [r1, #0x14]
	add r0, r4, r6
	ldr r0, [r0, #0x18]
	str r0, [sp]
	ldr r0, [r1, #0x10]
	add r1, r5, #0
	mul r0, r3
	str r0, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r3, [r4, r6]
	add r0, sp, #0x10
	bl ov01_021F4A50
	add r7, r0, #0
	ldr r0, _021F4E14 ; =0x0000FFFF
	cmp r7, r0
	beq _021F4E04
	ldr r1, [r4, r6]
	add r0, r5, #0
	bl ov01_021F4AAC
	mov r1, #1
	lsl r1, r1, #8
	ldr r0, [r5, r1]
	lsl r1, r1, #3
	add r2, sp, #0x20
	bl NARC_ReadFile
	mov r0, #1
	lsl r0, r0, #8
	ldr r3, [r4, r6]
	ldr r2, _021F4E18 ; =0x00000868
	ldr r0, [r5, r0]
	ldr r2, [r3, r2]
	add r3, r5, #0
	add r3, #0xf4
	ldr r1, [sp, #0x1c]
	ldr r3, [r3]
	bl MapPropManager_LoadFromNARC
	str r4, [sp]
	str r7, [sp, #4]
	mov r0, #0
	str r0, [sp, #8]
	ldr r1, [r4, r6]
	ldr r3, [sp, #0xc]
	add r0, r5, #0
	add r2, sp, #0x10
	bl ov01_021F4BE8
_021F4E04:
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x1fc
	add sp, #0x30
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_021F4E10: .word 0x00000828
_021F4E14: .word 0x0000FFFF
_021F4E18: .word 0x00000868
	thumb_func_end ov01_021F4D88


	thumb_func_start ov01_021F4E1C
ov01_021F4E1C: ; 0x021F4E1C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	ldr r5, [sp, #0x40]
	lsl r4, r0, #2
	add r7, r5, #0
	add r7, #0x18
	ldr r0, [r7, r4]
	ldr r6, [sp, #0x3c]
	str r0, [sp]
	ldr r0, [sp, #0x38]
	str r1, [sp, #0xc]
	mul r0, r3
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r3, [r5, r4]
	add r0, sp, #0x14
	add r1, r6, #0
	bl ov01_021F4A50
	ldr r1, _021F4E84 ; =0x0000FFFF
	str r0, [sp, #0x10]
	cmp r0, r1
	beq _021F4E80
	ldr r1, [r5, r4]
	add r0, r6, #0
	bl ov01_021F4AAC
	ldr r1, [r5, r4]
	ldr r2, [sp, #0x14]
	add r0, r6, #0
	bl ov01_021F4AE4
	ldr r1, [r5, r4]
	ldr r3, [r7, r4]
	add r0, r6, #0
	add r2, sp, #0x14
	bl ov01_021F4B1C
	ldr r0, [sp, #0x10]
	str r5, [sp]
	str r0, [sp, #4]
	mov r0, #1
	str r0, [sp, #8]
	ldr r1, [r5, r4]
	ldr r3, [sp, #0xc]
	add r0, r6, #0
	add r2, sp, #0x14
	bl ov01_021F4BE8
_021F4E80:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_021F4E84: .word 0x0000FFFF
	thumb_func_end ov01_021F4E1C
