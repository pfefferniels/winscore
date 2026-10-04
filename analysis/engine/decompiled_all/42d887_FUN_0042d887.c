// FUN_0042d887 @ 0042d887 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0042d887(float *param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  float10 fVar2;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_007f139c = (float)(&ITEM_P3)[*param_2];
  local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_007f1398 = (int)ROUND((float)(&ITEM_P2)[*param_2]);
  LOAD_I = 1;
  _DAT_007f13a0 = f_99999;
  local_34 = DAT_007f1398;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    load_item_header();
    if (((DAT_007f1398 == LOAD_STAFF) && (LOAD_CODE == 1)) && (_DAT_007f139c == LOAD_P3)) {
      local_3c = (&ITEM_P4)[LOAD_W];
      fVar2 = (float10)FUN_005ff874(&local_3c,&f_100);
      _DAT_007f1394 = (float)fVar2;
      DAT_007f1390 = ABS(_DAT_007f1394 - *param_1);
      if (DAT_007f1390 <= _DAT_007f13a0) {
        local_38 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
        local_34 = (int)ROUND(_DAT_007f1394);
        _DAT_007f13a0 = DAT_007f1390;
        *param_3 = local_34;
      }
      else {
        local_c = 0;
      }
    }
    else {
      local_10 = 0;
    }
    local_8 = 0;
    LOAD_I = LOAD_I + 1;
  }
  return;
}


