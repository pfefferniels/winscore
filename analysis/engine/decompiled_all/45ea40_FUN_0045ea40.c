// FUN_0045ea40 @ 0045ea40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045ea40(int param_1,float *param_2,float *param_3,int *param_4,float *param_5,int *param_6
                 )

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  float10 fVar2;
  unkbyte10 Var3;
  undefined1 *puVar4;
  uint local_4c;
  int local_48;
  int local_24;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar4 = &stack0xfffffffc;
  for (iVar1 = 1; iVar1 < 0x33; iVar1 = iVar1 + 1) {
    (&DAT_00824378)[iVar1] = (int)f_0;
  }
  DAT_00824378 = (int)ROUND(*param_5);
  if (DAT_00824378 == 0) {
    DAT_00824378 = 0x32;
  }
  DAT_00824374 = 1;
  for (local_24 = DAT_00824378; 0 < local_24; local_24 = local_24 + -1) {
    (&DAT_00824378)[DAT_00824374] = *(undefined4 *)(param_1 + -4 + DAT_00824374 * 4);
    DAT_00824374 = DAT_00824374 + 1;
  }
  DAT_00824370 = (int)ROUND(DAT_0082437c);
  if ((DAT_00824370 == 0x11) || (DAT_00824370 < 7 && 3 < DAT_00824370)) goto LAB_0045ef16;
  *param_4 = 6;
  if (DAT_00824370 < 3) {
    *param_4 = 0xf;
  }
  if (DAT_00824370 == 0x12) {
    *param_4 = 7;
  }
  if ((DAT_00824370 == 8) || (DAT_00824370 == 0xf)) {
    *param_4 = 5;
  }
  local_4c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_48 = (int)ROUND(DAT_00824380);
  DAT_0082436c = (float)(&STAFF_STEP0)[local_48] / f_25;
  if (DAT_0082436c == f_0) {
    DAT_0082436c = f_1;
  }
  if (DAT_00824370 == 7) {
    *param_4 = 5;
    if (_DAT_00824394 == f_20) {
      *param_4 = 9;
    }
LAB_0045ecc5:
    if (*param_2 == f_0) {
      local_4c = (&DAT_00824378)[*param_4];
      ffree(in_ST0);
      fVar2 = (float10)FUN_005ff874(&local_4c,&f_100);
      _DAT_00824368 = (float)(fVar2 * (float10)DAT_0082436c);
      if ((_DAT_00824368 == f_0) || (DAT_00824370 == 8)) {
        _DAT_00824368 = DAT_0082436c;
      }
LAB_0045ee2f:
      FUN_005f33c9(&stack0xfffffffc,0x45ee4d);
      Var3 = FUN_005f34d1(puVar4,0x45ee68);
      ffree(Var3);
      Var3 = thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00761930,&DAT_00761934,"(1f7.2)",7,
                                &DAT_00824368);
      ffree(Var3);
      Var3 = thunk_FUN_0058c248(&DAT_020b8ea0,0x200,&DAT_00761920,&DAT_00761924,"(1f5.2)",7,
                                &DAT_0082436c);
      ffree(Var3);
      Var3 = thunk_FUN_0054da52(&DAT_020b8ea0,0x200);
      ffree(Var3);
      in_ST0 = (float10)thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
      *(undefined4 *)(puVar4 + -8) = 0;
      goto LAB_0045ef16;
    }
    local_10 = 0;
    local_4c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_48 = (int)ROUND((float)(&DAT_00824378)[*param_4]);
    DAT_00824364 = local_48 / 100;
    *param_3 = *param_2;
    if (DAT_00824370 != 8) {
      in_ST0 = (float10)*param_2 / (float10)DAT_0082436c;
      local_48 = DAT_00824364 * 100;
      *param_3 = (float)((float10)local_48 + in_ST0);
    }
    if (*param_6 == 99) {
      *param_3 = *param_2 / (DAT_0082436c * f_13_56);
    }
    *param_2 = *param_3;
  }
  else {
    if (DAT_00824370 != 0xe) goto LAB_0045ecc5;
    if (_DAT_0082438c <= f_0) goto LAB_0045ef16;
    _DAT_00824368 = DAT_0082436c;
    if (DAT_008243bc != f_0) {
      _DAT_00824368 = DAT_008243bc;
    }
    if (*param_2 == f_0) {
      local_18 = 0;
      goto LAB_0045ee2f;
    }
    *param_4 = 0x11;
    local_14 = 0;
  }
  if (((DAT_00824370 == 0xc) && (f_0 <= _DAT_0082438c)) && (_DAT_00824394 != f_0)) {
    ffree(in_ST0);
    in_ST0 = (float10)thunk_FUN_0046f634(&DAT_00761974);
  }
LAB_0045ef16:
  ffree(in_ST0);
  return;
}


