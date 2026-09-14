#ifndef TO45_OVERLAY41_R50_R4_GEOMETRY_PRIVATE_H
#define TO45_OVERLAY41_R50_R4_GEOMETRY_PRIVATE_H

#include "global.h"

typedef struct Ov41R50Object {
    void *data;
    int mode;
} Ov41R50Object;

typedef struct Ov41R50Node {
    u8 padding00[8];
    struct Ov41R50Node *next;
} Ov41R50Node;

typedef struct Ov41R50Source {
    s32 unk00;
    s32 unk04;
    u8 padding08[8];
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Ov41R50Source;

typedef struct Ov41R50Destination {
    s32 unk00;
    s32 unk04;
    s32 unk08;
    s32 unk0C;
    s32 unk10;
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
    s32 unk24;
    s32 unk28;
} Ov41R50Destination;

void ov41_02246020(void *data, s32 *out0, s32 *out2);
void ov41_02249888(void *data, u8 out[4]);
void ov41_02249B44(Ov41R50Node *node, s32 *out0, s32 *out1);
void ov41_02249B94(Ov41R50Node *node, s32 *out0, s32 *out1);
void ov41_02249AF4(Ov41R50Node *node, s32 value0, s32 value1);
void ov41_02249E60(const Ov41R50Source *source, s32 *out0, s32 *out1);

void ov41_02249BAC(Ov41R50Object *object, s32 *out0, s32 *out1, s32 *out2, s32 *out3);
void ov41_02249BE8(Ov41R50Node *head, s32 delta0, s32 delta1);
void ov41_02249C20(Ov41R50Node *node, s32 *out0, s32 *out1, s32 *out2, s32 *out3);
void ov41_02249C7C(Ov41R50Destination *destination, const Ov41R50Source *source);

#endif
