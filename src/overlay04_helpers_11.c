#include "global.h"

#include "constants/sndseq.h"

typedef struct {
    u8 pad0[0x14];
    void *task;
} Ov04WorkTask;
typedef struct {
    u8 pad0[0x24];
    void *work;
} Ov04Inner;
typedef struct {
    u32 unused;
    Ov04Inner *inner;
} Ov04Context;
typedef struct {
    s32 x;
    s32 y;
    s32 z;
} Ov04Vec;
typedef struct {
    s32 x;
    s32 y;
} Ov04Pair;
typedef struct {
    u16 active;
    s16 value;
    u8 pad4[8];
} Ov04Record;
typedef struct {
    u16 unk0;
    s16 unk2;
    void *object;
    void *task;
} Ov04ObjectTask;
typedef struct {
    u16 x;
    u16 z;
} Ov04Coord;
typedef struct {
    s32 x;
    s32 z;
    u8 pad8[0xC];
} Ov04LookupEntry;

extern void SysTask_Destroy(void *task);
extern void Heap_Free(void *ptr);
extern BOOL IsSEPlaying(u32 seqNo);
extern BOOL Field3dModelAnimation_FrameAdvanceAndCheck(void *animation, s32 frames);
extern void Field3dObject_SetActiveFlag(void *object, BOOL active);
extern void Field3dObject_Draw(void *object);
extern void Field3dModelAnimation_FrameSet(void *animation, s32 frame);
extern void ov04_022570EC(void *work);
extern void *TaskManager_GetFieldSystem(void *taskManager);
extern void *TaskManager_GetEnvironment(void *taskManager);
extern int MapObject_GetID(void *mapObject);
extern const int sMortyGymTrainerObjectIds[4];
extern const Ov04LookupEntry ov04_0225766C[60];

void ov04_02254DD0(Ov04Context *context);
void ov04_02254710(Ov04Context *context);
void ov04_02254D84(Ov04Context *context);
void ov04_0225507C(Ov04Context *context);
void ov04_02256044(Ov04Context *context);
void ov04_022563B0(Ov04Context *context);
BOOL ov04_02254CA4(void);
BOOL ov04_02256E48(void *animation);
void ov04_022554C4(s32 delta, int count, Ov04Pair *pairs);
void ov04_022554E0(s32 delta, int count, Ov04Pair *pairs);
void ov04_022546C8(const Ov04Vec *vec, Ov04Pair *result);
int ov04_022546E8(BOOL increasing, int current, int delta, u16 target);
void ov04_02256B3C(Ov04ObjectTask *task);
BOOL ov04_02256920(const Ov04Record *records, s32 value);
void ov04_022558D0(int direction, Ov04Vec *vec);
BOOL ov04_02256A54(void *animations, u8 count);
void ov04_022572E0(void *animations, u8 count, s32 frame);
void ov04_02256EB0(Ov04Context *context);
void ov04_02256ED8(Ov04Context *context);
BOOL ov04_02257308(void *taskManager);
u8 ov04_MortyGymTrainerObjectToCandleIdx(void *mapObject);
s16 ov04_022568F0(s32 x, s32 z);
void ov04_02256734(void *task, Ov04Context *context);

void ov04_02256734(void *task, Ov04Context *context) {
    void *work = context->inner;
    if (ov04_02256A54((u8 *)work + 4, 4)) {
        ov04_02256B3C((Ov04ObjectTask *)context);
    } else {
        Field3dObject_Draw((u8 *)work + 0x54);
    }
}
