#include "ov83_wave36_private.h"

void ov83_02244408(void *p){int n=ov80_02237D8C(U8(p,9));ov83_02246E08((u8 *)p+0x2c8,PTR(p,0x55c),n);}

void ov83_0224442C(void *p){GfGfx_EngineATogglePlanes(0x1f,0);GfGfx_EngineBTogglePlanes(0x1f,0);FreeBgTilemapBuffer(p,3);FreeBgTilemapBuffer(p,2);FreeBgTilemapBuffer(p,0);FreeBgTilemapBuffer(p,1);FreeBgTilemapBuffer(p,4);FreeBgTilemapBuffer(p,5);Heap_Free(p);*(vu16 *)0x04000304|=0x8000;}
