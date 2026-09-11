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
    void *bgConfig;
    Window windows[34];
    Window *dynamicWindows;
    u32 numDynamicWindows;
    void *monData;
    u8 pad230[0x7bc - 0x230];
    s8 page;
    u8 pad7bd[0x800 - 0x7bd];
} SummaryState;
typedef struct SummarySelection {
    u8 low : 4;
    u8 high : 4;
} SummarySelection;
#define PTR(s, off, type) (*(type **)((u8 *)(s) + (off)))
#define U32(s, off)       (*(u32 *)((u8 *)(s) + (off)))
#define U16(s, off)       (*(u16 *)((u8 *)(s) + (off)))
#define U8(s, off)        (*(u8 *)((u8 *)(s) + (off)))
#define S8(s, off)        (*(s8 *)((u8 *)(s) + (off)))
#define SEL(s)            (*(SummarySelection *)((u8 *)(s) + 0x7bd))

extern volatile WindowTemplate _02104D94[34];
void AddWindow(void *, Window *, volatile const WindowTemplate *);
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

extern const WindowTemplate _02104C84[];
extern const WindowTemplate _02104CC4[];
extern const WindowTemplate _02104D04[];
Window *AllocWindows(u32 heapId, u8 count);
void sub_0208C42C(SummaryState *state);
