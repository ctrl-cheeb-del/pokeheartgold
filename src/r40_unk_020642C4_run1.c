#include "global.h"

#include "r40_unk_020642C4_private.h"

int sub_020642C4(LMO *obj, PAV *pav, int *outDir) {
    int mode = sub_02064298(obj);

    if (mode == 1) {
        int x = PlayerAvatar_GetXCoord(pav);
        int z = PlayerAvatar_GetZCoord(pav);
        int dir = MapObject_GetFacingDirection(obj);
        int param = MapObject_GetParam(obj, 0);
        int dist = sub_0206439C(obj, dir, param, x, z, 0);
        if (dist != -1 && sub_02064468(obj, dir, dist) == 0) {
            *outDir = dir;
            return dist;
        }
        return -1;
    }
    if (mode == 2) {
        int x = PlayerAvatar_GetXCoord(pav);
        int z = PlayerAvatar_GetZCoord(pav);
        int param = MapObject_GetParam(obj, 0);
        int dir;
        for (dir = 0; dir < 4; dir++) {
            int dist = sub_0206439C(obj, dir, param, x, z, 0);
            if (dist != -1 && sub_02064468(obj, dir, dist) == 0) {
                *outDir = dir;
                return dist;
            }
        }
        return -1;
    }
    return -1;
}
