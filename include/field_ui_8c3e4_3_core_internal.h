#include "global.h"

typedef struct Window {
    u32 raw[4];
} Window;
typedef struct String String;
typedef struct MsgData MsgData;
typedef struct SummaryState {
    u8 raw[0x800];
} SummaryState;
typedef struct PackedLevel {
    u8 value : 7;
    u8 flag : 1;
} PackedLevel;
typedef struct Unk0208E600Result {
    u8 pad[0x14];
    u32 x1;
    String *s1;
    u32 x2;
    String *s2;
    u32 x3;
    String *s3;
    u8 pad2[8];
    u32 x4;
    String *s4;
} Unk0208E600Result;

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define U32(s, off)       (*(u32 *)&(s)->raw[(off)])
#define U16(s, off)       (*(u16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])
#define S8(s, off)        (*(s8 *)&(s)->raw[(off)])
#define LEVEL(s)          (*(PackedLevel *)&(s)->raw[0x242])

void FillWindowPixelBuffer(Window *, int);
void ClearWindowTilemapAndScheduleTransfer(Window *);
void ScheduleWindowCopyToVram(Window *);
void ReadMsgDataIntoString(MsgData *, int, String *);
void AddTextPrinterParameterizedWithColor(Window *, int, String *, int, int, int, u32, void *);
void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
int FontID_String_GetWidth(int, String *, int);
int FontID_String_GetCenterAlignmentX(int, String *, int, int);
int Pokedex_ConvertToCurrentDexNo(void *, u16);
void sub_0208C778(SummaryState *, Window *, u32, int);
void sub_0208C7F8(SummaryState *, int, int, int, int);
void sub_0208C850(SummaryState *, int, int, u32, int);
void sub_0208C87C(SummaryState *, int, int, int, u8);
void sub_0208CC88(SummaryState *);
void sub_0208D0A4(SummaryState *);
void sub_0208D178(SummaryState *);
void sub_0208D474(SummaryState *);
void sub_0208D520(SummaryState *);
void sub_0208D6B8(SummaryState *);
void sub_0208D728(SummaryState *);
Unk0208E600Result *sub_0208E600(void *, int, int);
void sub_0208E994(Unk0208E600Result *);
void sub_0208C9A4(SummaryState *);
void sub_0208CBD4(SummaryState *);
void sub_0208CFB4(Window *, void *, int);
void sub_0208C8C8(SummaryState *, int, int, int, int, u16, u16, volatile u8, u8, u8);
