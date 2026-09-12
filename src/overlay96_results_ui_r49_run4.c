#include "overlay96_results_ui_r49_private.h"

void ov96_021EF924(Ov96ResultsUiR49 *work) {
    if (!ManagedSprite_IsAnimated(work->sprites[2])) {
        work->animIndex++;
        if (work->animIndex >= 2) {
            work->animIndex = 0;
        }
        ov96_021EFA04(work);
    }
}
