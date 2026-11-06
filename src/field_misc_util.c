#include "field_misc_util.h"

#include "global.h"

#include "constants/heap.h"
#include "constants/items.h"
#include "constants/pokemon.h"
#include "constants/sndseq.h"
#include "constants/species.h"

#include "msgdata/msg/msg_0666.h"

#include "field_system.h"
#include "heap.h"
#include "map_object.h"
#include "math_util.h"
#include "party.h"
#include "pokemon.h"
#include "task.h"

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
    u8 invisible;
    u8 padding[2];
} BlinkEnvironment;

static BOOL Task_SpinMapObject(TaskManager *taskManager);
static BOOL Task_BlinkMapObject(TaskManager *taskManager);

static const u16 sRegiSpecies[3] = { SPECIES_REGIROCK, SPECIES_REGICE, SPECIES_REGISTEEL };

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
    if (item >= ITEM_TM01 && item <= ITEM_HM08) {
        return TRUE;
    }
    return FALSE;
}

u16 GetOakJohtoDexRating(u16 count, u16 playerGender, u16 *fanfare) {
    *fanfare = SEQ_ME_HYOUKA1;
    if (count <= 9) {
        return msg_0666_00028;
    }
    if (count <= 19) {
        return msg_0666_00029;
    }
    if (count <= 34) {
        return msg_0666_00030;
    }
    if (count <= 49) {
        return msg_0666_00031;
    }
    if (count <= 64) {
        return msg_0666_00032;
    }
    if (count <= 79) {
        return msg_0666_00033;
    }
    if (count <= 94) {
        return msg_0666_00034;
    }
    if (count <= 109) {
        return msg_0666_00035;
    }
    if (count <= 124) {
        return msg_0666_00036;
    }
    if (count <= 139) {
        return msg_0666_00037;
    }
    if (count <= 154) {
        return msg_0666_00038;
    }
    if (count <= 169) {
        return msg_0666_00039;
    }
    if (count <= 184) {
        return msg_0666_00040;
    }
    if (count <= 199) {
        return msg_0666_00041;
    }
    if (count <= 214) {
        return msg_0666_00042;
    }
    if (count <= 229) {
        return msg_0666_00043;
    }
    if (count <= 244) {
        return msg_0666_00044;
    }
    if (count <= 253) {
        return msg_0666_00045;
    }
    *fanfare = SEQ_ME_HYOUKA6;
    if (playerGender) {
        return msg_0666_00023;
    }
    return msg_0666_00022;
}

u16 GetOakNationalDexRating(u16 count, u16 playerGender, u16 *fanfare) {
    *fanfare = SEQ_ME_HYOUKA1;
    if (count <= 100) {
        return msg_0666_00046;
    }
    if (count <= 150) {
        return msg_0666_00047;
    }
    if (count <= 200) {
        return msg_0666_00048;
    }
    if (count <= 250) {
        return msg_0666_00049;
    }
    if (count <= 300) {
        return msg_0666_00050;
    }
    if (count <= 350) {
        return msg_0666_00051;
    }
    if (count <= 400) {
        return msg_0666_00052;
    }
    if (count <= 435) {
        return msg_0666_00053;
    }
    if (count <= 465) {
        return msg_0666_00054;
    }
    if (count <= 475) {
        return msg_0666_00055;
    }
    if (count <= 483) {
        return msg_0666_00056;
    }
    *fanfare = SEQ_ME_HYOUKA6;
    if (playerGender) {
        return msg_0666_00025;
    }
    return msg_0666_00024;
}

u16 Save_GetPartyLead(SaveData *saveData) {
    u16 i;
    u16 count = Party_GetCount(SaveArray_Party_Get(saveData));

    for (i = 0; i < count; i++) {
        Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(saveData), i);
        if (GetMonData(mon, MON_DATA_IS_EGG, NULL) == 0) {
            return i;
        }
    }
    return 0;
}

u16 Save_GetPartyLeadAlive(SaveData *saveData) {
    u16 i;
    u16 count = Party_GetCount(SaveArray_Party_Get(saveData));

    for (i = 0; i < count; i++) {
        Pokemon *mon = Party_GetMonByIndex(SaveArray_Party_Get(saveData), i);
        if (GetMonData(mon, MON_DATA_IS_EGG, NULL) == 0 && GetMonData(mon, MON_DATA_HP, NULL) != 0) {
            return i;
        }
    }
    return 0;
}

BOOL Save_PlayerHasAllRegisInParty(SaveData *saveData) {
    int found = 0;
    Party *party = SaveArray_Party_Get(saveData);
    int count = Party_GetCount(party);
    u16 species[PARTY_SIZE];
    int i;
    int j;

    for (i = 0; i < count; i++) {
        species[i] = GetMonData(Party_GetMonByIndex(party, i), MON_DATA_SPECIES, NULL);
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

static BOOL Task_SpinMapObject(TaskManager *taskManager) {
    SpinEnvironment *environment;
    VecFx32 position;
    int radius;
    s64 product;

    TaskManager_GetFieldSystem(taskManager);
    environment = TaskManager_GetEnvironment(taskManager);
    position.x = FX32_CONST(8);
    position.z = FX32_CONST(8);
    radius = environment->xRadius;
    product = GF_SinDegNoWrap(environment->angle);
    product *= radius;
    position.x = (int)((product + 0x800) >> 12);
    radius = environment->zRadius;
    // BUG: z takes the sine as well, so the object sways back and forth along a diagonal instead of circling.
    product = GF_SinDegNoWrap(environment->angle);
    product *= radius;
    position.z = (int)((product + 0x800) >> 12);
    position.y = 0;
    MapObject_SetDrawOffset(environment->object, &position);
    environment->angle += environment->step;
    if (environment->angle >= 360) {
        environment->angle = 0;
        environment->turns--;
    }
    if (environment->turns == 0) {
        position.x = position.y = position.z = 0;
        MapObject_SetDrawOffset(environment->object, &position);
        Heap_Free(environment);
        return TRUE;
    }
    return FALSE;
}

void CallTask_SpinMapObject(TaskManager *taskManager, LocalMapObject *object, u16 turns, u16 step, u16 xRadius, u16 zRadius) {
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
    TaskManager_Call(fieldSystem->taskman, Task_SpinMapObject, environment);
}

static BOOL Task_BlinkMapObject(TaskManager *taskManager) {
    BlinkEnvironment *environment;

    TaskManager_GetFieldSystem(taskManager);
    environment = TaskManager_GetEnvironment(taskManager);
    MapObject_SetInvisible(environment->object, environment->invisible);
    if (environment->counter++ >= environment->interval) {
        environment->invisible ^= 1;
        environment->counter = 0;
        if (environment->cycles-- == 0) {
            Heap_Free(environment);
            return TRUE;
        }
    }
    return FALSE;
}

void CallTask_BlinkMapObject(TaskManager *taskManager, LocalMapObject *object, u16 cycles, u16 interval) {
    FieldSystem *fieldSystem = TaskManager_GetFieldSystem(taskManager);
    BlinkEnvironment *environment = Heap_AllocAtEnd(HEAP_ID_FIELD2, sizeof(BlinkEnvironment));

    MI_CpuFill8(environment, 0, sizeof(BlinkEnvironment));
    environment->cycles = cycles;
    environment->interval = interval;
    environment->object = object;
    environment->invisible = 0;
    TaskManager_Call(fieldSystem->taskman, Task_BlinkMapObject, environment);
}
