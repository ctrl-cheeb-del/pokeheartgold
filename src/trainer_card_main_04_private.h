#ifndef POKEHEARTGOLD_TO45_TRAINER_CARD_MAIN_04_PRIVATE_H
#define POKEHEARTGOLD_TO45_TRAINER_CARD_MAIN_04_PRIVATE_H

#include "global.h"

#include "bg_window.h"

typedef struct TrainerCardMainState04 {
    u8 data[0x4000];
} TrainerCardMainState04;

typedef struct TrainerCardData04 {
    u8 padding[4];
    u8 unused : 4;
    u8 showMessage : 1;
    u8 rest : 3;
} TrainerCardData04;

typedef struct TrainerCardAnimFlags04 {
    u8 unused : 1;
    u8 skipMessage : 1;
    u8 rest : 6;
} TrainerCardAnimFlags04;

extern const GraphicsModes ov51_021E7DC8;
extern const BgTemplate ov51_021E7E8C;
typedef struct TrainerCardBgPair {
    BgTemplate items[2];
} TrainerCardBgPair;

extern const TrainerCardBgPair ov51_021E7ED0;
extern const BgTemplate ov51_021E7E70;
extern const BgTemplate ov51_021E7E38;
extern const BgTemplate ov51_021E7E54;

void ov51_021E6238(BgConfig *bgConfig);
void ov51_021E6644(BgConfig *bgConfig);
void ov51_021E66C0(TrainerCardMainState04 *state);
void ov51_021E6734(TrainerCardMainState04 *state);
int ov51_021E67A4(TrainerCardMainState04 *state);
int ov51_021E6888(TrainerCardMainState04 *state);

void ov51_021E74D4(void *windows, u8 first, u8 last);
void ov51_021E6CCC(TrainerCardMainState04 *state);
void ov51_021E6C6C(TrainerCardMainState04 *state);
void ov51_021E7D44(void *sprites, int sprite, int sequence, int draw);
void ov51_021E76EC(TrainerCardMainState04 *state, int mode);
void ov51_021E6D44(BgConfig *bgConfig, int bgId, void *window);
void ov51_021E6F18(TrainerCardMainState04 *state, void *windows, void *cardData);
void ov51_021E7208(TrainerCardMainState04 *state, void *windows, void *cardData);
void ov51_021E71D0(TrainerCardMainState04 *state, void *windows);
void ov51_021E77A0(TrainerCardMainState04 *state, int message);
void ov51_021E7804(TrainerCardMainState04 *state, int message);
void ov51_021E6E10(TrainerCardMainState04 *state, int mode);
int ov51_021E786C(TrainerCardMainState04 *state, int mode);
int TextPrinterCheckActive(u8 printerId);
void PlaySE(u16 seqNo);

#endif
