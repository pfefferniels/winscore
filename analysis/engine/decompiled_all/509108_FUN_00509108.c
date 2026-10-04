// FUN_00509108 @ 00509108 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00509108(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  for (iVar1 = 1; iVar1 < 0x11; iVar1 = iVar1 + 1) {
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + iVar1 * 0x40 + 0x1f9393c) = 0;
    }
  }
  DAT_01b34574 = 0;
  DAT_01b9d5c0 = 0;
  thunk_FUN_00505e84();
  for (iVar1 = 1; iVar1 < 0x11; iVar1 = iVar1 + 1) {
    for (iVar2 = 1; iVar2 < 0x11; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + iVar1 * 0x40 + param_2 + -0x44) =
           *(undefined4 *)(iVar2 * 4 + iVar1 * 0x40 + 0x1f9393c);
    }
  }
  for (iVar1 = 1; iVar1 < 0x11; iVar1 = iVar1 + 1) {
    for (iVar2 = 1; iVar2 < 5; iVar2 = iVar2 + 1) {
      *(undefined4 *)(iVar2 * 4 + iVar1 * 0x10 + param_1 + -0x14) =
           *(undefined4 *)(iVar2 * 4 + iVar1 * 0x10 + 0x1a7288c);
    }
  }
  return;
}


