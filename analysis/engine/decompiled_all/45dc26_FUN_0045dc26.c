// FUN_0045dc26 @ 0045dc26 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0045dd25) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0045dc26(int *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  char *pcVar4;
  char *pcVar5;
  undefined4 *puVar6;
  bool bVar7;
  char local_58 [36];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  
  puVar2 = &stack0xfffffffc;
  local_34 = 0;
  puVar3 = &stack0xfffffffc;
  if (*param_1 != 2) {
    puVar3 = &stack0xfffffffc;
    if (*param_1 == 3) goto LAB_0045dea2;
    while( true ) {
      local_30 = 0;
      if (_DAT_00824300 == 0x1b) {
        return;
      }
      if (_DAT_00824300 == 0xd) break;
      thunk_FUN_0054c768(&DAT_00824300);
      _DAT_008242fc = _DAT_00824300 + -0x41;
      bVar7 = _DAT_008242fc == 0;
      local_58[0] = DAT_00824300;
      iVar1 = 1;
      pcVar4 = &DAT_020b90a0;
      pcVar5 = local_58;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar7 = *pcVar4 == *pcVar5;
        pcVar4 = pcVar4 + 1;
        pcVar5 = pcVar5 + 1;
      } while (bVar7);
      if (bVar7) {
        local_58[3] = DAT_00824300;
        DAT_01be7840 = DAT_00824300;
        if (*param_1 != 0) goto LAB_0045dcf6;
        local_20 = 0;
        puVar3 = &stack0xfffffffc;
        goto LAB_0045de81;
      }
      local_24 = 0;
    }
    local_28 = 0;
LAB_0045dcf6:
    local_1c = 0;
    local_18 = 0x3c;
    DAT_008242f8 = 0x3c;
    do {
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 == 0) {
        local_14 = 0;
        goto LAB_0045dd7f;
      }
      DAT_008242f8 = DAT_008242f8 + -1;
      local_18 = local_18 + -1;
    } while (0 < local_18);
    DAT_008242f8 = 0;
LAB_0045dd7f:
    pcVar4 = "(1x,1a1,\':\\\',1a60/\' Type new directory name or <Enter> ->\'$) ";
    puVar6 = &DAT_020b90df;
    for (iVar1 = 0xf; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar6 = *(undefined4 *)pcVar4;
      pcVar4 = pcVar4 + 4;
      puVar6 = puVar6 + 1;
    }
    if (DAT_008242f8 == 0) {
      DAT_008242f8 = 2;
      puVar2 = &stack0xfffffffc;
      FUN_005f34d1(&stack0xfffffffc,0x45ddc3);
    }
    thunk_FUN_0058c2c9(&DAT_020b90df,0x3c,&DAT_00761638,&DAT_0076163c,"(1i2.2)",7,&DAT_008242f8);
    puVar3 = puVar2;
    FUN_005f34d1(puVar2,0x45de1c);
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      *(undefined4 *)(puVar3 + -0xc) = 0;
      goto LAB_0045dea2;
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      *(undefined4 *)(puVar3 + -8) = 0;
    }
  }
LAB_0045de81:
  if ((char)DAT_020b90a4 == ' ') {
    DAT_020b90a4._0_1_ = '\0';
  }
  FUN_00629ed0(&DAT_020b90a3,0x3c);
LAB_0045dea2:
  *(undefined4 *)(puVar3 + -4) = 0;
  return;
}


