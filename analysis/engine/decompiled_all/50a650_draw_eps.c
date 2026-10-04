// draw_eps @ 0050a650 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x0050a7c6) */
/* WARNING: Removing unreachable block (ram,0x0050a807) */
/* WARNING: Removing unreachable block (ram,0x0050a89f) */
/* WARNING: Removing unreachable block (ram,0x0050a8de) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void draw_eps(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  float *pfVar6;
  undefined4 *puVar7;
  undefined1 *puVar8;
  float *pfVar9;
  bool bVar10;
  
  puVar4 = &stack0xfffffffc;
  puVar8 = &stack0xfffffffc;
  DAT_009405a4 = -1;
  DAT_009405a0 = 0;
  if (P13 == f_1) {
    FUN_0050b0c2();
    DAT_009405a0 = 1;
    if (IP13 == 99) {
      DAT_009405a0 = 1;
      return;
    }
    IP13 = 0;
    puVar4 = &stack0xfffffffc;
  }
  else {
    if ((EDIT_ITEM == 0) && (puVar4 = &stack0xfffffffc, OUTPUT_MODE < 0)) {
      iVar2 = 0xc;
      pfVar6 = &P14;
      pfVar9 = (float *)&DAT_020b90a0;
      do {
        if (iVar2 == 0) goto LAB_0050ae2c;
        iVar2 = iVar2 + -1;
        *pfVar9 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar9 = pfVar9 + 1;
      } while( true );
    }
    while( true ) {
      *(undefined4 *)(puVar4 + -0xa8) = 0;
      *(undefined4 *)(puVar4 + -0xb8) = 0x80;
      *(float **)(puVar4 + -0xb4) = &P14;
      *(uint **)(puVar4 + -0xb0) = &DAT_009405a8;
      *(undefined1 **)(puVar4 + -0xd8) = puVar4 + -0xb8;
      *(undefined **)(puVar4 + -0xdc) = &DAT_0076706c;
      *(undefined4 *)(puVar4 + -0xe0) = 0x784ff00;
      *(undefined4 *)(puVar4 + -0xe4) = 0xffffffff;
      *(undefined1 **)(puVar4 + -0xe8) = puVar4 + -0xa8;
      *(undefined4 *)(puVar4 + -0xec) = 0x50a761;
      FUN_005f47c0();
      if ((DAT_009405a8 & 1) != 0) break;
      if (-1 < DAT_009405a4) {
        *(undefined4 *)(puVar4 + -100) = 0;
        *(undefined4 *)(puVar4 + -0xd4) = 0x50af8e;
        *(undefined1 **)(puVar4 + -0xd8) = puVar4;
        *(undefined4 *)(puVar4 + -0xdc) = 0x50af8e;
        FUN_005f33c9();
        *(undefined4 *)(puVar4 + -0xd4) = 0x50afaa;
        *(undefined4 *)(puVar4 + -0xd8) = *(undefined4 *)(puVar4 + -0xd8);
        *(undefined4 *)(puVar4 + -0xdc) = 0x50afaa;
        FUN_005f33c9();
        *(undefined4 *)(puVar4 + -0xd4) = 0x50afc6;
        *(undefined4 *)(puVar4 + -0xd8) = *(undefined4 *)(puVar4 + -0xd8);
        *(undefined4 *)(puVar4 + -0xdc) = 0x50afc6;
        FUN_005f33c9();
        *(undefined4 *)(puVar4 + -0xd4) = 0x50afe1;
        *(undefined4 *)(puVar4 + -0xd8) = *(undefined4 *)(puVar4 + -0xd8);
        *(undefined4 *)(puVar4 + -0xdc) = 0x50afe1;
        FUN_005f34d1();
        iVar2 = *(int *)(puVar4 + -0xd8);
        bVar10 = puVar4 == (undefined1 *)0xd0;
        *(undefined4 *)(iVar2 + -0x4c) = 10;
        DAT_00940598 = 1;
        goto LAB_0050aff7;
      }
      puVar5 = &DAT_0078b510;
      puVar7 = &DAT_0094062c;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      *(undefined4 *)(puVar4 + -0x60) = 0x80;
      DAT_0094059c = 0x80;
      do {
        *(undefined4 *)(puVar4 + -0xd4) = 0x20;
        *(undefined4 *)(puVar4 + -0xd8) = 0x50a7e7;
        iVar2 = FUN_005f4660();
        if (iVar2 != 0) {
LAB_0050a85f:
          *(undefined4 *)(puVar4 + -0x5c) = 0;
          goto LAB_0050a866;
        }
        *(undefined4 *)(puVar4 + -0xd4) = 0x20;
        *(undefined4 *)(puVar4 + -0xd8) = 0x50a826;
        iVar2 = FUN_005f4660();
        if (iVar2 != 0) goto LAB_0050a85f;
        DAT_0094059c = DAT_0094059c + -1;
        *(int *)(puVar4 + -0x60) = *(int *)(puVar4 + -0x60) + -1;
      } while (0 < *(int *)(puVar4 + -0x60));
      DAT_0094059c = 1;
LAB_0050a866:
      DAT_0094059c = DAT_0094059c + -1;
      *(undefined4 *)(puVar4 + -0x58) = 0x80;
      DAT_009405a4 = 0x80;
      do {
        *(undefined4 *)(puVar4 + -0xd4) = 0x20;
        *(undefined4 *)(puVar4 + -0xd8) = 0x50a8be;
        iVar2 = FUN_005f4660();
        if (iVar2 != 0) {
LAB_0050a933:
          *(undefined4 *)(puVar4 + -0x54) = 0;
          goto LAB_0050a93a;
        }
        *(undefined4 *)(puVar4 + -0xd4) = 0x20;
        *(undefined4 *)(puVar4 + -0xd8) = 0x50a8fd;
        iVar2 = FUN_005f4660();
        if (iVar2 != 0) goto LAB_0050a933;
        DAT_009405a4 = DAT_009405a4 + -1;
        *(int *)(puVar4 + -0x58) = *(int *)(puVar4 + -0x58) + -1;
      } while (0 < *(int *)(puVar4 + -0x58));
      DAT_009405a4 = 0;
LAB_0050a93a:
      *(int *)(puVar4 + -0xac) = DAT_0094059c;
      iVar2 = 0x80 - *(int *)(puVar4 + -0xac);
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      *(int *)(puVar4 + -0xb0) = iVar2;
      iVar2 = 0x80 - DAT_009405a4;
      if (iVar2 < 0) {
        iVar2 = 0;
      }
      *(int *)(puVar4 + -0xb4) = iVar2;
      *(undefined4 *)(puVar4 + -0xb8) = 1;
      *(int *)(puVar4 + -0xbc) = *(int *)(puVar4 + -0xb8) + *(int *)(puVar4 + -0xb4);
      puVar8 = puVar4 + -0xd0;
      for (uVar1 = *(int *)(puVar4 + -0xb8) + *(int *)(puVar4 + -0xb4) + 7U & 0xfffffff8;
          0x1000 < (int)uVar1; uVar1 = uVar1 - 0x1000) {
        puVar8 = puVar8 + -0x1000;
      }
      iVar2 = (int)puVar8 - uVar1;
      *(int *)(puVar4 + -0xc0) = iVar2;
      *(undefined4 *)(iVar2 + -4) = 0x50a9ef;
      *(undefined1 **)(iVar2 + -8) = puVar4;
      *(undefined4 *)(iVar2 + -0xc) = 0x50a9ef;
      FUN_005f46bc();
      *(undefined4 *)(iVar2 + -4) = 0x50aa0c;
      *(undefined4 *)(iVar2 + -8) = *(undefined4 *)(iVar2 + -8);
      *(undefined4 *)(iVar2 + -0xc) = 0x50aa0c;
      FUN_005f46bc();
      *(undefined4 *)(iVar2 + -4) = 0x50aa3b;
      *(undefined4 *)(iVar2 + -8) = *(undefined4 *)(iVar2 + -8);
      *(undefined4 *)(iVar2 + -0xc) = 0x50aa3b;
      FUN_005f46bc();
      *(undefined4 *)(iVar2 + -4) = 0x50aa51;
      *(undefined4 *)(iVar2 + -8) = *(undefined4 *)(iVar2 + -8);
      *(undefined4 *)(iVar2 + -0xc) = 0x50aa51;
      FUN_005f34d1();
      puVar4 = *(undefined1 **)(iVar2 + -8);
      pfVar6 = (float *)&DAT_0094062c;
      pfVar9 = &P14;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar9 = *pfVar6;
        pfVar6 = pfVar6 + 1;
        pfVar9 = pfVar9 + 1;
      }
      *(undefined4 *)(puVar4 + -0x50) = 0;
    }
    *(undefined4 *)(puVar4 + -0x68) = 0;
  }
  puVar8 = puVar4;
  FUN_005f34d1(puVar4,0x50aa98);
  if (DAT_0205274c == 0) {
    pfVar6 = &P14;
    pfVar9 = (float *)&DAT_01c59580;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *pfVar9 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar9 = pfVar9 + 1;
    }
  }
  DAT_01be6cd8 = 0xffffffff;
  if (DAT_009405a0 == 0) goto LAB_0050aad8;
  *(undefined4 *)(puVar8 + -0x40) = 0;
  while( true ) {
    FUN_0050bea3();
    DAT_009405a0 = 0;
    if (IP11 == -9999) {
      *(undefined4 *)(puVar8 + -0xc) = 4;
      DAT_00940598 = 1;
      do {
        (&DAT_020b9454)[DAT_00940598] = *(undefined4 *)(DAT_00940598 * 4 + 0x1a2776c);
        (&P6)[DAT_00940598] = *(float *)(DAT_00940598 * 4 + 0x1a2776c);
        DAT_00940598 = DAT_00940598 + 1;
        *(int *)(puVar8 + -0xc) = *(int *)(puVar8 + -0xc) + -1;
      } while (0 < *(int *)(puVar8 + -0xc));
      *(undefined4 *)(puVar8 + -8) = 0;
    }
    else {
      *(undefined4 *)(puVar8 + -0x10) = 0;
    }
LAB_0050aad8:
    if (IP11 == -9999) break;
    add_point(&X_POS,&Y_POS,&DAT_00767054);
    _DAT_00940578 = STEP * f_7;
    DAT_00940580 = f_3;
    if (P5 != f_0) {
      DAT_00940580 = P5;
    }
    _DAT_00940594 = DAT_00940580;
    if (P6 != f_0) {
      _DAT_00940594 = P6;
    }
    DAT_00940580 = _DAT_00940578 * DAT_00940580 + X_POS;
    _DAT_00940594 = _DAT_00940578 * _DAT_00940594 + Y_POS;
    add_point(&DAT_00940580,&Y_POS,&DAT_00767050);
    add_point(&DAT_00940580,&DAT_00940594,&DAT_00767050);
    add_point(&X_POS,&DAT_00940594,&DAT_00767050);
    add_point(&X_POS,&Y_POS,&DAT_00767050);
    if (DAT_009405a0 == 0) {
      *(undefined4 *)(puVar8 + -0x34) = 0;
      return;
    }
    *(undefined4 *)(puVar8 + -0x38) = 0;
LAB_0050ae2c:
    *(undefined4 *)(puVar8 + -0xa8) = 0;
    *(undefined4 *)(puVar8 + -0xb8) = 0x80;
    *(float **)(puVar8 + -0xb4) = &P14;
    *(uint **)(puVar8 + -0xb0) = &DAT_009405a8;
    FUN_005f47c0(puVar8 + -0xa8,0xffffffff,0x784ff00,&DAT_0076706c,puVar8 + -0xb8);
    if ((DAT_009405a8 & 1) == 0) {
      *(undefined4 *)(puVar8 + -0x18) = 0;
      return;
    }
    *(undefined4 *)(puVar8 + -0x1c) = 0;
    if (DAT_009405a0 == 0) {
      *(undefined4 *)(puVar8 + -0x14) = 0;
      FUN_0050b5ce();
      return;
    }
  }
  *(undefined4 *)(puVar8 + -0x3c) = 0;
  NPT = 1;
  _DAT_00940590 = 1;
  if (P5 == f_0) {
    P5 = f_1;
  }
  _DAT_0094058c = P6;
  if (P6 == f_0) {
    _DAT_0094058c = P5;
  }
  DAT_00940580 = STEP / f_0_45;
  _DAT_00940588 = (P9 - P7) * DAT_00940580 * P5 + X_POS;
  _DAT_0094058c = (P10 - P8) * DAT_00940580 * _DAT_0094058c + Y_POS;
  add_point(&X_POS,&Y_POS,&DAT_00767054);
  add_point(&X_POS,&DAT_0094058c,&DAT_00767050);
  add_point(&DAT_00940588,&DAT_0094058c,&DAT_00767050);
  add_point(&DAT_00940588,&Y_POS,&DAT_00767050);
  add_point(&X_POS,&Y_POS,&DAT_00767050);
  add_point(&DAT_00940588,&DAT_0094058c,&DAT_00767050);
  add_point(&X_POS,&DAT_0094058c,&DAT_00767054);
  add_point(&DAT_00940588,&Y_POS,&DAT_00767050);
  if (IP12 != 0) {
    thunk_FUN_0042a5f4(&DAT_00940590,&X_POS,&Y_POS,&P12);
  }
  *(undefined4 *)(puVar8 + -4) = 0;
  return;
LAB_0050aff7:
  iVar3 = 0x20;
  pfVar6 = &P14;
  pfVar9 = (float *)(&DAT_0094062c + DAT_00940598 * 0x20);
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar10 = *pfVar6 == *pfVar9;
    pfVar6 = pfVar6 + 1;
    pfVar9 = pfVar9 + 1;
  } while (bVar10);
  if (bVar10) {
    *(undefined4 *)(iVar2 + -0x48) = 0;
    goto LAB_0050b0a3;
  }
  DAT_00940598 = DAT_00940598 + 1;
  *(int *)(iVar2 + -0x4c) = *(int *)(iVar2 + -0x4c) + -1;
  bVar10 = *(int *)(iVar2 + -0x4c) == 0;
  if (*(int *)(iVar2 + -0x4c) < 1) {
    *(undefined4 *)(puVar4 + -0xd4) = 0x200;
    *(undefined4 **)(puVar4 + -0xd8) = &DAT_009ae2bc;
    *(undefined4 *)(puVar4 + -0xdc) = 0x50b050;
    thunk_FUN_0042ac4e();
    DAT_00795b7c = DAT_00795b7c + 1;
    if (10 < DAT_00795b7c) {
      DAT_00795b7c = 1;
    }
    pfVar6 = &P14;
    pfVar9 = (float *)(&DAT_0094062c + DAT_00795b7c * 0x20);
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar9 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar9 = pfVar9 + 1;
    }
    pfVar6 = &P14;
    pfVar9 = (float *)&DAT_009405ac;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *pfVar9 = *pfVar6;
      pfVar6 = pfVar6 + 1;
      pfVar9 = pfVar9 + 1;
    }
LAB_0050b0a3:
    DAT_009405a0 = 1;
    *(undefined4 *)(iVar2 + -0x44) = 0;
    return;
  }
  goto LAB_0050aff7;
}


