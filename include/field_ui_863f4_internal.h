#include "global.h"

typedef struct ManagedSprite ManagedSprite;
typedef struct SpriteSystem SpriteSystem;
typedef struct SpriteManager SpriteManager;
typedef struct PaletteData PaletteData;
typedef struct Window Window;
typedef struct MsgData MsgData;
typedef struct String String;
typedef struct Config32 {
    u32 values[8];
} Config32;
typedef struct Config20 {
    u32 values[5];
} Config20;
typedef struct Config24 {
    u32 values[6];
} Config24;
typedef struct SpriteTemplate {
    s16 x;
    s16 y;
    s16 z;
    s16 animation;
    int priority;
    volatile int palette;
    int vram;
    int resources[4];
    int backgroundPriority;
    int transferPriority;
    int unk2c;
    int unk30;
} SpriteTemplate;
typedef struct SpriteSlot {
    ManagedSprite *sprite;
    u8 pad[0x18];
} SpriteSlot;
typedef struct CoordBytes {
    u8 y0;
    u8 y1;
    u8 x0;
    u8 x1;
} CoordBytes;
typedef struct ModuleView {
    u8 pad220[0x220];
    SpriteSlot sprites[3];
    u8 pad274[0xd0];
    CoordBytes coords[8];
} ModuleView;

typedef struct ModuleState {
    u8 raw[0x400];
} ModuleState;
typedef struct ModuleEntry {
    int value;
    int unk4;
    int active;
    ManagedSprite *sprite;
    u8 *bounds;
    s16 velocityX;
    s16 velocityY;
    u8 movement;
    u8 delay;
    u8 pad[2];
} ModuleEntry;

void ManagedSprite_SetDrawFlag(ManagedSprite *, int);
ManagedSprite *SpriteSystem_NewSprite(SpriteSystem *, SpriteManager *, const SpriteTemplate *);
SpriteSystem *SpriteSystem_Alloc(int);
void SpriteSystem_Init(SpriteSystem *, const Config32 *, const Config20 *, int);
SpriteManager *SpriteManager_New(SpriteSystem *);
int SpriteSystem_InitSprites(SpriteSystem *, SpriteManager *, int);
int SpriteSystem_InitManagerWithCapacities(SpriteSystem *, SpriteManager *, const Config24 *);
void GF_AssertFail(void);
void ManagedSprite_GetPositionXY(ManagedSprite *, s16 *, s16 *);
void ManagedSprite_SetPositionXY(ManagedSprite *, s16, s16);
void ManagedSprite_SetAnim(ManagedSprite *, int);
void ManagedSprite_SetOamMode(ManagedSprite *, int);
void ManagedSprite_TickFrame(ManagedSprite *);
void Sprite_DeleteAndFreeResources(ManagedSprite *);
int ManagedSprite_GetActiveAnim(ManagedSprite *);
int ManagedSprite_IsAnimated(ManagedSprite *);
void *FontSystem_NewInit(int, int);
void FontID_Alloc(int, int);
void FontID_Release(int);
void FontOAM_Delete(void *);
void sub_02021B5C(void *);
void sub_020135AC(void *);
void sub_020136B4(void *, int, int);
void SpriteSystem_LoadPaletteBuffer(void *, int, void *, void *, int, int, int, int, int, int);
void sub_02087028(ModuleState *);
void sub_02087090(ModuleState *, int, int, int, int);
void InitWindow(Window *);
void AddWindowParameterized(void *, Window *, u8, u8, u8, u8, u8, u8, u16);
void DrawFrameAndWindow2(Window *, int, int, int);
void FillWindowPixelBuffer(Window *, int);
void CopyWindowToVram(Window *);
void sub_02087230(Window *, int);
MsgData *NewMsgDataFromNarc(int, int, int, int);
String *NewString_ReadMsgData(MsgData *, int);
void AddTextPrinterParameterized(Window *, int, String *, int, int, int, int);
void String_Delete(String *);
void DestroyMsgData(MsgData *);
extern const Config20 _021027C8;
extern const Config24 _021027DC;
extern const Config32 _021027F4;
void sub_020863F4(ModuleState *);
void RemoveWindow(Window *);
void sub_020866CC(ModuleState *);
void sub_020868A0(ModuleState *);
void sub_020869BC(ModuleState *);
void sub_02086AB4(ModuleState *, int, int);
void sub_02086AE4(ModuleState *, int);
void sub_02086B2C(ModuleState *, int);
void sub_02086B6C(ModuleState *, int, int);
void sub_02086BB4(ModuleState *);
void sub_02086C80(void *, int, int);
void sub_02086C8C(ModuleState *);
int sub_02086D98(int, int);
void sub_02086DA4(ModuleState *);
void sub_02086FCC(ModuleState *);
void sub_02086FE8(ModuleState *);
void sub_02086F44(ModuleState *);
void sub_02087064(ModuleState *);
void sub_020871C4(void *, Window *, int, int, int, int, int, int, int);
