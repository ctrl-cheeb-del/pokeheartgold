#ifndef SOL40_OV70_R26_PRIVATE_H
#define SOL40_OV70_R26_PRIVATE_H
#include "global.h"

#include "gf_gfx_loader.h"
#include "msgdata.h"
#include "string_util.h"
#include "text.h"
extern void *ov70_022465EC[];
extern const u32 ov70_02245910[];
extern const u16 ov70_02245B5C[];
extern const u8 ov70_022459C8[];
int ov70_0223EDE4(u8 *state, u32 value);
int ov70_0223F1B8(u8 *work);
void *ov70_0223F2A0(int index, void *result);
void ov70_0223F8A8(u8 *work, u32 value);
int ov70_0223F8D0(u32 value, u32 *first);
int ov70_0223E8E8(void *, int, int, int, int);
void ov70_02238D84(void *, int, int);
void ov70_022420C4(void *, int);
void *ov70_02238C14(void *, int, int, int, int);
int ov70_0223EEE8(u8 *);
int ov70_0223EF10(u8 *);
int ov70_0223EFB8(u8 *);
int ov70_0223EFE0(u8 *);
int ov70_0223F0B4(u8 *);
int ov70_0223F0DC(u8 *);
extern const int ov70_02245AAC[];
void ov70_0223F38C(void *, void *, int, int, int, int, int, int);
void ov70_0223F370(void *, void *, int, int, int, int, int);
void ov70_0223F634(enum HeapID, int, u32 *);
void ov70_0223F658(enum HeapID, int, u32 *);
void GF_AssertFail(void);
void ov70_0223F6E4(void *, void *);
void ov70_0223F7A4(u8 *, u8 *);
void ov70_0223F828(u8 *, int, int);
int ov70_0223F864(int, int, int);
void ov70_02245084(void *, String *, int, int, int, int);
void ov70_0223F1D8(void *, MsgData *, int, int, int, int);
void ov70_0223F20C(Window *, MsgData *, int, int, int);

typedef struct Ov70MsgEntry26 {
    u32 msgId;
    u32 unused;
} Ov70MsgEntry26;
extern const Ov70MsgEntry26 ov70_02245A4C[];
extern const Ov70MsgEntry26 ov70_022459F4[];
void Heap_Free(void *);
int ov70_0223E490(u16);
void Mon_UpdateShayminForm(void *, int);
void BoxMon_UpdateShayminForm(void *, int);
u32 SizeOfStructPokemon(void);
void CopyBoxPokemonToPokemon(void *, void *);
u8 WifiHistory_GetPlayerCountry(void *);
u8 WiFiHistory_GetPlayerRegion(void *);
u32 GetBoxMonData(void *, int, void *);
u32 CalcBoxMonLevel(void *);
void ov70_0223F2BC(void *, void *, int, int, int, int, int);
u8 *ov70_0223F684(int);
void ov70_0223F3D8(void *, void *, void *, void *, int, int, int);
void ov70_0223F470(void *, void *, void *, void *, int, int, int);
void ov70_0223F508(void *, void *, void *, void *, void *);

#endif
