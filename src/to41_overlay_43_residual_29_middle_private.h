#ifndef OV43_R29_MIDDLE_PRIVATE_H
#define OV43_R29_MIDDLE_PRIVATE_H

#include "global.h"

typedef struct String String;
typedef struct Window Window;

void *sub_0202C6F4(void *);
u32 sub_0202C090(void *, u32, u32);
void *Save_Frontier_GetStatic(void *);
u32 FrontierSave_GetStat(void *, u32, u32);
String *String_New(u32, u32);
String *GetSpeciesName(u32, u32);
void String_Delete(String *);
void ReadMsgDataIntoString(void *, u32, String *);
void StringExpandPlaceholders(void *, String *, String *);
u32 FontID_String_GetWidth(u32, String *, u32);
u8 AddTextPrinterParameterizedWithColor(Window *, u32, String *, u32, u32, u32, u32, void *);
void FillBgTilemapRect(void *, u32, u32, u32, u32, u32, u32, u32);
void ScheduleBgTilemapBufferTransfer(void *, u32);
void ov43_0222ABFC(void *, u32);
void ov43_0222AC18(void *, u32);
void ov43_0222DEF8(void *, u32);

void ov43_0222EC58(void *, u32, u32, void *, void *, u32, u32, u32, u32, String *, String *, u32);
void ov43_0222DFB0(void *, void *, void *);
void ov43_0222E0E8(void *, void *, void *);
void ov43_0222E904(void *, void *, void *, u32);
void ov43_0222E78C(void *, void *, void *, u32);
void ov43_0222E5B4(void *, void *, void *, u32);
void ov43_0222EA40(void *, void *, void *, u32);
void ov43_0222EBD8(void *, void *, void *);
void ov43_0222EC14(void *, const volatile s16 *);

#endif
