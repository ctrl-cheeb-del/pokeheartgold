#define OMIT_UNMATCHED
#include "to45_ov40_r27_u19_private.h"

void ov40_02235B4C(void *scene) {
    void *inner = PTR_AT(scene, 0x860);
    void *window;
    void *formatted;
    void *source;
    void *fmt;
    void *line;
    void *word;
    u32 lineCount;
    u32 i;
    u32 y;

    if (WindowIsInUse((u8 *)inner + 0x10) == 1) {
        return;
    }
    window = (u8 *)inner + 0x10;
    InitWindow(window);
    AddWindowParameterized(PTR_AT(scene, 0x24), window, 2, 0x10, 0x13, 0x10, 4, 0xE, 0x12C);
    FillWindowPixelBuffer(window, 0);
    fmt = ov40_0222DAB0(0x6D);
    formatted = String_New(0xFF, 0x6D);
    source = NewString_ReadMsgData(PTR_AT(scene, 0x48), 0x38);
    line = String_New(0xFF, 0x6D);
    sub_0202BE60(PTR_AT(inner, 0x22C), line);
    ov40_02230DCC(scene, line);
    word = sub_0202BE98(PTR_AT(inner, 0x22C));
    BufferString(fmt, 0, line, 0, 1, 2);
    BufferECWord(fmt, 1, word);
    StringExpandPlaceholders(fmt, formatted, source);
    lineCount = String_CountLines(formatted);
    for (i = 0; i < lineCount; i++) {
        y = i * 0x10;
        u32 width;
        String_GetLineN(line, formatted, i);
        width = FontID_String_GetWidth(0, line, 0);
        width = (0x80 - width) >> 1;
        AddTextPrinterParameterizedWithColor(window, 0, line, width, y, 0xFF, 0xF0D00, NULL);
    }
    ScheduleWindowCopyToVram(window);
    String_Delete(line);
    String_Delete(source);
    String_Delete(formatted);
    MessageFormat_Delete(fmt);
}

void ov40_02235C7C(void *scene) {
    void *inner = PTR_AT(scene, 0x860);
    void *window;
    void *formatted;
    void *source;
    void *fmt;
    void *line;
    void *word;
    u32 lineCount;
    u32 i;
    u32 y;

    if (WindowIsInUse((u8 *)inner + 0x10) == 1) {
        return;
    }
    window = (u8 *)inner + 0x10;
    InitWindow(window);
    AddWindowParameterized(PTR_AT(scene, 0x24), window, 2, 0x10, 0x13, 0x10, 4, 0xE, 0x12C);
    FillWindowPixelBuffer(window, 0);
    fmt = ov40_0222DAB0(0x6D);
    formatted = String_New(0xFF, 0x6D);
    source = NewString_ReadMsgData(PTR_AT(scene, 0x48), 0x38);
    line = String_New(0xFF, 0x6D);
    sub_0202BE60(PTR_AT(inner, 0x238), line);
    ov40_02230DCC(scene, line);
    word = sub_0202BE98(PTR_AT(inner, 0x238));
    BufferString(fmt, 0, line, 0, 1, 2);
    BufferECWord(fmt, 1, word);
    StringExpandPlaceholders(fmt, formatted, source);
    lineCount = String_CountLines(formatted);
    for (i = 0; i < lineCount; i++) {
        y = i * 0x10;
        u32 width;
        String_GetLineN(line, formatted, i);
        width = FontID_String_GetWidth(0, line, 0);
        width = (0x80 - width) >> 1;
        AddTextPrinterParameterizedWithColor(window, 0, line, width, y, 0xFF, 0xF0D00, NULL);
    }
    ScheduleWindowCopyToVram(window);
    String_Delete(line);
    String_Delete(source);
    String_Delete(formatted);
    MessageFormat_Delete(fmt);
}

#ifndef OMIT_UNMATCHED
BOOL ov40_02235DAC(Ov40SceneU19 *scene, u32 selection) {
    Ov40SceneU19 *work;
    u32 found = FALSE;
    u32 count;
    u16 *list;
    void *pokedex;
    int i;
    u32 next;
    u16 *table;
    u16 end;
    u16 start;

    next = selection + 1;
    table = ov40_02245CD4;
    end = table[next];
    start = table[selection];
    work = scene;

    list = ov40_0222DD68(0x6D, 0, &count);
    pokedex = Save_Pokedex_Get(work->save);
    for (i = start; i < end; i++) {
        if (!Pokedex_CheckMonSeenFlag(pokedex, list[i])) {
            list[i] = 0xFFFF;
        }
    }
    for (i = start; i < end; i++) {
        if (list[i] != 0xFFFF) {
            found = TRUE;
            break;
        }
    }
    Heap_Free(list);
    return found;
}

void ov40_02235E34(void *scene, u32 selection) {
    void *inner = PTR_AT(scene, 0x860);
    u32 next = selection + 1;
    u16 *table = ov40_02245CD4;
    u16 end = table[next];
    u16 start = table[selection];
    u16 *list;
    void *pokedex;
    int i;
    int kept;
    int dstOffset;
    int srcOffset;
    int recordOffset;

    PTR_AT(inner, 0x1DC) = ov40_0222DD68(0x6D, 0, (u32 *)((u8 *)inner + 0x1D8));
    list = ov40_0222DD68(0x6D, 0, (u32 *)((u8 *)inner + 0x1D8));
    pokedex = Save_Pokedex_Get(PTR_AT(scene, 0x830));
    U32_AT(inner, 0x1D4) = 0;
    for (i = start; i < end; i++) {
        if (!Pokedex_CheckMonSeenFlag(pokedex, list[i])) {
            list[i] = 0xFFFF;
        } else {
            U32_AT(inner, 0x1D4)
            ++;
        }
    }
    kept = 0;
    dstOffset = kept;
    for (i = start; i < end; i++) {
        if (list[i] != 0xFFFF) {
            *(u16 *)((u8 *)PTR_AT(inner, 0x1DC) + dstOffset) = list[i];
            kept++;
            dstOffset += 2;
        }
    }
    while (kept < (int)U32_AT(inner, 0x1D8)) {
        ((u16 *)PTR_AT(inner, 0x1DC))[kept] = list[kept];
        kept++;
    }
    Heap_Free(list);
    PTR_AT(inner, 0x1E8) = Heap_Alloc(0x6D, U32_AT(inner, 0x1D4) << 4);
    MI_CpuFill8(PTR_AT(inner, 0x1E8), 0, U32_AT(inner, 0x1D4) << 4);
    i = 0;
    if (i < (int)U32_AT(inner, 0x1D4)) {
        srcOffset = i;
        recordOffset = i;
        do {
            U32_AT(PTR_AT(inner, 0x1E8), recordOffset) = *(u16 *)((u8 *)PTR_AT(inner, 0x1DC) + srcOffset);
            U32_AT(PTR_AT(inner, 0x1E8), recordOffset + 4) = *(u16 *)((u8 *)PTR_AT(inner, 0x1DC) + srcOffset);
            i++;
            srcOffset += 2;
            recordOffset += 0x10;
        } while (i < (int)U32_AT(inner, 0x1D4));
    }
    PTR_AT(inner, 0x1E0) = NewMsgDataFromNarc(0, 0x1B, 0xED, 0x6D);
    U32_AT(inner, 0x1E4) = 1;
}
#endif
