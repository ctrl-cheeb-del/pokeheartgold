#ifndef R40_OV109_R14_PRIVATE_H
#define R40_OV109_R14_PRIVATE_H
#include "global.h"

#include "touchscreen_list_menu.h"
#include "yes_no_prompt.h"
typedef struct R40PhotoApp14 {
    u8 raw[0x90];
} R40PhotoApp14;
#define F32(a, o)     (*(u32 *)((a)->raw + (o)))
#define FPTR(a, o, T) (*(T **)((a)->raw + (o)))
#define F8(a, o)      ((a)->raw[(o)])
extern const TouchscreenListMenuTemplate ov109_021E789C;
extern void ov109_021E7474(R40PhotoApp14 *, u8, u8, u32);
extern void ov109_021E75B4(R40PhotoApp14 *);
extern void ov109_021E73F8(R40PhotoApp14 *, u32, u32, u32);
extern void ov109_021E7248(R40PhotoApp14 *, u32);
extern void ov109_021E74D4(R40PhotoApp14 *, u32);
extern void ov109_021E5DEC(R40PhotoApp14 *, u8);
extern void ov109_021E70C4(R40PhotoApp14 *, u32, u32, u8);
extern void ov109_021E7524(R40PhotoApp14 *);
void ov109_021E75C8(R40PhotoApp14 *);
int ov109_021E7640(R40PhotoApp14 *);
void ov109_021E76F0(R40PhotoApp14 *);
int ov109_021E7748(R40PhotoApp14 *);
#endif
