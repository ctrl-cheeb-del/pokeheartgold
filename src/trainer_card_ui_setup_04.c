#include "global.h"

#include "constants/sndseq.h"

#include "bg_window.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "trainer_card_main_04_private.h"

void ov51_021E6644(BgConfig *bgConfig) {
    GfGfx_EngineATogglePlanes(0x1f, FALSE);
    GfGfx_EngineBTogglePlanes(0x1f, FALSE);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 5, BG_POS_OP_SET_Y, 0);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit(bgConfig, 3, BG_POS_OP_SET_Y, 0);
    FreeBgTilemapBuffer(bgConfig, 7);
    FreeBgTilemapBuffer(bgConfig, 6);
    FreeBgTilemapBuffer(bgConfig, 4);
    FreeBgTilemapBuffer(bgConfig, 5);
    FreeBgTilemapBuffer(bgConfig, 2);
    FreeBgTilemapBuffer(bgConfig, 3);
    Heap_Free(bgConfig);
}

void ov51_021E66C0(TrainerCardMainState04 *state) {
    if (*(void **)&state->data[0x30f4] == NULL) {
        GfGfxLoader_LoadScrnData((NarcId)0x31, 0x2f, *(BgConfig **)&state->data[0], (GFBgLayer)6, 0, 0, FALSE, (enum HeapID)0x19);
        ov51_021E74D4(&state->data[4], 7, 10);
        BgClearTilemapBufferAndCommit(*(BgConfig **)&state->data[0], 7);
    } else {
        GfGfxLoader_LoadScrnData((NarcId)0x31, 0x30, *(BgConfig **)&state->data[0], (GFBgLayer)6, 0, 0, FALSE, (enum HeapID)0x19);
        ov51_021E74D4(&state->data[4], 0, 6);
        ov51_021E6CCC(state);
        BgClearTilemapBufferAndCommit(*(BgConfig **)&state->data[0], 7);
    }
}

void ov51_021E6734(TrainerCardMainState04 *state) {
    void *cardData;

    ov51_021E66C0(state);
    ov51_021E7D44(&state->data[0x311c], 0, 0, 1);
    if (*(void **)&state->data[0x30f4] == NULL) {
        ov51_021E6C6C(state);
        ov51_021E76EC(state, 1);
    } else {
        ov51_021E6D44(*(BgConfig **)&state->data[0], 7, &state->data[0xec]);
        ov51_021E76EC(state, 0);
    }
    cardData = *(void **)&state->data[0xe8];
    ov51_021E6F18(state, &state->data[4], cardData);
    cardData = *(void **)&state->data[0xe8];
    ov51_021E7208(state, &state->data[4], cardData);
    ov51_021E71D0(state, &state->data[4]);
}

int ov51_021E67A4(TrainerCardMainState04 *state) {
    switch (state->data[0x3436]) {
    case 0:
        ov51_021E77A0(state, 0);
        state->data[0x3436]++;
        break;
    case 1:
        if (TextPrinterCheckActive(state->data[0x343c])) {
            return 0;
        }
        ov51_021E7804(state, 0);
        ov51_021E6E10(state, 1);
        state->data[0x3436]++;
        break;
    case 2: {
        int result = ov51_021E786C(state, 0);
        if (result < 0) {
            break;
        }
        if (result == 0) {
            ov51_021E6E10(state, 0);
            return 1;
        }
        if ((*(TrainerCardData04 **)&state->data[0xe8])->showMessage) {
            ov51_021E77A0(state, 1);
        } else {
            return 2;
        }
        state->data[0x3436]++;
        break;
    }
    case 3:
        if (TextPrinterCheckActive(state->data[0x343c])) {
            return 0;
        }
        ov51_021E7804(state, 1);
        state->data[0x3436]++;
        break;
    case 4: {
        int result = ov51_021E786C(state, 1);
        switch (result) {
        case 0:
            ov51_021E6E10(state, 0);
            return 1;
        case 1:
            return 2;
        default:
            break;
        }
        break;
    }
    }
    return 0;
}

int ov51_021E6888(TrainerCardMainState04 *state) {
    int done = 0;

    switch (state->data[0x3436]) {
    case 0:
        *(s32 *)&state->data[0x3394] = 8;
        *(s32 *)&state->data[0x30fc] = 8 << 9;
        *(s32 *)&state->data[0x3100] = 8 << 9;
        *(s32 *)&state->data[0x30fc] += 0x80;
        *(s32 *)&state->data[0x3100] += 0x80;
        PlaySE(SEQ_SE_DP_CARD5);
        state->data[0x3436]++;
        break;
    case 1: {
        int value = *(s32 *)&state->data[0x3394];
        *(s32 *)&state->data[0x30fc] -= 2 << (12 - value);
        if (*(s32 *)&state->data[0x30fc] <= 0) {
            *(s32 *)&state->data[0x30fc] = 0x24;
            state->data[0x3436]++;
        }
        (*(s32 *)&state->data[0x3394])--;
        if (*(s32 *)&state->data[0x3394] <= 1) {
            *(s32 *)&state->data[0x3394] = 1;
        }
        break;
    }
    case 2:
        *(s32 *)&state->data[0x30f4] ^= 1;
        ov51_021E66C0(state);
        state->data[0x3436]++;
        break;
    case 3:
        if (*(void **)&state->data[0x30f4] == NULL) {
            ov51_021E6C6C(state);
            ov51_021E76EC(state, 1);
        } else {
            ov51_021E6D44(*(BgConfig **)&state->data[0], 7, &state->data[0xec]);
            if (((TrainerCardAnimFlags04 *)&state->data[0x343a])->skipMessage == 0) {
                ov51_021E76EC(state, 0);
            }
        }
        state->data[0x3436]++;
        break;
    case 4:
        ov51_021E71D0(state, &state->data[4]);
        state->data[0x3436]++;
        break;
    case 5:
        (*(s32 *)&state->data[0x3394])++;
        if (*(s32 *)&state->data[0x3394] > 8) {
            *(s32 *)&state->data[0x3394] = 8;
        }
        *(s32 *)&state->data[0x30fc] += 2 << (12 - *(s32 *)&state->data[0x3394]);
        if (*(s32 *)&state->data[0x30fc] >= 0x1000) {
            *(s32 *)&state->data[0x30fc] = 0x1000;
            *(s32 *)&state->data[0x30fc] = 0x1000;
            *(s32 *)&state->data[0x3100] = 0x1000;
            done = 1;
        }
        break;
    }
    state->data[0x343a] |= 4;
    return done;
}
