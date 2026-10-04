// FUN_0047dc96 @ 0047dc96 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0047dc96(undefined4 param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined2 in_FPUControlWord;
  
  puVar3 = &stack0xfffffffc;
  iVar4 = *param_2;
  DAT_01ba0c30 = 1;
  for (; 0 < iVar4; iVar4 = iVar4 + -1) {
    DAT_01ba0c38 = (&ITEM_PTR0)[*(int *)(DAT_01ba0c30 * 4 + 0x1b9e12c)];
    (&DAT_01f95d4c)[DAT_01ba0c30 * 0xf] = (&ITEM_P3)[DAT_01ba0c38];
    DAT_01ba0c30 = DAT_01ba0c30 + 1;
  }
  DAT_01ba0c34 = 0;
  DAT_01ba0c58 = -999;
  DAT_01ba0c5c = -999;
  DAT_01ba0c40 = -1;
  iVar4 = *param_3;
  DAT_01ba0c30 = 1;
  iVar2 = DAT_01ba0c40;
  do {
    if (iVar4 < 1) {
      DAT_01ba0c40 = iVar2;
      DAT_01fb8cc0 = DAT_01ba0c34;
      return;
    }
    DAT_01ba0c3c = *(int *)(DAT_01ba0c30 * 4 + *(int *)(puVar3 + 0x14) + -4);
    DAT_01ba0c38 = (&ITEM_PTR0)[DAT_01ba0c3c];
    fVar1 = (float)(&ITEM_P3)[DAT_01ba0c38];
    *(undefined2 *)(puVar3 + -0x60) = in_FPUControlWord;
    *(ushort *)(puVar3 + -0x5e) = (ushort)*(undefined4 *)(puVar3 + -0x60) | 0xc00;
    *(int *)(puVar3 + -0x5c) = (int)ROUND(fVar1);
    in_FPUControlWord = *(undefined2 *)(puVar3 + -0x60);
    DAT_01ba0c40 = *(int *)(puVar3 + -0x5c);
    DAT_01ba0c44 = DAT_01ba0c40;
    if ((DAT_01fbb700 == 5) || (DAT_01ba0c40 != iVar2)) {
      fVar1 = (float)(&ITEM_P6)[DAT_01ba0c38];
      *(undefined2 *)(puVar3 + -0x60) = in_FPUControlWord;
      *(ushort *)(puVar3 + -0x5e) = (ushort)*(undefined4 *)(puVar3 + -0x60) | 0xc00;
      *(int *)(puVar3 + -0x5c) = (int)ROUND(fVar1);
      in_FPUControlWord = *(undefined2 *)(puVar3 + -0x60);
      DAT_01ba0c48 = *(int *)(puVar3 + -0x5c);
      DAT_01ba0c50 = 0;
      DAT_01ba0c54 = **(int **)(puVar3 + 8);
      iVar4 = **(int **)(puVar3 + 8) + -1;
      *(int *)(puVar3 + -0x2c) = iVar4;
      DAT_00828544 = 1;
      while (0 < iVar4) {
        DAT_01ba0c38 = *(int *)(&DAT_01f995bc + DAT_00828544 * 4);
        fVar1 = (float)(&DAT_01f95d4c)[DAT_01ba0c38 * 0xf];
        *(undefined2 *)(puVar3 + -0x60) = in_FPUControlWord;
        *(ushort *)(puVar3 + -0x5e) = (ushort)*(undefined4 *)(puVar3 + -0x60) | 0xc00;
        *(int *)(puVar3 + -0x5c) = (int)ROUND(fVar1);
        in_FPUControlWord = *(undefined2 *)(puVar3 + -0x60);
        _DAT_01ba0c4c = *(int *)(puVar3 + -0x5c);
        iVar4 = DAT_01ba0c40 - _DAT_01ba0c4c;
        if (iVar4 < 0) {
          iVar4 = -iVar4;
        }
        if (iVar4 < 2) {
          *(undefined4 *)(puVar3 + -0x28) = 0;
          *(undefined4 *)(puVar3 + -0x1c) = 0;
          DAT_01ba0c50 = DAT_00828544;
        }
        else {
          iVar4 = DAT_01ba0c48 - _DAT_01ba0c4c;
          if (iVar4 < 0) {
            iVar4 = -iVar4;
          }
          if (iVar4 < 2) {
            *(undefined4 *)(puVar3 + -0x24) = 0;
            DAT_01ba0c54 = DAT_00828544;
          }
          else {
            *(undefined4 *)(puVar3 + -0x20) = 0;
          }
        }
        *(undefined4 *)(puVar3 + -0x18) = 0;
        DAT_00828544 = DAT_00828544 + 1;
        *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
        iVar4 = *(int *)(puVar3 + -0x2c);
      }
      if ((DAT_01ba0c58 == DAT_01ba0c50) && (DAT_01ba0c5c == DAT_01ba0c54)) {
        *(undefined4 *)(puVar3 + -0x14) = 0;
        iVar2 = DAT_01ba0c40;
      }
      else {
        if (DAT_01fbb700 == 4) {
          if ((DAT_01ba0c50 == 0) || (DAT_01ba0c54 == **(int **)(puVar3 + 8))) {
            FUN_005f33c9(puVar3,0x47dffc);
            FUN_005f34d1(puVar3,0x47e017);
            thunk_FUN_0058c2c9(&DAT_020b90a0,0x200,&DAT_007624c4,&DAT_007624c8,"(1i4)",5,
                               &DAT_01ba0c3c);
            thunk_FUN_0054d831(&DAT_020b90a0,0x200);
            *(undefined4 *)(puVar3 + -8) = 0;
            iVar2 = DAT_01ba0c40;
            goto LAB_0047e06b;
          }
          *(undefined4 *)(puVar3 + -0xc) = 0;
        }
        else {
          *(undefined4 *)(puVar3 + -0x10) = 0;
        }
        DAT_01ba0c34 = DAT_01ba0c34 + 1;
        (&DAT_01fb8cc0)[DAT_01ba0c34] = (int)(float)DAT_01ba0c50;
        DAT_01ba0c34 = DAT_01ba0c34 + 1;
        (&DAT_01fb8cc0)[DAT_01ba0c34] = (int)(float)DAT_01ba0c54;
        DAT_01ba0c58 = DAT_01ba0c50;
        DAT_01ba0c5c = DAT_01ba0c54;
        iVar2 = DAT_01ba0c40;
      }
    }
    else {
      *(undefined4 *)(puVar3 + -0x30) = 0;
    }
LAB_0047e06b:
    DAT_01ba0c40 = iVar2;
    *(undefined4 *)(puVar3 + -4) = 0;
    DAT_01ba0c30 = DAT_01ba0c30 + 1;
    *(int *)(puVar3 + -0x34) = *(int *)(puVar3 + -0x34) + -1;
    iVar4 = *(int *)(puVar3 + -0x34);
    iVar2 = DAT_01ba0c40;
  } while( true );
}


