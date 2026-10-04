// FUN_00536543 @ 00536543 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00536543(float *param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  char *pcVar4;
  undefined4 *puVar5;
  char *pcVar6;
  bool bVar7;
  unkbyte10 in_ST0;
  unkbyte10 Var8;
  
  puVar3 = (undefined4 *)&DAT_020b8ea0;
  puVar5 = &DAT_009ae2bc;
  for (iVar2 = 0x80; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar5 = puVar5 + 1;
  }
  ffree(in_ST0);
  Var8 = draw_items();
  _DAT_0099a844 = 0x42;
  ffree(Var8);
  Var8 = fit_view(&DAT_0099a844,&DAT_01c25e80,&DAT_01c25e84,&DAT_01c25e88,&DAT_01c25e8c);
  _DAT_0099a840 = DAT_01c25e80 - DAT_01c25e84;
  _DAT_0099a83c = DAT_01c25e8c - _DAT_01c25e88;
  ffree(Var8);
  Var8 = thunk_FUN_00579770(&DAT_00768974,1,&IP1);
  _DAT_01c25e90 = IP1;
  _DAT_01c25e94 = IP2;
  ffree(Var8);
  Var8 = thunk_FUN_00579770(&DAT_00768970,1,&IP1);
  bVar7 = &stack0x00000000 == (undefined1 *)0x5c;
  _DAT_0099a838 = IP1;
  _DAT_0099a834 = IP2;
  iVar2 = 3;
  pcVar4 = (char *)((int)&DAT_009ae2bc + 2);
  pcVar6 = "038";
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar7 = *pcVar4 == *pcVar6;
    pcVar4 = pcVar4 + 1;
    pcVar6 = pcVar6 + 1;
  } while (bVar7);
  if ((bVar7) && (IP2 == 0)) {
    VIEW_DY = VIEW_DY + 2000;
    DAT_020b8ea0._0_1_ = DAT_007689a8;
  }
  else {
    IP1 = 500000;
    IP2 = -500000;
    ffree(Var8);
    Var8 = thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    ffree(Var8);
    thunk_FUN_00579770(&DAT_00768970,1,&IP1);
    iVar1 = IP2;
    iVar2 = IP1;
    DAT_01c25e9c = IP2;
    _DAT_0099a84c = -IP2;
    _DAT_0099a848 = (int)ROUND((float)IP1 + f_2400);
    DAT_01c25e98 = IP1;
    IP2 = (int)ROUND((float)IP2 * *param_2 + (float)_DAT_0099a834);
    IP1 = (int)ROUND((float10)IP1 * (float10)*param_1 + (float10)_DAT_0099a838);
    if (IP1 < 0) {
      IP1 = 0;
    }
    if (0 < IP2) {
      IP2 = 0;
    }
    if (iVar2 < IP1) {
      IP1 = iVar2;
    }
    if (IP2 < iVar1) {
      IP2 = iVar1;
    }
    ffree((float10)_DAT_0099a838);
    Var8 = thunk_FUN_00579770(&DAT_00768990,1,&IP1);
    if (PAPER != 0) {
      ffree(Var8);
      Var8 = draw_items();
    }
  }
  ffree(Var8);
  return;
}


