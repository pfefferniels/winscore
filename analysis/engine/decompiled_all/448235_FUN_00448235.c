// FUN_00448235 @ 00448235 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00448235(int *param_1)

{
  float fVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined2 in_FPUControlWord;
  undefined1 *puVar8;
  undefined1 *puVar9;
  
  puVar8 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar9 = &stack0xfffffffc;
  DAT_01c585d4 = 0;
  LOAD_I = 1;
  for (iVar3 = ITEM_I; 0 < iVar3; iVar3 = iVar3 + -1) {
    load_item_header();
    if (LOAD_CODE == 8) {
      if (DAT_01c585d8 == -2) {
        if (199 < LOAD_STAFF) {
LAB_004482ad:
          *(int *)(&DAT_01e9ae94 + LOAD_STAFF * 4) = LOAD_I;
          if (DAT_01c585d4 < LOAD_STAFF) {
            DAT_01c585d4 = LOAD_STAFF;
          }
        }
      }
      else if (LOAD_STAFF < 0xc9) goto LAB_004482ad;
    }
    LOAD_I = LOAD_I + 1;
  }
  if (1 < DAT_01c585d4) {
    _DAT_007fcf70 = 0;
    P1 = f_0;
    if (DAT_02052740 == 0) {
      if (*param_1 != 2) {
        FUN_005f34d1(&stack0xfffffffc,0x448371);
        FUN_005f34d1(puVar8,0x448392);
        iVar3 = thunk_FUN_0059c7f0();
        if (iVar3 == 2) {
          *(undefined4 *)(puVar8 + -0x2c) = 0;
          return;
        }
        FUN_005f33c9(puVar8,0x4483d4);
        puVar2 = puVar8;
        FUN_005f34d1(puVar8,0x4483ef);
        puVar5 = &DAT_009ae2bc;
        puVar7 = (undefined4 *)&DAT_020b8ea0;
        for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
      }
      if (DAT_01c4cb00 == f_0) {
        thunk_FUN_0054cc83(&DAT_020b8ea0,1);
      }
      else {
        iVar4 = 2;
        iVar6 = 1;
        for (iVar3 = 1; iVar3 < 0x14; iVar3 = iVar3 + 1) {
          *(undefined4 *)(&P0 + iVar6 * 4) = *(undefined4 *)(iVar4 * 4 + 0x1c4cafc);
          iVar4 = iVar4 + 1;
          iVar6 = iVar6 + 1;
        }
      }
      if (DAT_01c585d8 == -2) {
        DAT_01c585d4 = DAT_01c585d4 + -200;
      }
    }
    else {
      thunk_FUN_00518448();
      puVar5 = (undefined4 *)&DAT_020b90a0;
      puVar7 = (undefined4 *)&DAT_007a0b7c;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      thunk_FUN_00518448();
      FUN_005f33c9(&stack0xfffffffc,0x4484ca);
      puVar2 = puVar9;
      FUN_005f34d1(puVar9,0x4484e5);
      thunk_FUN_0054cd71(&DAT_020b90a0,1,&DAT_00760b04,&DAT_01c585d0);
      *(undefined4 *)(puVar2 + -0x34) = 0;
    }
    if ((float)DAT_01c585d4 <= P1) {
      DAT_01c585d4 = 0;
      *(undefined4 *)(puVar2 + -0x24) = 0;
    }
    else {
      *(undefined4 *)(puVar2 + -0x28) = 0;
      if (P1 == f_0) {
        *(undefined4 *)(puVar2 + -0x20) = 0;
      }
      else {
        DAT_01c585d0 = 0;
        *(undefined4 *)(puVar2 + -0x1c) = 0x100;
        DAT_01caea40 = 1;
        do {
          if (DAT_01caea40 < 0x19) {
            fVar1 = *(float *)(&P0 + DAT_01caea40 * 4);
            *(undefined2 *)(puVar2 + -0x78) = in_FPUControlWord;
            *(ushort *)(puVar2 + -0x76) = (ushort)*(undefined4 *)(puVar2 + -0x78) | 0xc00;
            *(int *)(puVar2 + -0x74) = (int)ROUND(fVar1);
            in_FPUControlWord = *(undefined2 *)(puVar2 + -0x78);
            if (*(int *)(puVar2 + -0x74) != 0) {
              DAT_01caea44 = *(int *)(puVar2 + -0x74);
            }
          }
          else {
            *(undefined4 *)(puVar2 + -0x18) = 0;
          }
          *(int *)(&DAT_01caea60 + DAT_01caea40 * 4) = DAT_01caea44;
          DAT_01c585d0 = DAT_01caea44 + DAT_01c585d0;
          if (DAT_01c585d4 <= DAT_01c585d0) {
            *(undefined4 *)(puVar2 + -0x14) = 0;
            break;
          }
          DAT_01caea40 = DAT_01caea40 + 1;
          *(int *)(puVar2 + -0x1c) = *(int *)(puVar2 + -0x1c) + -1;
        } while (0 < *(int *)(puVar2 + -0x1c));
        iVar3 = DAT_01caea40 + -1;
        *(int *)(puVar2 + -0x10) = iVar3;
        DAT_01caea48 = 2;
        DAT_01c585d0 = MAX_STAFF;
        while (0 < iVar3) {
          DAT_01caea44 = (&DAT_01caea5c)[DAT_01caea48] + *(int *)(&DAT_01caea60 + DAT_01caea48 * 4);
          if (DAT_01c585d0 < DAT_01caea44) {
            DAT_01caea44 = DAT_01c585d0;
          }
          *(int *)(&DAT_01caea60 + DAT_01caea48 * 4) = DAT_01caea44;
          DAT_01caea48 = DAT_01caea48 + 1;
          *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
          iVar3 = *(int *)(puVar2 + -0x10);
        }
        puVar5 = (undefined4 *)&DAT_020b90a0;
        puVar7 = (undefined4 *)&DAT_020b8ea0;
        for (iVar3 = 0x80; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar7 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar7 = puVar7 + 1;
        }
        if (DAT_01c585d8 == -2) {
          *(int *)(puVar2 + -8) = DAT_01c585d4;
          DAT_01caea48 = 1;
          iVar3 = DAT_01c585d4;
          while (0 < iVar3) {
            *(undefined4 *)(&DAT_01e9ae94 + DAT_01caea48 * 4) =
                 *(undefined4 *)(DAT_01caea48 * 4 + 0x1e9b1b4);
            DAT_01caea48 = DAT_01caea48 + 1;
            *(int *)(puVar2 + -8) = *(int *)(puVar2 + -8) + -1;
            iVar3 = *(int *)(puVar2 + -8);
          }
        }
        else {
          *(undefined4 *)(puVar2 + -0xc) = 0;
        }
      }
      *(undefined4 *)(puVar2 + -4) = 0;
    }
  }
  return;
}


