#include "global.h"

extern void GF_AssertFail(void);

typedef int (*Ov45TypeFn)(void *, int);
typedef struct Ov45Pair {
    u16 state;
    u16 value;
} Ov45Pair;
extern Ov45TypeFn ov45_02254BE8[];

typedef void *(*Ov45MessageFn)(void *, int, void *, void *, int, int);
extern Ov45MessageFn ov45_02254C0C[];
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void DestroyMsgData(void *);
extern void *MessageFormat_New(int);
extern void MessageFormat_Delete(void *);

int ov45_0222DDE4(void *, int, int);
BOOL ov45_0222DD44(void *);
u8 ov45_0222DD5C(void *);
void *ov45_0222DD78(void *, int, int, int, int);
void ov45_0222DE1C(void *);
void ov45_0222DE3C(void *, int, int, int);
void ov45_0222DE58(void *, int, int, int);
void ov45_0222DE74(void *, int);
void ov45_0222DE8C(void *, int, int);
void ov45_0222DEA4(void *, int);
void ov45_0222DEB8(void *, int);
BOOL ov45_0222DECC(void *, int);
int ov45_0222DEE0(void *, int);
BOOL ov45_0222DEF4(void *, int);
BOOL ov45_0222DF14(void *, int);
int ov45_0222DF38(void *, int);

BOOL ov45_0222DD44(void *p) {
    return *(void **)((u8 *)p + 0x228) != (u8 *)p + 0x1fc;
}

u8 ov45_0222DD5C(void *p) {
    if (!ov45_0222DD44(p)) {
        GF_AssertFail();
    }
    return **(u8 **)((u8 *)p + 0x228);
}

void *ov45_0222DD78(void *owner, int arg1, int unused, int arg3, int heapId) {
    void *format;
    void *msgData;
    void *result;
    u8 *object;
    int type;

    if (!ov45_0222DD44(owner)) {
        GF_AssertFail();
    }
    object = *(u8 **)((u8 *)owner + 0x228);
    msgData = NewMsgDataFromNarc(1, 0x1b, 0x2f5, heapId);
    format = MessageFormat_New(heapId);
    type = *object;
    if ((u32)type < 9) {
        result = ov45_02254C0C[type](object, arg1, format, msgData, arg3, heapId);
    } else {
        result = NULL;
    }
    DestroyMsgData(msgData);
    MessageFormat_Delete(format);
    return result;
}

int ov45_0222DDE4(void *owner, int unused, int arg) {
    u8 *p;
    int type;

    if (!ov45_0222DD44(owner)) {
        GF_AssertFail();
    }
    p = *(u8 **)((u8 *)owner + 0x228);
    type = *p;
    if ((u32)type < 9) {
        return ov45_02254BE8[type](p, arg);
    }
    GF_AssertFail();
    return 20;
}

void ov45_0222DE1C(void *p) {
    int i;

    for (i = 0; i < 20; i++) {
        ov45_0222DE3C(p, i, 2, 0);
    }
}

void ov45_0222DE3C(void *p, int i, int a, int b) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    ((Ov45Pair *)p)[i].state = a;
    ((Ov45Pair *)p)[i].value = b;
}

void ov45_0222DE58(void *p, int i, int a, int b) {
    ov45_0222DE3C(p, i, a, b);
    ov45_0222DEA4(p, 1);
    ov45_0222DEB8(p, i);
}

void ov45_0222DE74(void *p, int i) {
    ov45_0222DE3C(p, i, 2, 0);
    ov45_0222DEA4(p, 2);
}

void ov45_0222DE8C(void *p, int i, int value) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    *(u16 *)((u8 *)p + i * 4 + 2) = value;
}

void ov45_0222DEA4(void *p, int value) {
    if (value > 2) {
        GF_AssertFail();
    }
    *(u16 *)((u8 *)p + 0x50) = value;
}

void ov45_0222DEB8(void *p, int value) {
    if ((u32)value >= 20) {
        GF_AssertFail();
    }
    *(u16 *)((u8 *)p + 0x52) = value;
}

BOOL ov45_0222DECC(void *p, int i) {
    return ov45_0222DEE0(p, i) != 2;
}

int ov45_0222DEE0(void *p, int i) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    return *(u16 *)((u8 *)p + i * 4);
}

BOOL ov45_0222DEF4(void *p, int i) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    return (*(u16 *)((u8 *)p + i * 4 + 2) & 1) != 0;
}

BOOL ov45_0222DF14(void *p, int i) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    return (*(u16 *)((u8 *)p + i * 4 + 2) & 2) != 0;
}

int ov45_0222DF38(void *p, int i) {
    if ((u32)i >= 20) {
        GF_AssertFail();
    }
    return *(u16 *)((u8 *)p + i * 4 + 2);
}
