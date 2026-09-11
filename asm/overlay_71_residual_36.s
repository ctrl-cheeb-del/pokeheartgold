	.include "asm/macros.inc"
	.public TradeSequence_Exit
	.public TradeSequence_Init
	.public TradeSequence_Main
	.public _02246970
	.public _022469A6
	.public _022469EE
	.public _02246A20
	.public _02246A2C
	.public _02246A44
	.public _02246B06
	.public _02246B0C
	.public _02246B14
	.public _02246B18
	.public _02246B1C
	.public _02246B20
	.public _02246B24
	.public _02246B52
	.public _02246BEC
	.public _02246C24
	.public _02246C2C
	.public _02246C34
	.public _02246C38
	.public _02246C3C
	.public _02246C40
	.public _02246C44
	.public _02246C64
	.public _02246C68
	.public _02246CA6
	.public _02246CD6
	.public _02246D28
	.public _02246D30
	.public _02246D34
	.public _02246D38
	.public _02246D3C
	.public _02246D52
	.public _02246D66
	.public _02246D78
	.public _02246D9A
	.public _02246DD8
	.public _02246E1A
	.public _02246E5C
	.public _02246E7C
	.public _02246E80
	.public _02246E94
	.public _02246EA0
	.public _02246EDE
	.public _02246EE0
	.public _02246F52
	.public _02246F58
	.public _02246F5C
	.public _02246F8E
	.public _02246FC2
	.public _02246FD0
	.public _02246FEA
	.public _02246FF8
	.public _02246FFC
	.public _02247034
	.public _02247058
	.public _02247060
	.public _02247064
	.public _0224708A
	.public _02247096
	.public _022470A0
	.public _022470AC
	.public _022470B4
	.public _022470D0
	.public _02247120
	.public _0224713C
	.public _02247140
	.public _02247164
	.public _02247166
	.public _022471A0
	.public _022471B8
	.public _02247202
	.public _0224720C
	.public _0224720E
	.public _02247228
	.public _0224722C
	.public _02247242
	.public _02247250
	.public _02247252
	.public _022472BA
	.public _022472C0
	.public _0224730E
	.public _0224731C
	.public _0224737C
	.public _022473B8
	.public _022473CC
	.public _022473D8
	.public _022473EC
	.public _02247402
	.public _02247412
	.public _02247418
	.public _0224741C
	.public _02247420
	.public _02247434
	.public _02247444
	.public _02247448
	.public _02247482
	.public _02247492
	.public _022474A6
	.public _022474B8
	.public _022474EA
	.public _022474F8
	.public _02247502
	.public _022475AC
	.public _022475C0
	.public _0224760C
	.public _02247668
	.public _0224766A
	.public _02247674
	.public _02247676
	.public _022476AC
	.public _02247722
	.public _022477E8
	.public _02247818
	.public _02247828
	.public _02247838
	.public _02247848
	.public _022478B4
	.public _0224791E
	.public _02247980
	.public _0224798C
	.public _022479B4
	.public _022479BE
	.public _022479C4
	.public _02247C0C
	.public _02247C10
	.public _02247C14
	.public _02247C18
	.public _02247C1C
	.public _02247C20
	.public _02247C24
	.public _02247C28
	.public _02247C2C
	.public _02247C30
	.public _02247C5A
	.public _02247C7A
	.public _02247C84
	.public _02247C90
	.public _02247C9A
	.public _02247C9C
	.public _02247CBC
	.public _02247CC0
	.public _02247D04
	.public _02247D80
	.public _02247DB4
	.public _02247DD4
	.public _02247DE4
	.public _02247E06
	.public _02247E10
	.public _02247E2A
	.public _02247E50
	.public _02247E7C
	.public _02247E8E
	.public _02247EAE
	.public _02247EC6
	.public _02247ECC
	.public _02247F78
	.public _02247F7C
	.public _02247F80
	.public _02247F84
	.public _02247F88
	.public _02247F8C
	.public _02247F90
	.public _02247F94
	.public _02247F98
	.public _022480A4
	.public _022480AE
	.public _02248106
	.public _02248108
	.public _0224810C
	.public _0224811A
	.public _0224813C
	.public _02248162
	.public _02248178
	.public _022481BC
	.public _022481C0
	.public _022481C4
	.public _022481D2
	.public _022481E8
	.public _02248208
	.public _0224822E
	.public _0224825C
	.public _02248272
	.public _02248278
	.public _02248280
	.public _022482E2
	.public _022482E4
	.public _022482E8
	.public _0224834E
	.public _02248354
	.public _02248386
	.public _02248394
	.public _022483A4
	.public _022483D0
	.public _022483DA
	.public _022483E0
	.public _02248404
	.public _0224844C
	.public _02248462
	.public _0224846E
	.public _0224847A
	.public _02248480
	.public _0224849C
	.public _022484A6
	.public _022484B2
	.public _022484F6
	.public _0224850C
	.public _02248522
	.public _0224852A
	.public _0224854A
	.public _02248554
	.public _0224856A
	.public _02248588
	.public _022485A4
	.public _022485B8
	.public _022485E6
	.public _022485F4
	.public _022485FC
	.public _02248600
	.public _0224880A
	.public _02248880
	.public _02248884
	.public _02248888
	.public _0224888C
	.public _02248890
	.public _02248894
	.public _02248898
	.public _022488B2
	.public _022489C4
	.public _022489C8
	.public _022489CC
	.public _022489D0
	.public _022489D4
	.public _022489D8
	.public _022489DC
	.public _022489E0
	.public _022489E4
	.public _022489E8
	.public _022489EC
	.public _022489F0
	.public _022489F4
	.public _02248A06
	.public _02248AA2
	.public _02248B20
	.public _02248B2C
	.public _02248B36
	.public _02248B40
	.public _02248BB4
	.public _02248BB8
	.public _02248BD8
	.public _02248C1C
	.public _02248C20
	.public _02248C58
	.public _02248C66
	.public _02248CA6
	.public _02248D0A
	.public _02248D78
	.public _02248D7C
	.public _02248E02
	.public _02248E2E
	.public _02248E70
	.public _02248E74
	.public _02248E9A
	.public _02248F38
	.public _02248F84
	.public _02248F88
	.public _02248FBA
	.public _02248FBE
	.public _02249000
	.public _0224902A
	.public _0224905E
	.public _02249068
	.public _02249090
	.public _022490B6
	.public _0224911E
	.public _0224914A
	.public _02249156
	.public _022491E4
	.public _02249200
	.public _02249204
	.public _02249252
	.public _022492F4
	.public _022492F8
	.public _0224933C
	.public _02249354
	.public _0224939A
	.public _022493B0
	.public _022493B4
	.public _022493F8
	.public _02249410
	.public _02249446
	.public _0224945C
	.public _0224949C
	.public _022494CA
	.public _022494FE
	.public _02249524
	.public _0224952E
	.public _02249534
	.public _02249554
	.public _02249598
	.public _0224959C
	.public _022495BA
	.public _022495C4
	.public _022495D0
	.public _022495FA
	.public _02249624
	.public _0224964E
	.public _0224965C
	.public _02249664
	.public _02249668
	.public _0224966C
	.public _022496BA
	.public _022496C2
	.public _022496CE
	.public _022496DA
	.public _022496E6
	.public _022496F0
	.public _022497B4
	.public _022497B8
	.public _022497BC
	.public _022497C0
	.public _022497C4
	.public _022498B4
	.public _022498B8
	.public _022498BC
	.public _022498C0
	.public _022498C4
	.public _022498C8
	.public _022498CC
	.public _022498D0
	.public _022498D4
	.public _022498D8
	.public _022498DC
	.public _022498EC
	.public _0224997E
	.public _022499A2
	.public _02249A34
	.public _02249A38
	.public _02249A3C
	.public _02249A40
	.public _02249A44
	.public _02249A48
	.public _02249A4C
	.public _02249A5A
	.public _02249A96
	.public _02249AB2
	.public _02249AEC
	.public _02249B74
	.public _02249B7C
	.public _02249B88
	.public _02249B92
	.public _02249BC6
	.public _02249BE0
	.public _02249C04
	.public _02249C4A
	.public _02249C7A
	.public _02249C8C
	.public _02249CE4
	.public _02249CE8
	.public _02249CEC
	.public _02249D0E
	.public _02249D24
	.public _02249D4C
	.public _02249D50
	.public _02249D54
	.public _02249D7C
	.public _02249D98
	.public _02249DCA
	.public _02249DF6
	.public _02249E04
	.public _02249E0C
	.public _02249E10
	.public _02249E14
	.public _02249E18
	.public _02249E1C
	.public _02249E20
	.public _02249E52
	.public _0224A064
	.public _0224A068
	.public _0224A06C
	.public _0224A070
	.public _0224A074
	.public _0224A078
	.public _0224A07C
	.public _0224A0EC
	.public _0224A124
	.public _0224A128
	.public _0224A15A
	.public _0224A180
	.public _0224A184
	.public _0224A188
	.public _0224A1C0
	.public _0224A1DE
	.public _0224A1E6
	.public _0224A206
	.public _0224A230
	.public _0224A25C
	.public _0224A26A
	.public _0224A270
	.public _0224A274
	.public _0224A2C2
	.public _0224A2CA
	.public _0224A2D6
	.public _0224A2E2
	.public _0224A2EE
	.public _0224A2F8
	.public _0224A3C8
	.public _0224A3CC
	.public _0224A3D0
	.public _0224A3D4
	.public _0224A4D0
	.public _0224A4D4
	.public _0224A4D8
	.public _0224A4DC
	.public _0224A4E0
	.public _0224A4E4
	.public _0224A4E8
	.public _0224A4EC
	.public _0224A4F0
	.public _0224A4F4
	.public _0224A4F8
	.public _0224A4FC
	.public _0224A50C
	.public _0224A59E
	.public _0224A5C2
	.public _0224A664
	.public _0224A668
	.public _0224A66C
	.public _0224A670
	.public _0224A674
	.public _0224A678
	.public _0224A67C
	.public _0224A680
	.public _0224A68E
	.public _0224A6D4
	.public _0224A6FC
	.public _0224A730
	.public _0224A73A
	.public _0224A744
	.public _0224A7BA
	.public _0224A7CC
	.public _0224A7DE
	.public _0224A7F0
	.public _0224A7F8
	.public _0224A81E
	.public _0224A836
	.public _0224A858
	.public _0224A892
	.public _0224A8A4
	.public _0224A8CE
	.public _0224A910
	.public _0224A914
	.public _0224A918
	.public _0224A91C
	.public _0224A94E
	.public _0224A96E
	.public _0224A978
	.public _0224A982
	.public _0224A988
	.public _0224A9B0
	.public _0224A9BA
	.public _0224A9C0
	.public _0224A9F6
	.public _0224AA24
	.public _0224AA40
	.public _0224AA4E
	.public _0224AA6C
	.public _0224AA86
	.public _0224AA98
	.public _0224AAB0
	.public _0224AAD4
	.public _0224AAE8
	.public _0224AAF2
	.public _0224AB10
	.public _0224AB38
	.public _0224AB62
	.public _0224AB76
	.public _0224AD52
	.public _0224AD94
	.public _0224AD98
	.public _0224AD9C
	.public _0224ADA0
	.public _0224ADA4
	.public _0224ADA8
	.public _0224ADAC
	.public _0224ADC0
	.public _0224AEC8
	.public _0224AECC
	.public _0224AED0
	.public _0224AED4
	.public _0224AED8
	.public _0224AEDC
	.public _0224AEE0
	.public _0224AEE4
	.public _0224AEE8
	.public _0224AEEC
	.public _0224AEF0
	.public _0224AF06
	.public _0224AF48
	.public _0224AF4C
	.public _0224AF50
	.public _0224AF54
	.public _0224AF98
	.public _0224AFD2
	.public _0224B020
	.public _0224B024
	.public _0224B04E
	.public _0224B082
	.public _0224B0DC
	.public _0224B0E0
	.public _0224B0E4
	.public _0224B108
	.public _0224B136
	.public _0224B194
	.public _0224B1C8
	.public _0224B1E2
	.public _0224B1F8
	.public _0224B220
	.public _0224B22A
	.public _0224B230
	.public _0224B272
	.public _0224B430
	.public _0224B434
	.public _0224B438
	.public _0224B43C
	.public _0224B440
	.public _0224B444
	.public _0224B448
	.public _0224B44C
	.public _0224B476
	.public _0224B496
	.public _0224B4A0
	.public _0224B4AE
	.public _0224B4DC
	.public _0224B504
	.public _0224B55A
	.public _0224B566
	.public _0224B576
	.public _0224B596
	.public _0224B5A2
	.public _0224B5AE
	.public _0224B5B8
	.public _0224B5BA
	.public _0224B5DA
	.public _0224B5DE
	.public _0224B62C
	.public _0224B68E
	.public _0224B6AE
	.public _0224B6D8
	.public _0224B6E6
	.public _0224B6EC
	.public _0224B702
	.public _0224B710
	.public _0224B71A
	.public _0224B7C8
	.public _0224B7CC
	.public _0224B7D0
	.public _0224B7D4
	.public _0224B7D8
	.public _0224B7DC
	.public _0224B7E0
	.public _0224B7E4
	.public _0224B7E8
	.public _0224B8F4
	.public _0224B8FE
	.public _0224B956
	.public _0224B958
	.public _0224B95C
	.public _0224B96A
	.public _0224B98C
	.public _0224B9B2
	.public _0224B9C8
	.public _0224BA3A
	.public _0224BA3E
	.public _0224BA40
	.public _0224BA44
	.public _0224BA62
	.public _0224BA86
	.public _0224BA9C
	.public _0224BAB8
	.public _0224BADA
	.public _0224BAE6
	.public _0224BB06
	.public _0224BB16
	.public _0224BB2E
	.public _0224BB44
	.public _0224BB8C
	.public _0224BB9E
	.public _0224BBBA
	.public _0224BBCA
	.public _0224BBCC
	.public _0224BBD0
	.public _0224BBD4
	.public _0224C020
	.public _0224C040
	.public ov71_02246B28
	.public ov71_02246C48
	.public ov71_02246C6C
	.public ov71_02246D40
	.public ov71_02246D54
	.public ov71_02246D9C
	.public ov71_02246E84
	.public ov71_02246EAC
	.public ov71_02246F60
	.public ov71_02246F90
	.public ov71_02247000
	.public ov71_02247068
	.public ov71_022470DC
	.public ov71_02247124
	.public ov71_02247230
	.public ov71_022472C4
	.public ov71_022472FC
	.public ov71_02247320
	.public ov71_02247340
	.public ov71_02247384
	.public ov71_02247388
	.public ov71_0224738C
	.public ov71_02247390
	.public ov71_02247398
	.public ov71_022473A0
	.public ov71_022473A8
	.public ov71_022473B0
	.public ov71_022473BC
	.public ov71_022473C4
	.public ov71_022473D0
	.public ov71_022473DC
	.public ov71_022473E4
	.public ov71_022473F0
	.public ov71_02247424
	.public ov71_0224744C
	.public ov71_02247498
	.public ov71_022474CC
	.public ov71_02247514
	.public ov71_022475C4
	.public ov71_022475F8
	.public ov71_02247610
	.public ov71_022476B4
	.public ov71_022476C4
	.public ov71_022476D4
	.public ov71_022476EC
	.public ov71_02247704
	.public ov71_02247708
	.public ov71_02247730
	.public ov71_02247738
	.public ov71_022477EC
	.public ov71_0224780C
	.public ov71_0224781C
	.public ov71_0224782C
	.public ov71_0224783C
	.public ov71_0224784C
	.public ov71_022478B8
	.public ov71_022478C8
	.public ov71_02247924
	.public ov71_02247990
	.public ov71_022479C8
	.public ov71_02247A10
	.public ov71_02247C34
	.public ov71_02247C60
	.public ov71_02247DEC
	.public ov71_02247ED0
	.public ov71_02247F9C
	.public ov71_02247FF8
	.public ov71_0224809C
	.public ov71_022480C0
	.public ov71_02248110
	.public ov71_02248120
	.public ov71_02248140
	.public ov71_0224817C
	.public ov71_022481C8
	.public ov71_022481D8
	.public ov71_022481EC
	.public ov71_0224820C
	.public ov71_022482EC
	.public ov71_02248358
	.public ov71_022483AC
	.public ov71_022483E4
	.public ov71_02248408
	.public ov71_0224843C
	.public ov71_02248484
	.public ov71_02248530
	.public ov71_02248604
	.public ov71_0224889C
	.public ov71_022488E4
	.public ov71_022489F8
	.public ov71_02248A08
	.public ov71_02248B24
	.public ov71_02248B54
	.public ov71_02248B60
	.public ov71_02248BBC
	.public ov71_02248C24
	.public ov71_02248CF4
	.public ov71_02248D0C
	.public ov71_02248D80
	.public ov71_02248E04
	.public ov71_02248E30
	.public ov71_02248E78
	.public ov71_02248EB4
	.public ov71_02248F8C
	.public ov71_02248FC8
	.public ov71_02249004
	.public ov71_0224903C
	.public ov71_02249184
	.public ov71_02249208
	.public ov71_02249254
	.public ov71_02249260
	.public ov71_0224926C
	.public ov71_022492FC
	.public ov71_02249358
	.public ov71_022493B8
	.public ov71_02249414
	.public ov71_02249460
	.public ov71_022494A0
	.public ov71_022494D0
	.public ov71_02249500
	.public ov71_02249538
	.public ov71_02249558
	.public ov71_022495A0
	.public ov71_02249670
	.public ov71_022497C8
	.public ov71_022497E0
	.public ov71_022498E0
	.public ov71_022498F0
	.public ov71_02249970
	.public ov71_02249988
	.public ov71_02249990
	.public ov71_022499A4
	.public ov71_02249A50
	.public ov71_02249A60
	.public ov71_02249A98
	.public ov71_02249B64
	.public ov71_02249C90
	.public ov71_02249C98
	.public ov71_02249CF0
	.public ov71_02249D14
	.public ov71_02249D28
	.public ov71_02249D58
	.public ov71_02249D80
	.public ov71_02249E24
	.public ov71_02249E6C
	.public ov71_0224A080
	.public ov71_0224A0B8
	.public ov71_0224A0F0
	.public ov71_0224A12C
	.public ov71_0224A15C
	.public ov71_0224A18C
	.public ov71_0224A1C4
	.public ov71_0224A278
	.public ov71_0224A3D8
	.public ov71_0224A3F0
	.public ov71_0224A500
	.public ov71_0224A510
	.public ov71_0224A590
	.public ov71_0224A5A8
	.public ov71_0224A5B0
	.public ov71_0224A5C4
	.public ov71_0224A684
	.public ov71_0224A694
	.public ov71_0224A6D8
	.public ov71_0224A7D0
	.public ov71_0224A8A8
	.public ov71_0224A8B0
	.public ov71_0224A920
	.public ov71_0224A954
	.public ov71_0224A98C
	.public ov71_0224A9C4
	.public ov71_0224A9F8
	.public ov71_0224AA28
	.public ov71_0224AAF8
	.public ov71_0224AB7C
	.public ov71_0224ADB0
	.public ov71_0224ADE4
	.public ov71_0224AEF4
	.public ov71_0224AF08
	.public ov71_0224AF58
	.public ov71_0224AFB8
	.public ov71_0224AFD4
	.public ov71_0224B028
	.public ov71_0224B068
	.public ov71_0224B084
	.public ov71_0224B0E8
	.public ov71_0224B11C
	.public ov71_0224B138
	.public ov71_0224B198
	.public ov71_0224B1FC
	.public ov71_0224B234
	.public ov71_0224B280
	.public ov71_0224B450
	.public ov71_0224B47C
	.public ov71_0224B57C
	.public ov71_0224B6F0
	.public ov71_0224B720
	.public ov71_0224B7EC
	.public ov71_0224B848
	.public ov71_0224B8EC
	.public ov71_0224B910
	.public ov71_0224B960
	.public ov71_0224B970
	.public ov71_0224B990
	.public ov71_0224B9CC
	.public ov71_0224BA48
	.public ov71_0224BA64
	.public ov71_0224BAA0
	.public ov71_0224BABC
	.public ov71_0224BBDC
	.public ov71_0224BBEC
	.public ov71_0224BBF0
	.public ov71_0224BBF4
	.public ov71_0224BBF8
	.public ov71_0224BC5C
	.public ov71_0224BC64
	.public ov71_0224BC74
	.public ov71_0224BC84
	.public ov71_0224BCA0
	.public ov71_0224BCBC
	.public ov71_0224BCE4
	.public ov71_0224BCEC
	.public ov71_0224BCFC
	.public ov71_0224BD0C
	.public ov71_0224BD1C
	.public ov71_0224BD38
	.public ov71_0224BD54
	.public ov71_0224BD7C
	.public ov71_0224BD84
	.public ov71_0224BD94
	.public ov71_0224BDA4
	.public ov71_0224BDC0
	.public ov71_0224BDE8
	.public ov71_0224BDF0
	.public ov71_0224BE00
	.public ov71_0224BE1C
	.public ov71_0224BE38
	.public ov71_0224BE54
	.public ov71_0224BE7C
	.public ov71_0224BE84
	.public ov71_0224BE94
	.public ov71_0224BEA4
	.public ov71_0224BEC0
	.public ov71_0224BEE8
	.public ov71_0224BEF0
	.public ov71_0224BEFC
	.public ov71_0224BF0C
	.public ov71_0224BF1C
	.public ov71_0224BF38
	.public ov71_0224BF54
	.public ov71_0224BF7C
	.public ov71_0224BF84
	.public ov71_0224BF94
	.public ov71_0224BFA4
	.public ov71_0224BFC0
	.public ov71_0224BFDC
	.public ov71_0224C044
	.public ov71_0224C0C4
	.public ov71_0224C0C8
	.public ov71_0224C0D0
	.include "overlay_71.inc"
	.include "global.inc"

	.text
	.public ov71_02246B28
	.public ov71_02246D40
	.public ov71_02246E84
	.public ov71_02246F60
	.public ov71_022472FC
	.public ov71_02247384
	.public ov71_02247388
	.public ov71_0224738C
	.public ov71_02247390
	.public ov71_02247398
	.public ov71_022473A0
	.public ov71_022473A8
	.public ov71_022473B0
	.public ov71_022473BC
	.public ov71_022473C4
	.public ov71_022473D0
	.public ov71_022473DC
	.public ov71_022473E4
	.public ov71_022473F0
	.public ov71_02247424
	.public ov71_022475F8
	.public ov71_022476B4
	.public ov71_022476C4
	.public ov71_022476D4
	.public ov71_022476EC
	.public ov71_02247704
	.public ov71_02247730
	.public ov71_022477EC
	.public ov71_0224780C
	.public ov71_0224781C
	.public ov71_0224782C
	.public ov71_0224783C
	.public ov71_022478B8
	.public ov71_02247990
	.public ov71_02247C34
	.public ov71_0224809C
	.public ov71_02248110
	.public ov71_02248120
	.public ov71_022481C8
	.public ov71_022481D8
	.public ov71_022481EC
	.public ov71_022483AC
	.public ov71_022483E4
	.public ov71_022489F8
	.public ov71_02248B24
	.public ov71_02248B54
	.public ov71_02248CF4
	.public ov71_02248E04
	.public ov71_02249254
	.public ov71_02249260
	.public ov71_022494A0
	.public ov71_022494D0
	.public ov71_02249500
	.public ov71_02249538
	.public ov71_022497C8
	.public ov71_022498E0
	.public ov71_02249970
	.public ov71_02249988
	.public ov71_02249990
	.public ov71_02249A50
	.public ov71_02249C90
	.public ov71_02249CF0
	.public ov71_02249D14
	.public ov71_02249D28
	.public ov71_02249D58
	.public ov71_0224A080
	.public ov71_0224A0B8
	.public ov71_0224A12C
	.public ov71_0224A15C
	.public ov71_0224A3D8
	.public ov71_0224A500
	.public ov71_0224A590
	.public ov71_0224A5A8
	.public ov71_0224A5B0
	.public ov71_0224A684
	.public ov71_0224A8A8
	.public ov71_0224A920
	.public ov71_0224A954
	.public ov71_0224A98C
	.public ov71_0224A9F8
	.public ov71_0224ADB0
	.public ov71_0224AEF4
	.public ov71_0224AFB8
	.public ov71_0224B068
	.public ov71_0224B0E8
	.public ov71_0224B11C
	.public ov71_0224B450
	.public ov71_0224B6F0
	.public ov71_0224B8EC
	.public ov71_0224B960
	.public ov71_0224B970
	.public ov71_0224B990
	.public ov71_0224BA48
	.public ov71_0224BAA0

	thumb_func_start ov71_0224A694
ov71_0224A694: ; 0x0224A694
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, [sp, #0x18]
	add r4, r1, #0
	add r6, r2, #0
	add r7, r3, #0
	str r0, [sp]
	cmp r0, #0
	beq _0224A6D4
	ldr r0, [r5, #0x44]
	ldr r1, [sp]
	sub r0, r4, r0
	bl _s32_div_f
	str r0, [r5, #0x4c]
	ldr r0, [r5, #0x48]
	ldr r1, [sp]
	sub r0, r6, r0
	bl _s32_div_f
	str r0, [r5, #0x50]
	ldr r0, [r5, #0x5c]
	ldr r1, [sp]
	sub r0, r7, r0
	bl _s32_div_f
	str r0, [r5, #0x60]
	str r4, [r5, #0x54]
	str r6, [r5, #0x58]
	ldr r0, [sp, #0x18]
	str r7, [r5, #0x64]
	str r0, [r5, #0x68]
_0224A6D4:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov71_0224A694


	thumb_func_start ov71_0224A6D8
ov71_0224A6D8: ; 0x0224A6D8
	push {r4, r5, r6, lr}
	add r5, r0, #0
	ldr r0, _0224A7CC ; =_0224C020
	ldr r0, [r0]
	cmp r0, #0
	beq _0224A7BA
	add r0, r5, #0
	add r0, #0x78
	ldrh r0, [r0]
	mov r1, #0xb6
	bl _s32_div_f
	add r4, r0, #0
	mov r0, #0x5a
	lsl r0, r0, #2
	cmp r4, r0
	blt _0224A6FC
	sub r4, r4, r0
_0224A6FC:
	mov r0, #0x78
	ldrsh r1, [r5, r0]
	mov r0, #0x7a
	ldrsh r0, [r5, r0]
	sub r1, r1, r0
	add r0, r5, #0
	add r0, #0x78
	strh r1, [r0]
	ldr r0, [r5, #0x68]
	cmp r0, #0
	beq _0224A744
	sub r0, r0, #1
	str r0, [r5, #0x68]
	beq _0224A730
	ldr r1, [r5, #0x44]
	ldr r0, [r5, #0x4c]
	add r0, r1, r0
	str r0, [r5, #0x44]
	ldr r1, [r5, #0x48]
	ldr r0, [r5, #0x50]
	add r0, r1, r0
	str r0, [r5, #0x48]
	ldr r1, [r5, #0x5c]
	ldr r0, [r5, #0x60]
	add r0, r1, r0
	b _0224A73A
_0224A730:
	ldr r0, [r5, #0x54]
	str r0, [r5, #0x44]
	ldr r0, [r5, #0x58]
	str r0, [r5, #0x48]
	ldr r0, [r5, #0x64]
_0224A73A:
	str r0, [r5, #0x5c]
	ldr r0, [r5, #0xc]
	ldr r1, [r5, #0x5c]
	bl ov71_02247730
_0224A744:
	lsl r0, r4, #0x10
	ldr r6, [r5, #0x44]
	lsr r0, r0, #0x10
	bl GF_CosDegNoWrap
	asr r1, r0, #0x1f
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	str r1, [r5, #0x1c]
	lsl r0, r4, #0x10
	ldr r6, [r5, #0x48]
	lsr r0, r0, #0x10
	bl GF_SinDegNoWrap
	asr r1, r0, #0x1f
	asr r3, r6, #0x1f
	add r2, r6, #0
	bl _ll_mul
	mov r2, #2
	mov r3, #0
	lsl r2, r2, #0xa
	add r2, r0, r2
	adc r1, r3
	lsl r0, r1, #0x14
	lsr r1, r2, #0xc
	orr r1, r0
	str r1, [r5, #0x20]
	add r1, r5, #0
	str r3, [r5, #0x24]
	mov r0, #0x34
	ldrsh r2, [r5, r0]
	mov r0, #3
	lsl r0, r0, #8
	sub r0, r2, r0
	strh r0, [r5, #0x34]
	ldr r0, [r5, #0xc]
	add r1, #0x34
	bl ov71_022476EC
	add r0, r5, #0
	add r1, r5, #0
	add r5, #0x28
	add r0, #0x1c
	add r1, #0x10
	add r2, r5, #0
	bl VEC_Add
	pop {r4, r5, r6, pc}
_0224A7BA:
	add r2, r5, #0
	add r2, #0x10
	ldmia r2!, {r0, r1}
	add r5, #0x28
	stmia r5!, {r0, r1}
	ldr r0, [r2]
	str r0, [r5]
	pop {r4, r5, r6, pc}
	nop
_0224A7CC: .word _0224C020
	thumb_func_end ov71_0224A6D8


	thumb_func_start ov71_0224A7D0
ov71_0224A7D0: ; 0x0224A7D0
	push {r4, lr}
	add r4, r1, #0
	ldr r1, [r4, #0x74]
	cmp r1, #0x46
	bge _0224A7DE
	add r1, r1, #1
	str r1, [r4, #0x74]
_0224A7DE:
	ldr r1, [r4, #0x6c]
	cmp r1, #3
	bhi _0224A8A4
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0224A7F0: ; jump table
	.short _0224A7F8 - _0224A7F0 - 2 ; case 0
	.short _0224A81E - _0224A7F0 - 2 ; case 1
	.short _0224A858 - _0224A7F0 - 2 ; case 2
	.short _0224A892 - _0224A7F0 - 2 ; case 3
_0224A7F8:
	add r0, r4, #0
	bl ov71_0224A6D8
	add r1, r4, #0
	ldr r0, [r4, #0xc]
	add r1, #0x28
	bl ov71_022476C4
	ldr r0, [r4, #0x74]
	add r0, r0, #1
	str r0, [r4, #0x74]
	cmp r0, #0xc
	blt _0224A8A4
	mov r0, #0
	str r0, [r4, #0x74]
	ldr r0, [r4, #0x6c]
	add r0, r0, #1
	str r0, [r4, #0x6c]
	pop {r4, pc}
_0224A81E:
	ldr r0, [r4, #0xc]
	bl ov71_02247738
	cmp r0, #0
	bne _0224A836
	ldr r0, [r4]
	bl ov71_0224A8A8
	ldr r0, [r4, #0x6c]
	add r0, r0, #1
	str r0, [r4, #0x6c]
	pop {r4, pc}
_0224A836:
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x3c]
	add r0, r1, r0
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x40]
	add r0, r1, r0
	str r0, [r4, #0x18]
	add r0, r4, #0
	bl ov71_0224A6D8
	ldr r0, [r4, #0xc]
	add r4, #0x28
	add r1, r4, #0
	bl ov71_022476C4
	pop {r4, pc}
_0224A858:
	ldr r1, [r4, #0x14]
	ldr r0, [r4, #0x3c]
	add r0, r1, r0
	str r0, [r4, #0x14]
	ldr r1, [r4, #0x18]
	ldr r0, [r4, #0x40]
	add r0, r1, r0
	str r0, [r4, #0x18]
	add r0, r4, #0
	bl ov71_0224A6D8
	add r1, r4, #0
	ldr r0, [r4, #0xc]
	add r1, #0x28
	bl ov71_022476C4
	ldr r0, [r4, #0x74]
	cmp r0, #0x46
	blt _0224A8A4
	ldr r0, [r4, #0xc]
	mov r1, #0
	bl ov71_02247704
	mov r0, #0
	str r0, [r4, #0x70]
	ldr r0, [r4, #0x6c]
	add r0, r0, #1
	str r0, [r4, #0x6c]
	pop {r4, pc}
_0224A892:
	ldr r1, [r4, #0x70]
	add r1, r1, #1
	str r1, [r4, #0x70]
	cmp r1, #8
	ble _0224A8A4
	mov r1, #0
	str r1, [r4, #4]
	bl SysTask_Destroy
_0224A8A4:
	pop {r4, pc}
	.balign 4, 0
	thumb_func_end ov71_0224A7D0
