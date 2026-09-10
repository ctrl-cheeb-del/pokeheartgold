#include "field_effect_animation_internal.h"

struct Work {
    int count0;
    int count1;
    int active0;
    int active1;
    void *manager;
};

struct AnimWork {
    int state;
    int counter;
    int objectId;
    int mapId;
    int unk10;
    int done;
    int offX;
    int offY;
    int offZ;
    int unk24;
    int velocity;
    int unk2C;
    int which;
    int model;
    Work *effects;
    void *mapObject;
    void *renderObj;
};
void *ov01_022001E4(void *arg) {
    Work *w = ov01_021F1430(arg, 0x14, 0, 0);
    w->manager = arg;
    return w;
}
void ov01_022001F8(Work *w) {
    ov01_022002FC(w);
    ov01_021F1448(w);
}
void ov01_02200208(Work *w) {
    w->count0++;
}
void ov01_02200210(Work *w) {
    if (--w->count0 < 0) {
        GF_AssertFail();
    }
}
void ov01_02200220(Work *w) {
    w->count1++;
}
void ov01_02200228(Work *w) {
    if (--w->count1 < 0) {
        GF_AssertFail();
    }
}
void ov01_02200238(Work *w, int which) {
    if (which == 0) {
        ov01_02200208(w);
    } else {
        ov01_02200220(w);
    }
}
void ov01_0220024C(Work *w, int which) {
    if (which == 0) {
        ov01_02200210(w);
    } else {
        ov01_02200228(w);
    }
}
void ov01_02200260(Work *w) {
    if (w->active0 == 0) {
        w->active0 = 1;
        ov01_021F18D4(w->manager, 1, 0x76);
        ov01_021F1908(w->manager, 1, 0x8c);
        ov01_021F1930(w->manager, 1, 0x11, 1);
        ov01_021F1758(w->manager, 1, 1, 1, 1, 0, ov01_022092F0);
    }
}
void ov01_022002AC(Work *w) {
    if (w->active1 == 0) {
        w->active1 = 1;
        ov01_021F18D4(w->manager, 10, 0x7d);
        ov01_021F1908(w->manager, 10, 0x8c);
        ov01_021F1930(w->manager, 11, 0x18, 1);
        ov01_021F1758(w->manager, 12, 10, 10, 11, 0, ov01_022092F0);
    }
}
void ov01_022002FC(Work *w) {
    if (w->active0 == 1) {
        w->active0 = 0;
        ov01_021F18FC(w->manager, 1);
        ov01_021F1924(w->manager, 1);
        ov01_021F1970(w->manager, 1);
        ov01_021F18C8(w->manager, 1);
    }
}
void ov01_0220032C(Work *w) {
    if (w->active1 == 1) {
        w->active1 = 0;
        ov01_021F18FC(w->manager, 10);
        ov01_021F1924(w->manager, 10);
        ov01_021F1970(w->manager, 11);
        ov01_021F18C8(w->manager, 12);
    }
}
void ov01_0220035C(Work *w) {
    if (w->count0 == 0) {
        ov01_02200260(w);
    }
}
void ov01_0220036C(Work *w) {
    if (w->count1 == 0) {
        ov01_022002AC(w);
    }
}
void ov01_0220037C(Work *w) {
    if (w->count0 == 0) {
        ov01_022002FC(w);
    }
}
void ov01_0220038C(Work *w) {
    if (w->count1 == 0) {
        ov01_0220032C(w);
    }
}
void ov01_0220039C(Work *w, int which) {
    if (which == 0) {
        ov01_0220035C(w);
    } else {
        ov01_0220036C(w);
    }
}
void ov01_022003B0(Work *w, int which) {
    if (which == 0) {
        ov01_0220037C(w);
    } else {
        ov01_0220038C(w);
    }
}
void *ov01_022003C4(void *manager, int which, Vec3 *pos) {
    int ids[2] = { 1, 12 };
    void *obj = ov01_021F1740(manager, ids[which], pos);
    void *mdl = sub_02023F90(obj);
    NNS_G3dMdlSetMdlFogEnableFlagAll(mdl, 0);
    return obj;
}
void *ov01_022003F4(void) {
    return *(void **)(sub_02068D74() + 0x14);
}
void ov01_02200400(void) {
    u8 *p = sub_02068D74();
    *(int *)(p + 0x10) = 1;
    if (*(void **)(p + 0x40) != NULL) {
        sub_02023EA4(*(void **)(p + 0x40), 0);
    }
}

int ov01_02200418(void *task, AnimWork *w) {
    Vec3 pos;
    *(Vec4 *)((u8 *)w + 0x30) = *sub_02068D98(task);
    w->velocity = 0x6000;
    ov01_0220039C(w->effects, w->which);
    sub_02068DB8(task, &pos);
    w->renderObj = ov01_022003C4((void *)w->model, w->which, &pos);
    ov01_02200238(w->effects, w->which);
    sub_02023EA4(w->renderObj, 0);
    if (sub_02068D90(task) == 1) {
        PlaySE(SEQ_SE_DP_DECIDE);
    }
    return 1;
}
void ov01_02200480(void *task, AnimWork *w) {
    Vec3 pos;
    sub_02068DB8(task, &pos);
    switch (w->state) {
    case 0:
        sub_02023EA4(w->renderObj, 1);
        w->offY += w->velocity;
        if (w->offY != 0) {
            w->velocity -= 0x2000;
        } else {
            w->velocity = 0;
            w->state++;
        }
        break;
    case 1:
        w->counter++;
        if (w->counter >= 30) {
            w->state++;
            w->counter = 0;
            w->done = 1;
        }
        break;
    case 2:
        break;
    }
    sub_02068DA8(task, &pos);
}
void ov01_022004EC(void *task, AnimWork *w) {
    sub_02023DA4(w->renderObj);
    ov01_0220024C(w->effects, w->which);
    ov01_022003B0(w->effects, w->which);
}
void ov01_02200508(void *task, AnimWork *w) {
    Vec3 pos;
    if (w->unk10 != 1) {
        sub_02068DB8(task, &pos);
        pos.x += w->offX;
        pos.y += w->offY;
        pos.z += w->offZ;
        sub_02023E50(w->renderObj, &pos);
    }
}
int ov01_02200540(void *obj, int a1, int a2) {
    int priority;
    u8 args[16];
    Vec3 pos;
    Vec3 facing;
    void *manager = ov01_021F146C(obj);
    *(int *)(args + 0) = a1;
    *(void **)(args + 4) = manager;
    *(void **)(args + 8) = ov01_021F1450(manager, 9);
    *(void **)(args + 12) = obj;
    MapObject_CopyPositionVector(obj, &pos);
    MapObject_CopyFacingVector(obj, &facing);
    VEC_Add(&pos, &facing, &pos);
    priority = MapObject_GetPriority(obj) + 1;
    ov01_021F1620(manager, ov01_022092DC, &pos, a2, args, priority);
}
int ov01_0220059C(void *task, AnimWork *w) {
    Vec3 pos;
    *(Vec4 *)((u8 *)w + 0x30) = *sub_02068D98(task);
    w->objectId = MapObject_GetID(w->mapObject);
    w->mapId = MapObject_GetMapID(w->mapObject);
    w->velocity = 0x6000;
    ov01_0220039C(w->effects, w->which);
    sub_02068DB8(task, &pos);
    w->renderObj = ov01_022003C4((void *)w->model, w->which, &pos);
    ov01_02200238(w->effects, w->which);
    sub_02023EA4(w->renderObj, 0);
    if (sub_02068D90(task) == 1) {
        PlaySE(SEQ_SE_DP_DECIDE);
    }
    return 1;
}
void ov01_02200614(void *task, AnimWork *w) {
    Vec3 pos;
    void *obj = w->mapObject;
    if (sub_0205F0A8(obj, w->objectId, w->mapId) == 0) {
        GF_AssertFail();
    }
    ov01_021F93AC(obj, &pos);
    pos.y += 0x20000;
    pos.z += 0x1000;
    switch (w->state) {
    case 0:
        sub_02023EA4(w->renderObj, 1);
        w->offY += w->velocity;
        if (w->offY != 0) {
            w->velocity -= 0x2000;
        } else {
            w->velocity = 0;
            w->state++;
        }
        break;
    case 1:
        w->counter++;
        if (w->counter >= 30) {
            w->state++;
            w->counter = 0;
            w->done = 1;
        }
        break;
    case 2:
        break;
    }
    sub_02068DA8(task, &pos);
}
