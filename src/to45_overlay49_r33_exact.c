#include "overlay49_r33_internal.h"

void ov49_0225BEA0(void *unused0, void *unused1, void *ctx_, enum HeapID heapId, void *session) {
    void **ctx = ctx_;
    s32 i = 0;
    u16 *tileBase = ov49_022696F8;
    const u8(*tiles)[0x10] = ov49_0226978C;
    u32 y = 2;

    for (; i < 2; i++) {
        if ((u16)ov45_0222AAEC(session, i) != 0) {
            u16 type = ov45_0222D7C0();
            NarcId narcId = sub_020776B4();
            u32 member = sub_02077678(type);
            void *buf = GfGfxLoader_LoadFromNarc(narcId, member, 1, heapId, 1);
            NNSG2dCharacterData *charData;

            NNS_G2dGetUnpackedCharacterData(buf, &charData);
            BG_LoadCharTilesData(*ctx, 6, charData->pRawData, 0x100, *tileBase);
            Heap_Free(buf);
            CopyToBgTilemapRect(*ctx, 6, 0x1a, y, 4, 2, *tiles, 0, 0, 4, 2);
            BgTilemapRectChangePalette(*ctx, 6, 0x1a, y, 4, 2, (u8)(sub_0207769C(type) + 0xb));
            ScheduleBgTilemapBufferTransfer(*ctx, 6);
        }
        tiles++;
        tileBase++;
        y += 2;
    }
}

void ov49_0225BF80(void *state_, void *unused, void *ctx_) {
    u32 *state = state_;
    u8 *ctx = ctx_;
    if (*state == 1) {
        *state = 0;
    } else {
        ov49_0225C78C(state, ctx);
    }
    ov49_0225C148(state, ctx);
    ov49_0225C328(state, ctx);
    BgClearTilemapBufferAndCommit(*(void **)ctx, 4);
    BgClearTilemapBufferAndCommit(*(void **)ctx, 5);
    BgClearTilemapBufferAndCommit(*(void **)ctx, 6);
}

void ov49_0225BFC4(void *a0, void *a1, void *a2, void *a3, void *a4) {
    ov49_0225C148(a0, a1);
    ov49_0225BFF0(a0, a1, a2, a3, a4, 1);
}
