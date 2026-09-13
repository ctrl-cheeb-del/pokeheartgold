#ifndef OV41_RESIDUAL24_PRIVATE_H
#define OV41_RESIDUAL24_PRIVATE_H
#include "global.h"

#include "brightness.h"
#include "heap.h"
#include "sys_task_api.h"
#include "systask_environment.h"
#include "yes_no_prompt.h"

/* Placeholder work struct: word-indexed. Codegen-identical to a named-field
   struct for the word-sized accesses this module makes. */
typedef struct Ov41Work {
    u32 f[512];
} Ov41Work;
#define W(w, off)  ((w)->f[(off) / 4])
#define AT(w, off) ((void *)((u8 *)(w) + (off)))

typedef struct Ov41TransitionTask {
    Ov41Work *work;
    u32 *pDone;
    int counter;
    int state;
} Ov41TransitionTask;

typedef struct Ov41ListNode {
    void *data;
    u32 flag;
    struct Ov41ListNode *next;
} Ov41ListNode;

/* --- untracked externals: prototypes only (mwcc emits bl + relocation) --- */
void GF_AssertFail(void);
void *SysTask_GetData(SysTask *task);

void *PlayerProfile_GetPlayerName_NewString(void *profile, enum HeapID heapId);
u8 PlayerProfile_GetTrainerGender(void *profile);
void String_Delete(void *string);

void sub_0202BC38(void *entry);
void sub_0202BC60(void *entry);
void sub_0202BC88(void *entry, void *mon, void *value);
void sub_0202BCAC(void *entry, void *source, int index);
void sub_0202BD60(void *entry, u8 value);
void sub_0202BDC8(void *entry, void *string, u8 value);

/* --- in-module callees not transcribed in this candidate --- */
void ov41_02247414(Ov41Work *w);
void ov41_02247480(Ov41Work *w, int a);
void ov41_02247588(Ov41Work *w);
void ov41_02247B5C(Ov41Work *w);
void ov41_02247D1C(Ov41Work *w, int b);
BOOL ov41_02248750(void *p, int a, int b);
BOOL ov41_02248998(void *p);
void ov41_022480F8(void *p, int a, int b);
void ov41_0224A5A4(void *p, int a, int b);

#endif
