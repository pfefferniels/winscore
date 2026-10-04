// FUN_0056f14d @ 0056f14d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f14d(float *param_1)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  unkbyte10 extraout_ST0;
  unkbyte10 extraout_ST0_00;
  unkbyte10 extraout_ST0_01;
  unkbyte10 extraout_ST0_02;
  unkbyte10 extraout_ST0_03;
  unkbyte10 Var2;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  undefined4 local_28 [9];
  
  DAT_01a27704 = (int)ROUND(X_POS);
  if ((f_199 < P2) && (DAT_01a27704 < 33000)) {
    DAT_01a27704 = DAT_01a27704 + 0x8502;
  }
  local_30 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_01a27708 = (int)ROUND(Y_POS);
  DAT_0078d858 = -DAT_01a27704;
  DAT_0078d85c = -DAT_01a27708;
  _DAT_01c6da30 = (float)-(float10)*param_1;
  local_28[0] = 0;
  local_34 = &DAT_01a27704;
  ffree((float10)*param_1);
  local_2c = DAT_01a27708;
  iVar1 = FUN_005fc330(local_28,0x18,0x784ff01,&DAT_0076a384,&local_34,&DAT_0079fd68);
  Var2 = extraout_ST0;
  if (iVar1 == 0) {
    local_34 = &DAT_01a27708;
    ffree(extraout_ST0);
    iVar1 = FUN_005fc980(local_28,&DAT_0076a384,&local_34);
    Var2 = extraout_ST0_00;
    if (iVar1 == 0) {
      local_34 = (undefined4 *)&DAT_01c6da30;
      ffree(extraout_ST0_00);
      iVar1 = FUN_005fc980(local_28,&DAT_0076a358,&local_34);
      Var2 = extraout_ST0_01;
      if (iVar1 == 0) {
        local_34 = &DAT_0078d858;
        ffree(extraout_ST0_01);
        iVar1 = FUN_005fc980(local_28,&DAT_0076a384,&local_34);
        Var2 = extraout_ST0_02;
        if (iVar1 == 0) {
          local_34 = &DAT_0078d85c;
          ffree(extraout_ST0_02);
          iVar1 = FUN_005fc980(local_28,&DAT_0076a3e8,&local_34);
          Var2 = extraout_ST0_03;
        }
      }
    }
  }
  if (iVar1 != 0) {
    ffree(Var2);
    Var2 = thunk_FUN_004cf1c2();
  }
  ffree(Var2);
  return;
}


