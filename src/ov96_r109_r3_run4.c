#include "ov96_r109_r3_private.h"

void ov96_022140F4(void *course) {
    u8 i;
    u8 *work = PokeathlonCourse_GetHeapAllocPtr4(course);
    MsgData *msg = NewMsgDataFromNarc(MSGDATA_LOAD_LAZY, (NarcId)0x1b, 0x135, (enum HeapID) * (u32 *)(work + 0x58));
    MessageFormat *fmt = MessageFormat_New((enum HeapID) * (u32 *)(work + 0x58));
    *(String **)(work + 0x7b8) = NewString_ReadMsgData(msg, 0x133);
    *(String **)(work + 0x7bc) = NewString_ReadMsgData(msg, 0x134);
    *(String **)(work + 0x7c0) = NewString_ReadMsgData(msg, 0x135);
    for (i = 0; i < 4; i++) {
        String *name = PlayerProfile_GetPlayerName_NewString(
            PokeathlonCourse_GetPlayerProfileFromData(course, i),
            (enum HeapID) * (u32 *)(work + 0x58));
        BufferString(fmt, 0, name, 2, 1, 2);
        *(String **)(work + 0x7c4 + i * 4) = ReadMsgData_ExpandPlaceholders(fmt, msg, 0x132, (enum HeapID) * (u32 *)(work + 0x58));
        String_Delete(name);
    }
    MessageFormat_Delete(fmt);
    DestroyMsgData(msg);
}

void ov96_022141B0(void *course) {
    u8 i;
    u8 *w = PokeathlonCourse_GetHeapAllocPtr4(course);
    String_Delete(*(String **)(w + 0x7b8));
    String_Delete(*(String **)(w + 0x7bc));
    String_Delete(*(String **)(w + 0x7c0));
    for (i = 0; i < 4; i++) {
        u8 *item = w + i * 4;
        String_Delete(*(String **)(item + 0x7c4));
    }
}
