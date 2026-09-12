#include "overlay96_results_ui_r49_private.h"

void ov96_021EF770(Ov96ResultsUiR49 *work) {
    int value = work->selection * 3 + 0xD2;
    ov98_0221EBD8(work->message, 8, 0xF4, 0);
    ov98_0221EBEC(work->message, 9, 0xF2, 0, 0, 4);
    ov98_0221EBEC(work->message, 10, 0xF3, 0, 0, 4);
    ov98_0221EC08(work->message, 11, value, 0, 0);
}

void ov96_021EF7C4(Ov96ResultsUiR49 *work) {
    int value = work->selection * 3 + 0xD3;
    ov98_0221EBD8(work->message, 8, 0xF5, 0);
    ov98_0221EBEC(work->message, 9, 0xF1, 0, 0, 4);
    ov98_0221EBEC(work->message, 10, 0xF3, 0, 0, 4);
    ov98_0221EC08(work->message, 11, value, 0, 0);
}
