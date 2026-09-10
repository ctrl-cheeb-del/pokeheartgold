#include "global.h"

typedef struct RingPositionPrivate {
    u8 fields[4];
    s16 start;
    s16 current;
    s16 end;
    s16 length;
} RingPositionPrivate;

typedef struct EntryPrivate {
    u8 fields[0xe];
    u8 active;
    u8 fieldF;
} EntryPrivate;

typedef struct EntryListPrivate {
    u8 fields[0x18];
    EntryPrivate *entries;
    s32 count;
} EntryListPrivate;

s32 sub_02033BC4(const RingPositionPrivate *);
s32 sub_02033BE4(const RingPositionPrivate *);
s32 sub_02033BF4(const RingPositionPrivate *);
s32 sub_02033C14(const RingPositionPrivate *, s32);
void sub_02033C28(RingPositionPrivate *);
EntryPrivate *sub_02033C30(const EntryListPrivate *);
BOOL sub_02033C50(const EntryListPrivate *);
