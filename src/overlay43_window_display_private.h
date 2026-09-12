#ifndef POKEHEARTGOLD_OVERLAY43_WINDOW_DISPLAY_PRIVATE_H
#define POKEHEARTGOLD_OVERLAY43_WINDOW_DISPLAY_PRIVATE_H

#include "global.h"

typedef struct Ov43WindowMessageWork {
    u8 pad_00[0x50];
    void *formatted;
    void *msgData;
    u8 pad_58[0x24];
    void *expanded;
    void *raw;
} Ov43WindowMessageWork;

typedef struct Ov43WrappedCursor {
    s16 current;
    s16 previous;
    u8 pad_04[12];
    u32 mode;
} Ov43WrappedCursor;

void ov43_0222DF1C(void *, u32);
void ov43_0222EC14(void *, void *);
void ReadMsgDataIntoString(void *, int, void *);
void StringExpandPlaceholders(void *, void *, void *);
void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, int);

void ov43_0222DF90(void *, void *);
void ov43_0222ECD4(void *, int, void *, int, int, int, int);
void ov43_0222ED18(void *, int);

#endif
