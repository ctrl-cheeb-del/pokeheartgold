#ifndef PRIVATE_OVERLAY_90_H
#define PRIVATE_OVERLAY_90_H

typedef struct Ov90LinkRoster {
    u32 value;
    u8 slots[4];
    u8 count;
    u8 localSlot;
    u8 mode;
    u8 isHost;
    void *records;
} Ov90LinkRoster;

int sub_020347A0(void);
int sub_0203769C(void);
void *sub_02034818(int slot);
void GF_AssertFail(void);

void ov90_02258800(Ov90LinkRoster *roster, void *connection, u32 value, u8 mode, void *records);

#endif
