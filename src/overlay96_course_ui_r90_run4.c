#include "overlay96_course_ui_r90_private.h"

void ov96_02208840(void *work, int index, u32 value) {
    typedef struct {
        void *sprite;
        u8 pad[12];
    } Entry;
    typedef struct {
        u8 pad[0x140];
        Entry entries[1];
    } Work;
    if (value > 9) {
        GF_AssertFail();
    }
    ov96_021EB564(((Work *)work)->entries[index].sprite, value + 9);
}

void ov96_02208864(void *work, int index) {
    typedef struct {
        u8 pad[0x17C];
        void *sprites[4][2];
        u8 gap[6];
        u16 which;
    } Work;
    Work *w = work;
    ov96_021EB564(w->sprites[index][w->which], 2);
    ov96_021EB52C(w->sprites[index][w->which], 1, 1);
    w->which = (w->which + 1) % 2;
}
