#include "global.h"

#include "camera.h"

typedef struct Ov96R11Input {
    s32 unk00;
    s32 unk04;
} Ov96R11Input;

typedef struct Ov96R11Entry {
    s32 value;
    u8 padding_04[0x10];
    u32 active;
    s32 value2;
} Ov96R11Entry;

void NNS_G3dInit(void);
void G3X_InitMtxStack(void);
void sub_0200606C(u32 a, u32 b);
void ov96_021F6398(void *work);

extern const u8 ov96_0221DC18[];

void ov96_021F6088(void *work, s32 index, Ov96R11Input *input);
void ov96_021F6138(void *work);

void ov96_021F6088(void *work, s32 index, Ov96R11Input *input) {
    Ov96R11Entry *entry;
    s32 value;
    s32 speed;
    s32 *movement;

    if (input->unk04 > 0) {
        entry = (Ov96R11Entry *)((u8 *)work + 0xfac) + index;
        if (entry->active == 0) {
            value = (s32)((double)(input->unk04 / 64) / 2.5);
            speed = -input->unk00 / 4;
            if (speed >= 0) {
                if (speed > 0xa000) {
                    speed = 0xa000;
                }
            } else if (speed < -0xa000) {
                speed = -0xa000;
            }
            movement = (s32 *)((u8 *)work + 0xa8 + index * 0x38);
            *movement = speed;
            *movement = *movement * *(s32 *)((u8 *)work + 0xc4 + index * 0x38) / 12;
            entry->value = -value;
            entry->value2 = -value;
            entry->active = 1;
            sub_0200606C(0x8c2, ov96_0221DC18[index]);
        }
    }
}

void ov96_021F6138(void *work) {
    NNS_G3dInit();
    G3X_InitMtxStack();
    reg_G3_SWAP_BUFFERS = 2;
    reg_G2_BG0CNT = (u16)((reg_G2_BG0CNT & ~3) | 2);
    G3X_SetShading(GX_SHADING_TOON);
    G3X_AntiAlias(FALSE);
    G3X_AlphaTest(FALSE, 0);
    G3X_AlphaBlend(FALSE);
    G3X_EdgeMarking(FALSE);
    G3X_SetClearColor(0, 0, 0x7fff, 0x3f, FALSE);
    reg_G3_VIEWPORT = 0xbfff0000;
    *(Camera **)((u8 *)work + 0x190) = Camera_New(*(enum HeapID *)((u8 *)work + 0x54));
    ov96_021F6398(work);
}
