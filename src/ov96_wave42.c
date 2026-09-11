#include "ov96_wave42_private.h"
u32 ov96_021F83DC(void *w) {
    u32 i = PokeathlonCourse_GetCurrentParticipantIndex(w);
    if (PokeathlonCourse_GetMode(w) == 0) {
        i += 0xf6;
    } else {
        i += 0xf9;
    }
    return i;
}
u32 ov96_021F83FC(void *w) {
    u32 i = PokeathlonCourse_GetCurrentParticipantIndex(w);
    u8 *p = ov96_021E8A20((u8 *)PokeathlonCourse_GetDataCopyArea(w) + 0xf0);
    u32 n;
    if (*p >= 5) {
        GF_AssertFail();
    }
    if (PokeathlonCourse_GetMode(w) == 0) {
        n = 0x100 + i * 5 + *p;
    } else {
        n = 0x10f + i * 5 + *p;
    }
    return n;
}
void ov96_021F8448(Work *w) {
    XCfg24 counts = ov96_0221C2D8;
    XCfg32 oam = ov96_0221C2F0;
    XCfg20 transfer = ov96_0221C2C4;
    transfer.v[0] = 26;
    P32(w, 0x94) = SpriteSystem_Alloc(*(u32 *)w->d);
    P32(w, 0x98) = SpriteManager_New(P32(w, 0x94));
    SpriteSystem_Init(P32(w, 0x94), &oam, &transfer, 32);
    SpriteSystem_InitSprites(P32(w, 0x94), P32(w, 0x98), 2);
    SpriteSystem_InitManagerWithCapacities(P32(w, 0x94), P32(w, 0x98), &counts);
}
void ov96_021F84E4(Work *w) {
    u8 i = 0;
    void *zero = (void *)i;
    do {
        u32 off = i * 4;
        u8 *slot = (u8 *)w + off;
        void *s = *(void **)(slot + 0x9c);
        if (s != NULL) {
            Sprite_DeleteAndFreeResources(s);
            *(void **)(slot + 0x9c) = zero;
        }
        i++;
    } while (i < 2);
    SpriteSystem_FreeResourcesAndManager(P32(w, 0x94), P32(w, 0x98));
    SpriteSystem_Free(P32(w, 0x94));
}
void ov96_021F8528(Work *w) {
    void *sys = P32(w, 0x94);
    void *mgr = P32(w, 0x98);
    SpriteSystem_LoadCharResObj(sys, mgr, 0x9a, 9, 1, 2, 1000);
    SpriteSystem_LoadPlttResObj(sys, mgr, 0x9a, 8, 0, 1, 2, 1000);
    SpriteSystem_LoadCellResObj(sys, mgr, 0x9a, 10, 1, 1000);
    SpriteSystem_LoadAnimResObj(sys, mgr, 0x9a, 11, 1, 1000);
}
void ov96_021F85A0(Work *w) {
    u32 t[13] = { 0 };
    t[5] = 1000;
    t[6] = 1000;
    t[7] = 1000;
    t[8] = 1000;
    t[4] = 2;
    t[11] = 1;
    ((u16 *)t)[0] = 224;
    ((u16 *)t)[1] = 112;
    P32(w, 0x9c) = SpriteSystem_NewSprite(P32(w, 0x94), P32(w, 0x98), t);
}
BOOL ov96_021F85F4(void *course) {
    u8 *heap = PokeathlonCourse_GetHeapAllocPtr4(course);
    u8 *data = PokeathlonCourse_GetDataCopyArea(course);
    u8 *a = ov96_021E8A20(data + 0x28);
    u8 *b = ov96_021E8A20(data + 0xf0);
    u8 participant = (u8)ov96_021E5F24(course);
    u8 index = (u8) * (u32 *)(heap + 0xa4);
    BOOL active = 0;
    if (participant == 0) {
        BOOL all = 1;
        u8 *dst;
        u8 *src;
        u32 n;
        int i;
        a[1] = index;
        dst = ov96_021E8A20(data + 0x50);
        src = ov96_021E8A20(data);
        n = 0x24;
        while (n != 0) {
            *dst++ = *src++;
            n--;
        }
        i = 0;
        if (PokeathlonCourse_GetParticipantCount(course) > 0) {
            u8 *p = data + 0x50;
            do {
                u8 *r = ov96_021E8A20(p);
                if (r[0] < index || r[1] == 1) {
                    active = 1;
                }
                if (r[2] == 0) {
                    all = 0;
                }
                p += 0x28;
                i++;
            } while (i < PokeathlonCourse_GetParticipantCount(course));
        }
        if (all) {
            a[2] = 1;
        }
        a[3] = active;
    }
    a = ov96_021E8A20(data);
    a[0] = index;
    a[1] = (u8)ov96_021EEA80(*(void **)(heap + 0x18));
    a[2] = (u8) * (u32 *)(heap + 0xa8);
    if (b[3] != 0 && index >= b[1]) {
        return TRUE;
    }
    return FALSE;
}
void *ov96_021F86E8(int heap, void *a, void *b) {
    u8 *w = Heap_Alloc(heap, 0x334);
    int i;
    u8 *p;
    MI_CpuFill8(w, 0, 0x334);
    *(int *)w = heap;
    *(void **)(w + 0x10) = (void *)FontSystem_NewInit(10, heap);
    *(volatile void **)(w + 8) = a;
    *(volatile void **)(w + 4) = b;
    i = 0;
    p = w;
    do {
        *(int *)(p + 0x48) = i;
        i++;
        p += 0x48;
    } while (i < 5);
    return (void *)w;
}
void ov96_021F8728(void *arg) {
    u8 *w = arg;
    u8 *a = w;
    u8 *b = w;
    u8 *p;
    int i;
    i = 0;
    a += 0x24;
    b += 0x34;
    p = w;
    do {
        ov96_021F8E94(a);
        ov96_021F8E94(b);
        Sprite_Delete(*(void **)(p + 0x14));
        Sprite_Delete(*(void **)(p + 0x18));
        Sprite_Delete(*(void **)(p + 0x1c));
        Sprite_Delete(*(void **)(p + 0x20));
        i++;
        a += 0x48;
        b += 0x48;
        p += 0x48;
    } while (i < 5);
    i = 0;
    p = w + 0x2fc;
    do {
        sub_02013938(*(void **)(p + 0x10));
        RemoveWindow(p);
        i++;
        p += 0x18;
    } while (i < 2);
    sub_020135AC(*(void **)(w + 0x10));
    SpriteTransfer_DeleteCharTransferTask(*(void **)(w + 0x2c0));
    SpriteTransfer_DeletePlttTransferTask(*(void **)(w + 0x2c4));
    {
        u8 *q = w;
        int j = 0;
        do {
            Destroy2DGfxResObjMan(*(void **)(q + 0x2a8));
            j++;
            q += 4;
        } while (j < 6);
    }
    SpriteList_Delete(*(void **)(w + 0x17c));
    Heap_Free(w);
}
