#include "global.h"

typedef struct Window {
    u8 raw[0x10];
} Window;
typedef struct MsgData MsgData;
typedef struct MessageFormat MessageFormat;
typedef struct String String;
typedef struct Ov98TextContext {
    int heapId;
    Window *windows;
    MsgData *msgData;
    MsgData *msgDataFixed;
    MessageFormat *msgFormat;
    String *string;
    u32 windowCount;
} Ov98TextContext;

String *NewString_ReadMsgData(MsgData *, s32);
void StringExpandPlaceholders(MessageFormat *, String *, String *);
void ov98_0221EF14(Ov98TextContext *, u32);
u8 AddTextPrinterParameterizedWithColor(Window *, int, String *, u32, u32, u32, u32, void *);
void ScheduleWindowCopyToVram(Window *);
void String_Delete(String *);
void ov98_0221ED48(Ov98TextContext *, u32, u32, u32, u8);
