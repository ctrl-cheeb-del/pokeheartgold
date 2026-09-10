#ifndef POKEHEARTGOLD_COMMUNICATION_DISPATCH_INTERNAL_H
#define POKEHEARTGOLD_COMMUNICATION_DISPATCH_INTERNAL_H
#include "global.h"
typedef struct ByteRing {
    u8 *data;
    s16 read;
    s16 limit;
    s16 write;
    s16 capacity;
} ByteRing;
typedef struct PacketNode {
    u8 data[4];
    struct PacketNode *prev;
    struct PacketNode *next;
    u16 value;
    u8 type;
    u8 flags;
} PacketNode;
typedef struct ByteWriter {
    u8 *dest;
    int remaining;
} ByteWriter;
typedef struct PacketQueue {
    PacketNode *head;
    PacketNode *tail;
} PacketQueue;
typedef struct PoolNode {
    u8 pad[0xE];
    u8 type;
    u8 flags;
} PoolNode;
typedef struct PacketPool {
    void *head;
    void *tail;
    void *unk08;
    void *unk0C;
    void *current;
    void *ring;
    PoolNode *nodes;
    int count;
} PacketPool;
typedef void (*Handler)(int, int, int, void *);
typedef u32 (*ValueFunc)(void);
typedef void (*AuxFunc)(void *, void *);
typedef struct HandlerEntry {
    Handler handler;
    ValueFunc value;
    AuxFunc aux;
} HandlerEntry;
typedef struct CommManager {
    const HandlerEntry *table;
    int count;
    void *context;
    u8 ready[8];
    u8 shutdown;
} CommManager;
typedef char AssertByteRing[(sizeof(ByteRing) == 12) ? 1 : -1];
typedef char AssertPacketNode[(sizeof(PacketNode) == 16) ? 1 : -1];
typedef char AssertPacketPool[(sizeof(PacketPool) == 32) ? 1 : -1];
typedef char AssertCommManager[(sizeof(CommManager) == 24) ? 1 : -1];
#include "heap.h"
extern CommManager *_021D412C;
extern const HandlerEntry _020F6980[];
void sub_02037974(void);
int sub_02033BF4(ByteRing *);
int sub_02033C14(ByteRing *, int);
int sub_02033B78(ByteRing *, u8 *, int);
int sub_0203769C(void);
int sub_020373B4(u16);
void sub_02037108(int, int, int);
BOOL sub_020376E0(int, void *);
void sub_02033AE0(ByteRing *, u8 *, u16);
void sub_02033AF0(ByteRing *, const u8 *, int);
int sub_02033B4C(ByteRing *, u8 *, int);
u8 sub_02033B68(ByteRing *);
BOOL sub_02033C70(PacketQueue *);
BOOL sub_02033C94(ByteWriter *, u8);
void sub_02033F44(PacketPool *, int, void *);
void sub_02033F70(PacketPool *);
void sub_02033F90(PacketPool *);
BOOL sub_02033F9C(PacketPool *, u8);
BOOL sub_0203401C(int);
BOOL sub_02034044(int);
BOOL sub_02034084(int);
BOOL sub_02034098(int);
BOOL sub_020340C4(int);
void sub_0203410C(const void *, int, void *);
void sub_02034154(void);
void sub_02034170(int, int, int, int);
u32 sub_020341DC(int);
BOOL sub_02034244(int);
u32 sub_020342B8(void);
u32 sub_020342C0(void);
u32 sub_020342C4(void);
u32 sub_020342C8(void);
void sub_020342CC(int);
void sub_02034310(int, int, void *);
void sub_02034338(int);

void sub_02033AE0(ByteRing *ring, u8 *data, u16 capacity);
void sub_02033AF0(ByteRing *ring, const u8 *src, int count);
int sub_02033B4C(ByteRing *ring, u8 *dst, int count);
u8 sub_02033B68(ByteRing *ring);
int sub_02033B78(ByteRing *ring, u8 *dst, int count);
BOOL sub_02033C70(PacketQueue *queue);
BOOL sub_02033C94(ByteWriter *writer, u8 value);
void sub_02033F44(PacketPool *pool, int count, void *ring);
void sub_02033F70(PacketPool *pool);
void sub_02033F90(PacketPool *pool);
BOOL sub_02033F9C(PacketPool *pool, u8 type);
BOOL sub_0203401C(int v);
BOOL sub_02034044(int v);
BOOL sub_02034084(int v);
BOOL sub_02034098(int v);
BOOL sub_020340C4(int v);
void sub_0203410C(const void *table, int count, void *context);
void sub_02034154(void);
void sub_02034170(int a0, int index, int a2, int a3);
u32 sub_020341DC(int index);
BOOL sub_02034244(int index);
u32 sub_020342B8(void);
u32 sub_020342C0(void);
u32 sub_020342C4(void);
u32 sub_020342C8(void);
void sub_020342CC(int aid);
void sub_02034310(int a, int b, void *arg);
void sub_02034338(int aid);

#endif
