#include "overlay00_voice_chat_r17_private.h"

BOOL ov00_021E74A8(u32 value) {
    void *session = *(void **)(_0221A684.state + 0x1A54);
    if (session == NULL) {
        session = VCT_CreateSession(value);
        if (session == NULL) {
            return FALSE;
        }
        value = VCT_Request(session, 0);
    } else {
        value = VCT_Request(session, 0);
    }
    if (value != 0) {
        VCT_DeleteSession(session);
        *(void **)(_0221A684.state + 0x1A54) = NULL;
        return FALSE;
    }
    *(void **)(_0221A684.state + 0x1A54) = session;
    return TRUE;
}

BOOL ov00_021E74FC(void) {
    void *session = *(void **)(_0221A684.state + 0x1A54);
    if (session != NULL && *(u32 *)((u8 *)session + 0xC) == 4) {
        if (VCT_Response(session, 0) != 0) {
            return FALSE;
        }
        if (VCT_StartStreaming(*(void **)(_0221A684.state + 0x1A54)) != 0) {
            return TRUE;
        }
        return FALSE;
    }
    return FALSE;
}

void ov00_021E7544(void *unused, u32 event, void *session) {
    switch (event) {
    case 9:
        ov00_021E7638(session);
        return;
    case 7:
        VCT_StartStreaming(session);
        return;
    case 12:
        ov00_021E7638(session);
        return;
    }
}
