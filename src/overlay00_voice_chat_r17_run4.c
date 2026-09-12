#include "overlay00_voice_chat_r17_private.h"

void ov00_021E79B4(void) {
    NNS_SndStrmStart(_0221A684.state + 0x19F8);
}

void ov00_021E79CC(void) {
    void *session = *(void **)(_0221A684.state + 0x1A54);
    u32 mode;
    if (session == NULL || *(u32 *)(_0221A684.state + 0x19EC) == 0) {
        ov00_021E6A4C();
        return;
    }
    mode = *(u32 *)(_0221A684.state + 0x19EC);
    if (mode == 1) {
        if (VCT_Request(session, 2) != 0) {
            ov00_021E6A4C();
            return;
        }
    }
    session = *(void **)(_0221A684.state + 0x1A54);
    if (VCT_Request(session, 1) != 0) {
        ov00_021E6A4C();
    }
}
