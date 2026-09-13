#include "opus10_overlay07_callback_suffix_private.h"

Ov07CallbackWork *ov07_02233DB8(Ov07Params *params);
BOOL ov07_02233E88(Ov07CallbackWork *work);
BOOL ov07_02233EA0(Ov07CallbackWork *work);
void ov07_02233EB8(Ov07CallbackWork *work, u32 a1);
BOOL ov07_02233EBC(Ov07CallbackWork *work, u32 a1);
void ov07_02233ECC(Ov07CallbackWork *work);
void ov07_02233EFC(Ov07CallbackWork *work, u32 callbackId);
u32 ov07_02233F20(Ov07CallbackWork *work);
void ov07_02233F30(Ov07CallbackWork *work);
void ov07_022341A4(Ov07CallbackWork *work, s16 *x, s16 *y);
void ov07_022342E4(Ov07CallbackWork *work);
void ov07_0223441C(Ov07CallbackWork *work);
void ov07_0223449C(Ov07CallbackWork *work, int flag);
void ov07_022344A8(Ov07CallbackWork *work, s16 x, s16 y);
void ov07_022344B4(Ov07CallbackWork *work, u16 a1);
void ov07_022344C0(Ov07CallbackWork *work, u32 a1);
void ov07_022344C4(Ov07CallbackWork *work, u16 a1);
void ov07_022344D0(Ov07CallbackWork *work, int a1);
void ov07_022344DC(Ov07CallbackWork *work, s32 a1);
s32 ov07_022344E4(s16 x0, s16 y0, s16 x1, s16 y1);
s32 ov07_02234510(const SEAL *seal);
u8 ov07_02234530(const SEAL *seal);
Ov07EmitterManager *ov07_0223458C(enum HeapID heapId, s32 *a1);
Ov07Emitter *ov07_022345C8(Ov07EmitterManager *mgr, Ov07EmitterInit *init);
void ov07_02234604(Ov07EmitterManager *mgr);
void ov07_02234628(Ov07EmitterManager *mgr);
Ov07Emitter *ov07_02234658(enum HeapID heapId, Ov07EmitterInit *init);
void ov07_02234694(Ov07Emitter *emitter);
u32 ov07_022346BC(Ov07Emitter *emitter);
void ov07_022346C0(SysTask *task, void *data);
void ov07_022346E4(Ov07Emitter *emitter, void (*cb)(SPLEmitter *));
void *ov07_02234710(void);
s32 ov07_02234718(u32 id);
void ov07_0223474C(Ov07PicWork *w, u32 a1);
void ov07_0223475C(Ov07PicWork *w, u32 a1);

s16 ov07_02234B5C(u32 a0, u32 a1) {
    if (a1 == 0) {
        return ov07_022377DC[a0][0];
    }
    return ov07_022377F4[a0][a1];
}
