#include "overlay49_3d_cleanup_r47.h"

void ov49_0225D9D0(Ov49State *state, int heapId) {
    int i;
    int j;
    u8 *outer;
    u8 *cursor;
    u8 *freeCursor;
    int k;
    void *tex;
    u32 key1;
    u32 key2;

    i = 0;
    outer = state->raw + 0x38;
    do {
        j = 0;
        cursor = outer;
        do {
            sub_020180F8(cursor, heapId);
            j++;
            cursor += 0x14;
        } while (j < 4);
        outer += 0x50;
        i++;
    } while (i < 2);
    freeCursor = state->raw;
    k = 0;
    do {
        Heap_Free(PTR(freeCursor, 0));
        k++;
        freeCursor += 0x10;
    } while (k < 2);
    i = 0;
    do {
        freeCursor = state->raw;
        k = 0;
        do {
            tex = NNS_G3dGetTex(PTR(freeCursor, 0x20));
            NNS_G3dTexReleaseTexKey(tex, &key1, &key2);
            NNS_GfdDefaultFuncFreeTexVram(key1);
            NNS_GfdDefaultFuncFreeTexVram(key2);
            NNS_GfdDefaultFuncFreePlttVram(NNS_G3dPlttReleasePlttKey(tex));
            Heap_Free(PTR(freeCursor, 0x20));
            k++;
            freeCursor += 4;
        } while (k < 3);
        state = (Ov49State *)(state->raw + 0xC);
        i++;
    } while (i < 2);
}
