// FUN_00509048 @ 00509048 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00509048(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  FUN_00508c9f(param_1,1,&IP1,&DAT_00940400);
  iVar2 = IP2;
  if (IP1 < 0x11) {
    DAT_009403fc = 1;
    for (iVar2 = (DAT_00940400 + 1) / 2; 0 < iVar2; iVar2 = iVar2 + -1) {
      *(int *)(param_3 + -4 + *(int *)(&IP0 + DAT_009403fc * 4) * 4) = (&IP1)[DAT_009403fc];
      DAT_009403fc = DAT_009403fc + 2;
    }
  }
  else {
    for (iVar1 = 1; iVar1 < 0x11; iVar1 = iVar1 + 1) {
      *(int *)(param_3 + -4 + iVar1 * 4) = iVar2;
    }
  }
  return;
}


