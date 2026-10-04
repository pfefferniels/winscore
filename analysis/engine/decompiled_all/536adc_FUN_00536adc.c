// FUN_00536adc @ 00536adc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00536adc(void)

{
  _DAT_0099a898 = 0x42;
  fit_view(&DAT_0099a898,&DAT_01c25e80,&DAT_01c25e84,&DAT_01c25e88,&DAT_01c25e8c);
  _DAT_0099a894 = DAT_01c25e80 - DAT_01c25e84;
  _DAT_0099a890 = DAT_01c25e8c - _DAT_01c25e88;
  thunk_FUN_00579770(&DAT_00768974,1,&IP1);
  _DAT_01c25e90 = IP1;
  _DAT_01c25e94 = IP2;
  thunk_FUN_00579770(&DAT_00768970,1,&IP1);
  _DAT_0099a88c = IP1;
  _DAT_0099a888 = IP2;
  IP1 = 0;
  IP2 = 0;
  thunk_FUN_00579770(&DAT_00768990,1,&IP1);
  thunk_FUN_00579770(&DAT_00768970,1,&IP1);
  DAT_01c25e9c = IP2;
  _DAT_0099a8a0 = -IP2;
  _DAT_0099a89c = (int)ROUND((float)IP1 + f_2400);
  DAT_01c25e98 = IP1;
  VIEW_DX = 0x960;
  _DAT_0099a884 = 0;
  draw_items();
  thunk_FUN_00549422();
  thunk_FUN_0054943a();
  return;
}


