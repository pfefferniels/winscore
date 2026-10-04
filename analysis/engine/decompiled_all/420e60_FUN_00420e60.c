// FUN_00420e60 @ 00420e60 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00421035) */
/* WARNING: Removing unreachable block (ram,0x00420ee0) */
/* WARNING: Removing unreachable block (ram,0x00420ff5) */
/* WARNING: Removing unreachable block (ram,0x0042124c) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00420e60(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  undefined2 in_FPUControlWord;
  
  puVar3 = &stack0xfffffffc;
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_3 = *param_1;
    param_1 = param_1 + 1;
    param_3 = param_3 + 1;
  }
  FUN_005f34d1(&stack0xfffffffc,0x420e90);
  DAT_007d2218 = 0;
  if (DAT_01fbb700 == 1) {
    iVar2 = **(int **)(puVar3 + 0x18);
    *(int *)(puVar3 + -0x40) = iVar2;
    DAT_007d2214 = 1;
    while (0 < iVar2) {
      FUN_005f46bc(puVar3,0x420f03);
      FUN_005f34d1(puVar3,0x420f19);
      if ((DAT_007d221c == 0x4142) || (DAT_007d221c == 0x4554)) {
        DAT_007d2218 = 3;
      }
      if (((DAT_007d221c == 0x5250) || (DAT_007d221c == 0x5254)) || (DAT_007d221c == 0x4c41)) {
        DAT_007d2218 = 4;
      }
      *(undefined4 *)(puVar3 + -0x3c) = 0;
      DAT_007d2214 = DAT_007d2214 + 1;
      *(int *)(puVar3 + -0x40) = *(int *)(puVar3 + -0x40) + -1;
      iVar2 = *(int *)(puVar3 + -0x40);
    }
  }
  DAT_007d2214 = **(int **)(puVar3 + 0x1c) + 1;
  iVar2 = (**(int **)(puVar3 + 0x18) - DAT_007d2214) + 1;
  *(int *)(puVar3 + -0x38) = iVar2;
  while (0 < iVar2) {
    iVar2 = FUN_005f4660(0x20);
    if ((iVar2 != 0) || (iVar2 = FUN_005f4660(0x20), iVar2 != 0)) {
      *(undefined4 *)(puVar3 + -0x34) = 0;
      break;
    }
    DAT_007d2214 = DAT_007d2214 + 1;
    *(int *)(puVar3 + -0x38) = *(int *)(puVar3 + -0x38) + -1;
    iVar2 = *(int *)(puVar3 + -0x38);
  }
  FUN_005f46bc(puVar3,0x4210bd);
  FUN_005f34d1(puVar3,0x4210d3);
  *(int *)(puVar3 + -0x68) = (**(int **)(puVar3 + 0x18) - **(int **)(puVar3 + 0x1c)) + 1;
  thunk_FUN_00518b3f(puVar3 + -0x68);
  *(undefined2 *)(puVar3 + -0x68) = in_FPUControlWord;
  *(ushort *)(puVar3 + -0x66) = (ushort)*(undefined4 *)(puVar3 + -0x68) | 0xc00;
  *(int *)(puVar3 + -100) = (int)ROUND(P2);
  DAT_007cb2cc = *(undefined4 *)(puVar3 + -100);
  puVar4 = *(undefined4 **)(puVar3 + 0x10);
  puVar6 = *(undefined4 **)(puVar3 + 8);
  for (iVar2 = 0x28; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_007d2210 = **(int **)(puVar3 + 0x1c) + 1;
  FUN_005f46bc(puVar3,0x421176);
  FUN_005f34d1(puVar3,0x42118c);
  DAT_007d2210 = DAT_007d2210 + 1;
  if ((DAT_007d2208 == '-') || (DAT_007d2208 == '$')) {
    FUN_005f46bc(puVar3,0x4211fa);
    FUN_005f34d1(puVar3,0x421210);
  }
  if ((DAT_007d2208 == '-') || (DAT_007d2208 == '$')) {
    FUN_005f46bc(puVar3,0x42126d);
    FUN_005f34d1(puVar3,0x421283);
  }
  DAT_007d2220 = DAT_007d2208;
  FUN_005f33c9(puVar3,0x4212b9);
  FUN_005f33c9(puVar3,0x4212d5);
  FUN_005f33c9(puVar3,0x4212f1);
  FUN_005f33c9(puVar3,0x42130d);
  FUN_005f34d1(puVar3,0x421328);
  *(undefined4 *)(puVar3 + -0x60) = 0;
  *(undefined4 *)(puVar3 + -0x78) = 0xb;
  *(undefined4 *)(puVar3 + -0x74) = *(undefined4 *)(puVar3 + 0x10);
  *(undefined4 *)(puVar3 + -0x70) = 3;
  *(undefined **)(puVar3 + -0x6c) = &DAT_0075f84c;
  *(undefined4 *)(puVar3 + -0x68) = 2;
  uVar1 = FUN_005f6540(puVar3 + -0x60,0xb,0x784ff01,&DAT_0075f854,puVar3 + -0x78);
  *(undefined4 *)(puVar3 + -0x30) = uVar1;
  if (*(int *)(puVar3 + -0x30) == 0) {
    *(undefined4 *)(puVar3 + -0x60) = 0;
    *(undefined4 *)(puVar3 + -0x68) = 0x100;
    *(undefined1 **)(puVar3 + -100) = &DAT_007cb2d0;
    uVar1 = FUN_005fdbd0(puVar3 + -0x60,0xb,0x784ff01,&DAT_0075f840,puVar3 + -0x68,&DAT_0078e838);
    *(undefined4 *)(puVar3 + -0x2c) = uVar1;
    if (*(int *)(puVar3 + -0x2c) == 0) {
      *(undefined4 *)(puVar3 + -0x60) = 0;
      FUN_005f7950(puVar3 + -0x60,0xb,0x784ff00,&DAT_0075f83c,0);
      thunk_FUN_0054c83c(&DAT_007cb2d0,0x100,&DAT_0075f898);
      FUN_0041f64f();
      bVar8 = false;
      if (DAT_007d2218 == 0) {
        *(undefined4 *)(puVar3 + -0x24) = 0;
        return;
      }
      DAT_007d2214 = 1;
      bVar9 = false;
      do {
        iVar2 = 1;
        pbVar5 = (byte *)((int)&DAT_007cb2cc + DAT_007d2214 + 3);
        pbVar7 = &DAT_0075f778;
        do {
          if (iVar2 == 0) break;
          iVar2 = iVar2 + -1;
          bVar8 = *pbVar5 < *pbVar7;
          bVar9 = *pbVar5 == *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (bVar8) {
LAB_0042149c:
          *(undefined4 *)(puVar3 + -0x20) = 0;
        }
        else {
          iVar2 = 1;
          bVar8 = false;
          pbVar5 = (byte *)((int)&DAT_007cb2cc + DAT_007d2214 + 3);
          pbVar7 = &DAT_0075f874;
          do {
            if (iVar2 == 0) break;
            iVar2 = iVar2 + -1;
            bVar8 = *pbVar5 < *pbVar7;
            bVar9 = *pbVar5 == *pbVar7;
            pbVar5 = pbVar5 + 1;
            pbVar7 = pbVar7 + 1;
          } while (bVar9);
          if (!bVar8 && !bVar9) goto LAB_0042149c;
          if (*(char *)((int)&DAT_007cb2cc + DAT_007d2214 + 2) == '/') {
            DAT_007d2220 = (&DAT_007cb2d0)[DAT_007d2214];
            iVar2 = 1;
            bVar8 = true;
            bVar9 = false;
            pbVar5 = (byte *)&DAT_007d2220;
            pbVar7 = &DAT_0075f774;
            goto code_r0x004214f5;
          }
          *(undefined4 *)(puVar3 + -0x1c) = 0;
        }
        if (DAT_007d2214 == 0x100) {
          *(undefined4 *)(puVar3 + -8) = 0;
          return;
        }
        bVar8 = 0xfffffffe < DAT_007d2214;
        DAT_007d2214 = DAT_007d2214 + 1;
        bVar9 = DAT_007d2214 == 0;
        *(undefined4 *)(puVar3 + -4) = 0;
      } while( true );
    }
  }
  FUN_005f33c9(puVar3,0x421610);
  FUN_005f34d1(puVar3,0x42162b);
  *(char *)(*(int *)(puVar3 + 0x10) + 0x10) = DAT_007d2220;
  thunk_FUN_0054d831(*(undefined4 *)(puVar3 + 0x10),0xa0);
  return;
  while( true ) {
    iVar2 = iVar2 + -1;
    bVar9 = *pbVar5 < *pbVar7;
    bVar8 = *pbVar5 == *pbVar7;
    pbVar5 = pbVar5 + 1;
    pbVar7 = pbVar7 + 1;
    if (!bVar8) break;
code_r0x004214f5:
    if (iVar2 == 0) break;
  }
  if (!bVar9) {
    iVar2 = 1;
    pbVar5 = (byte *)&DAT_007d2220;
    pbVar7 = &DAT_0075f770;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      bVar9 = *pbVar5 < *pbVar7;
      bVar8 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar8);
    if (bVar9 || bVar8) {
      *(undefined4 *)(puVar3 + -0x18) = 0;
      return;
    }
  }
  if (((DAT_007d2220 == 'N') || (DAT_007d2220 == 'F')) || (DAT_007d2220 == 'S')) {
    DAT_007d2214 = DAT_007d2214 + 1;
  }
  else {
    *(undefined4 *)(puVar3 + -0x14) = 0;
  }
  iVar2 = (int)(DAT_007d2214 - 0x100) / -1;
  *(int *)(puVar3 + -0x10) = iVar2;
  **(undefined4 **)(puVar3 + 0x18) = 0xff;
  while (0 < iVar2) {
    (&DAT_007cb2d0)[**(int **)(puVar3 + 0x18)] =
         *(undefined1 *)((int)&DAT_007cb2cc + **(int **)(puVar3 + 0x18) + 3);
    **(int **)(puVar3 + 0x18) = **(int **)(puVar3 + 0x18) + -1;
    *(int *)(puVar3 + -0x10) = *(int *)(puVar3 + -0x10) + -1;
    iVar2 = *(int *)(puVar3 + -0x10);
  }
  puVar3[-0x61] = (char)DAT_007d2218 + '0';
  (&DAT_007cb2d0)[DAT_007d2214] = puVar3[-0x61];
  *(undefined4 *)(puVar3 + -0xc) = 0;
  return;
}


