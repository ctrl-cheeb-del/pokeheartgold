#include "global.h"

#define PTR(p, o) (*(void **)((u8 *)(p) + (o)))

extern void *NewString_ReadMsgData(void *, int);
extern void *ov40_0222DAB0(int);
extern void *sub_020315B8(void *, int);
extern void ov40_02230DCC(void *, void *);
extern void *String_New(int, int);
extern void BufferString(void *, int, void *, int, int, int);
extern void StringExpandPlaceholders(void *, void *, void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
extern void InitWindow(void *);
extern void AddTextWindowTopLeftCorner(void *, void *, int, int, int, int);
extern void AddTextPrinterParameterizedWithColor(void *, int, void *, int, int, int, int, void *);
extern void TextOBJ_CopyFromBGWindow(void *, void *, void *, int);
extern void RemoveWindow(void *);
extern void *sub_02013910(void *, int);
extern void *sub_02013688(void *, int, int);
extern void sub_02021AC8(void *, int, int, void *);
extern void ManagedSprite_GetPositionXY(void *, s16 *, s16 *);
extern void *SpriteManager_GetSpriteList(void *);
extern void *SpriteManager_FindPlttResourceProxy(void *, int);
extern void *TextOBJ_Create(const void *, void *);
extern void sub_020138E0(void *, int);
extern void TextOBJ_SetSpritesDrawFlag(void *, int);
extern const u32 ov40_02244DA8[];
extern const u8 ov40_02244DC0[];

typedef struct TextObjCreate {
    void *charData;
    void *window;
    void *spriteList;
    void *paletteProxy;
    void *resource;
    void *font;
    int y;
    int x;
    int priority;
    int palette;
    int variant;
    int heapId;
} TextObjCreate;

void ov40_0222D2A0(u8 *work);
void ov40_0222D3E8(u8 *work, u8 *entry, int msgId, u8 *selection);

void ov40_0222D3E8(u8 *work, u8 *entry, int msgId, u8 *selection) {
    u32 window[4];
    void *str;
    void *msgData = PTR(work, 0x48);

    if (msgId == 8) {
        void *value = PTR(work, 0x88c + *(u32 *)(selection + 0x18) * 4);
        if (value == NULL) {
            str = NewString_ReadMsgData(msgData, msgId);
        } else {
            void *format = ov40_0222DAB0(0x6d);
            void *template = NewString_ReadMsgData(PTR(work, 0x48), 7);
            void *name = sub_020315B8(PTR(work, 0x88c + *(u32 *)(selection + 0x18) * 4), 0x6d);
            ov40_02230DCC(work, name);
            str = String_New(0xff, 0x6d);
            BufferString(format, 0, name, 0, 1, 2);
            StringExpandPlaceholders(format, str, template);
            String_Delete(template);
            String_Delete(name);
            MessageFormat_Delete(format);
        }
    } else if (msgId == 0x29) {
        void *value = PTR(work, 0x88c + *(u32 *)(selection + 0x18) * 4);
        if (value == NULL) {
            str = NewString_ReadMsgData(msgData, msgId);
        } else {
            void *format = ov40_0222DAB0(0x6d);
            void *template = NewString_ReadMsgData(PTR(work, 0x48), 7);
            void *name = sub_020315B8(PTR(work, 0x88c + *(u32 *)(selection + 0x18) * 4), 0x6d);
            ov40_02230DCC(work, name);
            str = String_New(0xff, 0x6d);
            BufferString(format, 0, name, 0, 1, 2);
            StringExpandPlaceholders(format, str, template);
            String_Delete(template);
            String_Delete(name);
            MessageFormat_Delete(format);
        }
    } else {
        str = NewString_ReadMsgData(msgData, msgId);
    }

    InitWindow(window);
    AddTextWindowTopLeftCorner(PTR(work, 0x24), window, 0x14, 2, 0, 0);
    AddTextPrinterParameterizedWithColor(window, 0, str, 0, 0, 0xff, 0x000e0d00, NULL);
    TextOBJ_CopyFromBGWindow(PTR(entry, 0x14), PTR(entry, 0x18), window, 0x6d);
    String_Delete(str);
    RemoveWindow(window);
}
