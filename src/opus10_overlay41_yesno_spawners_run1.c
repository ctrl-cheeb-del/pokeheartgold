#include "opus10_overlay41_yesno_spawners_private.h"

/* ---- prototypes, source order ---- */
void ov41_022476B8(Ov41Work *work, u32 *pDone);
void ov41_022476E0(SysTask *task, Ov41TransitionTask *env);
void ov41_02247828(Ov41Work *work, u32 *pDone);
void ov41_02247850(SysTask *task, Ov41TransitionTask *env);
void ov41_022479A8(void *dst, Ov41Work *w, void *profile);
BOOL ov41_02247A48(Ov41TransitionTask *env, int x, int y, int limit);
void ov41_02247AB4(Ov41Work *w);

/* ---- bodies ---- */

void ov41_022476B8(Ov41Work *work, u32 *pDone) {
    Ov41TransitionTask *env = SysTask_GetData(CreateSysTaskAndEnvironment((SysTaskFunc)ov41_022476E0, sizeof(Ov41TransitionTask), 10, HEAP_ID_13));
    env->work = work;
    env->pDone = pDone;
    env->counter = 0;
    env->state = 0;
}

void ov41_022476E0(SysTask *task, Ov41TransitionTask *env) {
    switch (env->state) {
    case 0:
        if (!ov41_02248750(AT(env->work, 0x368), 3, 0)) {
            GF_AssertFail();
        }
        env->state++;
        break;
    case 1:
        if (ov41_02248998(AT(env->work, 0x368))) {
            env->state++;
        }
        break;
    case 2:
        StartBrightnessTransition(8, -16, 0, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3), SCREEN_MASK_MAIN);
        env->state++;
        break;
    case 3:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
            env->state++;
        }
        break;
    case 4:
        ov41_0224A5A4(AT(env->work, 0x4e0), 0, 8);
        env->counter++;
        if (env->counter >= 8) {
            env->counter = 0;
            env->state++;
        }
        break;
    case 5:
        if (ov41_02247A48(env, -8, 5, 8)) {
            env->counter = 0;
            env->state++;
        }
        break;
    case 6:
        ov41_02247480(env->work, 1);
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 1, BG_POS_OP_SET_Y, 0);
        ov41_02247AB4(env->work);
        env->state++;
        break;
    case 7:
        StartBrightnessTransition(8, 0, -16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3), SCREEN_MASK_MAIN);
        env->state++;
        break;
    case 8:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
            env->state++;
        }
        break;
    case 9:
        *env->pDone = 1;
        DestroySysTaskAndEnvironment(task);
        break;
    }
}

void ov41_02247828(Ov41Work *work, u32 *pDone) {
    Ov41TransitionTask *env = SysTask_GetData(CreateSysTaskAndEnvironment((SysTaskFunc)ov41_02247850, sizeof(Ov41TransitionTask), 10, HEAP_ID_13));
    env->work = work;
    env->pDone = pDone;
    env->counter = 0;
    env->state = 0;
}

void ov41_02247850(SysTask *task, Ov41TransitionTask *env) {
    switch (env->state) {
    case 0:
        StartBrightnessTransition(8, -16, 0, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3), SCREEN_MASK_MAIN);
        env->state++;
        break;
    case 1:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
            env->state++;
        }
        break;
    case 2:
        ov41_02247B5C(env->work);
        ov41_02247414(env->work);
        ov41_02247588(env->work);
        ov41_02247480(env->work, 0);
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 1, BG_POS_OP_SET_Y, -40);
        env->state++;
        break;
    case 3:
        if (ov41_02247A48(env, 8, -5, 8)) {
            env->counter = 0;
            env->state++;
        }
        break;
    case 4:
        ov41_0224A5A4(AT(env->work, 0x4e0), 0, -8);
        env->counter++;
        if (env->counter >= 8) {
            env->counter = 0;
            env->state++;
        }
        break;
    case 5:
        StartBrightnessTransition(8, 0, -16, (GXBlendPlaneMask)(GX_BLEND_PLANEMASK_BG1 | GX_BLEND_PLANEMASK_BG3), SCREEN_MASK_MAIN);
        env->state++;
        break;
    case 6:
        if (IsBrightnessTransitionActive(SCREEN_MASK_MAIN)) {
            env->state++;
        }
        break;
    case 7:
        if (!ov41_02248750(AT(env->work, 0x368), 0, 0)) {
            GF_AssertFail();
        }
        env->state++;
        break;
    case 8:
        if (ov41_02248998(AT(env->work, 0x368))) {
            env->state++;
        }
        break;
    case 9:
        *env->pDone = 1;
        DestroySysTaskAndEnvironment(task);
        break;
    }
}

void ov41_022479A8(void *dst, Ov41Work *w, void *profile) {
    Ov41ListNode *list;
    Ov41ListNode *node;
    int count;

    sub_0202BC60(dst);
    sub_0202BC88(dst, (void *)W(w, 0x84), AT(w, 0x78));
    if (profile != NULL) {
        void *name = PlayerProfile_GetPlayerName_NewString(profile, HEAP_ID_13);
        sub_0202BDC8(dst, name, PlayerProfile_GetTrainerGender(profile));
        String_Delete(name);
    }
    count = 0;
    node = (Ov41ListNode *)W(w, 0x1c);
    list = (Ov41ListNode *)AT(w, 0x14);
    for (; node != list; node = node->next) {
        if (node->flag == 0) {
            sub_0202BCAC(dst, node->data, count);
            count++;
        }
    }
    list = (Ov41ListNode *)AT(w, 4);
    for (node = (Ov41ListNode *)W(w, 0xc); node != list; node = node->next) {
        if (node->flag == 0) {
            sub_0202BCAC(dst, node->data, count);
            count++;
        }
    }
    sub_0202BD60(dst, (u8)W(w, 0x74));
    sub_0202BC38(dst);
}

BOOL ov41_02247A48(Ov41TransitionTask *env, int x, int y, int limit) {
    if (env->counter < 8) {
        ov41_022480F8(AT(env->work, 0x3f4), x, y);
    }
    if (env->counter >= 1) {
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 2, BG_POS_OP_SUB_X, x);
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 1, BG_POS_OP_SUB_X, x);
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 2, BG_POS_OP_SUB_Y, y);
        ScheduleSetBgPosText((BgConfig *)W(env->work, 0x40), 1, BG_POS_OP_SUB_Y, y);
    }
    env->counter++;
    if (env->counter > limit) {
        return TRUE;
    }
    return FALSE;
}

void ov41_02247AB4(Ov41Work *w) {
    YesNoPromptTemplate tmpl;

    BgClearTilemapBufferAndCommit((BgConfig *)W(w, 0x40), 3);
    BgSetPosTextAndCommit((BgConfig *)W(w, 0x40), 3, BG_POS_OP_SET_X, 0);
    BgSetPosTextAndCommit((BgConfig *)W(w, 0x40), 3, BG_POS_OP_SET_Y, 0);
    MI_CpuFill8(&tmpl, 0, sizeof(YesNoPromptTemplate));
    tmpl.bgConfig = (BgConfig *)W(w, 0x40);
    tmpl.bgId = 3;
    tmpl.tileStart = 0;
    tmpl.plttSlot = 5;
    tmpl.x = 25;
    tmpl.y = 4;
    tmpl.ignoreTouchFlag = (u8)W(w, 0x6ec);
    YesNoPrompt_InitFromTemplate((YesNoPrompt *)W(w, 0x6b8), &tmpl);
    ov41_02247D1C(w, 1);
    G2_SetBG0Priority(2);
    G2_SetBG1Priority(1);
    G2_SetBG2Priority(3);
    G2_SetBG3Priority(0);
}
