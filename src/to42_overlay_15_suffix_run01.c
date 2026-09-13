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

void ov15_021FEA5C(BagWorkRaw *work) {
    typedef struct {
        u8 pad[0x2F0];
        MsgData *msg;
        u8 pad2[0xC];
        String *strings[16];
    } Work;
    Work *w = (Work *)work;
    w->strings[0] = NewString_ReadMsgData(w->msg, 0);
    w->strings[1] = NewString_ReadMsgData(w->msg, 6);
    w->strings[2] = NewString_ReadMsgData(w->msg, 0x10);
    w->strings[3] = NewString_ReadMsgData(w->msg, 0x62);
    w->strings[4] = NewString_ReadMsgData(w->msg, 0x63);
    w->strings[5] = NewString_ReadMsgData(w->msg, 1);
    w->strings[6] = NewString_ReadMsgData(w->msg, 2);
    w->strings[7] = NewString_ReadMsgData(w->msg, 0x12);
    w->strings[8] = NewString_ReadMsgData(w->msg, 3);
    w->strings[9] = NewString_ReadMsgData(w->msg, 4);
    w->strings[10] = NewString_ReadMsgData(w->msg, 5);
    w->strings[11] = NewString_ReadMsgData(w->msg, 8);
    w->strings[12] = NewString_ReadMsgData(w->msg, 0x4B);
    w->strings[13] = NewString_ReadMsgData(w->msg, 0x56);
    w->strings[14] = NewString_ReadMsgData(w->msg, 0);
    w->strings[15] = NewString_ReadMsgData(w->msg, 0x80);
}

void ov15_021FEB64(BagWorkRaw *work) {
    typedef struct {
        u8 pad[0x300];
        String *strings[16];
    } Work;
    u16 i;
    for (i = 0; i < 16; i++) {
        String_Delete(((Work *)work)->strings[i]);
    }
}
