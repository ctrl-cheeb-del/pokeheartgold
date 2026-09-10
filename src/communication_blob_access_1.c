#include "communication_blob_access_internal.h"

s32 sub_02033BC4(const RingPositionPrivate *position) {
    s16 start = position->start;
    if (start > position->current) {
        return position->length + *(volatile const s16 *)&position->current - start;
    }
    return *(volatile const s16 *)&position->current - start;
}

s32 sub_02033BE4(const RingPositionPrivate *position) {
    return position->length - sub_02033BC4(position);
}

s32 sub_02033BF4(const RingPositionPrivate *position) {
    s16 start = position->start;
    if (start > position->end) {
        return start - *(volatile const s16 *)&position->end;
    }
    return position->length - (*(volatile const s16 *)&position->end - start);
}

s32 sub_02033C14(const RingPositionPrivate *position, s32 value) {
    return value % position->length;
}

void sub_02033C28(RingPositionPrivate *position) {
    position->current = position->end;
}

EntryPrivate *sub_02033C30(const EntryListPrivate *list) {
    register EntryPrivate *entry = list->entries;
    register s32 i;
    register s32 count = list->count;
    for (i = 0; i < count; i++, entry++) {
        if (entry->active == 0) {
            return entry;
        }
    }
    return NULL;
}

BOOL sub_02033C50(const EntryListPrivate *list) {
    register EntryPrivate *entry = list->entries;
    register s32 i;
    register s32 count = list->count;
    for (i = 0; i < count; i++, entry++) {
        if (entry->active != 0) {
            return FALSE;
        }
    }
    return TRUE;
}
