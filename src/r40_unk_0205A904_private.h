#ifndef POKEHEARTGOLD_UNK_0205A904_PRIVATE_H
#define POKEHEARTGOLD_UNK_0205A904_PRIVATE_H
#include "global.h"

#include "mail_message.h"
#include "message_format.h"
#include "player_data.h"
#include "unk_0205B3DC.h"
struct UnkSub_0205A904 {
    u32 id[4];
    u8 a[4];
    u8 b[4];
    u8 avatar[4];
    u8 command;
};
struct LinkMessageStateA904 {
    u32 unk00[2];
    PlayerProfile *profile;
    u8 pad0C[0x110 - 0x0C];
    void *objects[10];
    u8 pad138[0x178 - 0x138];
    MailMessage mail;
};
extern const s32 _020FC9D4[20];
void sub_0205A8B4(struct UnkSub_0205A904 *data, int mode);
void sub_02035854(void *data);
void sub_0203588C(void);
void sub_0205A904(int command);
int sub_0205A9A0(struct LinkMessageStateA904 *state, MessageFormat *msgFmt);
#endif
