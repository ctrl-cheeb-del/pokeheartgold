#include "overlay38_http_private.h"

Ov38HttpState _02225040 = { 1 };
u32 _02226020;

int ov38_0221BF48(void) {
    switch (_02225040.state) {
    case 3:
        _02225040.request = ov00_021FA21C(_02225040.response, ov38_0221BBD0, &_02225040);
        ov38_0221BB68(_02225040.request);
        if (_02225040.request >= 0) {
            _02225040.state = 4;
        } else {
            _02225040.state = 1;
        }
        break;
    case 4:
        if (!ov00_021FA118()) {
            _02225040.state = 1;
        }
        break;
    case 5:
        _02225040.request = ov00_021FA21C(_02225040.response, ov38_0221BBD0, &_02225040);
        ov38_0221BB68(_02225040.request);
        if (_02225040.request >= 0) {
            _02225040.state = 6;
        } else {
            _02225040.state = 1;
        }
        break;
    case 6:
        if (!ov00_021FA118()) {
            _02225040.state = 1;
        }
        break;
    case 7:
        break;
    }
    return _02225040.state;
}

void ov38_0221BFEC(void) {
    if (_02225040.response != NULL) {
        ov00_021EC2EC(10, _02225040.response, 0);
        _02225040.response = NULL;
    }
    ov00_021FA0D8();
    _02225040.state = 1;
}

int ov38_0221C014(void) {
    return _02225040.error;
}

int ov38_0221C020(void) {
    return _02225040.length;
}
