#include "map_matrix_internal.h"
extern const u16 _020F6280[];
#define sMapSecBases _020F6280

int sub_02017FAC(int mapsec) {
    int i;
    for (i = 0; i < 2; i++) {
        if ((u32)mapsec < sMapSecBases[i + 1]) {
            return i;
        }
    }
    return i;
}

int sub_02017FCC(int mapsec) {
    return mapsec - sMapSecBases[sub_02017FAC(mapsec)];
}

int sub_02017FE4(MapsecType group, int offset) {
    if (group >= 3) {
        GF_AssertFail();
    }
    return sMapSecBases[group] + offset;
}

BOOL LocationIsDiamondPearlCompatible(mapsec_t mapsec) {
    if ((mapsec >= MAPSEC_TWINLEAF_TOWN && mapsec <= MAPSEC_BATTLE_PARK) || (mapsec >= METLOC_DAY_CARE_COUPLE && mapsec <= METLOC_RILEY) || (mapsec >= METLOC_LOVELY_PLACE && mapsec <= METLOC_CONCERT_EVENT)) {
        return TRUE;
    }
    return FALSE;
}
