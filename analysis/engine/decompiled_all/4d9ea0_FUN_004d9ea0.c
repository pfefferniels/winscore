// FUN_004d9ea0 @ 004d9ea0 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004d9ea0(int *param_1,uint *param_2)

{
  undefined1 *puVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  byte *pbVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  float10 fVar14;
  int local_c4;
  int local_90;
  int local_80;
  int local_60;
  int local_48;
  int local_24;
  
  ram0x01aad7d6 = 0;
  DAT_01aad7c0 = *param_1;
  DAT_01aad7c4 = *param_2;
  if ((0x2f < (int)DAT_01aad7c4) && ((int)DAT_01aad7c4 < 0x3a)) {
LAB_004da0fa:
    ram0x01aad7ee = f_0;
    ram0x01aad7da = 0;
LAB_004da10e:
    ram0x01aad7d2 = DAT_01aad7c0;
LAB_004da11a:
    do {
      while( true ) {
        iVar5 = ram0x01aad7d2 + 1;
        DAT_01aad7c4 = (uint)*(byte *)((int)&DAT_020b8ea0 + ram0x01aad7d2);
        if ((DAT_01aad7c4 < 0x30) || (0x39 < DAT_01aad7c4)) break;
LAB_004da22f:
        ram0x01aad7d6 = 0;
        unique0x10000464 = iVar5;
      }
      if (DAT_01aad7c4 == 0x2e) {
        register0x0000001c = ram0x01aad7d6 + 1;
        unique0x1000046c = iVar5;
        goto LAB_004da11a;
      }
      unique0x100000d7 = (float)(ram0x01aad7d6 * 1000);
      if ((DAT_01aad7c4 != 0x3a) && (DAT_01aad7c4 != 0x27)) {
        DAT_01aad7cc._0_1_ = *(byte *)((int)&DAT_020b8ea0 + ram0x01aad7d2);
        local_90 = 8;
        ram0x01aad7de = 1;
        while (*(byte *)(ram0x01aad7de + 0x794733) != (byte)DAT_01aad7cc) {
          register0x0000001c = ram0x01aad7de + 1;
          local_90 = local_90 + -1;
          if (local_90 < 1) {
            iVar4 = register0x0000001c;
            if (ram0x01aad7d6 == 0) goto LAB_004da423;
            iVar4 = iVar5;
            if ((&DAT_020b8e9f)[ram0x01aad7d2] != '.') goto LAB_004da3df;
            DAT_01aad7cc._0_1_ = (&DAT_020b8e9f)[DAT_01aad7c0];
            local_80 = 8;
            ram0x01aad7de = 1;
            goto LAB_004da2de;
          }
        }
        goto LAB_004da22f;
      }
      ram0x01aad7da = 1;
      unique0x10000468 = iVar5;
    } while( true );
  }
  DAT_01aad7cc._0_1_ = (&DAT_020b8e9f)[DAT_01aad7c0];
  local_c4 = 0xb;
  ram0x01aad7ce = 1;
  do {
    if (*(byte *)(ram0x01aad7ce + 0x794733) == (byte)DAT_01aad7cc) {
      if (ram0x01aad7ce != 10) {
        if (ram0x01aad7ce != 9) goto LAB_004da0fa;
        if (*(char *)((int)&DAT_020b8ea0 + DAT_01aad7c0 + 1) != 'P') break;
        DAT_01aad7c0 = DAT_01aad7c0 + 2;
      }
      register0x00000000 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
      fVar14 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
      DAT_01fbb70c = (int)ROUND(fVar14);
      register0x00000000 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
      fVar14 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
      DAT_01fbb710 = (int)ROUND(-fVar14);
      DAT_01aad7c0 = DAT_01fbb704;
      goto LAB_004da9af;
    }
    register0x0000001c = ram0x01aad7ce + 1;
    local_c4 = local_c4 + -1;
  } while (0 < local_c4);
LAB_004da8c5:
  thunk_FUN_005259e5(&DAT_01aad7c0);
  goto LAB_004da9af;
  while( true ) {
    register0x0000001c = ram0x01aad7de + 1;
    local_48 = local_48 + -1;
    if (local_48 < 1) break;
LAB_004da4f3:
    if (*(byte *)(ram0x01aad7de + 0x794733) == (byte)DAT_01aad7cc) {
      unique0x100002a4 = *(float *)(ram0x01aad7de * 4 + 0x794710) * f_1_5;
      if (ram0x01aad7de == 3) {
        ram0x01aad7e6 = f_48;
      }
      DAT_01aad7c0 = DAT_01aad7c0 + 1;
      goto LAB_004da5fb;
    }
  }
  if (((((1 < DAT_01aad7c0) &&
        (DAT_01aad7cc._0_1_ = (&DAT_020b8e9e)[DAT_01aad7c0], (byte)DAT_01aad7cc != 0x5b)) &&
       ((byte)DAT_01aad7cc != 0x3a)) &&
      (((byte)DAT_01aad7cc != 0x20 && ((byte)DAT_01aad7cc != 0x2f)))) &&
     ((byte)DAT_01aad7cc != 0x2c)) goto LAB_004da8c5;
LAB_004da5fb:
  unique0x100002b5 = f_4 / ram0x01aad7e6;
  DAT_01aad7c0 = DAT_01aad7c0 + 1;
  goto LAB_004da738;
  while( true ) {
    register0x0000001c = ram0x01aad7de + 1;
    local_80 = local_80 + -1;
    if (local_80 < 1) break;
LAB_004da2de:
    if (*(byte *)(ram0x01aad7de + 0x794733) == (byte)DAT_01aad7cc) goto LAB_004da3df;
  }
  bVar13 = (byte)DAT_01aad7cc < 0x2e;
  if ((byte)DAT_01aad7cc != 0x2e) {
    iVar6 = 1;
    pbVar7 = (byte *)&DAT_01aad7cc;
    pbVar8 = &DAT_0076591c;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar3 = *pbVar8;
      bVar2 = *pbVar7;
      bVar13 = bVar2 < bVar3;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar2 == bVar3);
    bVar13 = !bVar13;
    bVar11 = !bVar13;
    iVar6 = 1;
    pbVar7 = (byte *)&DAT_01aad7cc;
    pbVar8 = &DAT_00765918;
    bVar9 = bVar13;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar9 = *pbVar7 < *pbVar8;
      bVar11 = *pbVar7 == *pbVar8;
      pbVar7 = pbVar7 + 1;
      pbVar8 = pbVar8 + 1;
    } while (bVar11);
    bVar10 = false;
    bVar12 = !bVar9 && !bVar11 || !bVar13;
    if (!bVar9 && !bVar11 || !bVar13) {
      DAT_01aad7cc._1_1_ = *(undefined1 *)((int)&DAT_020b8ea0 + ram0x01aad7d2);
      iVar6 = 1;
      pbVar7 = (byte *)((int)&DAT_01aad7cc + 1);
      pbVar8 = &DAT_0076591c;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar10 = *pbVar7 < *pbVar8;
        bVar12 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar12);
      unique0x10000458 = iVar5;
      if (bVar10) goto LAB_004da8c5;
      iVar6 = 1;
      bVar13 = false;
      pbVar7 = (byte *)((int)&DAT_01aad7cc + 1);
      pbVar8 = &DAT_00765918;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar13 = *pbVar7 < *pbVar8;
        bVar12 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar12);
      if (!bVar13 && !bVar12) goto LAB_004da8c5;
    }
  }
LAB_004da3df:
  while (ram0x01aad7de = iVar4, ram0x01aad7d2 = iVar5, iVar5 = ram0x01aad7d2,
        iVar4 = ram0x01aad7de + -1, (&DAT_020b8e9e)[ram0x01aad7de] == '.') {
    puVar1 = &DAT_020b8e9e + ram0x01aad7de;
    unique0x10000470 = ram0x01aad7de + -1;
    *puVar1 = 0x20;
    iVar5 = ram0x01aad7d2;
    iVar4 = ram0x01aad7de;
  }
LAB_004da423:
  ram0x01aad7de = iVar4;
  ram0x01aad7d2 = iVar5;
  if (ram0x01aad7da == 0) {
    DAT_01aad7cc._0_1_ = (&DAT_020b8e9f)[DAT_01aad7c0];
    local_60 = 8;
    ram0x01aad7de = 1;
    do {
      if (*(byte *)(ram0x01aad7de + 0x794733) == (byte)DAT_01aad7cc) {
        unique0x00017200 = *(float *)(ram0x01aad7de * 4 + 0x794710);
        if (ram0x01aad7de != 3) goto LAB_004da5fb;
        DAT_01aad7cc._0_1_ = *(byte *)((int)&DAT_020b8ea0 + DAT_01aad7c0);
        local_48 = 7;
        ram0x01aad7de = 2;
        goto LAB_004da4f3;
      }
      register0x0000001c = ram0x01aad7de + 1;
      local_60 = local_60 + -1;
    } while (0 < local_60);
    if ((byte)DAT_01aad7cc == 0x2e) {
      DAT_01aad7cc._1_1_ = *(undefined1 *)((int)&DAT_020b8ea0 + DAT_01aad7c0);
      iVar5 = 1;
      bVar13 = true;
      bVar11 = false;
      pbVar7 = (byte *)((int)&DAT_01aad7cc + 1);
      pbVar8 = &DAT_0076591c;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pbVar7 < *pbVar8;
        bVar13 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar13);
      if (bVar11) goto LAB_004da8c5;
      iVar5 = 1;
      bVar11 = false;
      pbVar7 = (byte *)((int)&DAT_01aad7cc + 1);
      pbVar8 = &DAT_00765918;
      do {
        if (iVar5 == 0) break;
        iVar5 = iVar5 + -1;
        bVar11 = *pbVar7 < *pbVar8;
        bVar13 = *pbVar7 == *pbVar8;
        pbVar7 = pbVar7 + 1;
        pbVar8 = pbVar8 + 1;
      } while (bVar13);
      if (!bVar11 && !bVar13) goto LAB_004da8c5;
    }
    fVar14 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
    ram0x01aad7e6 = (float)((float10)f_4 / fVar14);
  }
  else {
    fVar14 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
    ram0x01aad7e6 = (float)fVar14;
    iVar5 = (int)&DAT_020b8ea0 + DAT_01aad7c0;
    DAT_01aad7c0 = DAT_01aad7c0 + 1;
    fVar14 = (float10)thunk_FUN_005194d5(iVar5,1,&DAT_01aad7c0);
    ram0x01aad7e6 = (float)(fVar14 / (float10)ram0x01aad7e6);
    ram0x01aad7da = 0;
  }
LAB_004da738:
  ram0x01aad7ea = ram0x01aad7e6;
  for (; ram0x01aad7d6 != 0; register0x0000001c = ram0x01aad7d6 + -1) {
    unique0x100002c2 = ram0x01aad7ea * f_0_5;
    unique0x100002ce = ram0x01aad7e6 + unique0x100002c2;
  }
  if (ram0x01aad7ee != f_0) {
    ram0x01aad7e2 = f_0;
  }
  unique0x100002e3 = ram0x01aad7ee + ram0x01aad7e6;
  DAT_01aad7c0 = DAT_01aad7c0 + -1;
  iVar5 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
  if (iVar5 != 0) goto LAB_004da996;
  DAT_01aad7cc._0_1_ = (&DAT_020b8e9f)[DAT_01aad7c0];
  local_24 = 7;
  ram0x01aad7de = 2;
  do {
    if (*(byte *)(ram0x01aad7de + 0x794733) == (byte)DAT_01aad7cc) goto LAB_004da10e;
    register0x0000001c = ram0x01aad7de + 1;
    local_24 = local_24 + -1;
  } while (0 < local_24);
  if ((DAT_01aad7c4 == 0x2e) || (0x2f < (int)DAT_01aad7c4 && (int)DAT_01aad7c4 < 0x3a))
  goto LAB_004da10e;
  if (DAT_01aad7c4 == 0x58) {
    register0x00000000 = thunk_FUN_00526ec4(&DAT_01aad7c4,&DAT_01aad7c0,&DAT_01fbb704);
    fVar14 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_01aad7c0,1,&DAT_01aad7c0);
    DAT_01fbb710 = (int)ROUND(fVar14);
    DAT_01aad7c0 = DAT_01fbb704;
  }
LAB_004da996:
  DAT_01ade8e0 = ram0x01aad7ee + ram0x01aad7e2;
LAB_004da9af:
  *param_1 = DAT_01aad7c0;
  return;
}


