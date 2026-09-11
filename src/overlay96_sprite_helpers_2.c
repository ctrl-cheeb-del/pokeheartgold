#include "overlay96_sprite_helpers_private.h"

void ov96_021EB21C(Ov96R31Work *w){u8 i=0;if(w->config.resourceCount>0){do{u32 off=i*0x14;if(*(SpriteResource **)(w->resourceRecords+off+4))SpriteTransfer_DeleteCharTransferTask(*(SpriteResource **)(w->resourceRecords+off+4));if(*(SpriteResource **)(w->resourceRecords+off+8))SpriteTransfer_DeletePlttTransferTask(*(SpriteResource **)(w->resourceRecords+off+8));i++;}while(i<w->config.resourceCount);}for(i=0;i<4;i++)Destroy2DGfxResObjMan(w->resources[i]);SpriteList_Delete(w->spriteList);Heap_Free(w->records);Heap_Free(w->resourceRecords);Heap_Free(w);}

void ov96_021EB29C(Ov96R31Work *w,int i,void *v){if(i>=w->config.resourceCount)GF_AssertFail();*(void **)(w->resourceRecords+i*0x14)=v;}

void ov96_021EB2BC(Ov96R31Work *w,NarcId narc,int file,int id,int vram){void **slot=ov96_021EB5EC(w,id,0);*slot=AddCharResObjFromNarc(w->resources[0],narc,file,FALSE,id,vram,(enum HeapID)w->heap);}

void ov96_021EB2F4(Ov96R31Work *w,NarcId narc,int file,int id,int vram,u8 pltt){void **slot=ov96_021EB5EC(w,id,1);*slot=AddPlttResObjFromNarc(w->resources[1],narc,file,FALSE,id,vram,pltt,(enum HeapID)w->heap);}

void ov96_021EB334(Ov96R31Work *w,NarcId narc,int file,int id){void **slot=ov96_021EB5EC(w,id,2);*slot=AddCellOrAnimResObjFromNarc(w->resources[2],narc,file,FALSE,id,GF_GFX_RES_TYPE_CELL,(enum HeapID)w->heap);}

void ov96_021EB36C(Ov96R31Work *w,NarcId narc,int file,int id){void **slot=ov96_021EB5EC(w,id,3);*slot=AddCellOrAnimResObjFromNarc(w->resources[3],narc,file,FALSE,id,GF_GFX_RES_TYPE_ANIM,(enum HeapID)w->heap);}

void ov96_021EB3A4(Ov96R31Work *w){int i=0;if(w->config.resourceCount>0){u32 off=i;do{if(*(void **)(w->resourceRecords+off+4))SpriteTransfer_CreateCharTransferTask_AllocAtEnd(*(void **)(w->resourceRecords+off+4));if(*(void **)(w->resourceRecords+off+8))SpriteTransfer_CreateExtPlttTransferTask(*(void **)(w->resourceRecords+off+8));i++;off+=0x14;}while(i<w->config.resourceCount);}}

Ov96R31Rec *ov96_021EB3E4(Ov96R31Work *w,int a,int b,int id,u8 kind){ov96_021EB408(w,a,b,id,kind);return ov96_021EB4F4(w,id,kind);}
