#include "r40_overlay_45_thumb_residual_22_private.h"

typedef struct Req2 {
    void *selected[2];
    u16 values[2];
} Req2;
typedef struct Req2Option {
    void *selected[2];
    u16 values[2];
    u32 option;
} Req2Option;
typedef struct Req4 {
    u32 count;
    void *selected[4];
    u16 values[4];
} Req4;
typedef struct Req4Flags {
    u32 option;
    u32 count;
    void *selected[4];
    u16 values[4];
    u32 flag;
} Req4Flags;
typedef struct Req1Flags {
    u32 option;
    u32 count;
    void *selected;
    u16 value;
} Req1Flags;
typedef struct Req4Option {
    u32 option;
    u32 count;
    void *selected[4];
    u16 values[4];
} Req4Option;

void ov45_0222BE9C(Ov45State *state, Ov45Input *input) {
    Req2 req;
    int i;
    int slot;
    if (input->count != 2) {
        return;
    }
    for (i = 0; i < 2; i++) {
        slot = ov45_0222EC68(input->values[i]);
        if (slot == -1) {
            return;
        }
        ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
    }
    req.selected[0] = state->selected[0];
    req.selected[1] = state->selected[1];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    ov45_0222D940(state->context, &req);
}

void ov45_0222BF18(Ov45State *state, Ov45Input *input) {
    Req2Option req;
    int i;
    int slot;
    if (input->count != 2) {
        return;
    }
    for (i = 0; i < 2; i++) {
        slot = ov45_0222EC68(input->values[i]);
        if (slot == -1) {
            return;
        }
        ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
    }
    req.selected[0] = state->selected[0];
    req.selected[1] = state->selected[1];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    req.option = input->option;
    ov45_0222D990(state->context, &req);
}

void ov45_0222BF98(Ov45State *state, Ov45Input *input) {
    void *selected[4];
    Req4Flags req;
    int i;
    int slot;
    if (input->count > 4 || input->count == 0) {
        return;
    }
    if ((input->flag) == 1) {
        for (i = 0; i < 4; i++) {
            if (i < input->count) {
                slot = ov45_0222EC68(input->values[i]);
                if (slot == -1) {
                    return;
                }
                ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
                selected[i] = state->selected[i];
            } else {
                selected[i] = 0;
            }
        }
    } else {
        for (i = 0; i < 4; i++) {
            if (i == 0) {
                slot = ov45_0222EC68(input->values[i]);
                if (slot == -1) {
                    return;
                }
                ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
                selected[i] = state->selected[i];
            } else {
                selected[i] = 0;
            }
        }
    }
    req.option = input->mode;
    req.count = input->count;
    req.selected[0] = selected[0];
    req.selected[1] = selected[1];
    req.selected[2] = selected[2];
    req.selected[3] = selected[3];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    req.values[2] = ov45_0222EC68(input->values[2]);
    req.values[3] = ov45_0222EC68(input->values[3]);
    req.flag = input->flag;
    ov45_0222D9EC(state->context, &req);
}

void ov45_0222C0CC(Ov45State *state, Ov45Input *input) {
    Req1Flags req;
    int slot;
    if (input->count > 8 || input->count == 0) {
        return;
    }
    slot = ov45_0222EC68(input->values[0]);
    if (slot == -1) {
        return;
    }
    ov45_0222A844(ov45_0222A578(state, slot), state->selected[0], state->heapId);
    req.option = input->mode;
    req.count = input->count;
    req.selected = state->selected[0];
    req.value = ov45_0222EC68(input->values[0]);
    ov45_0222DA80(state->context, &req);
}

void ov45_0222C130(Ov45State *state, Ov45Input *input) {
    void *selected[4];
    Req4 req;
    int i;
    int slot;
    if (input->count > 4 || input->count == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (i < input->count) {
            slot = ov45_0222EC68(input->values[i]);
            if (slot == -1) {
                return;
            }
            ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
            selected[i] = state->selected[i];
        } else {
            selected[i] = 0;
        }
    }
    req.count = input->count;
    req.selected[0] = selected[0];
    req.selected[1] = selected[1];
    req.selected[2] = selected[2];
    req.selected[3] = selected[3];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    req.values[2] = ov45_0222EC68(input->values[2]);
    req.values[3] = ov45_0222EC68(input->values[3]);
    ov45_0222DAE0(state->context, &req);
}

void ov45_0222C1EC(Ov45State *state, Ov45Input *input) {
    void *selected[4];
    Req4 req;
    int i;
    int slot;
    if (input->count > 4 || input->count == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (i < input->count) {
            slot = ov45_0222EC68(input->values[i]);
            if (slot == -1) {
                return;
            }
            ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
            selected[i] = state->selected[i];
        } else {
            selected[i] = 0;
        }
    }
    req.count = input->count;
    req.selected[0] = selected[0];
    req.selected[1] = selected[1];
    req.selected[2] = selected[2];
    req.selected[3] = selected[3];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    req.values[2] = ov45_0222EC68(input->values[2]);
    req.values[3] = ov45_0222EC68(input->values[3]);
    ov45_0222DB3C(state->context, &req);
}

void ov45_0222C2A8(Ov45State *state, Ov45Input *input) {
    void *selected[4];
    Req4Option req;
    int i;
    int slot;
    if (input->count > 4 || input->count == 0) {
        return;
    }
    for (i = 0; i < 4; i++) {
        if (i < input->count) {
            slot = ov45_0222EC68(input->values[i]);
            if (slot == -1) {
                return;
            }
            ov45_0222A844(ov45_0222A578(state, slot), state->selected[i], state->heapId);
            selected[i] = state->selected[i];
        } else {
            selected[i] = 0;
        }
    }
    req.option = input->mode;
    req.count = input->count;
    req.selected[0] = selected[0];
    req.selected[1] = selected[1];
    req.selected[2] = selected[2];
    req.selected[3] = selected[3];
    req.values[0] = ov45_0222EC68(input->values[0]);
    req.values[1] = ov45_0222EC68(input->values[1]);
    req.values[2] = ov45_0222EC68(input->values[2]);
    req.values[3] = ov45_0222EC68(input->values[3]);
    ov45_0222DC64(state->context, &req);
}
