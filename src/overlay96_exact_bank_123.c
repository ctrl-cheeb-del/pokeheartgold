#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

void ov96_0221A670(int v) {
    ov96_0221A61C((float)(v * 3));
}

void ov96_0221A680(int v) {
    ov96_0221A61C((float)(v * 3));
}

void ov96_0221A690(u32 v) {
    ov96_0221A61C((float)v);
}

void ov96_0221A69C(float v) {
    ov96_0221A61C(ov96_0221A5D4(v, 0.08f));
}
