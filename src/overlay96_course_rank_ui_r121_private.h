#ifndef OVERLAY96_COURSE_RANK_UI_R121_PRIVATE_H
#define OVERLAY96_COURSE_RANK_UI_R121_PRIVATE_H

#include "global.h"

typedef struct Ov96RankUiWork {
    u8 data[0xC8];
} Ov96RankUiWork;

typedef struct Ov96RankUiFlags {
    u32 low : 14;
    u32 bit14 : 1;
    u32 bit15 : 1;
    u32 high : 16;
} Ov96RankUiFlags;

#define OV96_RANK_PTR(work, offset) (*(void **)((work)->data + (offset)))
#define OV96_RANK_U32(work, offset) (*(u32 *)((work)->data + (offset)))

int ov96_0221862C(Ov96RankUiWork *work);
u32 ov96_021E5F24(void *course);
void ManagedSprite_SetAnimNoRestart(void *sprite, int sequence);
void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
void FillWindowPixelBuffer(void *window, int value);
void BufferIntegerAsString(void *formatter, u32 field, u32 value, int digits, int mode, int padding);
void *ReadMsgData_ExpandPlaceholders(void *formatter, void *messages, u32 message, void *context);
void AddTextPrinterParameterizedWithColor(void *window, int font, void *string, int x, int y, u32 speed, int color, int spacing);
void String_Delete(void *string);
void CopyWindowToVram(void *window);
void ov96_022196E4(Ov96RankUiWork *work, s32 value);
void ov96_02219C30(Ov96RankUiWork *work);
void ov96_02219A5C(Ov96RankUiWork *work, u32 value);
void ov96_02219B30(Ov96RankUiWork *work);
void NARC_Delete(void *narc);
void Heap_Free(void *ptr);
void RemoveWindow(void *window);
void Sprite_DeleteAndFreeResources(void *sprite);
void ManagedSprite_SetAnimateFlag(void *sprite, int flag);
void ManagedSprite_SetDrawFlag(void *sprite, int flag);
void Sprite_SetAnimCtrlSeq(void *sprite, int sequence);
void ov96_022193F8(void *course, u32 number);
void ov96_02219460(Ov96RankUiWork *work, void *arg0, u32 flag);
void ov96_022195C8(Ov96RankUiWork *work);
void ov96_022195E8(Ov96RankUiWork *work);
void ov96_0221964C(Ov96RankUiWork *work);
void ov96_022196E4(Ov96RankUiWork *work, s32 value);
void ov96_02219770(Ov96RankUiWork *work, int first, int second);

#endif
