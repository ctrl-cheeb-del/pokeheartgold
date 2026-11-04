#include "frontier_save_access.h"

void FactoryFlags_Init(u8 *flags) {
    MI_CpuFill8(flags, 0, 4);
}

void FactoryFlags_SetField(u8 *flags, u32 field, u8 index, u8 *value) {
    if (field == FACTORY_FLAGS_HAS_STREAK) {
        if (*value >= 1) {
            *flags |= 1 << index;
        } else {
            *flags &= (1 << index) ^ 0xff;
        }
    }
}

u32 FactoryFlags_GetField(u8 *flags, int field, u8 index, int unused) {
    if (field == FACTORY_FLAGS_HAS_STREAK) {
        return (*flags >> index) & 1;
    }
    return 0;
}

u8 *Save_Frontier_GetFactoryFlags(SaveData *save) {
    return Save_Frontier_GetStatic(save)->factoryFlags;
}

void HallChallenge_Clear(HallChallenge *challenge) {
    MI_CpuFill8(challenge, 0, sizeof(HallChallenge));
}

HallChallenge *Save_Frontier_GetHallChallenge(SaveData *save) {
    return &Save_Frontier_GetStatic(save)->challenge.hall;
}

u32 HallChallenge_GetSaved(HallChallenge *challenge) {
    return challenge->saved;
}

void HallChallenge_SetSaved(HallChallenge *challenge, int saved) {
    challenge->saved = saved;
}

void HallChallenge_SetField(HallChallenge *challenge, int field, u8 index, int unused, void *value) {
    switch (field) {
    case HALL_CHALLENGE_TYPE:
        challenge->type = *(u8 *)value;
        break;
    case HALL_CHALLENGE_BATTLE_NO:
        challenge->battleNo = *(u8 *)value;
        break;
    case HALL_CHALLENGE_TRAINER_IDS:
        challenge->trainerIds[index] = *(u16 *)value;
        break;
    case HALL_CHALLENGE_PARTY_SLOTS:
        challenge->partySlots[index] = *(u8 *)value;
        break;
    case HALL_CHALLENGE_SET_IDS:
        challenge->setIds[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

u32 HallChallenge_GetField(HallChallenge *challenge, int field, u8 index, int unused, int unused2) {
    switch (field) {
    case HALL_CHALLENGE_TYPE:
        return challenge->type;
    case HALL_CHALLENGE_BATTLE_NO:
        return challenge->battleNo;
    case HALL_CHALLENGE_TRAINER_IDS:
        return challenge->trainerIds[index];
    case HALL_CHALLENGE_PARTY_SLOTS:
        return challenge->partySlots[index];
    case HALL_CHALLENGE_SET_IDS:
        return challenge->setIds[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}

u8 HallTypeRanks_Get(u8 cell, u8 *ranks) {
    u8 byte = (cell >> 1);
    u8 nibble = cell % 2;
    return (ranks[byte] >> (nibble * 4)) & 15;
}

void HallTypeRanks_Set(u8 cell, u8 *ranks, u8 rank) {
    u8 byte = (cell >> 1);
    u8 nibble = cell % 2;
    if (nibble == 0) {
        ranks[byte] &= 0xf0;
    } else {
        ranks[byte] &= 0xf;
    }
    ranks[byte] |= (u8)(rank << (nibble * 4));
}

void HallTypeRanks_Clear(u8 *ranks) {
    for (int i = 0; i < 18; i++) {
        HallTypeRanks_Set(i, ranks, 0);
    }
}

void HallFlags_Init(u8 *flags) {
    MI_CpuFill8(flags, 0, 4);
}

u8 *Save_Frontier_GetHallFlags(SaveData *save) {
    return Save_Frontier_GetStatic(save)->hallFlags;
}

void HallFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input) {
    u8 *value = input;
    switch (field) {
    case HALL_FLAGS_HAS_STREAK:
        if (*value >= 1) {
            *flags |= 1 << index;
        } else {
            *flags &= (1 << index) ^ 0xff;
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

u32 HallFlags_GetField(u8 *flags, int field, u8 index, int unused, int unused2) {
    if (field == HALL_FLAGS_HAS_STREAK) {
        return (*flags >> index) & 1;
    }
    GF_ASSERT(FALSE);
    return 0;
}

void CastleChallenge_Clear(CastleChallenge *challenge) {
    MI_CpuFill8(challenge, 0, sizeof(CastleChallenge));
}

CastleChallenge *Save_Frontier_GetCastleChallenge(SaveData *save) {
    return &Save_Frontier_GetStatic(save)->challenge.castle;
}

u32 CastleChallenge_GetSaved(CastleChallenge *challenge) {
    return challenge->saved;
}

void CastleChallenge_SetSaved(CastleChallenge *challenge, int saved) {
    challenge->saved = saved;
}

void CastleChallenge_SetField(CastleChallenge *challenge, int field, u8 index, int column, void *value) {
    switch (field) {
    case CASTLE_CHALLENGE_TYPE:
        challenge->type = *(u8 *)value;
        break;
    case CASTLE_CHALLENGE_BATTLE_NO:
        challenge->battleNo = *(u8 *)value;
        break;
    case CASTLE_CHALLENGE_HP:
        challenge->hp[index] = *(u16 *)value;
        break;
    case CASTLE_CHALLENGE_PP:
        challenge->pp[index][column] = *(u8 *)value;
        break;
    case CASTLE_CHALLENGE_STATUS:
        challenge->status[index] = *(u32 *)value;
        break;
    case CASTLE_CHALLENGE_HELD_ITEM:
        challenge->heldItems[index] = *(u16 *)value;
        break;
    case CASTLE_CHALLENGE_TRAINER_IDS:
        challenge->trainerIds[index] = *(u16 *)value;
        break;
    case CASTLE_CHALLENGE_PARTY_SLOTS:
        challenge->partySlots[index] = *(u8 *)value;
        break;
    case CASTLE_CHALLENGE_SET_IDS:
        challenge->setIds[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

u32 CastleChallenge_GetField(CastleChallenge *challenge, int field, u8 index, int column, int unused) {
    switch (field) {
    case CASTLE_CHALLENGE_TYPE:
        return challenge->type;
    case CASTLE_CHALLENGE_BATTLE_NO:
        return challenge->battleNo;
    case CASTLE_CHALLENGE_HP:
        return challenge->hp[index];
    case CASTLE_CHALLENGE_PP:
        return challenge->pp[index][column];
    case CASTLE_CHALLENGE_STATUS:
        return challenge->status[index];
    case CASTLE_CHALLENGE_HELD_ITEM:
        return challenge->heldItems[index];
    case CASTLE_CHALLENGE_TRAINER_IDS:
        return challenge->trainerIds[index];
    case CASTLE_CHALLENGE_PARTY_SLOTS:
        return challenge->partySlots[index];
    case CASTLE_CHALLENGE_SET_IDS:
        return challenge->setIds[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}

void CastleFlags_Init(u8 *flags) {
    MI_CpuFill8(flags, 0, 4);
}

u8 *Save_Frontier_GetCastleFlags(SaveData *save) {
    return Save_Frontier_GetStatic(save)->castleFlags;
}

void CastleFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input) {
    u8 *value = input;
    switch (field) {
    case CASTLE_FLAGS_HAS_STREAK:
        if (*value >= 1) {
            *flags |= 1 << index;
        } else {
            *flags &= (1 << index) ^ 0xff;
        }
        break;
    case CASTLE_FLAGS_ONCE:
        flags[1] = 1;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

u32 CastleFlags_GetField(u8 *flags, u32 field, u8 index, u32 unused, u32 unused2) {
    switch (field) {
    case CASTLE_FLAGS_HAS_STREAK:
        return (*flags >> index) & 1;
    case CASTLE_FLAGS_ONCE:
        return flags[1];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}

void ArcadeChallenge_Clear(ArcadeChallenge *challenge) {
    MI_CpuFill8(challenge, 0, sizeof(ArcadeChallenge));
}

ArcadeChallenge *Save_Frontier_GetArcadeChallenge(SaveData *save) {
    return &Save_Frontier_GetStatic(save)->challenge.arcade;
}

u32 ArcadeChallenge_GetSaved(ArcadeChallenge *challenge) {
    return challenge->saved;
}

void ArcadeChallenge_SetSaved(ArcadeChallenge *challenge, int saved) {
    challenge->saved = saved;
}

void ArcadeChallenge_SetField(ArcadeChallenge *challenge, int field, u8 index, int unused, void *value) {
    switch (field) {
    case ARCADE_CHALLENGE_TYPE:
        challenge->type = *(u8 *)value;
        break;
    case ARCADE_CHALLENGE_RANDOM_FLAG:
        challenge->randomFlag = *(u8 *)value;
        break;
    case ARCADE_CHALLENGE_BATTLE_NO:
        challenge->battleNo = *(u8 *)value;
        break;
    case ARCADE_CHALLENGE_CURSOR_SPEED:
        challenge->cursorSpeed = *(u8 *)value;
        break;
    case ARCADE_CHALLENGE_HELD_ITEMS:
        challenge->heldItems[index] = *(u16 *)value;
        break;
    case ARCADE_CHALLENGE_TRAINER_IDS:
        challenge->trainerIds[index] = *(u16 *)value;
        break;
    case ARCADE_CHALLENGE_PARTY_SLOTS:
        challenge->partySlots[index] = *(u8 *)value;
        break;
    case ARCADE_CHALLENGE_SET_IDS:
        challenge->setIds[index] = *(u16 *)value;
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
}

u32 ArcadeChallenge_GetField(ArcadeChallenge *challenge, int field, u8 index, int unused, int unused2) {
    switch (field) {
    case ARCADE_CHALLENGE_TYPE:
        return challenge->type;
    case ARCADE_CHALLENGE_RANDOM_FLAG:
        return challenge->randomFlag;
    case ARCADE_CHALLENGE_BATTLE_NO:
        return challenge->battleNo;
    case ARCADE_CHALLENGE_CURSOR_SPEED:
        return challenge->cursorSpeed;
    case ARCADE_CHALLENGE_HELD_ITEMS:
        return challenge->heldItems[index];
    case ARCADE_CHALLENGE_TRAINER_IDS:
        return challenge->trainerIds[index];
    case ARCADE_CHALLENGE_PARTY_SLOTS:
        return challenge->partySlots[index];
    case ARCADE_CHALLENGE_SET_IDS:
        return challenge->setIds[index];
    default:
        GF_ASSERT(FALSE);
        break;
    }
    return 0;
}

void ArcadeFlags_Init(u8 *flags) {
    MI_CpuFill8(flags, 0, 4);
}

u8 *Save_Frontier_GetArcadeFlags(SaveData *save) {
    return Save_Frontier_GetStatic(save)->arcadeFlags;
}

void ArcadeFlags_SetField(u8 *flags, u32 field, u32 index, u32 unused, void *input) {
    u8 *value = input;
    if (field == ARCADE_FLAGS_HAS_STREAK) {
        if (*value >= 1) {
            *flags |= 1 << index;
        } else {
            *flags &= (1 << index) ^ 0xff;
        }
    } else {
        GF_ASSERT(FALSE);
    }
}

u32 ArcadeFlags_GetField(u8 *flags, u32 field, u8 index, u32 unused, u32 unused2) {
    if (field == ARCADE_FLAGS_HAS_STREAK) {
        return (*flags >> index) & 1;
    }
    GF_ASSERT(FALSE);
    return 0;
}
