#include "r40_overlay_48_residual_25_private.h"

void ov48_0225AC34(void *p, void *managers) {
    int i;
    int j;
    void *sprite = p;
    void *record;

    StopSE(0x5D8, 0);
    record = p;
    for (i = 0; i < 12; i++) {
        Sprite_Delete(PTRAT(sprite, 0x3C));
        SpriteTransfer_DeleteCharTransferTask(PTRAT(record, 0x6C));
        if (i == 0) {
            SpriteTransfer_DeletePlttTransferTask(PTRAT(record, 0x70));
            DestroySingle2DGfxResObj(PTRAT(managers, 0x134), PTRAT(record, 0x70));
        }
        {
            void *manager = managers;
            void *resource;

            j = 0;
            resource = record;
            for (; j < 4; j++) {
                if (j != 1) {
                    DestroySingle2DGfxResObj(PTRAT(manager, 0x130), PTRAT(resource, 0x6C));
                }
                resource = ADD(resource, 4);
                manager = ADD(manager, 4);
            }
        }
        sprite = ADD(sprite, 4);
        record = ADD(record, 0x10);
    }
}

void ov48_0225ACAC(void *p) {
    u8 *a = ADD(p, 0x34);
    u8 *b = ADD(p, 0x34);
    u8 zero = 0;

    a[0] = zero;
    b[1] = zero;
    b[2] = zero;
    b[3] = zero;
    a = ADD(p, 0x38);
    b = ADD(p, 0x38);
    a[0] = zero;
    b[1] = zero;
    b[2] = zero;
    b[3] = zero;
    U16AT(p, 0x30) = 2;
    U16AT(p, 0x32) = 0x80;
}
