#include "field_ui_863f4_internal.h"

#define PTR(s, off, type) (*(type **)&(s)->raw[(off)])
#define S32(s, off)       (*(int *)&(s)->raw[(off)])
#define S16(s, off)       (*(s16 *)&(s)->raw[(off)])
#define U8(s, off)        ((s)->raw[(off)])

void sub_020863F4(ModuleState *state) {
    Config32 config32;
    Config20 config20;
    PTR(state, 0x2f0, SpriteSystem) = SpriteSystem_Alloc(0x6c);
    config32 = _021027F4;
    config20 = _021027C8;
    SpriteSystem_Init(PTR(state, 0x2f0, SpriteSystem), &config32, &config20, 0x20);
    {
        Config24 config24 = _021027DC;
        PTR(state, 0x2f4, SpriteManager) = SpriteManager_New(PTR(state, 0x2f0, SpriteSystem));
        if (!SpriteSystem_InitSprites(PTR(state, 0x2f0, SpriteSystem), PTR(state, 0x2f4, SpriteManager), 0x80)) {
            GF_AssertFail();
        }
        if (!SpriteSystem_InitManagerWithCapacities(PTR(state, 0x2f0, SpriteSystem), PTR(state, 0x2f4, SpriteManager), &config24)) {
            GF_AssertFail();
        }
    }
}
