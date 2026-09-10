#include "communication_dispatch_internal.h"

BOOL sub_0203401C(int v) {
    switch (v) {
    case 7:
    case 9:
    case 13:
    case 18:
    case 26:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL sub_02034044(int v) {
    switch (v) {
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 24:
    case 25:
    case 29:
    case 33:
    case 34:
    case 35:
    case 36:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL sub_02034084(int v) {
    if (v == 29 || v == 33 || v == 35) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02034098(int v) {
    switch (v) {
    case 19:
    case 20:
    case 21:
    case 22:
    case 23:
    case 34:
        return TRUE;
    default:
        return FALSE;
    }
}

BOOL sub_020340C4(int v) {
    switch (v) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 8:
    case 37:
    case 38:
    case 39:
    case 40:
        return TRUE;
    default:
        return FALSE;
    }
}

void sub_0203410C(const void *table, int count, void *context) {
    int i;
    if (_021D412C == NULL) {
        _021D412C = Heap_Alloc(HEAP_ID_15, sizeof(CommManager));
    }
    _021D412C->table = table;
    _021D412C->count = count;
    _021D412C->context = context;
    for (i = 0; i < 8; i++) {
        _021D412C->ready[i] = 0;
    }
    _021D412C->shutdown = 0;
}

void sub_02034154(void) {
    if (_021D412C != NULL) {
        Heap_Free(_021D412C);
        _021D412C = NULL;
    }
}

void sub_02034170(int a0, int index, int a2, int a3) {
    Handler func;
    if (index < 22) {
        func = _020F6980[index].handler;
    } else {
        GF_ASSERT(_021D412C != NULL);
        if (index > _021D412C->count + 22) {
            sub_02037974();
            return;
        }
        func = _021D412C->table[index - 22].handler;
    }
    if (func != NULL) {
        if (_021D412C != NULL) {
            func(a0, a2, a3, _021D412C->context);
        } else {
            func(a0, a2, a3, NULL);
        }
    }
}

u32 sub_020341DC(int index) {
    ValueFunc func;
    u32 result = 0;
    if (index < 22) {
        func = _020F6980[index].value;
    } else {
        GF_ASSERT(_021D412C != NULL);
        if (_021D412C == NULL) {
            sub_02037974();
            return 0;
        }
        if (index > _021D412C->count + 22) {
            GF_ASSERT(FALSE);
            sub_02037974();
            return 0;
        }
        func = _021D412C->table[index - 22].value;
    }
    if (func != NULL) {
        result = func();
    }
    return result;
}

BOOL sub_02034244(int index) {
    if (index < 22) {
        if (_020F6980[index].aux != NULL) {
            return TRUE;
        }
        return FALSE;
    } else {
        if (_021D412C->table[index - 22].aux != NULL) {
            return TRUE;
        }
        return FALSE;
    }
}
