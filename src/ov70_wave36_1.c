#include "ov70_wave36_private.h"

int ov70_02239990(R14Work *w){if(U32(w,0x18)==0)BeginNormalPaletteFade(0,0,0,0,6,1,0x3d);else BeginNormalPaletteFade(3,0,0,0,6,1,0x3d);U32(w,0x2c)=0;return 4;}

int ov70_022399D8(R14Work *w){P(w,0x11c8)=ov70_02238C14(P(w,4),10,258,3,1);U32(w,0x2c)=13;Sprite_SetDrawFlag(P(w,0xdcc),0);return 3;}

int ov70_02239A10(R14Work *w){int result=ov70_02238C8C(w);if(result==1){YesNoPrompt_Destroy(P(w,0x11c8));ClearFrameAndWindow2(w+0x1158,1);ClearWindowTilemapAndCopyToVram(w+0x1158);ClearWindowTilemapAndCopyToVram(w+0x1198);ToggleBgLayer(6,0);Sprite_SetDrawFlag(P(w,0xf10),0);ov70_02238E50(w,0,0);U32(w,0x2c)=7;}else if(result==2){YesNoPrompt_Destroy(P(w,0x11c8));ClearFrameAndWindow2(w+0x1158,1);ClearWindowTilemapAndCopyToVram(w+0x1158);Sprite_SetAnimActiveFlag(P(w,0xdcc),1);U32(w,0x2c)=5;Sprite_SetDrawFlag(P(w,0xdcc),1);}return 3;}

int ov70_02239AAC(R14Work *w){if(!TextPrinterCheckActive((u8)U32(w,0xbf0)))U32(w,0x2c)=U32(w,0x30);return 3;}

int ov70_02239ACC(R14Work *w){if(!TextPrinterCheckActive((u8)U32(w,0xbf0))){S32(w,0x11c0)++;if(S32(w,0x11c0)>45){S32(w,0x11c0)=0;U32(w,0x2c)=U32(w,0x30);}}return 3;}
