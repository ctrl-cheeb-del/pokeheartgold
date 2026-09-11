#include "overlay96_course_helpers_private.h"
#include <string.h>

void ov96_021E952C(Ov96R18Work *w) {
    int i;
    if (w->ready != 0) GF_AssertFail();
    if (w->ready == 0) {
        for (i = 0; i < w->count; i++) w->totals[w->entries[i]->slot] += w->entries[i]->amount;
        w->ready = 1;
    }
}

void ov96_021E9570(Ov96R18Work *w, int index) {
    int i; u32 values[4] = {0,0,0,0};
    if (index >= 10) GF_AssertFail();
    for (i = 0; i < w->count; i++) values[w->entries[i]->slot] += w->entries[i]->amount;
    for (i = 0; i < 4; i++) w->results[index][i] = values[i];
}

u32 ov96_021E95D8(Ov96R18Work *w, int a, int b) {
    if (a >= 10) GF_AssertFail();
    return w->results[a][b];
}

void ov96_021E95F8(PokeathlonCourseData *course, void *p, u32 value, u32 kind, u8 idx, u8 digits, u32 msgno) {
    enum HeapID heap=PokeathlonCourse_GetHeapID(course); MsgData *msg=NewMsgDataFromNarc((MsgDataLoadType)1, NARC_msgdata_msg, 0x135, heap);
    u8 *dst=ov96_021E9344(p); MessageFormat *fmt; String *str;
    *(u32 *)dst=value; *(u32 *)(dst+0xC)=kind; fmt=MessageFormat_New(heap);
    BufferIntegerAsString(fmt, idx, kind, digits, (PrintingMode)1, 1);
    str=ReadMsgData_ExpandPlaceholders(fmt,msg,msgno,heap); MessageFormat_Delete(fmt); String_Copy(*(String **)(dst+0x10),str); String_Delete(str); DestroyMsgData(msg);
}

void ov96_021E966C(PokeathlonCourseData *course, void *p, u32 value, u32 kind, u32 v1, u32 v2, u8 i1, u8 i2, u8 d1, u8 d2, u32 msgno) {
    enum HeapID heap=PokeathlonCourse_GetHeapID(course); MsgData *msg=NewMsgDataFromNarc((MsgDataLoadType)1, NARC_msgdata_msg, 0x135, heap);
    u8 *dst=ov96_021E9344(p); MessageFormat *fmt; String *str;
    *(u32 *)dst=value; *(u32 *)(dst+0xC)=kind; fmt=MessageFormat_New(heap);
    BufferIntegerAsString(fmt, i1, v1, d1, (PrintingMode)1, 1);
    BufferIntegerAsString(fmt, i2, v2, d2, (PrintingMode)1, 1);
    str=ReadMsgData_ExpandPlaceholders(fmt,msg,msgno,heap); MessageFormat_Delete(fmt); String_Copy(*(String **)(dst+0x10),str); String_Delete(str); DestroyMsgData(msg);
}

void ov96_021E96F8(u32 a,u32 b,u8 *p,PokeathlonCourseData *course) { ov96_021E5E04(course,p); PokeathlonCourse_SetStateTransitionType(course,1); PokeathlonCourse_SetStateField07(course,1); }
