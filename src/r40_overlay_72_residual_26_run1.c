#include "r40_overlay_72_residual_26_private.h"
#include "system.h"

#define U8_AT(p, o)  (*(u8 *)((p) + (o)))
#define S8_AT(p, o)  (*(s8 *)((p) + (o)))
#define S16_AT(p, o) (*(s16 *)((p) + (o)))
#define PTR_AT(p, o) (*(void **)((p) + (o)))

extern u8 ov72_0223A760(u8 current, int direction, u8 *table);
extern void ov72_022386F4(void *sprite, u8 selection);
extern void PlaySE(int seqNo);
extern int ov72_0223A738(void);
extern void Sprite_SetAnimCtrlSeq(void *sprite, int sequence);
extern int ov72_0223A7F4(u8 *work, int value);
extern void ov72_02238730(void *sprite, int index, void *data);
extern int ov72_0223A8DC(u8 *work);
extern void ov72_0223AED0(u8 *work, u8 a1, u8 a2, int a3);
extern u8 ov72_0223B478[];
extern u8 ov72_0223B479[];

typedef struct Ov72AnimSelection {
    u8 pad0000[0xDF4];
    void *sprites[3];
    void *selectionSprite;
    void *indexSprite;
    void *cancelSprite;
    void *confirmSprite;
    void *lastSprite;
    u8 pad0E14[0x130C - 0xE14];
    struct {
        u8 unk0;
        u8 mode;
        s8 cursor;
        u8 selection;
        s16 index;
        u8 state;
        u8 pad7;
        s8 sequences[3];
    } state;
    u8 pad1318[0x1368 - 0x1318];
    void *data1368;
} Ov72AnimSelection;

BOOL ov72_0223AA9C(u8 *work) {
    if (gSystem.newAndRepeatedKeys & 0x40) {
        U8_AT(work, 0x130F) = ov72_0223A760(U8_AT(work, 0x130F), 0, work + 0x1364);
        ov72_022386F4(PTR_AT(work, 0xE00), U8_AT(work, 0x130F));
        PlaySE(0x5DC);
    } else if (gSystem.newAndRepeatedKeys & 0x80) {
        U8_AT(work, 0x130F) = ov72_0223A760(U8_AT(work, 0x130F), 1, work + 0x1364);
        ov72_022386F4(PTR_AT(work, 0xE00), U8_AT(work, 0x130F));
        PlaySE(0x5DC);
    } else if (gSystem.newAndRepeatedKeys & 0x20) {
        U8_AT(work, 0x130F) = ov72_0223A760(U8_AT(work, 0x130F), 2, work + 0x1364);
        ov72_022386F4(PTR_AT(work, 0xE00), U8_AT(work, 0x130F));
        PlaySE(0x5DC);
    } else if (gSystem.newAndRepeatedKeys & 0x10) {
        U8_AT(work, 0x130F) = ov72_0223A760(U8_AT(work, 0x130F), 3, work + 0x1364);
        ov72_022386F4(PTR_AT(work, 0xE00), U8_AT(work, 0x130F));
        PlaySE(0x5DC);
    } else if (gSystem.newKeys & 1) {
        ov72_0223A8F0(work, U8_AT(work, 0x130F) + 3);
    } else if (gSystem.newKeys & 2) {
        ov72_0223A8F0(work, 13);
    }
    return FALSE;
}

BOOL ov72_0223AB84(u8 *work) {
    int input = ov72_0223A738();

    if (input == -1) {
        ov72_0223AA9C(work);
    } else {
        ov72_0223A8F0(work, input);
    }
    ov72_0223ABB0(work);
    return FALSE;
}

void ov72_0223ABB0(u8 *work) {
    Ov72AnimSelection *selection = (Ov72AnimSelection *)work;
    int i;

    for (i = 0; i < 3; i++) {
        s8 sequence = selection->state.sequences[i];
        if (sequence == -1) {
            Sprite_SetAnimCtrlSeq(selection->sprites[i], 0);
        } else if (sequence >= 0 && sequence <= 9) {
            Sprite_SetAnimCtrlSeq(selection->sprites[i], sequence + 1);
        }
    }
}
