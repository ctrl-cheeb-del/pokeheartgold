#include "to46_overlay96_ui_resources_r57_private.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void ov96_021F424C(void *w) {
    u8 i;
    u32 self;
    String *name;
    u8 display;

    for (i = 0; i < 5; i++) {
        FillWindowPixelBuffer((u8 *)w + 0xC + i * 0x10, 0);
    }

    self = (u8)ov96_021E5F24(PTR(w, 4));
    name = PlayerProfile_GetPlayerName_NewString(
        PokeathlonCourse_GetPlayerProfileFromData(PTR(w, 4), self), (enum HeapID)U32(w, 0));
    AddTextPrinterParameterizedWithColor((u8 *)w + 0xC, 0, name, 0, 0, 0xFF, 0x000F0E00, NULL);
    String_Delete(name);
    Sprite_SetAnimCtrlSeq(ov96_021EB5B8(PTR(w, 0x130)), self + 0xE);
    U8(w, 0x170 + self) = 0;

    display = 1;
    for (i = 0; i < 4; i++) {
        if (i != self) {
            name = PlayerProfile_GetPlayerName_NewString(
                PokeathlonCourse_GetPlayerProfileFromData(PTR(w, 4), i), (enum HeapID)U32(w, 0));
            AddTextPrinterParameterizedWithColor((u8 *)w + 0xC + display * 0x10, 0, name, 0, 0, 0xFF, 0x000F0E00, NULL);
            String_Delete(name);
            Sprite_SetAnimCtrlSeq(ov96_021EB5B8(((void **)w)[0x130 / 4 + display]), i + 0xE);
            {
                u8 *participant = (u8 *)w + i;
                participant[0x170] = display;
            }
            display++;
        }
    }
    ov96_021F459C(w, 1);
    for (i = 0; i < 5; i++) {
        CopyWindowToVram((u8 *)w + 0xC + i * 0x10);
    }
}
