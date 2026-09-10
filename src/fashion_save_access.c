#include "global.h"

#include "fashion_case.h"
#include "save.h"

BOOL sub_0202BF10(SaveFashionData *, SaveFashionDataSub *);
SaveFashionDataSub *sub_0202B9B8(SaveFashionData *, int);
void sub_0202BDA8(SaveFashionDataSub *, SaveFashionDataSub *);
void sub_0202BF80(u8, int, SaveFashionData *, SaveFashionDataSub **);

void sub_0202BF80(u8 count, int skip, SaveFashionData *fashionData, SaveFashionDataSub **entries) {
    int accepted = 0;
    int i;
    for (i = 0; i < count; i++) {
        if (i != skip && entries[i] != NULL && sub_0202BF10(fashionData, entries[i]) == TRUE) {
            accepted++;
        }
    }
    for (i = 10; i >= 1; i--) {
        if (i + accepted < 11) {
            sub_0202BDA8(sub_0202B9B8(fashionData, i + accepted), sub_0202B9B8(fashionData, i));
        }
    }
    {
        int dst = 1;
        for (i = 0; i < count; i++) {
            SaveFashionDataSub *entry;
            if (i == skip) {
                continue;
            }
            entry = entries[i];
            if (entry != NULL && sub_0202BF10(fashionData, entry) == TRUE) {
                sub_0202BDA8(sub_0202B9B8(fashionData, dst++), entry);
            }
        }
    }
}

SaveFashionData *Save_FashionData_Get(SaveData *saveData) {
    return SaveArray_Get(saveData, 0xC);
}
