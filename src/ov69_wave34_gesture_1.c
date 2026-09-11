#include "global.h"
#include "system.h"
void ov69_021E645C(int x,int y,u32*outX,u32*magX,u32*outY,u32*magY);
typedef struct Gesture {u32 result,state,x,y;s32 dx,dy;u32 timer;} Gesture;
typedef struct Big {u8 pad[0xc308];Gesture g;} Big;
void ov69_021E6308(void *);

void ov69_021E6308(void *arg){
    Big *w=arg;u32 direction=0;
    w->g.result=0;
    if(gSystem.touchX>=0xc0&&gSystem.touchX<=0x100&&gSystem.touchY>=0xa0&&gSystem.touchY<=0xb8)direction=2;
    else if(gSystem.touchX<=0x40&&gSystem.touchY>=0xa0&&gSystem.touchY<=0xb8)direction=0x400;
    if(gSystem.touchNew){
        if(direction){w->g.result=direction;return;}
        w->g.state=0;w->g.dx=0;w->g.dy=0;w->g.timer=0;w->g.result=0;w->g.x=gSystem.touchX;w->g.y=gSystem.touchY;w->g.timer=4;
    }
    if(gSystem.touchHeld){
        switch(w->g.state){case 0:if(w->g.timer==0)w->g.state++;else w->g.timer--;case 1:break;default:return;}
        if(direction==0){u32 fx,dx,fy,dy;ov69_021E645C(w->g.x,w->g.y,&fx,&dx,&fy,&dy);w->g.result=fx|fy;w->g.dx=dx;w->g.dy=dy;w->g.x=gSystem.touchX;w->g.y=gSystem.touchY;}
    }else{
        if(direction==0&&w->g.timer!=0&&w->g.dx<4&&w->g.dy<4)w->g.result=1;
        w->g.state=0;w->g.dx=0;w->g.dy=0;w->g.timer=0;
    }
}

void ov69_021E645C(int x,int y,u32*outX,u32*magX,u32*outY,u32*magY){
    u32 fx=0,fy=0;int dx=0,dy=0;
    if(gSystem.touchX!=0xffff){dx=(int)gSystem.touchX-x;if(dx<0){dx^=-1;fx=0x10;}else if(dx>0)fx=0x20;}
    *outX=fx;*magX=dx&0x3f;
    if(gSystem.touchY!=0xffff){dy=(int)gSystem.touchY-y;if(dy<0){dy^=-1;fy=0x80;}else if(dy>0)fy=0x40;}
    *outY=fy;*magY=dy&0x3f;
}
