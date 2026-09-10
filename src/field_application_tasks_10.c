#include "field_application_tasks_internal.h"

void sub_0205A07C(void *p) {
    int count = *(int *)((u8 *)p + 0x14);
    if (count != 0) {
        *(int *)((u8 *)p + 0x14) = count - 1;
        return;
    }
    sub_02038094();
    sub_0205A034(p, sub_0205A0A0, 0);
}

void sub_0205A0A0(void *p) {
    if (sub_02037474() == 0) {
        sub_0205A1D4(p);
    }
}

void sub_0205A0B4(void *p) {
    u8 *data = p;
    if (sub_02037F94() == TRUE) {
        sub_02034434();
        sub_0205A034(p, sub_0205A144, 3);
        return;
    }
    if (sub_020376F8() != 0) {
        *(u32 *)(data + 0x20) = 0;
        *(u32 *)(data + 0x1C) = 3;
        sub_0205A034(p, sub_02059F78, 0);
    }
    if (sub_02037F94() != 0) {
        sub_0205A034(p, sub_0205A114, 2);
        *(u32 *)(data + 0x24) = 0;
        *(u32 *)(data + 0x1C) = 2;
        *(u32 *)(data + 0x20) = 0;
        *(u32 *)(data + 0x44) = 0;
    }
}

void sub_0205A114(void *p) {
    if (FieldSystem_TaskIsRunning(*(void **)p) == 0) {
        sub_02037FF0();
        sub_0205ABBC(p);
        sub_0205A904(0);
        sub_0205A034(p, sub_02059F30, 2);
    }
}

void sub_0205A144(void *p) {
    u8 *data = p;
    if (sub_02037F94() == TRUE) {
        if (sub_02034818(sub_0203769C()) != 0) {
            *(u32 *)(data + 0x20) = 0;
            *(u32 *)(data + 0x1C) = 1;
            *(u32 *)(data + 0x44) = 0;
            sub_020398D4(1, 1);
            sub_0205A034(p, sub_0205A1AC, 3);
        }
    } else if (sub_02037F94() == 0) {
        sub_02037FF0();
        sub_0205ABBC(p);
        sub_0205A034(p, sub_02059F30, 2);
        *(u32 *)(data + 0x24) = 0;
        *(u32 *)(data + 0x1C) = 2;
        *(u32 *)(data + 0x20) = 0;
        *(u32 *)(data + 0x44) = 0;
    }
}

void sub_0205A1AC(void *p) {
    if (sub_02037F94() == 0) {
        sub_02037FF0();
        sub_0205ABBC(p);
        sub_0205A034(p, sub_02059F30, 2);
    }
}

void sub_0205A1D4(void *p) {
    if (p != NULL) {
        SysTask_Destroy(*(void **)((u8 *)p + 0xC));
        Heap_Free(p);
        Heap_Destroy(0x1F);
    }
}

u32 sub_0205A1F0(const void *p) {
    return *(const u32 *)p;
}

void *sub_0205A1F4(void *p, int index) {
    return *(void **)((u8 *)p + 0x110 + index * 4);
}
