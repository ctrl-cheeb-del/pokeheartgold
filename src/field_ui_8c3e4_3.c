#include "field_ui_8c3e4_internal.h"

int sub_0208D078(SummaryState *state) {
    return U8(state, 0x294) + U8(state, 0x295) + U8(state, 0x296) + U8(state, 0x297) + U8(state, 0x298) + U8(state, 0x299);
}

void sub_0208D0A4(SummaryState *state) {
    void *boxmon;
    int unchanged;
    void *mon;
    String *str;

    ScheduleWindowCopyToVram((Window *)&state->raw[0x14]);
    FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x60), 0);
    boxmon = sub_0208A520(state);
    unchanged = sub_0208C73C(state);
    if (U8((SummaryState *)PTR(state, 0x22c, void), 0x11) == 2) {
        mon = AllocMonZeroed(0x13);
        CopyBoxPokemonToPokemon(boxmon, mon);
        sub_0208CFB4((Window *)((u8 *)PTR(state, 0x224, Window) + 0x60), mon, unchanged);
        Heap_Free(mon);
    } else {
        sub_0208CFB4((Window *)((u8 *)PTR(state, 0x224, Window) + 0x60), boxmon, unchanged);
    }
    ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x60));
    if (sub_0208D078(state) != 0) {
        FillWindowPixelBuffer((Window *)((u8 *)PTR(state, 0x224, Window) + 0x70), 0);
        str = NewString_ReadMsgData(PTR(state, 0x7a0, MsgData), 0xc0);
        AddTextPrinterParameterizedWithColor((Window *)((u8 *)PTR(state, 0x224, Window) + 0x70), 0, str, 0, 0, 0, 0x10200, 0);
        ScheduleWindowCopyToVram((Window *)((u8 *)PTR(state, 0x224, Window) + 0x70));
        String_Delete(str);
    }
}
