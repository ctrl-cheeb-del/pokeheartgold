#ifndef OV109_PRIVATE_H
#define OV109_PRIVATE_H

#include "global.h"

#include "constants/heap.h"

#include "bg_window.h"
#include "font.h"
#include "gf_gfx_planes.h"
#include "heap.h"
#include "list_menu_items.h"
#include "menu_input_state.h"
#include "message_format.h"
#include "msgdata.h"
#include "overlay_109.h"
#include "overlay_manager.h"
#include "photo_album.h"
#include "photo_types_def.h"
#include "screen_fade.h"
#include "sprite.h"
#include "sprite_system.h"
#include "string_util.h"
#include "sys_task.h"
#include "text.h"
#include "touchscreen.h"
#include "touchscreen_list_menu.h"
#include "yes_no_prompt.h"

typedef struct PhotoTiles {
    u16 unk_00;
    u16 unk_02;
    u8 filler_04[0x8];
    u8 data[1];
} PhotoTiles;

typedef struct PhotoEntry {
    u8 idx;
    u8 filler_01[3];
    Photo *photo;
} PhotoEntry;

typedef struct PhotoAlbumApp {
    /* 0x000 */ enum HeapID heapId;
    /* 0x004 */ int state;
    /* 0x008 */ u16 subState;
    /* 0x00A */ u16 unk_0A;
    /* 0x00C */ int nextMenuState;
    /* 0x010 */ PhotoAlbumArgs *args;
    /* 0x014 */ BgConfig *bgConfig;
    /* 0x018 */ u8 fadeRunning : 1;
    /* 0x018 */ u8 unk_18_1 : 1;
    /* 0x018 */ u8 bgToggleReq : 1;
    /* 0x018 */ u8 bgToggleVal : 1;
    /* 0x019 */ u8 curPage;
    /* 0x01A */ u8 numPages;
    /* 0x01B */ u8 cursorX;
    /* 0x01C */ u8 cursorY;
    /* 0x01D */ u8 spriteCol;
    /* 0x01E */ u8 spriteRow;
    /* 0x01F */ u8 slotIdx;
    /* 0x020 */ u8 unk_20;
    /* 0x021 */ u8 unk_21[0x3];
    /* 0x024 */ MsgData *msgData;
    /* 0x028 */ MessageFormat *messageFormat;
    /* 0x02C */ String *str_2C;
    /* 0x030 */ String *str_30;
    /* 0x034 */ String *strs_34[5];
    /* 0x048 */ String *strs_48[2];
    /* 0x050 */ Window windows[3];
    /* 0x080 */ TouchscreenListMenuSpawner *listMenu;
    /* 0x084 */ u8 filler_84[0x4];
    /* 0x088 */ ListMenuItem *listMenuItems;
    /* 0x08C */ YesNoPrompt *yesNoPrompt;
    /* 0x090 */ SpriteSystem *spriteSystem;
    /* 0x094 */ SpriteManager *spriteManager;
    /* 0x098 */ Sprite *sprites[6];
    /* 0x0B0 */ void *unk_B0;
    /* 0x0B4 */ void *unk_B4;
    /* 0x0B8 */ void *unk_B8;
    /* 0x0BC */ PhotoTiles *tiles;
    /* 0x0C0 */ void *unk_C0;
    /* 0x0C4 */ u8 numPhotosPrev;
    /* 0x0C5 */ u8 numPhotos;
    /* 0x0C6 */ u8 filler_C6[0x2];
    /* 0x0C8 */ Photo *photos;
    /* 0x0CC */ PhotoEntry entries[36];
    /* 0x1EC */ PhotoAlbum *photoAlbum;
    /* 0x1F0 */ fx32 zoom;
} PhotoAlbumApp; // size: 0x1F4

typedef struct PhotoAlbumTask {
    PhotoAlbumApp *app;
    u8 filler_04[4];
} PhotoAlbumTask;


/* Generated integration prototypes. */
BOOL PhotoAlbum_Init(OverlayManager *man, int *state);
BOOL PhotoAlbum_Main(OverlayManager *man, int *state);
BOOL PhotoAlbum_Exit(OverlayManager *man, int *state);
void ov109_021E5A20(void);
void ov109_021E5B40(PhotoAlbumApp *app);
BOOL ov109_021E5B60(PhotoAlbumApp *app);
BOOL ov109_021E5B98(PhotoAlbumApp *app);
int ov109_021E5BAC(PhotoAlbumApp *app);
int ov109_021E5BF4(PhotoAlbumApp *app);
int ov109_021E5C40(PhotoAlbumApp *app);
int ov109_021E5C48(PhotoAlbumApp *app);
int ov109_021E5C68(PhotoAlbumApp *app);
int ov109_021E5C88(PhotoAlbumApp *app);
int ov109_021E5C90(PhotoAlbumApp *app);
int ov109_021E5C98(PhotoAlbumApp *app);
int ov109_021E5CAC(PhotoAlbumApp *app);
void ov109_021E5CB4(PhotoAlbumApp *app);
void ov109_021E5CE4(PhotoAlbumApp *app);
void ov109_021E5D08(PhotoAlbumApp *app);
void ov109_021E5D5C(PhotoAlbumApp *app);
void ov109_021E5DB8(PhotoAlbumApp *app, int a, int b);
void ov109_021E5EC8(PhotoAlbumApp *app);
int ov109_021E5F10(PhotoAlbumApp *app);
int ov109_021E5FFC(PhotoAlbumApp *app, int *a);
int ov109_021E61BC(PhotoAlbumApp *app);
int ov109_021E638C(PhotoAlbumApp *app, int *a);
int ov109_021E681C(PhotoAlbumApp *app);
int ov109_021E682C(PhotoAlbumApp *app);
void ov109_021E685C(PhotoAlbumApp *app);
void ov109_021E6898(PhotoAlbumApp *app);
void ov109_021E68B8(PhotoAlbumApp *app, int on);
void ov109_021E68D4(PhotoAlbumApp *app);
void ov109_021E691C(PhotoAlbumApp *app, fx32 v);
void ov109_021E692C(void);
void ov109_021E6AFC(PhotoAlbumApp *app);
void ov109_021E6C7C(PhotoAlbumApp *app);
void ov109_021E6D2C(PhotoAlbumApp *app);
void ov109_021E6D84(PhotoAlbumApp *app);
void ov109_021E6DBC(PhotoAlbumApp *app);
void ov109_021E6E64(PhotoAlbumApp *app);
void ov109_021E6E9C(PhotoAlbumApp *app);
void ov109_021E6EC0(PhotoAlbumApp *app);
void ov109_021E6F60(PhotoAlbumApp *app);
void ov109_021E6FD4(PhotoAlbumApp *app, u8 bgId, int which, int idx);
void ov109_021E7388(PhotoAlbumApp *app, int a);
void ov109_021E7474(PhotoAlbumApp *app, u8 x, u8 y, int draw);
void ov109_021E74D4(PhotoAlbumApp *app, int draw);
void ov109_021E7524(PhotoAlbumApp *app);
void ov109_021E7584(PhotoAlbumApp *app, int idx);
int ov109_021E75B4(PhotoAlbumApp *app);
void ov109_021E77D4(PhotoAlbumApp *app);
void ov109_021E7810(SysTask *task, PhotoAlbumTask *data);
u8 ov109_021E7850(Photo *photo);
#endif
