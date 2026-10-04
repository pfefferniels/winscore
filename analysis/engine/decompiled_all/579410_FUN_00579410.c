// FUN_00579410 @ 00579410 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00579410(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  _DAT_00793aac = 0;
  if (((*param_1 != 3) && (*param_1 < 5)) && (ITEM_I < 1 || DAT_02052748 != DAT_02052740))
  goto LAB_005796b6;
  push_words(&DAT_0076a9f4,&DAT_020b90a0);
  push_words(&DAT_0076a9f4,&DAT_020b8ea0);
  iVar2 = *param_1;
  if (iVar2 < 5) {
    if (iVar2 != 1) {
      if (iVar2 == 2) goto LAB_005795ce;
      if (iVar2 != 3) {
        if (iVar2 != 4) goto LAB_0057956e;
        FUN_005f33c9(&stack0xfffffffc,0x5794e1);
        puVar4 = puVar8;
        FUN_005f34d1(puVar8,0x5794fc);
        _DAT_020b8ea0 = ram0x020b90a6;
        DAT_020b8ea4 = DAT_020b90aa;
        *(undefined4 *)(puVar4 + -0x10) = 0;
        goto LAB_0057962d;
      }
    }
    puVar5 = &stack0xfffffffc;
    if (DAT_0078b4f0 == 0) goto LAB_005796b6;
    FUN_005f33c9(&stack0xfffffffc,0x579555);
    DAT_009a8e69 = 10;
    DAT_009a8e6a = 0xd;
LAB_00579597:
    puVar4 = puVar3;
    FUN_005f33c9(puVar3,0x5795b5);
    puVar6 = (undefined4 *)&DAT_020b8ea0;
    puVar7 = &DAT_009a8e38;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
  }
  else {
    if (6 < iVar2) {
LAB_0057956e:
      puVar3 = &stack0xfffffffc;
      FUN_005f33c9(&stack0xfffffffc,0x57958c);
      *(undefined4 *)(puVar3 + -0x14) = 0;
      goto LAB_00579597;
    }
LAB_005795ce:
    FUN_005f33c9(&stack0xfffffffc,0x5795ec);
    FUN_005f34d1(puVar4,0x579607);
    FUN_005f33c9(puVar4,0x579629);
LAB_0057962d:
    puVar6 = (undefined4 *)&DAT_020b8ea0;
    puVar7 = &DAT_009a8e38;
    for (iVar2 = 0x15; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    *(undefined4 *)(puVar4 + -0xc) = 0;
  }
  uVar1 = thunk_FUN_00595f30(&DAT_009a8e38,1);
  *(undefined4 *)(puVar4 + -0x1c) = uVar1;
  pop_words(&DAT_0076a9f4,&DAT_020b8ea0);
  pop_words(&DAT_0076a9f4,&DAT_020b90a0);
  if (*(int *)(puVar4 + -0x1c) < 0) {
    DAT_0078b4f0 = 0;
    *(undefined4 *)(puVar4 + -4) = 0;
  }
  else {
    _DAT_00793aac = 1;
  }
  DAT_0078b4e0 = 0;
  DAT_0078b378 = 0;
  puVar5 = puVar4;
LAB_005796b6:
  return *(undefined4 *)(puVar5 + -0x1c);
}


