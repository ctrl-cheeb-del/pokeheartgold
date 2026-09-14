#include "to47_overlay49_view_r76_internal.h"

static inline void ClearView(void *dest) {
    u8 *clear = dest;
    u32 count = sizeof(Ov49ViewR76);

    while (count != 0) {
        *clear = 0;
        clear = clear + 1;
        count = count - 1;
    }
}

void ov49_022686F0(void *colors) {
    u16 second;
    u16 first;
    int i;
    u8 *light;

    i = 0;
    light = colors;
    for (; i < 2; i++, light += 4) {
        ov49_02268624(light, &second);
        NNS_G3dGlbLightColor((GXLightId)i, second);
    }
    ov49_02268624((u8 *)colors + 8, &second);
    ov49_02268624((u8 *)colors + 0xC, &first);
    NNS_G3dGlbMaterialColorDiffAmb(second, first, 0);
    ov49_02268624((u8 *)colors + 0x10, &second);
    ov49_02268624((u8 *)colors + 0x14, &first);
    NNS_G3dGlbMaterialColorSpecEmi(second, first, 0);
}

Ov49ViewR76 *ov49_02268764(u32 heapId, void *work) {
    Ov49ViewR76 *view = Heap_Alloc(heapId, sizeof(Ov49ViewR76));
    void *a;
    void *b;
    void *c;
    u32 flagA;
    u32 flagB;
    u32 flagC;
    u32 flagD;

    ClearView(view);
    view->work = work;
    view->selection = ov49_02259FE8(work);
    view->model = ov49_02259FF8(work);
    view->object = ov49_02259FF0(work);
    a = ov49_02268974(ov45_0222A3BC(view->selection));
    b = ov49_022689A0(ov45_0222A3D4(view->selection));
    c = ov49_022689D4(ov45_0222A3EC(view->selection));
    view->render = ov49_02268490(heapId, a, b, c);
    view->task = ov49_02268FAC(work, heapId);
    view->aux = ov49_02268A0C(view->selection, view->model, heapId);
    ov49_02258BEC(view->object, a);
    flagA = ov45_0222A35C(view->selection);
    ov45_0222A324(view->selection);
    flagB = ov45_0222A374(view->selection);
    flagC = ov45_0222A3A0(view->selection);
    flagD = ov45_0222A330(view->selection);
    ov45_0222A394(view->selection);
    if (flagA == 2) {
        ov49_0225E714(view->model);
    }
    if ((flagA != 1) && (flagA == 0) && (flagC == 1)) {
        ov49_0225E760(view->model, 3);
    }
    if (flagB == 1) {
        ov49_0225E574(view->model);
    }
    if (flagD == 1) {
        ov49_02268A00(view);
    }
    return view;
}

void ov49_02268850(Ov49ViewR76 *view) {
    ov49_02268A6C(view->aux);
    ov49_02269090(view->task);
    ov49_022684F4(view->render);
    Heap_Free(view);
}

void ov49_02268870(Ov49ViewR76 *view) {
    void *value;

    if (ov45_0222A288(view->selection, 1)) {
        value = ov49_02268974(ov45_0222A3BC(view->selection));
        ov49_02268588(view->render, value);
        ov49_02258C08(view->object, value);
    }
    if (ov45_0222A288(view->selection, 2)) {
        value = ov49_022689A0(ov45_0222A3D4(view->selection));
        ov49_022685F8(view->render, value);
    }
    if (ov45_0222A288(view->selection, 3)) {
        value = ov49_022689D4(ov45_0222A3EC(view->selection));
        ov49_02268620(view->render, value);
    }
    if (ov45_0222A3A0(view->selection) == 1 && ov45_0222A35C(view->selection) == 0 && ov49_0225E824(view->model) == 0) {
        ov49_0225E760(view->model, 1);
    }
    if (ov45_0222A288(view->selection, 5) && ov45_0222A35C(view->selection) == 1) {
        ov49_0225E714(view->model);
        ov49_0225E760(view->model, 2);
    }
    if (ov45_0222A288(view->selection, 6) && ov45_0222A374(view->selection) == 1) {
        ov49_0225E574(view->model);
    }
    if (ov45_0222A330(view->selection) == 1) {
        ov49_0225E580(view->model);
        ov49_02268A00(view);
    }
    ov49_022684FC(view->render);
    ov49_02269098(view->task);
    ov49_02268A7C(view->aux);
}
