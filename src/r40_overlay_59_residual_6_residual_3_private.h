#include "global.h"

#include "bg_window.h"

typedef struct Ov59Work {
    enum HeapID heapId;
    u8 pad04[0x50];
    BgConfig *bgConfig;
} Ov59Work;

extern const GraphicsModes ov59_0223C658;
extern const BgTemplate ov59_0223C718;
extern const BgTemplate ov59_0223C68C;
extern const BgTemplate ov59_0223C6A8;
extern const BgTemplate ov59_0223C6FC;
extern const BgTemplate ov59_0223C734;
extern const BgTemplate ov59_0223C6E0;
void ov59_02239408(Ov59Work *);
void ov59_02239428(Ov59Work *);
