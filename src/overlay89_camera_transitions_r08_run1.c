#include "global.h"

typedef struct Ov89Pulse {
    u8 state;
    u8 count;
    s16 value;
} Ov89Pulse;

typedef struct Ov89DistanceMove {
    int distance;
    s16 timer;
    u8 state;
} Ov89DistanceMove;

typedef struct Ov89CameraUpMove {
    int x;
    int y;
    u32 padding;
    u8 state;
    u8 phase;
    u8 count;
} Ov89CameraUpMove;

typedef struct Ov89AngleMove {
    u16 angle[4];
    int current;
    s16 timer;
    u8 padding;
    u8 state;
} Ov89AngleMove;

extern int Camera_GetDistance(void *camera);
extern void Camera_AdjustDistance(int amount, void *camera);
extern void Camera_SetDistance(int distance, void *camera);
extern void PlaySE(int se);
extern void Camera_SetLookAtCamUp(void *value, void *camera);
extern void Camera_GetAngle(void *value, void *camera);
extern void Camera_AdjustAnglePos(void *value, void *camera);
extern void Camera_SetAnglePos(void *value, void *camera);

int ov89_0225BE84(u8 *work, Ov89Pulse *pulse, int arg2, int direction);
int ov89_0225BF34(void *unused, Ov89DistanceMove *move, void *camera);
int ov89_0225BFE4(void *unused, u8 *work, void *camera);
int ov89_0225C090(void *unused, u8 *work, void *camera);
int ov89_0225C3E8(void *unused, u8 *work, void *camera);

int ov89_0225BE84(u8 *work, Ov89Pulse *pulse, int arg2, int direction) {
    int multiplier;

    if (arg2 == 3) {
        return 0;
    }
    multiplier = direction == 0 ? -1 : 1;
    switch (pulse->state) {
    case 0:
        pulse->value += 0x200;
        if (pulse->value >= 0x800) {
            pulse->value = 0x800;
            pulse->state++;
        }
        work[0x740] = 1;
        *(s16 *)(work + 0x742) = (pulse->value >> 8) * multiplier;
        break;
    case 1:
        pulse->value -= 0x200;
        if (pulse->value <= 0) {
            pulse->value = 0;
            pulse->count++;
            if (pulse->count < 2) {
                pulse->state = 0;
            } else {
                pulse->state++;
            }
        }
        work[0x740] = 1;
        *(s16 *)(work + 0x742) = (pulse->value >> 8) * multiplier;
        break;
    default:
        work[0x73e] = 1;
        return 1;
    }
    return 0;
}

int ov89_0225BF34(void *unused, Ov89DistanceMove *move, void *camera) {
    switch (move->state) {
    case 0:
        move->distance = Camera_GetDistance(camera);
        move->state++;
        PlaySE(0x5d5);
    case 1:
        Camera_AdjustDistance(-0x1aaa, camera);
        move->timer++;
        if (move->timer >= 30) {
            move->timer = 0;
            move->state++;
        }
        break;
    case 2:
        move->timer++;
        if (move->timer > 4) {
            move->timer = 0;
            move->state++;
        }
        break;
    case 3:
        Camera_AdjustDistance(0x8555, camera);
        move->timer++;
        if (move->timer >= 6 || Camera_GetDistance(camera) >= move->distance) {
            Camera_SetDistance(move->distance, camera);
            return 1;
        }
        break;
    }
    return 0;
}

int ov89_0225BFE4(void *unused, u8 *work, void *camera) {
    Ov89CameraUpMove *move = (Ov89CameraUpMove *)(work + 8);
    int angle;

    switch (move->state) {
    case 0:
        PlaySE(0x5d5);
        move->state++;
    case 1:
        move->phase++;
        angle = move->phase << 10;
        if (angle < 0x2000) {
            move->y = 0x1000 - angle;
        } else {
            move->y = angle - 0x3000;
        }
        if (angle < 0x1000) {
            move->x = angle;
        } else if (angle < 0x2000) {
            move->x = 0x2000 - angle;
        } else if (angle < 0x3000) {
            move->x = -(angle - 0x2000);
        } else {
            move->x = angle - 0x4000;
        }
        if (move->phase >= 16) {
            move->y = 0x1000;
            move->x = 0;
            move->phase = 0;
            move->count++;
            if (move->count >= 2) {
                move->state++;
            }
        }
        Camera_SetLookAtCamUp(move, camera);
        break;
    default:
        return 1;
    }
    return 0;
}
