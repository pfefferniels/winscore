// FUN_00501a98 @ 00501a98 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00501ef4) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00501a98(void)

{
  undefined1 *puVar1;
  uint uVar2;
  int iVar3;
  undefined1 *puVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  bool bVar9;
  bool bVar10;
  
  puVar4 = &stack0xfffffffc;
  do {
    puVar6 = &DAT_01ae2880;
    puVar8 = (undefined4 *)(puVar4 + -200);
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    DAT_00902914 = FUN_005ff950(puVar4 + -200,0x80);
    FUN_005f46bc(puVar4,0x501aff);
    FUN_005f46bc(puVar4,0x501b1b);
    FUN_005f46bc(puVar4,0x501b37);
    FUN_005f33c9(puVar4,0x501b59);
    FUN_005f34d1(puVar4,0x501b74);
    DAT_02091d04 = 0xfffffb2e;
    FUN_005f34d1(puVar4,0x501ba0);
    thunk_FUN_00571f5d("Type output file name.",0x16);
    DAT_02091d04 = 0;
    bVar9 = (byte)DAT_020b8ea0 < 2;
    if ((byte)DAT_020b8ea0 == 2) {
      *(undefined4 *)(puVar4 + -0x1c) = 0;
      DAT_0078b4e0 = 0x2d;
      DAT_02091d04 = 0;
      return;
    }
    iVar3 = 1;
    bVar10 = false;
    pbVar5 = (byte *)&DAT_020b8ea0;
    pbVar7 = &DAT_0079551c;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar9 = *pbVar5 < *pbVar7;
      bVar10 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar10);
    if (bVar9 || bVar10) {
      puVar6 = &DAT_01ba20a0;
      puVar8 = (undefined4 *)&DAT_020b8ea0;
      for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar8 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar8 = puVar8 + 1;
      }
    }
    thunk_FUN_0054c6b5(&DAT_020b8ea0,1,&DAT_00902914,&DAT_0078b4e0,&DAT_0078b4e4);
    iVar3 = (int)-DAT_00902914 / -1;
    *(int *)(puVar4 + -0x18) = iVar3;
    DAT_01ba2120 = DAT_00902914;
    while (0 < iVar3) {
      if (DAT_00795520 == (&DAT_020b8e9f)[DAT_01ba2120]) {
        *(undefined4 *)(puVar4 + -0x14) = 0;
        goto LAB_00501d14;
      }
      DAT_01ba2120 = DAT_01ba2120 - 1;
      *(int *)(puVar4 + -0x18) = *(int *)(puVar4 + -0x18) + -1;
      iVar3 = *(int *)(puVar4 + -0x18);
    }
    thunk_FUN_0054946a("Extension \".PAG\" added to output name.",0x27);
    puVar1 = &DAT_020b8ea3 + DAT_00902914;
    DAT_00902914 = DAT_00902914 + 4;
    *puVar1 = (char)DAT_00795524;
    (&DAT_020b8e9e)[DAT_00902914] = (char)DAT_00795528;
    (&DAT_020b8e9d)[DAT_00902914] = (char)DAT_0079552c;
    (&DAT_020b8e9c)[DAT_00902914] = (char)_DAT_00795520;
    DAT_01ba2120 = DAT_00902914 - 3;
LAB_00501d14:
    *(undefined1 *)((int)&DAT_020b8ea0 + DAT_00902914) = 0;
    *(uint *)(puVar4 + -0x48) = DAT_00902914 + 1;
    thunk_FUN_0054c5f8(&DAT_020b8ea0,1,&DAT_01ba20a0,0x80,puVar4 + -0x48);
    uVar2 = DAT_01ba2120;
    bVar9 = DAT_01ba2120 == 1;
    if (1 < (int)DAT_01ba2120) {
      DAT_01ba2120 = DAT_01ba2120 - 1;
      bVar9 = DAT_01ba2120 == 0;
    }
    bVar10 = uVar2 == 0;
    DAT_01ba2129 = (&DAT_020b8e9f)[DAT_01ba2120];
    DAT_01ba2128 = DAT_00795518;
    iVar3 = 1;
    pbVar5 = &DAT_00902918;
    pbVar7 = &DAT_00795518;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *pbVar5 < *pbVar7;
      bVar9 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar9);
    if (!bVar10 && !bVar9) {
      DAT_01ba2128 = DAT_00795514;
    }
    DAT_01ba2127 = (&DAT_020b8e9e)[DAT_01ba2120];
    DAT_01ba2126 = DAT_00795518;
    iVar3 = 1;
    pbVar5 = &DAT_020b8e9e + DAT_01ba2120;
    pbVar7 = &DAT_00795518;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      bVar10 = *pbVar5 < *pbVar7;
      bVar9 = *pbVar5 == *pbVar7;
      pbVar5 = pbVar5 + 1;
      pbVar7 = pbVar7 + 1;
    } while (bVar9);
    if (!bVar10 && !bVar9) {
      DAT_01ba2126 = DAT_00795514;
    }
    DAT_01ba2125 = DAT_01ba2127;
    if (2 < (int)DAT_01ba2120) {
      DAT_01ba2125 = (&DAT_020b8e9d)[DAT_01ba2120];
    }
    _DAT_00902918 = CONCAT31(DAT_00902918_1,DAT_01ba2125);
    DAT_01ba2124 = DAT_00795518;
    bVar9 = DAT_01ba2120 < 2;
    bVar10 = DAT_01ba2120 == 2;
    if (2 < (int)DAT_01ba2120) {
      iVar3 = 1;
      pbVar5 = &DAT_020b8e9d + DAT_01ba2120;
      pbVar7 = &DAT_00795518;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        bVar9 = *pbVar5 < *pbVar7;
        bVar10 = *pbVar5 == *pbVar7;
        pbVar5 = pbVar5 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar10);
      if (!bVar9 && !bVar10) {
        DAT_01ba2124 = DAT_00795514;
      }
    }
    puVar6 = &DAT_01ba20a0;
    puVar8 = &DAT_01b9d540;
    for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar8 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar8 = puVar8 + 1;
    }
    iVar3 = thunk_FUN_0050273b(&DAT_01ba20a0,0x80);
    if (iVar3 != 0) {
      *(undefined4 *)(puVar4 + -0x10) = 0;
      return;
    }
    *(undefined4 *)(puVar4 + -0xc) = 0x80;
    DAT_00902914 = 0x80;
    do {
      iVar3 = FUN_005f4660(0x20);
      if (iVar3 == 0) {
        *(undefined4 *)(puVar4 + -8) = 0;
        break;
      }
      DAT_00902914 = DAT_00902914 + -1;
      *(int *)(puVar4 + -0xc) = *(int *)(puVar4 + -0xc) + -1;
    } while (0 < *(int *)(puVar4 + -0xc));
    FUN_005f33c9(puVar4,0x501f60);
    FUN_005f34d1(puVar4,0x501f7b);
    FUN_005f46bc(puVar4,0x501fb0);
    FUN_005f34d1(puVar4,0x501fc6);
    DAT_0090297c = 0;
    DAT_00902940 = i_7562585;
    DAT_00902944 = i_538976288;
    DAT_00902948 = DAT_00766c7c;
    DAT_00902930._0_1_ = s_New_name_00766c68[0];
    DAT_00902930._1_1_ = s_New_name_00766c68[1];
    DAT_00902930._2_1_ = s_New_name_00766c68[2];
    DAT_00902930._3_1_ = s_New_name_00766c68[3];
    DAT_00902934._0_1_ = s_New_name_00766c68[4];
    DAT_00902934._1_1_ = s_New_name_00766c68[5];
    DAT_00902934._2_1_ = s_New_name_00766c68[6];
    DAT_00902934._3_1_ = s_New_name_00766c68[7];
    DAT_00902938 = ram0x00766c70;
    DAT_00902920 = i_1953069125;
    DAT_00902924 = i_538976256;
    DAT_00902928 = DAT_00766c64;
    DAT_00902910 = thunk_FUN_00595720(&DAT_00902950,&DAT_00902940,&DAT_00902930,&DAT_00902920,0);
    if (-1 < DAT_00902910) {
      if (0 < DAT_00902910) {
        DAT_0078b4e0 = 0x2d;
      }
      thunk_FUN_0054946a(&DAT_00766c90,1);
      return;
    }
    *(undefined4 *)(puVar4 + -4) = 0;
  } while( true );
}


