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

int ov89_0225C3E8(void *unused, u8 *work, void *camera) {
    Ov89DistanceMove *move = (Ov89DistanceMove *)(work + 0x58);

    switch (move->state) {
    case 0:
        move->distance = Camera_GetDistance(camera);
        move->state++;
        PlaySE(0x5d5);
    case 1:
        Camera_AdjustDistance(0x1aaa, camera);
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
        Camera_AdjustDistance(-0x8555, camera);
        move->timer++;
        if (move->timer >= 6 || Camera_GetDistance(camera) <= move->distance) {
            Camera_SetDistance(move->distance, camera);
            return 1;
        }
        break;
    }
    return 0;
}
