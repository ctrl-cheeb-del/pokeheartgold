#include "overlay40_residual31_private.h"

#define PTR(p, off)  (*(void **)((u8 *)(p) + (off)))
#define WORD(p, off) (*(u32 *)((u8 *)(p) + (off)))

void ov40_02238290(void *p);
void ov40_02238304(void *p);
int ov40_02238358(void *p);
void ov40_02230DCC(void *p, void *str);
void ov40_0222FA88(void *p);
void ov40_0222F5EC(void *p, int value);
void ov40_0222EFD8(void *p, void *owner, void *data);
void sub_020878EC(void *p, int a1, int a2);

void ov40_02238290(void *p) {
    void *inner = PTR(p, 0x860);
    int i;
    u8 *entry;
    u8 *source;

    i = 0;
    if (*(int *)((u8 *)inner + 0x388) > 0) {
        entry = inner;
        source = inner;
        do {
            PTR(entry, 0x2E10) = String_New(20, (enum HeapID)109);
            CopyU16ArrayToString(PTR(entry, 0x2E10), PTR(source, 0x38C));
            ov40_02230DCC(p, PTR(entry, 0x2E10));
            PTR(entry, 0x2E0C) = String_New(30, (enum HeapID)109);
            CopyU16ArrayToString(PTR(entry, 0x2E0C), (u16 *)((u8 *)PTR(source, 0x38C) + 0x80));
            i++;
            entry += 8;
            source += 4;
        } while (i < *(int *)((u8 *)inner + 0x388));
    }
}

void ov40_02238304(void *p) {
    void *inner = PTR(p, 0x860);
    int i;
    u8 *entry;
    void *string;

    i = 0;
    if (*(int *)((u8 *)inner + 0x388) > 0) {
        entry = inner;
        do {
            string = PTR(entry, 0x2E0C);
            if (string != NULL) {
                String_Delete(string);
                PTR(entry, 0x2E0C) = NULL;
            }
            string = PTR(entry, 0x2E10);
            if (string != NULL) {
                String_Delete(string);
                PTR(entry, 0x2E10) = NULL;
            }
            i++;
            entry += 8;
        } while (i < *(int *)((u8 *)inner + 0x388));
    }
}

int ov40_02238358(void *p) {
    void *inner;

    inner = PTR(p, 0x860);
    if (WORD(inner, 0x2F64) == 0) {
        ov40_0222FA88((u8 *)p + 0x47C);
        ov40_0222F5EC((u8 *)p + 0x49C, *(s16 *)((u8 *)p + 0x48C));
        ov40_0222EFD8((u8 *)p + 0x49C, p, (u8 *)inner + 0x2E0C);
        sub_020878EC(PTR(p, 0x6F0), 0x10, (s16)(WORD(p, 0x4D8) * 24 + 0x44));
    }
    TouchHitboxController_IsTriggered(PTR(inner, 0x33C));
    return 0;
}
