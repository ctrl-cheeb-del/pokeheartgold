#include "overlay96_particle_update_r107_private.h"

void ov96_022108BC(Ov96ParticleUpdateR107 *particle, int index, void *owner) {
    int i;
    int twice;

    MI_CpuFill8(particle, 0, sizeof(Ov96ParticleUpdateR107) * 3);
    twice = index << 1;
    for (i = 0, index += twice; i < 3; i++) {
        ov96_02210980(&particle[i], owner, index);
        index++;
    }
}

void ov96_022108EC(Ov96ParticleUpdateR107 *particle, u16 average, u16 value) {
    int i;

    for (i = 0; i < 3; i++) {
        ov96_02210AE0(&particle[i], average, value);
    }
}
