// FUN_004fb38a @ 004fb38a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004fb38a(uint *param_1)

{
  undefined1 uVar1;
  undefined1 uVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  byte *pbVar6;
  bool bVar7;
  bool bVar8;
  
  puVar4 = &stack0xfffffffc;
  uVar1 = (&DAT_01c4eec3)[DAT_01c4ef40 * 0x80 + *param_1];
  if (*param_1 == 1) {
    bVar7 = false;
    bVar8 = true;
  }
  else {
    _DAT_00901cd8 = CONCAT31(DAT_00901cd8_1,(&DAT_01c4eec2)[DAT_01c4ef40 * 0x80 + *param_1]);
    bVar7 = CARRY4(DAT_01c4ef40 * 0x80,*param_1);
    iVar3 = DAT_01c4ef40 * 0x80 + *param_1;
    bVar8 = iVar3 == 0;
    _DAT_00901ce0 = CONCAT31(DAT_00901ce0_1,(&DAT_01c4eec1)[iVar3]);
  }
  DAT_00901ccc = 1;
  DAT_00901cc8 = 0x5a;
  iVar3 = 1;
  pbVar5 = &DAT_00901cd0;
  pbVar6 = &DAT_007669e4;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    bVar7 = *pbVar5 < *pbVar6;
    bVar8 = *pbVar5 == *pbVar6;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  } while (bVar8);
  uVar2 = DAT_007669e8;
  if (bVar7 || bVar8) {
    DAT_00901cc8 = 0x39;
    uVar2 = DAT_007669e0;
  }
  _DAT_00901cd4 = CONCAT31(DAT_00901cd4_1,uVar2);
  bVar7 = *param_1 == 0;
  bVar8 = *param_1 == 1;
  DAT_00901cd0 = uVar1;
  if (!bVar8) {
    DAT_00901cc4 = 0x5a;
    iVar3 = 1;
    pbVar5 = &DAT_00901cd8;
    pbVar6 = &DAT_007669e4;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar7 = *pbVar5 < *pbVar6;
      bVar8 = *pbVar5 == *pbVar6;
      pbVar5 = pbVar5 + 1;
      pbVar6 = pbVar6 + 1;
    } while (bVar8);
    uVar1 = DAT_007669e8;
    if (bVar7 || bVar8) {
      DAT_00901cc4 = 0x39;
      uVar1 = DAT_007669e0;
    }
    _DAT_00901cdc = CONCAT31(DAT_00901cdc_1,uVar1);
    bVar7 = *param_1 < 2;
    bVar8 = *param_1 == 2;
    puVar4 = &stack0xfffffffc;
    if (!bVar8) {
      DAT_00901cc0 = 0x5a;
      DAT_00901ce4 = DAT_007669e8;
      iVar3 = 1;
      pbVar5 = &DAT_00901ce0;
      pbVar6 = &DAT_007669e4;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar7 = *pbVar5 < *pbVar6;
        bVar8 = *pbVar5 == *pbVar6;
        pbVar5 = pbVar5 + 1;
        pbVar6 = pbVar6 + 1;
      } while (bVar8);
      puVar4 = &stack0xfffffffc;
      if (bVar7 || bVar8) {
        DAT_00901ce4 = DAT_007669e0;
        DAT_00901cc0 = 0x39;
        puVar4 = &stack0xfffffffc;
      }
    }
  }
  do {
    while (bVar7 = DAT_0078b4e0 != 0,
          iVar3 = thunk_FUN_0050273b(&DAT_01c4eec4 + DAT_01c4ef40 * 0x80,0x80), bVar7 || iVar3 == 0)
    {
LAB_004fb588:
      if (DAT_01c4ef40 == **(int **)(puVar4 + 0xc)) {
        *(undefined4 *)(puVar4 + -0x18) = 0;
        return;
      }
      FUN_005f33c9(puVar4,0x4fb5cb);
      DAT_00901cb8 = CONCAT31(DAT_00901cb8._1_3_,DAT_00901cd0);
      DAT_00901cb8 = DAT_00901cb8 + 1;
      DAT_00901cd0 = (undefined1)DAT_00901cb8;
      DAT_00901ccc = 1;
      DAT_01c4ef40 = DAT_01c4ef40 + 1;
      (&DAT_01c4eec3)[DAT_01c4ef40 * 0x80 + *param_1] = (undefined1)DAT_00901cb8;
      if (DAT_00901cc8 < DAT_00901cb8) {
LAB_004fb64e:
        if (*param_1 == 1) {
          *(undefined4 *)(puVar4 + -0x10) = 0;
          goto LAB_004fb7b1;
        }
        (&DAT_01c4eec3)[DAT_01c4ef40 * 0x80 + *param_1] = (char)_DAT_00901cd4;
        DAT_00901ccc = 2;
        DAT_00901cb8 = CONCAT31(DAT_00901cb8._1_3_,DAT_00901cd8);
        DAT_00901cb8 = DAT_00901cb8 + 1;
        _DAT_00901cd8 = CONCAT31(DAT_00901cd8_1,(undefined1)DAT_00901cb8);
        (&DAT_01c4eec2)[DAT_01c4ef40 * 0x80 + *param_1] = (undefined1)DAT_00901cb8;
        DAT_00901cd0 = DAT_00901cd4;
        if (DAT_00901cc4 < DAT_00901cb8) goto LAB_004fb6f3;
        *(undefined4 *)(puVar4 + -0xc) = 0;
      }
      else {
        *(undefined4 *)(puVar4 + -0x14) = 0;
      }
    }
    if (DAT_00901ccc == 1) goto LAB_004fb64e;
    if (DAT_00901ccc != 2) {
      if (DAT_00901ccc != 3) goto LAB_004fb588;
      goto LAB_004fb7b1;
    }
LAB_004fb6f3:
    if (*param_1 == 2) {
      *(undefined4 *)(puVar4 + -8) = 0;
LAB_004fb7b1:
      DAT_01c4ef40 = DAT_01c4ef40 + -1;
      return;
    }
    (&DAT_01c4eec2)[DAT_01c4ef40 * 0x80 + *param_1] = (char)_DAT_00901cdc;
    DAT_00901ccc = 3;
    DAT_00901cb8 = CONCAT31(DAT_00901cb8._1_3_,DAT_00901ce0);
    DAT_00901cb8 = DAT_00901cb8 + 1;
    _DAT_00901ce0 = CONCAT31(DAT_00901ce0_1,(undefined1)DAT_00901cb8);
    (&DAT_01c4eec1)[DAT_01c4ef40 * 0x80 + *param_1] = (undefined1)DAT_00901cb8;
    _DAT_00901cd8 = CONCAT31(DAT_00901cd8_1,DAT_00901cdc);
    if (DAT_00901cc0 < DAT_00901cb8) goto LAB_004fb7b1;
    *(undefined4 *)(puVar4 + -4) = 0;
  } while( true );
}


