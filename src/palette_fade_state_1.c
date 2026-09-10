#include "palette_fade_state_internal.h"

void HandleFadeUpdateFrame(void) {
    u8 *fade = _021D0EF4;
    if (_021D1034.active != 0) {
        if (DoFadeUpdateFrame(fade, fade + 0x14, fade + 0x44) == TRUE) {
            HandleEndFade(fade);
        }
    }
}

BOOL IsPaletteFadeFinished(void) {
    return _021D1034.active == 0;
}
