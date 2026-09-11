#include "overlay45_state_helpers_7_private.h"

void ov45_0222A4D0(Ov45Work *w) {
    struct Bits {
        u8 low : 4;
        u8 flag : 1;
    } *bits = (void *)(w->data + 0x1fc);
    if (bits->flag == 1 && S16(w, 0x206) <= 0) {
        Sound_SetSceneAndPlayBGM(0x15, 0x481, 0);
        ov45_0222BC84(w->data + 0x1fc);
        return;
    }
    Sound_SetSceneAndPlayBGM(0x15, 0x47f, 0);
    ov45_0222BC84(w->data + 0x1fc);
}

void ov45_0222A520(Ov45Work *w, int value) {
    if (value == U8(w, 0x209)) {
        return;
    }
    U8(w, 0x209) = value;
    ov45_0222BC84(w->data + 0x1fc);
}

void ov45_0222A53C(void) {
    ov45_0222E9E0();
    ov45_0222EC68();
}
void ov45_0222A548(void) {
    ov45_0222E9E0();
}

BOOL ov45_0222A550(void *unused, int idx) {
    u32 x[2];
    ov45_0222EC10(x);
    return ((s32 *)x[1])[idx] != -1;
}

void *ov45_0222A578(Ov45Work *w, u32 idx) {
    u32 x[2];
    int value;
    if (idx >= 20) {
        GF_AssertFail();
    }
    ov45_0222EC10(x);
    value = ((s32 *)x[1])[idx];
    if (value == -1) {
        return NULL;
    }
    if (value == ov45_0222E9E0()) {
        return w->data + 0x128;
    }
    return ov45_0222EA2C(value);
}

void *ov45_0222A5C0(Ov45Work *w) {
    if (!ov45_0222BADC(w->data + 0x108, (void *)U32(w, 0))) {
        U32(w, 0x52c) = 1;
    }
    return w->data + 0x128;
}

void ov45_0222A5E8(Ov45Work *w, int value) {
    if (value >= 15) {
        GF_AssertFail();
    }
    if (!ov45_0222BADC(w->data + 0x108, (void *)U32(w, 0))) {
        U32(w, 0x52c) = 1;
        return;
    }
    if (U8(w, 0x16b) == value) {
        return;
    }
    if (value != 9 && ov45_0222AFF8(w) == 1) {
        if (ov45_0222B00C(w) == 0) {
            ov45_0222EC90(U16(w, 0x1c4));
            ov45_0222BE28(w, U16(w, 0x1c4));
        }
        ov45_0222BD5C(w->data + 0x1c0);
    }
    switch (U8(w, 0x16b)) {
    case 2:
        ov45_0222CB74(w->data + 0x4bc, 0x10, -1);
        break;
    case 3:
        ov45_0222CB74(w->data + 0x4bc, 0x11, -1);
        break;
    case 4:
        ov45_0222CB74(w->data + 0x4bc, 0x12, -1);
        break;
    case 5:
        ov45_0222CB74(w->data + 0x4bc, 0x13, -1);
        break;
    case 6:
        ov45_0222CB74(w->data + 0x4bc, 0x14, -1);
        break;
    case 7:
        ov45_0222CB74(w->data + 0x4bc, 0x15, -1);
        break;
    case 8:
        ov45_0222CB74(w->data + 0x4bc, 0x16, -1);
        break;
    }
    U8(w, 0x16b) = value;
    ov45_0222BAC4(w->data + 0x108, (void *)U32(w, 0));
    ov45_0222BA3C(w);
}

void ov45_0222A704(Ov45Work *w, int idx, int value) {
    if (idx >= 24) {
        GF_AssertFail();
    }
    ov45_0222CB74(w->data + 0x4bc, idx, value);
    ov45_0222BA3C(w);
}

void ov45_0222A72C(Ov45Work *w, u8 value) {
    if (value >= 27) {
        GF_AssertFail();
    }
    if (!ov45_0222BADC(w->data + 0x108, (void *)U32(w, 0))) {
        U32(w, 0x52c) = 1;
        return;
    }
    U8(w, 0x169) = value;
    ov45_0222BAC4(w->data + 0x108, (void *)U32(w, 0));
    ov45_0222BA3C(w);
}

void ov45_0222A770(Ov45Work *w, int a, int b) {
    if (a >= 18) {
        GF_AssertFail();
    }
    if (b >= 18) {
        GF_AssertFail();
    }
    if (!ov45_0222BADC(w->data + 0x108, (void *)U32(w, 0))) {
        U32(w, 0x52c) = 1;
        return;
    }
    if (a < 18 && b < 18) {
        if (a == 0) {
            U16(w, 0x1b0) = b;
            U16(w, 0x1b2) = 0;
        } else {
            U16(w, 0x1b0) = a;
            U16(w, 0x1b2) = b;
        }
        ov45_0222BAC4(w->data + 0x108, (void *)U32(w, 0));
        ov45_0222BA3C(w);
    }
}

void ov45_0222A7DC(Ov45Work *w, u32 a, u32 b) {
    if (b >= 3) {
        GF_AssertFail();
    }
    if (!ov45_0222BADC(w->data + 0x108, (void *)U32(w, 0))) {
        U32(w, 0x52c) = 1;
        return;
    }
    if (b < 3) {
        U32(w, 0x1b4) = a;
        U32(w, 0x1b8) = b;
        U8(w, 0x20b) = (U8(w, 0x20b) & ~0xf) | 1;
        ov45_0222B118(w, 6);
        ov45_0222BAC4(w->data + 0x108, (void *)U32(w, 0));
        ov45_0222BA3C(w);
    }
}

void ov45_0222A844(Ov45Work *src, PlayerProfile *profile, enum HeapID heapId) {
    BOOL invalid;
    int ok = ov45_0222B28C(src->data + 8, 8, heapId);
    String *b;
    String *a;
    invalid = FALSE;
    if (ok == 1) {
        Save_Profile_PlayerName_Set(profile, (u16 *)(src->data + 8));
        a = String_New(0x20, heapId);
        b = String_New(0x20, heapId);
        PlayerName_FlatToString(profile, b);
        if (!FontID_String_AllCharsValid((FontID)0, b, a)) {
            invalid = TRUE;
        }
        String_Delete(a);
        String_Delete(b);
    } else {
        invalid = TRUE;
    }
    if (invalid) {
        MsgData *msg = NewMsgDataFromNarc((MsgDataLoadType)1, (NarcId)0x1b, 0x309, heapId);
        String *name = NewString_ReadMsgData(msg, 0x40);
        PlayerName_StringToFlat(profile, name);
        String_Delete(name);
        DestroyMsgData(msg);
    }
    PlayerProfile_SetTrainerID(profile, ov45_0222A9A0(src));
    PlayerProfile_SetTrainerGender(profile, ov45_0222A9CC(src));
    PlayerProfile_SetAvatar(profile, ov45_0222AA5C(src));
    PlayerProfile_SetLanguage(profile, ov45_0222AA10(src));
    PlayerProfile_SetGameClearFlag(profile);
}
