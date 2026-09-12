#include "global.h"

#include "overlay96_course_sprite_resources_r14_private.h"

void ov96_02203DCC(void *p, R14Participant *participants) {
    int i = 0;
    u8 *dst = p;
    PokepicTemplate tpl;

    do {
        GetMonSpriteCharAndPlttNarcIdsEx(&tpl, participants->species, participants->gender, 0, participants->shiny, (u8)participants->form, participants->personality);
        PTR_AT(dst, 0x24) = sub_0201457C((NarcId)tpl.narcID, tpl.charDataID, (enum HeapID)U32_AT(p, 0), participants->personality, 0, 0, participants->species);
        PTR_AT(dst, 0x28) = sub_02014450((NarcId)tpl.narcID, tpl.palDataID, (enum HeapID)U32_AT(p, 0));
        participants++;
        dst += 8;
        i++;
    } while (i < 3);
}
