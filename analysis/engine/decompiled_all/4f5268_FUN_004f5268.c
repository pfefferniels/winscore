// FUN_004f5268 @ 004f5268 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004f5644) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f5268(int *param_1)

{
  float fVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined2 in_FPUControlWord;
  undefined1 *puVar6;
  undefined1 *puVar7;
  int local_88;
  int local_6c;
  
  puVar3 = &stack0xfffffffc;
  puVar6 = &stack0xfffffffc;
  puVar7 = &stack0xfffffffc;
  if (*param_1 == 99) {
    *param_1 = DAT_008d1c34;
  }
  DAT_008d1c34 = *param_1;
  if (-1 < *param_1) {
    FUN_005f34d1(&stack0xfffffffc,0x4f5920);
    puVar4 = &DAT_0078b510;
    puVar5 = &DAT_008d1c40;
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    thunk_FUN_0054c83c(&DAT_008d1c40,0x80,&DAT_007666c0);
    puVar4 = &DAT_008d1c40;
    puVar5 = (undefined4 *)(puVar7 + -0x138);
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_008d1c10 = FUN_005ff950(puVar7 + -0x138,0x80);
    if ((&DAT_008d1c3f)[DAT_008d1c10] == '\0') {
      *(undefined4 *)(puVar7 + -0x30) = 0;
    }
    else {
      *(undefined1 *)((int)&DAT_008d1c40 + DAT_008d1c10) = 0;
      thunk_FUN_0058c2c9(&DAT_020b8ea0,0x200,&DAT_007666a8,&DAT_007666ac,"(1i3)",5,&DAT_008d1c10);
    }
    iVar2 = DAT_008d1c14;
    *(int *)(puVar7 + -0x2c) = DAT_008d1c14;
    DAT_008d1c2c = 1;
    do {
      if (iVar2 < 1) {
        FUN_005f33c9(puVar7,0x4f5d08);
        FUN_005f33c9(puVar7,0x4f5d24);
        thunk_FUN_0054d831(puVar7 + -0x148,0x8a);
        *(undefined4 *)(puVar7 + -0x14) = 0;
        return;
      }
      puVar4 = (undefined4 *)(DAT_008d1c2c * 0x80 + 0x1a78980);
      puVar5 = &DAT_0078b510;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
      *(undefined4 *)(puVar7 + -0x28) = 0x80;
      DAT_008d1c0c = 1;
      do {
        if (*(char *)(DAT_008d1c0c + 0x78b50f) != (&DAT_008d1c3f)[DAT_008d1c0c]) {
          *(undefined4 *)(puVar7 + -0x24) = 0;
          break;
        }
        if (*(char *)(DAT_008d1c0c + 0x78b50f) == '\0') {
          *(undefined4 *)(puVar7 + -0x20) = 0;
          if (**(int **)(puVar7 + 8) < 1) {
            if (P2 != f_0) {
              P2 = P2 - f_1;
            }
            fVar1 = (float)DAT_008d1c2c + P2;
            *(undefined2 *)(puVar7 + -0xac) = in_FPUControlWord;
            *(ushort *)(puVar7 + -0xaa) = (ushort)*(undefined4 *)(puVar7 + -0xac) | 0xc00;
            *(int *)(puVar7 + -0xa8) = (int)ROUND(fVar1);
            DAT_008d1c2c = *(int *)(puVar7 + -0xa8);
            if (DAT_008d1c14 <= DAT_008d1c2c) {
              if (DAT_02052740 != 0) {
                **(undefined4 **)(puVar7 + 8) = 0xffffff9d;
                DAT_02052740 = 0;
                *(undefined4 *)(puVar7 + -0xc) = 0;
                return;
              }
              DAT_008d1c2c = DAT_008d1c2c - DAT_008d1c14;
            }
            *(undefined4 *)(puVar7 + -8) = 0;
          }
          else {
            *(undefined4 *)(puVar7 + -0x10) = 0;
            if (P2 != f_0) {
              P2 = P2 - f_1;
            }
            fVar1 = (float)DAT_008d1c2c - P2;
            *(undefined2 *)(puVar7 + -0xac) = in_FPUControlWord;
            *(ushort *)(puVar7 + -0xaa) = (ushort)*(undefined4 *)(puVar7 + -0xac) | 0xc00;
            *(int *)(puVar7 + -0xa8) = (int)ROUND(fVar1);
            DAT_008d1c2c = *(int *)(puVar7 + -0xa8);
            if (DAT_008d1c2c < 2) {
              DAT_008d1c2c = DAT_008d1c2c + DAT_008d1c14;
            }
            DAT_008d1c2c = DAT_008d1c2c + -2;
          }
          iVar2 = DAT_008d1c2c * 0x80;
          *(undefined4 *)(puVar7 + -0xa4) = 0;
          *(undefined4 *)(puVar7 + -0xb8) = 0x80;
          *(undefined **)(puVar7 + -0xb4) = &DAT_01a78900 + iVar2;
          *(undefined4 *)(puVar7 + -0xb0) = 0x80;
          *(undefined **)(puVar7 + -0xac) = &DAT_008d1c38;
          FUN_005f47c0(puVar7 + -0xa4,0xffffffff,0x784ff00,&DAT_0076669c,puVar7 + -0xb8);
          FUN_005f33c9(puVar7,0x4f5cac);
          FUN_005f34d1(puVar7,0x4f5cc7);
          ram0x00794fc0 = 1;
          _DAT_020b90a0 = DAT_00766658;
          return;
        }
        *(undefined4 *)(puVar7 + -0x1c) = 0;
        DAT_008d1c0c = DAT_008d1c0c + 1;
        *(int *)(puVar7 + -0x28) = *(int *)(puVar7 + -0x28) + -1;
      } while (0 < *(int *)(puVar7 + -0x28));
      *(undefined4 *)(puVar7 + -0x18) = 0;
      DAT_008d1c2c = DAT_008d1c2c + 1;
      *(int *)(puVar7 + -0x2c) = *(int *)(puVar7 + -0x2c) + -1;
      iVar2 = *(int *)(puVar7 + -0x2c);
    } while( true );
  }
  DAT_008d1c30 = 0;
  puVar4 = &DAT_0078b510;
  puVar5 = &DAT_008d1c40;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  local_88 = 0x80;
  DAT_008d1c2c = 1;
  do {
    if ((&DAT_008d1c3f)[DAT_008d1c2c] == '\\') {
      DAT_008d1c28 = DAT_008d1c2c + 1;
      for (iVar2 = 0x81 - DAT_008d1c28; 0 < iVar2; iVar2 = iVar2 + -1) {
        if ((&DAT_008d1c3f)[DAT_008d1c28] == '\\') {
          iVar2 = (DAT_008d1c28 - DAT_008d1c2c) + -1;
          if (iVar2 < 0) {
            iVar2 = 0;
          }
          _DAT_008d1c24 = FUN_00601c70((int)&DAT_008d1c40 + DAT_008d1c2c,iVar2);
          goto LAB_004f53af;
        }
        DAT_008d1c28 = DAT_008d1c28 + 1;
      }
    }
    DAT_008d1c2c = DAT_008d1c2c + 1;
    local_88 = local_88 + -1;
  } while (0 < local_88);
LAB_004f53af:
  local_6c = 0x80;
  DAT_008d1c28 = 1;
  do {
    if (*(char *)(DAT_008d1c28 + 0x78b50f) == '\0') goto LAB_004f5404;
    DAT_008d1c28 = DAT_008d1c28 + 1;
    local_6c = local_6c + -1;
  } while (0 < local_6c);
  DAT_008d1c28 = 0x80;
LAB_004f5404:
  DAT_008d1c2c = DAT_008d1c28 + -1;
  iVar2 = -DAT_008d1c2c / -1;
joined_r0x004f5429:
  if (iVar2 < 1) {
    if (DAT_008d1c30 == 0) {
      return;
    }
    DAT_008d1c40._0_1_ = DAT_007666bc;
    FUN_005f46bc(&stack0xfffffffc,0x4f5668);
    FUN_005f34d1(puVar6,0x4f567e);
    puVar3 = puVar6;
    FUN_005f34d1(puVar6,0x4f569f);
  }
  else {
    if (((&DAT_008d1c3f)[DAT_008d1c2c] != '\\') && ((&DAT_008d1c3f)[DAT_008d1c2c] != ':'))
    goto code_r0x004f5453;
    DAT_008d1c20 = DAT_008d1c2c + 1;
    DAT_008d1c1c = DAT_008d1c2c;
    FUN_005f46bc(&stack0xfffffffc,0x4f5501);
    FUN_005f34d1(puVar3,0x4f5517);
    while (*(char *)((int)&DAT_008d1c40 + DAT_008d1c20) != '.') {
      DAT_008d1c20 = DAT_008d1c20 + 1;
      if (0x80 < DAT_008d1c20) {
        *(undefined4 *)(puVar3 + -0x54) = 0;
        return;
      }
      *(undefined4 *)(puVar3 + -0x50) = 0;
    }
    if (DAT_008d1c30 == 0) {
      *(undefined4 *)(puVar3 + -0x5c) = 0;
    }
    else {
      DAT_008d1c20 = DAT_008d1c30 + -1;
      *(undefined4 *)(puVar3 + -0x58) = 0;
    }
    *(undefined1 *)((int)&DAT_008d1c40 + DAT_008d1c2c) = 0x2a;
    thunk_FUN_0054c5f8((int)&DAT_008d1c40 + DAT_008d1c20,1,DAT_008d1c2c + 0x8d1c41,1,&DAT_007666c4);
    thunk_FUN_0054c83c(&DAT_008d1c40,0x80,&DAT_007666c0);
    DAT_008d1c30 = 0;
    *(undefined4 *)(puVar3 + -0x4c) = 0;
  }
  DAT_008d1c18 = -1;
  DAT_008d1c14 = 0;
  *(undefined4 *)(puVar3 + -0x3c) = 1000;
  DAT_008d1c2c = 1;
  do {
    DAT_008d1c30 = FUN_005f7bb0(&DAT_008d1c40,0x80,&DAT_008d1cc0,&DAT_008d1c18);
    if ((DAT_008d1c18 == -2) || (DAT_008d1c18 == -3)) {
      *(undefined4 *)(puVar3 + -0x38) = 0;
      break;
    }
    DAT_008d1c14 = DAT_008d1c14 + 1;
    *(undefined4 *)(puVar3 + -0xa8) = 0;
    FUN_005f46bc(puVar3,0x4f5765);
    FUN_005f34d1(puVar3,0x4f577b);
    FUN_005f46bc(puVar3,0x4f57bf);
    FUN_005f34d1(puVar3,0x4f57d5);
    puVar4 = (undefined4 *)(DAT_008d1c14 * 0x80 + 0x1a78980);
    puVar5 = (undefined4 *)(puVar3 + -0x138);
    for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    register0x00000000 = FUN_005ff950(puVar3 + -0x138,0x80);
    register0x00000000 = register0x00000000 + 1;
    FUN_005f46bc(puVar3,0x4f5856);
    FUN_005f34d1(puVar3,0x4f586c);
    thunk_FUN_0054c83c(DAT_008d1c14 * 0x80 + 0x1a78980,0x80,&DAT_007666c0);
    DAT_008d1c2c = DAT_008d1c2c + 1;
    *(int *)(puVar3 + -0x3c) = *(int *)(puVar3 + -0x3c) + -1;
  } while (0 < *(int *)(puVar3 + -0x3c));
  *(undefined4 **)(puVar3 + -0xb0) = &DAT_01a78a00;
  FUN_006027f0(puVar3 + -0xb0,&DAT_008d1c14,&DAT_007666c0);
  *(undefined4 *)(puVar3 + -0x34) = 0;
  ram0x00794fc0 = 0;
  return;
code_r0x004f5453:
  if (((&DAT_008d1c3f)[DAT_008d1c2c] == '.') && (DAT_008d1c30 == 0)) {
    DAT_008d1c30 = DAT_008d1c2c;
  }
  DAT_008d1c2c = DAT_008d1c2c + -1;
  iVar2 = iVar2 + -1;
  goto joined_r0x004f5429;
}


