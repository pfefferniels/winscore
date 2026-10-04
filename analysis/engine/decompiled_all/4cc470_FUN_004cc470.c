// FUN_004cc470 @ 004cc470 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004cc470(int *param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined2 in_FPUControlWord;
  unkbyte10 in_ST0;
  float10 fVar4;
  unkbyte10 extraout_ST1;
  
  puVar3 = &stack0xfffffffc;
  iVar2 = *param_1;
  DAT_01be1800 = 0;
  _DAT_01be1820 = (float)(&STAFF_STEP0)[*param_2];
  LOAD_CODE = -1;
  _DAT_0089fcec = 0;
  DAT_01be1804 = 1;
  DAT_0089fcf8 = iVar2;
  DAT_01be181c = f_5;
  DAT_0089fcf4 = f_0;
  DAT_0089fcf0 = f_0;
  for (; 0 < iVar2; iVar2 = iVar2 + -1) {
    _DAT_0089fce8 = *(float *)(&DAT_01e9cf5c + DAT_01be1804 * 4);
    *(undefined2 *)(puVar3 + -0x60) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5e) = (ushort)*(undefined4 *)(puVar3 + -0x60) | 0xc00;
    *(int *)(puVar3 + -0x5c) = (int)ROUND(_DAT_0089fce8);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x60);
    DAT_0089fce4 = *(int *)(puVar3 + -0x5c);
    if (DAT_0089fce4 < 0) {
      *(undefined4 *)(puVar3 + -0x38) = 0;
      if (DAT_0089fcf8 == DAT_01be1804) {
        *(undefined4 *)(puVar3 + -0x2c) = 0;
        DAT_01be1818 = f_0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x30) = 0;
        LOAD_I = 0;
        if (DAT_01be1804 < DAT_0089fcf8) {
          fVar1 = (float)(&DAT_01e9cf60)[DAT_01be1804];
          *(undefined2 *)(puVar3 + -0x60) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x5e) = (ushort)*(undefined4 *)(puVar3 + -0x60) | 0xc00;
          *(int *)(puVar3 + -0x5c) = (int)ROUND(fVar1);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x60);
          LOAD_I = *(int *)(puVar3 + -0x5c);
        }
        DAT_01be1818 = f_3_5;
        if ((DAT_0089fce4 == -0xe) || (DAT_0089fce4 == -0x8c)) {
          DAT_0089fce4 = LOAD_I;
          if (LOAD_I < 0) {
            if ((LOAD_I == -0xf) || (LOAD_I == -0x11)) {
              DAT_01be1818 = f_1_5;
            }
            if (LOAD_I == -0x12) {
              DAT_01be1818 = f_1;
            }
            *(undefined4 *)(puVar3 + -0x20) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x24) = 0;
          }
        }
        else {
          *(undefined4 *)(puVar3 + -0x28) = 0;
          if (DAT_0089fce4 == -0xf) {
            if (LOAD_I < -0x10) {
              DAT_01be1818 = f_8;
              if (LOAD_I == -0x12) {
                DAT_01be1818 = f_6;
              }
            }
            else {
              *(undefined4 *)(puVar3 + -0x18) = 0;
              DAT_01be1818 = f_10;
            }
            if (-1 < LOAD_CODE) {
              _DAT_0089fce0 = f_0;
            }
            *(undefined4 *)(puVar3 + -0x14) = 0;
          }
          else {
            *(undefined4 *)(puVar3 + -0x1c) = 0;
            if (DAT_0089fce4 == -0x12) {
              if (LOAD_I == -0xe) {
                DAT_01be1818 = f_4_6;
              }
            }
            else {
              *(undefined4 *)(puVar3 + -0x10) = 0;
            }
          }
        }
        DAT_0089fcf0 = DAT_01be1818 + DAT_0089fcf0;
      }
    }
    else {
      fVar4 = (float10)FUN_006033ff(puVar3,0x4cc710);
      DAT_01be1818 = (float)fVar4;
      DAT_0089fcf4 = DAT_01be1818 + DAT_0089fcf4;
      *(undefined4 *)(puVar3 + -0x34) = 0;
      in_ST0 = extraout_ST1;
    }
    (&DAT_01e9cd04)[DAT_01be1804] = DAT_01be1818;
    DAT_01be1804 = DAT_01be1804 + 1;
    LOAD_CODE = DAT_0089fce4;
  }
  DAT_01be1818 = _DAT_01be1820 / f_25;
  DAT_0089fcdc = ((**(float **)(puVar3 + 0x14) - **(float **)(puVar3 + 0x10)) -
                 DAT_01be1818 * DAT_0089fcf0) / DAT_0089fcf4;
  DAT_0089fcf4 = **(float **)(puVar3 + 0x10);
  DAT_01be1804 = 1;
  while ((&DAT_01e9bfc4)[DAT_01be1804] = DAT_0089fcf4, DAT_01be1804 <= DAT_0089fcf8) {
    if (*(float *)(&DAT_01e9cf5c + DAT_01be1804 * 4) <= f_0) {
      DAT_0089fcf0 = DAT_01be1818;
    }
    else {
      *(undefined4 *)(puVar3 + -8) = 0;
      DAT_0089fcf0 = DAT_0089fcdc;
    }
    DAT_0089fcf0 = DAT_0089fcf0 * (float)(&DAT_01e9cd04)[DAT_01be1804];
    (&DAT_01e9cd04)[DAT_01be1804] = DAT_0089fcf0;
    DAT_0089fcf4 = DAT_0089fcf0 + DAT_0089fcf4;
    DAT_01be1804 = DAT_01be1804 + 1;
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  *(undefined4 *)(puVar3 + -0xc) = 0;
  **(int **)(puVar3 + 8) = DAT_0089fcf8;
  ffree(in_ST0);
  return;
}


