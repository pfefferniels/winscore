// FUN_004f41aa @ 004f41aa (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f41aa(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *piVar6;
  undefined4 *puVar7;
  bool bVar8;
  undefined1 *puVar9;
  undefined1 *puVar10;
  undefined4 local_a4;
  undefined4 *local_a0;
  undefined4 *local_9c;
  undefined4 local_90 [8];
  undefined4 local_70;
  undefined4 local_64;
  undefined4 local_54;
  undefined4 local_4c;
  
  puVar9 = &stack0xfffffffc;
  puVar10 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (((_DAT_020b8ea0 & 0xffff) == 0x5853) || ((_DAT_020b8ea0 & 0xffff) == 0x4253)) {
    local_70 = 0;
    if ((DAT_0078b4e4 != 0x58) && (DAT_0078b4e4 != 0x42)) {
      return;
    }
    if ((_DAT_020b8ea0 >> 0x10 & 0xff) == 0x41) {
      local_54 = 0;
    }
    else {
      local_90[0] = 0;
      local_a4 = 0xc;
      local_a0 = (undefined4 *)&DAT_0076664c;
      local_9c = &DAT_008d1a60;
      FUN_005f47c0(local_90,0xffffffff,0x784ff00,&DAT_0076665c,&local_a4);
      if ((DAT_008d1a60 & 1) != 0) {
        local_4c = 0;
      }
      FUN_005f33c9(&stack0xfffffffc,0x4f4421);
      puVar3 = puVar10;
      FUN_005f34d1(puVar10,0x4f443c);
      *(undefined4 *)(puVar3 + -0x44) = 0x7e;
      DAT_008d1a58 = 0x80;
      do {
        if ((&DAT_020b8e9f)[DAT_008d1a58] == '\\') {
          FUN_005f46bc(puVar3,0x4f44d9);
          FUN_005f34d1(puVar3,0x4f44ef);
          *(undefined4 *)(puVar3 + -0x3c) = 0;
          break;
        }
        *(undefined4 *)(puVar3 + -0x40) = 0;
        *(undefined4 *)(puVar3 + -0x38) = 0;
        DAT_008d1a58 = DAT_008d1a58 + -1;
        *(int *)(puVar3 + -0x44) = *(int *)(puVar3 + -0x44) + -1;
      } while (0 < *(int *)(puVar3 + -0x44));
      *(undefined4 *)(puVar3 + -0x34) = 0x7f;
      DAT_008d1a58 = 2;
      do {
        if ((&DAT_020b8e9f)[DAT_008d1a58] == '.') {
          *(undefined4 *)(puVar3 + -0x30) = 0;
          break;
        }
        DAT_008d1a58 = DAT_008d1a58 + 1;
        *(int *)(puVar3 + -0x34) = *(int *)(puVar3 + -0x34) + -1;
      } while (0 < *(int *)(puVar3 + -0x34));
      _DAT_020b90a0 = (undefined2)_DAT_020b8ea0;
      _DAT_020b90a2 = (undefined2)(_DAT_020b8ea0 >> 0x10);
      DAT_020b90a4._0_2_ = (undefined2)_DAT_020b8ea4;
      DAT_020b90a4._2_2_ = (undefined2)((uint)_DAT_020b8ea4 >> 0x10);
      iVar2 = 0x81 - DAT_008d1a58;
      *(int *)(puVar3 + -0x2c) = iVar2;
      DAT_008d1a54 = DAT_008d1a58;
      while (0 < iVar2) {
        (&DAT_020b909f)[DAT_008d1a54] = 0x20;
        DAT_008d1a54 = DAT_008d1a54 + 1;
        *(int *)(puVar3 + -0x2c) = *(int *)(puVar3 + -0x2c) + -1;
        iVar2 = *(int *)(puVar3 + -0x2c);
      }
      _DAT_020b90a8 = (undefined2)DAT_0078b690;
      _DAT_020b90aa = (undefined2)((uint)DAT_0078b690 >> 0x10);
      *(undefined4 *)(puVar3 + -0x8c) = 0;
      *(undefined4 *)(puVar3 + -0xa0) = 0xc;
      *(undefined **)(puVar3 + -0x9c) = &DAT_0076664c;
      *(undefined4 *)(puVar3 + -0x98) = 2;
      *(undefined4 *)(puVar3 + -0x94) = 4;
      uVar1 = FUN_005f6540(puVar3 + -0x8c,0x21,0x784ff01,&DAT_0076663c,puVar3 + -0xa0);
      *(undefined4 *)(puVar3 + -0x28) = uVar1;
      if (*(int *)(puVar3 + -0x28) == 0) {
        FUN_005f34d1(puVar3,0x4f464f);
        while( true ) {
          *(undefined4 *)(puVar3 + -0x8c) = 0;
          *(undefined4 *)(puVar3 + -0x98) = 0x80;
          *(undefined4 **)(puVar3 + -0x94) = &DAT_008d1ae4;
          uVar1 = FUN_005fdbd0(puVar3 + -0x8c,0x21,0x784ff01,&DAT_00766634,puVar3 + -0x98,
                               &DAT_00794f50);
          *(undefined4 *)(puVar3 + -0x24) = uVar1;
          if (*(int *)(puVar3 + -0x24) != 0) break;
          iVar2 = FUN_005f4660(0x20);
          if (iVar2 != 0) {
            *(undefined4 *)(puVar3 + -0x20) = 0;
            if (DAT_0078b4e4 == 0x58) {
              *(undefined4 *)(puVar3 + -0x18) = 0;
              *(undefined4 *)(puVar3 + -0x8c) = 0;
              *(undefined4 *)(puVar3 + -0x98) = 0xc;
              *(undefined **)(puVar3 + -0x94) = &DAT_020b90a2;
              uVar1 = FUN_005fdbd0(puVar3 + -0x8c,0x21,0x784ff01,&DAT_00766634,puVar3 + -0x98,
                                   &DAT_00794f64);
              *(undefined4 *)(puVar3 + -0x10) = uVar1;
              if (*(int *)(puVar3 + -0x10) != 0) break;
            }
            else {
              _DAT_020b90a2 = (undefined2)DAT_008d1a64;
              DAT_020b90a4._0_2_ = (undefined2)((uint)DAT_008d1a64 >> 0x10);
              DAT_020b90a4._2_2_ = (undefined2)DAT_008d1a68;
              _DAT_020b90a8 = (undefined2)((uint)DAT_008d1a68 >> 0x10);
              _DAT_020b90aa = (undefined2)DAT_008d1a6c;
              _DAT_020b90ac = (undefined2)((uint)DAT_008d1a6c >> 0x10);
              *(undefined4 *)(puVar3 + -0x14) = 0;
            }
            thunk_FUN_0045db4f(&DAT_020b90a2,1);
            goto LAB_004f4829;
          }
          puVar5 = &DAT_008d1ae4;
          puVar7 = &DAT_008d1a64;
          for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          *(undefined4 *)(puVar3 + -0x1c) = 0;
        }
      }
    }
    FUN_005f33c9(puVar3,0x4f47c6);
    FUN_005f34d1(puVar3,0x4f47e1);
    DAT_008d1a54 = 1;
    if (DAT_0078b4e4 == 0x42) {
      DAT_008d1a54 = -1;
    }
    FUN_004f4889(&DAT_020b90a0,0x200,&DAT_008d1a54);
    *(undefined4 *)(puVar3 + -4) = 0;
LAB_004f4829:
    _DAT_020b8ea0 = CONCAT31(ram0x020b8ea1,DAT_007665e0);
    _DAT_020b90a0 = DAT_00766658;
    *(undefined4 *)(puVar3 + -0x8c) = 0;
    FUN_005f7950(puVar3 + -0x8c,0x21,0x784ff00,&DAT_00766614,0);
    *(undefined4 *)(puVar3 + -8) = 0;
    return;
  }
  puVar5 = &DAT_0078b510;
  puVar7 = &DAT_008d1ae4;
  for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar7 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar7 = puVar7 + 1;
  }
  _DAT_008d1a5c = 1;
  if ((_DAT_020b8ea0 >> 8 & 0xff) == 0x42) {
    _DAT_008d1a5c = 0xffffffff;
  }
  while( true ) {
    FUN_004f4bb0(&DAT_0078b510,0x80,&DAT_008d1a5c,&DAT_008d1a58);
    if (DAT_008d1a58 != 0) {
      puVar5 = &DAT_008d1ae4;
      puVar7 = &DAT_0078b510;
      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar7 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar7 = puVar7 + 1;
      }
      return;
    }
    local_90[0] = 0;
    local_a4 = 0x80;
    local_a0 = &DAT_0078b510;
    local_9c = &DAT_008d1a60;
    FUN_005f47c0(local_90,0xffffffff,0x784ff00,&DAT_0076665c,&local_a4);
    bVar8 = (DAT_008d1a60 & 1) == 0;
    if (!bVar8) break;
    local_64 = 0;
  }
  iVar2 = 0x20;
  piVar4 = &DAT_0078b510;
  piVar6 = &DAT_008d1ae4;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    bVar8 = *piVar4 == *piVar6;
    piVar4 = piVar4 + 1;
    piVar6 = piVar6 + 1;
  } while (bVar8);
  if (!bVar8) {
    FUN_005f33c9(&stack0xfffffffc,0x4f4316);
    FUN_005f34d1(puVar9,0x4f4331);
    _DAT_020b90a0 = DAT_00766658;
    *(undefined4 *)(puVar9 + -0x58) = 0;
  }
  return;
}


