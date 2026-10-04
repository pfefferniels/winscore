// FUN_004e1b9f @ 004e1b9f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004e1b9f(int *param_1)

{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if ((char)DAT_01e62c88 == 'N') {
    *param_1 = 5;
  }
  iVar3 = *param_1;
  DAT_008c8854 = 1;
  for (; 0 < iVar3; iVar3 = iVar3 + -1) {
    puVar1 = &DAT_020b90a0 + DAT_0078d938;
    DAT_0078d938 = DAT_0078d938 + 1;
    *puVar1 = *(undefined1 *)((int)&DAT_01e62c80 + DAT_008c8854 + 3);
    DAT_008c8854 = DAT_008c8854 + 1;
  }
  if (DAT_01fbb700 != 2) {
    FUN_005f34d1(&stack0xfffffffc,0x4e1c4b);
  }
  (&DAT_020b90a0)[DAT_0078d938] = 0;
  puVar2 = (undefined4 *)&DAT_020b90a0;
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  thunk_FUN_005494b2(&DAT_020b8ea0,0x200,&DAT_0078d938);
  return;
}


