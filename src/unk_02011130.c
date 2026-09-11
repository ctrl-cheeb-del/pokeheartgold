#include <nitro.h>

#include "global.h"

#include "unk_02011130_internal.h"

#define GX_BLEND_ALL 0x3F

static inline int GX_IsHBlank(void);
static inline int GX_IsHBlank(void) {
    return reg_GX_DISPSTAT & REG_GX_DISPSTAT_HBLK_MASK;
}

static inline void SetOutsidePlane(int planes, BOOL effect, int screen);
static inline void SetInsidePlane(int planes, BOOL effect, int window, int screen);
static inline void ApplyLine(HBlankWindowWork *work, int line, int index);

static inline void SetOutsidePlane(int planes, BOOL effect, int screen) {
    if (screen == 0) {
        if (GX_IsHBlank()) {
            G2_SetWndOutsidePlane(planes, effect);
        }
    } else {
        if (GX_IsHBlank()) {
            G2S_SetWndOutsidePlane(planes, effect);
        }
    }
}

static inline void SetInsidePlane(int planes, BOOL effect, int window, int screen) {
    if (window == 0) {
        if (screen == 0) {
            if (GX_IsHBlank()) {
                G2_SetWnd0InsidePlane(planes, effect);
            }
        } else {
            if (GX_IsHBlank()) {
                G2S_SetWnd0InsidePlane(planes, effect);
            }
        }
    } else {
        if (screen == 0) {
            if (GX_IsHBlank()) {
                G2_SetWnd1InsidePlane(planes, effect);
            }
        } else {
            if (GX_IsHBlank()) {
                G2S_SetWnd1InsidePlane(planes, effect);
            }
        }
    }
}

static inline void ApplyLine(HBlankWindowWork *work, int line, int index) {
    HBlankWindowBuffer *buffer = &work->buffer[index];

    if (buffer->latched[line] == 0) {
        SetOutsidePlane(GX_BLEND_ALL, TRUE, work->screen);
        SetInsidePlane(GX_BLEND_PLANEMASK_BD, TRUE, buffer->window, work->screen);
    } else {
        SetOutsidePlane(GX_BLEND_PLANEMASK_BD, TRUE, work->screen);
        SetInsidePlane(GX_BLEND_ALL, TRUE, buffer->window, work->screen);
    }
}

void sub_02011130(void *data) {
    HBlankWindowWork *work = data;
    int line;

    if (data == NULL) {
        GF_AssertFail();
    }

    line = GX_GetVCount();
    if (line < 192) {
        line++;
        if (line > 191) {
            line -= 192;
        }
        if (work->count == 1) {
            ApplyLine(work, line, 0);
        } else {
            ApplyLine(work, line, 0);
            ApplyLine(work, line, 1);
        }
    }
}
