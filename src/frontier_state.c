#include "unk_02030A98.h"
void *sub_02030CC8(SaveData *save);
void *sub_02030B04(SaveData *save);
void sub_02030A98(void *state);
u32 sub_02030AD4(u8 *state, int field, int index);
void sub_02030AF8(void *state);
typedef struct {
    u8 kind : 3, active : 1, rest : 4;
    u8 value;
    u8 bytes[2];
    u16 values[20];
    u16 more[20];
} FrontierState;
u32 sub_02030B14(FrontierState *state);
void sub_02030B1C(FrontierState *state, int value);
void sub_02030B30(FrontierState *state, int field, int index, int unused, void *value);
u32 sub_02030B88(FrontierState *state, int field, int index, int unused, int unused2);
u8 sub_02030BD0(int index, u8 *values);
void sub_02030BF4(int index, u8 *values, int value);
void sub_02030C34(u8 *values);
void sub_02030C50(void *state);
void sub_02030A98(void *state) {
    MI_CpuFill8(state, 0, 4);
}
void sub_02030AA4(u32 state, u32 field, u8 index, u8 *value) {
    if (field == 10) {
        if (*value >= 1) {
            *(u8 *)state |= 1 << index;
        } else {
            *(u8 *)state &= (1 << index) ^ 0xff;
        }
    }
}
u32 sub_02030AD4(u8 *state, int field, int index) {
    if (field == 10) {
        return (*state >> index) & 1;
    }
    return 0;
}
int sub_02030AE8(SaveData *save) {
    return (int)((u8 *)Save_Frontier_GetStatic(save) + 0x1618);
}
void sub_02030AF8(void *state) {
    MI_CpuFill8(state, 0, 0x54);
}

void *sub_02030B04(SaveData *save) {
    return (u8 *)Save_Frontier_GetStatic(save) + 0x8e0;
}
u32 sub_02030B14(FrontierState *state) {
    return state->active;
}
void sub_02030B1C(FrontierState *state, int value) {
    state->active = (u8)value;
}
void sub_02030B30(FrontierState *state, int field, int index, int unused, void *value) {
    switch (field) {
    case 0:
        state->kind = *(u8 *)value;
        break;
    case 1:
        state->value = *(u8 *)value;
        break;
    case 2:
        state->values[index] = *(u16 *)value;
        break;
    case 3:
        state->bytes[index] = *(u8 *)value;
        break;
    case 4:
        state->more[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
u32 sub_02030B88(FrontierState *state, int field, int index, int unused, int unused2) {
    switch (field) {
    case 0:
        return state->kind;
    case 1:
        return state->value;
    case 2:
        return state->values[index];
    case 3:
        return state->bytes[index];
    case 4:
        return state->more[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}
u8 sub_02030BD0(int index, u8 *values) {
    u8 byte = (index >> 1);
    u8 nibble = index % 2;
    return (values[byte] >> (nibble * 4)) & 15;
}
void sub_02030BF4(int index, u8 *values, int value) {
    u8 byte = (index >> 1);
    u8 nibble = index % 2;
    if (nibble == 0) {
        values[byte] &= 0xf0;
    } else {
        values[byte] &= 0xf;
    }
    values[byte] |= (u8)(value << (nibble * 4));
}
void sub_02030C34(u8 *values) {
    for (int i = 0; i < 18; i++) {
        sub_02030BF4((u8)i, values, 0);
    }
}
void sub_02030C50(void *state) {
    MI_CpuFill8(state, 0, 4);
}
int sub_02030C5C(SaveData *save) {
    return (int)((u8 *)Save_Frontier_GetStatic(save) + 0x161c);
}

void sub_02030C6C(u32 address, u32 field, u32 index, u32 unused, u8 *volatile input) {
    // Preserve the original unconditional load of the stack argument.
    u8 *value = input;
    switch (field) {
    case 5:
        if (*value >= 1) {
            *(u8 *)address |= 1 << index;
        } else {
            *(u8 *)address &= (1 << index) ^ 0xff;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
int sub_02030CA0(int address, int field, u8 index, int unused, int unused2) {
    if (field == 5) {
        return (*(u8 *)address >> index) & 1;
    }
    GF_ASSERT(FALSE);
    return 0;
}
void sub_02030CBC(void *state);
u32 sub_02030CD8(FrontierState *state);
void sub_02030CE0(FrontierState *state, int value);
void sub_02030CBC(void *state) {
    MI_CpuFill8(state, 0, 0x74);
}
void *sub_02030CC8(SaveData *save) {
    return (u8 *)Save_Frontier_GetStatic(save) + 0x8e0;
}
u32 sub_02030CD8(FrontierState *state) {
    return state->active;
}
void sub_02030CE0(FrontierState *state, int value) {
    state->active = (u8)value;
}
typedef struct {
    u8 kind : 3, active : 1, rest : 4;
    u8 value, padding;
    u8 bytes[3];
    u16 values6[14];
    u16 values22[4];
    u8 matrix[4][4];
    u16 padding3a;
    u32 values3c[4];
    u16 values4c[4];
    u16 values54[16];
} FrontierState2;
void sub_02030CF4(FrontierState2 *state, int field, int index, int column, void *value);
u32 sub_02030D84(FrontierState2 *state, int field, int index, int column, int unused);
void sub_02030DFC(void *state);
void sub_02030CF4(FrontierState2 *state, int field, int index, int column, void *value) {
    switch (field) {
    case 0:
        state->kind = *(u8 *)value;
        break;
    case 1:
        state->value = *(u8 *)value;
        break;
    case 2:
        state->values22[index] = *(u16 *)value;
        break;
    case 3:
        state->matrix[index][column] = *(u8 *)value;
        break;
    case 4:
        state->values3c[index] = *(u32 *)value;
        break;
    case 5:
        state->values4c[index] = *(u16 *)value;
        break;
    case 6:
        state->values6[index] = *(u16 *)value;
        break;
    case 7:
        state->bytes[index] = *(u8 *)value;
        break;
    case 8:
        state->values54[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
u32 sub_02030D84(FrontierState2 *state, int field, int index, int column, int unused) {
    switch (field) {
    case 0:
        return state->kind;
    case 1:
        return state->value;
    case 2:
        return state->values22[index];
    case 3:
        return state->matrix[index][column];
    case 4:
        return state->values3c[index];
    case 5:
        return state->values4c[index];
    case 6:
        return state->values6[index];
    case 7:
        return state->bytes[index];
    case 8:
        return state->values54[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}
void sub_02030DFC(void *state) {
    MI_CpuFill8(state, 0, 4);
}
u32 sub_02030E08(SaveData *save) {
    return (u32)((u8 *)Save_Frontier_GetStatic(save) + 0x1620);
}
void sub_02030E18(u32 address, u32 field, u32 index, u32 unused, u8 *volatile input) {
    // Preserve the original unconditional load of the stack argument.
    u8 *value = input;
    switch (field) {
    case 9:
        if (*value >= 1) {
            *(u8 *)address |= 1 << index;
        } else {
            *(u8 *)address &= (1 << index) ^ 0xff;
        }
        break;
    case 10:
        ((u8 *)address)[1] = 1;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
u32 sub_02030E58(u32 address, u32 field, u8 index, u32 unused, u32 unused2) {
    switch (field) {
    case 9:
        return (*(u8 *)address >> index) & 1;
    case 10:
        return ((u8 *)address)[1];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}
void sub_02030E7C(void *state);
void sub_02030EA0(FrontierState *state, int value);
void sub_02030E7C(void *state) {
    MI_CpuFill8(state, 0, 0x48);
}
void *sub_02030E88(SaveData *save) {
    return (u8 *)Save_Frontier_GetStatic(save) + 0x8e0;
}
u32 sub_02030E98(u32 state) {
    return ((FrontierState *)state)->active;
}
void sub_02030EA0(FrontierState *state, int value) {
    state->active = (u8)value;
}
typedef struct {
    u8 kind : 3, active : 1, flag4 : 1, rest : 3;
    u8 value1, value2, bytes[3];
    u16 values6[4];
    u16 valuese[14];
    u16 values2a[15];
} FrontierState3;
void sub_02030EB4(FrontierState3 *state, int field, int index, int unused, void *value);
u32 sub_02030F34(FrontierState3 *state, int field, int index, int unused, int unused2);
void sub_02030F94(void *state);
void sub_02030EB4(FrontierState3 *state, int field, int index, int unused, void *value) {
    switch (field) {
    case 0:
        state->kind = *(u8 *)value;
        break;
    case 1:
        state->flag4 = *(u8 *)value;
        break;
    case 2:
        state->value1 = *(u8 *)value;
        break;
    case 3:
        state->value2 = *(u8 *)value;
        break;
    case 4:
        state->values6[index] = *(u16 *)value;
        break;
    case 5:
        state->valuese[index] = *(u16 *)value;
        break;
    case 6:
        state->bytes[index] = *(u8 *)value;
        break;
    case 7:
        state->values2a[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}
u32 sub_02030F34(FrontierState3 *state, int field, int index, int unused, int unused2) {
    switch (field) {
    case 0:
        return state->kind;
    case 1:
        return state->flag4;
    case 2:
        return state->value1;
    case 3:
        return state->value2;
    case 4:
        return state->values6[index];
    case 5:
        return state->valuese[index];
    case 6:
        return state->bytes[index];
    case 7:
        return state->values2a[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}
void sub_02030F94(void *state) {
    MI_CpuFill8(state, 0, 4);
}
void *sub_02030FA0(SaveData *save) {
    return (u8 *)Save_Frontier_GetStatic(save) + 0x1624;
}
void sub_02030FB0(void *address, u32 field, u32 index, u32 unused, u8 *volatile input) {
    // Preserve the original unconditional load of the stack argument.
    u8 *value = input;
    if (field == 8) {
        if (*value >= 1) {
            *(u8 *)address |= 1 << index;
        } else {
            *(u8 *)address &= (1 << index) ^ 0xff;
        }
    } else {
        GF_ASSERT(FALSE);
    }
}
u32 sub_02030FE4(void *address, u32 field, u8 index, u32 unused, u32 unused2) {
    if (field == 8) {
        return (*(u8 *)address >> index) & 1;
    }
    GF_ASSERT(FALSE);
    return 0;
}
