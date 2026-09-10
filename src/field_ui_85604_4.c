#include "global.h"

typedef struct SelectionRecord {
    u16 x, y;
} SelectionRecord;
typedef struct TouchBounds {
    s16 x, y, width, height;
} TouchBounds;
typedef struct MenuEntry {
    u32 value, id, kind;
    void *sprite;
    u8 pad10[0xC];
} MenuEntry;
typedef union OverlayState {
    u8 raw[0x400];
    MenuEntry entries[36];
} OverlayState;
typedef struct SelectionState {
    u8 pad000[0x2AA];
    SelectionRecord records[10];
    u8 pad2D2[2];
    u32 current;
    u32 previous;
    u32 currentX;
    u32 currentY;
    u32 previousX;
    u32 previousY;
} SelectionState;
typedef int (*OverlayUpdateFunc)(OverlayState *);
extern const OverlayUpdateFunc _0210271C[4];

extern void BeginNormalPaletteFade(u32, u32, u32, u32, u32, u32, u32);
extern BOOL IsPaletteFadeFinished(void);
extern void sub_02086328(OverlayState *);
extern int TouchHitboxController_IsTriggered(void *);
extern void sub_02085C20(OverlayState *);
extern void sub_02086BB4(OverlayState *);
extern void sub_02086C8C(OverlayState *);
extern void SpriteSystem_DrawSprites(void *);
extern void sub_02085604(OverlayState *, int);
extern void sub_02086DA4(OverlayState *);
extern void sub_02086DE4(OverlayState *, int);
extern void sub_02086AE4(OverlayState *, int);
extern void *String_New(u32, u32);
extern void String_Delete(void *);
extern void String16_FormatInteger(void *, int, int, int, int);
extern void String_Cat(void *, const void *);
extern int sub_02086D98(int, int);
extern void ManagedSprite_SetAnim(void *, int);
extern void sub_02086490(OverlayState *);
extern void sub_02086758(OverlayState *);
extern void sub_020868A0(OverlayState *);
extern void sub_020869BC(OverlayState *);
extern void sub_02086F44(OverlayState *);
extern void sub_02086FCC(OverlayState *);
extern void sub_02087064(OverlayState *);
extern void sub_020871C4(void *, void *, int, int, int, int, int, int, void *);
extern void *sub_0203A4AC(int);
extern void PaletteData_LoadPalette(void *, void *, int, int, int);
extern void Heap_Free(void *);
extern void *TouchHitboxController_Create(void *, int, void *, void *, int);
extern void sub_02086180(void);

void sub_02085604(OverlayState *, int);
void sub_02085808(OverlayState *, int);
BOOL sub_02085820(OverlayState *);
BOOL sub_020858DC(OverlayState *);
BOOL sub_02085938(OverlayState *);
int sub_02085BEC(OverlayState *);
void sub_02085F80(OverlayState *);
void sub_02085FFC(OverlayState *);
void sub_020860B8(OverlayState *);
void sub_02086328(OverlayState *);
void sub_02086384(OverlayState *);
int sub_02086398(void *, int);
int sub_020863C0(void *, int);

void sub_02085F80(OverlayState *state) {
    void *numberString = String_New(0x64, 0x6C);
    int i;
    u8 *entry;
    *(u32 *)&state->raw[0x284] = 1;
    state->raw[0x29C] = 0;
    i = 0;
    if (*(s32 *)&state->raw[0x2D0] > 0) {
        entry = state->raw;
        do {
            if (*(u32 *)entry == 0) {
                *(u32 *)entry = 1;
                ManagedSprite_SetAnim(*(void **)(entry + 0xC), sub_02086D98(1, *(u32 *)(entry + 8)));
            }
            String16_FormatInteger(numberString, *(u32 *)entry - 1, 1, 1, 1);
            String_Cat(*(void **)&state->raw[0x3D4], numberString);
            i++;
            entry += 0x1C;
        } while (i < *(s32 *)&state->raw[0x2D0]);
    }
    String_Delete(numberString);
    sub_02085808(state, 3);
}
