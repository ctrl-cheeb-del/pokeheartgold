#include "overlay47_setup_r6_private.h"

void ov47_02259488(void *windows, void *messages, void *context, void *data, int heapId) {
    const u8 *template;
    u8 *window;
    int i;

    GfGfxLoader_GXLoadPalFromOpenNarc(PTR(context, 0x140), 0xc7, 0, 0, 0x80, heapId);
    GfGfxLoader_LoadCharDataFromOpenNarc(PTR(context, 0x140), 0xc8, PTR(context, 0), 0, 0, 0, 0, heapId);
    GfGfxLoader_LoadScrnDataFromOpenNarc(PTR(context, 0x140), 0xca, PTR(context, 0), 0, 0, 0, 0, heapId);

    template = ov47_02259EE8;
    window = windows;
    i = 0;
    do {
        AddWindow(PTR(context, 0), window, template);
        i++;
        template += 8;
        window += 0x10;
    } while (i < 6);

    ov47_0225999C(windows, messages, 0x6d, 0x30400);
    PTR(windows, 0x80) = GfGfxLoader_GetCharDataFromOpenNarc(PTR(context, 0x140), 0xc8, 0, (u8 *)windows + 0x84, heapId);
    ov47_02259C8C((u8 *)windows + 0x88, 1, heapId);
    ov47_02259C8C((u8 *)windows + 0xa8, 0, heapId);
    if (!ov45_0222B21C(PTR(data, 4), (u8 *)windows + 0xc8)) {
        ov47_02259DCC((u8 *)windows + 0xc8, PTR(data, 4));
        ov45_0222B1FC(PTR(data, 4), (u8 *)windows + 0xc8);
    }
    ov47_02259D74((u8 *)windows + 0xdc);
}
