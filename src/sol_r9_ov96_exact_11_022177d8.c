#include "global.h"

#include "gf_gfx_planes.h"

typedef struct SolR9Ui {
    void *unk00;
    void *unk10;
    void *spriteSystem;
    void *spriteManager;
    void *mainSprite;
    void *unk14;
    void *unk18;
} SolR9Ui;

extern const GraphicsBanks ov96_0221D774;
extern const u32 ov96_0221D738[];
extern void *PokeathlonCourse_GetDataCopyArea(void *course);
extern void *PokeathlonCourse_GetHeapAllocPtr4(void *course);
extern void *ov96_021E8A20(void *p);
extern u16 ov96_0221978C(void *p);
extern void ov96_021E8318(void *course, u16 value);
extern void ov96_022193F8(void *course, u8 value);
extern void ov96_021E9C0C(void *p);
extern void SpriteSystem_FreeResourcesAndManager(void *system, void *manager);
extern void SpriteSystem_Free(void *system);
extern void RemoveWindow(void *window);
extern void MessageFormat_Delete(void *format);
extern void DestroyMsgData(void *msgData);
extern void FreeBgTilemapBuffer(void *bgConfig, u8 bgId);
extern void FontID_Release(int fontId);
extern void Heap_Free(void *p);
extern void Sprite_DeleteAndFreeResources(void *sprite);
extern void ManagedSprite_SetAnimateFlag(void *sprite, int flag);
extern int ov96_022186CC(int value);
void ov96_02215FA8(void);
void ov96_02216200(void *course);
void ov96_02216390(SolR9Ui *p);
void ov96_022165FC(u8 *p);
int ov96_02216C00(const u8 *a, const u8 *b);
int ov96_02216C1C(const u8 *a, const u8 *b);
void ov96_022177D8(u8 *p);
void ov96_02217820(u8 *p);
void ov96_02217868(u8 *p, int value);

void ov96_022177D8(u8 *p) {
    int i;
    int j;
    u8 *q;
    GF_ASSERT(*(void **)(p + 4) != NULL);
    GF_ASSERT(*(void **)(p + 8) != NULL);
    GF_ASSERT(*(void **)(p + 0xC) != NULL);
    Sprite_DeleteAndFreeResources(*(void **)(p + 0xC));
    i = 0;
    p += 0x10;
    for (; i < 4; i++, p += 0xE8) {
        j = 0;
        q = p;
        for (; j < 5; j++, q += 4) {
            Sprite_DeleteAndFreeResources(*(void **)(q + 4));
        }
    }
}
