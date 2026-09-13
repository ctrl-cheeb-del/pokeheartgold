#ifndef R40_OV85_R15_H
#define R40_OV85_R15_H
#include "global.h"
void *PaletteData_Init(int);
void PaletteData_SetAutoTransparent(void *, int);
void PaletteData_AllocBuffers(void *, int, int, int);
void PaletteData_FreeBuffers(void *, int);
void PaletteData_Free(void *);
void ov85_021E6E14(u8 *);
void ov85_021E6E6C(u8 *);
#endif
