#ifndef TO45_OVERLAY85_R7_PRIVATE_H
#define TO45_OVERLAY85_R7_PRIVATE_H

#include "global.h"

typedef struct Ov85R7Work Ov85R7Work;

extern BOOL ov85_021E8570(Ov85R7Work *work);
extern BOOL ov85_021E8150(Ov85R7Work *work);
extern void ov85_021E8128(Ov85R7Work *work);
extern u16 ov85_021E834C(Ov85R7Work *work);
extern BOOL ov85_021E750C(Ov85R7Work *work);
extern void ov85_021E8358(Ov85R7Work *work);
extern int sub_02096D4C(void *a0, int a1, void *a2, int a3);
extern BOOL ov85_021E8144(Ov85R7Work *work);
extern void ov85_021E7644(void *a0, int a1);
extern void ov85_021E8558(Ov85R7Work *work, int a1);
extern void ov85_021E84EC(Ov85R7Work *work, int a1);
extern void *ov85_021E7958(Ov85R7Work *work);
extern BOOL sub_0203769C(void);
extern BOOL PlaySE(u16 seqNo);
extern void ov85_021E78A4(Ov85R7Work *work, int a1);
extern void ov85_021E8530(void *a0, int a1);
typedef struct Ov85R7AngleRow {
    u16 angle[5];
} Ov85R7AngleRow;
extern const Ov85R7AngleRow ov85_021EA7C4[];

int ov85_021E5FE0(Ov85R7Work *work);
int ov85_021E60F0(Ov85R7Work *work);
int ov85_021E61C8(Ov85R7Work *work);
int ov85_021E61FC(Ov85R7Work *work);
int ov85_021E6224(Ov85R7Work *work);

#endif
