#ifndef POKEHEARTGOLD_TO47_OVERLAY49_MANAGER_R4_PRIVATE_H
#define POKEHEARTGOLD_TO47_OVERLAY49_MANAGER_R4_PRIVATE_H

#include "global.h"

#include "overlay_42.h"

typedef struct Ov49EntryR4 {
    u8 raw[0x24];
    void (*callback)(struct Ov49EntryR4 *, void *);
} Ov49EntryR4;

typedef struct Ov49ManagerR4 {
    void *object0;
    void *object4;
    Ov49EntryR4 *entries;
    u16 count;
    u16 value;
    void *iterator;
    void *arg;
    u8 sub18[0x10];
} Ov49ManagerR4;

void *ov45_02230498(u32, u32, u32, u32);
void ov49_022591D8(Ov49ManagerR4 *);
void ov45_02230638(void *);
void ov49_02259A54(void *, void *);
u32 ov49_022593FC(Ov49EntryR4 *);
void *ov49_02258AB0(void *);
void ov45_02230680(void *);
Ov49ManagerR4 *ov49_02258AB4(u32, u32, void *, enum HeapID, u32);
void ov49_02258B20(Ov49ManagerR4 *);
void ov49_02258B44(Ov49ManagerR4 *);
void ov49_02258B5C(Ov49ManagerR4 *);

#endif // POKEHEARTGOLD_TO47_OVERLAY49_MANAGER_R4_PRIVATE_H
