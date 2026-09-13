#include "overlay96_pokeathlon_course_motion_r79_private.h"

void ov96_021FEAEC(u8 *work, int value) {
    u8 i;

    for (i = 0; i < 30; i++) {
        u8 *slot = work + i * 12;
        VecFx32 vec;
        int x;
        u8 y;

        if (*(void **)(slot + 0x4D4) == NULL) {
            break;
        }
        y = slot[0x4DE];
        x = value - *(u16 *)(slot + 0x4DC);
        if ((double)x >= 768.0) {
            x = (int)(80.0 + (1024.0 - (double)x));
        } else if ((double)x <= -768.0) {
            x = (int)(80.0 - (1024.0 + (double)x));
        } else {
            x = 80 - x;
        }
        vec.z = 0;
        vec.x = x << 12;
        vec.y = (y + 32) << 12;
        ov96_021EB588(*(void **)(slot + 0x4D8), &vec);
        if (x >= -32 && x <= 288) {
            ov96_021EB52C(*(void **)(slot + 0x4D8), 1, 1);
        } else {
            ov96_021EB52C(*(void **)(slot + 0x4D8), 1, 0);
        }
    }
}

void ov96_021FEBF0(void *course, u8 *work, VecFx32 *position, int mode, u8 participant, u8 *result, BOOL checkA, BOOL checkB) {
    VecFx32 vec;

    switch (work[0xA0]) {
    case 0:
        ov96_021EB588(*(void **)(work + 0x74), position);
        ov96_021EB588(*(void **)(work + 0x70), position);
        ov96_021EB52C(*(void **)(work + 0x70), 1, 1);
        ov96_021EB564(*(void **)(work + 0x70), 8);
        ov96_021EB52C(*(void **)(work + 0x74), 1, 1);
        ov96_021EAB38(*(void **)(work + participant * 4), 0);
        *(u32 *)(work + 0xC8) = 1;
        work[0xA1] = 0;
        ov96_021FFE38(position->x / 0x1000, 0x8B4, checkB);
        work[0xA0]++;
        break;
    case 1:
        vec = *(VecFx32 *)ov96_021EB594(*(void **)(work + 0x74));
        vec.y -= 0x14000;
        vec.x = position->x;
        ov96_021EB588(*(void **)(work + 0x74), &vec);
        ov96_021EB588(*(void **)(work + 0x70), position);
        work[0xA1]++;
        if (work[0xA1] >= 20) {
            work[0xA0]++;
        }
        break;
    case 2:
        if (checkB != 0) {
            if (ov96_022006BC(course, participant)) {
                result[8] = 1;
                work[0xA0]++;
            }
        } else if (checkA != 0) {
            if (ov96_02200900(course, mode)) {
                result[8] = 1;
                work[0xA0]++;
            }
        } else {
            work[0xA0]++;
        }
        break;
    case 3:
        break;
    }
}

void ov96_021FED3C(u8 *work, VecFx32 *position, int unused, u8 participant, u8 *result, BOOL flag, BOOL sound) {
    switch (work[0xA0]) {
    case 0: {
        VecFx32 vec;
        vec = *position;
        vec.y -= 0x190000;
        ov96_021EB588(*(void **)(work + 0x74), &vec);
        ov96_021EB52C(*(void **)(work + 0x74), 1, 1);
        ov96_021EAB38(*(void **)(work + participant * 4), 0);
        work[0xA1] = 0;
        ov96_021FFE38(position->x / 0x1000, 0x8B5, sound);
        work[0xA0]++;
        break;
    }
    case 1: {
        VecFx32 vec;
        vec = *(VecFx32 *)ov96_021EB594(*(void **)(work + 0x74));
        vec.y += 0x14000;
        vec.x = position->x;
        ov96_021EB588(*(void **)(work + 0x74), &vec);
        work[0xA1]++;
        if (work[0xA1] >= 20) {
            ov96_021EB588(*(void **)(work + 0x70), position);
            work[0xA0]++;
        }
        break;
    }
    case 2:
        if (flag != 0) {
            result[8] = 2;
        }
        ov96_021EB588(*(void **)(work + 0x74), position);
        ov96_021EB588(*(void **)(work + 0x70), position);
        work[0xA0]++;
        /* fall through */
    case 3:
        ov96_021EB588(*(void **)(work + 0x74), position);
        ov96_021EB588(*(void **)(work + 0x70), position);
        break;
    }
}
