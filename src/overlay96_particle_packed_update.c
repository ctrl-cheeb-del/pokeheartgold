#include "overlay96_particle_packed_update_private.h"

void ov96_0220FE38(Ov96R102Particle *particle, Ov96R102Packed *packed, void *context) {
    s16 point[4];

    if (particle->enabled) {
        goto enabled;
    }
    goto done;
enabled: {
    switch (particle->state) {
    case 1:
        if (ov96_0220FBEC(particle, context, point)) {
            ov96_0220FD28(particle, context, point);
        } else if (particle->counter >= 480) {
            particle->counter = 0;
            particle->state = 2;
        } else {
            particle->counter += particle->speed;
            particle->value = ov96_0220E6DC(particle->counter, particle->type);
        }
        break;
    case 2:
        particle->counter += particle->speed;
        if (particle->counter >= 48) {
            ov96_0220FBDC(particle);
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        particle->timer++;
        if (particle->timer >= 20) {
            ov96_0220FBDC(particle);
        }
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }

    packed->counter = (particle->counter << 1) / 8;
    packed->type = particle->type;
    packed->state = particle->state;
    packed->low = particle->low;
}
done:;
}
