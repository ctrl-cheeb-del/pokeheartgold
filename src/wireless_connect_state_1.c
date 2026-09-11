#include "wireless_connect_state_1_private.h"

int sub_02032E9C(void) {
 u8 data[0x20]; int r;
 if((u32)(*(u32 *)(*(u8 **)(_021D4124+4)+0x1310)-4)<=2)return TRUE;
 sub_02032844(3); MI_CpuCopy8(_0210F8FC,data+1,3);data[0]=sub_0203993C();
 r=WM_StartConnectEx(sub_02032F0C,*(u8 **)(_021D4124+4)+0x1220,data,1,0);if(r!=2){sub_02032858(r);return FALSE;}return TRUE;
}

void sub_02032F0C(void *arg) {
 u8 *a=arg; u16 code;
 if(*(u16 *)(a+2)!=0){sub_02032858(*(u16 *)(a+2)); if(*(u16 *)(a+2)==12){sub_02032844(9);return;}if(*(u16 *)(a+2)==11){sub_02032844(9);return;}if(*(u16 *)(a+2)==1){if(sub_02039918()){sub_02032844(9);return;}sub_02032844(8);return;}sub_02032844(9);return;}
 code=*(u16 *)(a+8); if(code==8)return; if(code==7){u8 *p=*(u8 **)(_021D4124+4);if(p[0x1335]){sub_02032858(20);sub_02032844(9);return;}sub_02032844(4);if(!sub_02032FCC()){sub_02032844(3);return;}*(u16 *)(*(u8 **)(_021D4124+4)+0x132c)=*(u16 *)(a+0xa);return;}if(code==6)return;if(code==9){sub_02032858(20);sub_02032844(9);return;}if(code==26)return;sub_02032844(9);
}

int sub_02032FCC(void) {
 u8 *p=*(u8 **)(_021D4124+4);
 int r=WM_StartMP(sub_0203301C,p+0x1020,(u16)*(u32 *)(p+0x1308),p+0xF40,(u16)*(u32 *)(p+0x1304),1);
 if(r!=2){sub_02032858(r);return FALSE;}return TRUE;
}

void sub_0203301C(void *arg) {
 u8 *a=arg;u16 err=*(u16 *)(a+2);u16 code;
 if(err!=0){if(err==15||err==9||err==13)return;sub_02032858(err);sub_02032844(9);return;}
 code=*(u16 *)(a+4);switch(code){case 10:if(*(u32 *)(*(u8 **)(_021D4124+4)+0x1314)!=3||*(u32 *)(*(u8 **)(_021D4124+4)+0x1310)!=6)sub_02032844(4);break;case 11:case 12:case 13:default:break;}
}
