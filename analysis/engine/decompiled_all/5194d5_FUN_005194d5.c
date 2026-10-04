// FUN_005194d5 @ 005194d5 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_005194d5(char *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  float10 in_ST0;
  float10 fVar4;
  float10 extraout_ST1;
  
  puVar1 = &stack0xfffffffc;
  DAT_0094e220 = 0;
  DAT_0094e21c = 0;
  DAT_0094e224 = -1;
  _DAT_0094e218 = f_1;
  DAT_0094e214 = 1;
  if (*param_1 != '+') {
    DAT_0094e214 = 0;
  }
  do {
    while( true ) {
      iVar3 = DAT_0094e214 + 1;
      DAT_0094e200 = param_1[DAT_0094e214];
      DAT_0094e214 = iVar3;
      if (DAT_0094e200 != 0x2d) break;
      in_ST0 = (float10)_DAT_0094e218;
      _DAT_0094e218 = (float)-in_ST0;
LAB_00519620:
      while( true ) {
        puVar2 = &stack0xfffffffc;
        if (0xb < DAT_0094e214) goto LAB_00519725;
        if (param_1[DAT_0094e214] != ' ') break;
        DAT_0094e214 = DAT_0094e214 + 1;
      }
    }
    if (DAT_0094e200 == 0x2e) {
      DAT_0094e21c = iVar3;
      if (DAT_0094e224 < 0) goto LAB_00519620;
    }
    else {
      if (((char)DAT_0094e200 < '0') || ('9' < (char)DAT_0094e200)) {
        puVar2 = &stack0xfffffffc;
        if (-1 < DAT_0094e224) {
          _DAT_0094e20c = f_1;
          _DAT_0094e208 = (float)DAT_0094e224;
          DAT_0094e210 = iVar3;
          if (DAT_0094e21c != 0) {
            _DAT_0094e20c = (float)((iVar3 - DAT_0094e21c) + -1);
            puVar1 = &stack0xfffffffc;
            fVar4 = (float10)FUN_006033ff(&stack0xfffffffc,0x5196ea);
            _DAT_0094e20c = (float)fVar4;
            in_ST0 = extraout_ST1;
          }
          *(float *)(puVar1 + -0x3c) = (_DAT_0094e208 * _DAT_0094e218) / _DAT_0094e20c;
          puVar2 = puVar1;
        }
        goto LAB_00519725;
      }
      DAT_0094e220 = DAT_0094e220 * 10 + (uint)DAT_0094e200 + -0x30;
      DAT_0094e224 = DAT_0094e220;
    }
    puVar2 = &stack0xfffffffc;
    if (0xb < iVar3) {
LAB_00519725:
      **(int **)(puVar2 + 0x10) = **(int **)(puVar2 + 0x10) + DAT_0094e210 + -1;
      ffree(in_ST0);
      return (float10)*(float *)(puVar2 + -0x3c);
    }
  } while( true );
}


