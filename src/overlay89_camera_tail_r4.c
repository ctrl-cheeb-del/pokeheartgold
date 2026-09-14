#include "global.h"

#include "overlay89_camera_tail_r4_private.h"

typedef struct Ov89LookAtMove {
    VecFx32 target;
    VecFx32 position;
    fx32 phase;
    u8 count;
    u8 state;
} Ov89LookAtMove;

typedef struct Ov89AngleMove {
    CameraAngle angle;
    s32 current;
    s16 timer;
    u8 state;
} Ov89AngleMove;

int ov89_0225C498(void *unused, u8 *work, Camera *camera) {
    Ov89LookAtMove *move = (Ov89LookAtMove *)(work + 0x60);
    VecFx32 offset = { 0, 0, 0 };
    VecFx32 position;
    VecFx32 target;

    switch (move->state) {
    case 0:
        position = Camera_GetLookAtCamPos(camera);
        move->position = position;
        target = Camera_GetLookAtCamTarget(camera);
        move->target = target;
        move->state++;
        PlaySE(0x5D5);
    case 1:
        move->phase += 0x20000;
        if (move->phase >= 0x168000) {
            move->phase -= 0x168000;
            move->count++;
            if (move->count >= 4) {
                move->state++;
                move->phase = 0;
            }
        }
        offset.x = FX_Mul(GF_SinDegFX32(move->phase), 0x10000);
        Camera_SetLookAtCamTarget(&move->target, camera);
        Camera_SetLookAtCamPos(&move->position, camera);
        Camera_OffsetLookAtPosAndTarget(&offset, camera);
        break;
    default:
        return 1;
    }
    return 0;
}

int ov89_0225C570(void *unused, u8 *work, Camera *camera) {
    Ov89LookAtMove *move = (Ov89LookAtMove *)(work + 0x80);
    VecFx32 offset = { 0, 0, 0 };
    VecFx32 position;
    VecFx32 target;

    switch (move->state) {
    case 0:
        position = Camera_GetLookAtCamPos(camera);
        move->position = position;
        target = Camera_GetLookAtCamTarget(camera);
        move->target = target;
        move->state++;
        PlaySE(0x5D5);
    case 1:
        move->phase += 0x20000;
        if (move->phase >= 0x168000) {
            move->phase -= 0x168000;
            move->count++;
            if (move->count >= 4) {
                move->state++;
                move->phase = 0;
            }
        }
        offset.y = FX_Mul(GF_SinDegFX32(move->phase), 0x8000);
        Camera_SetLookAtCamTarget(&move->target, camera);
        Camera_SetLookAtCamPos(&move->position, camera);
        Camera_OffsetLookAtPosAndTarget(&offset, camera);
        break;
    default:
        return 1;
    }
    return 0;
}

int ov89_0225C648(void *unused, u8 *work, Camera *camera) {
    Ov89AngleMove *move = (Ov89AngleMove *)(work + 0xA0);
    CameraAngle adjustment = { 0, 0, 0, 0 };
    CameraAngle current;

    switch (move->state) {
    case 0:
        current = Camera_GetAngle(camera);
        move->angle = current;
        move->current = move->angle.x;
        move->state++;
        PlaySE(0x5D5);
    case 1:
        adjustment.x -= 0xAAA;
        move->current -= 0xAAA;
        Camera_AdjustAnglePos(&adjustment, camera);
        if (move->current <= move->angle.x - 0x2000) {
            move->state++;
        }
        break;
    case 2:
        move->timer++;
        if (move->timer >= 0x10) {
            move->state++;
        }
        break;
    case 3:
        adjustment.x += 0x200;
        move->current += 0x200;
        Camera_AdjustAnglePos(&adjustment, camera);
        if (move->current >= move->angle.x) {
            Camera_SetAnglePos(&move->angle, camera);
            return 1;
        }
        break;
    }
    return 0;
}

void ov89_0225C724(MsgData *msgData, MessageFormat *format, Window *windows, void *context, void *network) {
    u32 index = ov45_0222EC7C(network);
    int slot;
    void *record;
    PlayerProfile *profile;
    String *template;
    String *name;
    String *expanded;
    int gender;
    u32 color;
    Window *window;

    if (index == (u32)-1) {
        return;
    }
    slot = ov45_0222EC68(network);
    if (slot == -1) {
        return;
    }
    record = ov45_0222A578(context, slot);
    if (record == NULL) {
        return;
    }
    if (index >= 8) {
        GF_AssertFail();
        return;
    }
    profile = PlayerProfile_New(HEAP_ID_125);
    ov45_0222A844(record, profile, HEAP_ID_125);
    name = PlayerProfile_GetPlayerName_NewString(profile, HEAP_ID_125);
    gender = PlayerProfile_GetTrainerGender(profile);
    BufferString(format, 0, name, gender, 1, 2);
    template = NewString_ReadMsgData(msgData, 0);
    expanded = String_New(0x40, HEAP_ID_125);
    StringExpandPlaceholders(format, expanded, template);
    window = &windows[index];
    FillWindowPixelBuffer(window, 0);
    color = ov45_0222AB28(context, slot) == 1 ? 0x70800 : 0x10200;
    AddTextPrinterParameterizedWithColor(window, 0, expanded, 0, 0, 0, color, NULL);
    CopyWindowToVram(window);
    String_Delete(name);
    String_Delete(template);
    String_Delete(expanded);
    Heap_Free(profile);
}
