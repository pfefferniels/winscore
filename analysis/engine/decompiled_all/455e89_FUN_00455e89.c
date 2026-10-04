// FUN_00455e89 @ 00455e89 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00455e89(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  unkbyte10 in_ST0;
  float10 fVar3;
  unkbyte10 extraout_ST1;
  undefined1 *puVar4;
  
  puVar4 = &stack0xfffffffc;
  _DAT_007febd8 = f_199999;
  *param_1 = 0;
  iVar2 = *param_2;
  DAT_007febd4 = 1;
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    *(int *)(puVar4 + -0x30) = (&PT_X0)[DAT_007febd4] - _DAT_0078df18;
    iVar1 = *(int *)(puVar4 + -0x30);
    *(int *)(puVar4 + -0x30) = (&PT_Y0)[DAT_007febd4] - DAT_0078df1c;
    _DAT_007febd0 = (float)iVar1 / f_4;
    _DAT_007febcc = (float)*(int *)(puVar4 + -0x30) / f_4;
    DAT_007febc8 = (float)((float10)_DAT_007febcc * (float10)_DAT_007febcc +
                          (float10)_DAT_007febd0 * (float10)_DAT_007febd0);
    ffree((float10)_DAT_007febd0 * (float10)_DAT_007febd0);
    fVar3 = (float10)FUN_005ff146(puVar4,0x455f5b);
    DAT_007febc8 = (float)fVar3;
    if ((**(int **)(puVar4 + 0x10) == 1) && (_DAT_007febd8 == DAT_007febc8)) {
      *(undefined4 *)(puVar4 + -0xc) = 0;
    }
    else if (DAT_007febc8 <= _DAT_007febd8) {
      _DAT_007febd8 = DAT_007febc8;
      *param_1 = DAT_007febd4;
    }
    else {
      *(undefined4 *)(puVar4 + -8) = 0;
    }
    *(undefined4 *)(puVar4 + -4) = 0;
    DAT_007febd4 = DAT_007febd4 + 1;
    in_ST0 = extraout_ST1;
  }
  ffree(in_ST0);
  return;
}


