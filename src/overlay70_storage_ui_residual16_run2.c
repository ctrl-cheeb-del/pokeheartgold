#include "overlay70_storage_ui_residual16_private.h"

void ov70_0223A72C(void *msgData, void *windowsA, const u16 *name, void *mon, void *windowsB) {
    void *nameString = String_New(0x10, 0x3D);
    void *monString = String_New(0x10, 0x3D);
    void *label = NewString_ReadMsgData(msgData, 0x31);
    void *typeLabel;
    CopyU16ArrayToString(nameString, name);
    typeLabel = NewString_ReadMsgData(msgData, 0xB4);
    GetMonData(mon, 0x91, monString);
    ov70_02245084(windowsA, label, 0, 0, 0, 0xF0200);
    ov70_02245084((u8 *)windowsA + 0x10, nameString, 0, 0, 0, 0x10200);
    ov70_02245084(windowsB, typeLabel, 0, 0, 0, 0xF0200);
    ov70_02245084((u8 *)windowsB + 0x10, monString, 0, 0, 0, 0x10200);
    String_Delete(label);
    String_Delete(nameString);
    String_Delete(typeLabel);
    String_Delete(monString);
}

void ov70_0223A7E4(void *mon) {
    u16 ids[8];
    void *buf = Heap_Alloc(0x3D, 0xC80);
    int species;
    int form;
    GetPokemonSpriteCharAndPlttNarcIds(ids, mon, 2);
    species = GetMonData(mon, 0, NULL);
    form = GetMonData(mon, 5, NULL);
    sub_02014494(ids[0], ids[1], 0x3D, 0, 0, 10, 10, buf, species, 0, 2, form);
    DC_FlushRange(buf, 0xC80);
    GX_LoadOBJ(buf, 0x4A00, 0xC80);
    GfGfxLoader_GXLoadPal(ids[0], ids[2], 1, 0x1A0, 0x20, 0x3D);
    Heap_Free(buf);
}

void ov70_0223A874(Ov70Work *work) {
    int value = ov70_0223F864(work->field22F, work->field230, 0);
    ov70_0223F470(work->msgDataBA0, work->stringBA4, work->msgFmtB9C,
        work->window10E8, work->field22C, work->field22E, value);
}
