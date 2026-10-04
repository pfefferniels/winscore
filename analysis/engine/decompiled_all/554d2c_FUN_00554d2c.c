// FUN_00554d2c @ 00554d2c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_00554d2c(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  if (*param_1 == 0) {
    FUN_005f34d1(&stack0xfffffffc,0x554d69);
    if (_DAT_020b8ea0 == 0x4e42494c) {
LAB_00554ecc:
      DAT_01a1ae60._0_1_ = s_symblist_txt_00769904[0];
      DAT_01a1ae60._1_1_ = s_symblist_txt_00769904[1];
      DAT_01a1ae60._2_1_ = s_symblist_txt_00769904[2];
      DAT_01a1ae60._3_1_ = s_symblist_txt_00769904[3];
      DAT_01a1ae64._0_1_ = s_symblist_txt_00769904[4];
      DAT_01a1ae64._1_1_ = s_symblist_txt_00769904[5];
      DAT_01a1ae64._2_1_ = s_symblist_txt_00769904[6];
      DAT_01a1ae64._3_1_ = s_symblist_txt_00769904[7];
      DAT_01a1ae68._0_1_ = s_symblist_txt_00769904[8];
      DAT_01a1ae68._1_1_ = s_symblist_txt_00769904[9];
      DAT_01a1ae68._2_1_ = s_symblist_txt_00769904[10];
      DAT_01a1ae68._3_1_ = s_symblist_txt_00769904[0xb];
      DAT_01a1ae6c._0_1_ = s_symblist_txt_00769904[0xc];
      DAT_01a1ae6c._1_1_ = UNK_00769911;
      DAT_01a1ae6c._2_1_ = UNK_00769912;
      DAT_01a1ae6c._3_1_ = UNK_00769913;
      FUN_005f46bc(puVar3,0x554f1f);
      FUN_005f46bc(puVar3,0x554f3b);
      FUN_005f34d1(puVar3,0x554f51);
      *(undefined4 *)(puVar3 + -0x48) = 0;
      *(undefined4 *)(puVar3 + -0x58) = 0x80;
      *(undefined **)(puVar3 + -0x54) = &DAT_009a3aa8;
      *(undefined4 *)(puVar3 + -0x50) = 2;
      *(undefined4 *)(puVar3 + -0x4c) = 4;
      uVar1 = FUN_005f6540(puVar3 + -0x48,0x11,0x784ff01,&DAT_007698ec,puVar3 + -0x58);
      *(undefined4 *)(puVar3 + -0x14) = uVar1;
      iVar2 = *(int *)(puVar3 + -0x14);
      puVar4 = puVar3;
    }
    else {
      DAT_01a1ae60._0_1_ = s_symblist_alf_txt_00769920[0];
      DAT_01a1ae60._1_1_ = s_symblist_alf_txt_00769920[1];
      DAT_01a1ae60._2_1_ = s_symblist_alf_txt_00769920[2];
      DAT_01a1ae60._3_1_ = s_symblist_alf_txt_00769920[3];
      DAT_01a1ae64._0_1_ = s_symblist_alf_txt_00769920[4];
      DAT_01a1ae64._1_1_ = s_symblist_alf_txt_00769920[5];
      DAT_01a1ae64._2_1_ = s_symblist_alf_txt_00769920[6];
      DAT_01a1ae64._3_1_ = s_symblist_alf_txt_00769920[7];
      DAT_01a1ae68._0_1_ = s_symblist_alf_txt_00769920[8];
      DAT_01a1ae68._1_1_ = s_symblist_alf_txt_00769920[9];
      DAT_01a1ae68._2_1_ = s_symblist_alf_txt_00769920[10];
      DAT_01a1ae68._3_1_ = s_symblist_alf_txt_00769920[0xb];
      DAT_01a1ae6c._0_1_ = s_symblist_alf_txt_00769920[0xc];
      DAT_01a1ae6c._1_1_ = s_symblist_alf_txt_00769920[0xd];
      DAT_01a1ae6c._2_1_ = s_symblist_alf_txt_00769920[0xe];
      DAT_01a1ae6c._3_1_ = s_symblist_alf_txt_00769920[0xf];
      FUN_005f46bc(puVar3,0x554dd5);
      FUN_005f46bc(puVar3,0x554df1);
      FUN_005f34d1(puVar3,0x554e07);
      *(undefined4 *)(puVar3 + -0x48) = 0;
      *(undefined4 *)(puVar3 + -0x58) = 0x80;
      *(undefined **)(puVar3 + -0x54) = &DAT_009a3aa8;
      *(uint **)(puVar3 + -0x50) = &DAT_009a3a70;
      FUN_005f47c0(puVar3 + -0x48,0xffffffff,0x784ff00,&DAT_00769914,puVar3 + -0x58);
      if ((DAT_009a3a70 & 1) == 0) {
        *(undefined4 *)(puVar3 + -0x1c) = 0;
        goto LAB_00554ecc;
      }
      *(undefined4 *)(puVar3 + -0x48) = 0;
      *(undefined4 *)(puVar3 + -0x58) = 0x80;
      *(undefined **)(puVar3 + -0x54) = &DAT_009a3aa8;
      *(undefined4 *)(puVar3 + -0x50) = 2;
      *(undefined4 *)(puVar3 + -0x4c) = 4;
      uVar1 = FUN_005f6540(puVar3 + -0x48,0x11,0x784ff01,&DAT_007698ec,puVar3 + -0x58);
      *(undefined4 *)(puVar3 + -0x18) = uVar1;
      iVar2 = *(int *)(puVar3 + -0x18);
      puVar4 = puVar3;
    }
    if (iVar2 != 0) {
      FUN_005f33c9(puVar4,0x555141);
      FUN_005f34d1(puVar4,0x55515c);
      thunk_FUN_0042ac4e(&DAT_020b90a0,0x7f);
      **(undefined4 **)(puVar4 + 8) = 1;
      goto LAB_0055517b;
    }
    **(undefined4 **)(puVar4 + 8) = 0xffffffff;
  }
  *(undefined4 *)(puVar4 + -0x48) = 0;
  *(undefined4 *)(puVar4 + -0x50) = 0x30;
  *(undefined4 **)(puVar4 + -0x4c) = &DAT_009a3a78;
  uVar1 = FUN_005fdbd0(puVar4 + -0x48,0x11,0x784ff01,&DAT_007698e8,puVar4 + -0x50,&DAT_0079ec70);
  *(undefined4 *)(puVar4 + -0x10) = uVar1;
  if (*(int *)(puVar4 + -0x10) == 0) {
    puVar5 = &DAT_009a3a78;
    puVar6 = (undefined4 *)(puVar4 + -0x88);
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    iVar2 = FUN_005ff950(puVar4 + -0x88,0x30);
    DAT_009a3a6c = iVar2 + 1;
    FUN_005f46bc(puVar4,0x555074);
    FUN_005f34d1(puVar4,0x55508a);
    FUN_005f33c9(puVar4,0x5550ac);
    FUN_005f34d1(puVar4,0x5550c7);
    if (DAT_007a0b7c != '*') {
      *(undefined4 *)(puVar4 + -0xc) = 0;
      goto LAB_0055517b;
    }
  }
  **(undefined4 **)(puVar4 + 8) = 1;
  *(undefined4 *)(puVar4 + -0x48) = 0;
  FUN_005f7950(puVar4 + -0x48,0x11,0x784ff00,&DAT_007698dc,0);
  *(undefined4 *)(puVar4 + -4) = 0;
LAB_0055517b:
  return (float10)*(float *)(puVar4 + -0x28);
}


