#include "constants/pokemon.h"
	.include "asm/macros.inc"
	.public WirelessTradeSelectMon_Exit
	.public WirelessTradeSelectMon_Init
	.public WirelessTradeSelectMon_Main
	.public _0221BF9C
	.public _0221BFA0
	.public _0221BFA4
	.public _0221BFA8
	.public _0221BFAC
	.public _0221BFB0
	.public _0221BFB4
	.public _0221BFB8
	.public _0221C080
	.public _0221C084
	.public _0221C088
	.public _0221C1AC
	.public _0221C1B0
	.public _0221C1B4
	.public _0221C1B8
	.public _0221C1BC
	.public _0221C1C0
	.public _0221C240
	.public _0221C244
	.public _0221C248
	.public _0221C24C
	.public _0221C26E
	.public _0221C270
	.public _0221C284
	.public _0221C28A
	.public _0221C28C
	.public _0221C298
	.public _0221C2A8
	.public _0221C2B0
	.public _0221C2B8
	.public _0221C2D6
	.public _0221C2F4
	.public _0221C330
	.public _0221C380
	.public _0221C39C
	.public _0221C3AA
	.public _0221C3B4
	.public _0221C3CA
	.public _0221C3F0
	.public _0221C412
	.public _0221C430
	.public _0221C466
	.public _0221C482
	.public _0221C48A
	.public _0221C51A
	.public _0221C542
	.public _0221C558
	.public _0221C578
	.public _0221C584
	.public _0221C59C
	.public _0221C5C0
	.public _0221C5C4
	.public _0221C5C8
	.public _0221C5CC
	.public _0221C5D0
	.public _0221C5D4
	.public _0221C5D8
	.public _0221C5DC
	.public _0221C5F2
	.public _0221C5FE
	.public _0221C626
	.public _0221C64A
	.public _0221C678
	.public _0221C686
	.public _0221C68E
	.public _0221C6A4
	.public _0221C6A6
	.public _0221C6CA
	.public _0221C6D8
	.public _0221C6E6
	.public _0221C6FA
	.public _0221C70A
	.public _0221C722
	.public _0221C736
	.public _0221C748
	.public _0221C76C
	.public _0221C774
	.public _0221C77A
	.public _0221C77C
	.public _0221C782
	.public _0221C78E
	.public _0221C796
	.public _0221C7B2
	.public _0221C7D0
	.public _0221C7E4
	.public _0221C804
	.public _0221C812
	.public _0221C82E
	.public _0221C83A
	.public _0221C84C
	.public _0221C87E
	.public _0221C88E
	.public _0221C890
	.public _0221C8CA
	.public _0221C90C
	.public _0221C94C
	.public _0221C99E
	.public _0221C9A4
	.public _0221C9A8
	.public _0221C9AC
	.public _0221C9B0
	.public _0221C9B4
	.public _0221C9B8
	.public _0221C9BC
	.public _0221C9C0
	.public _0221C9C4
	.public _0221C9C8
	.public _0221C9CC
	.public _0221C9D0
	.public _0221C9D4
	.public _0221CA50
	.public _0221CA60
	.public _0221CAA6
	.public _0221CACE
	.public _0221CAD4
	.public _0221CAD8
	.public _0221CB48
	.public _0221CB4C
	.public _0221CB50
	.public _0221CB54
	.public _0221CB58
	.public _0221CBD4
	.public _0221CBEE
	.public _0221CBF0
	.public _0221CBF4
	.public _0221CBF8
	.public _0221CBFC
	.public _0221CC00
	.public _0221CC04
	.public _0221CC08
	.public _0221CC22
	.public _0221CC38
	.public _0221CC40
	.public _0221CC46
	.public _0221CC4C
	.public _0221CC72
	.public _0221CCA8
	.public _0221CCAC
	.public _0221CCE4
	.public _0221CD22
	.public _0221CD38
	.public _0221CD4A
	.public _0221CD60
	.public _0221CD64
	.public _0221CD68
	.public _0221CD6C
	.public _0221CD70
	.public _0221CE14
	.public _0221CE18
	.public _0221CE6C
	.public _0221CE84
	.public _0221CE88
	.public _0221CE8C
	.public _0221CE90
	.public _0221CE94
	.public _0221CEA2
	.public _0221CEB4
	.public _0221CFFC
	.public _0221D0C0
	.public _0221D0C4
	.public _0221D0C8
	.public _0221D0CC
	.public _0221D0D0
	.public _0221D0D4
	.public _0221D0D8
	.public _0221D0DC
	.public _0221D0E0
	.public _0221D0E4
	.public _0221D0E8
	.public _0221D1B0
	.public _0221D1B4
	.public _0221D1B8
	.public _0221D1BC
	.public _0221D1C0
	.public _0221D1C4
	.public _0221D232
	.public _0221D250
	.public _0221D256
	.public _0221D3E4
	.public _0221D424
	.public _0221D5C0
	.public _0221D5F8
	.public _0221D6D4
	.public _0221D74C
	.public _0221D76A
	.public _0221D78E
	.public _0221D7B0
	.public _0221D836
	.public _0221D842
	.public _0221D8AC
	.public _0221D8B0
	.public _0221D8B4
	.public _0221D8B8
	.public _0221D8BC
	.public _0221D8C0
	.public _0221D92C
	.public _0221D9EC
	.public _0221DA54
	.public _0221DABA
	.public _0221DB0C
	.public _0221DB94
	.public _0221DBE4
	.public _0221DBE8
	.public _0221DBEC
	.public _0221DBF0
	.public _0221DC08
	.public _0221DC12
	.public _0221DC1C
	.public _0221DC26
	.public _0221DC2C
	.public _0221DC30
	.public _0221DC8E
	.public _0221DC96
	.public _0221DCAA
	.public _0221DCAC
	.public _0221DCB0
	.public _0221DCB4
	.public _0221DCB8
	.public _0221DCD2
	.public _0221DD12
	.public _0221DD20
	.public _0221DD28
	.public _0221DD30
	.public _0221DD46
	.public _0221DD78
	.public _0221DD96
	.public _0221DDAC
	.public _0221DDB0
	.public _0221DDB4
	.public _0221DDB8
	.public _0221DDBC
	.public _0221DDFA
	.public _0221DE00
	.public _0221DE08
	.public _0221DE0C
	.public _0221DE3C
	.public _0221DE50
	.public _0221DE54
	.public _0221DED8
	.public _0221DF52
	.public _0221DF82
	.public _0221DF8E
	.public _0221DF9A
	.public _0221DFA0
	.public _0221DFA4
	.public _0221DFA8
	.public _0221DFAC
	.public _0221DFB0
	.public _0221DFB4
	.public _0221DFE4
	.public _0221E008
	.public _0221E014
	.public _0221E030
	.public _0221E034
	.public _0221E038
	.public _0221E03C
	.public _0221E040
	.public _0221E044
	.public _0221E048
	.public _0221E04C
	.public _0221E09C
	.public _0221E0D6
	.public _0221E130
	.public _0221E134
	.public _0221E138
	.public _0221E13C
	.public _0221E140
	.public _0221E188
	.public _0221E18C
	.public _0221E190
	.public _0221E1C6
	.public _0221E1D0
	.public _0221E218
	.public _0221E250
	.public _0221E258
	.public _0221E25C
	.public _0221E260
	.public _0221E264
	.public _0221E268
	.public _0221E26C
	.public _0221E2B4
	.public _0221E2B8
	.public _0221E2BC
	.public _0221E2D8
	.public _0221E316
	.public _0221E31C
	.public _0221E320
	.public _0221E324
	.public _0221E328
	.public _0221E32C
	.public _0221E386
	.public _0221E390
	.public _0221E398
	.public _0221E3A6
	.public _0221E3AC
	.public _0221E3B0
	.public _0221E3B4
	.public _0221E3B8
	.public _0221E3EE
	.public _0221E3F8
	.public _0221E42C
	.public _0221E450
	.public _0221E458
	.public _0221E45C
	.public _0221E460
	.public _0221E464
	.public _0221E468
	.public _0221E46C
	.public _0221E470
	.public _0221E494
	.public _0221E4C0
	.public _0221E506
	.public _0221E530
	.public _0221E534
	.public _0221E538
	.public _0221E53C
	.public _0221E540
	.public _0221E544
	.public _0221E548
	.public _0221E54C
	.public _0221E550
	.public _0221E554
	.public _0221E580
	.public _0221E5AA
	.public _0221E5EC
	.public _0221E5F0
	.public _0221E5F4
	.public _0221E5F8
	.public _0221E5FC
	.public _0221E632
	.public _0221E63C
	.public _0221E644
	.public _0221E668
	.public _0221E670
	.public _0221E674
	.public _0221E678
	.public _0221E67C
	.public _0221E680
	.public _0221E6B6
	.public _0221E6C0
	.public _0221E6CA
	.public _0221E6EA
	.public _0221E6F0
	.public _0221E708
	.public _0221E70E
	.public _0221E714
	.public _0221E718
	.public _0221E71C
	.public _0221E720
	.public _0221E724
	.public _0221E728
	.public _0221E75A
	.public _0221E770
	.public _0221E77C
	.public _0221E7C2
	.public _0221E7FE
	.public _0221E808
	.public _0221E828
	.public _0221E82E
	.public _0221E838
	.public _0221E83C
	.public _0221E840
	.public _0221E844
	.public _0221E848
	.public _0221E84C
	.public _0221E850
	.public _0221E854
	.public _0221E898
	.public _0221E8CC
	.public _0221E8D0
	.public _0221E8D4
	.public _0221E8D8
	.public _0221E8DC
	.public _0221E8E0
	.public _0221E8E4
	.public _0221E8E8
	.public _0221E908
	.public _0221E90E
	.public _0221E918
	.public _0221E91C
	.public _0221E920
	.public _0221E924
	.public _0221E99C
	.public _0221E9A0
	.public _0221E9A4
	.public _0221EA5C
	.public _0221EA60
	.public _0221EA64
	.public _0221EA68
	.public _0221EA6C
	.public _0221EA70
	.public _0221EA94
	.public _0221EA9E
	.public _0221EAEA
	.public _0221EB32
	.public _0221EB78
	.public _0221EB80
	.public _0221EB84
	.public _0221EB88
	.public _0221EB8C
	.public _0221EB90
	.public _0221EB94
	.public _0221EB98
	.public _0221EBEC
	.public _0221EBF0
	.public _0221EBF4
	.public _0221EC14
	.public _0221EC1A
	.public _0221EC24
	.public _0221EC28
	.public _0221EC2C
	.public _0221EC30
	.public _0221EC46
	.public _0221EC70
	.public _0221EC84
	.public _0221ECBC
	.public _0221ECD0
	.public _0221ED54
	.public _0221ED58
	.public _0221ED5C
	.public _0221ED60
	.public _0221ED64
	.public _0221ED68
	.public _0221ED6C
	.public _0221ED70
	.public _0221ED74
	.public _0221ED78
	.public _0221ED7C
	.public _0221EDF2
	.public _0221EE14
	.public _0221EEE0
	.public _0221EEE8
	.public _0221EEEC
	.public _0221EEF0
	.public _0221EEF4
	.public _0221EEF8
	.public _0221EEFC
	.public _0221EF00
	.public _0221EF04
	.public _0221EF08
	.public _0221EF34
	.public _0221EF80
	.public _0221EFA6
	.public _0221EFB2
	.public _0221F004
	.public _0221F008
	.public _0221F00C
	.public _0221F010
	.public _0221F014
	.public _0221F018
	.public _0221F01C
	.public _0221F020
	.public _0221F024
	.public _0221F0B0
	.public _0221F0B4
	.public _0221F0B8
	.public _0221F0BC
	.public _0221F0C0
	.public _0221F11C
	.public _0221F152
	.public _0221F15C
	.public _0221F17A
	.public _0221F1A4
	.public _0221F1AC
	.public _0221F1C8
	.public _0221F1E4
	.public _0221F1F6
	.public _0221F238
	.public _0221F240
	.public _0221F244
	.public _0221F248
	.public _0221F24C
	.public _0221F250
	.public _0221F254
	.public _0221F29C
	.public _0221F2A0
	.public _0221F2A4
	.public _0221F2DA
	.public _0221F2E4
	.public _0221F2FC
	.public _0221F33E
	.public _0221F344
	.public _0221F348
	.public _0221F34C
	.public _0221F350
	.public _0221F37C
	.public _0221F382
	.public _0221F398
	.public _0221F39C
	.public _0221F3A0
	.public _0221F3A4
	.public _0221F3A8
	.public _0221F3AC
	.public _0221F3E8
	.public _0221F3EC
	.public _0221F3F0
	.public _0221F498
	.public _0221F49C
	.public _0221F4A0
	.public _0221F4A4
	.public _0221F4A8
	.public _0221F4AC
	.public _0221F4F4
	.public _0221F540
	.public _0221F586
	.public _0221F58C
	.public _0221F590
	.public _0221F594
	.public _0221F598
	.public _0221F59C
	.public _0221F614
	.public _0221F62C
	.public _0221F664
	.public _0221F6BC
	.public _0221F70C
	.public _0221F710
	.public _0221F796
	.public _0221F798
	.public _0221F7B8
	.public _0221F7C0
	.public _0221F7C8
	.public _0221F7D2
	.public _0221F7D8
	.public _0221F7DC
	.public _0221F7F6
	.public _0221F80E
	.public _0221F814
	.public _0221F826
	.public _0221F83E
	.public _0221F844
	.public _0221F848
	.public _0221F84C
	.public _0221F886
	.public _0221F888
	.public _0221F88C
	.public _0221F8AC
	.public _0221F8B0
	.public _0221FA3A
	.public _0221FA84
	.public _0221FAD0
	.public _0221FAD4
	.public _0221FAD8
	.public _0221FADC
	.public _0221FAE6
	.public _0221FAF8
	.public _0221FB70
	.public _0221FB8C
	.public _0221FBBA
	.public _0221FBC6
	.public _0221FBFC
	.public _0221FC00
	.public _0221FC04
	.public _0221FC6A
	.public _0221FC7A
	.public _0221FC82
	.public _0221FC9A
	.public _0221FD10
	.public _0221FD14
	.public _0221FD18
	.public _0221FD1C
	.public _0221FD34
	.public ov65_0221BFBC
	.public ov65_0221BFEC
	.public ov65_0221C08C
	.public ov65_0221C1C4
	.public ov65_0221C3DC
	.public ov65_0221C414
	.public ov65_0221C46C
	.public ov65_0221C5E0
	.public ov65_0221C9D8
	.public ov65_0221CA64
	.public ov65_0221CADC
	.public ov65_0221CB5C
	.public ov65_0221CC0C
	.public ov65_0221CCB0
	.public ov65_0221CD0C
	.public ov65_0221CE1C
	.public ov65_0221CE98
	.public ov65_0221CEB8
	.public ov65_0221D0EC
	.public ov65_0221D1C8
	.public ov65_0221D204
	.public ov65_0221D280
	.public ov65_0221D3B8
	.public ov65_0221D3E8
	.public ov65_0221D57C
	.public ov65_0221D5FC
	.public ov65_0221D674
	.public ov65_0221D8C4
	.public ov65_0221D930
	.public ov65_0221DBF4
	.public ov65_0221DC34
	.public ov65_0221DCBC
	.public ov65_0221DCFC
	.public ov65_0221DD34
	.public ov65_0221DDC0
	.public ov65_0221DE24
	.public ov65_0221DEA0
	.public ov65_0221DF1C
	.public ov65_0221DFB8
	.public ov65_0221E06C
	.public ov65_0221E144
	.public ov65_0221E194
	.public ov65_0221E270
	.public ov65_0221E2C0
	.public ov65_0221E354
	.public ov65_0221E3BC
	.public ov65_0221E474
	.public ov65_0221E558
	.public ov65_0221E600
	.public ov65_0221E684
	.public ov65_0221E740
	.public ov65_0221E858
	.public ov65_0221E8EC
	.public ov65_0221E928
	.public ov65_0221E9A8
	.public ov65_0221EA74
	.public ov65_0221EB9C
	.public ov65_0221EBF8
	.public ov65_0221EC34
	.public ov65_0221ED94
	.public ov65_0221EE18
	.public ov65_0221EF0C
	.public ov65_0221F028
	.public ov65_0221F0D8
	.public ov65_0221F120
	.public ov65_0221F258
	.public ov65_0221F2A8
	.public ov65_0221F354
	.public ov65_0221F3B0
	.public ov65_0221F3F4
	.public ov65_0221F4D4
	.public ov65_0221F5A0
	.public ov65_0221F780
	.public ov65_0221F79C
	.public ov65_0221F7E0
	.public ov65_0221F864
	.public ov65_0221F890
	.public ov65_0221F8D0
	.public ov65_0221FAE0
	.public ov65_0221FB4C
	.public ov65_0221FB90
	.public ov65_0221FC08
	.public ov65_0221FC54
	.public ov65_0221FCA0
	.public ov65_0221FD3C
	.public ov65_0221FD48
	.public ov65_0221FD58
	.public ov65_0221FD68
	.public ov65_0221FD6C
	.public ov65_0221FD70
	.public ov65_0221FD80
	.public ov65_0221FD9C
	.public ov65_0221FDB8
	.public ov65_0221FDD4
	.public ov65_0221FDF0
	.public ov65_0221FE0C
	.public ov65_0221FE28
	.public ov65_0221FE44
	.public ov65_0221FE6C
	.public ov65_0221FEA4
	.public ov65_0221FEA8
	.public ov65_0221FEEC
	.public ov65_0221FF4C
	.public ov65_0221FF50
	.public ov65_0221FFB4
	.public ov65_022200EC
	.public ov65_0222010C
	.public ov65_02220144
	.public WirelessTradeSelectMon_Exit
	.public WirelessTradeSelectMon_Init
	.public WirelessTradeSelectMon_Main
	.public _0221FD34
	.public ov65_0221BFBC
	.public ov65_0221BFEC
	.public ov65_0221C08C
	.public ov65_0221C1C4
	.public ov65_0221C3DC
	.public ov65_0221C414
	.public ov65_0221C46C
	.public ov65_0221C5E0
	.public ov65_0221C9D8
	.public ov65_0221CA64
	.public ov65_0221CADC
	.public ov65_0221CB5C
	.public ov65_0221CC0C
	.public ov65_0221CCB0
	.public ov65_0221CD0C
	.public ov65_0221CE1C
	.public ov65_0221CE98
	.public ov65_0221CEB8
	.public ov65_0221D0EC
	.public ov65_0221D1C8
	.public ov65_0221D204
	.public ov65_0221D25C
	.public ov65_0221D280
	.public ov65_0221D3B8
	.public ov65_0221D3E8
	.public ov65_0221D57C
	.public ov65_0221D5FC
	.public ov65_0221D648
	.public ov65_0221D674
	.public ov65_0221D8C4
	.public ov65_0221D930
	.public ov65_0221DBF4
	.public ov65_0221DC34
	.public ov65_0221DCBC
	.public ov65_0221DCFC
	.public ov65_0221DD34
	.public ov65_0221DDC0
	.public ov65_0221DE10
	.public ov65_0221DE24
	.public ov65_0221DE58
	.public ov65_0221DE64
	.public ov65_0221DE8C
	.public ov65_0221DEA0
	.public ov65_0221DF0C
	.public ov65_0221DF1C
	.public ov65_0221DFB8
	.public ov65_0221E050
	.public ov65_0221E06C
	.public ov65_0221E144
	.public ov65_0221E194
	.public ov65_0221E270
	.public ov65_0221E2C0
	.public ov65_0221E330
	.public ov65_0221E354
	.public ov65_0221E3BC
	.public ov65_0221E474
	.public ov65_0221E558
	.public ov65_0221E600
	.public ov65_0221E684
	.public ov65_0221E72C
	.public ov65_0221E740
	.public ov65_0221E858
	.public ov65_0221E8EC
	.public ov65_0221E928
	.public ov65_0221E9A8
	.public ov65_0221EA74
	.public ov65_0221EB9C
	.public ov65_0221EBF8
	.public ov65_0221EC34
	.public ov65_0221ED80
	.public ov65_0221ED94
	.public ov65_0221EE18
	.public ov65_0221EF0C
	.public ov65_0221F028
	.public ov65_0221F0C4
	.public ov65_0221F0D8
	.public ov65_0221F120
	.public ov65_0221F258
	.public ov65_0221F2A8
	.public ov65_0221F354
	.public ov65_0221F3B0
	.public ov65_0221F3F4
	.public ov65_0221F4B0
	.public ov65_0221F4D4
	.public ov65_0221F5A0
	.public ov65_0221F714
	.public ov65_0221F748
	.public ov65_0221F760
	.public ov65_0221F780
	.public ov65_0221F79C
	.public ov65_0221F7E0
	.public ov65_0221F850
	.public ov65_0221F864
	.public ov65_0221F890
	.public ov65_0221F8B4
	.public ov65_0221F8D0
	.public ov65_0221FAE0
	.public ov65_0221FB4C
	.public ov65_0221FB90
	.public ov65_0221FC08
	.public ov65_0221FC54
	.public ov65_0221FCA0
	.public ov65_0221FD20
	.include "overlay_65.inc"
	.include "global.inc"

	.text
	.public ov65_0221D25C
	.public ov65_0221D648
	.public ov65_0221DE10
	.public ov65_0221DE58
	.public ov65_0221DE64
	.public ov65_0221DE8C
	.public ov65_0221DF0C
	.public ov65_0221E050
	.public ov65_0221E330
	.public ov65_0221E72C
	.public ov65_0221ED80
	.public ov65_0221F0C4
	.public ov65_0221F4B0
	.public ov65_0221F714
	.public ov65_0221F748
	.public ov65_0221F760
	.public ov65_0221F850
	.public ov65_0221F8B4
	.public ov65_0221FD20

	thumb_func_start WirelessTradeSelectMon_Init
WirelessTradeSelectMon_Init: ; 0x0221BE20
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r6, r0, #0
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	bl HBlankInterruptDisable
	bl GfGfx_DisableEngineAPlanes
	bl GfGfx_DisableEngineBPlanes
	mov r2, #1
	lsl r2, r2, #0x1a
	ldr r1, [r2]
	ldr r0, _0221BF9C ; =0xFFFFE0FF
	and r1, r0
	str r1, [r2]
	ldr r2, _0221BFA0 ; =0x04001000
	ldr r1, [r2]
	and r0, r1
	str r0, [r2]
	ldr r2, _0221BFA4 ; =0x00070FA0
	mov r0, #3
	mov r1, #0x1a
	bl Heap_Create
	mov r0, #4
	mov r1, #0x1a
	bl FontID_Alloc
	mov r0, #0x34
	mov r1, #0x1a
	bl NARC_New
	add r5, r0, #0
	ldr r1, _0221BFA8 ; =0x000036CC
	add r0, r6, #0
	mov r2, #0x1a
	bl OverlayManager_CreateAndGetData
	add r4, r0, #0
	ldr r2, _0221BFA8 ; =0x000036CC
	mov r0, #0
	add r1, r4, #0
	bl MIi_CpuClearFast
	mov r0, #0x1a
	bl BgConfig_Alloc
	mov r1, #6
	lsl r1, r1, #6
	str r0, [r4, r1]
	mov r0, #0xc
	mov r1, #0x16
	mov r2, #0x1a
	bl MessageFormat_New_Custom
	mov r1, #0x61
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x1a
	bl MessageFormat_New
	mov r1, #0x62
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0x1a
	bl MessageFormat_New
	mov r1, #0x63
	lsl r1, r1, #2
	str r0, [r4, r1]
	mov r0, #0
	mov r1, #0x1b
	mov r2, #0xb7
	mov r3, #0x1a
	bl NewMsgDataFromNarc
	mov r1, #0x19
	lsl r1, r1, #4
	str r0, [r4, r1]
	mov r0, #0
	str r0, [r4, #0x4c]
	add r0, r4, #0
	add r1, r6, #0
	bl ov65_0221D0EC
	mov r0, #4
	mov r1, #8
	bl SetKeyRepeatTimers
	bl ov65_0221CE98
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ov65_0221CEB8
	mov r0, #0x10
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x1a
	str r0, [sp, #8]
	mov r0, #0
	add r2, r1, #0
	add r3, r0, #0
	bl BeginNormalPaletteFade
	add r0, r4, #0
	add r1, r5, #0
	bl ov65_0221D280
	ldr r0, _0221BFAC ; =ov65_0221CE1C
	add r1, r4, #0
	bl Main_SetVBlankIntrCB
	bl ov65_0221D3B8
	add r0, r4, #0
	add r1, r5, #0
	bl ov65_0221D3E8
	add r0, r4, #0
	bl ov65_0221D930
	mov r0, #6
	ldr r2, [r4, #8]
	lsl r0, r0, #6
	ldr r1, _0221BFB0 ; =0x00000444
	ldr r0, [r4, r0]
	ldr r2, [r2, #0x18]
	add r1, r4, r1
	bl ov65_0221F8D0
	ldr r0, [r4, #8]
	add r1, r4, #0
	ldr r0, [r0]
	str r0, [r4]
	bl sub_0208F7E0
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221BFB4 ; =0x000005B4
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0x14
	mov r2, #1
	bl ov65_0221FB90
	ldr r0, [r4]
	bl sub_0208F658
	mov r0, #0
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	mov r1, #6
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	mov r0, #0x1a
	bl sub_020399FC
	bl sub_0203A880
	bl IsNighttime
	ldr r1, _0221BFB8 ; =0x00000427
	mov r0, #0
	bl sub_02055198
	ldr r0, _0221BFB8 ; =0x00000427
	bl sub_02005448
	add r0, r5, #0
	bl NARC_Delete
	mov r0, #1
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	nop
_0221BF9C: .word 0xFFFFE0FF
_0221BFA0: .word 0x04001000
_0221BFA4: .word 0x00070FA0
_0221BFA8: .word 0x000036CC
_0221BFAC: .word ov65_0221CE1C
_0221BFB0: .word 0x00000444
_0221BFB4: .word 0x000005B4
_0221BFB8: .word 0x00000427
	thumb_func_end WirelessTradeSelectMon_Init


	thumb_func_start ov65_0221BFBC
ov65_0221BFBC: ; 0x0221BFBC
	push {r4, r5, r6, lr}
	add r5, r1, #0
	ldr r1, [sp, #0x10]
	add r4, r2, #0
	lsl r1, r1, #4
	add r1, #0x92
	mov r2, #2
	ldr r0, [r0, #0x14]
	add r6, r3, #0
	lsl r1, r1, #5
	lsl r2, r2, #8
	bl GX_LoadOBJ
	add r0, r5, #0
	add r1, r4, #0
	add r2, r6, #0
	bl GetMonIconPaletteEx
	add r1, r0, #0
	ldr r0, [sp, #0x14]
	add r1, #0xa
	bl Sprite_SetPalOffset
	pop {r4, r5, r6, pc}
	thumb_func_end ov65_0221BFBC


	thumb_func_start ov65_0221BFEC
ov65_0221BFEC: ; 0x0221BFEC
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r0, #0
	bl sub_0203769C
	bl sub_02034818
	add r4, r0, #0
	bl sub_0203769C
	mov r1, #1
	eor r0, r1
	bl sub_02034818
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #0x1a
	bl PlayerProfile_GetPlayerName_NewString
	add r4, r0, #0
	add r0, r6, #0
	mov r1, #0x1a
	bl PlayerProfile_GetPlayerName_NewString
	add r6, r0, #0
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r5, r0]
	mov r1, #0x32
	bl NewString_ReadMsgData
	add r7, r0, #0
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _0221C080 ; =0x00000444
	add r1, r4, #0
	add r0, r5, r0
	mov r2, #0xa
	mov r3, #0
	bl ov65_0221FB4C
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _0221C084 ; =0x00000454
	add r1, r6, #0
	add r0, r5, r0
	mov r2, #0xa
	mov r3, #0
	bl ov65_0221FB4C
	mov r0, #1
	str r0, [sp]
	str r0, [sp, #4]
	ldr r0, _0221C088 ; =0x000004A4
	add r1, r7, #0
	add r0, r5, r0
	mov r2, #5
	mov r3, #0
	bl ov65_0221FB4C
	add r0, r7, #0
	bl String_Delete
	add r0, r6, #0
	bl String_Delete
	add r0, r4, #0
	bl String_Delete
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221C080: .word 0x00000444
_0221C084: .word 0x00000454
_0221C088: .word 0x000004A4
	thumb_func_end ov65_0221BFEC


	thumb_func_start ov65_0221C08C
ov65_0221C08C: ; 0x0221C08C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #0x34
	mov r1, #0x1a
	bl NARC_New
	add r4, r0, #0
	bl ov65_0221CE98
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl ov65_0221CEB8
	add r0, r5, #0
	add r1, r4, #0
	bl ov65_0221D280
	add r0, r5, #0
	bl ov65_0221C1C4
	add r0, r5, #0
	bl ov65_0221BFEC
	ldr r0, [r5, #8]
	ldr r0, [r0, #0x18]
	bl Options_GetFrame
	lsl r0, r0, #0x18
	lsr r0, r0, #0x18
	str r0, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r2, _0221C1AC ; =0x000003D9
	mov r1, #0
	mov r3, #0xa
	bl LoadUserFrameGfx2
	mov r1, #0
	str r1, [sp]
	mov r0, #0x1a
	str r0, [sp, #4]
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	ldr r2, _0221C1B0 ; =0x000003F7
	mov r3, #0xb
	bl LoadUserFrameGfx1
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r5, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221C1B4 ; =0x00000594
	ldr r3, [r5, r3]
	add r0, r5, r0
	mov r1, #0xf
	mov r2, #1
	bl ov65_0221FB90
	mov r0, #4
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #5
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	mov r0, #0
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #1
	add r1, r0, #0
	bl ToggleBgLayer
	mov r0, #2
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #3
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	bl ov65_0221D3B8
	add r0, r5, #0
	add r1, r4, #0
	bl ov65_0221D3E8
	add r0, r5, #0
	bl ov65_0221D930
	ldr r0, _0221C1B8 ; =0x00002224
	mov r1, #0
	ldr r0, [r5, r0]
	add r2, r5, #0
	bl ov65_0221C46C
	ldr r0, _0221C1BC ; =0x00002228
	mov r1, #6
	ldr r0, [r5, r0]
	add r2, r5, #0
	bl ov65_0221C46C
	mov r0, #0xd1
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xd2
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _0221C1C0 ; =ov65_0221CE1C
	add r1, r5, #0
	bl Main_SetVBlankIntrCB
	add r0, r4, #0
	bl NARC_Delete
	add sp, #8
	pop {r3, r4, r5, pc}
	nop
_0221C1AC: .word 0x000003D9
_0221C1B0: .word 0x000003F7
_0221C1B4: .word 0x00000594
_0221C1B8: .word 0x00002224
_0221C1BC: .word 0x00002228
_0221C1C0: .word ov65_0221CE1C
	thumb_func_end ov65_0221C08C


	thumb_func_start ov65_0221C1C4
ov65_0221C1C4: ; 0x0221C1C4
	push {r3, r4, r5, lr}
	add r5, r0, #0
	mov r0, #0x61
	ldr r1, _0221C240 ; =0x00002224
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #0
	bl ov65_0221C3DC
	mov r0, #0x61
	ldr r1, _0221C244 ; =0x00002228
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r1, [r5, r1]
	mov r2, #6
	bl ov65_0221C3DC
	mov r0, #0
	mov r2, #0x61
	str r0, [sp]
	lsl r2, r2, #2
	ldr r3, _0221C240 ; =0x00002224
	ldr r0, _0221C248 ; =0x000004B4
	ldr r1, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	ldr r3, [r5, r3]
	add r0, r5, r0
	bl ov65_0221C414
	mov r0, #6
	mov r2, #0x61
	str r0, [sp]
	lsl r2, r2, #2
	ldr r3, _0221C244 ; =0x00002228
	ldr r0, _0221C24C ; =0x00000514
	ldr r1, [r5, r2]
	add r2, #0xc
	ldr r2, [r5, r2]
	ldr r3, [r5, r3]
	add r0, r5, r0
	bl ov65_0221C414
	ldr r0, _0221C240 ; =0x00002224
	ldr r0, [r5, r0]
	bl Party_GetCount
	add r4, r0, #0
	ldr r0, _0221C244 ; =0x00002228
	ldr r0, [r5, r0]
	bl Party_GetCount
	add r2, r0, #0
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	add r1, r4, #0
	bl ov65_0221D25C
	pop {r3, r4, r5, pc}
	nop
_0221C240: .word 0x00002224
_0221C244: .word 0x00002228
_0221C248: .word 0x000004B4
_0221C24C: .word 0x00000514
	thumb_func_end ov65_0221C1C4


	thumb_func_start WirelessTradeSelectMon_Main
WirelessTradeSelectMon_Main: ; 0x0221C250
	push {r3, r4, r5, r6, lr}
	sub sp, #0xc
	add r5, r1, #0
	bl OverlayManager_GetData
	ldr r1, [r5]
	add r4, r0, #0
	mov r6, #0
	cmp r1, #0
	beq _0221C270
	cmp r1, #1
	beq _0221C284
	cmp r1, #2
	bne _0221C26E
	b _0221C3AA
_0221C26E:
	b _0221C3B4
_0221C270:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221C28A
	mov r0, #1
	str r0, [r5]
	add r0, r4, #0
	bl ov65_0221BFEC
	b _0221C3B4
_0221C284:
	ldr r1, [r4, #0x54]
	cmp r1, #7
	bls _0221C28C
_0221C28A:
	b _0221C3B4
_0221C28C:
	add r1, r1, r1
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0221C298: ; jump table
	.short _0221C2A8 - _0221C298 - 2 ; case 0
	.short _0221C2B0 - _0221C298 - 2 ; case 1
	.short _0221C2B8 - _0221C298 - 2 ; case 2
	.short _0221C2D6 - _0221C298 - 2 ; case 3
	.short _0221C2F4 - _0221C298 - 2 ; case 4
	.short _0221C330 - _0221C298 - 2 ; case 5
	.short _0221C380 - _0221C298 - 2 ; case 6
	.short _0221C39C - _0221C298 - 2 ; case 7
_0221C2A8:
	bl ov65_0221C5E0
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C2B0:
	bl ov65_0221CC0C
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C2B8:
	mov r0, #8
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x1a
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r6, #0
	add r2, r6, #0
	add r3, r6, #0
	bl BeginNormalPaletteFade
	mov r0, #2
	str r0, [r5]
	b _0221C3B4
_0221C2D6:
	mov r0, #8
	str r0, [sp]
	mov r0, #1
	str r0, [sp, #4]
	mov r0, #0x1a
	str r0, [sp, #8]
	add r0, r6, #0
	add r1, r6, #0
	add r2, r6, #0
	add r3, r6, #0
	bl BeginNormalPaletteFade
	mov r0, #4
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C2F4:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221C3B4
	add r0, r4, #0
	bl ov65_0221CD0C
	add r0, r4, #0
	bl ov65_0221CCB0
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ov65_0221D1C8
	mov r0, #1
	str r0, [r4, #0x50]
	mov r0, #5
	str r0, [r4, #0x54]
	add r0, r4, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #6
	bl _s32_div_f
	add r1, r0, #0
	add r0, r4, #0
	bl ov65_0221E06C
	b _0221C3B4
_0221C330:
	ldr r0, [r4, #0x4c]
	bl OverlayManager_Run
	cmp r0, #0
	beq _0221C3B4
	ldr r0, [r4, #0x4c]
	bl OverlayManager_Delete
	add r0, r4, #0
	bl ov65_0221C08C
	add r0, r6, #0
	str r0, [r4, #0x50]
	add r0, r4, #0
	add r0, #0x20
	ldrb r2, [r0]
	ldr r1, [r4, #0x48]
	mov r0, #6
	mul r0, r1
	add r1, r2, r0
	add r0, r4, #0
	add r0, #0x94
	str r1, [r0]
	add r0, r4, #0
	bl ov65_0221CB5C
	add r0, r4, #0
	mov r1, #0xd1
	add r0, #0x94
	lsl r1, r1, #2
	ldr r0, [r0]
	ldr r1, [r4, r1]
	add r2, r6, #0
	bl ov65_0221DD34
	bl sub_0203A880
	mov r0, #6
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C380:
	mov r0, #8
	str r0, [sp]
	mov r1, #1
	str r1, [sp, #4]
	mov r0, #0x1a
	str r0, [sp, #8]
	add r0, r6, #0
	add r2, r1, #0
	add r3, r6, #0
	bl BeginNormalPaletteFade
	mov r0, #7
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C39C:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221C3B4
	mov r0, #1
	str r0, [r4, #0x54]
	b _0221C3B4
_0221C3AA:
	bl IsPaletteFadeFinished
	cmp r0, #0
	beq _0221C3B4
	mov r6, #1
_0221C3B4:
	ldr r0, [r4, #0x50]
	cmp r0, #0
	bne _0221C3CA
	add r0, r4, #0
	bl ov65_0221F714
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl SpriteList_RenderAndAnimateSprites
_0221C3CA:
	mov r1, #6
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	mov r0, #0x1a
	bl sub_020399FC
	add r0, r6, #0
	add sp, #0xc
	pop {r3, r4, r5, r6, pc}
	thumb_func_end WirelessTradeSelectMon_Main


	thumb_func_start ov65_0221C3DC
ov65_0221C3DC: ; 0x0221C3DC
	push {r3, r4, r5, r6, r7, lr}
	add r5, r1, #0
	add r7, r0, #0
	add r0, r5, #0
	add r6, r2, #0
	mov r4, #0
	bl Party_GetCount
	cmp r0, #0
	ble _0221C412
_0221C3F0:
	add r0, r5, #0
	add r1, r4, #0
	bl Party_GetMonByIndex
	bl Mon_GetBoxMon
	add r2, r0, #0
	add r0, r7, #0
	add r1, r4, r6
	bl BufferBoxMonNickname
	add r0, r5, #0
	add r4, r4, #1
	bl Party_GetCount
	cmp r4, r0
	blt _0221C3F0
_0221C412:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end ov65_0221C3DC


	thumb_func_start ov65_0221C414
ov65_0221C414: ; 0x0221C414
	push {r4, r5, r6, r7, lr}
	sub sp, #0x14
	add r5, r0, #0
	add r0, r3, #0
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	str r3, [sp, #0x10]
	ldr r6, [sp, #0x28]
	mov r4, #0
	bl Party_GetCount
	cmp r0, #0
	ble _0221C466
	add r7, r6, #1
_0221C430:
	ldr r0, [sp, #8]
	ldr r1, [sp, #0xc]
	add r2, r7, r4
	mov r3, #0x1a
	bl ReadMsgData_ExpandPlaceholders
	add r6, r0, #0
	mov r0, #1
	str r0, [sp]
	mov r0, #0
	str r0, [sp, #4]
	add r0, r5, #0
	add r1, r6, #0
	mov r2, #8
	mov r3, #0
	bl ov65_0221FB4C
	add r0, r6, #0
	bl String_Delete
	ldr r0, [sp, #0x10]
	add r5, #0x10
	add r4, r4, #1
	bl Party_GetCount
	cmp r4, r0
	blt _0221C430
_0221C466:
	add sp, #0x14
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov65_0221C414


	thumb_func_start ov65_0221C46C
ov65_0221C46C: ; 0x0221C46C
	push {r4, r5, r6, r7, lr}
	sub sp, #0x24
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	str r2, [sp, #0x20]
	mov r7, #0
	bl Party_GetCount
	cmp r0, #0
	bgt _0221C482
	b _0221C584
_0221C482:
	ldr r1, _0221C5C4 ; =0x000007CC
	ldr r0, [sp, #0x20]
	add r0, r0, r1
	str r0, [sp, #0x1c]
_0221C48A:
	ldr r0, [sp, #0xc]
	ldr r2, _0221C5C8 ; =0x000006A2
	add r0, r7, r0
	str r0, [sp, #0x10]
	lsl r0, r0, #2
	str r0, [sp, #0x18]
	ldr r0, [sp, #0x10]
	lsl r1, r0, #4
	ldr r0, [sp, #0x20]
	add r4, r0, r1
	ldr r1, [sp, #0x18]
	ldrb r2, [r4, r2]
	add r5, r0, r1
	ldr r0, _0221C5CC ; =0x0000069C
	ldr r1, _0221C5D0 ; =0x000006A1
	ldrh r0, [r4, r0]
	ldrb r1, [r4, r1]
	bl GetMonIconNaixEx
	add r1, r0, #0
	mov r0, #0x1a
	str r0, [sp]
	ldr r6, [sp, #0x1c]
	ldr r3, [sp, #0x18]
	mov r0, #0x14
	mov r2, #0
	add r3, r6, r3
	bl GfGfxLoader_GetCharData
	ldr r1, _0221C5D4 ; =0x0000079C
	str r0, [r5, r1]
	add r0, r1, #0
	add r0, #0x30
	ldr r0, [r5, r0]
	mov r1, #2
	ldr r0, [r0, #0x14]
	lsl r1, r1, #8
	bl DC_FlushRange
	ldr r0, [sp, #0x10]
	ldr r1, _0221C5CC ; =0x0000069C
	str r0, [sp]
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	ldr r2, _0221C5C8 ; =0x000006A2
	str r0, [sp, #4]
	ldr r3, _0221C5D0 ; =0x000006A1
	ldr r0, _0221C5C4 ; =0x000007CC
	ldrh r1, [r4, r1]
	ldrb r2, [r4, r2]
	ldrb r3, [r4, r3]
	ldr r0, [r5, r0]
	bl ov65_0221BFBC
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	ldr r0, _0221C5D8 ; =0x0000069E
	ldrh r0, [r4, r0]
	cmp r0, #0
	bne _0221C51A
	mov r0, #0xeb
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0221C542
_0221C51A:
	ldr r0, [sp, #0x10]
	lsl r1, r0, #2
	ldr r0, [sp, #0x20]
	add r1, r0, r1
	mov r0, #0xeb
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	str r1, [sp, #0x14]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xeb
	ldr r1, [sp, #0x14]
	lsl r0, r0, #2
	ldr r0, [r1, r0]
	ldr r1, _0221C5D8 ; =0x0000069E
	ldrh r1, [r4, r1]
	add r1, r1, #2
	bl Sprite_SetAnimCtrlSeq
_0221C542:
	ldr r0, _0221C5DC ; =0x000006A8
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0221C558
	mov r0, #0xf7
	lsl r0, r0, #2
	ldr r0, [r5, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	b _0221C578
_0221C558:
	ldr r0, [sp, #0x10]
	lsl r1, r0, #2
	ldr r0, [sp, #0x20]
	add r4, r0, r1
	mov r0, #0xf7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #1
	bl Sprite_SetDrawFlag
	mov r0, #0xf7
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0x15
	bl Sprite_SetAnimCtrlSeq
_0221C578:
	ldr r0, [sp, #8]
	add r7, r7, #1
	bl Party_GetCount
	cmp r7, r0
	blt _0221C48A
_0221C584:
	cmp r7, #6
	bge _0221C5C0
	ldr r0, [sp, #0xc]
	mov r6, #0xeb
	lsl r1, r0, #2
	ldr r0, [sp, #0x20]
	lsl r6, r6, #2
	add r1, r0, r1
	lsl r0, r7, #2
	add r5, r6, #0
	add r4, r1, r0
	add r5, #0x30
_0221C59C:
	mov r0, #0xdf
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r4, r6]
	mov r1, #0
	bl Sprite_SetDrawFlag
	ldr r0, [r4, r5]
	mov r1, #0
	bl Sprite_SetDrawFlag
	add r7, r7, #1
	add r4, r4, #4
	cmp r7, #6
	blt _0221C59C
_0221C5C0:
	add sp, #0x24
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221C5C4: .word 0x000007CC
_0221C5C8: .word 0x000006A2
_0221C5CC: .word 0x0000069C
_0221C5D0: .word 0x000006A1
_0221C5D4: .word 0x0000079C
_0221C5D8: .word 0x0000069E
_0221C5DC: .word 0x000006A8
	thumb_func_end ov65_0221C46C


	thumb_func_start ov65_0221C5E0
ov65_0221C5E0: ; 0x0221C5E0
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #0x10
	add r4, r0, #0
	bl ov65_0221F864
	ldr r0, [r4, #0x58]
	cmp r0, #0x13
	bls _0221C5F2
	b _0221C99E
_0221C5F2:
	add r1, r0, r0
	add r1, pc
	ldrh r1, [r1, #6]
	lsl r1, r1, #0x10
	asr r1, r1, #0x10
	add pc, r1
_0221C5FE: ; jump table
	.short _0221C626 - _0221C5FE - 2 ; case 0
	.short _0221C68E - _0221C5FE - 2 ; case 1
	.short _0221C6D8 - _0221C5FE - 2 ; case 2
	.short _0221C6E6 - _0221C5FE - 2 ; case 3
	.short _0221C6FA - _0221C5FE - 2 ; case 4
	.short _0221C70A - _0221C5FE - 2 ; case 5
	.short _0221C722 - _0221C5FE - 2 ; case 6
	.short _0221C736 - _0221C5FE - 2 ; case 7
	.short _0221C748 - _0221C5FE - 2 ; case 8
	.short _0221C774 - _0221C5FE - 2 ; case 9
	.short _0221C782 - _0221C5FE - 2 ; case 10
	.short _0221C78E - _0221C5FE - 2 ; case 11
	.short _0221C812 - _0221C5FE - 2 ; case 12
	.short _0221C82E - _0221C5FE - 2 ; case 13
	.short _0221C83A - _0221C5FE - 2 ; case 14
	.short _0221C84C - _0221C5FE - 2 ; case 15
	.short _0221C890 - _0221C5FE - 2 ; case 16
	.short _0221C8CA - _0221C5FE - 2 ; case 17
	.short _0221C90C - _0221C5FE - 2 ; case 18
	.short _0221C94C - _0221C5FE - 2 ; case 19
_0221C626:
	mov r0, #0x50
	bl sub_02037AC0
	mov r0, #2
	bl sub_0201A728
	add r0, r4, #0
	bl ov65_0221F760
	ldr r0, [r4, #8]
	mov r5, #0
	ldr r0, [r0, #8]
	bl Party_GetCount
	cmp r0, #0
	ble _0221C686
	mov r7, #0x7b
	lsl r7, r7, #2
_0221C64A:
	ldr r0, [r4, #8]
	add r1, r5, #0
	ldr r0, [r0, #8]
	bl Party_GetMonByIndex
	mov r1, #0xae
	mov r2, #0
	add r6, r0, #0
	bl GetMonData
	cmp r0, r7
	bne _0221C678
	add r0, r6, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	cmp r0, #0
	beq _0221C678
	add r0, r6, #0
	mov r1, #0
	bl Mon_UpdateShayminForm
_0221C678:
	ldr r0, [r4, #8]
	add r5, r5, #1
	ldr r0, [r0, #8]
	bl Party_GetCount
	cmp r5, r0
	blt _0221C64A
_0221C686:
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C68E:
	mov r0, #0x50
	bl sub_02037B38
	cmp r0, #0
	beq _0221C77A
	ldr r0, [r4, #8]
	ldr r0, [r0, #0x30]
	cmp r0, #0
	bne _0221C6A4
	mov r0, #6
	b _0221C6A6
_0221C6A4:
	mov r0, #2
_0221C6A6:
	str r0, [r4, #0x58]
	bl sub_0203769C
	cmp r0, #0
	bne _0221C6CA
	bl LCRandom
	mov r1, #0x3c
	bl _s32_div_f
	lsl r0, r1, #0x10
	lsr r5, r0, #0x10
	bl sub_0203769C
	mov r1, #0x1f
	add r2, r5, #3
	bl ov65_0221DE10
_0221C6CA:
	ldr r0, [r4, #4]
	bl ov65_0221DE8C
	add r0, r4, #0
	bl ov65_0221F850
	b _0221C99E
_0221C6D8:
	ldr r1, _0221C9A4 ; =0x000022CC
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _0221C77A
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C6E6:
	ldr r0, _0221C9A4 ; =0x000022CC
	ldr r1, [r4, r0]
	sub r1, r1, #1
	str r1, [r4, r0]
	ldr r0, [r4, r0]
	cmp r0, #0
	bne _0221C77A
	mov r0, #4
	str r0, [r4, #0x58]
	b _0221C99E
_0221C6FA:
	ldr r0, _0221C9A8 ; =0x000036A8
	add r0, r4, r0
	bl sub_02039EAC
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C70A:
	ldr r2, _0221C9A8 ; =0x000036A8
	ldr r0, [r4, #4]
	mov r1, #2
	add r2, r4, r2
	bl sub_02039EB4
	cmp r0, #0
	beq _0221C77A
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C722:
	mov r0, #1
	bl sub_020378E4
	mov r0, #0x51
	bl sub_02037AC0
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C736:
	mov r0, #0x51
	bl sub_02037B38
	cmp r0, #0
	beq _0221C77A
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C748:
	mov r0, #0
	str r0, [r4, #0x5c]
	str r0, [r4, #0x60]
	str r0, [r4, #0x64]
	bl sub_0203769C
	cmp r0, #1
	bne _0221C76C
	bl sub_0203769C
	ldr r1, _0221C9AC ; =0x00002224
	ldr r2, [r4, #0x5c]
	ldr r1, [r4, r1]
	bl ov65_0221DE64
	ldr r0, [r4, #0x5c]
	add r0, r0, #1
	str r0, [r4, #0x5c]
_0221C76C:
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C774:
	ldr r0, [r4, #0x60]
	cmp r0, #0
	bne _0221C77C
_0221C77A:
	b _0221C99E
_0221C77C:
	mov r0, #0xa
	str r0, [r4, #0x58]
	b _0221C99E
_0221C782:
	add r0, r0, #1
	str r0, [r4, #0x58]
	add r0, r4, #0
	bl ov65_0221C1C4
	b _0221C99E
_0221C78E:
	mov r1, #0
	ldr r0, _0221C9B0 ; =0x0000069C
	add r2, r4, #0
	add r5, r1, #0
_0221C796:
	add r1, r1, #1
	strh r5, [r2, r0]
	add r2, #0x10
	cmp r1, #0xd
	blt _0221C796
	ldr r0, _0221C9AC ; =0x00002224
	ldr r0, [r4, r0]
	bl Party_GetCount
	cmp r0, #0
	ble _0221C7D0
	ldr r0, _0221C9B0 ; =0x0000069C
	ldr r7, _0221C9AC ; =0x00002224
	add r6, r4, r0
_0221C7B2:
	ldr r0, _0221C9AC ; =0x00002224
	add r1, r5, #0
	ldr r0, [r4, r0]
	bl Party_GetMonByIndex
	add r1, r6, #0
	bl ov65_0221C9D8
	ldr r0, [r4, r7]
	add r6, #0x10
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _0221C7B2
_0221C7D0:
	ldr r0, _0221C9B4 ; =0x00002228
	mov r5, #0
	ldr r0, [r4, r0]
	bl Party_GetCount
	cmp r0, #0
	ble _0221C804
	ldr r0, _0221C9B0 ; =0x0000069C
	ldr r7, _0221C9B4 ; =0x00002228
	add r6, r4, r0
_0221C7E4:
	ldr r0, _0221C9B4 ; =0x00002228
	add r1, r5, #0
	ldr r0, [r4, r0]
	bl Party_GetMonByIndex
	add r1, r5, #6
	lsl r1, r1, #4
	add r1, r6, r1
	bl ov65_0221C9D8
	ldr r0, [r4, r7]
	add r5, r5, #1
	bl Party_GetCount
	cmp r5, r0
	blt _0221C7E4
_0221C804:
	ldr r0, _0221C9B8 ; =0x0000075C
	mov r1, #1
	strh r1, [r4, r0]
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C812:
	bl sub_0203769C
	bl sub_02034818
	ldr r2, _0221C9BC ; =0x00002230
	ldr r1, [r4, r2]
	add r2, r2, #4
	add r2, r4, r2
	bl ov65_0221DEA0
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C82E:
	ldr r1, [r4, #0x60]
	cmp r1, #3
	bne _0221C88E
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C83A:
	ldr r0, [r4, #4]
	bl Save_Chatot_Get
	bl ov65_0221DF0C
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C84C:
	ldr r1, [r4, #0x60]
	cmp r1, #4
	bne _0221C88E
	add r0, r0, #1
	str r0, [r4, #0x58]
	mov r0, #0x10
	mov r1, #0
	bl GfGfx_EngineATogglePlanes
	ldr r0, _0221C9AC ; =0x00002224
	mov r1, #0
	ldr r0, [r4, r0]
	add r2, r4, #0
	bl ov65_0221C46C
	ldr r0, _0221C9B4 ; =0x00002228
	mov r1, #6
	ldr r0, [r4, r0]
	add r2, r4, #0
	bl ov65_0221C46C
	mov r6, #0xd1
	mov r5, #0
	mov r7, #1
	lsl r6, r6, #2
_0221C87E:
	ldr r0, [r4, r6]
	add r1, r7, #0
	bl Sprite_SetDrawFlag
	add r5, r5, #1
	add r4, r4, #4
	cmp r5, #2
	blt _0221C87E
_0221C88E:
	b _0221C99E
_0221C890:
	mov r1, #0
	mov r0, #1
	add r2, r1, #0
	str r0, [sp]
	mov r0, #8
	sub r2, #0x10
	mov r3, #0x1e
	bl StartBrightnessTransition
	mov r0, #1
	add r1, r0, #0
	bl ToggleBgLayer
	mov r0, #2
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #3
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineATogglePlanes
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C8CA:
	mov r0, #1
	bl IsBrightnessTransitionActive
	cmp r0, #0
	beq _0221C99E
	ldr r0, _0221C9AC ; =0x00002224
	mov r1, #0
	ldr r0, [r4, r0]
	bl Party_GetMonByIndex
	ldr r2, _0221C9C0 ; =0x000007FC
	ldr r3, _0221C9C4 ; =0x000020FC
	add r1, r0, #0
	mov r0, #0
	add r2, r4, r2
	add r3, r4, r3
	bl ov65_0221D57C
	ldr r1, _0221C9C8 ; =0x0000211C
	ldr r2, _0221C9AC ; =0x00002224
	str r0, [r4, r1]
	str r4, [sp]
	ldr r0, _0221C9CC ; =0x00000444
	mov r1, #0
	ldr r2, [r4, r2]
	add r0, r4, r0
	add r3, r1, #0
	bl ov65_0221D674
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	b _0221C99E
_0221C90C:
	mov r1, #0
	mov r0, #2
	add r2, r1, #0
	str r0, [sp]
	mov r0, #8
	sub r2, #0x10
	mov r3, #0x17
	bl StartBrightnessTransition
	mov r0, #4
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #5
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #1
	bl ToggleBgLayer
	mov r0, #0x10
	mov r1, #1
	bl GfGfx_EngineBTogglePlanes
	ldr r0, [r4, #0x58]
	add r0, r0, #1
	str r0, [r4, #0x58]
	add r0, r4, #0
	bl ov65_0221F780
	b _0221C99E
_0221C94C:
	mov r0, #2
	bl IsBrightnessTransitionActive
	cmp r0, #0
	beq _0221C99E
	ldr r0, _0221C9D0 ; =0x000005B4
	mov r1, #1
	add r0, r4, r0
	bl ClearFrameAndWindow2
	mov r1, #0
	str r1, [sp]
	mov r0, #0x20
	str r0, [sp, #4]
	mov r0, #0x18
	str r0, [sp, #8]
	str r1, [sp, #0xc]
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	add r2, r1, #0
	add r3, r1, #0
	bl FillBgTilemapRect
	mov r3, #0x61
	lsl r3, r3, #2
	ldr r0, [r4, r3]
	add r3, #0xc
	str r0, [sp]
	ldr r0, _0221C9D4 ; =0x00000594
	ldr r3, [r4, r3]
	add r0, r4, r0
	mov r1, #0xf
	mov r2, #1
	bl ov65_0221FB90
	mov r0, #2
	bl sub_0201A738
	add sp, #0x10
	mov r0, #1
	pop {r3, r4, r5, r6, r7, pc}
_0221C99E:
	mov r0, #0
	add sp, #0x10
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
_0221C9A4: .word 0x000022CC
_0221C9A8: .word 0x000036A8
_0221C9AC: .word 0x00002224
_0221C9B0: .word 0x0000069C
_0221C9B4: .word 0x00002228
_0221C9B8: .word 0x0000075C
_0221C9BC: .word 0x00002230
_0221C9C0: .word 0x000007FC
_0221C9C4: .word 0x000020FC
_0221C9C8: .word 0x0000211C
_0221C9CC: .word 0x00000444
_0221C9D0: .word 0x000005B4
_0221C9D4: .word 0x00000594
	thumb_func_end ov65_0221C5E0


	thumb_func_start ov65_0221C9D8
ov65_0221C9D8: ; 0x0221C9D8
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	add r4, r1, #0
	bl AcquireMonLock
	add r7, r0, #0
	add r0, r5, #0
	mov r1, #0x9b
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #4]
	add r0, r5, #0
	mov r1, #5
	mov r2, #0
	bl GetMonData
	strh r0, [r4]
	add r0, r5, #0
	mov r1, #0x70
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #6]
	add r0, r5, #0
	mov r1, #0x4c
	mov r2, #0
	bl GetMonData
	strb r0, [r4, #5]
	add r0, r5, #0
	mov r1, #0x6f
	mov r2, #0
	bl GetMonData
	strh r0, [r4, #8]
	add r0, r5, #0
	mov r1, #0xa2
	mov r2, #0
	bl GetMonData
	str r0, [r4, #0xc]
	add r0, r5, #0
	mov r1, #6
	mov r2, #0
	bl GetMonData
	add r6, r0, #0
	add r0, r5, #0
	add r1, r7, #0
	bl ReleaseMonLock
	ldrh r0, [r4]
	cmp r0, #0
	beq _0221CA50
	ldrb r1, [r4, #6]
	mov r2, #0x1c
	bl GetMonBaseStat_HandleAlternateForm
	strh r0, [r4, #0xa]
_0221CA50:
	cmp r6, #0
	beq _0221CA60
	lsl r0, r6, #0x10
	lsr r0, r0, #0x10
	bl ItemIdIsMail
	add r0, r0, #1
	strh r0, [r4, #2]
_0221CA60:
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov65_0221C9D8


	thumb_func_start ov65_0221CA64
ov65_0221CA64: ; 0x0221CA64
	push {r3, r4, r5, r6, r7, lr}
	sub sp, #8
	add r5, r1, #0
	ldr r1, _0221CAD4 ; =0x0000040C
	lsl r7, r5, #2
	add r6, r0, r1
	add r4, r2, #0
	ldr r0, [r6, r7]
	add r1, r4, #7
	bl Sprite_SetAnimCtrlSeq
	cmp r5, #2
	bne _0221CAA6
	mov r0, #0x20
	sub r1, r4, #1
	str r0, [sp]
	mov r0, #0x1a
	lsl r2, r1, #2
	ldr r1, _0221CAD8 ; =ov65_0221FEEC
	str r0, [sp, #4]
	mov r0, #0xa2
	ldr r1, [r1, r2]
	add r3, r0, #0
	mov r2, #5
	add r3, #0xbe
	bl GfGfxLoader_GXLoadPal
	ldr r0, [r6, r7]
	mov r1, #0xb
	bl Sprite_SetPaletteOverride
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
_0221CAA6:
	cmp r5, #3
	bne _0221CACE
	mov r0, #0x20
	sub r1, r4, #1
	str r0, [sp]
	mov r0, #0x1a
	lsl r2, r1, #2
	ldr r1, _0221CAD8 ; =ov65_0221FEEC
	str r0, [sp, #4]
	mov r0, #0xa2
	ldr r1, [r1, r2]
	add r3, r0, #0
	mov r2, #5
	add r3, #0xde
	bl GfGfxLoader_GXLoadPal
	ldr r0, [r6, r7]
	mov r1, #0xc
	bl Sprite_SetPaletteOverride
_0221CACE:
	add sp, #8
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221CAD4: .word 0x0000040C
_0221CAD8: .word ov65_0221FEEC
	thumb_func_end ov65_0221CA64


	thumb_func_start ov65_0221CADC
ov65_0221CADC: ; 0x0221CADC
	push {r3, r4, r5, r6, r7, lr}
	add r4, r1, #0
	add r5, r0, #0
	add r0, r4, #0
	mov r1, #6
	bl _s32_div_f
	ldr r0, _0221CB48 ; =0x00002228
	add r7, r1, #0
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r6, r0, #0
	add r0, r4, #0
	mov r1, #6
	bl _s32_div_f
	add r1, r6, #0
	ldr r2, _0221CB4C ; =0x000007FC
	mov r6, #0x32
	add r3, r0, #0
	lsl r6, r6, #6
	mul r6, r3
	add r2, r5, r2
	add r2, r2, r6
	ldr r6, _0221CB50 ; =0x000020FC
	lsl r3, r3, #4
	add r6, r5, r6
	mov r0, #1
	add r3, r6, r3
	bl ov65_0221D57C
	ldr r1, _0221CB54 ; =0x0000211C
	ldr r2, _0221CB48 ; =0x00002228
	str r0, [r5, r1]
	str r5, [sp]
	ldr r0, _0221CB58 ; =0x00000444
	ldr r2, [r5, r2]
	add r0, r5, r0
	mov r1, #1
	add r3, r7, #0
	bl ov65_0221D674
	lsl r2, r4, #4
	add r3, r5, r2
	mov r2, #0x6a
	lsl r2, r2, #4
	ldrb r2, [r3, r2]
	add r0, r5, #0
	mov r1, #3
	bl ov65_0221CA64
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221CB48: .word 0x00002228
_0221CB4C: .word 0x000007FC
_0221CB50: .word 0x000020FC
_0221CB54: .word 0x0000211C
_0221CB58: .word 0x00000444
	thumb_func_end ov65_0221CADC


	thumb_func_start ov65_0221CB5C
ov65_0221CB5C: ; 0x0221CB5C
	push {r3, r4, r5, lr}
	add r5, r0, #0
	add r1, r5, #0
	add r1, #0x94
	ldr r1, [r1]
	cmp r1, #0xc
	beq _0221CBEE
	cmp r1, #6
	bge _0221CBD4
	ldr r0, _0221CBF0 ; =0x00002224
	ldr r0, [r5, r0]
	bl Party_GetMonByIndex
	add r4, r0, #0
	add r0, r5, #0
	add r0, #0x94
	ldr r0, [r0]
	mov r1, #6
	bl _s32_div_f
	add r3, r0, #0
	ldr r2, _0221CBF4 ; =0x000007FC
	add r1, r4, #0
	add r4, r5, r2
	mov r2, #0x32
	lsl r2, r2, #6
	mul r2, r3
	add r2, r4, r2
	ldr r4, _0221CBF8 ; =0x000020FC
	lsl r3, r3, #4
	add r4, r5, r4
	mov r0, #0
	add r3, r4, r3
	bl ov65_0221D57C
	ldr r1, _0221CBFC ; =0x0000211C
	add r3, r5, #0
	str r0, [r5, r1]
	ldr r0, _0221CC00 ; =0x00000444
	ldr r2, _0221CBF0 ; =0x00002224
	str r5, [sp]
	add r3, #0x94
	ldr r2, [r5, r2]
	ldr r3, [r3]
	add r0, r5, r0
	mov r1, #0
	bl ov65_0221D674
	ldr r0, _0221CC00 ; =0x00000444
	mov r1, #1
	add r0, r5, r0
	add r2, r5, #0
	bl ov65_0221D8C4
	ldr r0, _0221CC04 ; =0x00000418
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
	pop {r3, r4, r5, pc}
_0221CBD4:
	bl ov65_0221CADC
	ldr r0, _0221CC00 ; =0x00000444
	mov r1, #0
	add r0, r5, r0
	add r2, r5, #0
	bl ov65_0221D8C4
	ldr r0, _0221CC08 ; =0x00000414
	mov r1, #0
	ldr r0, [r5, r0]
	bl Sprite_SetDrawFlag
_0221CBEE:
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221CBF0: .word 0x00002224
_0221CBF4: .word 0x000007FC
_0221CBF8: .word 0x000020FC
_0221CBFC: .word 0x0000211C
_0221CC00: .word 0x00000444
_0221CC04: .word 0x00000418
_0221CC08: .word 0x00000414
	thumb_func_end ov65_0221CB5C


	thumb_func_start ov65_0221CC0C
ov65_0221CC0C: ; 0x0221CC0C
	push {r3, r4, lr}
	sub sp, #4
	ldr r1, _0221CCA8 ; =0x00002220
	add r4, r0, #0
	ldr r1, [r4, r1]
	cmp r1, #0
	beq _0221CC22
	blx r1
	mov r1, #0x53
	lsl r1, r1, #2
	str r0, [r4, r1]
_0221CC22:
	mov r0, #0x53
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	cmp r0, #3
	bhi _0221CC4C
	add r0, r0, r0
	add r0, pc
	ldrh r0, [r0, #6]
	lsl r0, r0, #0x10
	asr r0, r0, #0x10
	add pc, r0
_0221CC38: ; jump table
	.short _0221CC4C - _0221CC38 - 2 ; case 0
	.short _0221CC4C - _0221CC38 - 2 ; case 1
	.short _0221CC40 - _0221CC38 - 2 ; case 2
	.short _0221CC46 - _0221CC38 - 2 ; case 3
_0221CC40:
	add sp, #4
	mov r0, #2
	pop {r3, r4, pc}
_0221CC46:
	add sp, #4
	mov r0, #3
	pop {r3, r4, pc}
_0221CC4C:
	mov r0, #0
	mov r2, #0xd1
	str r0, [sp]
	mov r0, #0x56
	lsl r2, r2, #2
	ldr r3, _0221CCAC ; =0x0000069C
	lsl r0, r0, #2
	add r1, r4, #0
	ldr r2, [r4, r2]
	add r0, r4, r0
	add r1, #0x94
	add r3, r4, r3
	bl ov65_0221DDC0
	cmp r0, #0
	beq _0221CC72
	add r0, r4, #0
	bl ov65_0221CB5C
_0221CC72:
	mov r0, #1
	mov r2, #0xd2
	str r0, [sp]
	mov r0, #0x57
	lsl r2, r2, #2
	ldr r3, _0221CCAC ; =0x0000069C
	lsl r0, r0, #2
	add r1, r4, #0
	ldr r2, [r4, r2]
	add r0, r4, r0
	add r1, #0x98
	add r3, r4, r3
	bl ov65_0221DDC0
	add r0, r4, #0
	add r0, #0x9c
	bl ov65_0221DCBC
	add r0, r4, #0
	add r4, #0x94
	ldr r2, [r4]
	mov r1, #0x17
	bl ov65_0221DE24
	mov r0, #1
	add sp, #4
	pop {r3, r4, pc}
	.balign 4, 0
_0221CCA8: .word 0x00002220
_0221CCAC: .word 0x0000069C
	thumb_func_end ov65_0221CC0C


	thumb_func_start ov65_0221CCB0
ov65_0221CCB0: ; 0x0221CCB0
	push {r3, r4, r5, r6, r7, lr}
	add r6, r0, #0
	mov r0, #0xb7
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0xbb
	lsl r0, r0, #2
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeleteCharTransferTask
	mov r0, #0x2e
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r0, #0x2f
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteTransfer_DeletePlttTransferTask
	mov r7, #0xb3
	mov r4, #0
	add r5, r6, #0
	lsl r7, r7, #2
_0221CCE4:
	ldr r0, [r5, r7]
	bl Destroy2DGfxResObjMan
	add r4, r4, #1
	add r5, r5, #4
	cmp r4, #4
	blt _0221CCE4
	mov r0, #0x1a
	lsl r0, r0, #4
	ldr r0, [r6, r0]
	bl SpriteList_Delete
	bl OamManager_Free
	bl ObjCharTransfer_Destroy
	bl ObjPlttTransfer_Destroy
	pop {r3, r4, r5, r6, r7, pc}
	.balign 4, 0
	thumb_func_end ov65_0221CCB0


	thumb_func_start ov65_0221CD0C
ov65_0221CD0C: ; 0x0221CD0C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	ldr r0, _0221CD64 ; =0x00002224
	mov r6, #0
	ldr r0, [r5, r0]
	bl Party_GetCount
	cmp r0, #0
	ble _0221CD38
	ldr r7, _0221CD64 ; =0x00002224
	add r4, r5, #0
_0221CD22:
	ldr r0, _0221CD68 ; =0x0000079C
	ldr r0, [r4, r0]
	bl Heap_Free
	ldr r0, [r5, r7]
	add r4, r4, #4
	add r6, r6, #1
	bl Party_GetCount
	cmp r6, r0
	blt _0221CD22
_0221CD38:
	ldr r0, _0221CD6C ; =0x00002228
	mov r6, #0
	ldr r0, [r5, r0]
	bl Party_GetCount
	cmp r0, #0
	ble _0221CD60
	ldr r7, _0221CD6C ; =0x00002228
	add r4, r5, #0
_0221CD4A:
	ldr r0, _0221CD70 ; =0x000007B4
	ldr r0, [r4, r0]
	bl Heap_Free
	ldr r0, [r5, r7]
	add r4, r4, #4
	add r6, r6, #1
	bl Party_GetCount
	cmp r6, r0
	blt _0221CD4A
_0221CD60:
	pop {r3, r4, r5, r6, r7, pc}
	nop
_0221CD64: .word 0x00002224
_0221CD68: .word 0x0000079C
_0221CD6C: .word 0x00002228
_0221CD70: .word 0x000007B4
	thumb_func_end ov65_0221CD0C


	thumb_func_start WirelessTradeSelectMon_Exit
WirelessTradeSelectMon_Exit: ; 0x0221CD74
	push {r3, r4, r5, lr}
	add r5, r0, #0
	bl OverlayManager_GetData
	add r4, r0, #0
	add r0, r5, #0
	bl OverlayManager_GetArgs
	ldr r1, [r4, #0x68]
	str r1, [r0, #0x24]
	add r0, r4, #0
	bl ov65_0221CD0C
	mov r0, #0x67
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl String_Delete
	ldr r0, _0221CE14 ; =0x00002228
	ldr r0, [r4, r0]
	bl Heap_Free
	add r0, r4, #0
	bl ov65_0221CCB0
	ldr r0, _0221CE18 ; =0x00000444
	add r0, r4, r0
	bl ov65_0221FAE0
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r4, r0]
	bl ov65_0221D1C8
	mov r1, #6
	lsl r1, r1, #6
	ldr r1, [r4, r1]
	mov r0, #0x1a
	bl Heap_FreeExplicit
	mov r0, #0x19
	lsl r0, r0, #4
	ldr r0, [r4, r0]
	bl DestroyMsgData
	mov r0, #0x63
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	mov r0, #0x62
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	mov r0, #0x61
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl MessageFormat_Delete
	mov r0, #0x66
	lsl r0, r0, #2
	ldr r0, [r4, r0]
	bl String_Delete
	add r0, r5, #0
	bl OverlayManager_FreeData
	mov r0, #0
	add r1, r0, #0
	bl Main_SetVBlankIntrCB
	mov r0, #4
	bl FontID_Release
	mov r0, #0x1a
	bl Heap_Destroy
	mov r0, #1
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221CE14: .word 0x00002228
_0221CE18: .word 0x00000444
	thumb_func_end WirelessTradeSelectMon_Exit


	thumb_func_start ov65_0221CE1C
ov65_0221CE1C: ; 0x0221CE1C
	push {r3, r4, r5, lr}
	sub sp, #8
	add r5, r0, #0
	mov r0, #6
	lsl r0, r0, #6
	ldr r0, [r5, r0]
	bl DoScheduledBgGpuUpdates
	ldr r0, _0221CE84 ; =0x0000211C
	ldr r0, [r5, r0]
	cmp r0, #0
	beq _0221CE6C
	sub r4, r0, #1
	ldr r0, _0221CE88 ; =0x000007FC
	mov r2, #0x32
	lsl r2, r2, #6
	add r1, r4, #0
	add r0, r5, r0
	mul r1, r2
	add r0, r0, r1
	bl GXS_LoadOBJ
	lsl r1, r4, #4
	mov r0, #0x20
	add r2, r5, r1
	str r0, [sp]
	mov r0, #0x1a
	add r3, r4, #2
	ldr r1, _0221CE8C ; =0x000020FC
	str r0, [sp, #4]
	ldrh r0, [r2, r1]
	add r1, r1, #4
	ldrh r1, [r2, r1]
	mov r2, #5
	lsl r3, r3, #5
	bl GfGfxLoader_GXLoadPal
	ldr r0, _0221CE84 ; =0x0000211C
	mov r1, #0
	str r1, [r5, r0]
_0221CE6C:
	bl GF_RunVramTransferTasks
	bl OamManager_ApplyAndResetBuffers
	ldr r3, _0221CE90 ; =0x027E0000
	ldr r1, _0221CE94 ; =0x00003FF8
	mov r0, #1
	ldr r2, [r3, r1]
	orr r0, r2
	str r0, [r3, r1]
	add sp, #8
	pop {r3, r4, r5, pc}
	.balign 4, 0
_0221CE84: .word 0x0000211C
_0221CE88: .word 0x000007FC
_0221CE8C: .word 0x000020FC
_0221CE90: .word 0x027E0000
_0221CE94: .word 0x00003FF8
	thumb_func_end ov65_0221CE1C


	thumb_func_start ov65_0221CE98
ov65_0221CE98: ; 0x0221CE98
	push {r4, lr}
	sub sp, #0x28
	ldr r4, _0221CEB4 ; =ov65_0221FE44
	add r3, sp, #0
	mov r2, #5
_0221CEA2:
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	sub r2, r2, #1
	bne _0221CEA2
	add r0, sp, #0
	bl GfGfx_SetBanks
	add sp, #0x28
	pop {r4, pc}
	.balign 4, 0
_0221CEB4: .word ov65_0221FE44
	thumb_func_end ov65_0221CE98


	thumb_func_start ov65_0221CEB8
ov65_0221CEB8: ; 0x0221CEB8
	push {r4, r5, r6, r7, lr}
	sub sp, #0xd4
	ldr r4, _0221D0C0 ; =ov65_0221FD58
	add r3, sp, #0xc4
	add r5, r0, #0
	add r2, r3, #0
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	add r0, r2, #0
	bl SetBothScreensModesAndDisable
	ldr r4, _0221D0C4 ; =ov65_0221FDF0
	add r3, sp, #0xa8
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #0
	str r0, [r3]
	add r0, r5, #0
	add r3, r1, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #0
	bl BgClearTilemapBufferAndCommit
	ldr r4, _0221D0C8 ; =ov65_0221FDB8
	add r3, sp, #0x8c
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #1
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #1
	bl BgClearTilemapBufferAndCommit
	ldr r4, _0221D0CC ; =ov65_0221FE0C
	add r3, sp, #0x70
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #2
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #2
	bl BgClearTilemapBufferAndCommit
	ldr r4, _0221D0D0 ; =ov65_0221FE28
	add r3, sp, #0x54
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #3
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r4, _0221D0D4 ; =ov65_0221FD80
	add r3, sp, #0x38
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	str r0, [r3]
	add r0, r5, #0
	mov r1, #4
	mov r3, #0
	bl InitBgFromTemplate
	add r0, r5, #0
	mov r1, #4
	bl BgClearTilemapBufferAndCommit
	ldr r4, _0221D0D8 ; =ov65_0221FD9C
	add r3, sp, #0x1c
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #5
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	ldr r4, _0221D0DC ; =ov65_0221FDD4
	add r3, sp, #0
	ldmia r4!, {r0, r1}
	add r2, r3, #0
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldmia r4!, {r0, r1}
	stmia r3!, {r0, r1}
	ldr r0, [r4]
	mov r1, #6
	str r0, [r3]
	add r0, r5, #0
	mov r3, #0
	bl InitBgFromTemplate
	mov r0, #0
	mov r1, #0x20
	add r2, r0, #0
	mov r3, #0x1a
	bl BG_ClearCharDataRange
	mov r0, #1
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x1a
	bl BG_ClearCharDataRange
	mov r0, #4
	mov r1, #0x20
	mov r2, #0
	mov r3, #0x1a
	bl BG_ClearCharDataRange
	mov r4, #0
	mov r6, #3
	add r7, r4, #0
_0221CFFC:
	lsl r1, r4, #0x18
	mov r2, #0
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, r6, #0
	add r3, r7, #0
	bl BgSetPosTextAndCommit
	add r1, r4, #4
	lsl r1, r1, #0x18
	mov r2, #0
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r3, r2, #0
	bl BgSetPosTextAndCommit
	add r1, r4, #4
	lsl r1, r1, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	mov r2, #3
	mov r3, #0
	bl BgSetPosTextAndCommit
	add r4, r4, #1
	cmp r4, #4
	blt _0221CFFC
	mov r0, #0
	add r1, r0, #0
	bl ToggleBgLayer
	mov r0, #1
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #2
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #3
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #4
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #5
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #6
	mov r1, #0
	bl ToggleBgLayer
	mov r0, #1
	lsl r0, r0, #0x1a
	add r3, r0, #0
	ldr r2, [r0]
	ldr r1, _0221D0E0 ; =0xFFFF1FFF
	add r3, #0x48
	and r1, r2
	str r1, [r0]
	ldrh r4, [r3]
	mov r1, #0x3f
	mov r2, #0x1f
	bic r4, r1
	orr r4, r2
	strh r4, [r3]
	add r3, r0, #0
	add r3, #0x4a
	ldrh r4, [r3]
	bic r4, r1
	orr r2, r4
	mov r1, #0x20
	orr r1, r2
	strh r1, [r3]
	add r1, r0, #0
	mov r2, #0xf
	lsl r2, r2, #0xc
	add r1, #0x40
	strh r2, [r1]
	ldr r2, _0221D0E4 ; =0x04000304
	mov r1, #0x10
	add r0, #0x44
	strh r1, [r0]
	ldrh r1, [r2]
	ldr r0, _0221D0E8 ; =0xFFFF7FFF
	and r0, r1
	strh r0, [r2]
	add sp, #0xd4
	pop {r4, r5, r6, r7, pc}
	.balign 4, 0
_0221D0C0: .word ov65_0221FD58
_0221D0C4: .word ov65_0221FDF0
_0221D0C8: .word ov65_0221FDB8
_0221D0CC: .word ov65_0221FE0C
_0221D0D0: .word ov65_0221FE28
_0221D0D4: .word ov65_0221FD80
_0221D0D8: .word ov65_0221FD9C
_0221D0DC: .word ov65_0221FDD4
_0221D0E0: .word 0xFFFF1FFF
_0221D0E4: .word 0x04000304
_0221D0E8: .word 0xFFFF7FFF
	thumb_func_end ov65_0221CEB8


	thumb_func_start ov65_0221D0EC
ov65_0221D0EC: ; 0x0221D0EC
	push {r4, r5, r6, lr}
	add r5, r0, #0
	add r0, r1, #0
	bl OverlayManager_GetArgs
	add r4, r0, #0
	mov r2, #6
	ldr r0, _0221D1B0 ; =0x00000674
	str r4, [r5, #8]
	mov r1, #4
	str r1, [r5, r0]
	mov r3, #0
	str r3, [r5, #0x50]
	sub r0, r0, #4
	str r3, [r5, r0]
	mov r0, #0x5e
	lsl r0, r0, #2
	str r2, [r5, r0]
	add r1, r0, #4
	str r2, [r5, r1]
	add r1, r5, #0
	add r1, #0x94
	str r3, [r1]
	add r1, r5, #0
	add r1, #0x98
	str r2, [r1]
	sub r0, #0x2c
	str r3, [r5, r0]
	str r3, [r5, #0x54]
	ldr r0, _0221D1B4 ; =ov65_0221E050
	ldr r1, _0221D1B8 ; =0x00002220
	str r3, [r5, #0x58]
	str r0, [r5, r1]
	str r3, [r5, #0x6c]
	str r3, [r5, #0x70]
	ldr r0, _0221D1BC ; =0x0000211C
	str r3, [r5, #0x68]
	str r3, [r5, r0]
	ldr r0, _0221D1C0 ; =0x000036AC
	sub r6, r2, #7
	str r6, [r5, r0]
	add r2, r0, #4
	str r6, [r5, r2]
	add r2, r1, #0
	add r2, #0xac
	str r3, [r5, r2]
	add r2, r0, #0
	add r2, #0xc
	str r3, [r5, r2]
	add r0, #0x10
	str r3, [r5, r0]
	add r0, r1, #4
	ldr r2, [r4, #8]
	add r1, #0x10
	str r2, [r5, r0]
	ldr r0, [r4, #0xc]
	str r0, [r5, r1]
	ldr r0, [r4, #0x10]
	str r0, [r5, #4]
	bl SaveArray_Party_sizeof
	add r1, r0, #0
	mov r0, #0x1a
	bl Heap_Alloc
	ldr r1, _0221D1C4 ; =0x00002228
	str r0, [r5, r1]
	ldr r0, [r5, r1]
	mov r1, #6
	bl Party_InitWithMaxSize
	bl SaveArray_Party_sizeof
	add r2, r0, #0
	ldr r0, _0221D1C4 ; =0x00002228
	mov r1, #0xff
	ldr r0, [r5, r0]
	bl memset
	ldr r0, [r4, #4]
	mov r1, #0x1a
	bl PlayerProfile_GetPlayerName_NewString
	mov r1, #0x66
	lsl r1, r1, #2
	str r0, [r5, r1]
	sub r1, #8
	ldr r0, [r5, r1]
	mov r1, #0x2a
	bl NewString_ReadMsgData
	mov r1, #0x67
	lsl r1, r1, #2
	str r0, [r5, r1]
	ldr r0, [r4, #0x14]
	bl sub_02039F68
	pop {r4, r5, r6, pc}
	.balign 4, 0
_0221D1B0: .word 0x00000674
_0221D1B4: .word ov65_0221E050
_0221D1B8: .word 0x00002220
_0221D1BC: .word 0x0000211C
_0221D1C0: .word 0x000036AC
_0221D1C4: .word 0x00002228
	thumb_func_end ov65_0221D0EC


	thumb_func_start ov65_0221D1C8
ov65_0221D1C8: ; 0x0221D1C8
	push {r4, lr}
	add r4, r0, #0
	mov r1, #6
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #5
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #4
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #3
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #2
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #1
	bl FreeBgTilemapBuffer
	add r0, r4, #0
	mov r1, #0
	bl FreeBgTilemapBuffer
	pop {r4, pc}
	thumb_func_end ov65_0221D1C8


	thumb_func_start ov65_0221D204
ov65_0221D204: ; 0x0221D204
	push {r4, r5, r6, lr}
	sub sp, #8
	add r5, r2, #0
	mov r2, #1
	add r4, r3, #0
	str r2, [sp]
	ldr r2, [sp, #0x20]
	ldr r3, [sp, #0x24]
	bl GfGfxLoader_LoadFromOpenNarc
	add r6, r0, #0
	beq _0221D256
	add r1, sp, #4
	bl NNS_G2dGetUnpackedScreenData
	cmp r0, #0
	beq _0221D250
	ldr r0, [sp, #0x1c]
	cmp r0, #0
	bne _0221D232
	ldr r0, [sp, #4]
	ldr r0, [r0, #8]
	str r0, [sp, #0x1c]
_0221D232:
	lsl r1, r4, #0x18
	add r0, r5, #0
	lsr r1, r1, #0x18
	bl GetBgTilemapBuffer
	cmp r0, #0
	beq _0221D250
	ldr r2, [sp, #4]
	lsl r1, r4, #0x18
	ldr r3, [sp, #0x1c]
	add r0, r5, #0
	lsr r1, r1, #0x18
	add r2, #0xc
	bl BG_LoadScreenTilemapData
_0221D250:
	add r0, r6, #0
	bl Heap_Free
_0221D256:
	add sp, #8
	pop {r4, r5, r6, pc}
	.balign 4, 0
	thumb_func_end ov65_0221D204
