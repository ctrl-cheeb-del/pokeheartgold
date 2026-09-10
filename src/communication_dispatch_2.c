#include "communication_dispatch_internal.h"

BOOL sub_02033C70(PacketQueue *queue) {
    if (queue->head != NULL) {
        if (queue->head->next != NULL) {
            queue->head = queue->head->next;
            queue->head->prev = NULL;
        } else {
            queue->head = NULL;
            queue->tail = NULL;
        }
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02033C94(ByteWriter *writer, u8 value) {
    *writer->dest = value;
    writer->dest++;
    writer->remaining--;
    if (writer->remaining == 0) {
        return TRUE;
    }
    return FALSE;
}
