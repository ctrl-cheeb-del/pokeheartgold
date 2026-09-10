#ifndef OV01_021FC4C4_PRIVATE_H
#define OV01_021FC4C4_PRIVATE_H

#include "global.h"

typedef struct Ov01HeapEntry {
    void *data;
    u32 id;
} Ov01HeapEntry;

typedef struct Ov01HeapManager {
    u32 parentHeapId;
    u32 heapId;
    u32 capacity;
    u32 heapSize;
    u32 entriesSize;
    Ov01HeapEntry *entries;
} Ov01HeapManager;

extern BOOL Heap_Create(u32 parentHeapId, u32 heapId, u32 size);
extern void *Heap_Alloc(u32 heapId, u32 size);
extern void *Heap_AllocAtEnd(u32 heapId, u32 size);
extern void Heap_Free(void *ptr);
extern void Heap_Destroy(u32 heapId);
extern void GF_AssertFail(void);
extern u32 NARC_GetMemberSize(void *narc, u32 member);
extern void NARC_ReadWholeMember(void *narc, u32 member, void *dest);

Ov01HeapManager *ov01_021FC4C4(u32 parentHeapId, u32 heapId, u32 heapSize, u32 capacity);
void ov01_021FC520(Ov01HeapManager *manager);
void *ov01_021FC554(Ov01HeapManager *manager, u32 id, u32 size, BOOL atEnd);
void ov01_021FC588(Ov01HeapManager *manager, u32 id);
void *ov01_021FC5A4(Ov01HeapManager *manager, u32 id);
BOOL ov01_021FC5B8(Ov01HeapManager *manager, u32 id);
void *ov01_021FC5CC(Ov01HeapManager *manager, u32 id, void *narc, u32 member, BOOL atEnd);
void *ov01_021FC5FC(Ov01HeapManager *manager, u32 size, BOOL atEnd);
void ov01_021FC61C(void *ptr);
Ov01HeapEntry *ov01_021FC624(Ov01HeapManager *manager, u32 id);
Ov01HeapEntry *ov01_021FC644(Ov01HeapManager *manager);
void ov01_021FC65C(Ov01HeapEntry *entry, u32 id, void *data);
void ov01_021FC664(Ov01HeapEntry *entry);

#endif
