#include "ov96_wave40_b_private.h"

void ov96_022146C0(R27Work *w) {
    GfGfxLoader_LoadScrnData(NARC_a_2_3_4, 8, w->bg, (GFBgLayer)5, 0, 0, FALSE, w->heap);
    GfGfxLoader_LoadScrnData(NARC_a_2_3_4, 9, w->bg, (GFBgLayer)6, 0, 0, FALSE, w->heap);
    w->screenAlloc = GfGfxLoader_GetScrnData(NARC_a_2_3_4, 10, FALSE, &w->screenData, w->heap);
    ov96_0221497C(w, 0);
}

void ov96_02214718(void *system, R27Work *w, void *resource) {
    R27Vec matrixA = ov96_0221D660;
    R27Vec matrixB = ov96_0221D66C;
    void *label;
    u8 i;

    label = ov96_021EB3E4(system, 0, 2, 0x66, 9);
    ov96_021EB52C(label, TRUE, TRUE);
    ov96_021EB588(label, &matrixA);
    ov96_021EB564(label, ov96_021E5F24(w->course) + 1);

    label = ov96_021EB3E4(system, 0, 2, 0x66, 10);
    ov96_021EB52C(label, TRUE, TRUE);
    ov96_021EB588(label, &matrixB);
    ov96_021EB564(label, 5);
    w->label = label;

    for (i = 0; i < 2; i++) {
        R27Vec matrix;
        w->sprites[i] = ov96_021EA2C4(resource, ov96_021EB5E8(system), 0, w->heap);
        Sprite_SetDrawFlag(w->sprites[i], TRUE);
        matrix.x = ov96_0221D648[i] << 12;
        matrix.y = 10 << 18;
        matrix.z = 0;
        Sprite_SetMatrix(w->sprites[i], &matrix);
        Sprite_SetAnimCtrlSeq(w->sprites[i], ov96_0221D64C[i]);
    }
}

void ov96_022147FC(R27Work *w) {
    String *name;
    u8 index;
    FillWindowPixelBuffer(&w->windowA, 0);
    index = ov96_021E5F24(w->course);
    name = PlayerProfile_GetPlayerName_NewString(PokeathlonCourse_GetPlayerProfileFromData(w->course, index), w->heap);
    AddTextPrinterParameterizedWithColor(&w->windowA, 0, name, 0, 0, 0xFF, 0xF0E00, NULL);
    String_Delete(name);
    CopyWindowToVram(&w->windowA);
}

void ov96_02214854(R27Work *w) {
    String *string;
    FillWindowPixelBuffer(&w->windowB, 0);
    string = ReadMsgData_ExpandPlaceholders(w->format, w->msgData, 0x137, w->heap);
    AddTextPrinterParameterizedWithColor(&w->windowB, 0, string, 0, 0, 0xFF, 0xF0E00, NULL);
    String_Delete(string);
    CopyWindowToVram(&w->windowB);
}

void ov96_022148A4(R27Work *w) {
    AddWindow(w->bg, &w->windowA, &ov96_0221D650);
    AddWindow(w->bg, &w->windowB, &ov96_0221D658);
    BG_FillCharDataRange(w->bg, (GFBgLayer)4, 0, 1, 0);
    LoadFontPal0((enum GFPalLoadLocation)4, (enum GFPalSlotOffset)0x1E0, w->heap);
}
