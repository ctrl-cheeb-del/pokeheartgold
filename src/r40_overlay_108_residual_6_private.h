#ifndef OV108_RESIDUAL6_R40_PRIVATE_H
#define OV108_RESIDUAL6_R40_PRIVATE_H

#include "global.h"

#include "system.h"
#include "touchscreen_list_menu.h"
#include "yes_no_prompt.h"

typedef struct SafariAreaCustomizer {
    u32 heapId;
    u32 unk04;
    u32 unk08;
    u32 unk0C;
    u32 unk10;
    u8 pad14[0x340 - 0x14];
    BgConfig *bgConfig;
    TouchscreenListMenuSpawner *listMenuSpawner;
    u8 pad348[0x4B4 - 0x348];
    ListMenuItem *listMenuItems1;
    ListMenuItem *listMenuItems2;
    TouchscreenListMenu *touchscreenListMenu;
    YesNoPrompt *yesNoPrompt;
    u8 pad4C4[0x184DE - 0x4C4];
    u8 unk184DE;
    u8 unk184DF;
    u8 unk184E0;
    u8 unk184E1;
    u8 flag0 : 1;
    u8 bit1 : 1;
    u8 flagB : 1;
    u8 mode : 5;
    u8 unk184E3;
    s16 unk184E4;
    s16 unk184E6;
} SafariAreaCustomizer;

void ov108_021E6850(SafariAreaCustomizer *work);
void ov108_021E78F4(SafariAreaCustomizer *work, u32 index, u32 animation);
void ov108_021E8490(SafariAreaCustomizer *work);
void PlaySE(u32 sequence);
void GF_RunVramTransferTasks(void);
u32 ov108_021E6894(SafariAreaCustomizer *work);
u32 ov108_021E69A0(SafariAreaCustomizer *work);
void ov108_021E6B00(SafariAreaCustomizer *work);
void ov108_021E6A58(SafariAreaCustomizer *work);
void ov108_021E6BA0(SafariAreaCustomizer *work);
extern const TouchscreenHitbox ov108_021EA760[];
extern const u8 _021EA720[];
extern const u16 ov108_021EA748[];
extern const u16 ov108_021EA74A[];
void ov108_021E79A8(SafariAreaCustomizer *work, u32 a, u32 b, u32 c);
void ov108_021E7BB4(SafariAreaCustomizer *work, u32 index, int member);
void ov108_021E767C(SafariAreaCustomizer *work, u32 a);
void ov108_021E7700(SafariAreaCustomizer *work, u32 a, u32 b, u32 c);

#endif
