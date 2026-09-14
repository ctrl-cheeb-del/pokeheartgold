#include "overlay40_r33_a02_private.h"

void ov40_0223A430(void *p) {
    void *w = PTR(p, 0x860);

    ov40_0222D6EC(p, 2);
    PTR(w, 0x118) = ov40_0222D800(p, 2);
    PTR(w, 0x134) = ov40_0222D800(p, 2);
    ov40_0222D5AC((u8 *)w + 0x114, (u8 *)p + 0x14, 2);
    ov40_0222D5AC((u8 *)w + 0x130, (u8 *)p + 0x14, 2);
    ov40_0222D66C((u8 *)w + 0x114, (u8 *)p + 0x14, 3);
    ov40_0222D66C((u8 *)w + 0x130, (u8 *)p + 0x14, 0x5E);
    ManagedSprite_SetAnim(PTR(w, 0x118), 0);
    ManagedSprite_SetAnim(PTR(w, 0x134), 3);
    ManagedSprite_SetPositionXY(PTR(w, 0x118), 0x20, 0xE8);
    ManagedSprite_SetPositionXY(PTR(w, 0x134), 0x80, 0xE8);
    sub_020136B4(PTR(w, 0x11C), 0x24, -8);
    sub_020136B4(PTR(w, 0x138), 0x24, -8);
    TextOBJ_SetSpritesDrawFlag(PTR(w, 0x11C), TRUE);
    TextOBJ_SetSpritesDrawFlag(PTR(w, 0x138), TRUE);
    ov40_0223B4BC(p, 0);
}

void ov40_0223A510(void *p, int msgId, int index) {
    void *win = (u8 *)p + 0x8A4;
    void *w = PTR(p, 0x860);
    void *str;

    if (msgId == 0x64) {
        u32 value = WORD(w, 0x194);
        void *fmt = ov40_0222DAB0(0x6D);
        void *out = String_New(0xFF, 0x6D);
        void *name = sub_020315B8(value, 0x6D);
        void *message;

        ov40_02230DCC(p, name);
        message = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        BufferString(fmt, 0, name, 0, 1, 2);
        StringExpandPlaceholders(fmt, out, message);
        String_Delete(name);
        String_Delete(message);
        MessageFormat_Delete(fmt);
        str = out;
    } else if (msgId == 0x66) {
        u32 value = WORD((u8 *)p + index * 4, 0x88C);
        void *fmt = ov40_0222DAB0(0x6D);
        void *out = String_New(0xFF, 0x6D);
        void *name = sub_020315B8(value, 0x6D);
        void *message;

        ov40_02230DCC(p, name);
        message = NewString_ReadMsgData(PTR(p, 0x48), msgId);
        BufferString(fmt, 0, name, 0, 1, 2);
        StringExpandPlaceholders(fmt, out, message);
        String_Delete(name);
        String_Delete(message);
        MessageFormat_Delete(fmt);
        str = out;
    } else {
        str = NewString_ReadMsgData(PTR(p, 0x48), msgId);
    }
    FillWindowPixelBuffer(win, 0xCC);
    AddTextPrinterParameterizedWithColor(win, 0, str, 0, 0, 0xFF, 0xF0D0C, NULL);
    ScheduleWindowCopyToVram(win);
    String_Delete(str);
}

int ov40_0223A640(void *p) {
    void *w = PTR(p, 0x860);

    if (!ov40_0223D5CC(p)) {
        return 0;
    }
    switch (WORD(p, 8)) {
    case 0:
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 2);
        BgClearTilemapBufferAndCommit(PTR(p, 0x24), 6);
        if (WORD(w, 0x10) == 0) {
            ov40_022306A0((u8 *)w + 0x220, 0);
        } else {
            ov40_0222E7DC((u8 *)w + 0x194, 0);
        }
        WORD(p, 8)
        ++;
        // fallthrough
    case 1:
        ov40_0222DA84((int *)w + 2, 1);
        if (ov40_0222DA00(w, (int *)w + 1, 1, 0)) {
            WORD(p, 8)
            ++;
        }
        PaletteData_BlendPalettes(PTR(p, 0x28), 3, 0xC, (u8)WORD(w, 8), (u16)WORD(p, 0x58));
        break;
    case 2:
        ov40_0222DED0(p, 0x75);
        ov40_0223077C(p, PTR(p, 0x6F0), 0x80, 0x60);
        sub_020879E0(PTR(p, 0x6F0), 1);
        sub_02087A08(PTR(p, 0x6F0), 0x18, 0x18);
        WORD(w, 0x2038) = 0;
        PlaySE(0x57D);
        WORD(p, 8)
        ++;
        break;
    case 3: {
        u8 *entry;

        void *result = ov40_0223D540(p);
        entry = PTR((u8 *)p + WORD(p, 0x4D4) * 4, 0x2608);
        if (ov39_02227720(result, PTR(entry, 0xD8), PTR(entry, 0xDC)) == TRUE) {
            WORD(p, 8)
            ++;
        }
        break;
    }
    case 4: {
        void *result;
        void *ctx;

        ov40_0222DFB0(p);
        ctx = ov40_0223D540(p);
        if (ov39_02227D44(ctx, &result) == TRUE) {
            StopSE(0x57D, 0);
            ov40_02230CDC(p, 8, WORD(result, 0xC), WORD(result, 4));
            WORD(p, 8)
            ++;
            WORD(w, 0x2038) = 0;
        } else {
            StopSE(0x57D, 0);
            WORD(p, 8) = 0xFF;
            WORD(w, 0x2038) = 1;
            PTR(p, 0x878) = (u8 *)p + 0x413C + WORD(p, 0x4D4);
            PTR(w, 0x184) = PTR(p, 0x8B4);
            MI_CpuCopy8(PTR(w, 0x184), (u8 *)p + 0x8B8, 0x1D4C);
        }
        sub_020879E0(PTR(p, 0x6F0), 0);
        sub_02087A08(PTR(p, 0x6F0), 0, 0);
        break;
    }
    default:
        if (WORD(w, 0x2038) != 0) {
            PlaySE(0x577);
            ov40_0222BF80(p, WORD(w, 0x2034));
            ov40_0222FC40(p, 1);
        } else {
            ov40_0222BF80(p, 0x14);
        }
        break;
    }
    return 0;
}
