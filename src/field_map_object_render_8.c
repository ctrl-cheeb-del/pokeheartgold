#include "field_map_object_render_internal.h"

void ov01_021FA1C8(void *p, void *v) {
    *(void **)((u8 *)p + 0xe0) = v;
}

void *ov01_021FA1D0(void *p) {
    return *(void **)((u8 *)p + 0xe0);
}

void ov01_021FA1D8(void *p, void *v) {
    *(void **)((u8 *)p + 4) = v;
}

void *ov01_021FA1DC(void *p) {
    return *(void **)((u8 *)p + 0xe8);
}

void *ov01_021FA1E4(void *p) {
    return *(void **)((u8 *)p + 0xec);
}

void ov01_021FA1EC(void *p, void *v) {
    *(void **)((u8 *)p + 0xf0) = v;
}

void *ov01_021FA1F4(void *p) {
    return *(void **)((u8 *)p + 0xf0);
}

void *ov01_021FA1FC(void *p) {
    return (u8 *)p + 0x60;
}

void *ov01_021FA200(void *p) {
    return (u8 *)p + 0x20;
}

void *ov01_021FA204(void *p) {
    return (u8 *)p + 0x40;
}

void ov01_021FA208(void *p, void *v) {
    *(void **)((u8 *)p + 8) = v;
}

void *ov01_021FA20C(void *p) {
    return *(void **)((u8 *)p + 8);
}

void ov01_021FA210(void *p, void *v) {
    *(void **)((u8 *)p + 0xc) = v;
}

void *ov01_021FA214(void *p) {
    return *(void **)((u8 *)p + 0xc);
}

void ov01_021FA218(void *p, void *v) {
    *(void **)((u8 *)p + 0x10) = v;
}

void *ov01_021FA21C(void *p) {
    return *(void **)((u8 *)p + 0x10);
}

void ov01_021FA220(void *p, void *v) {
    *(void **)((u8 *)p + 0x14) = v;
}

void *ov01_021FA224(void *p) {
    return *(void **)((u8 *)p + 0x14);
}

void ov01_021FA228(void *p, void *v) {
    *(void **)((u8 *)p + 0x18) = v;
}

void *ov01_021FA22C(void *p) {
    return *(void **)((u8 *)p + 0x18);
}

void ov01_021FA230(void *p, void *v) {
    *(void **)((u8 *)p + 0x1c) = v;
}

void *ov01_021FA234(void *p) {
    return *(void **)((u8 *)p + 0x1c);
}

void *FldObjSys_ReadMModelFromNarc(void *sys, u32 a, u32 b) {
    return ReadMModelFromNarcInternal(*(void **)((u8 *)sys + 0x104), a, b);
}
