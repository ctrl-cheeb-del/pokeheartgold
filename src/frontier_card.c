#include "global.h"

#include "heap.h"
#include "location_gmm_dat.h"
#include "player_data.h"
#include "pm_string.h"
#include "sav_system_info.h"
#include "save.h"
#include "save_misc_data.h"
#include "save_wifi_history.h"
#include "string_util.h"
#include "unk_0205B3DC.h"

typedef struct FrontierCard {
    u16 name[8];
    u32 trainerId;
    u8 gender;
    u8 birthdayMonth;
    u8 avatar;
    u8 country;
    u8 region;
    u8 version;
    u8 unk_1A;
    u8 isEgg : 1;
    u8 form : 7;
    u16 species;
    u8 unk_1E[2];
    u16 greeting[40];
    u8 unk_70[12];
    u16 crc;
    u8 unk_7E[2];
} FrontierCard;

FrontierCard *sub_020314A4(enum HeapID heapId);
void sub_020314BC(FrontierCard *card);
void sub_020314C4(FrontierCard *card, SaveData *saveData);
String *sub_020315B8(const u16 *name, enum HeapID heapId);
u32 sub_020315D0(FrontierCard *card);
u32 sub_020315E0(FrontierCard *card);
u32 sub_020315F0(FrontierCard *card);
u32 sub_02031610(FrontierCard *card);
u32 sub_02031620(FrontierCard *card);
u32 sub_0203162C(FrontierCard *card);
u8 sub_02070438(u16 species, u8 form);

FrontierCard *sub_020314A4(enum HeapID heapId) {
    FrontierCard *ret = Heap_Alloc(heapId, sizeof(FrontierCard));
    MI_CpuFill8(ret, 0, sizeof(FrontierCard));
    return ret;
}

void sub_020314BC(FrontierCard *card) {
    Heap_Free(card);
}

void sub_020314C4(FrontierCard *card, SaveData *saveData) {
    PlayerProfile *profile = Save_PlayerData_GetProfile(saveData);
    SaveWiFiHistory *wifiHistory = Save_WiFiHistory_Get(saveData);
    Save_SysInfo_Get(saveData);
    SAVE_MISC_DATA *misc = (SAVE_MISC_DATA *)Save_Misc_Const_Get(saveData);
    OSOwnerInfo ownerInfo;
    int species;
    int form;
    int isEgg;
    int i;

    OS_GetOwnerInfo(&ownerInfo);
    SaveMisc_GetFavoriteMon(misc, &species, &form, &isEgg);
    MI_CpuFill8(card, 0, sizeof(FrontierCard));
    CopyU16StringArray(card->name, PlayerProfile_GetNamePtr(profile));
    card->trainerId = PlayerProfile_GetTrainerID(profile);
    card->gender = PlayerProfile_GetTrainerGender(profile);
    card->species = species;
    card->form = form;
    card->isEgg = isEgg;
    card->country = WifiHistory_GetPlayerCountry(wifiHistory);
    card->region = WiFiHistory_GetPlayerRegion(wifiHistory);
    for (i = 0; i < 40; i++) {
        card->greeting[i] = 0xFFFF;
    }
    SaveMisc_GetBattleGreeting(misc, (MailMessage *)card->greeting);
    card->birthdayMonth = ownerInfo.birthday.month;
    card->avatar = GetUnionRoomAvatarAttrBySprite(PlayerProfile_GetTrainerGender(profile), PlayerProfile_GetAvatar(profile), 0);
    card->version = GAME_VERSION;
    card->unk_1A = 2;
    card->crc = SaveArray_CalcCRC16(saveData, card, 0x7C);
}

String *sub_020315B8(const u16 *name, enum HeapID heapId) {
    String *ret = String_New(15, heapId);
    CopyU16ArrayToStringN(ret, name, 15);
    return ret;
}

u32 sub_020315D0(FrontierCard *card) {
    if (card->gender != 0 && card->gender != 1) {
        return 0;
    }
    return card->gender;
}

u32 sub_020315E0(FrontierCard *card) {
    if (card->species >= 495) {
        return 0;
    }
    return card->species;
}

u32 sub_020315F0(FrontierCard *card) {
    if (card->species >= 495) {
        return 0;
    }
    return sub_02070438(card->species, card->form);
}

u32 sub_02031610(FrontierCard *card) {
    u32 ret = card->isEgg;
    if (ret > 1) {
        ret = 1;
    }
    return ret;
}

u32 sub_02031620(FrontierCard *card) {
    if (card->country >= 234) {
        return 0;
    }
    return card->country;
}

u32 sub_0203162C(FrontierCard *card) {
    u32 country = card->country;
    u32 region;
    if (country >= 234) {
        return 0;
    }
    region = card->region;
    if (LocationGmmDatRegionCountGetByCountryMsgNo(country) < region) {
        region = 0;
    }
    return region;
}
