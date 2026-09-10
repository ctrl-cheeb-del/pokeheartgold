#include "global.h"
typedef struct Window {
    u32 raw[4];
} Window;
typedef struct WindowTemplate {
    u8 raw[8];
} WindowTemplate;
typedef struct String String;
typedef struct MsgData MsgData;
typedef struct SummaryState {
    u8 raw[0x800];
} SummaryState;
typedef struct SummarySelection {
    u8 low : 4;
    u8 high : 4;
} SummarySelection;
#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define U32(s, off)       (*(u32 *)&(s)->raw[(off)])
#define U16(s, off)       (*(u16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])
#define S8(s, off)        (*(s8 *)&(s)->raw[(off)])
#define SEL(s)            (*(SummarySelection *)&(s)->raw[0x7bd])

extern const WindowTemplate _02104D94[34];
void AddWindow(void *, Window *, const WindowTemplate *);
void FillWindowPixelBuffer(Window *, int);
void RemoveWindow(Window *);
void ClearWindowTilemapAndScheduleTransfer(Window *);
void ClearWindowTilemapAndCopyToVram(Window *);
void WindowArray_Delete(Window *, u8);
void ScheduleWindowCopyToVram(Window *);
void ScheduleBgTilemapBufferTransfer(void *, int);
void ReadMsgDataIntoString(MsgData *, int, String *);
String *NewString_ReadMsgData(MsgData *, int);
void String_Delete(String *);
void BufferIntegerAsString(void *, int, int, int, int, int);
void StringExpandPlaceholders(void *, String *, String *);
void AddTextPrinterParameterizedWithColor(Window *, int, String *, int, int, int, u32, void *);
void BgCommitTilemapBufferToVram(void *, int);
void DrawFrameAndWindow2(Window *, int, int, int);
int GetRibbonAttr(int, int);
int GetRibbonDescGmm(void *, int);
int FontID_String_GetWidth(int, String *, int);
int GetWindowWidth(Window *);
extern const s8 gNatureStatMods[][5];
int String_Compare(String *, String *);
void sub_0208C4E0(SummaryState *);
void sub_0208C57C(SummaryState *);
void sub_0208C614(SummaryState *);
void sub_0208C6B4(SummaryState *);
void sub_0208C9A4(SummaryState *);
void sub_0208C778(SummaryState *, Window *, u32, int);
void sub_0208C7F8(SummaryState *, int, int, int, int);
void sub_0208D884(SummaryState *, int);
void *sub_0208A520(SummaryState *);
void *AllocMonZeroed(int);
void CopyBoxPokemonToPokemon(void *, void *);
void Heap_Free(void *);
void sub_0208CFB4(Window *, void *, int);

void sub_0208C3E4(SummaryState *);
void sub_0208C560(SummaryState *);
int sub_0208C73C(SummaryState *);
void sub_0208C850(SummaryState *, int, int, u32, int);
void sub_0208C87C(SummaryState *, int, int, int, u8);
int sub_0208D078(SummaryState *);
void sub_0208D0A4(SummaryState *);
void sub_0208DAD4(SummaryState *);
void sub_0208D6B8(SummaryState *);
void sub_0208D474(SummaryState *);
void sub_0208D728(SummaryState *);
void sub_0208D7C4(SummaryState *);
void sub_0208DB1C(SummaryState *);
void sub_0208DB58(SummaryState *);
void sub_0208DB64(SummaryState *);
void sub_0208DBF0(SummaryState *);
void sub_0208DC68(SummaryState *, int);
void sub_0208DD20(SummaryState *, int);
void sub_0208DDA0(SummaryState *, int);
