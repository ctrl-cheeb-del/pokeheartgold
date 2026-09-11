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

void ov96_021E75BC(void*x){volatile u32*base=(volatile u32*)0x027E0000;OamManager_ApplyAndResetBuffers();DoScheduledBgGpuUpdates(x);GF_RunVramTransferTasks();base[0x3ff8/4]=base[0x3ff8/4]|1;}
