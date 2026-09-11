	.include "asm/macros.inc"
	.public _0225EEA8
	.public _0225EF20
	.public _0225EF70
	.public _0225EFD4
	.public _0225F264
	.public _0225F2C8
	.public _0225F2DC
	.public _0225F2EC
	.public _0225F300
	.public _0225F314
	.public _0225F32C
	.public _0225F340
	.public _0225F358
	.public _0225F36C
	.public _0225F3E4
	.public _0225F3EC
	.public _0225F43C
	.public _0225F440
	.public _0225F444
	.public _0225F448
	.public _0225F4BC
	.public _0225F4E8
	.public _0225F4F4
	.public _0225F51C
	.public _0225F540
	.public _0225F544
	.public _0225F5A0
	.public _0225F5B4
	.public _0225F5E0
	.public _0225F608
	.public _0225F680
	.public _0225F69C
	.public _0225F6C0
	.public _0225F6E0
	.public _0225F700
	.public _0225F724
	.public _0225F7D0
	.public _0225F7E4
	.public _0225F8A4
	.public _0225F8A8
	.public _0225F948
	.public _0225FAB4
	.public _0225FAB8
	.public _0225FAF8
	.public _0225FAFC
	.public _0225FB68
	.public _0225FB94
	.public _0225FBE0
	.public _0225FBEC
	.public _02262C04
	.public ov93_0225EE98
	.public ov93_0225EF0C
	.public ov93_0225EF5C
	.public ov93_0225EFAC
	.public ov93_0225F268
	.public ov93_0225F370
	.public ov93_0225F44C
	.public ov93_0225F548
	.public ov93_0225F8AC
	.public ov93_0225F8E4
	.public ov93_0225F94C
	.public ov93_0225F9AC
	.public ov93_0225F9D8
	.public ov93_0225FABC
	.public ov93_0225FB00
	.public ov93_0225FB6C
	.public ov93_0225FBE4
	.public ov93_02262C05
	.public ov93_02262C06
	.public ov93_02262C07
	.public ov93_02262C08
	.public ov93_02262C38
	.include "overlay_93_arm.inc"
	.include "global.inc"

	.text
	.public ov93_0225EE98
	.public ov93_0225EF0C
	.public ov93_0225EF5C
	.public ov93_0225F8AC
	.public ov93_0225F94C
	.public ov93_0225F9AC
	.public ov93_0225F9D8
	.public ov93_0225FABC
	.public ov93_0225FB00
	.public ov93_0225FB6C
	.public ov93_0225FBE4
	.rodata

_02262C04:
	.byte 0x80

ov93_02262C05: ; 0x02262C05
	.byte 0x40

ov93_02262C06: ; 0x02262C06
	.byte 0xC0

ov93_02262C07: ; 0x02262C07
	.byte 0x10

ov93_02262C08: ; 0x02262C08
	.byte 0xA8, 0x28, 0xD8, 0x00, 0xA8, 0x54, 0xAC, 0x08
	.byte 0xA8, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0x0F, 0x00, 0x00, 0xFF, 0x0F
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00, 0x01, 0xF0, 0x00, 0x00
	.byte 0x01, 0xF0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00

ov93_02262C38: ; 0x02262C38
	.byte 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
	.byte 0x0E, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x13, 0x27, 0x00, 0x00
	.byte 0x15, 0x27, 0x00, 0x00, 0x13, 0x27, 0x00, 0x00, 0x13, 0x27, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF
	.byte 0xFF, 0xFF, 0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
