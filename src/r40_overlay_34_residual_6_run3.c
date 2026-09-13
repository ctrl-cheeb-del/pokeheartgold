#include "r40_overlay_34_residual_6_private.h"

BOOL ov34_0225E428(void *work, void *mail, u32 value) {
    int i;

    if (!MailMsg_IsInit(mail)) {
        return FALSE;
    }
    for (i = 0; i < (int)U32_AT(PTR_AT(work, 0x270), 0x348); i++) {
        u8 *entry = (u8 *)PTR_AT(work, 0x270) + i * 0x1C;
        if (value == U32_AT(entry, 0xC) && MailMsg_Compare(mail, entry + 0x14)) {
            break;
        }
    }
    if (i != (int)U32_AT(PTR_AT(work, 0x270), 0x348) && U32_AT(PTR_AT(work, 0x270), 0x348) != 0) {
        return FALSE;
    }
    if (value != U32_AT((u8 *)PTR_AT(work, 0x270) + i * 0x1C, 0xC)) {
        MailMsg_Compare(mail, (u8 *)PTR_AT(work, 0x270) + i * 0x1C + 0x14);
    }
    return TRUE;
}

void ov34_0225E4A8(void *work, void *profile, void *mail, u32 trainerId) {
    BOOL atEnd = FALSE;

    if (U16_AT(work, 0x288) == U16_AT(work, 0x284) - 3) {
        atEnd = TRUE;
    }
    ov34_0225E348(work, trainerId, mail, profile);
    if (U16_AT(work, 0x28A) != 0 && atEnd) {
        U16_AT(work, 0x288) = U32_AT(PTR_AT(work, 0x270), 0x348) - 3;
    }
    ov34_0225E560(work);
}

void ov34_0225E4F8(void *work) {
    int i;

    if (!FieldSystem_TaskIsRunning(PTR_AT(work, 0xC))) {
        for (i = 0; i < 16; i++) {
            void *entry = sub_02035754(i);
            if (entry != NULL) {
                u8 *value = (u8 *)entry + 0x50;
                void *mail = value + 8;
                if (ov34_0225E428(work, mail, U32_AT(value, 0))) {
                    void *profile = sub_02035798(i);
                    ov34_0225E4A8(work, profile, mail, U32_AT(value, 0));
                }
            }
        }
        void *mail = sub_0205AA84(PTR_AT(work, 8));
        if (mail != NULL) {
            ov34_0225E4A8(work, PTR_AT(work, 0x10), mail, PlayerProfile_GetTrainerID(PTR_AT(work, 0x10)));
        }
    }
}
