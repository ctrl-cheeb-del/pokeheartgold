#ifndef UNK_02089D68_PRIVATE_H
#define UNK_02089D68_PRIVATE_H
#include "global.h"
typedef struct SummaryState89 {
    void *bgConfig;
    u8 data[0x7B8];
} SummaryState89;
void sub_0208C4E0(SummaryState89 *);
void sub_0208B448(SummaryState89 *);
void sub_0208B5A8(SummaryState89 *);
void sub_0208B89C(SummaryState89 *);
void sub_0208B9C8(SummaryState89 *);
void sub_0208C2A0(SummaryState89 *);
void sub_0208BCD4(SummaryState89 *);
void sub_0208C42C(SummaryState89 *);
void sub_0208CBD4(SummaryState89 *);
void sub_02089F98(SummaryState89 *);
void sub_0208A950(SummaryState89 *);
void FillBgTilemapRect(void *, int, int, int, int, int, int, int);
void BgCommitTilemapBufferToVram(void *, int);
void PlaySE(int);
void sub_02089D68(SummaryState89 *, int);
void sub_02089E14(SummaryState89 *, int);
void sub_02089E30(SummaryState89 *, int);
#endif
