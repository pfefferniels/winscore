// FUN_00527276 @ 00527276 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00527276(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  int iVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  undefined1 *puVar8;
  int local_58;
  
  puVar8 = &stack0xfffffffc;
  DAT_0094eae8 = 0;
  local_58 = 0x3c;
  DAT_0094eae4 = 1;
  do {
    if ((*(char *)((int)&DAT_007cb2cc + DAT_0094eae4 + 3) == 'R') ||
       (*(char *)((int)&DAT_007cb2cc + DAT_0094eae4 + 3) == 'M')) {
      DAT_0094eae0 = 0x3c;
      for (iVar4 = (int)(DAT_0094eae4 + -0x3c) / -1; 0 < iVar4; iVar4 = iVar4 + -1) {
        *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eae0 + 3) =
             *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eae0 + 2);
        DAT_0094eae0 = DAT_0094eae0 + -1;
      }
      (&DAT_007cb2d0)[DAT_0094eae4] = 0x34;
      DAT_0094eae8 = 1;
    }
    DAT_0094eae4 = DAT_0094eae4 + 1;
    local_58 = local_58 + -1;
  } while (0 < local_58);
  _DAT_0094eadc = 0;
  FUN_005f34d1(&stack0xfffffffc,0x5273a0);
  *(undefined4 *)(puVar8 + -0x44) = 0x3c;
  DAT_0094ead8 = 1;
  do {
    DAT_0094eaf0 = *(char *)((int)&DAT_007cb2cc + DAT_0094ead8 + 3);
    if ((*(char *)((int)&DAT_007cb2cc + DAT_0094ead8 + 1) == 'R') ||
       (*(char *)((int)&DAT_007cb2cc + DAT_0094ead8 + 1) == 'M')) {
      *(undefined4 *)(puVar8 + -0x40) = 0;
    }
    else if (((DAT_0094eaf0 == 'X') || (DAT_0094eaf0 == '/')) || (DAT_0094eaf0 == ':')) {
      *(undefined4 *)(puVar8 + -0x3c) = 0;
      if (*(char *)((int)&DAT_007cb2cc + DAT_0094ead8 + 2) == ' ') {
        DAT_0094ead8 = DAT_0094ead8 + -1;
      }
      uVar3 = (uint)*(byte *)((int)&DAT_007cb2cc + DAT_0094ead8 + 2);
      bVar7 = uVar3 < 0x30;
      DAT_0094ead4 = uVar3 - 0x30;
      DAT_0094eaf0 = *(char *)((int)&DAT_007cb2cc + DAT_0094ead8);
      iVar4 = 1;
      pbVar5 = (byte *)&DAT_0094eaf0;
      pbVar6 = &DAT_00767edc;
      break;
    }
    *(undefined4 *)(puVar8 + -0x38) = 0;
    DAT_0094ead8 = DAT_0094ead8 + 1;
    *(int *)(puVar8 + -0x44) = *(int *)(puVar8 + -0x44) + -1;
    if (*(int *)(puVar8 + -0x44) < 1) {
      *(undefined4 *)(puVar8 + -0x34) = 0;
      return;
    }
  } while( true );
  while( true ) {
    iVar4 = iVar4 + -1;
    bVar2 = *pbVar6;
    bVar1 = *pbVar5;
    bVar7 = bVar1 < bVar2;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
    if (bVar1 != bVar2) break;
    if (iVar4 == 0) break;
  }
  if (!bVar7) {
    iVar4 = 1;
    bVar7 = false;
    pbVar5 = (byte *)&DAT_0094eaf0;
    pbVar6 = &DAT_00767ed8;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar2 = *pbVar6;
      bVar1 = *pbVar5;
      bVar7 = bVar1 < bVar2;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 == bVar2);
    if (bVar7) {
      *(undefined4 *)(puVar8 + -0x30) = 0;
      goto LAB_005274fb;
    }
  }
  DAT_0094eaf0 = *(char *)((int)&DAT_007cb2cc + DAT_0094ead8 + 1);
LAB_005274fb:
  FUN_00527240(&DAT_0094eaf0,1,&DAT_0094ead0,&DAT_0094ead4);
  do {
    DAT_0094eae4 = DAT_0094ead8 + 1;
    iVar4 = 0x3d - DAT_0094eae4;
    *(int *)(puVar8 + -0x2c) = iVar4;
    while( true ) {
      if (iVar4 < 1) {
        *(undefined4 *)(puVar8 + -0x24) = 0;
        return;
      }
      DAT_0094eaf0 = *(char *)((int)&DAT_007cb2cc + DAT_0094eae4 + 3);
      if (((DAT_0094eaf0 == ']') || (DAT_0094eaf0 == 'X')) ||
         ((DAT_0094eaf0 == '/' || (DAT_0094eaf0 == ':')))) break;
      DAT_0094eae4 = DAT_0094eae4 + 1;
      *(int *)(puVar8 + -0x2c) = *(int *)(puVar8 + -0x2c) + -1;
      iVar4 = *(int *)(puVar8 + -0x2c);
    }
    *(undefined4 *)(puVar8 + -0x28) = 0;
    DAT_0094ead4 = *(byte *)((int)&DAT_007cb2cc + DAT_0094eae4 + 2) - 0x30;
    bVar7 = DAT_0094eae4 < 3;
    DAT_0094eae0 = DAT_0094eae4 - 3;
    DAT_0094eaec = *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eae4);
    iVar4 = 1;
    pbVar5 = &DAT_0094eaec;
    pbVar6 = &DAT_00767edc;
    do {
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      bVar2 = *pbVar6;
      bVar1 = *pbVar5;
      bVar7 = bVar1 < bVar2;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar1 == bVar2);
    if (bVar7) {
LAB_00527632:
      DAT_0094eae0 = DAT_0094eae4 - 2;
      DAT_0094eaec = *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eae4 + 1);
    }
    else {
      iVar4 = 1;
      bVar7 = false;
      pbVar5 = &DAT_0094eaec;
      pbVar6 = &DAT_00767ed8;
      do {
        if (iVar4 == 0) break;
        iVar4 = iVar4 + -1;
        bVar2 = *pbVar6;
        bVar1 = *pbVar5;
        bVar7 = bVar1 < bVar2;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar1 == bVar2);
      if (!bVar7) goto LAB_00527632;
      *(undefined4 *)(puVar8 + -0x20) = 0;
    }
    FUN_00527240(&DAT_0094eaec,1,&DAT_0094eacc,&DAT_0094ead4);
    uVar3 = DAT_0094eae4;
    DAT_0094eaf4 = DAT_0094ead0 * 2 - DAT_0094eacc;
    DAT_0094ead4 = (DAT_0094eaf4 + -1) / 7;
    puVar8[-0x75] = (char)DAT_0094ead4 + '0';
    *(undefined1 *)((int)&DAT_007cb2cc + uVar3 + 2) = puVar8[-0x75];
    iVar4 = DAT_0094eae0;
    DAT_0094eaf4 = DAT_0094eaf4 % 7;
    if (DAT_0094eaf4 == 0) {
      DAT_0094eaf4 = 7;
    }
    if (5 < DAT_0094eaf4) {
      DAT_0094eaf4 = DAT_0094eaf4 + -7;
    }
    if ((*(char *)((int)&DAT_007cb2cc + DAT_0094eae0 + 3) != 'R') &&
       (*(char *)((int)&DAT_007cb2cc + DAT_0094eae0 + 3) != 'M')) {
      puVar8[-0x75] = (char)DAT_0094eaf4 + 'B';
      *(undefined1 *)((int)&DAT_007cb2cc + iVar4 + 3) = puVar8[-0x75];
    }
    if (DAT_0094eaf0 == ']') {
      *(undefined4 *)(puVar8 + -0x1c) = 0;
      if (DAT_0094eae8 == 0) {
        *(undefined4 *)(puVar8 + -0x14) = 0;
      }
      else {
        *(undefined4 *)(puVar8 + -0x10) = 0x3c;
        DAT_0094eae4 = 1;
        do {
          if ((*(char *)((int)&DAT_007cb2cc + DAT_0094eae4 + 3) == 'R') ||
             (*(char *)((int)&DAT_007cb2cc + DAT_0094eae4 + 3) == 'M')) {
            DAT_0094eae0 = DAT_0094eae4 + 1;
            iVar4 = 0x3c - DAT_0094eae0;
            *(int *)(puVar8 + -8) = iVar4;
            while (0 < iVar4) {
              *(undefined1 *)((int)&DAT_007cb2cc + DAT_0094eae0 + 3) = (&DAT_007cb2d0)[DAT_0094eae0]
              ;
              DAT_0094eae0 = DAT_0094eae0 + 1;
              *(int *)(puVar8 + -8) = *(int *)(puVar8 + -8) + -1;
              iVar4 = *(int *)(puVar8 + -8);
            }
          }
          else {
            *(undefined4 *)(puVar8 + -0xc) = 0;
          }
          *(undefined4 *)(puVar8 + -4) = 0;
          DAT_0094eae4 = DAT_0094eae4 + 1;
          *(int *)(puVar8 + -0x10) = *(int *)(puVar8 + -0x10) + -1;
        } while (0 < *(int *)(puVar8 + -0x10));
      }
      if (*(char *)((int)&DAT_020b8ea0 + **(int **)(puVar8 + 8) + 1) != '-') {
        return;
      }
      FUN_00526f23(*(undefined4 *)(puVar8 + 8));
      return;
    }
    DAT_0094ead8 = DAT_0094eae4 + 1;
    *(undefined4 *)(puVar8 + -0x18) = 0;
  } while( true );
}


