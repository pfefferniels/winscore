// FUN_004e7f79 @ 004e7f79 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004e8499) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e7f79(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int iVar9;
  undefined1 *puVar10;
  undefined1 *puVar11;
  
  puVar10 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar11 = &stack0xfffffffc;
  if (DAT_01fbb8a0 == 9) {
    DAT_01fbb7e0 = VEC_N;
    if ((char)DAT_020b8ea0 == '|') {
      thunk_FUN_0041b011();
      fVar1 = P4;
    }
    else {
      thunk_FUN_00518448();
      if (((char)DAT_020b8ea0 == 'B') || (P1 == f_0 && P3 == f_0)) goto LAB_004e84fa;
      thunk_FUN_0041aa88();
      fVar1 = (P2 + P1) - f_1;
    }
    DAT_01fbb864 = (int)ROUND(fVar1);
    thunk_FUN_004a30bb(&DAT_008d12f8,&DAT_00766140);
    if (DAT_008d12f8 != -2) {
      if (DAT_008d12f8 != 0) {
        DAT_01fbb860 = (int)ROUND(P1);
        DAT_01fbb868 = f_0;
        DAT_01fbb86c = DAT_01fbb8b8;
        thunk_FUN_0041b68a();
        FUN_005f33c9(&stack0xfffffffc,0x4e859e);
        FUN_005f34d1(puVar6,0x4e85b9);
        DAT_01fbb8a0 = 10;
        *(undefined4 *)(puVar6 + -0x24) = 0;
        goto LAB_004e8621;
      }
      VEC_N = DAT_01fbb7e0;
LAB_004e85e4:
      FUN_005f33c9(&stack0xfffffffc,0x4e8602);
      puVar6 = puVar11;
      FUN_005f34d1(puVar11,0x4e861d);
LAB_004e8621:
      puVar7 = &DAT_009ae2bc;
      puVar8 = (undefined4 *)&DAT_020b90a0;
      for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar8 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar8 = puVar8 + 1;
      }
      *(undefined4 *)(puVar6 + -0x40) = 0;
      return;
    }
LAB_004e8460:
    *DAT_01fbb7c0 = DAT_01fbb7e0 + -1;
    iVar2 = VEC_STRIDE;
    iVar5 = VEC_BASE;
    iVar4 = VEC_STRIDE * VEC_LBOUND;
    iVar9 = DAT_01fbb7e0;
    for (iVar3 = 1; iVar3 < 0x11; iVar3 = iVar3 + 1) {
      *(undefined4 *)((iVar5 - iVar4) + iVar2 * iVar9) = 0;
      iVar9 = iVar9 + 1;
    }
  }
  else {
    if (DAT_01fbb8a0 == 10) {
      if (((char)DAT_020b8ea0 != '|') && ((char)DAT_020b8ea0 != '~')) {
        thunk_FUN_00518448();
        DAT_01fbb7e0 = VEC_N;
        thunk_FUN_0041aa88();
        thunk_FUN_004a30bb(&DAT_008d12f8,&DAT_00766170);
        if (DAT_008d12f8 == -2) goto LAB_004e8460;
        if (DAT_008d12f8 != 0) goto LAB_004e815d;
        VEC_N = DAT_01fbb7e0;
      }
      DAT_01fbb7e4 = VEC_N;
      thunk_FUN_0041b011();
      thunk_FUN_004a30bb(&DAT_008d12f8,&DAT_00766170);
      if (DAT_008d12f8 == -2) goto LAB_004e8460;
      if (DAT_008d12f8 == 0) {
        VEC_N = DAT_01fbb7e4;
        puVar7 = (undefined4 *)&DAT_020b90a0;
        puVar8 = &DAT_009ae2bc;
        for (iVar5 = 0x80; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *puVar7;
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        }
        thunk_FUN_00549422();
        return;
      }
    }
    else {
      DAT_008d12fc = DAT_020b8ea0;
      if (DAT_02052740 == 0) {
        thunk_FUN_0041b68a();
        DAT_01fbb8a0 = 9;
        goto LAB_004e85e4;
      }
      thunk_FUN_00518448();
      DAT_01fbb860 = (int)ROUND(P1);
      DAT_01fbb868 = f_0;
      DAT_01fbb86c = DAT_01fbb8b8;
      DAT_01fbb864 = (int)ROUND((P2 + P1) - f_1);
      thunk_FUN_00518448();
    }
LAB_004e815d:
    DAT_01fbb890 = (int)ROUND(P1);
    DAT_01fbb880 = f_0;
    _DAT_01fbb884 = DAT_01fbb8b8;
    DAT_01fbb8a4 = 1;
    if (MAX_STAFF < DAT_01fbb890) {
      DAT_01fbb890 = DAT_01fbb860;
    }
    if (_DAT_008d12f4 == f_0) {
      _DAT_008d12f4 = DAT_01fbb86c;
    }
    if ((float)DAT_01fbb860 == P1) {
      thunk_FUN_0054d831("Cannot move or copy to same place.",0x23);
      FUN_005f33c9(&stack0xfffffffc,0x4e8225);
      FUN_005f34d1(puVar10,0x4e8240);
      *(undefined4 *)(puVar10 + -0x10) = 0;
      return;
    }
    DAT_01fbb874 = 1;
    DAT_01fbb878 = 1;
    DAT_01fbb87c = ITEM_I;
    thunk_FUN_0049b1d8();
    _DAT_009c6ad4 = f_0;
    DAT_01fbb8a0 = 0;
    thunk_FUN_00468df8(&DAT_00766144);
    if (DAT_020492a0 == 0) {
      thunk_FUN_00410362();
    }
    else {
      DAT_01fbb870 = f_0;
      if (DAT_008d12fc == 0x5343) {
        thunk_FUN_0044236f();
      }
      P1 = (float)(DAT_01fbb890 - DAT_01fbb860);
      thunk_FUN_005725fa();
      FUN_004e7eea();
      draw_items();
      DAT_020527e8 = ITEM_I;
    }
    DAT_0078b4ec = 0;
    DAT_0078b4f0 = 1;
    DAT_0078b4e0 = 0;
  }
  thunk_FUN_00549422();
  DAT_01fbb8a4 = 0;
  thunk_FUN_00468df8(&DAT_00766144);
LAB_004e84fa:
  DAT_01fbb8a0 = 0;
  if (DAT_008d12f8 == -2) {
    draw_items();
  }
  thunk_FUN_00597b60(0xffffffff);
  return;
}


