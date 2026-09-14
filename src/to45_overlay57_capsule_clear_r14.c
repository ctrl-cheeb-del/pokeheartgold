#include "global.h"

#include "pokemon.h"

typedef struct Ov57R14MonEntry {
    u32 capsule;
    u32 unused;
} Ov57R14MonEntry;

typedef struct Ov57R14Work {
    Pokemon **mons;
    Ov57R14MonEntry monEntries[12];
} Ov57R14Work;

void ov57_022394AC(Ov57R14Work *work);
void ov57_0223BC4C(Ov57R14Work *work, int index);

void ov57_0223BC4C(Ov57R14Work *work, int index) {
    u32 zero = 0;

    if (work->monEntries[index].capsule != 0xFF) {
        SetMonData(work->mons[work->monEntries[index].capsule + 1], 0xA2, &zero);
    }
    work->monEntries[index].capsule = 0xFF;
    ov57_022394AC(work);
}
