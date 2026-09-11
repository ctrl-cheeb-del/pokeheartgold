#ifndef TO40_OV96_R115_PRIVATE_H
#define TO40_OV96_R115_PRIVATE_H
#include "global.h"
typedef struct Course Course;
typedef struct CourseObject {
    void *object;
    void *subObject;
    u8 pad08[0x14];
    s16 posX;
    s16 posY;
    u8 pad20[0x0C];
    s32 x;
    s32 y;
    u8 pad34[0x2C];
    u32 flags;
    u8 pad64[0x44];
} CourseObject;
typedef struct CourseHeap {
    u8 pad000[0x1A4];
    CourseObject objects[1];
} CourseHeap;
CourseHeap *PokeathlonCourse_GetHeapAllocPtr4(Course *course);
void ov96_021EB06C(void *object, s32 x, s32 y, s32 *outX, s32 *outY);
void ov96_02218688(void *object);
void ov96_0221910C(void *object);
void ov96_022186B8(void *object, void *arg);
void *ov96_02215DD4(Course *, int);
void ov96_02215DEC(Course *, int, VecFx32 *);
u32 ov96_02215E2C(Course *, int);
u8 ov96_02215E48(Course *, int);
u8 ov96_02215E68(Course *, int);
u32 ov96_02215E94(Course *, int);
u32 ov96_02215EB0(Course *, int);
void ov96_02215ECC(Course *, int);
void ov96_02215EE8(Course *, int, const VecFx32 *);
void ov96_02215F2C(Course *, int);
void ov96_02215F64(Course *, int);
void ov96_02215F80(Course *, int, void *);
#endif
