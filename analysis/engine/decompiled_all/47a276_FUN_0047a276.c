// FUN_0047a276 @ 0047a276 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0047a276(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  
  puVar2 = (undefined4 *)&DAT_020b8ea0;
  puVar4 = param_1;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar4 = puVar4 + 1;
  }
  if ((DAT_01c58600 == 2) && (DAT_00828400 == ' ')) {
    pcVar3 = s_PARTS_00795090;
    puVar2 = param_1;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar2 = puVar2 + 1;
    }
  }
  iVar1 = thunk_FUN_0050273b(param_1,0x80);
  if (iVar1 == 0) {
    thunk_FUN_00502575(&DAT_007623b0,param_1,0x80,&DAT_007623b4);
  }
  else {
    DAT_0078b4e0 = 99;
  }
  return;
}


