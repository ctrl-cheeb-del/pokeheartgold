#include "overlay96_exact_bank_internal.h"
#include "overlay96_exact_bank_prototypes.h"

int ov96_021F54C0(void *course) {
    u8 *p = PokeathlonCourse_GetHeapAllocPtr4(course);
    ov96_021EB5BC(*(u8 **)(p + 0x60));
    thunk_UpdateCellTransferStateManager();
    return 1;
}
