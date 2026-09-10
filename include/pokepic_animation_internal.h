#ifndef POKEHEARTGOLD_POKEPIC_ANIMATION_INTERNAL_H
#define POKEHEARTGOLD_POKEPIC_ANIMATION_INTERNAL_H
#include "global.h"

#include "heap.h"
#include "pokepic.h"
#include "sys_task_api.h"

typedef struct PicEntry {
    Pokepic *pic;
    SysTask *task;
    void *data;
    void **cursor;
    u32 active;
    u32 unk14;
    u32 unk18;
    u32 done;
    u32 state;
    s32 vars[9];
    s32 limit;
    s32 current;
    void **saved;
    u32 delay;
    u8 rest58[0x1CD - 0x58];
    u8 flag1CD;
    u8 mode1CE;
    u8 rest1CF;
} PicEntry;

typedef struct PicManager {
    PicEntry *entries;
    enum HeapID heapId;
    u8 flag;
    u8 count;
    u8 pad[2];
} PicManager;

PicManager *sub_02016EDC(enum HeapID heapId, int count, int flag);
void sub_02016F2C(PicManager *mgr);
u32 sub_02017068(PicManager *mgr, u32 index);
void sub_02017088(PicManager *mgr, u32 index);
void sub_020170C4(SysTask *task, PicEntry *entry);
void sub_020170FC(PicEntry *entry);
void *sub_020171F4(void **array, int index, int expected);
void *sub_02017208(void **array, int expected);
void *sub_02017214(void **array);
void sub_0201726C(PicEntry *data, u32 *out);
void sub_02017280(PicEntry *data, u8 *out);
void sub_02017294(PicEntry *data, u8 *out);
void sub_020172B4(PicEntry *data, u8 *a, u8 *b);
void sub_020172C8(PicEntry *data, u8 *index, s32 *a, s32 *b);
void sub_0201733C(PicEntry *data, u8 *index, s32 *a, s32 *b);
void sub_02017504(PicEntry *data);
void sub_0201752C(PicEntry *data);
void sub_02017550(PicEntry *data);
void sub_02017578(PicEntry *data);
void sub_0201759C(PicEntry *data);
void sub_020175C4(PicEntry *data);
void sub_020176CC(PicEntry *data);
void sub_020176F0(PicEntry *data);
void sub_02017714(PicEntry *data);
void sub_02017730(PicEntry *data);
void sub_0201775C(PicEntry *data);
void sub_02017788(PicEntry *data);
void sub_02017C78(PicEntry *data, int index);
void sub_02017B48(PicEntry *data);
void sub_02017B54(PicEntry *data);
void sub_02017B8C(PicEntry *data);
void sub_02017B98(PicEntry *data);
void sub_02017BA4(PicEntry *data);
void sub_02017BB0(PicEntry *data);
void sub_02017BBC(PicEntry *data);
void sub_02017BC8(int op, int *lhs, int *rhs, int *dst);

PicManager *sub_02016EDC(enum HeapID heapId, int count, int flag);
void sub_02016F2C(PicManager *mgr);
u32 sub_02017068(PicManager *mgr, u32 index);
void sub_02017088(PicManager *mgr, u32 index);
void sub_020170C4(SysTask *task, PicEntry *entry);
void *sub_020171F4(void **array, int index, int expected);
void *sub_02017208(void **array, int expected);
void *sub_02017214(void **array);
void sub_0201726C(PicEntry *data, u32 *out);
void sub_02017280(PicEntry *data, u8 *out);
void sub_02017294(PicEntry *data, u8 *out);
void sub_020172B4(PicEntry *data, u8 *a, u8 *b);
void sub_02017504(PicEntry *data);
void sub_0201752C(PicEntry *data);
void sub_02017550(PicEntry *data);
void sub_02017578(PicEntry *data);
void sub_0201759C(PicEntry *data);
void sub_020175C4(PicEntry *data);
void sub_020176CC(PicEntry *data);
void sub_020176F0(PicEntry *data);
void sub_02017714(PicEntry *data);
void sub_02017730(PicEntry *data);
void sub_0201775C(PicEntry *data);
void sub_02017788(PicEntry *data);
void sub_02017B48(PicEntry *data);
void sub_02017B54(PicEntry *data);
void sub_02017B8C(PicEntry *data);
void sub_02017B98(PicEntry *data);
void sub_02017BA4(PicEntry *data);
void sub_02017BB0(PicEntry *data);
void sub_02017BBC(PicEntry *data);
void sub_02017BC8(int op, int *lhs, int *rhs, int *dst);

#endif
