#include "global.h"

#include "bg_window.h"
#include "heap.h"
#include "list_menu_cursor.h"
#include "pm_string.h"
#include "spl.h"
#include "text.h"

extern void *sub_02015550(SPLEmitter *, int);

void sub_02015640(SPLEmitter *, VecFx32 *);
void sub_02015674(SPLEmitter *, s16 *);
void sub_0201568C(SPLEmitter *, s16 *);
void sub_020156A8(SPLEmitter *, u16 *);
void sub_020156BC(SPLEmitter *, u16 *);
void sub_020156D8(SPLEmitter *, u16 *);
void sub_020156EC(SPLEmitter *, u16 *);
void sub_02015708(SPLEmitter *, VecFx32 *);
void sub_02015720(SPLEmitter *, VecFx32 *);
void sub_02015754(SPLEmitter *, s16 *);
void sub_0201576C(SPLEmitter *, s16 *);

void sub_02015640(SPLEmitter *emitter, VecFx32 *value) {
    VecFx32 *field = sub_02015550(emitter, 2);
    if (field == NULL) {
        VecFx32 zero = { 0, 0, 0 };
        *value = zero;
        return;
    }
    *value = *field;
}

void sub_02015674(SPLEmitter *emitter, s16 *value) {
    u8 *field = sub_02015550(emitter, 2);
    if (field != NULL) {
        *(s16 *)(field + 0xC) = *value;
    }
}
void sub_0201568C(SPLEmitter *emitter, s16 *value) {
    u8 *field = sub_02015550(emitter, 2);
    if (field == NULL) {
        *value = 0;
    } else {
        *value = *(s16 *)(field + 0xC);
    }
}
void sub_020156A8(SPLEmitter *emitter, u16 *value) {
    u16 *field = sub_02015550(emitter, 3);
    if (field != NULL) {
        field[0] = *value;
    }
}
void sub_020156BC(SPLEmitter *emitter, u16 *value) {
    u16 *field = sub_02015550(emitter, 3);
    if (field == NULL) {
        *value = 0;
    } else {
        *value = field[0];
    }
}
void sub_020156D8(SPLEmitter *emitter, u16 *value) {
    u16 *field = sub_02015550(emitter, 3);
    if (field != NULL) {
        field[1] = *value;
    }
}
void sub_020156EC(SPLEmitter *emitter, u16 *value) {
    u16 *field = sub_02015550(emitter, 3);
    if (field == NULL) {
        *value = 0;
    } else {
        *value = field[1];
    }
}
void sub_02015708(SPLEmitter *emitter, VecFx32 *value) {
    VecFx32 *field = sub_02015550(emitter, 5);
    if (field != NULL) {
        *field = *value;
    }
}
void sub_02015720(SPLEmitter *emitter, VecFx32 *value) {
    VecFx32 *field = sub_02015550(emitter, 5);
    if (field == NULL) {
        VecFx32 zero = { 0, 0, 0 };
        *value = zero;
        return;
    }
    *value = *field;
}
void sub_02015754(SPLEmitter *emitter, s16 *value) {
    u8 *field = sub_02015550(emitter, 5);
    if (field != NULL) {
        *(s16 *)(field + 0xC) = *value;
    }
}
void sub_0201576C(SPLEmitter *emitter, s16 *value) {
    u8 *field = sub_02015550(emitter, 5);
    if (field == NULL) {
        *value = 0;
    } else {
        *value = *(s16 *)(field + 0xC);
    }
}
