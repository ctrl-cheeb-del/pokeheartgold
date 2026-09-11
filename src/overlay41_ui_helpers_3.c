#include "overlay41_ui_helpers_private.h"

void ov41_0224B084(void *w,void *r){SpriteTransfer_DeleteCharTransferTask(PTR(w,0));SpriteTransfer_DeletePlttTransferTask(PTR(w,4));DestroySingle2DGfxResObj(PTR(r,0),PTR(w,0));DestroySingle2DGfxResObj(PTR(r,4),PTR(w,4));DestroySingle2DGfxResObj(PTR(r,8),PTR(w,8));DestroySingle2DGfxResObj(PTR(r,0xc),PTR(w,0xc));}
