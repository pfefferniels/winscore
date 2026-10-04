// FUN_004e5ea6 @ 004e5ea6 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004e5ea6(void)

{
  undefined1 *puVar1;
  byte bVar2;
  uint uVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  int iVar6;
  byte *pbVar7;
  bool bVar8;
  bool bVar9;
  
  puVar4 = &stack0xfffffffc;
  _DAT_008d0b74 = (int)ROUND(P2);
  P2 = f_0;
  thunk_FUN_0054cb15(&DAT_007cb2d0,1,&DAT_008d0b70,&DAT_00765fbc);
  for (iVar6 = 1; iVar6 < 0x201; iVar6 = iVar6 + 1) {
    *(undefined1 *)(iVar6 + 0x8d0b7f) = (&DAT_020b8e9f)[iVar6];
  }
  DAT_008d0b6c = 1;
  bVar8 = false;
  bVar9 = true;
  DAT_008d0b68 = 0;
  do {
    uVar3 = DAT_008d0b6c;
    DAT_008d0b64 = DAT_008d0b6c;
    bVar2 = *(byte *)((int)&DAT_007cb2cc + DAT_008d0b6c + 3);
    _DAT_008d0b7c = CONCAT31(DAT_008d0b7c_1,bVar2);
    DAT_008d0b78 = (&DAT_007cb2d0)[DAT_008d0b6c];
    iVar6 = 1;
    pbVar5 = &DAT_008d0b7c;
    pbVar7 = &DAT_00765fb8;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      bVar8 = *pbVar5 < *pbVar7;
      bVar9 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar9);
    if (bVar8) {
LAB_004e61d5:
      *(undefined4 *)(puVar4 + -0x20) = 0;
    }
    else {
      iVar6 = 1;
      bVar8 = false;
      pbVar5 = &DAT_008d0b7c;
      pbVar7 = &DAT_00765fb4;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar8 = *pbVar5 < *pbVar7;
        bVar9 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (!bVar8 && !bVar9) goto LAB_004e61d5;
      bVar8 = bVar2 < 0x30;
      DAT_008d0b60 = bVar2 - 0x30;
      bVar9 = DAT_008d0b60 == 0;
      iVar6 = 1;
      pbVar5 = &DAT_008d0b78;
      pbVar7 = &DAT_00765fb8;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        bVar8 = *pbVar5 < *pbVar7;
        bVar9 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar9);
      if (bVar8) {
LAB_004e600e:
        *(undefined4 *)(puVar4 + -0x1c) = 0;
      }
      else {
        iVar6 = 1;
        bVar8 = false;
        pbVar5 = &DAT_008d0b78;
        pbVar7 = &DAT_00765fb4;
        do {
          if (iVar6 == 0) break;
          iVar6 = iVar6 + -1;
          bVar8 = *pbVar5 < *pbVar7;
          bVar9 = *pbVar5 == *pbVar7;
          pbVar5 = pbVar5 + 1;
          pbVar7 = pbVar7 + 1;
        } while (bVar9);
        if (!bVar8 && !bVar9) goto LAB_004e600e;
        DAT_008d0b60 = DAT_008d0b60 * 10 + (uint)DAT_008d0b78 + -0x30;
        DAT_008d0b6c = DAT_008d0b6c + 1;
      }
      if (DAT_008d0b68 == 0) {
        DAT_008d0b68 = DAT_008d0b60 - _DAT_008d0b74;
      }
      DAT_008d0b60 = DAT_008d0b60 - DAT_008d0b68;
      if (DAT_008d0b60 < 10) {
        puVar4[-0x41] = (char)DAT_008d0b60 + '0';
        *(undefined1 *)((int)&DAT_007cb2cc + uVar3 + 3) = puVar4[-0x41];
        if (DAT_008d0b64 == DAT_008d0b6c) {
          *(undefined4 *)(puVar4 + -0x14) = 0;
        }
        else {
          *(undefined1 *)((int)&DAT_007cb2cc + DAT_008d0b6c + 3) = 0x20;
          *(undefined4 *)(puVar4 + -0x10) = 0;
        }
      }
      else {
        *(undefined4 *)(puVar4 + -0x18) = 0;
        _DAT_008d0b7c = CONCAT31(DAT_008d0b7c_1,(&DAT_007cb2d0)[uVar3]);
        puVar4[-0x41] = (char)(DAT_008d0b60 / 10) + '0';
        *(undefined1 *)((int)&DAT_007cb2cc + uVar3 + 3) = puVar4[-0x41];
        puVar4[-0x41] = (char)(DAT_008d0b60 % 10) + '0';
        puVar1 = &DAT_007cb2d0 + DAT_008d0b64;
        DAT_008d0b64 = DAT_008d0b64 + 1;
        *puVar1 = puVar4[-0x41];
        *(uint *)(puVar4 + -0x44) = DAT_008d0b64;
        iVar6 = DAT_008d0b70 - *(int *)(puVar4 + -0x44);
        if (iVar6 < 0) {
          iVar6 = 0;
        }
        *(int *)(puVar4 + -0x48) = iVar6;
        FUN_005f46bc(puVar4,0x4e612d);
        FUN_005f34d1(puVar4,0x4e6143);
        DAT_008d0b70 = DAT_008d0b70 + 1;
        (&DAT_007cb2d0)[DAT_008d0b64] = (char)_DAT_008d0b7c;
        DAT_008d0b6c = DAT_008d0b64;
        *(undefined4 *)(puVar4 + -8) = 0;
      }
    }
    DAT_008d0b6c = DAT_008d0b6c + 1;
    bVar8 = DAT_008d0b6c < DAT_008d0b70;
    bVar9 = DAT_008d0b6c == DAT_008d0b70;
    if (!bVar9 && (int)DAT_008d0b70 <= (int)DAT_008d0b6c) {
      return;
    }
    *(undefined4 *)(puVar4 + -4) = 0;
  } while( true );
}


