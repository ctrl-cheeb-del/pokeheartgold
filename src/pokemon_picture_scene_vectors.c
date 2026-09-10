#include "pokemon_picture_scene_internal.h"

typedef struct PictureVectorQuad {
    UnkVec3s vectors[4];
} PictureVectorQuad;

typedef struct PictureVectorWork {
    u8 pad_000[0x2D8];
    PictureVectorQuad from[4];
    PictureVectorQuad out[4];
    PictureVectorQuad to[4];
    u32 done;
} PictureVectorWork;

extern const u8 _02104EB0[], _02104EC2[], _02104ED4[], _02104EE6[];
extern const u8 _02104EF8[], _02104F0A[], _02104F1C[], _02104F2E[];
extern const u8 _02104F40[], _02104F52[], _02104F64[], _02104F76[];
extern const u8 _02104F88[], _02104F9A[], _02104FAC[], _02104FBE[];

void sub_0208DFF8(const UnkVec3s *from, const UnkVec3s *to, UnkVec3s *out) {
    int diff;
    s16 rounded;

    diff = to->x - from->x;
    if ((float)diff / 4096.0f / 4.0f > 0.0f) {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f + 0.5f);
    } else {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f - 0.5f);
    }
    out->x = rounded;

    diff = to->y - from->y;
    if ((float)diff / 4096.0f / 4.0f > 0.0f) {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f + 0.5f);
    } else {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f - 0.5f);
    }
    out->y = rounded;

    diff = to->z - from->z;
    if ((float)diff / 4096.0f / 4.0f > 0.0f) {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f + 0.5f);
    } else {
        rounded = (s16)(((float)diff / 4096.0f / 4.0f) * 4096.0f - 0.5f);
    }
    out->z = rounded;
}

void sub_0208E174(UnkStruct_0208DE40 *summary) {
    u32 i;
    u8 *raw = (u8 *)summary;
    PictureVectorWork *vectors = (PictureVectorWork *)summary;

    sub_0208DF9C((const UnkAnimVec *)_02104EB0, (UnkVec3s *)&raw[0x398], raw[0x275]);
    sub_0208DF9C((const UnkAnimVec *)_02104EC2, (UnkVec3s *)&raw[0x39E], raw[0x276]);
    sub_0208DF9C((const UnkAnimVec *)_02104ED4, (UnkVec3s *)&raw[0x3AA], raw[0x277]);
    sub_0208DF9C((const UnkAnimVec *)_02104EE6, (UnkVec3s *)&raw[0x3A4], 0);
    sub_0208DF9C((const UnkAnimVec *)_02104EF8, (UnkVec3s *)&raw[0x3B0], raw[0x279]);
    sub_0208DF9C((const UnkAnimVec *)_02104F0A, (UnkVec3s *)&raw[0x3B6], raw[0x275]);
    sub_0208DF9C((const UnkAnimVec *)_02104F1C, (UnkVec3s *)&raw[0x3C2], 0);
    sub_0208DF9C((const UnkAnimVec *)_02104F2E, (UnkVec3s *)&raw[0x3BC], raw[0x278]);
    sub_0208DF9C((const UnkAnimVec *)_02104F40, (UnkVec3s *)&raw[0x3C8], raw[0x279]);
    sub_0208DF9C((const UnkAnimVec *)_02104F52, (UnkVec3s *)&raw[0x3CE], 0);
    sub_0208DF9C((const UnkAnimVec *)_02104F64, (UnkVec3s *)&raw[0x3DA], raw[0x277]);
    sub_0208DF9C((const UnkAnimVec *)_02104F76, (UnkVec3s *)&raw[0x3D4], raw[0x278]);
    sub_0208DF9C((const UnkAnimVec *)_02104F88, (UnkVec3s *)&raw[0x3E0], 0);
    sub_0208DF9C((const UnkAnimVec *)_02104F9A, (UnkVec3s *)&raw[0x3E6], raw[0x276]);
    sub_0208DF9C((const UnkAnimVec *)_02104FAC, (UnkVec3s *)&raw[0x3F2], raw[0x277]);
    sub_0208DF9C((const UnkAnimVec *)_02104FBE, (UnkVec3s *)&raw[0x3EC], raw[0x278]);

    for (i = 0; i < 4; i++) {
        sub_0208DFF8(&vectors->from[i].vectors[0], &vectors->to[i].vectors[0], &vectors->out[i].vectors[0]);
        sub_0208DFF8(&vectors->from[i].vectors[1], &vectors->to[i].vectors[1], &vectors->out[i].vectors[1]);
        sub_0208DFF8(&vectors->from[i].vectors[2], &vectors->to[i].vectors[2], &vectors->out[i].vectors[2]);
        sub_0208DFF8(&vectors->from[i].vectors[3], &vectors->to[i].vectors[3], &vectors->out[i].vectors[3]);
    }
    vectors->done = 0;
}
