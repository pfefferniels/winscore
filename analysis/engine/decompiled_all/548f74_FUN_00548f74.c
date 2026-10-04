// FUN_00548f74 @ 00548f74 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00548f74(void)

{
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  unkbyte10 Var1;
  float10 fVar2;
  undefined4 local_54;
  undefined4 *local_50;
  undefined *local_4c;
  int local_48;
  undefined4 local_44 [16];
  
  local_4c = (undefined *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  DAT_009a1804 = (int)ROUND(P2);
  ffree(in_ST0);
  local_48 = DAT_009a1804;
  Var1 = fit_view(&DAT_00769288,&DAT_009a1800,&DAT_009a17fc,&DAT_009a17f8,&DAT_009a17f4);
  local_44[0] = 0;
  local_54 = 6;
  local_50 = &DAT_009ae2bc;
  local_4c = &DAT_009a1800;
  ffree(Var1);
  Var1 = FUN_005f34f0(local_44,0x784ff00,&DAT_0076915c,&local_54,&DAT_007975d8);
  local_44[0] = 0;
  local_54 = 6;
  local_50 = (undefined4 *)0x9ae2c3;
  local_4c = &DAT_009a17fc;
  ffree(Var1);
  Var1 = FUN_005f34f0(local_44,0x784ff00,&DAT_0076915c,&local_54,&DAT_007975ec);
  local_44[0] = 0;
  local_54 = 6;
  local_50 = (undefined4 *)0x9ae2ca;
  local_4c = &DAT_009a17f8;
  ffree(Var1);
  Var1 = FUN_005f34f0(local_44,0x784ff00,&DAT_0076915c,&local_54,&DAT_00797600);
  local_44[0] = 0;
  local_54 = 6;
  local_50 = &DAT_009ae2d1;
  local_4c = &DAT_009a17f4;
  ffree(Var1);
  Var1 = FUN_005f34f0(local_44,0x784ff00,&DAT_0076915c,&local_54,&DAT_00797614);
  EDIT_ITEM = DAT_009a1804;
  ffree(Var1);
  Var1 = FUN_0055036f(&DAT_009a17f0,&DAT_009a17ec,&DAT_009a17e8,&DAT_009a17e4);
  ffree(Var1);
  Var1 = thunk_FUN_00579770(&DAT_00769284,1,&IP1);
  IP4 = IP2;
  IP6 = 0;
  local_4c = (undefined *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  IP2 = (int)ROUND((_DAT_009a17f0 - _DAT_009a17ec) + f_5000);
  ffree(Var1);
  local_48 = IP2;
  Var1 = thunk_FUN_00579770(&DAT_0076927c,1,&IP1);
  IP1 = 0;
  IP2 = 10000;
  ffree(Var1);
  Var1 = thunk_FUN_00579770(&DAT_00769278,1,&IP1);
  ffree(Var1);
  Var1 = thunk_FUN_00579770(&DAT_00769274,1,&IP1);
  DAT_009a1804 = (&ITEM_PTR0)[EDIT_ITEM];
  local_4c = (undefined *)(&ITEM_P4)[DAT_009a1804];
  ffree(Var1);
  fVar2 = (float10)FUN_005ff874(&local_4c,&f_100);
  _DAT_009a17e0 = (float)fVar2;
  if ((float)(&ITEM_P1)[DAT_009a1804] == f_14) {
    _DAT_009a17e0 = f_3;
  }
  DAT_0078d934 = (int)ROUND((float)(&ITEM_P2)[DAT_009a1804]);
  fVar2 = (float10)(int)(&STAFF_Y0)[DAT_0078d934] +
          (float10)_DAT_009a17e0 * (float10)f_7 * (float10)(float)(&STAFF_STEP0)[DAT_0078d934];
  _DAT_009a17e0 = (float)(fVar2 - (float10)VIEW_DY);
  _DAT_009a17dc = _DAT_009a17e0 / (_DAT_009a17ec - _DAT_009a17f0);
  if (_DAT_009a17dc < f_0_1) {
    _DAT_009a17dc = f_0;
  }
  _DAT_009a17d8 = (float)IP2;
  local_4c = (undefined *)(CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000);
  IP2 = (int)ROUND(_DAT_009a17dc * _DAT_009a17d8);
  ffree(fVar2);
  local_48 = IP2;
  Var1 = thunk_FUN_00579770(&DAT_00769278,1,&IP1);
  EDIT_ITEM = 0;
  ffree(Var1);
  return;
}


