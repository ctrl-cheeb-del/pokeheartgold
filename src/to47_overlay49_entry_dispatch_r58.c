#include "to47_overlay49_entry_dispatch_r58_private.h"

void ov49_0225F260(void *arg0, void *arg1, u32 arg2, const Ov49R58Entry *entries, u32 value)
{
    void *state = ov49_0225EF84(arg0);
    void *context = ov49_0225A010(arg1);
    int i;
    int j;

    for (i = 0; entries[i].type != 3; i++) {
        for (j = 0; j < 8; j++) {
            if (entries[i].values[j] == 0xFF) {
                break;
            }
            if (entries[i].values[j] == value) {
                switch (entries[i].type) {
                case 0:
                    ov49_0225EF68(arg0);
                    ov49_0225EF98(context, arg2, entries[i].config, 0);
                    return;
                case 1:
                    if (entries[i].callback != NULL) {
                        entries[i].callback(state, arg1, arg2, entries[i].values[j]);
                    }
                    ov49_0225EFC4(context, arg2, entries[i].config, 0);
                    return;
                default:
                    return;
                }
            }
        }
    }
    GF_AssertFail();
}
