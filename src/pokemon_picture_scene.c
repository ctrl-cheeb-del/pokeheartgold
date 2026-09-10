#include "pokemon_picture_scene_internal.h"

void sub_0208DEDC(UnkStruct_0208DE40 *a) {
    NNS_G2dSetupSoftwareSpriteCamera();
    PokepicManager_DrawAll(a->unk_2A0);
    *(vu32 *)0x04000540 = 1;
}

void sub_0208DEFC(UnkStruct_0208DE40 *a) {
    Camera_Delete(a->unk_29C);
    sub_02017088(a->unk_2CC, 0);
    sub_02016F2C(a->unk_2CC);
    PokepicManager_Delete(a->unk_2A0);
}
