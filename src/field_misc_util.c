#include "global.h"

#include "constants/heap.h"

#include "field_system.h"
#include "heap.h"
#include "map_object.h"
#include "math_util.h"
#include "party.h"
#include "pokemon.h"
#include "task.h"
#include "unk_0205BB1C.h"

typedef struct SpinEnvironment {
    LocalMapObject *object;
    int xRadius;
    int zRadius;
    u16 turns;
    u16 angle;
    u16 step;
    u16 padding;
} SpinEnvironment;

typedef struct BlinkEnvironment {
    LocalMapObject *object;
    u16 cycles;
    u16 interval;
    u8 counter;
    u8 visible;
    u8 padding[2];
} BlinkEnvironment;

extern const u16 sRegiSpecies[3];

static BOOL sub_0205BE28(TaskManager *taskManager);
static BOOL sub_0205BF6C(TaskManager *taskManager);

u32 CountDigits(u32 value) {
    if (value / 10 == 0) {
        return 1;
    }
    if (value / 100 == 0) {
        return 2;
    }
    if (value / 1000 == 0) {
        return 3;
    }
    if (value / 10000 == 0) {
        return 4;
    }
    if (value / 100000 == 0) {
        return 5;
    }
    if (value / 1000000 == 0) {
        return 6;
    }
    if (value / 10000000 == 0) {
        return 7;
    }
    if (value / 100000000 == 0) {
        return 8;
    }
    return 1;
}

BOOL ItemIsTMOrHM(u16 item) {
    if (item >= 328 && item <= 427) {
        return TRUE;
    }
    return FALSE;
}

u16 GetOakJohtoDexRating(u16 count, u16 caughtAll, u16 *music) {
    *music = 1194;
    if (count <= 9) {
        return 28;
    }
    if (count <= 19) {
        return 29;
    }
    if (count <= 34) {
        return 30;
    }
    if (count <= 49) {
        return 31;
    }
    if (count <= 64) {
        return 32;
    }
    if (count <= 79) {
        return 33;
    }
    if (count <= 94) {
        return 34;
    }
    if (count <= 109) {
        return 35;
    }
    if (count <= 124) {
        return 36;
    }
    if (count <= 139) {
        return 37;
    }
    if (count <= 154) {
        return 38;
    }
    if (count <= 169) {
        return 39;
    }
    if (count <= 184) {
        return 40;
    }
    if (count <= 199) {
        return 41;
    }
    if (count <= 214) {
        return 42;
    }
    if (count <= 229) {
        return 43;
    }
    if (count <= 244) {
        return 44;
    }
    if (count <= 253) {
        return 45;
    }
    *music = 1199;
    if (caughtAll) {
        return 23;
    }
    return 22;
}

u16 GetOakNationalDexRating(u16 count, u16 caughtAll, u16 *music) {
    *music = 1194;
    if (count <= 100) {
        return 46;
    }
    if (count <= 150) {
        return 47;
    }
    if (count <= 200) {
        return 48;
    }
    if (count <= 250) {
        return 49;
    }
    if (count <= 300) {
        return 50;
    }
    if (count <= 350) {
        return 51;
    }
    if (count <= 400) {
        return 52;
    }
    if (count <= 435) {
        return 53;
    }
    if (count <= 465) {
        return 54;
    }
    if (count <= 475) {
        return 55;
    }
    if (count <= 483) {
        return 56;
    }
    *music = 1199;
    if (caughtAll) {
        return 25;
    }
    return 24;
}

u16 Save_GetPartyLead(SaveData *saveData) {
    u16 i;
    u16 count = Party_GetCount(SaveArray_Party_Get(saveData));

    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(SaveArray_Party_Get(saveData), i);
        if (GetMonData(mon, 0x4C, NULL) == 0) {
            return i;
        }
    }
    return 0;
}

u16 Save_GetPartyLeadAlive(SaveData *saveData) {
    u16 i;
    u16 count = Party_GetCount(SaveArray_Party_Get(saveData));

    for (i = 0; i < count; i++) {
        void *mon = Party_GetMonByIndex(SaveArray_Party_Get(saveData), i);
        if (GetMonData(mon, 0x4C, NULL) == 0 && GetMonData(mon, 0xA3, NULL) != 0) {
            return i;
        }
    }
    return 0;
}

BOOL Save_PlayerHasAllRegisInParty(SaveData *saveData) {
    int found = 0;
    void *party = SaveArray_Party_Get(saveData);
    int count = Party_GetCount(party);
    u16 species[6];
    int i;
    int j;

    for (i = 0; i < count; i++) {
        species[i] = GetMonData(Party_GetMonByIndex(party, i), 5, NULL);
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < count; j++) {
            if (species[j] == sRegiSpecies[i]) {
                found++;
                break;
            }
        }
    }
    return found == 3;
}

static BOOL sub_0205BE28(TaskManager *taskManager) {
    SpinEnvironment *environment;
    VecFx32 position;
    int radius;
    s64 product;

    TaskManager_GetFieldSystem(taskManager);
    environment = TaskManager_GetEnvironment(taskManager);
    position.x = 0x8000;
    position.z = 0x8000;
    radius = environment->xRadius;
    product = GF_SinDegNoWrap(environment->angle);
    product *= radius;
    position.x = (int)((product + 0x800) >> 12);
    radius = environment->zRadius;
    product = GF_SinDegNoWrap(environment->angle);
    product *= radius;
    position.z = (int)((product + 0x800) >> 12);
    position.y = 0;
    sub_0205F9A0(environment->object, &position);
    environment->angle += environment->step;
    if (environment->angle >= 360) {
        environment->angle = 0;
        environment->turns--;
    }
    if (environment->turns == 0) {
        position.x = position.y = position.z = 0;
        sub_0205F9A0(environment->object, &position);
        Heap_Free(environment);
        return TRUE;
    }
    return FALSE;
}

void sub_0205BED8(TaskManager *taskManager, LocalMapObject *object, u16 turns, u16 step, u16 xRadius, u16 zRadius) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    SpinEnvironment *environment = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(SpinEnvironment));
    float value;

    MI_CpuFill8(environment, 0, sizeof(SpinEnvironment));
    if (xRadius != 0) {
        value = (float)(xRadius << 12) + 0.5f;
    } else {
        value = (float)(xRadius << 12) - 0.5f;
    }
    environment->xRadius = (int)value;
    if (zRadius != 0) {
        value = (float)(zRadius << 12) + 0.5f;
    } else {
        value = (float)(zRadius << 12) - 0.5f;
    }
    environment->zRadius = (int)value;
    environment->turns = turns;
    environment->step = step;
    environment->object = object;
    TaskManager_Call(fieldSystem->taskman, sub_0205BE28, environment);
}

static BOOL sub_0205BF6C(TaskManager *taskManager) {
    BlinkEnvironment *environment;

    TaskManager_GetFieldSystem(taskManager);
    environment = TaskManager_GetEnvironment(taskManager);
    MapObject_SetVisible(environment->object, environment->visible);
    if (environment->counter++ >= environment->interval) {
        environment->visible ^= 1;
        environment->counter = 0;
        if (environment->cycles-- == 0) {
            Heap_Free(environment);
            return TRUE;
        }
    }
    return FALSE;
}

void sub_0205BFB4(TaskManager *taskManager, LocalMapObject *object, u16 cycles, u16 interval) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    BlinkEnvironment *environment = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(BlinkEnvironment));

    MI_CpuFill8(environment, 0, sizeof(BlinkEnvironment));
    environment->cycles = cycles;
    environment->interval = interval;
    environment->object = object;
    environment->visible = 0;
    TaskManager_Call(fieldSystem->taskman, sub_0205BF6C, environment);
}
