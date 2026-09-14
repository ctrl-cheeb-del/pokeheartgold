#ifndef OVERLAY_93_ARM_SOL_R38_PRIVATE_H
#define OVERLAY_93_ARM_SOL_R38_PRIVATE_H

// Include order selects the instruction set: global.h enables Thumb through
// nitro/code16.h, then code32.h switches this translation unit back to ARM.
// clang-format would reverse these includes and silently emit Thumb.
// clang-format off
#include "global.h"
#include <nitro/code32.h>
// clang-format on

/* Scratch declarations are intentionally kept in candidate.c for easy extraction. */

#endif
