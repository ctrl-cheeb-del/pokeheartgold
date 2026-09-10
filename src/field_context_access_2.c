#include "field_context_access_internal.h"

void sub_020692A0(u32 flag, u32 version, u32 stars, u32 gender, u8 language, TrainerCardBuffer *card) {
    card->raw[4] = (card->raw[4] & ~1) | (flag & 1);
    card->raw[0] = version;
    card->raw[3] = stars;
    card->raw[1] = language;
    card->raw[2] = gender;
}

void sub_020692C4(u32 id, u8 gender, const u16 *name, u32 money, u32 owned, u32 dex, u32 score, TrainerCardBuffer *card) {
    *(u16 *)&card->raw[0x28] = id;
    card->raw[4] = (card->raw[4] & ~4) | ((gender & 1) << 2);
    CopyU16StringArrayN((u16 *)&card->raw[8], name, 8);
    *(u32 *)&card->raw[0x1c] = money;
    *(u32 *)&card->raw[0x20] = owned;
    card->raw[4] = (card->raw[4] & ~8) | ((((u8)dex) & 1) << 3);
    *(u32 *)&card->raw[0x24] = score;
}

void sub_02069308(BOOL clear, void *igt, const u32 *current, const u32 *clearTime, const u32 *clearDate, u8 flag, TrainerCardBuffer *card) {
    u32 dateTail;
    *(u16 *)&card->raw[0x2a] = GetIGTHours(igt);
    card->raw[0x2e] = GetIGTMinutes(igt);
    card->raw[0x2f] = current[0];
    card->raw[0x30] = current[1];
    card->raw[0x31] = current[2];
    if (clear) {
        card->raw[0x32] = clearTime[0];
        card->raw[0x33] = clearTime[1];
        card->raw[0x34] = clearTime[2];
        *(u16 *)&card->raw[0x2c] = clearDate[0];
        dateTail = clearDate[1];
    } else {
        card->raw[0x32] = 0;
        card->raw[0x33] = 0;
        card->raw[0x34] = 0;
        *(u16 *)&card->raw[0x2c] = 0;
        dateTail = 0;
    }
    card->raw[0x35] = dateTail;
    card->raw[4] = (card->raw[4] & ~2) | ((flag & 1) << 1);
    if (flag) {
        *(void **)&card->raw[0x18] = igt;
    } else {
        *(u32 *)&card->raw[0x18] = 0;
    }
}

void sub_020693AC(u32 a, u32 b, u32 c, u32 d, u8 flag, const void *signature, TrainerCardBuffer *card) {
    *(u32 *)&card->raw[0x38] = a;
    if (a > 999999) {
        *(u32 *)&card->raw[0x38] = 999999;
    }
    *(u32 *)&card->raw[0x3c] = b;
    *(u32 *)&card->raw[0x40] = c;
    if (*(u32 *)&card->raw[0x3c] > 9999) {
        *(u32 *)&card->raw[0x3c] = 9999;
    }
    if (*(u32 *)&card->raw[0x40] > 9999) {
        *(u32 *)&card->raw[0x40] = 9999;
    }
    *(u32 *)&card->raw[0x44] = d;
    if (d > 99999) {
        *(u32 *)&card->raw[0x44] = 99999;
    }
    card->raw[4] = (card->raw[4] & ~0x10) | ((flag & 1) << 4);
    MI_CpuCopy8(signature, &card->raw[0x68], 0x600);
}

void sub_0206940C(void *profile, void *fieldSystem, TrainerCardBuffer *card) {
    u32 *words;
    u8 i;
    u16 mask;
    u8 j;
    TrainerCard_GetBadgeShininessArr(Save_TrainerCard_Get(*(void **)((u8 *)fieldSystem + 0xc)));
    i = 0;
    words = (u32 *)&card->raw[0x48];
    for (; i < 8; i++) {
        words[i] &= ~1;
        words[i] &= 1;
    }
    mask = 1;
    for (j = 0; j < 16; j++) {
        if (PlayerProfile_TestBadgeFlag(profile, j)) {
            *(u16 *)&card->raw[6] |= mask;
        }
        mask <<= 1;
    }
}

void sub_02069464(void *fieldSystem) {
    TrainerCardTaskEnv *env = Heap_AllocAtEnd(11, sizeof(TrainerCardTaskEnv));
    env->state = 0;
    env->source = sub_0205ABD8(*(void **)((u8 *)fieldSystem + 0x80));
    TaskManager_Call(*(void **)((u8 *)fieldSystem + 0x10), sub_02069498, env);
}

BOOL sub_02069498(void *taskman) {
    void *fieldSystem = TaskManager_GetFieldSystem(taskman);
    TrainerCardTaskEnv *env = TaskManager_GetEnvironment(taskman);
    switch (env->state) {
    case 0:
        sub_0205AC70(*(void **)((u8 *)fieldSystem + 0x80));
        env->state = 1;
    case 1:
        if (*(u16 *)((u8 *)env->source + 0x66a) != 0) {
            env->state = 10;
        }
        break;
    case 10:
        MI_CpuCopy8(env->source, &env->copy, 0x66c);
        TrainerCard_LaunchApp(fieldSystem, &env->copy);
        env->state = 11;
        break;
    case 11:
        if (!FieldSystem_ApplicationIsRunning(fieldSystem)) {
            sub_0205AC4C(*(void **)((u8 *)fieldSystem + 0x80));
            Heap_Free(env);
            return TRUE;
        }
        break;
    }
    return FALSE;
}
