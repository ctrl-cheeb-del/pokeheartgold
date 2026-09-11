#ifndef TO40_OVERLAY_95_RESIDUAL_2_PRIVATE_H
#define TO40_OVERLAY_95_RESIDUAL_2_PRIVATE_H
#include "global.h"
extern void LoadUserFrameGfx2(void *, int, int, int, int, int);
extern void LoadUserFrameGfx1(void *, int, int, int, int, int);
extern int sub_0200E640(int);
extern int sub_0200E3D8(void);
extern void PaletteData_LoadNarc(void *, int, int, int, int, int, int);
extern void InitWindow(void *);
extern void AddWindowParameterized(void *, void *, int, int, int, int, int, int, int);
extern void DrawFrameAndWindow2(void *, int, int, int);
extern void FillWindowPixelBuffer(void *, int);
extern void CopyWindowToVram(void *);
extern void *NewMsgDataFromNarc(int, int, int, int);
extern void *MessageFormat_New(int);
extern void *NewString_ReadMsgData(void *, int);
extern void *String_New(int, int);
extern void *Mon_GetBoxMon(void *);
extern void BufferBoxMonSpeciesName(void *, int, void *);
extern void StringExpandPlaceholders(void *, void *, void *);
extern int AddTextPrinterParameterized(void *, int, void *, int, int, int, void *);
extern void DestroyMsgData(void *);
extern void String_Delete(void *);
extern void MessageFormat_Delete(void *);
void ov95_021E5BBC(void *, void *, int);
void ov95_021E5C44(void *, void *, int, int, int, int, int, int, int);
int ov95_021E5CAC(void *, int, void *, int);
#endif
