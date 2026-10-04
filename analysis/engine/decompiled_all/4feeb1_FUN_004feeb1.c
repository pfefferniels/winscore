// FUN_004feeb1 @ 004feeb1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004feeb1(void)

{
  undefined1 *puVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  byte *pbVar5;
  bool bVar6;
  bool bVar7;
  float10 fVar8;
  
  thunk_FUN_0054c6b5(&DAT_020b8ea0,1,&DAT_00902064,&DAT_0078b4e0,&DAT_0078b4e4);
  thunk_FUN_0054cd13(&DAT_01a72dc0,&DAT_00766bac);
  DAT_00902060 = -1;
  DAT_0090205c = 0;
  DAT_00902058 = 0;
  DAT_00902054 = 1;
  do {
    bVar2 = (&DAT_020b8e9f)[DAT_00902054];
    _DAT_00902068 = CONCAT31(DAT_00902068_1,bVar2);
    bVar6 = bVar2 < 0x20;
    bVar7 = bVar2 == 0x20;
    if (bVar7) {
      DAT_00902060 = 1;
    }
    else {
      iVar3 = 1;
      pbVar4 = &DAT_00902068;
      pbVar5 = &DAT_00766ba8;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar6 = *pbVar4 < *pbVar5;
        bVar7 = *pbVar4 == *pbVar5;
        pbVar4 = pbVar4 + 1;
        pbVar5 = pbVar5 + 1;
      } while (bVar7);
      if (bVar6) {
LAB_004fef8d:
        if ((bVar2 == 0x2e) || (bVar2 == 0x2d)) goto LAB_004fefe1;
        if (DAT_00902060 < 0) goto LAB_004ff0d6;
        if (DAT_00902060 != 0) {
          _DAT_00902068 = CONCAT31(DAT_00902068_1,DAT_00766ba0);
          goto LAB_004ff0de;
        }
      }
      else {
        iVar3 = 1;
        bVar6 = false;
        pbVar4 = &DAT_00902068;
        pbVar5 = &DAT_00766ba4;
        do {
          if (iVar3 == 0) break;
          iVar3 = iVar3 + -1;
          bVar6 = *pbVar4 < *pbVar5;
          bVar7 = *pbVar4 == *pbVar5;
          pbVar4 = pbVar4 + 1;
          pbVar5 = pbVar5 + 1;
        } while (bVar7);
        if (!bVar6 && !bVar7) goto LAB_004fef8d;
LAB_004fefe1:
        DAT_00902058 = DAT_00902058 + 1;
        DAT_00902060 = -1;
        iVar3 = DAT_00902058 * 4;
        fVar8 = (float10)thunk_FUN_005194d5(&DAT_020b8e9f + DAT_00902054,1,&DAT_00902054);
        *(float *)(iVar3 + 0x1a72dbc) = (float)fVar8;
        _DAT_00902068 = CONCAT31(DAT_00902068_1,DAT_00766ba0);
      }
      while( true ) {
        if (DAT_00902058 == 0x50) {
          DAT_00902058 = 0x4f;
        }
        puVar1 = (undefined1 *)((int)&DAT_020b8ea0 + DAT_0090205c);
        DAT_0090205c = DAT_0090205c + 1;
        *puVar1 = (char)_DAT_00902068;
        if (DAT_00902060 < 1) break;
        _DAT_00902068 = CONCAT31(DAT_00902068_1,(&DAT_020b8e9f)[DAT_00902054]);
LAB_004ff0d6:
        DAT_00902060 = 0;
LAB_004ff0de:
        DAT_00902058 = DAT_00902058 + 1;
        *(float *)(DAT_00902058 * 4 + 0x1a72dbc) = f_0;
      }
    }
    DAT_00902054 = DAT_00902054 + 1;
    if (DAT_00902064 < DAT_00902054) {
      if (DAT_00902064 != DAT_0090205c) {
        DAT_00902054 = DAT_0090205c + 1;
        for (iVar3 = (DAT_00902064 - DAT_00902054) + 1; 0 < iVar3; iVar3 = iVar3 + -1) {
          (&DAT_020b8e9f)[DAT_00902054] = 0x20;
          DAT_00902054 = DAT_00902054 + 1;
        }
      }
      thunk_FUN_0054c590(&DAT_01a72dc0,&P1,&DAT_00766ab0);
      return;
    }
  } while( true );
}


