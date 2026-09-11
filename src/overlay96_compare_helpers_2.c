#include "global.h"
typedef struct Work{u8 d[0xe00];}Work;
extern void OamManager_ApplyAndResetBuffers(void);
extern void DoScheduledBgGpuUpdates(void*);
extern void GF_RunVramTransferTasks(void);
extern u32 ov96_021E5F24(Work*);
extern BOOL ov96_021E7D30(int,int,u32);
extern void GF_AssertFail(void);
extern void *Save_Pokeathlon_FriendshipRecords_Get(void*);
void ov96_021E75BC(void*);void ov96_021E7C94(Work*,u16*,u16*);void ov96_021E7CC8(Work*,u8*,u8*);BOOL ov96_021E7D18(int,int,u32);BOOL ov96_021E7D30(int,int,u32);void ov96_021E7F48(Work*);

void ov96_021E7C94(Work*w,u16*dst,u16*src){int i,j;ov96_021E5F24(w);for(i=0;i<5;i++){dst[0]=src[0];for(j=0;j<3;j++)dst[j+1]=src[j+1];src+=0x10;dst+=4;}}
