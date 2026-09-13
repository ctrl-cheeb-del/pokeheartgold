#include "global.h"
typedef struct Pokemon Pokemon;
typedef struct BoxPokemon BoxPokemon;
extern u8 gSystem[];
void *sub_0208A520(void *);
Pokemon *AllocMonZeroed(int);
void CopyBoxPokemonToPokemon(BoxPokemon *, Pokemon *);
u32 GetMonData(Pokemon *, int, void *);
void Heap_Free(void *);
void LoadFontPal1(int, int, int);
u32 Options_GetFrame(void *);
void LoadUserFrameGfx2(void *, int, int, int, int, int);
void sub_0208DDA0(void *, int);
void sub_0208E174(void *);
void sub_0208BCD4(void *);
void sub_0208BDC8(void *);
u32 sub_02089478(void *);
