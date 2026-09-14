#include "global.h"

typedef void (*Ov41R22Callback)(void *, void *);

void ov41_0224A27C(void *input, void *work, void *storage);
void ov41_0224A5D4(void *input, int index, Ov41R22Callback callback, void *work, void *argument);
void ov41_0224A3E4(void *input, void *work);
void ov41_02247598(void *unused, void *work);
void ov41_022475B4(void *unused, void *work);
void ov41_022475D4(void *unused, void *work);
void ov41_022475F4(void *unused, void *work);
void ov41_02247628(void *unused, void *work);

void ov41_022474D4(void *work);
void ov41_02247568(void *work);

void ov41_022474D4(void *work) {
    u8 *bytes = work;

    ov41_0224A27C(bytes + 0x4E0, work, bytes + 0x6EC);
    ov41_0224A5D4(bytes + 0x4E0, 0, ov41_022475B4, work, NULL);
    ov41_0224A5D4(bytes + 0x4E0, 1, ov41_022475D4, work, NULL);
    ov41_0224A5D4(bytes + 0x4E0, 2, ov41_022475F4, work, NULL);
    ov41_0224A5D4(bytes + 0x4E0, 3, ov41_02247628, work, NULL);
    ov41_0224A5D4(bytes + 0x4E0, 4, ov41_02247598, work, NULL);
}

void ov41_02247568(void *work) {
    u8 *bytes = work;

    ov41_0224A3E4(bytes + 0x4E0, work);
}
