#include "global.h"

typedef struct MsgData MsgData;
typedef struct MessageFormat MessageFormat;
typedef struct String String;

typedef struct {
    u8 pad00[0x10];
    void *bg;
    u8 pad14[0xC];
    void *narc;
} State;

typedef struct {
    u16 width, height;
    u8 pad04[8];
    u8 raw[1];
} ScrnData;

extern void *GfGfxLoader_GetScrnDataFromOpenNarc(void *, int, int, ScrnData **, int);
extern void LoadRectToBgTilemapRect(void *, int, void *, int, int, int, int);
extern void Heap_Free(void *);
extern void BgCommitTilemapBufferToVram(void *, int);
extern MsgData *NewMsgDataFromNarc(int, int, int, int);
extern MessageFormat *MessageFormat_New(int);
extern String *String_New(int, int);
extern void ReadMsgDataIntoString(MsgData *, int, String *);
extern void BufferTrainerName(MessageFormat *, int, void *);
extern void StringExpandPlaceholders(MessageFormat *, String *, String *);
extern void DestroyMsgData(MsgData *);
extern void MessageFormat_Delete(MessageFormat *);
extern void String_Delete(String *);
extern void ov117_0225F524(void *, void *, const u8 *);
extern const u8 _0225FACC[];
extern const u8 ov117_0225FAD4[];
extern const u8 ov117_0225FADC[];
extern const u8 ov117_0225FAE4[];
extern const u8 ov117_0225FAEC[];

void ov117_0225F420(State *, int, int);
String *ov117_0225F470(void *, int);
void ov117_0225F4D4(void *, void *);
void ov117_0225F4E4(void *, void *);
void ov117_0225F4F4(void *, void *);
void ov117_0225F504(void *, void *);
void ov117_0225F514(void *, void *);

void ov117_0225F420(State *state, int bgId, int member) {
    ScrnData *scrn;
    void *allocation = GfGfxLoader_GetScrnDataFromOpenNarc(state->narc, member, 0, &scrn, 4);
    LoadRectToBgTilemapRect(*(void **)((u8 *)state->bg + 8), bgId, scrn->raw, 0, 0, ((u32)scrn->width << 21) >> 24, ((u32)scrn->height << 21) >> 24);
    Heap_Free(allocation);
    BgCommitTilemapBufferToVram(*(void **)((u8 *)state->bg + 8), bgId);
}

String *ov117_0225F470(void *trainer, int heapId) {
    MsgData *msg = NewMsgDataFromNarc(1, 0x1B, 0xBD, heapId);
    MessageFormat *fmt = MessageFormat_New(heapId);
    String *out = String_New(0x80, heapId);
    String *src = String_New(0x80, heapId);
    ReadMsgDataIntoString(msg, 0, src);
    BufferTrainerName(fmt, 0, trainer);
    StringExpandPlaceholders(fmt, out, src);
    DestroyMsgData(msg);
    MessageFormat_Delete(fmt);
    String_Delete(src);
    return out;
}

void ov117_0225F4D4(void *a, void *b) {
    ov117_0225F524(a, b, _0225FACC);
}

void ov117_0225F4E4(void *a, void *b) {
    ov117_0225F524(a, b, ov117_0225FAD4);
}

void ov117_0225F4F4(void *a, void *b) {
    ov117_0225F524(a, b, ov117_0225FADC);
}

void ov117_0225F504(void *a, void *b) {
    ov117_0225F524(a, b, ov117_0225FAE4);
}

void ov117_0225F514(void *a, void *b) {
    ov117_0225F524(a, b, ov117_0225FAEC);
}
