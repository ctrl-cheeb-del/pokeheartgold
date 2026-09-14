#include "global.h"

#include "move.h"
#include "pokemon.h"
#include "yes_no_prompt.h"

#define P(p, o)   (*(void **)((u8 *)(p) + (o)))
#define U32(p, o) (*(u32 *)((u8 *)(p) + (o)))
#define U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))

typedef int (*Ov68Callback)(void *);
typedef struct Ov68CallbackEntry {
    Ov68Callback callback;
    u32 unused;
} Ov68CallbackEntry;

extern const Ov68CallbackEntry ov68_021E7D3C[];
extern const Ov68CallbackEntry ov68_021E7D40[];
extern void ov68_021E7BC8(int);
extern u16 ov68_021E6BEC(void *);

int ov68_021E6078(void *);
int ov68_021E60D8(void *);
int ov68_021E614C(void *);

int ov68_021E6078(void *work) {
    YesNoPromptTemplate template;
    MI_CpuFill8(&template, 0, sizeof(template));
    template.bgConfig = P(work, 4);
    template.bgId = 4;
    template.tileStart = 1;
    template.plttSlot = 0xB;
    template.x = 0x1A;
    template.y = 0xA;
    template.ignoreTouchFlag = U32(work, 0x1B4);
    template.initialCursorPos = 0;
    YesNoPrompt_InitFromTemplate(P(work, 0x118), &template);
    ov68_021E7BC8(1);
    return 4;
}

int ov68_021E60D8(void *work) {
    int result;
    switch (YesNoPrompt_HandleInput(P(work, 0x118))) {
    case YESNORESPONSE_YES:
        result = ov68_021E7D3C[U8(work, 0x1BA)].callback(work);
        ov68_021E7BC8(0);
        break;
    case YESNORESPONSE_NO:
        result = ov68_021E7D40[U8(work, 0x1BA)].callback(work);
        ov68_021E7BC8(0);
        break;
    default:
        return 4;
    }
    U32(work, 0x1B4) = YesNoPrompt_IsInTouchMode(P(work, 0x118));
    YesNoPrompt_Reset(P(work, 0x118));
    return result;
}

int ov68_021E614C(void *work) {
    u32 value = ov68_021E6BEC(work);
    u8 *args = P(work, 0);
    SetMonData(P(args, 0), MON_DATA_MOVE1 + U8(args, 0x1B), &value);
    value = 0;
    args = P(work, 0);
    SetMonData(P(args, 0), MON_DATA_MOVE1_PP_UPS + U8(args, 0x1B), &value);
    value = GetMoveMaxPP(ov68_021E6BEC(work), 0);
    args = P(work, 0);
    SetMonData(P(args, 0), MON_DATA_MOVE1_PP + U8(args, 0x1B), &value);
    U8(P(work, 0), 0x1A) = 0;
    return 8;
}
