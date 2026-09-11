#include "overlay05_task_internal.h"

void ov05_0221BA00(void *arg) {
    u8 *a = arg;
    SysTask *task = CreateSysTaskAndEnvironment(ov05_0221BA70, 0xBD4, 0x64, (enum HeapID) * (u32 *)(a + 0x24));
    u8 *w = SysTask_GetData(task);
    memset(w, 0, 0xBD4);
    *(void **)w = arg;
    w[0xB7F] = 0;
    *(u32 *)(w + 0xBC8) = sub_020304B4();
    if (*(u32 *)(w + 0xBC8) == 1) {
        void *field = *(void **)w;
        void *save = *(void **)field;
        if (save != 0 && *(void **)((u8 *)save + 0x1C0) != 0) {
            void *bag = Save_Bag_Get(*(SaveData **)((u8 *)save + 0x1C0));
            *(u32 *)(w + 0xBC8) = Bag_HasItem(bag, 0x1D1, 1, (enum HeapID) * (u32 *)(a + 0x24));
        }
    }
}

void ov05_0221BA70(SysTask *task, void *data) {
    u8 *w = data;
    int result;
    switch (w[0xB7F]) {
    case 0:
        w[0xB7F] = ov05_0221BD28(w);
        break;
    case 1:
        do {
            int (**funcs)(void *) = *(int (***)(void *))(w + 4);
            result = funcs[w[0xB80]](w);
            if (result != 0) {
                w[0xB80]++;
            }
        } while (result == 2);
        if ((*((u8 **)w))[0x28] == 2) {
            ov05_0221BB30(w);
        }
        break;
    case 2:
        if (ov05_0221CC74(task, data) == 1) {
            return;
        }
        break;
    }
    if (w[0xB80] != 0) {
        ov05_0221CE50(w);
        SpriteSystem_DrawSprites(*(void **)(w + 0x194));
    }
    if ((*((u8 **)w))[0x28] != 0) {
        *(volatile u32 *)0x04000540 = 1;
    }
}
