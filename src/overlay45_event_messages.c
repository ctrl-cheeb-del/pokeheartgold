#include "global.h"

#include "heap.h"
#include "msgdata.h"
#include "overlay45_event_messages_private.h"
#include "player_data.h"
#include "pm_string.h"
extern void GF_AssertFail(void);
extern void ov45_0222E0CC(EList *, ENode *);
BOOL ov45_0222DF58(u8 *, u32);
void ov45_0222DF78(EList *, u32);
void ov45_0222DFD0(EList *);
void ov45_0222E000(EList *);
void ov45_0222E0E0(ENode *, u32, u32, u32, const void *, const void *, const void *, const void *, u16, u16, u16, u16, u32, u32, u32);
void ov45_0222E03C(EList *);
ENode *ov45_0222E04C(EList *, u16);
void ov45_0222E094(ENode *, ENode *);
void ov45_0222E0A4(EList *, ENode *);
void ov45_0222E0CC(EList *, ENode *);
BOOL ov45_0222E484(EWork *, const u8 *, u32, void *, void *);
u16 ov45_0222E540(EWork *, u32);
u16 ov45_0222E550(EWork *, u32);
u16 ov45_0222E560(EWork *, u32);
u16 ov45_0222E574(EWork *, u32);
u16 ov45_0222E584(EWork *, u32);

extern BOOL ov45_0222E5B4(u32, u32);
extern const u16 ov45_02254BCA[];
extern const u16 ov45_02254BD2[];
extern const u8 gGameLanguage;
BOOL ov45_0222E14C(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E1A0(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E200(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E33C(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E39C(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E414(ENode *, u32, MessageFormat *, MsgData *, String *);
BOOL ov45_0222E4A8(EWork *, u32, MessageFormat *, MsgData *, String *);

BOOL ov45_0222DF58(u8 *p, u32 v) {
    if (v >= 20) {
        GF_AssertFail();
    }
    return *(u16 *)(p + 0x52) == v;
}

void ov45_0222DF78(EList *list, u32 heap) {
    s32 i, j;
    ENode *p;
    memset(list, 0, 0x1d4);
    for (i = 0, p = list->nodes; i < 8; p++, i++) {
        for (j = 0; j < 4; j++) {
            p->strings[j] = String_New(8, (enum HeapID)heap);
        }
    }
    *(ENode **)((u8 *)list + 0x1cc) = (ENode *)((u8 *)list + 0x1a0);
    *(ENode **)((u8 *)list + 0x1d0) = (ENode *)((u8 *)list + 0x1a0);
}

void ov45_0222DFD0(EList *list) {
    s32 i, j;
    ENode *p;
    for (i = 0, p = list->nodes; i < 8; i++, p++) {
        for (j = 0; j < 4; j++) {
            String_Delete((String *)p->strings[j]);
        }
    }
    memset(list, 0, 0x1d4);
}

void ov45_0222E000(EList *list) {
    ENode *n = list->sentinel.next;
    ENode *sentinel = &list->sentinel;
    while (n != sentinel) {
        ENode *next = n->next;
        n->rank = 0;
        if (n->timer - 1 > 0) {
            n->timer--;
        } else {
            ov45_0222E0CC(list, n);
        }
        n = next;
    }
}

void ov45_0222E03C(EList *list) {
    ov45_0222E0CC(list, *(ENode **)((u8 *)list + 0x1cc));
}

ENode *ov45_0222E04C(EList *list, u16 rank) {
    s32 i;
    ENode *ret = NULL;
    for (i = 0; i < 8; i++) {
        if (list->nodes[i].next == NULL) {
            ret = &list->nodes[i];
            break;
        }
    }
    if (ret == NULL) {
        for (i = 0; i < 8; i++) {
            if (list->nodes[i].rank >= rank) {
                ret = &list->nodes[i];
                ov45_0222E0CC(list, ret);
                break;
            }
        }
    }
    return ret;
}

void ov45_0222E094(ENode *at, ENode *n) {
    n->next = at->next;
    n->prev = at;
    at->next = n;
    n->next->prev = n;
}

void ov45_0222E0A4(EList *list, ENode *n) {
    ENode *at = list->sentinel.prev;
    ENode *sentinel = &list->sentinel;
    if (at != sentinel) {
        u16 rank = n->rank;
        do {
            if (at->rank < rank) {
                break;
            }
            at = at->prev;
        } while (at != sentinel);
    }
    ov45_0222E094(at, n);
}

void ov45_0222E0CC(EList *list, ENode *n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    n->prev = NULL;
    n->next = NULL;
}

void ov45_0222E0E0(ENode *p, u32 a, u32 b, u32 c, const void *s0, const void *s1, const void *s2, const void *s3, u16 v0, u16 v1, u16 v2, u16 v3, u32 timer, u32 rank, u32 type) {
    if (type >= 9) {
        GF_AssertFail();
    }
    p->type = type;
    p->timer = timer;
    p->rank = rank;
    p->a = a;
    p->b = b;
    p->c = c;
    p->v20 = v0;
    p->v22 = v1;
    p->v24 = v2;
    p->v26 = v3;
    if (s0 != NULL) {
        PlayerName_FlatToString((PlayerProfile *)s0, (String *)p->strings[0]);
    }
    if (s1 != NULL) {
        PlayerName_FlatToString((PlayerProfile *)s1, (String *)p->strings[1]);
    }
    if (s2 != NULL) {
        PlayerName_FlatToString((PlayerProfile *)s2, (String *)p->strings[2]);
    }
    if (s3 != NULL) {
        PlayerName_FlatToString((PlayerProfile *)s3, (String *)p->strings[3]);
    }
}

BOOL ov45_0222E14C(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    BufferString(fmt, 0, p->strings[0], 0, 1, gGameLanguage);
    BufferString(fmt, 1, p->strings[1], 0, 1, gGameLanguage);
    tmp = NewString_ReadMsgData(msg, 7);
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E1A0(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    BufferString(fmt, 0, p->strings[0], 0, 1, gGameLanguage);
    BufferString(fmt, 1, p->strings[1], 0, 1, gGameLanguage);
    BufferWiFiPlazaInstrumentName(fmt, 2, p->a);
    tmp = NewString_ReadMsgData(msg, 8);
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E200(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    u32 msgno;
    BufferWiFiPlazaActivityName(fmt, 0, p->a);
    if (p->c == 1) {
        switch (p->b) {
        case 3:
            BufferString(fmt, 1, p->strings[0], 0, 1, gGameLanguage);
            BufferString(fmt, 2, p->strings[1], 0, 1, gGameLanguage);
            BufferString(fmt, 3, p->strings[2], 0, 1, gGameLanguage);
            msgno = 0x12;
            break;
        case 2:
            BufferString(fmt, 1, p->strings[0], 0, 1, gGameLanguage);
            BufferString(fmt, 2, p->strings[1], 0, 1, gGameLanguage);
            msgno = 0x13;
            break;
        case 4:
            BufferString(fmt, 1, p->strings[0], 0, 1, gGameLanguage);
            BufferString(fmt, 2, p->strings[1], 0, 1, gGameLanguage);
            BufferString(fmt, 3, p->strings[2], 0, 1, gGameLanguage);
            BufferString(fmt, 4, p->strings[3], 0, 1, gGameLanguage);
            msgno = 6;
            break;
        default:
            return FALSE;
        }
        tmp = NewString_ReadMsgData(msg, msgno);
    } else {
        BufferString(fmt, 1, (String *)p->strings[0], 0, 1, gGameLanguage);
        BufferIntegerAsString(fmt, 2, 4 - p->b, 1, PRINTING_MODE_RIGHT_ALIGN, TRUE);
        tmp = NewString_ReadMsgData(msg, 5);
    }
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E33C(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    BufferWiFiPlazaActivityName(fmt, 0, p->a);
    BufferString(fmt, 1, (String *)p->strings[0], 0, 1, gGameLanguage);
    BufferIntegerAsString(fmt, 2, 8 - p->b, 1, PRINTING_MODE_RIGHT_ALIGN, TRUE);
    tmp = NewString_ReadMsgData(msg, 9);
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E39C(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    u32 i;
    for (i = 0; i < p->a; i++) {
        BufferString(fmt, i, p->strings[i], 0, 1, gGameLanguage);
    }
    if (p->type == 4) {
        BufferWiFiPlazaActivityName(fmt, p->a, 5);
    } else {
        BufferWiFiPlazaActivityName(fmt, p->a, 6);
    }
    tmp = NewString_ReadMsgData(msg, 0xe - p->a);
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E414(ENode *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    u32 msgno;
    switch (p->b) {
    case 0:
        BufferWiFiPlazaEventName(fmt, 0, 0);
        msgno = 0xf;
        break;
    case 1:
        BufferWiFiPlazaEventName(fmt, 0, 1);
        msgno = 0x14;
        break;
    case 2:
        BufferWiFiPlazaEventName(fmt, 0, 2);
        msgno = 0x10;
        break;
    case 4:
        msgno = 0x11;
        break;
    default:
        return FALSE;
    }
    tmp = NewString_ReadMsgData(msg, msgno);
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

BOOL ov45_0222E484(EWork *w, const u8 *enabled, u32 unused, void *msg, void *out) {
    u32 i = w->count;
    if (i >= 20) {
        return FALSE;
    }
    if (enabled[i] == 0) {
        return FALSE;
    }
    ReadMsgDataIntoString((MsgData *)msg, 0x15, (String *)out);
    return TRUE;
}

BOOL ov45_0222E4A8(EWork *p, u32 unused, MessageFormat *fmt, MsgData *msg, String *out) {
    String *tmp;
    u32 i;
    if (!ov45_0222E5B4(p->count, p->count2)) {
        return FALSE;
    }
    BufferWiFiPlazaActivityName(fmt, 0, p->count);
    for (i = 0; i < p->count2; i++) {
        BufferString(fmt, i + 1, p->strings[i], 0, 1, gGameLanguage);
    }
    if (p->count <= 1) {
        tmp = NewString_ReadMsgData(msg, ov45_02254BCA[p->count2]);
    } else {
        tmp = NewString_ReadMsgData(msg, ov45_02254BD2[p->count2]);
    }
    StringExpandPlaceholders(fmt, out, tmp);
    String_Delete(tmp);
    return TRUE;
}

u16 ov45_0222E540(EWork *p, u32 i) {
    if (i >= 2) {
        return 20;
    }
    return p->vals[i];
}

u16 ov45_0222E550(EWork *p, u32 i) {
    if (i >= 2) {
        return 20;
    }
    return p->vals[i];
}

u16 ov45_0222E560(EWork *p, u32 i) {
    if (p->count2 <= i) {
        return 20;
    }
    return p->vals[i];
}

u16 ov45_0222E574(EWork *p, u32 i) {
    if (i >= 1) {
        return 20;
    }
    return p->vals[i];
}

u16 ov45_0222E584(EWork *p, u32 i) {
    if (p->count <= i) {
        return 20;
    }
    return p->vals[i];
}
