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

void ov83_02245554(u8 *p, u8 value) {
    int result = ov83_02245068(value);

    ov83_02244A98(p, 0, result, 4, 0);
    p[0xa] = ov83_022448AC(p, 0x19, 1);
    ov83_02244A74(p);
    p[0xe] = value;
}
