#ifndef POKEHEARTGOLD_WIRELESS_SCAN_PARAM_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_SCAN_PARAM_INTERNAL_H
#include "wireless_internal.h"

typedef void (*WMCallback)(void *);

void sub_02032844(int);
void sub_02032858(int);
void sub_02039AD8(int);
BOOL sub_02032E48(void);
u16 WM_GetAllowedChannel(void);
u16 WM_GetDispersionScanPeriod(void);
int WM_StartScan(WMCallback, void *);
void DC_InvalidateRange(void *, u32);

BOOL sub_02032B84(void *a0, const u16 *mac, u16 channel);
BOOL sub_02032C1C(void *a0, const u16 *mac, u16 channel);
BOOL sub_02032C84(void);
void sub_02032D4C(void *cb);

BOOL sub_02032B84(void *a0, const u16 *mac, u16 channel);
BOOL sub_02032C1C(void *a0, const u16 *mac, u16 channel);
BOOL sub_02032C84(void);
void sub_02032D4C(void *cb);

#endif
