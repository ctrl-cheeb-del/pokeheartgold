#ifndef SOL_R9_OVERLAY18_PRIVATE_H
#define SOL_R9_OVERLAY18_PRIVATE_H
#include "global.h"

typedef struct Window18 {
    u8 raw[0x10];
} Window18;

typedef struct Work18 {
    void *root;
    void *bgConfig;
    void *unk8;
    Window18 windows[101];
} Work18;

void AddWindow(void *, void *, const void *);
void RemoveWindow(void *);
void ScheduleWindowCopyToVram(void *);
void FillWindowPixelBuffer(void *, u32);
void ov18_021F9648(void *, void *, u32, u32, u32, u32, u32, u32);
void ov18_021EE44C(void *, u32, u32);
void ov18_021EE520(void *, u32, u32);
void ov18_021EE35C(Work18 *, const void *, u32);
void ov18_021EE5E4(void *, u32, u32);
void ov18_021EEED0(void *, u32);
void ov18_021EF45C(void *);
void ov18_021EF528(void *);
void ov18_021EEE84(void *);
void sub_02019A60(void *, u32, void *);

void ov18_021EE388(Work18 *);
void ov18_021EE508(void *, u32, u32);
void ov18_021EE5E4(void *, u32, u32);
void ov18_021EE5FC(void *);
void ov18_021EEE58(void *);
void ov18_021EF1E4(void *, u32);
void ov18_021EF220(void *, u32);
void ov18_021EF25C(void *, u32);
void ov18_021EF298(void *, u32);
void ov18_021EF2D4(void *, u32);
void ov18_021EF310(void *, u32);
void ov18_021EF34C(void *, u32);
void ov18_021EE9FC(void *, u32);
void ov18_021EEA40(void *, u32);
u32 LanguageToDexFlag(u32);
void ov18_021EEBE4(void *, u32);
void ov18_021E613C(void *, u32);
void ov18_021EF388(void *, u32, u32);
void ov18_021EFB88(void *);
u32 ov18_021F8824(void *);
u32 ov18_021F8838(void *);
void ov18_021EE6BC(void *, u32, u32);
void ov18_021EE8B8(void *, u32, u32);
void ov18_021EE3FC(void *);
void ov18_021EE71C(void *, u32);
void ov18_021EE75C(void *, u32, u32);
void ov18_021EE7DC(void *, u32, u32);
void ov18_021EE834(void *, u32, u32, u32);
void ov18_021EE6EC(void *, u32, u32);

extern const u8 ov18_021F9FDC[];
extern const u8 ov18_021F9F3C[];

#endif
