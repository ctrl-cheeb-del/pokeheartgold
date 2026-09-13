#ifndef SOL40_FOLLOWUP_UNK_02034280_PRIVATE_H
#define SOL40_FOLLOWUP_UNK_02034280_PRIVATE_H

#include "global.h"

typedef void *(*CommAuxAllocFunc34280)(void *, void *, int);

typedef struct CommHandlerEntry34280 {
    void *handler;
    void *value;
    CommAuxAllocFunc34280 aux;
} CommHandlerEntry34280;

typedef struct CommManager34280 {
    const CommHandlerEntry34280 *table;
    int count;
    void *context;
} CommManager34280;

extern const CommHandlerEntry34280 _020F6980[];
extern CommManager34280 *_021D412C;
void *sub_02034280(int index, void *arg, int size);

#endif
