#include "global.h"

extern int ov69_021E6300(int country);
extern void *NewMsgDataFromNarc(u32 kind, u32 narcId, u32 msgId, u32 heapId);
extern void ReadMsgDataIntoString(void *msgData, int msgNo, void *string);
extern void DestroyMsgData(void *msgData);
extern int LocationGmmDatGetGmmNo(int index);

int ov69_021E7520(int country, int msgNo, void *dest, void *src, u32 heapId);

int ov69_021E7520(int country, int msgNo, void *dest, void *src, u32 heapId) {
    int ret;
    int gmmIndex = ov69_021E6300(country);
    u32 heap = *(volatile u32 *)&heapId;
    void *msgData = NewMsgDataFromNarc(0, 0x1B, 0x31E, heap);
    ReadMsgDataIntoString(msgData, country, dest);
    DestroyMsgData(msgData);
    if (gmmIndex == 0) {
        gmmIndex = 1;
        msgNo = 0;
        ret = 0;
    } else {
        ret = 1;
    }
    msgData = NewMsgDataFromNarc(0, 0x1B, LocationGmmDatGetGmmNo(gmmIndex), heap);
    ReadMsgDataIntoString(msgData, msgNo, src);
    DestroyMsgData(msgData);
    return ret;
}
