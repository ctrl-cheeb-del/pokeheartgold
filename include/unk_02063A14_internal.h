#ifndef PRIVATE_UNK_02063A14_H
#define PRIVATE_UNK_02063A14_H

#include "global.h"

#include "map_object.h"

typedef void (*MapObjectAction)(LocalMapObject *object);
typedef BOOL (*MapObjectPredicate)(LocalMapObject *object);

extern MapObjectAction _020FE104[];
extern MapObjectPredicate _020FE134[];
extern MapObjectPredicate _020FE164[];

void sub_02063A14(LocalMapObject *object);
BOOL sub_02063A1C(LocalMapObject *object);
void sub_02063A40(LocalMapObject *object);
BOOL sub_02063A5C(LocalMapObject *object);
BOOL sub_02063A78(LocalMapObject *object);

#endif
