#include "overlay96_course_ui_r90_private.h"

void ov96_02208250(void *work, const void *records) {
    typedef struct {
        u16 species;
        u16 value2;
        u16 unused4;
        u8 value6;
        u8 value7;
        u32 unused8;
        u32 valueC;
    } Record;
    u16 ids[7];
    int i = 0;
    const Record *record = records;
    u8 *out = work;

    for (; i < 3; i++, record++, out += 8) {
        GetMonSpriteCharAndPlttNarcIdsEx(ids, record->species, record->value7, 2, record->value6, (u8)record->value2, record->valueC);
        OV96_R90_PTR(out, 0x108) = sub_0201457C(ids[0], ids[1], OV96_R90_WORD(work, 0), record->valueC, 0, 2, record->species);
        OV96_R90_PTR(out, 0x10C) = sub_02014450(ids[0], ids[2], OV96_R90_WORD(work, 0));
    }
}

void ov96_022082BC(void *work, u32 bank, u32 index) {
    typedef struct {
        void *character;
        void *palette;
    } Asset;
    typedef struct {
        u8 pad[0x108];
        Asset assets[3];
        u32 characterOffsets[2];
        u32 paletteOffsets[2];
    } Work;
    Work *w = work;

    if (bank >= 2) {
        GF_AssertFail();
    }
    if (index >= 3) {
        GF_AssertFail();
    }
    DC_FlushRange(w->assets[index].character, 0xC80);
    GXS_LoadOBJ(w->assets[index].character, w->characterOffsets[bank], 0xC80);
    DC_FlushRange(w->assets[index].palette, 0x20);
    GXS_LoadOBJPltt(w->assets[index].palette, w->paletteOffsets[bank], 0x20);
}
