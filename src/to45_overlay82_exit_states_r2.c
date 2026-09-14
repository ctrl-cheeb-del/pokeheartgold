#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
BOOL IsPaletteFadeFinished(void);
void ov82_0223F90C(void *work);
void ov82_0223F834(void *work);
void ov82_0223FCB0(void *object, int value);
void ClearFrameAndWindow2(void *window, int dontCopy);
void ov82_0223FC9C(void *object);
void ov82_0223FDC0(void *object);
void sub_0203A914(void);
void PaletteData_FreeBuffers(void *paletteData, int id);
void PaletteData_Free(void *paletteData);
void ov82_0223FBBC(void *object);
void DestroyMsgData(void *msgData);
void MessageFormat_Delete(void *messageFormat);
void String_Delete(void *string);
void MessagePrinter_Delete(void *printer);
void ov82_0223FD5C(void *window);
void ov82_0223EBB8(void *bgConfig);
void NARC_Delete(void *narc);
void ov82_0223E9B0(void);
void *BgConfig_Alloc(int heapId);
void ov82_0223E9E8(void *work);
u32 ov80_02237920(u8 value);
void ov82_0223FCFC(void *object, int value);
void ov82_0223FCBC(void *object, int x, int y);

BOOL ov82_0223E820(void *work);
BOOL ov82_0223E888(void *work);
void ov82_0223E8C4(void *work);
void ov82_0223E974(void *work);

BOOL ov82_0223E820(void *work) {
    switch (U8(work, 8)) {
    case 0:
        U8(work, 0x1B) = 10;
        U8(work, 8)
        ++;
        break;
    case 1:
        U8(work, 0x1B)
        --;
        if (U8(work, 0x1B) == 0) {
            ov82_0223F90C(work);
            BeginNormalPaletteFade(0, 0, 0, 0, 6, 1, 0x69);
            U8(work, 8)
            ++;
        }
        break;
    case 2:
        if (IsPaletteFadeFinished() == TRUE) {
            return TRUE;
        }
        break;
    }
    return FALSE;
}

BOOL ov82_0223E888(void *work) {
    switch (U8(work, 8)) {
    case 0:
        ov82_0223F834(work);
        ov82_0223FCB0(PTR(work, 0x208), 1);
        ClearFrameAndWindow2((u8 *)work + 0x4C, FALSE);
        U8(work, 8)
        ++;
        break;
    case 1:
        return TRUE;
    }
    return FALSE;
}

void ov82_0223E8C4(void *work) {
    int i;
    u8 *cursor;

    if (PTR(work, 0x204) != NULL) {
        ov82_0223FC9C(PTR(work, 0x204));
    }
    if (PTR(work, 0x208) != NULL) {
        ov82_0223FC9C(PTR(work, 0x208));
    }
    ov82_0223FDC0(PTR(work, 0x8C));
    sub_0203A914();
    PaletteData_FreeBuffers(PTR(work, 0x94), 2);
    PaletteData_FreeBuffers(PTR(work, 0x94), 0);
    PaletteData_Free(PTR(work, 0x94));
    PTR(work, 0x94) = NULL;
    ov82_0223FBBC((u8 *)work + 0xA8);
    DestroyMsgData(PTR(work, 0x20));
    MessageFormat_Delete(PTR(work, 0x24));
    String_Delete(PTR(work, 0x28));
    String_Delete(PTR(work, 0x2C));
    MessagePrinter_Delete(PTR(work, 0x98));
    i = 0;
    cursor = work;
    do {
        String_Delete(PTR(cursor, 0x30));
        i++;
        cursor += 4;
    } while (i < 2);
    ov82_0223FD5C((u8 *)work + 0x4C);
    ov82_0223EBB8(PTR(work, 0x48));
    NARC_Delete(PTR(work, 0x220));
}

void ov82_0223E974(void *work) {
    ov82_0223E9B0();
    PTR(work, 0x48) = BgConfig_Alloc(0x69);
    ov82_0223E9E8(work);
    if (ov80_02237920(U8(work, 0xD)) == 0xFE) {
        ov82_0223FCFC(PTR(work, 0x204), 2);
        ov82_0223FCBC(PTR(work, 0x204), 0x80, 0xA8);
    }
}
