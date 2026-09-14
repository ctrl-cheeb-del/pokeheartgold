#include "overlay96_course_collision_r89_private.h"

void ov96_02207800(Ov96R89Slots *slots) {
    slots->current = (slots->current + 1) % 20;
}

void ov96_02207818(Ov96R89Slots *slots) {
    int i;

    for (i = 0; i < 5; i++) {
        if (slots->slot[i].active == 0) {
            slots->slot[i].coordIndex = slots->current;
            slots->slot[i].x = slots->coords[slots->current].x;
            slots->slot[i].z = slots->coords[slots->current].z;
            ov96_02207800(slots);
            slots->slot[i].active = 1;
            return;
        }
    }
    GF_AssertFail();
}

void ov96_02207870(void *p) {
    int i;
    int remaining = 5 - *(u16 *)((u8 *)p + 0x61A);

    for (i = 0; i < remaining; i++) {
        ov96_02207818((Ov96R89Slots *)((u8 *)p + 0x564));
        (*(u16 *)((u8 *)p + 0x61A))++;
        if (*(u16 *)((u8 *)p + 0x61A) > 5) {
            GF_AssertFail();
        }
    }
}

BOOL ov96_022078B0(Ov96R89Slots *slots, Ov96R89Entity *entity, u8 *out) {
    int i;
    VecFx32 position;

    *out = FALSE;
    for (i = 0; i < 5; i++) {
        if (slots->slot[i].active != 0) {
            position.x = slots->coords[slots->slot[i].coordIndex].x << FX32_SHIFT;
            position.y = slots->coords[slots->slot[i].coordIndex].z << FX32_SHIFT;
            position.z = 0;
            if (ov96_02207990(&entity->position, &position, ov96_021EAF8C(entity->objects[entity->direction]) << FX32_SHIFT, 0x8000)) {
                if (entity->amount >= 9) {
                    if (entity->flags[i] == 0) {
                        *out = TRUE;
                        entity->flags[i] = TRUE;
                    }
                    return FALSE;
                }
                entity->flags[i] = TRUE;
                slots->slot[i].active = FALSE;
                entity->amount++;
                if (slots->remaining == 0) {
                    GF_AssertFail();
                }
                slots->remaining--;
                return TRUE;
            }
            entity->flags[i] = FALSE;
        } else {
            entity->flags[i] = FALSE;
        }
    }
    return FALSE;
}

BOOL ov96_02207990(const VecFx32 *a, const VecFx32 *b, fx32 radiusA, fx32 radiusB) {
    VecFx32 delta;

    VEC_Subtract(a, b, &delta);
    if (VEC_Mag(&delta) < radiusA + radiusB) {
        return TRUE;
    }
    return FALSE;
}

int ov96_022079B8(const VecFx32 *vector) {
    VecFx32 normalized;
    VecFx32 reference;
    VecFx32 rotated;
    u16 angle;
    int result = 1;

    VEC_Normalize(vector, &normalized);
    if (VEC_Mag(&normalized) != 0) {
        reference = ov96_0221CAC8;
        rotated.x = normalized.y;
        rotated.z = normalized.x;
        rotated.y = 0;
        angle = CalcAngleBetweenVecs(&reference, &rotated);
        if (angle <= 0x2000 || angle >= 0xE000) {
            result = 4;
        } else if (angle > 0x2000 && angle < 0x6000) {
            result = 2;
        } else if (angle >= 0x6000 && angle <= 0xA000) {
            result = 3;
        } else {
            result = 1;
        }
    }
    return result;
}

BOOL ov96_02207A34(void *system, Ov96R89Entity *a, Ov96R89Entity *b) {
    fx32 magA;
    fx32 magB;
    Ov96R89Entity *fast;
    fx32 scale;
    u8 direction;

    magA = VEC_Mag(&a->velocity);
    magB = VEC_Mag(&b->velocity);
    if (magA > magB) {
        fast = a;
    } else if (magA < magB) {
        fast = b;
        b = a;
    } else {
        return FALSE;
    }
    if (fast->category != b->category) {
        return FALSE;
    }
    if (ov96_022079B8(&fast->velocity) != fast->category) {
        return FALSE;
    }
    if (fast->blocked == 1) {
        return FALSE;
    }
    if (b->amount >= 2) {
        b->amount -= 2;
        fast->amount += 2;
    } else {
        fast->amount += b->amount;
        b->amount = 0;
    }
    if (fast->amount > 9) {
        fast->amount = 9;
    }
    b->blocked = 1;
    ov96_021E8228(system, (u8)b->field98, b->direction, 1, 1);
    direction = b->direction;
    b->fieldA2 = *(s32 *)((u8 *)b + direction * 20 + 0x18) + VEC_Mag(&fast->velocity) / FX32_ONE;
    {
        VecFx32 zero = { 0, 0, 0 };
        scale = (fx32)(4096.0f * *(float *)((u8 *)fast + fast->direction * 20 + 0x14));
        VEC_MultAdd(scale, &fast->velocity, &zero, &b->velocity);
        fast->velocity = zero;
    }
    fast->state = 0x12;
    b->state = 6;
    return TRUE;
}

BOOL ov96_02207B8C(Ov96R89Entity *entity) {
    BOOL inside = FALSE;

    if (entity->position.y > 0x198000 && entity->position.x >= 0xD0000 && entity->position.x <= 0x130000) {
        inside = TRUE;
    }
    if (!inside) {
        return FALSE;
    }
    if (entity->amount == 0) {
        return FALSE;
    }
    if (entity->blocked == 0) {
        return TRUE;
    }
    return FALSE;
}
