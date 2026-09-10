#include "global.h"

#include "heap.h"
#include "vram_transfer_manager.h"
typedef struct TextureAnimation {
    void *resource;
    NNSG3dResTex *texture;
    u32 textureKey;
    u32 paletteKey;
    u8 textureIndex;
    u8 paletteIndex;
} TextureAnimation;
typedef struct TextureAnimationPool {
    TextureAnimation *animations;
    int count;
} TextureAnimationPool;
typedef struct TextureFrame {
    u8 texture;
    u8 palette;
} TextureFrame;
void *NNS_G3dGetResDataByName(const NNSG3dResDict *, const NNSG3dResName *);
u32 sub_02026DE0(void *, u32);
void sub_02020B3C(NNSG3dResName *, const char *);
TextureAnimationPool *sub_0202068C(int count, enum HeapID heapID);
void sub_020206C8(TextureAnimationPool *pool);
TextureAnimation *sub_020206E0(TextureAnimationPool *pool, void *resource, NNSG3dResTex *texture, u32 textureKey, u32 paletteKey, fx32 frame);
void sub_02020738(TextureAnimation *animation);
void sub_02020740(TextureAnimationPool *pool);
void sub_02020764(TextureAnimation *animation, fx32 frame);
void sub_02020770(TextureAnimation *animation);
void sub_02020780(TextureAnimation *animation, u16 frame);
void sub_020207C8(TextureAnimation *animation, TextureFrame *indices);
void sub_020207F4(TextureAnimation *animation, TextureFrame *indices);
void *sub_02020820(TextureAnimation *animation, TextureFrame *indices);
void *sub_0202082C(TextureAnimation *animation, TextureFrame *indices);
void *sub_02020838(NNSG3dResTex *texture, u32 index);
void *sub_02020888(NNSG3dResTex *texture, u32 index);
u32 sub_020208CC(NNSG3dResTex *texture, u32 *entry);
u32 sub_020208DC(NNSG3dResTex *texture, const char *name);
u32 sub_02020910(NNSG3dResTex *texture, u32 index);
u32 sub_0202094C(NNSG3dResTex *texture, u32 *entry);
u32 sub_020209AC(NNSG3dResTex *texture, u32 index);
u32 sub_020209E0(NNSG3dResTex *texture, const char *name);
TextureAnimationPool *sub_0202068C(int count, enum HeapID heapID) {
    TextureAnimationPool *pool = Heap_Alloc(heapID, sizeof(*pool));
    int i;
    pool->animations = Heap_Alloc(heapID, sizeof(TextureAnimation) * count);
    pool->count = count;
    for (i = 0; i < pool->count; i++) {
        sub_02020770(&pool->animations[i]);
    }
    return pool;
}
void sub_020206C8(TextureAnimationPool *pool) {
    sub_02020740(pool);
    Heap_Free(pool->animations);
    Heap_Free(pool);
}
TextureAnimation *sub_020206E0(TextureAnimationPool *pool, void *resource, NNSG3dResTex *texture, u32 textureKey, u32 paletteKey, fx32 frame) {
    TextureAnimation *animation = NULL;
    int i;
    for (i = 0; i < pool->count; i++) {
        if (pool->animations[i].resource == NULL) {
            animation = &pool->animations[i];
            break;
        }
    }
    if (animation == NULL) {
        return NULL;
    }
    animation->resource = resource;
    animation->texture = texture;
    animation->textureKey = textureKey;
    animation->paletteKey = paletteKey;
    animation->textureIndex = 255;
    animation->paletteIndex = 255;
    sub_02020780(animation, (u16)(frame >> 12));
    return animation;
}
void sub_02020738(TextureAnimation *animation) {
    sub_02020770(animation);
}
void sub_02020740(TextureAnimationPool *pool) {
    int i;
    for (i = 0; i < pool->count; i++) {
        sub_02020770(&pool->animations[i]);
    }
}
void sub_02020764(TextureAnimation *animation, fx32 frame) {
    sub_02020780(animation, (u16)(frame >> 12));
}
void sub_02020770(TextureAnimation *animation) {
    animation->resource = NULL;
    animation->texture = NULL;
    animation->textureKey = 0;
    animation->paletteKey = 0;
    animation->textureIndex = 0;
    animation->paletteIndex = 0;
}
void sub_02020780(TextureAnimation *animation, u16 frame) {
    u32 packed = sub_02026DE0(animation->resource, frame);
    TextureFrame indices, initial;
    initial.texture = packed;
    initial.palette = packed >> 8;
    indices = initial;
    if (animation->textureIndex != indices.texture) {
        sub_020207C8(animation, &indices);
    }
    if (animation->paletteIndex != indices.palette) {
        sub_020207F4(animation, &indices);
    }
}
void sub_020207C8(TextureAnimation *animation, TextureFrame *indices) {
    void *data = sub_02020820(animation, indices);
    u32 key = animation->textureKey;
    GF_CreateNewVramTransferTask((NNS_GFD_DST_TYPE)0, (key & 0xFFFF) << 3, data, ((key & 0x7FFF0000) >> 16) << 4);
    animation->textureIndex = indices->texture;
}
void sub_020207F4(TextureAnimation *animation, TextureFrame *indices) {
    void *data = sub_0202082C(animation, indices);
    u32 key = animation->paletteKey;
    GF_CreateNewVramTransferTask((NNS_GFD_DST_TYPE)1, (key & 0xFFFF) << 3, data, ((key & 0xFFFF0000) >> 16) << 3);
    animation->paletteIndex = indices->palette;
}
void *sub_02020820(TextureAnimation *animation, TextureFrame *indices) {
    return sub_02020838(animation->texture, indices->texture);
}
void *sub_0202082C(TextureAnimation *animation, TextureFrame *indices) {
    return sub_02020888(animation->texture, indices->palette);
}
void *sub_02020838(NNSG3dResTex *texture, u32 index) {
    u32 *entry = texture ? NNS_G3dGetResDataByIdx(&texture->dict, index) : NULL;
    if (entry == NULL) {
        return NULL;
    }
    return (u8 *)texture + texture->texInfo.ofsTex + (((*entry & 0xFFFF) + texture->texInfo.vramKey) << 3);
}
void *sub_02020888(NNSG3dResTex *texture, u32 index) {
    u16 *entry;
    if (texture && texture->plttInfo.ofsDict) {
        entry = NNS_G3dGetResDataByIdx((NNSG3dResDict *)((u8 *)texture + texture->plttInfo.ofsDict), index);
    } else {
        entry = NULL;
    }
    if (entry == NULL) {
        return NULL;
    }
    return (u8 *)texture + texture->plttInfo.ofsPlttData + (*entry << 3);
}
u32 sub_020208CC(NNSG3dResTex *texture, u32 *entry) {
    return ((*entry << 16) >> 13) + ((texture->texInfo.vramKey << 16) >> 13);
}
u32 sub_020208DC(NNSG3dResTex *texture, const char *name) {
    NNSG3dResName key;
    u32 *entry;
    sub_02020B3C(&key, name);
    entry = texture ? NNS_G3dGetResDataByName(&texture->dict, &key) : NULL;
    if (entry == NULL) {
        return 0;
    }
    return sub_020208CC(texture, entry);
}
u32 sub_02020910(NNSG3dResTex *texture, u32 index) {
    u32 *entry = texture ? NNS_G3dGetResDataByIdx(&texture->dict, index) : NULL;
    if (entry == NULL) {
        return 0;
    }
    return sub_020208CC(texture, entry);
}
u32 sub_0202094C(NNSG3dResTex *texture, u32 *entry) {
    u32 packed = *entry;
    u32 divisor;
    switch ((packed & (7 << 26)) >> 26) {
    case 2:
        divisor = 4;
        break;
    case 3:
        divisor = 2;
        break;
    case 4:
        divisor = 1;
        break;
    case 1:
        divisor = 1;
        break;
    case 6:
        divisor = 1;
        break;
    default:
        return 0;
    }
    return ((((packed & (7 << 20)) >> 20) << 4) * (((packed & (7 << 23)) >> 23) << 4)) / divisor;
}
u32 sub_020209AC(NNSG3dResTex *texture, u32 index) {
    u32 *entry = texture ? NNS_G3dGetResDataByIdx(&texture->dict, index) : NULL;
    return sub_0202094C(texture, entry);
}
u32 sub_020209E0(NNSG3dResTex *texture, const char *name) {
    NNSG3dResName key;
    u32 *entry;
    sub_02020B3C(&key, name);
    entry = texture ? NNS_G3dGetResDataByName(&texture->dict, &key) : NULL;
    return sub_0202094C(texture, entry);
}
