#ifndef SOL40_OV49_RES25_PRIVATE_H
#define SOL40_OV49_RES25_PRIVATE_H
#include "global.h"

#include "bg_window.h"
#include "render_window.h"
#include "text.h"
typedef void MessageFormat;
extern void *sub_020392D8();
extern u32 ov45_0222D7CC();
extern u32 ov45_0222E7FC();
extern MessageFormat *MessageFormat_New_Custom();
extern void MessageFormat_Delete();
extern void *NewMsgDataFromNarc();
extern void DestroyMsgData();
extern String *String_New();
extern void String_Delete();
extern void ReadMsgDataIntoString();
extern void StringExpandPlaceholders();
extern void BufferIntegerAsString();
extern void BufferPlayersName();
extern void BufferWiFiPlazaActivityName();
extern void BufferWiFiPlazaEventName();
extern void BufferWiFiPlazaInstrumentName();
extern void BufferCountryName();
extern void BufferCityName();
extern void BufferECWord();
extern void MessageFormat_ResetBuffers();
extern const u32 ov49_02269714[];
#endif
