#include "overlay96_ui_resources_57_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov96_021F4364(void *w, u32 n) {
    if (U32(w, 0x64) != n) {
        U32(w, 0x64) = n;
        ov96_021F459C(w, n);
        Sprite_SetAnimCtrlSeq(ov96_021EB5B8(PTR(w, 0x120)), n);
        CopyWindowToVram((u8 *)w + 0x4c);
    }
}

void ov96_021F4390(void *w, u32 index, u32 kind) {
    u32 seq;
    void **sprites;
    u32 selected;
    switch (kind) {
    case 1:
        seq = 0x12;
        break;
    case 2:
        seq = 0x13;
        break;
    case 3:
        seq = 0x14;
        break;
    case 4:
        seq = 0x15;
        break;
    default:
        GF_AssertFail();
        seq = 0x12;
        break;
    }
    sprites = (void **)((u8 *)w + 0x140);
    selected = U8(w, 0x170 + index) * 4;
    ov96_021EB52C(*(void **)((u8 *)sprites + selected), 1, 1);
    Sprite_SetAnimCtrlSeq(ov96_021EB5B8(*(void **)((u8 *)sprites + selected)), seq);
}

void ov96_021F43EC(void *w) {
    u8 i;
    for (i = 0; i < 12; i++) {
        u8 *p = (u8 *)w + i;
        p[0x70] = 0;
    }
    U32(w, 0x6c) = 0;
    ov96_021F4724((u8 *)w + 0x68);
}

void ov96_021F440C(void *sprites, void *w) {
    u32 ids[2] = { ov96_0221BFF4[8], ov96_0221BFF4[9] };
    u8 i;
    for (i = 0; i < 2; i++) {
        NNSG2dImagePaletteProxy *volatile pltt;
        SpriteResource *volatile chr;
        SpriteResource *volatile pal;
        NNSG2dImageProxy *proxy;
        u32 offset = i * 4;
        u32 id = ids[i];
        chr = *ov96_021EB5EC(sprites, id, 0);
        pal = *ov96_021EB5EC(sprites, id, 1);
        proxy = SpriteTransfer_GetCharProxy(chr);
        pltt = SpriteTransfer_GetPaletteProxy(pal, proxy);
        U32(w, 0x88 + offset) = NNS_G2dGetImageLocation(proxy, NNS_G2D_VRAM_TYPE_2DSUB);
        U32(w, 0x90 + offset) = NNS_G2dGetImagePaletteLocation(pltt, NNS_G2D_VRAM_TYPE_2DSUB);
    }
}

void ov96_021F4484(void *w) {
    int i;
    PokepicTemplate tpl;
    R57ParticipantView view;
    u8 *dst;
    i = 0;
    dst = w;
    for (; i < 12; i++) {
        int row = i / 3;
        int col = i % 3;
        ov96_021E6168(PTR(w, 4), row, col, &view);
        GetMonSpriteCharAndPlttNarcIdsEx(&tpl, view.species, view.field7, 2, view.kind, (u8)view.field2, view.fieldC);
        PTR(dst, 0x98) = sub_0201457C((NarcId)tpl.narcID, tpl.charDataID, (enum HeapID)U32(w, 0), view.fieldC, FALSE, 2, view.species);
        PTR(dst, 0x9c) = sub_02014450((NarcId)tpl.narcID, tpl.palDataID, (enum HeapID)U32(w, 0));
        dst += 8;
    }
}

void ov96_021F4504(void *w, u32 which, u32 index) {
    void **base;
    if (which >= 2) {
        GF_AssertFail();
    }
    if (index >= 12) {
        GF_AssertFail();
    }
    base = w;
    index *= 2;
    base += 12;
    DC_FlushRange(base[index], 0xc80);
    GXS_LoadOBJ(base[index], U32(w, 0x20 + which * 4), 0xc80);
    base = (void **)((u8 *)w + 0x34);
    DC_FlushRange(base[index], 0x20);
    GXS_LoadOBJPltt(base[index], U32(w, 0x28 + which * 4), 0x20);
}

void ov96_021F4558(void *w) {
    u8 i;
    for (i = 0; i < 5; i++) {
        AddWindow(PTR(w, 8), (u8 *)w + 0xc + i * 0x10, ov96_0221C028 + i * 8);
    }
    BG_FillCharDataRange(PTR(w, 8), 4, 0, 1, 0);
    LoadFontPal0(4, 0x1e0, U32(w, 0));
}

void ov96_021F459C(void *w, u32 n) {
    void *s;
    FillWindowPixelBuffer((u8 *)w + 0x4c, 0);
    BufferIntegerAsString(PTR(w, 0x60), 0, n, 2, 0, 1);
    s = ReadMsgData_ExpandPlaceholders(PTR(w, 0x60), PTR(w, 0x5c), 0x98, U32(w, 0));
    AddTextPrinterParameterizedWithColor((u8 *)w + 0x4c, 0, s, 0, 0, 0xff, 0x000f0e00, NULL);
    String_Delete(s);
}

void ov96_021F45F4(void *w, u32 active, u32 input) {
    void *m = (u8 *)w + 0x68;
    u32 result = (u8)ov96_021F46BC(m, input);
    if (active == 0 && U32(m, 4) != 0) {
        ov96_021F43EC(w);
    }
    if (U32(m, 0) != 0) {
        if (active != 0) {
            if (U32(m, 4) == 0) {
                U32(m, 4) = 1;
                if (ov96_021F47F0(m, 1) != 1) {
                    GF_AssertFail();
                }
                ov96_021F480C(m, PTR(w, 8));
            }
        } else if (result != 12 && ov96_021F47F0(m, 2) != 0) {
            PlaySE(0x89e);
            ov96_021F48A8(m, PTR(w, 8), result);
        }
    } else {
        ov96_021F4A60(m, PTR(w, 8));
    }
    if (PTR(m, 0x14) != NULL) {
        ((void (*)(void *))PTR(m, 0x14))(w);
    } else {
        GF_AssertFail();
    }
}

void ov96_021F4688(void *w, u32 value, u32 who) {
    u32 cur = ov96_021E5F24(PTR(w, 4));
    if (who == cur && U8(w, 0x150) != value) {
        if (U8(w, 0x150) < value) {
        } else {
            GF_AssertFail();
        }
        U8(w, 0x150) = value;
    }
}
