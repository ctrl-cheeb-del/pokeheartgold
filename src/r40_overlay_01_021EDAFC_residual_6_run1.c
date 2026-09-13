#include "r40_overlay_01_021EDAFC_residual_6_candidate_private.h"

int MapNumToFloorNo(int mapId) {
    switch (mapId) {
    case MAP_GOLDENROD_RADIO_TOWER_5F:
        return 0;
    case MAP_GOLDENROD_RADIO_TOWER_OBSERVATION_DECK:
        return 1;
    case MAP_OLIVINE_LIGHTHOUSE_1F:
        return 0;
    case MAP_OLIVINE_LIGHTHOUSE_LIGHT_ROOM:
        return 1;
    case MAP_SAFFRON_SILPH_CO_HQ:
        return 0;
    case MAP_SAFFRON_SILPH_CO_ROTOM_ROOM:
        return 1;
    case MAP_GOLDENROD_DEPARTMENT_STORE_1F:
        return 1;
    case MAP_GOLDENROD_DEPARTMENT_STORE_2F:
        return 2;
    case MAP_GOLDENROD_DEPARTMENT_STORE_3F:
        return 3;
    case MAP_GOLDENROD_DEPARTMENT_STORE_4F:
        return 4;
    case MAP_GOLDENROD_DEPARTMENT_STORE_5F:
        return 5;
    case MAP_GOLDENROD_DEPARTMENT_STORE_6F:
        return 6;
    case MAP_GOLDENROD_DEPARTMENT_STORE_BASEMENT:
        return 0;
    case MAP_CELADON_DEPARTMENT_STORE_1F:
        return 0;
    case MAP_CELADON_DEPARTMENT_STORE_2F:
        return 1;
    case MAP_CELADON_DEPARTMENT_STORE_3F:
        return 2;
    case MAP_CELADON_DEPARTMENT_STORE_4F:
        return 3;
    case MAP_CELADON_DEPARTMENT_STORE_5F:
        return 4;
    case MAP_CELADON_DEPARTMENT_STORE_ROOF:
        return 5;
    case MAP_CELADON_CONDOMINIUMS_1F:
        return 0;
    case MAP_CELADON_CONDOMINIUMS_2F:
        return 1;
    case MAP_CELADON_CONDOMINIUMS_3F:
        return 2;
    case MAP_CELADON_CONDOMINIUMS_ROOF:
        return 3;
    default:
        GF_AssertFail();
        return 0;
    }
}
