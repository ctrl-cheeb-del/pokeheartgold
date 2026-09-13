#include "global.h"

#include "filesystem.h"
#include "gf_gfx_loader.h"
#include "overlay90_resource_internal.h"

extern void sub_0200F478(void *);
extern void ov90_0225A65C(NARC *, int, enum HeapID);
extern void ov90_0225A2B0(void *, void *, void *, int, NARC *, enum HeapID);
void ov90_02259570(void *, int);
void ov90_022596C8(void *, enum HeapID);

typedef struct Ov90TextSlots {
    u8 filler[0x2c];
    void *slots[2];
} Ov90TextSlots;

void ov90_02259570(void *work, int index) {
    Ov90TextSlots *slots = work;

    if (slots->slots[index] != NULL) {
        sub_0200F478(slots->slots[index]);
        slots->slots[index] = NULL;
    }
}
