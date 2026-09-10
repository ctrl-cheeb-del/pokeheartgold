#include "pokepic_animation_internal.h"

void sub_020176CC(PicEntry *data) {
    u8 dst;
    sub_02017294(data, &dst);
    data->cursor++;
    data->vars[dst] = (u32)sub_02017214(data->cursor);
}

void sub_020176F0(PicEntry *data) {
    GF_ASSERT(data->saved == NULL);
    data->cursor++;
    data->saved = data->cursor;
    data->limit = (u32)sub_02017214(data->cursor);
    data->current = 0;
}

void sub_02017714(PicEntry *data) {
    data->current++;
    if (data->current >= data->limit) {
        data->saved = NULL;
        data->current = 0;
        data->limit = 0;
    } else {
        data->cursor = data->saved;
    }
}

void sub_02017730(PicEntry *data) {
    u32 attr;
    u8 var;
    sub_0201726C(data, &attr);
    sub_02017294(data, &var);
    Pokepic_SetAttr(data->pic, attr, data->vars[var]);
}

void sub_0201775C(PicEntry *data) {
    u32 attr;
    u8 var;
    sub_0201726C(data, &attr);
    sub_02017294(data, &var);
    Pokepic_AddAttr(data->pic, attr, data->vars[var]);
}

void sub_02017788(PicEntry *data) {
    struct {
        u8 command;
        u8 valueType;
        u8 variable;
        u8 pad;
        u32 value;
        u32 attr;
    } local;
    sub_0201726C(data, &local.attr);
    sub_02017280(data, &local.valueType);
    if (local.valueType == 0x14) {
        sub_0201726C(data, &local.value);
    } else if (local.valueType == 0x15) {
        sub_02017294(data, &local.variable);
        local.value = data->vars[local.variable];
    } else {
        GF_ASSERT(FALSE);
    }
    sub_02017280(data, &local.command);
    if (local.command == 0x16) {
        Pokepic_SetAttr(data->pic, local.attr, local.value);
    } else if (local.command == 0x17) {
        Pokepic_AddAttr(data->pic, local.attr, local.value);
    } else {
        GF_ASSERT(FALSE);
    }
}
