#ifndef UNK_02088D48_PRIVATE_H
#define UNK_02088D48_PRIVATE_H

#include "global.h"

#include "system.h"

typedef struct SummaryMenuObject {
    u8 pad00[0x12];
    u8 mode;
    u8 pad13[3];
    u8 cursor;
    u8 flag;
    u16 value;
} SummaryMenuObject;

typedef struct SummaryMoveWork {
    u8 pad000[0x22C];
    SummaryMenuObject *menu;
    u8 pad230[0x34];
    u16 moves[5];
    u8 pad26E[0x1BA];
    void *sprite428;
    void *sprite42C;
    u8 pad430[0x1C];
    void *sprite44C;
    u8 pad450[0x36D];
    u8 selectionLow : 4;
    u8 selectionHigh : 4;
} SummaryMoveWork;

extern BOOL sub_0208A71C(void *, int);
extern void PlaySE(u32);
extern void sub_0208A79C(void *);
extern int sub_0208B08C(void *, u8);
extern void sub_0208AFA0(void *, int);
extern int sub_0208B044(void *, u8);
extern int sub_0208AE08(void *);
extern void sub_0208BC78(void *);
extern void Sprite_SetDrawFlag(void *, BOOL);
extern void sub_0208A834(void *);
extern void sub_0208BB24(void *, u8, u8);
extern void sub_0208DB64(void *);
extern int sub_0208ADDC(void);
extern BOOL MoveIsHM(u16);
extern int sub_0208AED4(void *);
extern void thunk_Sprite_SetDrawFlag(void *, BOOL);
extern void sub_0208DBF0(void *);
extern int sub_0208AE48(void);
extern void sub_0208BBDC(void *);
extern int sub_0208B068(void *, u8);
extern void Sprite_SetAnimCtrlSeq(void *, int);
extern void sub_0208AF08(void *, int);
extern int sub_0208AE88(void);

int sub_02088D48(SummaryMoveWork *);
int sub_02088E68(SummaryMoveWork *);
int sub_02088E98(SummaryMoveWork *);
int sub_02089028(SummaryMoveWork *);
int sub_02089208(SummaryMoveWork *);

#endif
