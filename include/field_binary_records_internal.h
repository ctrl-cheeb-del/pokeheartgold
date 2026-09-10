#ifndef PRIVATE_OV01_021EA6C4_H
#define PRIVATE_OV01_021EA6C4_H
#include "global.h"

#include "filesystem.h"
#include "heap.h"
typedef struct LocalAreaPairs {
    u16 (*first)[2];
    u16 (*second)[2];
} LocalAreaPairs;
LocalAreaPairs *ov01_021EA724(void);
void ov01_021EA73C(const char *, LocalAreaPairs *);
void ov01_021EA7E0(LocalAreaPairs *);
void ov01_021EA7F8(int, LocalAreaPairs *, u16 *);
void ov01_021EA804(int, LocalAreaPairs *, u16 *, u16 *);
u16 (*ov01_021EA81C(int, LocalAreaPairs *))[2];
#endif
