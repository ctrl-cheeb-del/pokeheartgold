#include "global.h"

#include "application/pokedex/pokedex_internal.h"

#include "dex_mon_measures.h"
#include "gf_gfx_loader.h"
#include "heap.h"
#include "pokedex.h"
#include "pokedex_util.h"

// Runs a Pokedex search: starts from the seen species of the Johto or national order and narrows the list
// criterion by criterion; stops early when a criterion leaves nothing. The result goes to searchResults.
BOOL PokedexApp_RunSearch(PokedexAppData *pokedexApp, u8 natDexFlag, u32 order, u32 letter, u32 type1, u32 type2, u32 heightMin, u32 heightMax, u32 weightMin, u32 weightMax, u32 areaMask, u32 bodyType) {
    u16 *buf1;
    u16 *buf2;
    u16 *list;
    u32 listCount;
    u32 count1;
    u32 count2;

    MI_CpuClear32(&pokedexApp->searchResults, sizeof(PokedexSearchResults));
    buf1 = Heap_AllocAtEnd(HEAP_ID_POKEDEX_APP, NATIONAL_DEX_COUNT * sizeof(u16));
    GF_ASSERT(buf1 != NULL);
    memset(buf1, 0, NATIONAL_DEX_COUNT * sizeof(u16));
    count1 = 0;
    buf2 = Heap_AllocAtEnd(HEAP_ID_POKEDEX_APP, NATIONAL_DEX_COUNT * sizeof(u16));
    GF_ASSERT(buf2 != NULL);
    memset(buf2, 0, NATIONAL_DEX_COUNT * sizeof(u16));
    count2 = 0;
    if (natDexFlag == 0) {
        list = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_dex_order_johto), &listCount);
    } else {
        list = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_dex_order_national), &listCount);
    }
    PokedexApp_FilterSeen(buf1, &count1, pokedexApp->args->pokedex, list, listCount);
    PokedexApp_ApplySortOrder(order, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByLetter(letter, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    if (count2 == 0) {
        goto end;
    }
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByType(type1, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    if (count2 == 0) {
        goto end;
    }
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByType(type2, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    if (count2 == 0) {
        goto end;
    }
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByBodyType(bodyType, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    if (count2 == 0) {
        goto end;
    }
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    if (pokedexApp->nationalDex == 0 && (areaMask & (1 << DEX_SEARCH_AREA_KANTO))) {
        PokedexApp_FilterByArea(pokedexApp, (1 << DEX_SEARCH_AREA_JOHTO) | (1 << DEX_SEARCH_AREA_KANTO), buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
        if (count2 != 0) {
            goto filterHeight;
        }
        goto end;
    } else {
        PokedexApp_FilterByArea(pokedexApp, areaMask, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
        if (count2 == 0) {
            goto end;
        }
    }
filterHeight:
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByHeight(pokedexApp, heightMin, heightMax, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    memcpy(buf1, buf2, count2 * sizeof(u16));
    count1 = count2;
    memset(buf2, 0, count2 * sizeof(u16));
    count2 = 0;
    PokedexApp_FilterByWeight(pokedexApp, weightMin, weightMax, buf2, &count2, buf1, count1, pokedexApp->args->pokedex);
    PokedexApp_StoreSearchResults(&pokedexApp->searchResults, pokedexApp->args->pokedex, buf2, count2);
end:
    Heap_Free(list);
    Heap_Free(buf2);
    Heap_Free(buf1);
    return TRUE;
}

// Loads one species list of the sort-order files (DEX_SORT_FILE index); *count is its length.
u16 *PokedexApp_LoadSortData(u32 index, u32 *count) {
    u32 size;
    u16 *ret;

    GF_ASSERT(index < 82);
    ret = GfGfxLoader_LoadFromNarc_GetSizeOut(GetPokedexDataNarcID(), index + NARC_zukan_data_sort_order_dex_order_national, FALSE, HEAP_ID_POKEDEX_APP, FALSE, &size);
    *count = size / 2;
    return ret;
}

void PokedexApp_FilterSeen(u16 *dst, u32 *count, const Pokedex *pokedex, const u16 *src, u32 length) {
    u32 i;

    *count = 0;
    i = 0;
    if (length <= i) {
        return;
    }
    do {
        if (Pokedex_CheckMonSeenFlag(pokedex, *src)) {
            dst[*count] = *src;
            (*count)++;
        }
        i++;
        src++;
    } while (i < length);
}

void PokedexApp_StoreSearchResults(PokedexSearchResults *result, const Pokedex *pokedex, const u16 *src, u32 count) {
    u32 i;

    result->count = count;
    result->caughtCount = 0;
    for (i = 0; i < count; i++) {
        result->entries[i][0] = src[i];
        if (Pokedex_CheckMonCaughtFlag(pokedex, src[i])) {
            result->entries[i][1] = POKEDEXAPP_ENTRY_CAUGHT;
            result->caughtCount++;
        } else {
            result->entries[i][1] = POKEDEXAPP_ENTRY_SEEN;
        }
    }
}

void PokedexApp_ApplySortOrder(u32 order, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u16 *sorted;
    u32 sortedCount;
    BOOL seenOnly = FALSE;

    switch (order) {
    case 0:
        memcpy(dst, src, srcCount * sizeof(u16));
        *dstCount = srcCount;
        return;
    case 1:
        sorted = PokedexApp_LoadSortData(DEX_ORDER_ALPHABETICAL, &sortedCount);
        seenOnly = TRUE;
        break;
    case 2:
        sorted = PokedexApp_LoadSortData(DEX_ORDER_HEAVIEST, &sortedCount);
        break;
    case 3:
        sorted = PokedexApp_LoadSortData(DEX_ORDER_LIGHTEST, &sortedCount);
        break;
    case 4:
        sorted = PokedexApp_LoadSortData(DEX_ORDER_TALLEST, &sortedCount);
        break;
    case 5:
        sorted = PokedexApp_LoadSortData(DEX_ORDER_SHORTEST, &sortedCount);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    PokedexApp_IntersectSpeciesLists(dst, dstCount, src, srcCount, sorted, sortedCount, seenOnly, pokedex);
    Heap_Free(sorted);
}

void PokedexApp_FilterByLetter(u32 letter, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u16 *matches;
    u32 matchCount;

    if (letter == DEX_SEARCH_LETTERS_ALL) {
        memcpy(dst, src, srcCount * sizeof(u16));
        *dstCount = srcCount;
        return;
    }
    matches = PokedexApp_LoadSortData(letter + DEX_SORT_FILE(NARC_zukan_data_sort_order_letters_a), &matchCount);
    PokedexApp_IntersectSpeciesLists(dst, dstCount, matches, matchCount, src, srcCount, TRUE, pokedex);
    Heap_Free(matches);
}

#pragma opt_propagation off

void PokedexApp_FilterByType(u32 type, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u16 *matches;
    u32 matchCount;
    u32 count;

    switch (PokedexApp_IdentityU32(type)) {
    case DEX_SEARCH_TYPE_ALL:
        count = srcCount;
        memcpy(dst, src, count * sizeof(u16));
        *dstCount = count;
        return;
    case DEX_SEARCH_TYPE_NORMAL:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_normal), &matchCount);
        break;
    case DEX_SEARCH_TYPE_FIGHTING:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_fighting), &matchCount);
        break;
    case DEX_SEARCH_TYPE_FLYING:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_flying), &matchCount);
        break;
    case DEX_SEARCH_TYPE_POISON:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_poison), &matchCount);
        break;
    case DEX_SEARCH_TYPE_GROUND:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_ground), &matchCount);
        break;
    case DEX_SEARCH_TYPE_ROCK:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_rock), &matchCount);
        break;
    case DEX_SEARCH_TYPE_BUG:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_bug), &matchCount);
        break;
    case DEX_SEARCH_TYPE_GHOST:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_ghost), &matchCount);
        break;
    case DEX_SEARCH_TYPE_STEEL:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_steel), &matchCount);
        break;
    case DEX_SEARCH_TYPE_FIRE:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_fire), &matchCount);
        break;
    case DEX_SEARCH_TYPE_WATER:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_water), &matchCount);
        break;
    case DEX_SEARCH_TYPE_GRASS:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_grass), &matchCount);
        break;
    case DEX_SEARCH_TYPE_ELECTRIC:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_electric), &matchCount);
        break;
    case DEX_SEARCH_TYPE_PSYCHIC:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_psychic), &matchCount);
        break;
    case DEX_SEARCH_TYPE_ICE:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_ice), &matchCount);
        break;
    case DEX_SEARCH_TYPE_DRAGON:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_dragon), &matchCount);
        break;
    case DEX_SEARCH_TYPE_DARK:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_types_dark), &matchCount);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    PokedexApp_IntersectSpeciesLists(dst, dstCount, matches, matchCount, src, srcCount, FALSE, pokedex);
    Heap_Free(matches);
}

#pragma opt_propagation reset

// The cases are the body-type grid positions of the search screen.
void PokedexApp_FilterByBodyType(u32 bodyType, u16 *dst, u32 *dstCount, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u16 *matches;
    u32 matchCount;

    switch (bodyType) {
    case 14:
        memcpy(dst, src, srcCount * sizeof(u16));
        *dstCount = srcCount;
        return;
    case 7:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_quadruped), &matchCount);
        break;
    case 13:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_bipedal_tailless), &matchCount);
        break;
    case 11:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_bipedal_tail), &matchCount);
        break;
    case 5:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_serpentine), &matchCount);
        break;
    case 4:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_multiwing), &matchCount);
        break;
    case 12:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_biwing), &matchCount);
        break;
    case 9:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_insectoid), &matchCount);
        break;
    case 6:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_head_torso), &matchCount);
        break;
    case 1:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_head_arms), &matchCount);
        break;
    case 2:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_head_legs), &matchCount);
        break;
    case 3:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_tentacles), &matchCount);
        break;
    case 10:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_fins), &matchCount);
        break;
    case 0:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_head_only), &matchCount);
        break;
    case 8:
        matches = PokedexApp_LoadSortData(DEX_SORT_FILE(NARC_zukan_data_sort_order_body_style_multibody), &matchCount);
        break;
    default:
        GF_ASSERT(FALSE);
        break;
    }
    PokedexApp_IntersectSpeciesLists(dst, dstCount, matches, matchCount, src, srcCount, TRUE, pokedex);
    Heap_Free(matches);
}

// speciesAreaMasks holds a DEX_SEARCH_AREA_* bit mask per species.
void PokedexApp_FilterByArea(PokedexAppData *pokedexApp, u32 areaMask, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    if (areaMask & (1 << DEX_SEARCH_AREA_ALL)) {
        memcpy(dst, src, srcCount * sizeof(u16));
        *count = srcCount;
        return;
    }
    if (areaMask == ((1 << DEX_SEARCH_AREA_JOHTO) | (1 << DEX_SEARCH_AREA_KANTO))) {
        u32 i;
        for (i = 0; i < srcCount; i++) {
            if ((areaMask & pokedexApp->speciesAreaMasks[src[i]]) && !(pokedexApp->speciesAreaMasks[src[i]] & (1 << DEX_SEARCH_AREA_UNKNOWN)) && Pokedex_CheckMonSeenFlag(pokedex, src[i])) {
                dst[*count] = src[i];
                (*count)++;
            }
        }
    } else {
        u32 i;
        for (i = 0; i < srcCount; i++) {
            if ((pokedexApp->speciesAreaMasks[src[i]] & areaMask) && Pokedex_CheckMonSeenFlag(pokedex, src[i])) {
                dst[*count] = src[i];
                (*count)++;
            }
        }
    }
}

// min and max are slider positions; sliderValues maps them to heights.
void PokedexApp_FilterByHeight(PokedexAppData *pokedexApp, u16 min, u16 max, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u32 i;

    if (min == 0 && max == DEX_SEARCH_SLIDER_MAX) {
        memcpy(dst, src, srcCount * sizeof(u16));
        *count = srcCount;
        return;
    }
    for (i = 0; i < srcCount; i++) {
        s32 height = ((s32 *)pokedexApp->heights)[src[i]];
        if (height >= pokedexApp->sliderValues[min].height && height <= pokedexApp->sliderValues[max].height && Pokedex_CheckMonCaughtFlag(pokedex, src[i])) {
            dst[*count] = src[i];
            (*count)++;
        }
    }
}

void PokedexApp_FilterByWeight(PokedexAppData *pokedexApp, u16 min, u16 max, u16 *dst, u32 *count, const u16 *src, u32 srcCount, const Pokedex *pokedex) {
    u32 i;

    if (min == 0 && max == DEX_SEARCH_SLIDER_MAX) {
        memcpy(dst, src, srcCount * sizeof(u16));
        *count = srcCount;
        return;
    }
    for (i = 0; i < srcCount; i++) {
        s32 weight = ((s32 *)pokedexApp->weights)[src[i]];
        if (weight >= pokedexApp->sliderValues[min].weight && weight <= pokedexApp->sliderValues[max].weight && Pokedex_CheckMonCaughtFlag(pokedex, src[i])) {
            dst[*count] = src[i];
            (*count)++;
        }
    }
}

// Keeps the species of src that also occur in lookup; unless seenOnly, they must also be caught.
void PokedexApp_IntersectSpeciesLists(u16 *dst, u32 *count, const u16 *lookup, u32 lookupCount, const u16 *src, u32 srcCount, BOOL seenOnly, const Pokedex *pokedex) {
    u32 i;
    u32 j;

    *count = 0;
    i = 0;
    if (seenOnly == TRUE) {
        for (; i < srcCount; i++) {
            for (j = 0; j < lookupCount; j++) {
                if (src[i] == lookup[j]) {
                    dst[*count] = src[i];
                    (*count)++;
                    break;
                }
            }
        }
    } else {
        for (; i < srcCount; i++) {
            for (j = 0; j < lookupCount; j++) {
                if (src[i] == lookup[j] && Pokedex_CheckMonCaughtFlag(pokedex, src[i])) {
                    dst[*count] = src[i];
                    (*count)++;
                    break;
                }
            }
        }
    }
}

// 15 entries per list page
u32 PokedexApp_GetListCursorIndex(PokedexAppData *pokedexApp) {
    return pokedexApp->listCursor + 15 * pokedexApp->listPage;
}

u16 PokedexApp_GetCursorSpecies(PokedexAppData *pokedexApp) {
    int index = PokedexApp_GetListCursorIndex(pokedexApp);
    return pokedexApp->listEntries[index].species;
}

// Returns species if it is among the results, else the first result.
u32 PokedexApp_FindSpeciesInResults(PokedexSearchResults *results, u16 species) {
    u32 i;
    u16 first = 0;
    u16 count = results->count;

    for (i = 0; i < count; i++) {
        if (first == 0) {
            first = results->entries[i][0];
        }
        if (species == results->entries[i][0]) {
            return species;
        }
    }
    return first;
}

// Fills the list entries from the results: in dex-number mode every species sits at its dex number,
// otherwise the results follow each other (entry 0 stays empty).
void PokedexApp_BuildListEntries(PokedexAppData *pokedexApp, int mode) {
    u32 i;

    MI_CpuClear32(pokedexApp->listEntries, sizeof(pokedexApp->listEntries));
    if (mode == 1) {
        for (i = 0; i < pokedexApp->searchResults.count; i++) {
            u32 dexNo = Pokedex_ConvertToCurrentDexNo(pokedexApp->dexMode, pokedexApp->searchResults.entries[i][0]);
            PokedexAppData *shifted;
            dexNo--;
            shifted = (PokedexAppData *)((u8 *)pokedexApp + dexNo * sizeof(PokedexListEntry));
            shifted->listEntries[0].species = pokedexApp->searchResults.entries[i][0];
            shifted->listEntries[0].caughtState = pokedexApp->searchResults.entries[i][1];
        }
    } else {
        for (i = 0; i < pokedexApp->searchResults.count; i++) {
            pokedexApp->listEntries[i + 1].species = pokedexApp->searchResults.entries[i][0];
            pokedexApp->listEntries[i + 1].caughtState = pokedexApp->searchResults.entries[i][1];
        }
    }
}

u32 PokedexApp_GetListLength(PokedexAppData *pokedexApp, int mode) {
    if (mode == 0) {
        return pokedexApp->searchResults.count;
    }
    return Pokedex_ConvertToCurrentDexNo(pokedexApp->dexMode, pokedexApp->searchResults.entries[pokedexApp->searchResults.count - 1][0]);
}

u32 PokedexApp_GetLastListPage(PokedexAppData *pokedexApp, int mode) {
    if (mode == 0) {
        return PokedexApp_GetListLength(pokedexApp, mode) / 15;
    }
    return (PokedexApp_GetListLength(pokedexApp, mode) - 1) / 15;
}

// Passes its argument through (the type filter's switch value).
u32 PokedexApp_IdentityU32(u32 value) {
    return value;
}
