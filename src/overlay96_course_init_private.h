#ifndef OV96_R3_PRIVATE_H
#define OV96_R3_PRIVATE_H
#include "global.h"
#include "sprite.h"
#include "sys_task_api.h"
#include "pokeathlon/pokeathlon.h"
#include "filesystem.h"
#include "follow_mon.h"
#include "unk_02005D10.h"
typedef struct Ov96DEntry { u32 active; u32 a; Sprite *sprite; SysTask *task; } Ov96DEntry;
typedef struct Ov96Work { u8 pad000[0x71C]; Sprite *sprites[3]; u8 spriteCount; u8 pad729[0x607]; u32 dCount; Ov96DEntry d[3]; } Ov96Work;
typedef struct Ov96ParticipantView { u16 species; u16 field2; u16 special; u8 kind; u8 field7; u32 participant; u32 fieldC; } Ov96ParticipantView;
typedef struct Ov96Mini { u8 pad[6]; u8 type6; u8 pad7; u8 type8; } Ov96Mini;
extern void GF_AssertFail(void);
extern Sprite *ov96_021EA7A4(void *,int,void *,void *);
extern void ov96_021E81D8(SysTask *,void *);
extern void *ov96_021EB5E8(void *);
extern void ov96_021E62AC(void *,int,int,void *,u32,u8,u32);
extern void *ov96_021E61D8(void *,int,int,void *);
void ov96_021E6168(PokeathlonCourseData *,int,int,Ov96ParticipantView *);
int ov96_021E6108(const Ov96Mini *);
int ov96_021E6138(const Ov96Mini *);
void ov96_021E634C(void *,int,int,void *,u32,u8,u32);
void *ov96_021E6290(void *,int,int,void *);
Sprite *ov96_021E64F8(u8 *,int,void *,int,void *);
void ov96_021E6454(u8 *,int);
void ov96_021E64B8(Ov96Work *);
void ov96_021E6550(Ov96Work *);
void ov96_021E658C(Ov96Work *,int,int);
void ov96_021E65A4(Ov96Work *);
void ov96_021E65D8(Ov96Work *);
BOOL ov96_021E661C(u8 *);
#endif
