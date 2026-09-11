#include "overlay49_menu_helpers_private.h"

int ov49_0225AC5C(Ov49R20 *w){if(TextPrinterCheckActive((u8)w->printer)==0)return 1;return 0;}

void ov49_0225AC74(Ov49R20 *w){if(TextPrinterCheckActive((u8)w->printer))RemoveTextPrinter((u8)w->printer);ov49_0225AC38(w);ClearFrameAndWindow2(w,1);ClearWindowTilemapAndScheduleTransfer(w);}

void ov49_0225ACA8(void *w){ov49_0225AAC8(w);SetWindowPaletteNum(w,2);}

void ov49_0225ACBC(void){ov49_0225AB14();}

void ov49_0225ACC4(Ov49R20 *w,void *s){if(TextPrinterCheckActive((u8)w->printer))RemoveTextPrinter((u8)w->printer);FillWindowPixelBuffer(w,15);String_Copy(w->str,s);w->printer=AddTextPrinterParameterized(w,1,w->str,0,0,w->speed,0);DrawFrameAndWindow3(w,1,31,2,3);}
