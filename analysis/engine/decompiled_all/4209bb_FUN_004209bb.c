// FUN_004209bb @ 004209bb (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00420a74) */

void FUN_004209bb(void)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  bool bVar4;
  bool bVar5;
  undefined1 *puVar6;
  
  puVar6 = &stack0xfffffffc;
  bVar4 = &stack0xfffffffc < (undefined1 *)0x54;
  bVar5 = &stack0x00000000 == (undefined1 *)0x58;
  iVar1 = 1;
  pbVar2 = &DAT_020b8e9f + DAT_007cc604;
  pbVar3 = &DAT_0075f774;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar4 && !bVar5) {
    iVar1 = 1;
    pbVar2 = &DAT_020b8e9f + DAT_007cc604;
    pbVar3 = &DAT_0075f770;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pbVar2 < *pbVar3;
      bVar5 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    if (bVar4 || bVar5) {
      return;
    }
  }
  DAT_007d20fc = DAT_007cc604;
  if (*(char *)((int)&DAT_020b8ea0 + DAT_007cc604) == '[') {
    DAT_007d20fc = DAT_007cc604 + 2;
  }
  iVar1 = DAT_007cc600 - DAT_007d20fc;
  DAT_007d20f8 = DAT_007d20fc;
  do {
    if (iVar1 < 1) {
      *(undefined4 *)(puVar6 + -0x1c) = 0;
      return;
    }
    FUN_005f46bc(puVar6,0x420a9a);
    FUN_005f34d1(puVar6,0x420ab0);
    if (((((DAT_007d2100 == 0x5250) || (DAT_007d2100 == 0x4f53)) || (DAT_007d2100 == 0x4453)) ||
        ((DAT_007d2100 == 0x5553 || (DAT_007d2100 == 0x4f43)))) ||
       ((DAT_007d2100 == 0x5443 || ((DAT_007d2100 == 0x4c41 || (DAT_007d2100 == 0x4142)))))) {
      *(undefined4 *)(puVar6 + -0x28) = 0;
      return;
    }
    DAT_007d2104 = (&DAT_020b8e9f)[DAT_007d20f8];
    if (((DAT_007d2104 == 0x52) || (DAT_007d2104 == 0x4d)) ||
       (bVar4 = DAT_007d2104 < 0x4b, DAT_007d2104 == 0x4b)) {
      *(undefined4 *)(puVar6 + -0x24) = 0;
      return;
    }
    iVar1 = 1;
    bVar5 = false;
    pbVar2 = &DAT_007d2104;
    pbVar3 = &DAT_0075f778;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pbVar2 < *pbVar3;
      bVar5 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    if (!bVar4) {
      iVar1 = 1;
      pbVar2 = &DAT_007d2104;
      pbVar3 = &DAT_0075f874;
      do {
        if (iVar1 == 0) break;
        iVar1 = iVar1 + -1;
        bVar4 = *pbVar2 < *pbVar3;
        bVar5 = *pbVar2 == *pbVar3;
        pbVar2 = pbVar2 + 1;
        pbVar3 = pbVar3 + 1;
      } while (bVar5);
      if (bVar4 || bVar5) {
        *(undefined4 *)(puVar6 + -0x20) = 0;
        DAT_007d20f4 = DAT_007d20f8 + 1;
        iVar1 = (DAT_007cc600 - DAT_007d20f4) + 1;
        *(int *)(puVar6 + -0x18) = iVar1;
        break;
      }
    }
    DAT_007d20f8 = DAT_007d20f8 + 1;
    *(int *)(puVar6 + -0x2c) = *(int *)(puVar6 + -0x2c) + -1;
    iVar1 = *(int *)(puVar6 + -0x2c);
  } while( true );
joined_r0x00420c2f:
  if (iVar1 < 1) {
LAB_00420d53:
    DAT_007d20f8 = DAT_007cc600 + 1;
    iVar1 = (DAT_007d20f4 - DAT_007d20f8) / -1;
    *(int *)(puVar6 + -4) = iVar1;
    DAT_007cc600 = DAT_007d20f8;
    while (0 < iVar1) {
      (&DAT_020b8e9f)[DAT_007d20f8] = (&DAT_020b8e9e)[DAT_007d20f8];
      DAT_007d20f8 = DAT_007d20f8 + -1;
      *(int *)(puVar6 + -4) = *(int *)(puVar6 + -4) + -1;
      iVar1 = *(int *)(puVar6 + -4);
    }
    puVar6[-0x51] = (char)DAT_007cbfa0 + '0';
    (&DAT_020b8e9f)[DAT_007d20f4] = puVar6[-0x51];
    FUN_005f46bc(puVar6,0x420e24);
    FUN_005f34d1(puVar6,0x420e3a);
    return;
  }
  bVar5 = iVar1 == 0;
  bVar4 = false;
  DAT_007d2104 = (&DAT_020b8e9f)[DAT_007d20f4];
  iVar1 = 1;
  pbVar2 = &DAT_007d2104;
  pbVar3 = &DAT_0075f774;
  do {
    if (iVar1 == 0) break;
    iVar1 = iVar1 + -1;
    bVar4 = *pbVar2 < *pbVar3;
    bVar5 = *pbVar2 == *pbVar3;
    pbVar2 = pbVar2 + 1;
    pbVar3 = pbVar3 + 1;
  } while (bVar5);
  if (!bVar4 && !bVar5) {
    iVar1 = 1;
    pbVar2 = &DAT_007d2104;
    pbVar3 = &DAT_0075f770;
    do {
      if (iVar1 == 0) break;
      iVar1 = iVar1 + -1;
      bVar4 = *pbVar2 < *pbVar3;
      bVar5 = *pbVar2 == *pbVar3;
      pbVar2 = pbVar2 + 1;
      pbVar3 = pbVar3 + 1;
    } while (bVar5);
    if (bVar4 || bVar5) {
      *(undefined4 *)(puVar6 + -0x14) = 0;
      return;
    }
  }
  if ((DAT_007d2104 == 0x55) || (DAT_007d2104 == 0x4a)) {
    *(undefined4 *)(puVar6 + -0x10) = 0;
    return;
  }
  if (((DAT_007d2104 == 0x5d) || (DAT_007d2104 == 0x58)) ||
     ((DAT_007d2104 == 0x2f || (DAT_007d2104 == 0x3a)))) {
    *(undefined4 *)(puVar6 + -0xc) = 0;
    goto LAB_00420d53;
  }
  if ((DAT_007d2104 == 0x2d) || (DAT_007d2104 == 0x2b)) {
    *(undefined4 *)(puVar6 + -8) = 0;
    goto LAB_00420d53;
  }
  DAT_007d20f4 = DAT_007d20f4 + 1;
  *(int *)(puVar6 + -0x18) = *(int *)(puVar6 + -0x18) + -1;
  iVar1 = *(int *)(puVar6 + -0x18);
  goto joined_r0x00420c2f;
}


