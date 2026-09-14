#ifndef TO45_OVERLAY45_R40_PRIVATE_H
#define TO45_OVERLAY45_R40_PRIVATE_H

typedef struct Ov45R40Model {
    NNSG3dResFileHeader *file;
    NNSG3dResMdlSet *set;
    NNSG3dResMdl *model;
    NNSG3dResTex *texture;
    int alpha;
} Ov45R40Model;

u32 ov45_022309D0(u32 divisor, u16 value, u32 factor);
void ov45_022309E8(Ov45R40Model *model, void *narc, int fileId, u32 heapId);
void ov45_02230A44(Ov45R40Model *model);
void ov45_02230A4C(Ov45R40Model *model, int alpha);

#endif
