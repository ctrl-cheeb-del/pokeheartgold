#include "touch_sampling_internal.h"

void GF_TouchpadInit(void) {
    memset(&STATE, 0, sizeof(STATE));
}
void sub_020210BC(void) {
    GF_ASSERT(FLAGS.mode == 0);
    FLAGS.mode = 0;
}
BOOL sub_020210D8(TPData *data, u32 capacity, u32 frequency) {
    int result;
    if (FLAGS.paused) {
        sub_020211AC(1, 1, data, capacity, 0, frequency * 2);
        return 1;
    }
    if (frequency >= 5 || frequency == 0) {
        return 0;
    }
    if (FLAGS.mode != 0) {
        return 0;
    }
    result = GF_TouchpadStartAutoSampling(frequency);
    if (result == 1) {
        sub_020211AC(1, 1, data, capacity, 0, frequency * 2);
        return 1;
    }
    return result;
}
BOOL sub_02021148(int frequency) {
    int result;
    if (FLAGS.paused) {
        sub_020211AC(2, 1, NULL, 0, 0, frequency * 2);
        return 1;
    }
    if ((u32)frequency >= 5 || frequency == 0) {
        return 0;
    }
    if (FLAGS.mode != 0) {
        return 0;
    }
    result = GF_TouchpadStartAutoSampling(frequency);
    if (result == 1) {
        sub_020211AC(2, 1, NULL, 0, 0, frequency * 2);
        return 1;
    }
    return result;
}
void sub_020211AC(u16 mode, u8 autoRead, TPData *data, u32 capacity, u32 write, u32 count) {
    FLAGS.mode = mode;
    gSystem.touchpadReadAuto = autoRead;
    STATE.buffer = data;
    STATE.capacity = capacity;
    STATE.count = count;
    STATE.write = write;
    sub_020211E0(STATE.samples, 9);
}
void sub_020211E0(TPData *data, int count) {
    int i;
    for (i = 0; i < count; i++) {
        data[i].touch = 0;
    }
}
int GF_TouchpadStopAutoSampling(void) {
    u32 retries = 0;
    u32 busy;
    if (FLAGS.mode == 0) {
        return 1;
    }
    do {
        TP_RequestAutoSamplingStopAsync();
        TP_WaitBusy(4);
        busy = TP_CheckBusy(4);
        if (busy) {
            retries++;
        }
    } while (busy && retries <= 5);
    if (retries > 5) {
        return 2;
    }
    return 1;
}
BOOL sub_02021238(void) {
    int result;
    if (FLAGS.paused) {
        sub_020211AC(0, 0, NULL, 0, 0, 0);
        return 1;
    }
    result = GF_TouchpadStopAutoSampling();
    if (result == 1) {
        sub_020211AC(0, 0, NULL, 0, 0, 0);
    }
    return result;
}
int sub_02021280(TouchOutput *out, int mode, u32 threshold) {
    int result = 3;
    u16 latest;
    if (FLAGS.paused) {
        if (out) {
            sub_02021528(out);
        }
        if (mode == 2) {
            return 1;
        }
        return 0;
    }
    if (FLAGS.mode) {
        latest = TP_GetLatestIndexInAuto();
        sub_020212EC(STATE.samples, 9);
        if (out) {
            sub_02021540(out, latest);
        }
        if (FLAGS.mode == 1) {
            result = sub_020213C8(mode, latest, threshold);
        } else {
            result = 1;
        }
    }
    return result;
}
void sub_020212EC(TPData *data, u32 count) {
    u32 i;
    TPData calibrated;
    for (i = 0; i < count; i++) {
        TP_GetCalibratedPoint(&calibrated, &data[i]);
        data[i] = calibrated;
    }
}
void GF_TouchpadResumeOnLidOpen(void) {
    if (FLAGS.paused && FLAGS.mode) {
        GF_ASSERT(GF_TouchpadStartAutoSampling(STATE.count >> 1) == 1);
        FLAGS.paused = 0;
    }
}
void GF_TouchpadPauseOnLidClose(void) {
    if (FLAGS.paused != 1 && FLAGS.mode) {
        GF_ASSERT(GF_TouchpadStopAutoSampling() == 1);
        FLAGS.paused = 1;
    }
}
int GF_TouchpadStartAutoSampling(u32 frequency) {
    int retries = 0;
    u32 busy;
    do {
        TP_RequestAutoSamplingStartAsync(0, (u16)frequency, STATE.samples, 9);
        TP_WaitBusy(2);
        busy = TP_CheckBusy(2);
        if (busy) {
            retries++;
        }
    } while (busy && retries <= 5);
    if (retries > 5) {
        return 2;
    }
    return 1;
}
int sub_020213C8(int mode, int latest, u32 threshold) {
    switch (mode) {
    case 1:
    case 3:
        return sub_020213F8(mode, latest, threshold);
    case 4:
    case 5:
        return sub_020214B0(mode, latest, threshold);
    default:
        return 1;
    }
}
