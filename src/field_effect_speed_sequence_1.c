#include "field_effect_speed_sequence_internal.h"
typedef struct LocalThreeWords {
    u32 v[3];
} LocalThreeWords;
typedef struct LocalFiveWords {
    fx32 v[5];
} LocalFiveWords;
extern const u32 ov01_02209084[], ov01_022090AC[];
LocalManager *ov01_021FE590(void *owner) {
    LocalManager *m = ov01_021F1430(owner, 12, 0, 0);
    m->owner = owner;
    return m;
}
void ov01_021FE5A4(LocalManager *m) {
    ov01_021FE61C(m);
    ov01_021F1448(m);
}
void ov01_021FE5B4(LocalManager *m) {
    m->refs++;
}
void ov01_021FE5BC(LocalManager *m) {
    m->refs--;
    if (m->refs < 0) {
        GF_AssertFail();
    }
}
void ov01_021FE5CC(LocalManager *m) {
    if (m->active == 0) {
        m->active = 1;
        ov01_021F18D4(m->owner, 11, 0x80);
        ov01_021F1908(m->owner, 11, 0x95);
        ov01_021F1930(m->owner, 12, 0x1a, 1);
        ov01_021F1758(m->owner, 13, 11, 11, 12, 0, ov01_022090AC);
    }
}
void ov01_021FE61C(LocalManager *m) {
    if (m->active == 1) {
        m->active = 0;
        ov01_021F18FC(m->owner, 11);
        ov01_021F1924(m->owner, 11);
        ov01_021F1970(m->owner, 12);
        ov01_021F18C8(m->owner, 13);
    }
}
void ov01_021FE64C(LocalManager *m) {
    if (m->refs == 0) {
        ov01_021FE5CC(m);
    }
}
void ov01_021FE65C(LocalManager *m) {
    if (m->refs == 0) {
        ov01_021FE61C(m);
    }
}
void ov01_021FE66C(void *obj) {
    struct {
        LocalManager *manager;
        void *resource;
        u32 pad10;
        VecFx32 pos;
    } local;
    LocalManager *m = ov01_021F146C(obj);
    ov01_021F93AC(obj, &local.pos);
    local.pos.z += 2 << 14;
    local.manager = m;
    local.resource = ov01_021F1450(m, 16);
    ov01_021F1620(m, ov01_02209084, &local.pos, 0, &local, 0xff);
}
BOOL ov01_021FE6B4(void *task, LocalState *s) {
    VecFx32 pos;
    *(LocalThreeWords *)&s->resource = *(LocalThreeWords *)sub_02068D98(task);
    ov01_021FE64C(s->manager);
    sub_02068DB8(task, &pos);
    s->effect = ov01_021F1740(s->resource, 13, &pos);
    ov01_021FE5B4(s->manager);
    return TRUE;
}
void ov01_021FE6F4(void *task, LocalState *s) {
    sub_02023DA4(s->effect);
    ov01_021FE5BC(s->manager);
    ov01_021FE65C(s->manager);
}
void ov01_021FE70C(void *task, LocalState *s) {
    static const LocalFiveWords init = {
        { FX32_ONE, FX32_ONE, 2 * FX32_ONE, 2 * FX32_ONE, FX32_ONE }
    };
    LocalFiveWords values = init;
    if (s->finished == 1) {
        s->finished = 0;
        s->index++;
        if (s->index >= 5) {
            ov01_021F1640(task);
            return;
        }
        sub_02023F1C(s->effect, 0);
    }
    if (sub_02023F04(s->effect, values.v[s->index]) == TRUE) {
        s->finished = 1;
    }
}
void ov01_021FE768(void *task, LocalState *s) {
    VecFx32 pos;
    sub_02068DB8(task, &pos);
    sub_02023E50(s->effect, &pos);
}
