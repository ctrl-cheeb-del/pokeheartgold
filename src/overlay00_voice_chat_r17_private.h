#ifndef POKEHEARTGOLD_OVERLAY00_VOICE_CHAT_R17_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY00_VOICE_CHAT_R17_PRIVATE_H

#include "global.h"

typedef struct Ov00VoiceChatGlobalR17 {
    u32 field0;
    u8 *state;
} Ov00VoiceChatGlobalR17;

extern Ov00VoiceChatGlobalR17 _0221A684;
void *Heap_Alloc(u32 heapId, u32 size);
void MI_CpuFill8(void *dest, u8 value, u32 size);
int VCT_StartStreaming(void *session);
void *VCT_CreateSession(u32 value);
int VCT_Request(void *session, int request);
int VCT_Response(void *session, int response);
void VCT_StopStreaming(void *session);
void VCT_DeleteSession(void *session);
int VCT_HandleData(u8 value, void *a1, void *a2, void *state);
void NNS_SndStrmStart(void *stream);
void ov00_021E6A4C(void);
BOOL ov00_021E74A8(u32 value);
BOOL ov00_021E74FC(void);
void ov00_021E7544(void *unused, u32 event, void *session);
void ov00_021E7638(void *session);
BOOL ov00_021E77A4(u32 value, void *a1, void *a2);
void ov00_021E77CC(void **allocation, void **aligned, u32 size, u32 heapId);
void ov00_021E79B4(void);
void ov00_021E79CC(void);

#endif
