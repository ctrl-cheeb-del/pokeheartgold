#include "global.h"

extern void ov48_0225A634(void *);
extern void ov48_0225AC34(void *, void *);
extern void Heap_Free(void *);
extern void ov48_0225A768(void *);
extern void RemoveWindow(void *);
extern void ov48_0225A294(void *);
extern void ov48_0225A928(void *);
void ov48_0225A108(void *, void *);

void ov48_0225A108(void *work, void *arg) {
    u8 *raw = work;
    int i;
    u8 *item;

    ov48_0225A634(raw + 0x2e4);
    ov48_0225AC34(raw + 0x1b8, arg);
    Heap_Free(*(void **)(raw + 0x94));
    ov48_0225A768(work);
    RemoveWindow(raw + 0x1a8);
    ov48_0225A294(work);
    i = 0;
    item = raw + 0xa0;
    do {
        ov48_0225A928(item);
        i++;
        item += 0x28;
    } while (i < 5);
}
