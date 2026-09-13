#include "global.h"

#include "constants/sndseq.h"

#include "bg_window.h"
#include "font.h"
#include "heap.h"
#include "message_format.h"
#include "msgdata.h"
#include "options.h"
#include "player_data.h"
#include "pm_string.h"
#include "render_text.h"
#include "render_window.h"
#include "sprite_system.h"
#include "string_util.h"
#include "text.h"
#include "to42_overlay_15_suffix_private.h"
#include "unk_02005D10.h"
#include "yes_no_prompt.h"

void ov15_021FEA5C(BagWorkRaw *);
void ov15_021FE9F0(BagWorkRaw *, Window *, u16, BOOL);
void ov15_021FEB64(BagWorkRaw *);
void ov15_021FECA0(BagWorkRaw *, Window *, u32);
void ov15_021FECC4(BagWorkRaw *, Window *);
void ov15_021FECD8(BagWorkRaw *, Window *, u32);
void ov15_021FED24(BagWorkRaw *);
void ov15_021FED3C(BagWorkRaw *);
void ov15_021FED58(BagWorkRaw *);
void ov15_021FED60(BagWorkRaw *);
void ov15_021FEDEC(BagWorkRaw *, u32);
u8 ov15_021FEF48(BagWorkRaw *, BOOL);
void ov15_021FEEA4(BagWorkRaw *);
void ov15_021FF058(BagWorkRaw *);
void ov15_021FF004(BagWorkRaw *);
BOOL ov15_021FEFC4(TextPrinterTemplate *, u16);
void ov15_021FF29C(BagWorkRaw *, BOOL);
void ov15_021FF4EC(BagWorkRaw *, s32, s32);
void ov15_021FF1E0(BagWorkRaw *);
void ov15_021FF0FC(BagWorkRaw *, BOOL);
void ov15_021FF068(BagWorkRaw *);
void ov15_021FF560(BagWorkRaw *);
void ov15_021FF6BC(BagWorkRaw *, s32, s32, s32);
void ov15_021FF7AC(Window *);
void ov15_021FF758(Window *, String **, u32);
void ov15_021FF7C4(BagWorkRaw *);
void ov15_021FF7FC(BagWorkRaw *);
void ov15_021FF834(BagWorkRaw *);
void ov15_021FF844(BagWorkRaw *);
void ov15_021FF894(BagWorkRaw *);
void ov15_021FF8D4(BagWorkRaw *);
void ov15_021FF950(BagWorkRaw *);
void ov15_021FF964(BagWorkRaw *);
void ov15_021FFEC0(BagWorkRaw *);
void ov15_021FFECC(BagWorkRaw *, s32);
void ov15_021FFF24(BagWorkRaw *);
void ov15_021FFFDC(BagWorkRaw *, s32);
void ov15_02200030(BagWorkRaw *, s32);
void ov15_02200294(BagWorkRaw *);
void ov15_0220005C(BagWorkRaw *, s32, s32, BOOL);
void ov15_022000F4(BagWorkRaw *);
void ov15_0220023C(BagWorkRaw *, const u8 *);
void ov15_022002B4(BagWorkRaw *, s32);
s32 ov15_022002EC(s32);
void ov15_02200428(BagWorkRaw *);
void ov15_02200458(BagWorkRaw *, BOOL);
void ov15_022004DC(BagWorkRaw *, BOOL);
void ov15_021FF97C(BagWorkRaw *, u16, BOOL);

u8 ov15_021FEF48(BagWorkRaw *work, BOOL wide) {
    Window *window;
    if (wide == FALSE) {
        window = (Window *)&work->raw[0x34];
    } else {
        GF_ASSERT(*(u32 *)&work->raw[0x204] != 0);
        window = (Window *)&work->raw[0x204];
    }
    FillWindowPixelBuffer(window, 0xF);
    DrawFrameAndWindow2(window, TRUE, 0x3E2, 0xC);
    ScheduleWindowCopyToVram(window);
    TextFlags_SetCanABSpeedUpPrint(TRUE);
    TextFlags_SetAutoScrollParam(0);
    u8 speed = Options_GetTextFrameDelay(*(Options **)&work->raw[0x240]);
    return AddTextPrinterParameterized(window, 1, *(String **)&work->raw[0x5E4], 0, 0, speed, ov15_021FEFC4);
}

BOOL ov15_021FEFC4(TextPrinterTemplate *printer, u16 event) {
    switch (event) {
    case 1:
        return GF_IsAnySEPlaying();
    case 2:
        return IsFanfarePlaying();
    case 3:
        PlaySE(SEQ_SE_DP_PC_LOGIN);
        break;
    case 4:
        return IsSEPlaying(SEQ_SE_DP_PC_LOGIN);
    }
    return FALSE;
}
