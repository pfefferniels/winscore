// FUN_004faa2c @ 004faa2c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004faa2c(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  DAT_01c58604 = 1;
  for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
    (&DAT_009012ec)[iVar1] = 0;
  }
  DAT_009012ec = 0;
  iVar1 = *param_4;
  DAT_009012e8 = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_009012e4 = *(int *)(DAT_009012e8 * 4 + param_2 + -4);
    if (*(float *)(param_1 + DAT_009012e4 * 4) == f_14) {
      if ((f_3 < *(float *)(param_1 + -4 + DAT_009012e4 * 4)) &&
         ((float)DAT_01c58604 < *(float *)(param_1 + 0xc + DAT_009012e4 * 4))) {
        DAT_01c58604 = (int)ROUND(*(float *)(param_1 + 0xc + DAT_009012e4 * 4));
      }
    }
    else if (*(float *)(param_1 + DAT_009012e4 * 4) == f_8) {
      DAT_009012ec = DAT_009012ec + 1;
      (&DAT_009012ec)[DAT_009012ec] = (int)ROUND(*(float *)(param_1 + 4 + DAT_009012e4 * 4));
    }
    DAT_009012e8 = DAT_009012e8 + 1;
  }
  DAT_009012e0 = 1;
  DAT_009012dc = f_1;
  while( true ) {
    DAT_009012e8 = 2;
    iVar1 = DAT_009012ec;
    while( true ) {
      iVar1 = iVar1 + -1;
      if (iVar1 < 1) {
        do {
          iVar1 = *param_4;
          DAT_009012d4 = 1;
          for (; 0 < iVar1; iVar1 = iVar1 + -1) {
            DAT_009012e4 = *(int *)(DAT_009012d4 * 4 + param_2 + -4);
            DAT_009012d0 = (int)ROUND(*(float *)(param_1 + 4 + DAT_009012e4 * 4));
            if (DAT_009012d0 == (&DAT_009012ec)[DAT_009012e0]) {
              *(float *)(param_1 + 4 + DAT_009012e4 * 4) = DAT_009012dc;
            }
            DAT_009012d4 = DAT_009012d4 + 1;
          }
          DAT_009012dc = DAT_009012dc + f_1;
          DAT_009012e0 = DAT_009012e0 + 1;
        } while (DAT_009012e0 <= DAT_009012ec);
        return;
      }
      if ((&DAT_009012ec)[DAT_009012e8] <= (&DAT_009012e8)[DAT_009012e8]) break;
      DAT_009012e8 = DAT_009012e8 + 1;
    }
    if ((&DAT_009012ec)[DAT_009012e8] == (&DAT_009012e8)[DAT_009012e8]) break;
    thunk_FUN_0054c68f(&DAT_009012ec + DAT_009012e8,&DAT_009012e8 + DAT_009012e8);
  }
  FUN_005f33c9(&stack0xfffffffc,0x4facb5);
  FUN_005f34d1(puVar2,0x4facd0);
  DAT_020b8ed0 = 10;
  FUN_005f33c9(puVar2,0x4facf9);
  _DAT_009012d8 = DAT_009012e8 + -1;
  *(undefined4 *)(puVar2 + -0x58) = 0;
  *(undefined4 *)(puVar2 + -0x68) = 2;
  *(undefined **)(puVar2 + -100) = &DAT_020b8ee8;
  *(undefined **)(puVar2 + -0x60) = &DAT_009012d8;
  FUN_005f34f0(puVar2 + -0x58,0x784ff00,&DAT_00766980,puVar2 + -0x68,&DAT_00795140);
  thunk_FUN_0054d831(&DAT_020b8ea0,0x200);
  DAT_0078b4e0 = 0x2d;
  *(undefined4 *)(puVar2 + -0x10) = 0;
  return;
}


