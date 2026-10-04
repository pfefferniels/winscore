// FUN_004aac7d @ 004aac7d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004aba8a) */
/* WARNING: Removing unreachable block (ram,0x004abade) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 FUN_004aac7d(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  undefined4 local_bc;
  char *local_b8;
  undefined4 local_b4;
  int *local_b0;
  undefined4 local_a8 [9];
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_14;
  undefined4 local_10;
  
  puVar7 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  if (*param_1 == 0) {
    local_84 = 0;
    DAT_0088d73c = 8;
    thunk_FUN_00498826(&DAT_019c692c,0x40,&DAT_0088d73c,&DAT_00763d50,&DAT_00763d50);
    if (DAT_0088d73c < 0) {
      thunk_FUN_0042ac4e(&DAT_019c692c,0x40);
      local_10 = 0;
      puVar3 = &stack0xfffffffc;
    }
    else {
      local_14 = 0;
      DAT_02052740 = 8;
      FUN_004a830b();
      puVar5 = &DAT_00790b90;
      puVar6 = &DAT_019c68ac;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      FUN_004acee1(&DAT_019c68ac,0x80,&DAT_0078b4c0);
      param_2[4] = DAT_0078b4e8;
      param_3[4] = DAT_0078b470 * f_100;
      param_2[2] = DAT_0078b474;
      param_3[5] = _DAT_0078ded4 * _DAT_0078ded8;
      param_3[6] = DAT_0078b488;
      param_3[7] = DAT_0078b48c;
      *param_3 = DAT_0078b490;
      param_3[1] = DAT_0078b494;
      param_3[2] = DAT_0078b498;
      param_2[1] = DAT_0078b4a0;
      param_2[3] = DAT_0078b4a4;
      *param_2 = DAT_0078b478;
      param_2[0x12] = DAT_0078df00;
      param_2[0x13] = DAT_0088d724;
      param_2[0x14] = DAT_0078df04;
      DAT_0088d730 = DAT_01fbb6f8;
      if (DAT_01fbb6f8 < 0) {
        DAT_0088d730 = 0;
      }
      param_2[0x15] = DAT_0088d730;
      FUN_005f33c9(&stack0xfffffffc,0x4aae2d);
      FUN_005f34d1(puVar7,0x4aae48);
      DAT_0088d720 = PAPER + 10;
      if (DAT_0088d720 == 10) {
        DAT_0088d720 = 0x12;
      }
      *(undefined4 *)(puVar7 + -8) = 8;
      DAT_0088d730 = 0xb;
      do {
        *(undefined4 *)(DAT_0088d730 * 4 + *(int *)(puVar7 + 0xc) + -4) = 0;
        if (DAT_0088d720 == DAT_0088d730) {
          *(undefined4 *)(DAT_0088d730 * 4 + *(int *)(puVar7 + 0xc) + -4) = 1;
        }
        DAT_0088d730 = DAT_0088d730 + 1;
        *(int *)(puVar7 + -8) = *(int *)(puVar7 + -8) + -1;
      } while (0 < *(int *)(puVar7 + -8));
      FUN_005f33c9(puVar7,0x4aaeee);
      FUN_005f34d1(puVar7,0x4aaf09);
      puVar3 = puVar7;
    }
  }
  else {
    if (*param_1 == 2) {
      local_80 = 0;
      goto LAB_004abb37;
    }
    DAT_0088d73c = 8;
    thunk_FUN_00498826(&DAT_019c692c,0x40,&DAT_0088d73c,&DAT_00763d50,&DAT_00763d50);
    if (DAT_0088d73c < 0) {
      local_7c = 0;
    }
    else {
      DAT_02052740 = 8;
      local_b0 = param_2 + 2;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763f38,&local_b4,&DAT_00791a28);
      local_b0 = param_3 + 4;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791a44);
      local_a8[0] = 0;
      local_b4 = 4;
      local_b0 = param_2;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763f38,&local_b4,&DAT_00791a60);
      local_b0 = param_2 + 3;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763f38,&local_b4,&DAT_00791a7c);
      local_b0 = param_3 + 7;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791a98);
      IP1._0_2_ = (undefined2)DAT_009ae2bc;
      IP1._2_1_ = DAT_009ae2bc._2_1_;
      local_a8[0] = 0;
      local_b4 = 3;
      local_b0 = &IP1;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763d88,&local_b4,&DAT_00791ab4);
      local_b8 = s_INCHESMETRIC_0079218e + param_2[4] * 6;
      local_a8[0] = 0;
      local_bc = 6;
      local_b4 = 6;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c8c,&local_bc,&DAT_00791ad4);
      local_b0 = param_3 + 6;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791ae8);
      local_b0 = param_3 + 5;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791b08);
      local_b0 = param_2 + 1;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763f38,&local_b4,&DAT_00791b24);
      local_a8[0] = 0;
      local_b4 = 4;
      local_b0 = param_3;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791b44);
      local_b0 = param_3 + 1;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791b60);
      local_b0 = param_3 + 2;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791b7c);
      local_b0 = param_3 + 3;
      local_a8[0] = 0;
      local_b4 = 4;
      FUN_005fc330(local_a8,8,0x784ff00,&DAT_00763c9c,&local_b4,&DAT_00791b98);
      DAT_0078b4c0 = FUN_004a81c0(&DAT_019c68ac,0x80,&DAT_00763d64);
      DAT_0088d738 = DAT_0078b4c0 + 1;
      FUN_005f46bc(&stack0xfffffffc,0x4ab461);
      FUN_005f34d1(puVar2,0x4ab477);
      FUN_004abb46(&DAT_019c68ac,0x80,&DAT_0078b4c0,&DAT_00763d50);
      DAT_0078b4c4 = FUN_004a81c0(&DAT_019c682c,0x80,&DAT_00763d64);
      DAT_0088d738 = DAT_0078b4c4 + 1;
      FUN_005f46bc(puVar2,0x4ab507);
      FUN_005f34d1(puVar2,0x4ab51d);
      FUN_004abb46(&DAT_019c682c,0x80,&DAT_0078b4c4,&DAT_00763c94);
      iVar1 = FUN_00601a30(0x20);
      if (iVar1 != 0) {
        FUN_005f33c9(puVar2,0x4ab585);
        FUN_005f34d1(puVar2,0x4ab5a0);
      }
      puVar3 = puVar2;
      FUN_005f33c9(puVar2,0x4ab5c2);
      DAT_0088d734 = FUN_005ff950(puVar3 + -0x138,0x80);
      FUN_004abb46(&DAT_009af53c,0x80,&DAT_0088d734,&DAT_00763f20);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined **)(puVar3 + -0xb0) = &DAT_0078dc80;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f1c,puVar3 + -0xb0,&DAT_00791bb4);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 4;
      *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + 0xc) + 0x48;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f38,puVar3 + -0xb0,&DAT_00791bd4);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 4;
      *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + 0xc) + 0x4c;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f38,puVar3 + -0xb0,&DAT_00791bf4);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 4;
      *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + 0xc) + 0x50;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f38,puVar3 + -0xb0,&DAT_00791c14);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 4;
      *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + 0xc) + 0x54;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f38,puVar3 + -0xb0,&DAT_00791c34);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 4;
      *(int *)(puVar3 + -0xac) = *(int *)(puVar3 + 0xc) + 0x58;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f38,puVar3 + -0xb0,&DAT_00791c54);
      *(undefined4 *)(puVar3 + -0x24) = 8;
      DAT_0088d734 = 0xb;
      do {
        if (*(int *)(*(int *)(puVar3 + 0xc) + -4 + DAT_0088d734 * 4) != 0) {
          DAT_0088d730 = DAT_0088d734 + -10;
        }
        DAT_0088d734 = DAT_0088d734 + 1;
        *(int *)(puVar3 + -0x24) = *(int *)(puVar3 + -0x24) + -1;
      } while (0 < *(int *)(puVar3 + -0x24));
      if (DAT_0088d730 == 8) {
        DAT_0088d730 = 0;
      }
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(int **)(puVar3 + -0xb0) = &DAT_0088d730;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f18,puVar3 + -0xb0,&DAT_00791c74);
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(undefined4 *)(puVar3 + -0xb0) = 1;
      *(undefined1 **)(puVar3 + -0xac) = &DAT_019c6828;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763d88,puVar3 + -0xb0,&DAT_00791c94);
      iVar1 = DAT_0078dc84 % 10000;
      DAT_0088d734 = iVar1 / 1000;
      DAT_0088d72c = (iVar1 % 1000) / 100;
      DAT_0088d728 = (iVar1 % 100) / 10;
      **(int **)(puVar3 + 8) = iVar1 % 10;
      DAT_0088d730 = **(int **)(puVar3 + 8) * 8 +
                     DAT_0088d72c * 30000 + DAT_0088d734 * 2000000 + DAT_0088d728 * 500;
      *(undefined4 *)(puVar3 + -0xa4) = 0;
      *(int **)(puVar3 + -0xb0) = &DAT_0088d730;
      FUN_005fc330(puVar3 + -0xa4,8,0x784ff00,&DAT_00763f18,puVar3 + -0xb0,&DAT_00791cb4);
      *(undefined4 *)(puVar3 + -0x14) = 0;
    }
  }
  *(undefined4 *)(puVar3 + -0xa4) = 0;
  FUN_005f7950(puVar3 + -0xa4,DAT_02052740,0x784ff00,&DAT_00763c88,0);
  FUN_005f46bc(puVar3,0x4aba0a);
  FUN_005f34d1(puVar3,0x4aba20);
  FUN_005f46bc(puVar3,0x4aba5a);
  FUN_005f34d1(puVar3,0x4aba70);
  FUN_005f46bc(puVar3,0x4abaae);
  FUN_005f34d1(puVar3,0x4abac4);
  FUN_005f46bc(puVar3,0x4abb02);
  puVar4 = puVar3;
  FUN_005f34d1(puVar3,0x4abb18);
  puVar5 = &DAT_019c68ac;
  puVar6 = &DAT_0078b420;
  for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_02052740 = 0;
LAB_004abb37:
  return (float10)*(float *)(puVar4 + -0x84);
}


