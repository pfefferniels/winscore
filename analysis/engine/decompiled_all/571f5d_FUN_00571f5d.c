// FUN_00571f5d @ 00571f5d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00571f5d(void)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  
  puVar5 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  if (DAT_02091d04 != -0x4d2) {
    FUN_005f33c9(&stack0xfffffffc,0x571f8f);
    puVar2 = puVar5;
    FUN_005f34d1(puVar5,0x571faa);
  }
  FUN_005f34d1(puVar2,0x571fcb);
  puVar3 = *(undefined4 **)(puVar2 + 8);
  puVar4 = &DAT_009a8480;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  DAT_020b8ea0._0_1_ = thunk_FUN_0059c430(&DAT_009a8480);
  if ((char)DAT_020b8ea0 == '\x02') {
    *(undefined4 *)(puVar2 + -4) = 0;
  }
  else {
    puVar3 = &DAT_009ae2bc;
    puVar4 = (undefined4 *)&DAT_020b8ea0;
    for (iVar1 = 0x80; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
  }
  return;
}


