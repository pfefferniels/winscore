// FUN_0054b1fc @ 0054b1fc (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0054b1fc(int *param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  undefined1 *puVar4;
  int iVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  byte *pbVar9;
  bool bVar10;
  float10 fVar11;
  undefined *puStack_88;
  undefined4 local_74;
  undefined2 *local_70;
  undefined4 *local_6c;
  undefined4 *local_68;
  undefined4 local_64 [8];
  int local_44;
  int local_40;
  int local_3c;
  int local_14;
  
  puVar4 = &stack0xfffffffc;
  puStack_88 = (undefined *)0x20;
  iVar3 = FUN_005f4660();
  if (iVar3 == 0) {
    puStack_88 = (undefined *)0x20;
    iVar3 = FUN_005f4660();
    if (iVar3 == 0) {
      if (DAT_020b8ea0._1_1_ != 'H') {
        puStack_88 = (undefined *)0x54b5a7;
        thunk_FUN_00575e58();
        puStack_88 = (undefined *)0x54b5ac;
        draw_items();
        return;
      }
      local_64[0] = 0;
      local_74 = 3;
      local_70 = (undefined2 *)&DAT_00769388;
      local_6c = (undefined4 *)0x2;
      local_68 = (undefined4 *)0x4;
      FUN_005f6540(local_64,5,0x784ff00,&DAT_007693a4,&local_74);
      DAT_009a2210 = 1;
      for (local_14 = NPT; 0 < local_14; local_14 = local_14 + -1) {
        local_68 = &PT_X0 + DAT_009a2210;
        local_64[0] = 0;
        local_6c = (undefined4 *)0x4;
        puStack_88 = &DAT_00797678;
        FUN_005fc330(local_64,5,0x784ff00,&DAT_00769384,&local_6c);
        DAT_009a2210 = DAT_009a2210 + 1;
      }
      local_64[0] = 0;
      FUN_005f7950(local_64,5,0x784ff00,&DAT_0076939c,0);
      return;
    }
    puStack_88 = (undefined *)0x54b3fd;
    thunk_FUN_004ea5ef();
    puStack_88 = (undefined *)0x200;
    fVar11 = (float10)FUN_00601b80(&DAT_009ae2bc);
    _DAT_009a220c = (int)ROUND(fVar11);
    local_64[0] = 0;
    local_74 = 3;
    local_70 = &DAT_009ae2dc;
    local_6c = &DAT_01aad480;
    local_68 = (undefined4 *)_DAT_009a220c;
    FUN_005f34f0(local_64,0x784ff00,&DAT_0076915c,&local_74,&DAT_00797664);
    DAT_009ae2df._0_1_ = s_files_0076938c[0];
    DAT_009ae2df._1_1_ = s_files_0076938c[1];
    DAT_009ae2df._2_1_ = s_files_0076938c[2];
    DAT_009ae2df._3_1_ = s_files_0076938c[3];
    DAT_009ae2e3 = ram0x00769390;
    DAT_009ae2e7 = i_538976288;
    DAT_009bb1cc = DAT_01aad480;
    DAT_009a2214 = -99;
    iVar3 = thunk_FUN_0059a430(&DAT_009a2214);
    *param_1 = iVar3;
    if ((DAT_009a2214 == 0) || (*param_1 == 2)) {
LAB_0054b579:
      *param_1 = 2;
      return;
    }
    puStack_88 = (undefined *)0x54b4ff;
    FUN_005f33c9();
    bVar10 = (undefined1 *)0xfffffffb < &puStack_88;
    iVar3 = 1;
    pbVar7 = (byte *)&DAT_01c4cb60;
    pbVar9 = &DAT_00769150;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar2 = *pbVar9;
      bVar1 = *pbVar7;
      bVar10 = bVar1 < bVar2;
      pbVar7 = pbVar7 + 1;
      pbVar9 = pbVar9 + 1;
    } while (bVar1 == bVar2);
    if (!bVar10) {
      puStack_88 = (undefined *)0x54b51d;
      load_score();
    }
    puStack_88 = (undefined *)0x54b53a;
    FUN_005f34d1();
    *(undefined4 *)(puVar4 + -0x20) = 0;
  }
  else {
    local_64[0] = 0;
    local_74 = 0x14;
    local_70 = (undefined2 *)&DAT_007693b4;
    local_6c = (undefined4 *)0x2;
    local_68 = (undefined4 *)0x4;
    local_44 = FUN_005f6540(local_64,0x11,0x784ff01,&DAT_007693a4,&local_74);
    puVar4 = &stack0xfffffffc;
    if (local_44 == 0) {
      local_40 = 0x28;
      DAT_009a2210 = 1;
      iVar3 = local_3c;
      do {
        local_3c = iVar3;
        local_70 = (undefined2 *)(&DAT_0078b650 + DAT_009a2210 * 0x80);
        local_64[0] = 0;
        local_74 = 0x80;
        local_6c = (undefined4 *)0x80;
        puStack_88 = &DAT_00797650;
        local_3c = FUN_005fdbd0(local_64,0x11,0x784ff01,&DAT_007693a0,&local_74);
        if (local_3c != 0) break;
        DAT_009a2210 = DAT_009a2210 + 1;
        local_40 = local_40 + -1;
        iVar3 = 0;
      } while (0 < local_40);
      local_64[0] = 0;
      FUN_005f7950(local_64,0x11,0x784ff00,&DAT_0076939c,0);
      DAT_009a2214 = -99;
      iVar3 = thunk_FUN_0059a340(&DAT_009a2214);
      *param_1 = iVar3;
      if ((DAT_009a2214 == 0) || (*param_1 == 2)) goto LAB_0054b579;
      iVar5 = (int)((longlong)DAT_009a2214 * 0x80);
      bVar10 = (longlong)iVar5 != (longlong)DAT_009a2214 * 0x80;
      puVar6 = (undefined4 *)(&DAT_0078b650 + iVar5);
      puVar8 = &DAT_01c4cb60;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
      iVar3 = 1;
      pbVar7 = (byte *)&DAT_01c4cb60;
      pbVar9 = &DAT_00769150;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar2 = *pbVar9;
        bVar1 = *pbVar7;
        bVar10 = bVar1 < bVar2;
        pbVar7 = pbVar7 + 1;
        pbVar9 = pbVar9 + 1;
      } while (bVar1 == bVar2);
      puVar4 = &stack0xfffffffc;
      if (!bVar10) {
        puStack_88 = (undefined *)0x54b3b9;
        load_score();
        puVar4 = &stack0xfffffffc;
      }
    }
  }
  puStack_88 = (undefined *)0x54b562;
  FUN_005f34d1();
  *(undefined4 *)(puVar4 + -0x2c) = 0;
  return;
}


