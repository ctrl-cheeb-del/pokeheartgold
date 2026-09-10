#include "map_object_jump_internal.h"

BOOL MapObjectMovementCmd108_Step1(void *obj) {
    Vec3 vec;
    MoveCmd *cmd = sub_0205F3E4(obj);
    s64 duration;
    fx32 sine;
    fx32 targetY;
    float rounded;
    if (cmd->step != 0) {
        rounded = (float)(cmd->step << 12) + 0.5f;
    } else {
        rounded = (float)(cmd->step << 12) - 0.5f;
    }
    duration = (int)rounded;
    vec.x = cmd->data->origin.x + (fx32)(((s64)cmd->data->stepX * duration + 0x800) >> 12);
    vec.y = 0;
    vec.z = cmd->data->origin.z + (fx32)(((s64)cmd->data->stepZ * duration + 0x800) >> 12);
    if (sub_02061248(MapObject_GetFieldSystem(obj), &vec, MapObject_CheckFlag29(obj))) {
        cmd->savedY = vec.y;
    } else {
        vec.y = cmd->savedY;
    }
    MapObject_SetPositionVector(obj, &vec);
    sine = GF_SinDegNoWrap((u16)(cmd->data->angle * cmd->step));
    targetY = cmd->data->origin.y + (fx32)(((s64)cmd->data->stepY * duration + 0x800) >> 12);
    targetY += (fx32)(((s64)sine * 0x10000 + 0x800) >> 12);
    vec.y = targetY - vec.y;
    vec.x = 0;
    vec.z = 0;
    sub_0205F9A0(obj, &vec);
    cmd->frames--;
    cmd->step++;
    if (cmd->frames > 0) {
        return FALSE;
    }
    vec.x = vec.y = vec.z = 0;
    MapObject_SetFacingVector(obj, &vec);
    sub_0205F9A0(obj, &vec);
    MapObject_AddCurrentX(obj, cmd->data->dx);
    MapObject_AddCurrentY(obj, cmd->data->dy);
    MapObject_AddCurrentZ(obj, cmd->data->dz);
    if (cmd->data->dx << 4 > 0) {
        rounded = (float)(cmd->data->dx << 16) + 0.5f;
    } else {
        rounded = (float)(cmd->data->dx << 16) - 0.5f;
    }
    vec.x = cmd->data->origin.x + (int)rounded;
    if (cmd->data->dy << 4 > 0) {
        rounded = (float)(cmd->data->dy << 16) + 0.5f;
    } else {
        rounded = (float)(cmd->data->dy << 16) - 0.5f;
    }
    vec.y = cmd->data->origin.y + (int)rounded;
    if (cmd->data->dz << 4 > 0) {
        rounded = (float)(cmd->data->dz << 16) + 0.5f;
    } else {
        rounded = (float)(cmd->data->dz << 16) - 0.5f;
    }
    vec.z = cmd->data->origin.z + (int)rounded;
    MapObject_SetPositionVector(obj, &vec);
    sub_02061070(obj);
    MapObject_SetFlagsBits(obj, 0x20008);
    sub_02060F78(obj);
    sub_0205F484(obj);
    sub_0205F328(obj, 0);
    MapObject_IncrementMovementStep(obj);
    if (!MapObject_CheckVisible(obj)) {
        PlaySE(SEQ_SE_DP_SUTYA2);
    }
    Heap_Free(cmd->data);
    return FALSE;
}
