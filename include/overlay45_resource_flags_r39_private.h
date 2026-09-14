#ifndef OVERLAY45_RESOURCE_FLAGS_R39_PRIVATE_H
#define OVERLAY45_RESOURCE_FLAGS_R39_PRIVATE_H

#include "global.h"

typedef struct Overlay45ResourceConfig {
    u16 lookupKey;
    u16 packedResourceId;
} Overlay45ResourceConfig;

typedef struct Overlay45PackedFlags {
    u8 unused : 6;
    u8 value : 2;
} Overlay45PackedFlags;

void ov45_02230E28(u8 *data);
void ov45_02230978(u8 *data, int value);
int ov45_02230994(u8 *data);
Overlay45ResourceConfig *ov45_0223099C(u16 id);

#endif
