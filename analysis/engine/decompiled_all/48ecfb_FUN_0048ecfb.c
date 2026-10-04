// FUN_0048ecfb @ 0048ecfb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0048edd0) */
/* WARNING: Removing unreachable block (ram,0x0048ed5c) */
/* WARNING: Removing unreachable block (ram,0x0048ee24) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0048ecfb(void)

{
  int iVar1;
  undefined1 *puVar2;
  char *pcVar3;
  undefined4 *puVar4;
  undefined2 in_FPUControlWord;
  unkbyte10 Var5;
  unkbyte10 extraout_ST0;
  float10 fVar6;
  
  puVar2 = &stack0xfffffffc;
  Var5 = FUN_005f34d1(&stack0xfffffffc,0x48ed21);
  if (EDIT_ITEM == 0) {
    *(undefined4 *)(puVar2 + -0x38) = 0x33;
    DAT_0082970c = 0x14;
    do {
      iVar1 = FUN_005f4660(0x20);
      if (iVar1 != 0) {
        FUN_005f46bc(puVar2,0x48edf4);
        FUN_005f34d1(puVar2,0x48ee0a);
        FUN_005f46bc(puVar2,0x48ee48);
        Var5 = FUN_005f34d1(puVar2,0x48ee5e);
        *(undefined4 *)(puVar2 + -0x30) = 0;
        break;
      }
      *(undefined4 *)(puVar2 + -0x34) = 0;
      *(undefined4 *)(puVar2 + -0x2c) = 0;
      DAT_0082970c = DAT_0082970c + 1;
      *(int *)(puVar2 + -0x38) = *(int *)(puVar2 + -0x38) + -1;
      Var5 = extraout_ST0;
    } while (0 < *(int *)(puVar2 + -0x38));
    DAT_0082970c = DAT_0082970c + 2;
    ffree(Var5);
    Var5 = FUN_0048f4eb(&DAT_0078b510,0x80,&DAT_0082970c);
    _DAT_00829714 = 0xc;
    DAT_020527c8 = 0;
    DAT_0078b370 = 1;
    if (DAT_0078d840 == f_1) {
      *(undefined4 *)(puVar2 + -0x28) = 0;
      goto LAB_0048f4e2;
    }
  }
  if (DAT_0078dc45 == 0) {
    Var5 = FUN_005f34d1(puVar2,0x48eeff);
    if (DAT_0078d840 != f_1) {
      DAT_01a1499c = (float)i_1850286112;
      DAT_01a149a0 = i_538983779;
      DAT_01a149a4 = i_538976288;
      DAT_01a149a8 = DAT_00762ce8;
      ffree(Var5);
      thunk_FUN_0058c248(&DAT_01a1499c,0xd,&DAT_00762ccc,&DAT_00762cd0,"(1f5.2)",7,&DAT_0078d840);
    }
  }
  else {
    DAT_01a1499c = f_655874;
    DAT_01a149a0 = i_540894062;
    DAT_01a149a4 = i_538976288;
    DAT_01a149a8 = DAT_00762cc8;
    ffree(Var5);
    Var5 = thunk_FUN_0058c2c9(&DAT_01a1499c,0xd,&DAT_00762cac,&DAT_00762cb0,"(1i2)",5,&DAT_0078dc45)
    ;
    ffree(Var5);
    thunk_FUN_0058c248(&DAT_01a1499c,0xd,&DAT_00762ca4,&DAT_00762ca8,"(1f5.2)",7,&DAT_0078dc3d);
  }
  _DAT_00829714 = 0xe;
  *(undefined2 *)(puVar2 + -0x60) = in_FPUControlWord;
  *(ushort *)(puVar2 + -0x5e) = (ushort)*(undefined4 *)(puVar2 + -0x60) | 0xc00;
  *(int *)(puVar2 + -0x5c) = (int)ROUND(DAT_020b9440);
  DAT_00829708 = *(int *)(puVar2 + -0x5c);
  if (DAT_00829708 == 7) {
    if (DAT_020b9458 != f_0) {
      DAT_00829708 = 0x17;
    }
    if ((f_19 < DAT_020b9458) && (DAT_020b9458 < f_26)) {
      DAT_00829708 = 0x14;
    }
    if (DAT_020b9458 == f_1) {
      DAT_00829708 = 0x13;
    }
  }
  else if (DAT_00829708 == 0xc) {
    if (DAT_020b9450 < f_0) {
      DAT_00829708 = 0x15;
    }
    if (DAT_020b9450 == f_10) {
      DAT_00829708 = 0x16;
    }
  }
  FUN_005f33c9(puVar2,0x48f128);
  Var5 = FUN_005f34d1(puVar2,0x48f143);
  DAT_01a1498c = 0;
  DAT_01a14bb4 = EDIT_ITEM;
  ffree(Var5);
  Var5 = thunk_FUN_0058c2c9(&DAT_01c4c860,0x200,&DAT_00762cac,&DAT_00762c8c,"(1i4)",5,&EDIT_ITEM);
  ram0x01c4c865 = DAT_01a14984;
  DAT_01c4c869 = DAT_01a14988;
  DAT_01c4c86d = DAT_01a1498c;
  ffree(Var5);
  Var5 = thunk_FUN_0058c2c9(&DAT_01c4c860,0x200,&DAT_00762c7c,&DAT_00762c80,"(1i1)",5,&DAT_020b8e50)
  ;
  ffree(Var5);
  Var5 = thunk_FUN_0058c248(&DAT_01c4c860,0x200,&DAT_00762c6c,&DAT_00762c70,"(1f5.1)",7,
                            &DAT_020b9444);
  ffree(Var5);
  Var5 = thunk_FUN_0058c248(&DAT_01c4c860,0x200,&DAT_00762c5c,&DAT_00762c60,"(1f7.2)",7,
                            &DAT_020b9448);
  DAT_00829710 = 0x21;
  if (((DAT_020b8e50 == 0xf) || (DAT_020b8e50 == 0xb)) ||
     (DAT_020b8e50 == 0x10 && DAT_020b9474 != f_m1)) {
    DAT_020527c8 = 0xd;
  }
  iVar1 = DAT_020527c8 + -3;
  *(int *)(puVar2 + -0x24) = iVar1;
  DAT_0082970c = 4;
  while (0 < iVar1) {
    fVar6 = (float10)*(float *)(&DAT_020b943c + DAT_0082970c * 4);
    if ((float10)f_1000 <= ABS(fVar6)) {
      *(int *)(puVar2 + -0x60) = DAT_00829710 + 7;
      ffree(fVar6);
      Var5 = thunk_FUN_0058c248(&DAT_01c4c860,0x200,&DAT_00829710,puVar2 + -0x60,"(1f8.1)",7,
                                &DAT_020b943c + DAT_0082970c * 4);
    }
    else {
      *(int *)(puVar2 + -0x60) = DAT_00829710 + 7;
      ffree(fVar6);
      Var5 = thunk_FUN_0058c248(&DAT_01c4c860,0x200,&DAT_00829710,puVar2 + -0x60,"(1f7.2)",7,
                                &DAT_020b943c + DAT_0082970c * 4);
    }
    *(undefined4 *)(puVar2 + -0x20) = 0;
    *(undefined4 *)(puVar2 + -0x1c) = 0;
    DAT_00829710 = DAT_00829710 + 10;
    DAT_0082970c = DAT_0082970c + 1;
    *(int *)(puVar2 + -0x24) = *(int *)(puVar2 + -0x24) + -1;
    iVar1 = *(int *)(puVar2 + -0x24);
  }
  if (DAT_020527c8 < 3) {
    DAT_020527c8 = 3;
  }
  *(undefined4 *)(puVar2 + -0x14) = 0x14;
  DAT_0082970c = 1;
  do {
    if (DAT_020527c8 < DAT_0082970c) {
      *(undefined4 *)(puVar2 + -0x10) = 0;
      *(float *)(&DAT_01a149a8 + DAT_0082970c * 4) = f_m99991;
    }
    else {
      *(undefined4 *)(&DAT_01a149a8 + DAT_0082970c * 4) =
           *(undefined4 *)(&DAT_020b943c + DAT_0082970c * 4);
      *(undefined4 *)(puVar2 + -0xc) = 0;
    }
    *(undefined4 *)(puVar2 + -8) = 0;
    DAT_0082970c = DAT_0082970c + 1;
    *(int *)(puVar2 + -0x14) = *(int *)(puVar2 + -0x14) + -1;
  } while (0 < *(int *)(puVar2 + -0x14));
  if (DAT_0078dc30 == 0) {
    pcVar3 = "Move All ";
    puVar4 = &DAT_01a14954;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar4 = *(undefined4 *)pcVar3;
      pcVar3 = pcVar3 + 4;
      puVar4 = puVar4 + 1;
    }
    if ((DAT_020b8e50 < 4) || (8 < DAT_020b8e50)) {
      FUN_005f33c9(puVar2,0x48f4c3);
      Var5 = FUN_005f34d1(puVar2,0x48f4de);
    }
  }
  else {
    *(undefined4 *)(puVar2 + -4) = 0;
  }
LAB_0048f4e2:
  ffree(Var5);
  return;
}


