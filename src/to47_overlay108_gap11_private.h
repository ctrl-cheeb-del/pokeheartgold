#include "global.h"

#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define U16(p, o) (*(u16 *)((u8 *)(p) + (o)))
#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

void Sprite_SetAnimCtrlSeq(void *, int);
void Sprite_ResetAnimCtrlState(void *);
void FillWindowPixelBuffer(void *, int);
int FontID_String_GetWidth(u32, void *, u32);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, u32, int);
void ScheduleWindowCopyToVram(void *);
void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
void CopyToBgTilemapRect(void *, int, int, int, int, int, void *, int, int, int, int);
void ScheduleBgTilemapBufferTransfer(void *, int);
void ReadMsgDataIntoString(void *, int, void *);
void BufferIntegerAsString(void *, int, int, int, int, int);
void StringExpandPlaceholders(void *, void *, void *);
void ClearWindowTilemapAndScheduleTransfer(void *);
int ov108_021EA52C(void *, int);

extern const u32 ov108_021EAAA4[];

typedef struct SafariWorkGap11 {
    u8 pad000[0x30C];
    void *msgData;
    void *format;
    void *expanded;
    void *message;
    u8 pad31C[0x10];
    void *templateString;
    void *titleString;
    u8 *records;
    u8 pad338[0xF5];
    u8 recordCount;
    u8 pageCount;
    u8 pad42F;
    u8 page;
    u8 pad431;
    u8 selected;
    u8 pad433[5];
    void *bg;
    u8 pad43C[0x10];
    void *leftSprite;
    void *rightSprite;
    u8 windows[0xC8];
    void *tileData;
} SafariWorkGap11;

void ov108_021E9F20(void *, int);
void ov108_021E9F94(void *, int);
void ov108_021EA040(void *);
void ov108_021EA260(void *);
