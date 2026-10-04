// FUN_0057579a @ 0057579a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0057579a(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  DAT_01a1acb0 = 99999;
  iVar1 = 0x65;
  DAT_009a8c6c = 0;
  do {
    DAT_01a1acb8 = *(int *)(DAT_009a8c6c * 4 + param_2);
    if (DAT_01a1acb8 != 400000) {
      DAT_01c585c4 = DAT_01caf3b4 + DAT_009a8c6c;
      if (100 < DAT_01c585c4) {
        DAT_01c585c4 = 100;
      }
      DAT_009a8c68 = DAT_009a8c6c - DAT_01caf3b4;
      if (DAT_009a8c68 < 0) {
        DAT_009a8c68 = 0;
      }
      DAT_01caea48 = DAT_009a8c68;
      for (iVar2 = (DAT_01c585c4 - DAT_009a8c68) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
        DAT_01a1acbc = *(int *)(param_1 + DAT_01caea48 * 4);
        if ((DAT_01c585cc != -400000) &&
           (DAT_01a1acbc = DAT_01a1acb8 - DAT_01a1acbc, DAT_01a1acbc < DAT_01a1acb0)) {
          DAT_01a1acb0 = DAT_01a1acbc;
        }
        DAT_01caea48 = DAT_01caea48 + 1;
      }
    }
    DAT_009a8c6c = DAT_009a8c6c + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


