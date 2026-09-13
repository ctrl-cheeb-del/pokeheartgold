#ifndef R40_OV109_R6_PRIVATE_H
#define R40_OV109_R6_PRIVATE_H
#include "global.h"
typedef struct R40PhotoApp6 {
    u8 pad00[8];
    u16 subState, counter;
    int nextState;
    void *args;
    void *bgConfig;
    u8 bits18, curPage, numPages, cursorX, cursorY, spriteCol, spriteRow, slotIdx, flag, printerId, unk22;
    u8 pad23[0xA2];
    u8 numPhotos;
} R40PhotoApp6;
extern void ov109_021E70C4(void *, u32, u32, u32);
extern void ov109_021E73F8(void *, u32, u32, u32);
extern BOOL TextPrinterCheckActive(u8);
extern void PlaySE(u16);
extern void ov109_021E7474(void *, u8, u8, u32);
extern void ScheduleBgTilemapBufferTransfer(void *, u32);
extern void ov109_021E7248(void *, u32);
extern void ov109_021E74D4(void *, u32);
extern void ov109_021E77D4(void *);
extern void ov109_021E7584(void *, u32);
extern void ov109_021E5DB8(void *, u32, u32);
extern void ov109_021E71BC(void *, u32, u32);
extern const u8 _021E7884[];
int ov109_021E61DC(R40PhotoApp6 *);
int ov109_021E628C(R40PhotoApp6 *, u32);
#endif
