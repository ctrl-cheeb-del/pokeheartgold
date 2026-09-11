	.include "asm/macros.inc"
	.public FrtCmd_080
	.public FrtCmd_081
	.public FrtCmd_082
	.public FrtCmd_151
	.public FrtCmd_152
	.public FrtCmd_153
	.public FrtCmd_154
	.public FrtCmd_155
	.public FrtCmd_156
	.public FrtCmd_157
	.public FrtCmd_158
	.public FrtCmd_159
	.public FrtCmd_160
	.public FrtCmd_161
	.public FrtCmd_162
	.public FrtCmd_163
	.public FrtCmd_164
	.public FrtCmd_165
	.public FrtCmd_166
	.public FrtCmd_167
	.public FrtCmd_168
	.public FrtCmd_169
	.public _02231CD8
	.public _02231CDC
	.public _02231D2C
	.public _02231D30
	.public _02231D84
	.public _02231DA8
	.public _02231DF4
	.public _02231E44
	.public _02231E48
	.public _02231E6A
	.public _02231E90
	.public _02231F18
	.public _02231F24
	.public _02231F7E
	.public _02231F82
	.public _02231F90
	.public _02231F96
	.public _02231FA4
	.public _02231FAC
	.public _02231FB6
	.public _02231FC0
	.public _02231FCA
	.public _02231FDE
	.public _02231FF4
	.public _02232002
	.public _0223201E
	.public _02232020
	.public _0223202A
	.public _02232036
	.public _0223203E
	.public _02232046
	.public _02232050
	.public _0223205A
	.public _02232062
	.public _02232076
	.public _0223207E
	.public _02232086
	.public _02232094
	.public _02232098
	.public _022320A8
	.public _022320AE
	.public _022320C4
	.public _022320CE
	.public _022320E2
	.public _022320EC
	.public _02232110
	.public _02232118
	.public _0223211A
	.public _02232120
	.public _0223212A
	.public _02232130
	.public _02232136
	.public _0223214A
	.public _02232178
	.public _02232182
	.public _022321B2
	.public _022321CA
	.public _022321D4
	.public _02232200
	.public _02232208
	.public _02232212
	.public _0223226A
	.public _0223228E
	.public _02232294
	.public _02232298
	.public _0223229C
	.public _022322A0
	.public _022322A4
	.public _022322A8
	.public _02232314
	.public _0223233E
	.public _02232344
	.public _02232364
	.public _0223238C
	.public _0223239C
	.public _022324B0
	.public ov80_02231E4C
	.public ov80_02231E94
	.public ov80_02232318
	.public ov80_02232368
	.include "overlay_80_02231BF8.inc"
	.include "global.inc"

    .text
	.public FrtCmd_080
	.public FrtCmd_081
	.public FrtCmd_082
	.public FrtCmd_151
	.public FrtCmd_152
	.public FrtCmd_153
	.public FrtCmd_154
	.public FrtCmd_155
	.public FrtCmd_156
	.public FrtCmd_157
	.public FrtCmd_158
	.public FrtCmd_159
	.public FrtCmd_161
	.public FrtCmd_162
	.public FrtCmd_163
	.public FrtCmd_164
	.public FrtCmd_165
	.public FrtCmd_166
	.public FrtCmd_167
	.public FrtCmd_168
	.public FrtCmd_169
	.public ov80_02231E94
	.public ov80_02232318
	.public ov80_02232368

	thumb_func_start ov80_02231E4C
ov80_02231E4C: ; 0x02231E4C
	push {r4, r5, r6, r7}
	ldrb r2, [r1, #0x10]
	mov r6, #0
	strb r2, [r0, #4]
	ldr r2, [r1, #0x28]
	str r2, [r0, #0x18]
	ldr r2, [r1, #0x2c]
	str r2, [r0, #0x1c]
	ldr r2, _02231E90 ; =0x00000A1C
	str r1, [r0, #0x24]
	ldrh r2, [r1, r2]
	strh r2, [r0, #0x28]
	mov r2, #0xde
	lsl r2, r2, #2
	add r3, r2, #4
_02231E6A:
	mov r7, #0x37
	add r5, r1, r6
	lsl r7, r7, #4
	ldrb r7, [r5, r7]
	add r4, r0, r6
	add r6, r6, #1
	strb r7, [r4, #8]
	mov r7, #0xdd
	lsl r7, r7, #2
	ldrb r7, [r5, r7]
	cmp r6, #4
	strb r7, [r4, #0xc]
	ldrb r7, [r5, r2]
	strb r7, [r4, #0x10]
	ldrb r5, [r5, r3]
	strb r5, [r4, #0x14]
	blt _02231E6A
	pop {r4, r5, r6, r7}
	bx lr
	.balign 4, 0
_02231E90: .word 0x00000A1C
	thumb_func_end ov80_02231E4C
