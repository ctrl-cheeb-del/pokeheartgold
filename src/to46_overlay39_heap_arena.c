#include <nitro/os/alloc.h>
#include <nitro/os/arena.h>

#include "global.h"

#include "heap.h"

typedef struct Ov39Work {
    u8 padding[0x3BC];
    void *unk3BC;
} Ov39Work;

extern OSHeapHandle _0222AB80;

void *ov39_02227DE4(Ov39Work *work);
void *ov39_02227DEC(enum HeapID heapId);

void *ov39_02227DE4(Ov39Work *work) {
    return work->unk3BC;
}

void *ov39_02227DEC(enum HeapID heapId) {
    void *memory = Heap_Alloc(heapId, 0x2000);
    void *end = (u8 *)memory + 0x2000;
    void *arenaLo = OS_InitAlloc(OS_ARENA_MAIN, memory, end, 1);

    OS_SetArenaLo(OS_ARENA_MAIN, arenaLo);
    arenaLo = (void *)(((u32)arenaLo + 31) & ~31);
    end = (void *)(((u32)end + 31) & ~31);
    _0222AB80 = OS_CreateHeap(OS_ARENA_MAIN, arenaLo, end);
    OS_SetCurrentHeap(OS_ARENA_MAIN, _0222AB80);
    return memory;
}
