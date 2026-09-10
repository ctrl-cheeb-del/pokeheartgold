#ifndef POKEHEARTGOLD_WIRELESS_ROOM_INTERNAL_H
#define POKEHEARTGOLD_WIRELESS_ROOM_INTERNAL_H
#include "global.h"

#include "math_util.h"
#include "sound.h"
#include "unk_02005D10.h"
#include "unk_02032844.h"
#include "unk_02033AE0.h"
#include "unk_02035900.h"
#include "unk_02037C94.h"
typedef struct Room {
    u8 pad0[0x384];
    u32 flag;
    u32 send[0x2EE];
    u32 checksum, random;
    u8 receive[5][0xBC0];
    u32 count, unk4a0c, remote;
    u8 active;
    u8 pad4a15[7];
    u32 participantCount, unk4a20, participantMask;
    u8 pad4a28[8];
    u16 assignedCount;
} Room;
typedef struct RoomHandshake {
    u8 sender, count, command, accepted;
} RoomHandshake;
extern const u32 _021059DC[];
void ov73_021E6B98(Room *);
void ov73_021E705C(Room *, int, int);
void ov73_021E7120(Room *, int, int);
int ov73_021E7488(void);
u32 MATH_CountPopulation(u32);
void sub_02038C1C(int);
BOOL sub_02036FD8(int, void *, int);
void sub_0208FB64(Room *room);
void sub_0208FB78(int sender, int unused, void *data, Room *room);
void sub_0208FB88(int sender, int unused, u8 *data, Room *room);
void sub_0208FB98(int sender, int unused, void *data, Room *room);
void sub_0208FBE0(int sender, int unused, void *data, Room *room);
void sub_0208FBF0(int sender, int unused, void *data, Room *room);
void sub_0208FCDC(int sender, int unused, u8 *data, Room *room);
void sub_0208FCFC(int sender, int unused, void *data, Room *room);
void sub_0208FD00(int sender, int unused, void *data, Room *room);
void sub_0208FD04(int sender, int unused, void *data, Room *room);
void sub_0208FD1C(int sender);
void sub_0208FD3C(Room *room, int unused);
u32 sub_0208FD7C(void);
u32 sub_0208FD80(void);
u32 sub_0208FD84(void);
void *sub_0208FD88(int sender, Room *room);

void sub_0208FB64(Room *room);
void sub_0208FB78(int sender, int unused, void *data, Room *room);
void sub_0208FB88(int sender, int unused, u8 *data, Room *room);
void sub_0208FB98(int sender, int unused, void *data, Room *room);
void sub_0208FBE0(int sender, int unused, void *data, Room *room);
void sub_0208FBF0(int sender, int unused, void *data, Room *room);
void sub_0208FCDC(int sender, int unused, u8 *data, Room *room);
void sub_0208FCFC(int sender, int unused, void *data, Room *room);
void sub_0208FD00(int sender, int unused, void *data, Room *room);
void sub_0208FD04(int sender, int unused, void *data, Room *room);
void sub_0208FD1C(int sender);
void sub_0208FD3C(Room *room, int unused);
u32 sub_0208FD7C(void);
u32 sub_0208FD80(void);
u32 sub_0208FD84(void);
void *sub_0208FD88(int sender, Room *room);

#endif
