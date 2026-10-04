// FUN_00429178 @ 00429178 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00429178(int *param_1,int *param_2,int *param_3,float *param_4,float *param_5,
                 float *param_6,float *param_7,int *param_8,undefined4 param_9)

{
  int iVar1;
  
  DAT_007d3534 = *param_1 / 10;
  load_symbol_library(&DAT_007d3534,&DAT_007d3560,&DAT_007d3578,0x18);
  if (DAT_007d3534 != -999) {
    DAT_007d3534 = *param_1 % 10 + 1;
    P10 = f_0;
    if (0x2c < *param_2) {
      *param_3 = *param_3 + -1;
    }
    DAT_007d3528 = (int)*(short *)(&DAT_007d355e + DAT_007d3534 * 2);
    iVar1 = *(short *)(&DAT_007d3560 + DAT_007d3534 * 2) - DAT_007d3528;
    DAT_007d3530 = DAT_007d3528;
    _DAT_007d352c = NPT;
    DAT_007d3534 = iVar1;
    if ((DAT_0078b4e0 == 0x56ce) && (0x21 < iVar1)) {
      iVar1 = iVar1 + -0xb;
      DAT_007d3534 = iVar1;
    }
    for (; 0 < iVar1; iVar1 = iVar1 + -1) {
      _DAT_007d3524 = *param_4 * *(float *)(&DAT_01dc41fc + DAT_007d3528 * 4);
      _DAT_007d3520 = _DAT_007d3524 + *param_6;
      _DAT_007d351c = *param_5 * *(float *)(&DAT_01e123fc + DAT_007d3528 * 4) + *param_7;
      DAT_007d3518 = (int)*(short *)(&DAT_01d9d0fe + DAT_007d3528 * 2);
      if (DAT_007d3518 < 0) {
        DAT_007d3518 = 0;
      }
      add_point(&DAT_007d3520,&DAT_007d351c,&DAT_007d3518);
      DAT_007d3528 = DAT_007d3528 + 1;
    }
    if ((float)*param_8 != f_0) {
      thunk_FUN_0042a5f4(&DAT_007d352c,param_6,param_7,param_9);
    }
  }
  return;
}


