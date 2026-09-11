#ifndef LOCAL_OV88_R7_H
#define LOCAL_OV88_R7_H
#include "global.h"
typedef struct Ov88Small {
    s16 frame;
    u16 state;
} Ov88Small;
extern int ov45_0222DD38(void *);
extern void ov88_0225918C(void *, void *, void *, void *, int);
extern int ov45_0222DDE4(void *, void *, int);
extern int ov45_0222AB28(void *, int);
extern int GF_CreateNewVramTransferTask(int, void *, void *, int);
extern void GF_AssertFail(void);
extern void Heap_Free(void *);
extern void String_Delete(void *);
extern void RemoveWindow(void *);
extern void ov88_0225954C(void *);
extern void ov88_022595F8(void *, void *);
extern void *String_New(int, int);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
void ov88_02259104(Ov88Small *, void *, void *, void *, void *);
int ov88_022590D8(Ov88Small *, void *);
void ov88_02259244(void *, void *, void *, void *, u32);
void ov88_02259264(void *, void *, void *, void *, u32);
void ov88_02259280(u8 *, void *, void *, void *);
void ov88_022592B8(const u8 *, void *, int);
void ov88_022593D0(void *);
void ov88_022594E0(void *);
void ov88_02259508(void *, void *, int, int);
#endif
