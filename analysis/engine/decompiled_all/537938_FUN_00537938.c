// FUN_00537938 @ 00537938 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00537938(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  DAT_0099a8fc = 0;
  DAT_0099a900 = DAT_020b8ea4;
  DAT_020b8ea0 = CONCAT11(0x42,(undefined1)DAT_020b8ea0);
  DAT_0099a904 = _DAT_020b8ea0;
  puVar3 = &DAT_009ae2bc;
  puVar4 = (undefined4 *)&DAT_020b8ea0;
  for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  if (*param_1 == 2) {
    FUN_00537bb4(&DAT_01e99980,0x80,&DAT_0099a8fc);
  }
  else {
    thunk_FUN_0054c78b(&DAT_0099a8f8);
    FUN_00537db4(&DAT_01e99980,0x80,&DAT_0099a8fc);
  }
  *param_1 = 0;
  DAT_0099a8f4 = 1;
  for (iVar1 = DAT_0099a8fc; 0 < iVar1; iVar1 = iVar1 + -1) {
    FUN_00537f49(DAT_0099a8f4 * 0x80 + 0x1e99900,0x80,param_1);
    DAT_0099a8f4 = DAT_0099a8f4 + 1;
  }
  puVar2 = &stack0xfffffffc;
  if ((1 < *param_1) && (puVar2 = &stack0xfffffffc, DAT_0099a900 == 'R')) {
    DAT_0099a8f4 = *param_1;
    DAT_0099a908 = 1;
    iVar1 = *param_1 / 2;
    while (puVar2 = puVar5, 0 < iVar1) {
      puVar3 = (undefined4 *)(&DAT_01c4eec4 + DAT_0099a908 * 0x80);
      puVar4 = &DAT_0099a910;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      FUN_005f33c9(puVar5,0x537af6);
      puVar3 = &DAT_0099a910;
      puVar4 = (undefined4 *)(&DAT_01c4eec4 + DAT_0099a8f4 * 0x80);
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
      DAT_0099a8f4 = DAT_0099a8f4 + -1;
      DAT_0099a908 = DAT_0099a908 + 1;
      *(int *)(puVar5 + -4) = *(int *)(puVar5 + -4) + -1;
      iVar1 = *(int *)(puVar5 + -4);
    }
  }
  DAT_01c4ef40 = **(undefined4 **)(puVar2 + 8);
  _DAT_020b8ea0 = DAT_0099a904;
  FUN_005f33c9(puVar2,0x537b8c);
  FUN_005f34d1(puVar2,0x537ba7);
  return;
}


