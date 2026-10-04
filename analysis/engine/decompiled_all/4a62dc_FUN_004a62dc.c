// FUN_004a62dc @ 004a62dc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004a62dc(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      DAT_0078d920 = (DAT_01be6c48 * (DAT_01ae2864 - DAT_01be6c40)) / 0x96;
      DAT_008391bc = DAT_01ae2864 - DAT_01be6c40;
      return;
    }
    if (iVar1 == 3) {
      DAT_0078de10 = (DAT_01be6c48 * (DAT_01ae2868 - DAT_01be6c40)) / 0x96;
      DAT_008391bc = DAT_01ae2868 - DAT_01be6c40;
      return;
    }
    if (iVar1 == 4) {
      DAT_0078d924 = (DAT_01be6c48 * (DAT_01ae286c - DAT_01be6c40)) / 0x96;
      DAT_008391bc = DAT_01ae286c - DAT_01be6c40;
      return;
    }
  }
  DAT_008391bc = DAT_01ae2860 - DAT_01be6c40;
  DAT_0078de04 = (DAT_01be6c48 * (DAT_01ae2860 - DAT_01be6c40)) / 0x96;
  return;
}


