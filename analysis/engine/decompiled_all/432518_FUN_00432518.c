// FUN_00432518 @ 00432518 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00432518(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  float *pfVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  undefined4 local_6c;
  float *local_68;
  undefined4 local_60 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  
  puVar8 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (DAT_02052740 == 0) {
    local_40 = 0;
    if ((IP13 != 1) && (P14 != f_0)) {
      if (9 < IP5) {
        return;
      }
      thunk_FUN_0054c590(&P5,&DAT_01cf8f00,&DAT_007600c4);
      goto LAB_00432625;
    }
    local_34 = 0;
LAB_0043267d:
    if (DAT_02052740 == 0) {
      thunk_FUN_0050b0c2();
    }
  }
  else {
    local_60[0] = 0;
    local_6c = 0x80;
    local_68 = &P14;
    iVar2 = FUN_005fdbd0(local_60,DAT_02052740,0x784ff01,&DAT_007600c0,&local_6c,&DAT_0078f330);
    if (iVar2 != 0) goto LAB_00432968;
    IP13 = 0;
    P13 = f_0;
    IP11 = -9999;
    DAT_020b9468 = f_m9999;
    P11 = f_m9999;
    local_38 = 0;
    local_3c = 0;
LAB_00432625:
    thunk_FUN_0054cd71(&P14,0x80,&DAT_007600b8,&DAT_007f1544);
    thunk_FUN_00571b78(&P14,0x80,&DAT_007600b4,3);
    if ((IP13 != 0) || (P14 == f_0)) goto LAB_0043267d;
  }
  FUN_005f34d1(&stack0xfffffffc,0x4326a8);
  puVar3 = puVar8;
  FUN_005f34d1(puVar8,0x4326c9);
  if (IP13 != 99) {
    if (P13 < f_0) {
      IP13 = 0;
      P13 = f_0;
      *(undefined4 *)(puVar3 + -0x20) = 0;
      return;
    }
    *(undefined4 *)(puVar3 + -0x24) = 0;
    pfVar4 = &P14;
    pfVar6 = (float *)&DAT_007f15f0;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar6 = *pfVar4;
      pfVar4 = pfVar4 + 1;
      pfVar6 = pfVar6 + 1;
    }
    puVar5 = &DAT_007f15f0;
    puVar7 = &DAT_007f1570;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar7 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar7 = puVar7 + 1;
    }
    thunk_FUN_0054c590(&P5,&DAT_01cf8f00,&DAT_007600ac);
    *(undefined4 *)(puVar3 + -0x1c) = 0;
    while( true ) {
      *(undefined4 *)(puVar3 + -0x5c) = 0;
      *(undefined4 *)(puVar3 + -0x70) = 0x80;
      *(undefined4 **)(puVar3 + -0x6c) = &DAT_007f1570;
      *(uint **)(puVar3 + -0x68) = &DAT_007f1550;
      FUN_005f47c0(puVar3 + -0x5c,0xffffffff,0x784ff00,&DAT_007600a0,puVar3 + -0x70);
      if ((DAT_007f1550 & 1) != 0) break;
      if ((char)DAT_007f1570 == '\\') goto LAB_0043281e;
      FUN_005f33c9(puVar3,0x4327c9);
      FUN_005f33c9(puVar3,0x4327e5);
      FUN_005f33c9(puVar3,0x432807);
      *(undefined4 *)(puVar3 + -0xc) = 0;
    }
    *(undefined4 *)(puVar3 + -0x10) = 0;
LAB_0043281e:
    DAT_007f1540 = 3;
    *(undefined4 *)(puVar3 + -0x5c) = 0;
    *(undefined4 *)(puVar3 + -0x80) = 0x80;
    *(undefined4 **)(puVar3 + -0x7c) = &DAT_007f1570;
    *(undefined4 *)(puVar3 + -0x78) = 3;
    *(undefined **)(puVar3 + -0x74) = &DAT_00760088;
    *(undefined4 *)(puVar3 + -0x70) = 6;
    *(char **)(puVar3 + -0x6c) = "binary";
    *(undefined4 *)(puVar3 + -0x68) = 0x200;
    *(undefined4 *)(puVar3 + -100) = 2;
    uVar1 = FUN_005f6540(puVar3 + -0x5c,3,0x784ff01,&DAT_00760068,puVar3 + -0x80);
    *(undefined4 *)(puVar3 + -8) = uVar1;
    if (*(int *)(puVar3 + -8) == 0) {
      if (DAT_007f1540 < 0) {
        *(undefined4 *)(puVar3 + -4) = 0;
      }
      else {
        if (DAT_0205274c == 0) {
          puVar5 = &DAT_007f1570;
          puVar7 = &DAT_01c59580;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        FUN_00432998();
      }
    }
    else {
      thunk_FUN_0042ac4e(&DAT_007f1570,0x80);
      P1 = f_0;
      *(undefined4 *)(puVar3 + -0x18) = 0;
    }
    thunk_FUN_0054c590(&DAT_01cf8f00,&P5,&DAT_007600c4);
    _DAT_007f153c = 0x19;
    FUN_005f34d1(puVar3,0x432945);
    return;
  }
LAB_00432968:
  for (iVar2 = 1; iVar2 < 0x33; iVar2 = iVar2 + 1) {
    *(float *)(&P0 + iVar2 * 4) = f_0;
  }
  *(undefined4 *)(puVar3 + -0x28) = 0;
  return;
}


