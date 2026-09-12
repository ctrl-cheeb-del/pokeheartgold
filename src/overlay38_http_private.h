#ifndef OVERLAY38_HTTP_PRIVATE_H
#define OVERLAY38_HTTP_PRIVATE_H

#include "global.h"

typedef struct Ov38HttpState {
    int state;
    int request;
    int error;
    int length;
    int pidValue;
    int unk14;
    int dataLength;
    char *buffer;
    int bufferSize;
    void *response;
    u8 *hash;
    u8 *data;
    int encodedSize;
} Ov38HttpState;

extern Ov38HttpState _02225040;
extern u32 _02226020;

void ov00_021EC2EC(int heapId, void *ptr, int unused);
BOOL ov00_021FA0B4(int value);
void ov00_021FA0D8(void);
BOOL ov00_021FA118(void);
int ov00_021FA21C(void *buffer, void (*callback)(const char *, int, int), void *arg);

void ov38_0221BBD0(const char *data, int length, int status);
void ov38_0221BB68(int value);
void ov38_0221BA00(u32 value);
u8 ov38_0221BA10(void);
int ov38_0221BB44(u32 size);
void ov38_0221BE84(void);
int ov38_0221BF48(void);
void ov38_0221BFEC(void);
int ov38_0221C014(void);
int ov38_0221C020(void);

#endif
