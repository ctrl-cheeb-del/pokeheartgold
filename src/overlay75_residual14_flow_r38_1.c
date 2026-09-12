#include "global.h"

typedef struct {
    void *work;
    u32 unk04;
    u32 next;
    u32 returnState;
    s32 value;
    s32 amount;
    u32 unk18;
    u32 unk1C;
    void *format;
    u8 unk24[0x10];
    void *msgData;
    u8 unk38[0xC];
    u32 printer;
    u8 unk48[0x20];
    u8 window[0x2C];
    u32 state;
    u32 timer;
} Ov75Task;

extern u8 gSystem[];

extern int ov75_02249534(u32 printer);
extern void ov75_022494CC(Ov75Task *task, void *msgData, u32 msgId, u32 speed, u32 fill);
extern void *ov75_02247890(void *work, u32 msgId, u32 mode);
extern void ov75_02247854(Ov75Task *task, u32 next, u32 arg);
extern void ov75_0224785C(Ov75Task *task);
extern void ov75_02246BCC(void *work, u32 a, u32 b);
extern void ov75_02246BE0(void *work, u32 state);
extern void ov75_02246C3C(void *work);
extern void ov75_02246C68(void *work);
extern void ov75_02246C8C(void *work);
extern int YesNoPrompt_HandleInput(void *prompt);
extern void YesNoPrompt_Destroy(void *prompt);
extern s32 ov00_021E6A70(s32, u32);
extern void ov75_0224971C(Ov75Task *task, s32, s32);
extern void sub_0200E5D4(void *window, u32 fill);
extern int SaveGameNormal(void *saveData);
extern void *Save_PlayerData_GetProfile(void *saveData);
extern void BufferPlayersName(void *format, u32 idx, void *profile);
extern void PlaySE(u32 seqNo);
extern void Save_ClearStatusFlags(void *saveData);
extern void ov75_02247878(Ov75Task *task);
extern void ov00_021EC8D8(void);
extern void sub_0203A914(void);
extern void sub_0203957C(void);
extern void Sys_ClearSleepDisableFlag(u32 flag);
extern void ov70_02237F2C(void);

int ov75_02248C84(Ov75Task *task);
int ov75_02248F18(Ov75Task *task);
int ov75_02248F7C(Ov75Task *task);
int ov75_02248FE8(Ov75Task *task);
int ov75_022490D8(Ov75Task *task);
int ov75_022491CC(Ov75Task *task);
int ov75_022491F0(Ov75Task *task);

int ov75_02248C84(Ov75Task *task) {
    int result;

    if (ov75_02249534(task->printer) == 1) {
        return 0;
    }

    switch (task->state) {
    case 0:
        ov75_022494CC(task, task->msgData, 14, 1, 0xF0F);
        task->state++;
        break;
    case 1:
        *(void **)((u8 *)task + 0x88) = ov75_02247890(*(void **)((u8 *)task + 4), 0x234, 0);
        task->state++;
        break;
    case 2:
        result = YesNoPrompt_HandleInput(*(void **)((u8 *)task + 0x88));
        if (result == 1) {
            YesNoPrompt_Destroy(*(void **)((u8 *)task + 0x88));
            ov75_02247854(task, 0x1A, 0);
        } else if (result == 2) {
            YesNoPrompt_Destroy(*(void **)((u8 *)task + 0x88));
            task->next = 0x13;
        }
        break;
    }
    return 0;
}
