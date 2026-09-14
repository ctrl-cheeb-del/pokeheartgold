#include "global.h"

typedef struct Ov85Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Ov85Vec3;

typedef struct Ov85EffectObject {
    u8 padding_00[0x10];
    s32 index;
    u8 padding_14[0x30];
    Ov85Vec3 initialPosition;
    Ov85Vec3 position;
} Ov85EffectObject;

typedef struct Ov85Particle {
    u32 active;
    u16 unk04;
    u16 unk06;
    u16 unk08;
    u16 padding_0A;
    s32 scaleX;
    s32 scaleY;
    s32 scaleZ;
    Ov85Vec3 position;
    u8 padding_24[0x54];
    Ov85EffectObject *object;
} Ov85Particle;

typedef struct Ov85MovingParticle {
    u32 active;
    Ov85Vec3 position;
    u8 padding_10[0x54];
    Ov85EffectObject *object;
} Ov85MovingParticle;

typedef struct Ov85TaskState {
    u32 active;
    u32 padding_04;
    u32 state;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} Ov85TaskState;

void sub_02069998(void *a, void *b, void *c);
void sub_020698E8(void *a, s32 b, int c);
void *Heap_AllocAtEnd(u32 heapId, u32 size);
void *SysTask_CreateOnMainQueue(void (*callback)(void *, void *), void *data, u32 priority);
void ov85_021E7B8C(void *, void *);
void ov85_021E7A54(void *unused, Ov85Particle *particle);
void ov85_021E7AC8(void *work, Ov85EffectObject *object);
void ov85_021E7B04(void *work, Ov85MovingParticle *particle);
void ov85_021E7B40(void *work, s32 a, s32 b, s32 c, s32 d, s32 e, Ov85TaskState *state);

void ov85_021E7A54(void *unused, Ov85Particle *particle) {
    s32 speed;

    particle->unk04 = 0;
    particle->unk06 = 0;
    particle->unk08 = 0;
    particle->position = particle->object->initialPosition;
    particle->position.x -= particle->object->position.x;
    particle->position.y -= particle->object->position.y;
    particle->position.z -= particle->object->position.z;
    particle->position.y += 0x2000;
    speed = particle->object->position.y;
    if (speed < 0) {
        speed = -speed;
    }
    speed /= 128;
    if (speed > 0x800) {
        speed = 0x800;
    }
    particle->scaleX = 0x1000 - speed;
    particle->scaleY = 0x1000 - speed;
    particle->scaleZ = 0x1000 - speed;
}

void ov85_021E7AC8(void *work, Ov85EffectObject *object) {
    u8 *base = (u8 *)work + 0x190;
    u8 *entry = base + 0x71c + object->index * 0x68;

    *(u32 *)entry = 1;
    *(Ov85EffectObject **)(entry + 0x64) = object;
    sub_02069998(entry + 0x10, base + 0x28 + object->index * 0x14, base + 0x8c + object->index * 0x24);
}

void ov85_021E7B04(void *work, Ov85MovingParticle *particle) {
    particle->position = particle->object->initialPosition;
    particle->position.y += 0x14000;
    sub_020698E8((u8 *)work + 0x21c + particle->object->index * 0x24, 0x1000, 1);
}

void ov85_021E7B40(void *work, s32 a, s32 b, s32 c, s32 d, s32 e, Ov85TaskState *state) {
    u8 *taskData;

    state->unk0C = a;
    state->unk10 = b;
    state->unk14 = c;
    state->unk18 = b;
    state->unk1C = d << 12;
    state->unk20 = e << 12;
    state->active = 1;
    state->state = 0;
    taskData = Heap_AllocAtEnd(0x66, 0x18);
    memset(taskData, 0, 0x18);
    *(void **)(taskData + 0x14) = work;
    *(Ov85TaskState **)(taskData + 0x10) = state;
    SysTask_CreateOnMainQueue(ov85_021E7B8C, taskData, 0);
}
