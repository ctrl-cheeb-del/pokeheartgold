#include "overlay96_particle_manager_r39_private.h"

void ov96_021ECDEC(Ov96R39Particle *particle, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    ManagedSpriteTemplate template;
    u32 value;
    s32 offset;
    float floatValue;

    if (particle == NULL) {
        GF_AssertFail();
    }
    MI_CpuFill8(particle, 0, sizeof(*particle));

    value = MTRandom() % 5;
    if (value != 0) {
        value = MTRandom() % 5;
        floatValue = (float)(value << 12) + 0.5f;
    } else {
        value = MTRandom() % 5;
        floatValue = (float)(value << 12) - 0.5f;
    }
    offset = (s32)floatValue;
    particle->yVelocity = (offset >> 1) + 0x1800;

    if (MTRandom() & 1) {
        value = MTRandom() & 1;
        floatValue = (float)(value << 12) + 0.5f;
    } else {
        value = MTRandom() & 1;
        floatValue = (float)(value << 12) - 0.5f;
    }
    particle->xVelocity = ((s32)floatValue + 0x19A) >> 1;

    if ((MTRandom() & 0xFF) != 0) {
        value = MTRandom() & 0xFF;
        floatValue = (float)(value << 12) + 0.5f;
    } else {
        value = MTRandom() & 0xFF;
        floatValue = (float)(value << 12) - 0.5f;
    }
    particle->x = (s32)floatValue;

    particle->state.speed = MTRandom() % 5 + 1;
    particle->state.active = TRUE;
    template = ov96_0221B0BC;
    template.x = particle->x >> 12;
    if (!(MTRandom() & 1)) {
        template.animation = 12;
    }
    particle->sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, 0x20C000);
    ManagedSprite_SetAnimateFlag(particle->sprite, TRUE);
}

BOOL ov96_021ECF48(Ov96R39Particle *particle) {
    BOOL result = FALSE;
    s64 velocity;
    s64 sine;
    fx32 xVelocity;

    if (particle == NULL) {
        GF_AssertFail();
    }
    xVelocity = particle->xVelocity;
    sine = GF_SinDeg(particle->state.angle * particle->state.speed);
    velocity = sine * xVelocity;
    particle->x += (velocity + 0x800) >> 12;
    particle->y += particle->yVelocity;
    ManagedSprite_SetPositionFxXYWithSubscreenOffset(particle->sprite, particle->x, particle->y, 0x20C000);
    if ((particle->y >> 12) > 224) {
        if (particle->state.destroy) {
            particle->state.active = FALSE;
            Sprite_DeleteAndFreeResources(particle->sprite);
            particle->sprite = NULL;
        } else {
            particle->state.destroy = TRUE;
            result = TRUE;
        }
    }
    particle->state.angle += MTRandom() & 1;
    return result;
}

void ov96_021ECFF8(Ov96R39Particle *particle, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    ManagedSpriteTemplate template = ov96_0221B0F0;

    particle->y = 0;
    template.animation = ManagedSprite_GetActiveAnim(particle->sprite) - 11;
    template.x = particle->x >> 12;
    template.y = particle->y >> 12;
    Sprite_DeleteAndFreeResources(particle->sprite);
    particle->sprite = SpriteSystem_NewSpriteWithYOffset(spriteSystem, spriteManager, &template, 0x20C000);
    ManagedSprite_SetAnimateFlag(particle->sprite, TRUE);
}

Ov96R39Manager *ov96_021ED054(u32 heapId, SpriteSystem *spriteSystem, SpriteManager *spriteManager) {
    Ov96R39Manager *manager;

    if (spriteSystem == NULL) {
        GF_AssertFail();
    }
    if (spriteManager == NULL) {
        GF_AssertFail();
    }
    manager = Heap_Alloc((enum HeapID)heapId, sizeof(*manager));
    MI_CpuFill8(manager, 0, sizeof(*manager));
    manager->heapId = heapId;
    manager->spriteSystem = spriteSystem;
    manager->spriteManager = spriteManager;
    manager->delay = ov96_021ED6E8();
    return manager;
}

void ov96_021ED09C(Ov96R39Manager *manager) {
    int i;
    Ov96R39Particle *particle;

    if (manager == NULL) {
        GF_AssertFail();
    }
    particle = (Ov96R39Particle *)manager;
    for (i = 0; i < 15; i++, particle++) {
        if (particle->xVelocity != 0) {
            Sprite_DeleteAndFreeResources((ManagedSprite *)particle->xVelocity);
            particle->xVelocity = 0;
        }
    }
    Heap_Free(manager);
}

void ov96_021ED0C8(Ov96R39Manager *manager) {
    int i;
    Ov96R39Particle *particle;
    Ov96R39Flags *flags;

    if (manager == NULL) {
        GF_AssertFail();
    }
    if (manager->threshold != 0) {
        if (manager->timer++ > manager->delay) {
            ov96_021ED17C(manager, (MTRandom() & 1) + 2);
            manager->delay = ov96_021ED6E8();
            manager->timer = 0;
        }
    }
    i = 0;
    flags = &manager->particles[0].state;
    particle = manager->particles;
    for (; i < 15; i++, flags = (Ov96R39Flags *)((u8 *)flags + sizeof(Ov96R39Particle)), particle++) {
        if (flags->active == TRUE && ov96_021ECF48(particle)) {
            ov96_021ECFF8(particle, manager->spriteSystem, manager->spriteManager);
        }
    }
}

void ov96_021ED158(Ov96R39Manager *manager, u32 threshold) {
    manager->threshold = threshold;
    GfGfxLoader_GXLoadPal(0x9A, 12, 1, 0x160, 0x20, manager->heapId);
}
