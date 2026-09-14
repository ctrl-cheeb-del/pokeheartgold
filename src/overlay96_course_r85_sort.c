#include "overlay96_course_r85_sort_private.h"

u8 ov96_0220472C(u32 excludedGroup, Ov96R85Entry **entries, Ov96R85Entry **sorted) {
    u8 count;
    u8 i;
    u8 equalCount;
    Ov96R85Node list[10];

    list[0].prev = &list[1];
    list[0].next = &list[1];
    list[0].entry = NULL;
    equalCount = 0;
    count = equalCount;

    for (i = count; i < 12; i++) {
        if (i / 3 != excludedGroup) {
            u8 j;
            Ov96R85Entry *entry = entries[i];
            Ov96R85Node *node = &list[count + 1];
            Ov96R85Node *cursor = &list[0];

            node->entry = entry;
            node->next = NULL;
            node->prev = NULL;
            j = 0;
            if (count > equalCount) {
                u16 score = node->entry->score;
                do {
                    cursor = cursor->next;
                    if (cursor->entry->score < score) {
                        cursor->prev->next = node;
                        node->prev = cursor->prev;
                        node->next = cursor;
                        cursor->prev = node;
                        break;
                    }
                    j++;
                } while (j < count);
            }
            if (j == count) {
                cursor->next = node;
                node->prev = cursor;
            }
            count++;
        }
    }

    {
        Ov96R85Node *cursor = list[0].next;
        u16 score = cursor->entry->score;
        cursor = &list[0];
        for (i = 0; i < 9; i++) {
            cursor = cursor->next;
            sorted[i] = cursor->entry;
            if (score == sorted[i]->score) {
                equalCount++;
            }
        }
    }
    if (equalCount == 0) {
        GF_AssertFail();
    }
    return equalCount;
}
