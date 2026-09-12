#include "overlay00_voice_chat_r17_private.h"

void ov00_021E7638(void *session) {
    VCT_StopStreaming(session);
    VCT_DeleteSession(session);
    *(void **)(_0221A684.state + 0x1A54) = NULL;
}
