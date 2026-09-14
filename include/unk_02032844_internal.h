#ifndef POKEHEARTGOLD_UNK_02032844_INTERNAL_H
#define POKEHEARTGOLD_UNK_02032844_INTERNAL_H

#include "global.h"

#include "wireless_internal.h"

typedef void (*WMCallback)(void *);
extern void sub_02032844(int state);
extern void sub_02032858(int error);
extern int WM_StartMP(WMCallback callback, void *recvBuf, int recvSize, void *sendBuf, int sendSize, int mode);
extern void sub_02032AB0(void *arg);

BOOL sub_02032A40(void);

#endif
