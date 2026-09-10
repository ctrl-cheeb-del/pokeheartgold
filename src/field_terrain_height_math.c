#include "field_terrain_height_math_internal.h"

BOOL ov01_021FAD1C(Ov01Vec2 *a, Ov01Vec2 *b, Ov01Vec2 *pt);
void ov01_021FAD6C(Ov01Thm *thm, int tri, Ov01Vec2 *out);
void ov01_021FAD9C(Ov01Thm *thm, int tri, VecFx32 *out);
void ov01_021FADBC(Ov01Thm *thm, int tri, fx32 *out);
void ov01_021FADD4(Ov01Hit *hits);
BOOL ov01_021FADEC(Ov01Bucket *buckets, int count, fx32 key, u16 *out);
int ov01_021FAE50(int mode, fx32 refY, fx32 x, fx32 z, void *a4, fx32 *outY);

BOOL ov01_021FAD1C(Ov01Vec2 *a, Ov01Vec2 *b, Ov01Vec2 *pt) {
    fx32 *minX;
    fx32 *maxX;
    fx32 *minZ;
    fx32 *maxZ;

    if (a->x <= b->x) {
        minX = &a->x;
        maxX = &b->x;
    } else {
        minX = &b->x;
        maxX = &a->x;
    }
    if (a->z <= b->z) {
        minZ = &a->z;
        maxZ = &b->z;
    } else {
        minZ = &b->z;
        maxZ = &a->z;
    }
    if (*minX <= pt->x && pt->x <= *maxX && *minZ <= pt->z && pt->z <= *maxZ) {
        return TRUE;
    }
    return FALSE;
}

void ov01_021FAD6C(Ov01Thm *thm, int tri, Ov01Vec2 *out) {
    out[0] = thm->verts[thm->tris[tri].vtxA];
    out[1] = thm->verts[thm->tris[tri].vtxB];
}

void ov01_021FAD9C(Ov01Thm *thm, int tri, VecFx32 *out) {
    *out = thm->normals[thm->tris[tri].normal];
}

void ov01_021FADBC(Ov01Thm *thm, int tri, fx32 *out) {
    *out = thm->dists[thm->tris[tri].plane];
}

void ov01_021FADD4(Ov01Hit *hits) {
    int i;

    for (i = 0; i < 10; i++) {
        hits[i].y = 0;
        hits[i].unk4 = -1;
        hits[i].unk8 = -1;
    }
}

BOOL ov01_021FADEC(Ov01Bucket *buckets, int count, fx32 key, u16 *out) {
    int lo;
    int mid;

    if (count == 0) {
        return FALSE;
    }
    if (count == 1) {
        *out = 0;
        return TRUE;
    }
    count--;
    lo = 0;
    mid = count / 2;
    while (TRUE) {
        if (buckets[mid].key > key) {
            count--;
            if (count > lo) {
                count = mid;
                mid = (lo + count) / 2;
            } else {
                *out = mid;
                return TRUE;
            }
        } else {
            lo++;
            if (lo < count) {
                lo = mid;
                mid = (lo + count) / 2;
            } else {
                *out = mid + 1;
                return TRUE;
            }
        }
    }
}

int ov01_021FAE50(int mode, fx32 refY, fx32 x, fx32 z, void *a4, fx32 *outY) {
    Ov01Thm *thm = (Ov01Thm *)a4;
    Ov01Bucket *buckets;
    Ov01Vec2 pt;
    Ov01Vec2 edge[2];
    VecFx32 normal;
    Ov01Hit hits[10];
    u16 idx;
    fx32 d;
    int n;
    int best;
    fx32 maxY;
    u16 j;
    u16 i;
    u16 count;
    u16 base;
    int tri;
    fx32 cur;
    u16 k;
    fx32 bestVal;

    if (thm->unk18 == 0) {
        return FALSE;
    }
    pt.x = x;
    pt.z = z;
    n = 0;
    ov01_021FADD4(hits);
    buckets = thm->buckets;
    if (!ov01_021FADEC(buckets, (u16)thm->numBuckets, pt.z, &idx)) {
        return FALSE;
    }
    count = buckets[idx].count;
    base = buckets[idx].offset;
    i = 0;
    while (i < count) {
        tri = thm->indices[base + i];
        ov01_021FAD6C(thm, tri, edge);
        if (ov01_021FAD1C(&edge[0], &edge[1], &pt) == TRUE) {
            ov01_021FAD9C(thm, tri, &normal);
            ov01_021FADBC(thm, tri, &d);
            hits[n].y = FX_Div(-(d + (FX_Mul(normal.x, pt.x) + FX_Mul(normal.z, pt.z))), normal.y);
            n++;
            if (n >= 10) {
                break;
            }
        }
        i++;
    }

    if (n > 1) {
        best = 0;
        switch (mode) {
        case 1:
            maxY = (fx32)0xFF000000;
            for (j = 0; j < n; j++) {
                cur = hits[j].y;
                if (maxY < cur) {
                    maxY = cur;
                    best = j;
                }
            }
            break;
        case 2:
            bestVal = (fx32)0x01000000;
            for (k = 0; k < n; k++) {
                cur = hits[k].y;
                if (bestVal > cur) {
                    bestVal = cur;
                    best = k;
                }
            }
            break;
        case 0:
        default:
            bestVal = sub_02020B94(refY, hits[0].y) - sub_02020B8C(refY, hits[0].y);
            for (j = 1; j < n; j++) {
                cur = sub_02020B94(refY, hits[j].y) - sub_02020B8C(refY, hits[j].y);
                if (bestVal > cur) {
                    bestVal = cur;
                    best = j;
                }
            }
            break;
        }
        *outY = hits[best].y;
        return TRUE;
    } else if (n == 1) {
        *outY = hits[0].y;
        return TRUE;
    } else if (n != 0) {
        *outY = hits[0].y;
        return TRUE;
    } else {
        return FALSE;
    }
}
