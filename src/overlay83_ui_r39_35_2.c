#include "overlay83_ui_r39_35_private.h"

extern int ov83_022448AC(void *p, int field, int value);
extern void *Party_GetMonByIndex(void *party, int index);
extern int Options_GetFrame(void *options);
extern void ov83_02247944(void *p, int frame);
extern void *Mon_GetBoxMon(void *mon);
extern void ov83_02244AB0(u8 *p, int field, void *mon);
extern void ov83_022449D4(void *p, void *window);
extern void ov83_02245D48(void *p);
extern void ov83_02246114(void *p, int value);
extern void ov83_02246988(void *p);
extern void PlaySE(int seq);

void ov83_02245748(u8 *p, u32 value) {
    int index;
    void *mon;

    index = ov83_02247768(p[0x14], value);
    mon = Party_GetMonByIndex(PAT(p, 0x55c), index);
    ov83_02247944(p + 0xc0, Options_GetFrame(PAT(p, 0x2b8)));
    ov83_02244AB0(p, 0, Mon_GetBoxMon(mon));
    p[0xa] = ov83_022448AC(p, 0x14, 1);

    index = ov83_02247768(p[0x14], value);
    U8AT(PAT(p, 0x54c), index) = 1;

    index = ov83_02247768(p[0x14], value);
    ov83_0224755C(PAT(p + index * 4, 0x4f4), 0);

    index = ov83_02247768(p[0x14], value);
    ov83_0224755C(PAT(p + index * 4, 0x4e4), 1);

    ov83_022449D4(p, p + 0x70);
    if (p[0xd] == value) {
        ov83_02245D48(p);
        ov83_02246114(p, 0);
        ov83_02246988(p);
    }

    index = ov83_02247768(p[0x14], value);
    ov83_0224755C(PAT(p + index * 4, 0x510), 1);
    PlaySE(0x623);
}
