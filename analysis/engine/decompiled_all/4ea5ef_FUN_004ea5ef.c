// FUN_004ea5ef @ 004ea5ef (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ea5ef(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  
  puVar3 = &stack0xfffffffc;
  FUN_005f33c9(&stack0xfffffffc,0x4ea619);
  FUN_005f34d1(puVar3,0x4ea634);
  _DAT_008d1450 = i_538976288;
  FUN_005f34d1(puVar3,0x4ea661);
  DAT_008d144c = -1;
  DAT_01aad480 = 0;
LAB_004ea678:
  do {
    _DAT_008d1448 = FUN_005f7bb0(&DAT_008d14a8,0x30,&DAT_008d14d8,&DAT_008d144c);
    if ((DAT_008d144c == -2) || (DAT_008d144c == -3)) {
      *(undefined4 *)(puVar3 + -0x50) = 0;
LAB_004eae2a:
      *(undefined **)(puVar3 + -0x78) = &DAT_01aa1900;
      FUN_006027f0(puVar3 + -0x78,&DAT_01aad480,&DAT_007662a8);
      return;
    }
    puVar4 = &DAT_008d14ea;
    puVar5 = (undefined4 *)&DAT_008d1478;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    if (((DAT_008d1478 != ';') && (DAT_008d1478 != '.')) && (DAT_008d1478 != ' ')) {
      thunk_FUN_0054c83c(&DAT_008d1478,0x30,&DAT_007662a8);
      thunk_FUN_00497193(&DAT_008d1478,0x30,&DAT_008d1474,4);
      if ((DAT_008d1474 == 0x53554d2e) || (DAT_008d1474 == 0x20474150)) {
        *(undefined4 *)(puVar3 + -0x48) = 0;
      }
      else {
        *(undefined4 *)(puVar3 + -0x44) = 0x1b;
        DAT_008d1444 = 1;
        do {
          if ((*(uint *)((int)&DAT_00794c28 + DAT_008d1444 * 3 + 1) & 0xffffff) == DAT_008d1474 >> 8
             ) {
            *(undefined4 *)(puVar3 + -0x40) = 0;
            goto LAB_004ea678;
          }
          *(undefined4 *)(puVar3 + -0x3c) = 0;
          DAT_008d1444 = DAT_008d1444 + 1;
          *(int *)(puVar3 + -0x44) = *(int *)(puVar3 + -0x44) + -1;
        } while (0 < *(int *)(puVar3 + -0x44));
        *(undefined4 *)(puVar3 + -0x70) = 0;
        *(undefined4 *)(puVar3 + -0x90) = 0x30;
        *(char **)(puVar3 + -0x8c) = &DAT_008d1478;
        *(undefined4 *)(puVar3 + -0x88) = 3;
        *(undefined **)(puVar3 + -0x84) = &DAT_007662a4;
        *(undefined4 *)(puVar3 + -0x80) = 6;
        *(char **)(puVar3 + -0x7c) = "binary";
        *(undefined4 *)(puVar3 + -0x78) = 2;
        uVar1 = FUN_005f6540(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766288,puVar3 + -0x90);
        *(undefined4 *)(puVar3 + -0x38) = uVar1;
        if (*(int *)(puVar3 + -0x38) != 0) goto LAB_004ea678;
        *(undefined4 *)(puVar3 + -0x70) = 0;
        *(undefined **)(puVar3 + -0x78) = &DAT_008d1470;
        uVar1 = FUN_005f8240(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766284,puVar3 + -0x78);
        *(undefined4 *)(puVar3 + -0x34) = uVar1;
        if (*(int *)(puVar3 + -0x34) != 0) goto LAB_004ea678;
        *(undefined4 *)(puVar3 + -0x70) = 0;
        *(undefined **)(puVar3 + -0x78) = &DAT_008d1440;
        iVar2 = FUN_005f8240(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766280,puVar3 + -0x78);
        *(int *)(puVar3 + -0x30) = iVar2;
        if (iVar2 == 0) {
          *(undefined **)(puVar3 + -0x78) = &DAT_008d143c;
          iVar2 = FUN_005f8730(puVar3 + -0x70,&DAT_00766280,puVar3 + -0x78);
          *(int *)(puVar3 + -0x30) = iVar2;
          if (iVar2 == 0) {
            *(undefined **)(puVar3 + -0x78) = &DAT_008d1438;
            uVar1 = FUN_005f8730(puVar3 + -0x70,&DAT_0076627c,puVar3 + -0x78);
            *(undefined4 *)(puVar3 + -0x30) = uVar1;
          }
        }
        if (*(int *)(puVar3 + -0x30) != 0) goto LAB_004ea678;
        *(undefined2 *)(puVar3 + -0x78) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
        *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d1440);
        DAT_008d1434 = *(int *)(puVar3 + -0x74);
        *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
        *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
        *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d143c);
        DAT_008d1430 = *(int *)(puVar3 + -0x74);
        *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
        *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
        *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d1438);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x78);
        DAT_008d142c = *(int *)(puVar3 + -0x74);
        if (((DAT_008d1434 < 3) || (DAT_008d1430 < 1 || 0x12 < DAT_008d1430)) ||
           (DAT_008d142c < 1 || 0xff < DAT_008d142c)) {
          *(undefined4 *)(puVar3 + -0x70) = 0;
          FUN_005f7950(puVar3 + -0x70,0xb,0x784ff00,&DAT_007661a8,0);
          *(undefined4 *)(puVar3 + -0x70) = 0;
          *(undefined4 *)(puVar3 + -0x90) = 0x30;
          *(char **)(puVar3 + -0x8c) = &DAT_008d1478;
          *(undefined4 *)(puVar3 + -0x88) = 3;
          *(undefined **)(puVar3 + -0x84) = &DAT_007662a4;
          *(undefined4 *)(puVar3 + -0x80) = 6;
          *(char **)(puVar3 + -0x7c) = "binary";
          *(undefined4 *)(puVar3 + -0x78) = 2;
          uVar1 = FUN_005f6540(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766288,puVar3 + -0x90);
          *(undefined4 *)(puVar3 + -0x24) = uVar1;
          if (*(int *)(puVar3 + -0x24) != 0) goto LAB_004ea678;
          *(undefined4 *)(puVar3 + -0x70) = 0;
          *(undefined **)(puVar3 + -0x78) = &DAT_008d1428;
          uVar1 = FUN_005f8240(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766278,puVar3 + -0x78);
          *(undefined4 *)(puVar3 + -0x20) = uVar1;
          if (*(int *)(puVar3 + -0x20) != 0) goto LAB_004ea678;
          *(undefined4 *)(puVar3 + -0x70) = 0;
          *(undefined **)(puVar3 + -0x78) = &DAT_008d1440;
          iVar2 = FUN_005f8240(puVar3 + -0x70,0xb,0x784ff01,&DAT_00766280,puVar3 + -0x78);
          *(int *)(puVar3 + -0x1c) = iVar2;
          if (iVar2 == 0) {
            *(undefined **)(puVar3 + -0x78) = &DAT_008d143c;
            iVar2 = FUN_005f8730(puVar3 + -0x70,&DAT_00766280,puVar3 + -0x78);
            *(int *)(puVar3 + -0x1c) = iVar2;
            if (iVar2 == 0) {
              *(undefined **)(puVar3 + -0x78) = &DAT_008d1438;
              uVar1 = FUN_005f8730(puVar3 + -0x70,&DAT_0076627c,puVar3 + -0x78);
              *(undefined4 *)(puVar3 + -0x1c) = uVar1;
            }
          }
          if (*(int *)(puVar3 + -0x1c) != 0) goto LAB_004ea678;
          *(undefined2 *)(puVar3 + -0x78) = in_FPUControlWord;
          *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
          *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d1440);
          DAT_008d1434 = *(int *)(puVar3 + -0x74);
          *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
          *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
          *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d143c);
          DAT_008d1430 = *(int *)(puVar3 + -0x74);
          *(undefined2 *)(puVar3 + -0x78) = *(undefined2 *)(puVar3 + -0x78);
          *(ushort *)(puVar3 + -0x76) = (ushort)*(undefined4 *)(puVar3 + -0x78) | 0xc00;
          *(int *)(puVar3 + -0x74) = (int)ROUND(_DAT_008d1438);
          in_FPUControlWord = *(undefined2 *)(puVar3 + -0x78);
          DAT_008d142c = *(int *)(puVar3 + -0x74);
          if (((DAT_008d1434 < 3) || (DAT_008d1430 < 1 || 0x12 < DAT_008d1430)) ||
             (DAT_008d142c < 1 || 0xff < DAT_008d142c)) {
            *(undefined4 *)(puVar3 + -0x70) = 0;
            FUN_005f7950(puVar3 + -0x70,0xb,0x784ff00,&DAT_007661a8,0);
            *(undefined4 *)(puVar3 + -0x10) = 0;
            goto LAB_004ea678;
          }
          *(undefined4 *)(puVar3 + -0x18) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x2c) = 0;
        }
        *(undefined4 *)(puVar3 + -0x70) = 0;
        FUN_005f7950(puVar3 + -0x70,0xb,0x784ff00,&DAT_007661a8,0);
      }
      DAT_01aad480 = DAT_01aad480 + 1;
      FUN_005f81b0(&DAT_008d14dc,&DAT_008d146c,&DAT_008d1468,&DAT_008d1464,&DAT_008d1460,
                   &DAT_008d145c,&DAT_008d1458);
      *(undefined4 *)(puVar3 + -0x70) = 0;
      *(undefined4 *)(puVar3 + -0x80) = 0x10;
      *(undefined **)(puVar3 + -0x7c) = &DAT_008d1497;
      *(undefined **)(puVar3 + -0x78) = &DAT_008d1468;
      FUN_005f34f0(puVar3 + -0x70,0x784ff00,&DAT_00766270,puVar3 + -0x80,&DAT_00794bc4);
      *(undefined **)(puVar3 + -0x78) = &DAT_008d1464;
      FUN_005f3960(puVar3 + -0x70,&DAT_0076626c,puVar3 + -0x78);
      *(undefined **)(puVar3 + -0x78) = &DAT_008d146c;
      FUN_005f3960(puVar3 + -0x70,&DAT_00766284,puVar3 + -0x78);
      FUN_005f33c9(puVar3,0x4eadfb);
      if (999 < DAT_01aad480) goto LAB_004eae2a;
      *(undefined4 *)(puVar3 + -4) = 0;
      goto LAB_004ea678;
    }
    *(undefined4 *)(puVar3 + -0x4c) = 0;
  } while( true );
}


