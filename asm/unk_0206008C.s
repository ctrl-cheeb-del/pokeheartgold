#include "constants/sndseq.h"
#include "constants/species.h"
#include "constants/maps.h"
#include "constants/pokemon.h"
#include "constants/flags.h"
#include "constants/vars.h"
#include "constants/items.h"
#include "constants/std_script.h"
#include "fielddata/script/scr_seq/event_D24R0204.h"
#include "constants/field_move_response.h"
	.include "asm/macros.inc"
	.include "unk_0205FD20.inc"
	.include "global.inc"
	.text
	thumb_func_start sub_0206008C
sub_0206008C: ; 0x0206008C
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_0205F514
	lsl r0, r0, #0x18
	lsr r1, r0, #0x18
	add r0, r5, #0
	bl sub_0205F51C
	add r0, r5, #0
	bl sub_02061108
	add r0, r5, #0
	bl sub_0205F73C
	cmp r0, #1
	bne _02060112
	add r0, r5, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	bl sub_0205F514
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	bl ov01_021F9318
	add r7, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020601A4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206073C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020607A4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206039C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020609D4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060530
_02060112:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_0206008C
	thumb_func_start sub_02060114
sub_02060114: ; 0x02060114
	push {r3, r4, r5, r6, r7, lr}
	add r5, r0, #0
	bl sub_02061108
	add r0, r5, #0
	bl sub_0205F73C
	cmp r0, #1
	bne _020601A2
	add r0, r5, #0
	bl sub_0205F504
	lsl r0, r0, #0x18
	lsr r6, r0, #0x18
	add r0, r5, #0
	bl sub_0205F514
	lsl r0, r0, #0x18
	lsr r4, r0, #0x18
	add r0, r5, #0
	bl ov01_021F9318
	add r7, r0, #0
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020601A4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206073C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020607A4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206039C
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_020609D4
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060530
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_02060274
	add r0, r5, #0
	add r1, r6, #0
	add r2, r4, #0
	add r3, r7, #0
	bl sub_0206064C
_020601A2:
	pop {r3, r4, r5, r6, r7, pc}
	thumb_func_end sub_02060114
