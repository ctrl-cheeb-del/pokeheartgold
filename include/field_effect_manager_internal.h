#ifndef OV01_021F1348_PRIVATE_H
#define OV01_021F1348_PRIVATE_H

#include "global.h"

#include "heap.h"

// Forward struct declarations only: never typedefs, so nothing here can collide
// with a tracked header that happens to get pulled in transitively.
struct SysTask;

typedef void (*FieldEffectTaskFunc)(struct SysTask *, void *);

typedef struct FieldEffectEntry {
    u32 id;
    void *data;
} FieldEffectEntry;

typedef struct FieldEffectSlot {
    u32 id;
    struct FieldEffectRecord *record;
} FieldEffectSlot;

typedef struct FieldEffectMtx {
    u32 raw[4];
} FieldEffectMtx;

typedef struct FieldEffectRecord {
    void *unk0;
    void *unk4;
    int unk8;
    FieldEffectMtx unkC;
    u32 texKey;
    u32 tex4x4Key;
    u32 plttKey;
} FieldEffectRecord;

typedef struct FieldEffectGfx {
    enum HeapID heapID;
    u16 count;
    u16 unk6;
    u16 unk8;
    u16 unkA;
    void *unkC;
    void *unk10;
    void *unk14;
    void *resMan;
    FieldEffectSlot *slots;
    FieldEffectRecord *records;
} FieldEffectGfx;

typedef struct FieldEffectManager {
    enum HeapID heapID;
    u32 count;
    u32 animManagerCount;
    u32 unkC;
    void *fieldSystem;
    FieldEffectEntry *entries;
    void *narc;
    void *effectManager;
    FieldEffectGfx *gfx;
} FieldEffectManager;

typedef struct FieldEffectRenderer {
    u32 id;
    void *(*init)(FieldEffectManager *);
    void (*free)(void *);
} FieldEffectRenderer;

typedef struct FieldEffectLoadTask {
    int state;
    int id;
    void *resMan;
} FieldEffectLoadTask;

typedef struct FieldEffectAnimReq {
    u32 count;
    enum HeapID heapID;
} FieldEffectAnimReq;

typedef struct FieldEffectModelReq {
    void *unk0;
    void *unk4;
    VecFx32 position;
    VecFx32 scale;
} FieldEffectModelReq;

extern const FieldEffectRenderer ov01_02208C5C[];

#endif // OV01_021F1348_PRIVATE_H
