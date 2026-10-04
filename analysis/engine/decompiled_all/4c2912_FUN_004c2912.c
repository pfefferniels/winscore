// FUN_004c2912 @ 004c2912 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */

undefined4 FUN_004c2912(char *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  uint uVar7;
  byte *pbVar8;
  byte *pbVar9;
  char *pcVar10;
  undefined4 *puVar11;
  bool bVar12;
  bool bVar13;
  bool bVar14;
  undefined1 *puVar15;
  int local_24;
  int local_10;
  
  puVar15 = &stack0xfffffffc;
  puVar5 = &stack0xfffffffc;
  DAT_0089fab8 = 1;
  if (*param_1 == '\r') {
    DAT_0089fab8 = 2;
  }
  DAT_0089fac0 = param_1[DAT_0089fab8 - 1];
  DAT_0089fabc = param_1[DAT_0089fab8];
  if (DAT_0089fac0 == 0x2d) {
    if ((((DAT_0089fabc == 0x54) || (DAT_0089fabc == 0x41)) || (DAT_0089fabc == 0x42)) &&
       (((DAT_0089fac0 = param_1[DAT_0089fab8 + 1], DAT_0089fac0 == 0x52 || (DAT_0089fac0 == 0x45))
        || ((DAT_0089fac0 == 0x4c || (DAT_0089fac0 == 0x41)))))) {
      DAT_0089fac0 = param_1[DAT_0089fab8];
      DAT_0089fabc = param_1[DAT_0089fab8 + 1];
      goto LAB_004c2a51;
    }
    goto LAB_004c3503;
  }
LAB_004c2a51:
  if (DAT_0089fac0 == 0x40) {
    iVar3 = 1;
    bVar14 = true;
    bVar12 = false;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d04;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar12 = *pbVar8 < *pbVar9;
      bVar14 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar14);
    if (!bVar12) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d74;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pbVar8 < *pbVar9;
        bVar14 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar14);
      puVar6 = &stack0xfffffffc;
      if (bVar12 || bVar14) goto LAB_004c35a4;
    }
    if ((DAT_0089fabc == 0x2d) || (DAT_0089fabc == 0x24)) {
      bVar14 = CARRY4(DAT_0089fab8,(uint)param_1);
      pbVar9 = (byte *)(param_1 + DAT_0089fab8);
      iVar3 = 1;
      pbVar8 = &DAT_00764d04;
      do {
        pbVar9 = pbVar9 + 1;
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar1 = *pbVar8;
        bVar14 = *pbVar9 < bVar1;
        pbVar8 = pbVar8 + 1;
      } while (*pbVar9 == bVar1);
      if (!bVar14) {
        bVar14 = CARRY4(DAT_0089fab8,(uint)param_1);
        pbVar9 = (byte *)(param_1 + DAT_0089fab8);
        bVar12 = pbVar9 == (byte *)0x0;
        iVar3 = 1;
        pbVar8 = &DAT_00764d74;
        do {
          pbVar9 = pbVar9 + 1;
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar14 = *pbVar9 < *pbVar8;
          bVar12 = *pbVar9 == *pbVar8;
          pbVar8 = pbVar8 + 1;
        } while (bVar12);
        puVar6 = &stack0xfffffffc;
        if (bVar14 || bVar12) goto LAB_004c35a4;
      }
      goto LAB_004c3503;
    }
  }
  if (DAT_0089fabc == 0x5b) {
    iVar3 = 1;
    bVar14 = true;
    bVar12 = false;
    pbVar8 = &DAT_0089fac0;
    pbVar9 = &DAT_00764d04;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar12 = *pbVar8 < *pbVar9;
      bVar14 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar14);
    if (!bVar12) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fac0;
      pbVar9 = &DAT_00764d74;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pbVar8 < *pbVar9;
        bVar14 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar14);
      if (bVar12 || bVar14) {
        DAT_0089fac0 = param_1[DAT_0089fab8 + 1];
        DAT_0089fabc = param_1[DAT_0089fab8 + 2];
        goto LAB_004c2b56;
      }
    }
    goto LAB_004c3503;
  }
LAB_004c2b56:
  uVar4 = (uint)DAT_0089fac0;
  DAT_0089fab4 = uVar4 - 0x40;
  puVar6 = &stack0xfffffffc;
  if (((DAT_0089fac0 == 0x5d) || (puVar6 = &stack0xfffffffc, DAT_0089fac0 == 0x2f)) ||
     (puVar6 = &stack0xfffffffc, DAT_0089fac0 == 0x3b)) goto LAB_004c35a4;
  if (DAT_01fbb700 == 2) {
    iVar3 = 1;
    bVar14 = true;
    bVar12 = false;
    pbVar8 = &DAT_0089fac0;
    pbVar9 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar12 = *pbVar8 < *pbVar9;
      bVar14 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar14);
    if (bVar12 || bVar14) {
LAB_004c2bf2:
      bVar14 = DAT_0089fac0 < 0x2e;
      if ((DAT_0089fac0 == 0x2e) &&
         (bVar14 = DAT_0089fabc < 0x35, puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x35))
      goto LAB_004c35a4;
      bVar12 = false;
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      if (bVar14 || bVar12) {
        iVar3 = 1;
        pbVar8 = &DAT_0089fabc;
        pbVar9 = &DAT_00764d2c;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar14 = *pbVar8 < *pbVar9;
          bVar12 = *pbVar8 == *pbVar9;
          pbVar8 = pbVar8 + 1;
          pbVar9 = pbVar9 + 1;
        } while (bVar12);
        if ((!bVar14 && !bVar12) && (puVar6 = &stack0xfffffffc, DAT_0089fac0 == 0x58))
        goto LAB_004c35a4;
      }
      if (DAT_0089fac0 != 0x54) {
        local_24 = 7;
        DAT_0089fab8 = 1;
        do {
          if (*(byte *)(DAT_0089fab8 + 0x792617) == DAT_0089fac0) goto LAB_004c2d2a;
          DAT_0089fab8 = DAT_0089fab8 + 1;
          local_24 = local_24 + -1;
        } while (0 < local_24);
        goto LAB_004c3503;
      }
      local_10 = 4;
      DAT_0089fab8 = 1;
      do {
        puVar6 = &stack0xfffffffc;
        if (*(byte *)(DAT_0089fab8 + 0x792613) == DAT_0089fabc) goto LAB_004c35a4;
        DAT_0089fab8 = DAT_0089fab8 + 1;
        local_10 = local_10 + -1;
      } while (0 < local_10);
    }
    else {
      iVar3 = 1;
      pbVar8 = &DAT_0089fac0;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar12 = *pbVar8 < *pbVar9;
        bVar14 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar14);
      if (!bVar12 && !bVar14) goto LAB_004c2bf2;
LAB_004c2d2a:
      bVar14 = DAT_0089fabc < 0x2e;
      puVar6 = &stack0xfffffffc;
      if (DAT_0089fabc == 0x2e) goto LAB_004c35a4;
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d2c;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar9;
        bVar1 = *pbVar8;
        bVar14 = bVar1 < bVar2;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar1 == bVar2);
      bVar14 = !bVar14;
      bVar12 = !bVar14;
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      bVar13 = bVar14;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar13 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      puVar6 = &stack0xfffffffc;
      if ((bVar13 || bVar12) && bVar14) goto LAB_004c35a4;
    }
    goto LAB_004c335c;
  }
  uVar7 = uVar4 - 0x41;
  bVar14 = uVar7 < 0x19;
  bVar12 = uVar7 == 0x19;
  if (0x19 < uVar7) {
    iVar3 = 1;
    pbVar8 = &DAT_0089fac0;
    pbVar9 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    bVar13 = !bVar14 && !bVar12;
    bVar14 = bVar14 || bVar12;
    iVar3 = 1;
    pbVar8 = &DAT_0089fac0;
    pbVar9 = &DAT_00764d28;
    bVar12 = bVar13;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar12 = *pbVar8 < *pbVar9;
      bVar14 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar14);
    puVar6 = &stack0xfffffffc;
    if (((bVar12 || bVar14) && bVar13) ||
       (puVar6 = &stack0xfffffffc, DAT_0089fac0 == 0x3d || DAT_0089fac0 == 0x2e)) goto LAB_004c35a4;
    goto LAB_004c3503;
  }
  bVar14 = DAT_0089fab4 == 0;
  bVar12 = uVar4 - 0x41 == 0;
  switch(uVar4 - 0x41) {
  case 0:
    puVar6 = &stack0xfffffffc;
    if (DAT_0089fabc == 0x4c) goto LAB_004c35a4;
  case 3:
  case 4:
  case 5:
  case 6:
LAB_004c323a:
    puVar6 = &stack0xfffffffc;
    if ((((DAT_0089fabc == 0x27) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x3a)) ||
        ((puVar6 = &stack0xfffffffc, DAT_0089fac0 == DAT_0089fabc ||
         ((((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2b ||
            (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2d)) ||
           (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x55)) ||
          ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x4a ||
           (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x4e)))))))) ||
       ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x46 ||
        (bVar14 = DAT_0089fabc < 0x53, puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x53))))
    goto LAB_004c35a4;
    iVar3 = 1;
    bVar12 = false;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (!bVar14 && !bVar12) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar9;
        bVar1 = *pbVar8;
        bVar14 = bVar1 < bVar2;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar1 == bVar2);
      puVar6 = &stack0xfffffffc;
      if (bVar14) goto LAB_004c35a4;
    }
    puVar6 = &stack0xfffffffc;
    if (DAT_0089fabc == 0x28) goto LAB_004c35a4;
LAB_004c335c:
    puVar6 = &stack0xfffffffc;
    if (((DAT_0089fabc == 0x2e) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x3d)) ||
       ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x5d ||
        (((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x58 ||
          (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2f)) ||
         (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x3b)))))) goto LAB_004c35a4;
    break;
  case 1:
    puVar6 = &stack0xfffffffc;
    if (DAT_0089fabc == 0x41) goto LAB_004c35a4;
    goto LAB_004c323a;
  case 2:
    puVar6 = &stack0xfffffffc;
    if ((DAT_0089fabc == 0x55) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x4f))
    goto LAB_004c35a4;
    goto LAB_004c323a;
  case 10:
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d70;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (!bVar14) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &UNK_00764d6c;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      puVar6 = &stack0xfffffffc;
      if (bVar14 || bVar12) goto LAB_004c35a4;
    }
    break;
  case 0xc:
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar9;
      bVar1 = *pbVar8;
      bVar14 = bVar1 < bVar2;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 == bVar2);
    if (bVar14) {
      iVar3 = 1;
      bVar14 = true;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar9;
        bVar1 = *pbVar8;
        bVar14 = bVar1 < bVar2;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar1 == bVar2);
      puVar6 = &stack0xfffffffc;
      if (!bVar14) goto LAB_004c35a4;
    }
    puVar6 = &stack0xfffffffc;
    goto LAB_004c35a4;
  case 0xe:
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d04;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (!bVar14) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d00;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      puVar6 = &stack0xfffffffc;
      if (bVar14 || bVar12) goto LAB_004c35a4;
    }
    break;
  case 0xf:
    bVar14 = DAT_0089fabc < 0x52;
    puVar6 = &stack0xfffffffc;
    if (DAT_0089fabc == 0x52) goto LAB_004c35a4;
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d04;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar9;
      bVar1 = *pbVar8;
      bVar14 = bVar1 < bVar2;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 == bVar2);
    bVar14 = !bVar14;
    bVar12 = !bVar14;
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d00;
    bVar13 = bVar14;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar13 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    puVar6 = &stack0xfffffffc;
    if ((bVar13 || bVar12) && bVar14) goto LAB_004c35a4;
    break;
  case 0x10:
    if (DAT_0089fabc == 0x3d) {
      DAT_0089fabc = s______Input_error________00764d44[0x24];
    }
    goto joined_r0x004c317a;
  case 0x11:
    puVar6 = &stack0xfffffffc;
    if ((DAT_0089fabc == 0x46) ||
       (((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x49 ||
         (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x57)) ||
        (bVar14 = DAT_0089fabc < 0x50, puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x50))))
    goto LAB_004c35a4;
    iVar3 = 1;
    bVar12 = false;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d70;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (!bVar14) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      puVar6 = &stack0xfffffffc;
      if (bVar14 || bVar12) goto LAB_004c35a4;
    }
    puVar6 = &stack0xfffffffc;
    if ((((DAT_0089fabc == 0x5d) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x44)) ||
        ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x55 ||
         ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2f ||
          (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x3b)))))) ||
       (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x58)) goto LAB_004c35a4;
    break;
  case 0x12:
    puVar6 = &stack0xfffffffc;
    if ((DAT_0089fabc == 0x4f) ||
       ((puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x55 ||
        (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x44)))) goto LAB_004c35a4;
joined_r0x004c317a:
    puVar6 = &stack0xfffffffc;
    if (((DAT_0089fabc == 0x30) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2b)) ||
       (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x2d)) goto LAB_004c35a4;
    break;
  case 0x13:
    puVar6 = &stack0xfffffffc;
    if ((DAT_0089fabc == 0x52) || (puVar6 = &stack0xfffffffc, DAT_0089fabc == 0x45))
    goto LAB_004c35a4;
    break;
  case 0x17:
  case 0x19:
    iVar3 = 1;
    pbVar8 = &DAT_0089fabc;
    pbVar9 = &DAT_00764d2c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar14 = *pbVar8 < *pbVar9;
      bVar12 = *pbVar8 == *pbVar9;
      pbVar8 = pbVar8 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar12);
    if (!bVar14) {
      iVar3 = 1;
      pbVar8 = &DAT_0089fabc;
      pbVar9 = &DAT_00764d28;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar14 = *pbVar8 < *pbVar9;
        bVar12 = *pbVar8 == *pbVar9;
        pbVar8 = pbVar8 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar12);
      puVar6 = &stack0xfffffffc;
      if (bVar14 || bVar12) goto LAB_004c35a4;
    }
  }
LAB_004c3503:
  pcVar10 = "**** Input error ****               +";
  puVar11 = &DAT_0089fac4;
  for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar11 = *(undefined4 *)pcVar10;
    pcVar10 = pcVar10 + 4;
    puVar11 = puVar11 + 1;
  }
  thunk_FUN_0054c5f8(param_1,1,&DAT_0089fada,1,&DAT_00764d40);
  thunk_FUN_0054d831(&DAT_0089fac4,0x24);
  if (DAT_01fbb700 == 1) {
    FUN_005f33c9(&stack0xfffffffc,0x4c3574);
    puVar5 = puVar15;
    FUN_005f34d1(puVar15,0x4c358f);
  }
  *(undefined4 *)(puVar5 + -0x104) = 1;
  *(undefined4 *)(puVar5 + -0x34) = 0;
  puVar6 = puVar5;
LAB_004c35a4:
  return *(undefined4 *)(puVar6 + -0x104);
}


