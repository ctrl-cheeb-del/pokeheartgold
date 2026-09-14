#ifndef TO46_OVERLAY88_R9_PRIVATE_H
#define TO46_OVERLAY88_R9_PRIVATE_H

#include "global.h"

#include "bg_window.h"
#include "pm_string.h"

typedef struct Ov88GaugeConfig {
    u16 unk00;
    u16 scale;
    u16 divisor;
    u16 value;
    u8 filler08[0x10];
    void *pixels;
} Ov88GaugeConfig;

typedef struct Ov88TextWindowConfig {
    u8 left;
    u8 top;
    u8 width;
    u8 height;
    u16 baseTile;
    u8 palette;
    u8 x;
    u8 y;
    u8 alignment;
    u8 filler0A[2];
    u32 color;
} Ov88TextWindowConfig;

typedef struct Ov88TextEntry {
    u8 data[12];
} Ov88TextEntry;

extern const u16 _02259A60[4];
extern void *const ov88_02259A68[4];
extern const Ov88TextWindowConfig ov88_02259980[4];

void ov88_0225983C(Ov88TextEntry *entry, u16 messageId, void *data);
void ov88_0225985C(Ov88TextEntry *entry);
void ov88_02259884(Ov88TextEntry *entry);

void ov88_022595F8(Ov88GaugeConfig *config, Window *window);
void ov88_0225967C(void *work, BgConfig **bgConfig, enum HeapID heapId);
void ov88_022597DC(void *work);
void ov88_02259800(void *work);

#endif
