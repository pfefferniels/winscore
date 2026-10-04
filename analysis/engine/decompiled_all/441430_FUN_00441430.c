// FUN_00441430 @ 00441430 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00441430(void)

{
  int iVar1;
  int iVar2;
  undefined2 in_FPUControlWord;
  int local_44;
  uint local_40;
  int local_3c;
  undefined4 local_14;
  undefined4 local_10;
  
  DAT_01cadd48 = (int)ROUND(P2);
  if ((DAT_01cadd48 < 1) || (ITEM_I < DAT_01cadd48)) {
    DAT_01cadd48 = ITEM_I;
  }
  local_40 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_3c = (int)ROUND(P3);
  DAT_01cadd4c = local_3c;
  if (ITEM_I < local_3c) {
    DAT_01cadd4c = ITEM_I;
  }
  if (DAT_01cadd4c < 1) {
    DAT_01cadd4c = 1;
  }
  if (DAT_01cadd4c != DAT_01cadd48) {
    DAT_01cadd70 = (&ITEM_PTR0)[DAT_01cadd48];
    DAT_01cadd74 = (&ITEM_PTR0)[DAT_01cadd4c];
    DAT_01cadd80 = (&DAT_02091d20)[DAT_01cadd48];
    DAT_01cadd90 = (&DAT_02091d20)[DAT_01cadd4c];
    DAT_01cadd50 = DAT_01cadd80 - DAT_01cadd70;
    DAT_01cadd78 = *(int *)(&DAT_020359fc + DAT_01cadd48 * 4);
    DAT_01cadd7c = *(int *)(&DAT_020359fc + DAT_01cadd4c * 4);
    DAT_01cadd88 = (&DAT_02035a00)[DAT_01cadd48];
    DAT_01cadd94 = (&DAT_02035a00)[DAT_01cadd4c];
    DAT_01cadd60 = DAT_01cadd88 - DAT_01cadd78;
    if (DAT_01cadd4c < DAT_01cadd48) {
      local_14 = 0;
      DAT_01cadd84 = DAT_01cadd74 - DAT_01cadd70;
      _DAT_01cadd8c = DAT_01cadd7c - DAT_01cadd78;
      DAT_01cadd54 = DAT_01cadd80;
      DAT_01cadd58 = DAT_01cadd74;
      DAT_01cadd5c = DAT_01cadd70;
      DAT_01cadd64 = DAT_01cadd88 + -1;
      DAT_01cadd68 = DAT_01cadd7c;
      DAT_01cadd6c = DAT_01cadd78 + -1;
    }
    else {
      DAT_01cadd84 = DAT_01cadd90 - DAT_01cadd80;
      _DAT_01cadd8c = DAT_01cadd94 - DAT_01cadd88;
      DAT_01cadd58 = DAT_01cadd90 - DAT_01cadd50;
      DAT_01cadd68 = DAT_01cadd94 - DAT_01cadd60;
      local_10 = 0;
      DAT_01cadd54 = DAT_01cadd70;
      DAT_01cadd5c = DAT_01cadd80;
      DAT_01cadd64 = DAT_01cadd78;
      DAT_01cadd6c = DAT_01cadd88;
    }
    local_44 = DAT_01cadd50 * 2;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_01cadd70,&ITEM_LEN + ITEM_WORDS,&local_44);
    thunk_FUN_0054c4c6(&PT_X0 + DAT_01cadd78,&PT_X0 + NPT,&DAT_01cadd60);
    thunk_FUN_0054c4c6(&PT_Y0 + DAT_01cadd78,&PT_Y0 + NPT,&DAT_01cadd60);
    local_44 = DAT_01cadd84 * 2;
    thunk_FUN_0054c590(&ITEM_LEN + DAT_01cadd5c,&ITEM_LEN + DAT_01cadd54,&local_44);
    thunk_FUN_0054c4c6(&PT_X0 + DAT_01cadd6c,&PT_X0 + DAT_01cadd64,&DAT_01cadd8c);
    thunk_FUN_0054c4c6(&PT_Y0 + DAT_01cadd6c,&PT_Y0 + DAT_01cadd64,&DAT_01cadd8c);
    local_44 = DAT_01cadd50 * 2;
    thunk_FUN_0054c590(&ITEM_LEN + ITEM_WORDS,&ITEM_LEN + DAT_01cadd58,&local_44);
    thunk_FUN_0054c4c6(&PT_X0 + NPT,&PT_X0 + DAT_01cadd68,&DAT_01cadd60);
    thunk_FUN_0054c4c6(&PT_Y0 + NPT,&PT_Y0 + DAT_01cadd68,&DAT_01cadd60);
    if (DAT_01cadd4c < DAT_01cadd48) {
      DAT_01cadda0 = -1;
      DAT_01cadd4c = DAT_01cadd4c + 1;
      DAT_01cadd50 = -DAT_01cadd50;
      DAT_01cadd60 = -DAT_01cadd60;
    }
    else {
      DAT_01cadda0 = 1;
      DAT_01cadd48 = DAT_01cadd48 + 1;
    }
    iVar1 = DAT_01cadda0;
    DAT_01cadd80 = DAT_01cadd48;
    for (iVar2 = ((DAT_01cadd4c - DAT_01cadd48) + DAT_01cadda0) / DAT_01cadda0; 0 < iVar2;
        iVar2 = iVar2 + -1) {
      (&ITEM_PTR0)[DAT_01cadd80] = (&ITEM_PTR0)[DAT_01cadda0 + DAT_01cadd80] - DAT_01cadd50;
      *(int *)(&DAT_020359fc + DAT_01cadd80 * 4) =
           *(int *)(&DAT_020359fc + (DAT_01cadda0 + DAT_01cadd80) * 4) - DAT_01cadd60;
      DAT_01cadd80 = DAT_01cadd80 + iVar1;
    }
    DAT_0078b4f0 = 1;
    DAT_0078b4ec = 0;
  }
  return;
}


