// FUN_0056f33e @ 0056f33e (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0056f33e(float *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 local_74;
  undefined *local_70;
  undefined4 local_6c;
  undefined4 local_60 [8];
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  
  puVar3 = &stack0xfffffffc;
  DAT_01cadcfc = 0;
  DAT_01a9f308 = STEP * P6;
  DAT_01a9f30c = STEP * P7;
  if (DAT_0078d854 == 0) {
    local_40 = 0;
    if ((_DAT_009a82d0 == DAT_01a9f30c) && (DAT_01a9f308 == *param_1)) {
      DAT_01cadcfc = 0;
      return;
    }
  }
  else {
    DAT_0078d854 = 0;
    local_3c = 0;
  }
  *param_1 = DAT_01a9f308 * f_110_206;
  _DAT_009a82d0 = DAT_01a9f30c * f_110_206;
  if (DAT_01aae360 == 0) {
    local_34 = 0;
  }
  else {
    if (DAT_01aae364 == 0) {
      local_30 = 0;
    }
    else {
      DAT_01a9f304 = 1;
      for (local_2c = DAT_01aae364; 0 < local_2c; local_2c = local_2c + -1) {
        if (DAT_01a9f300 == (&DAT_01aae364)[DAT_01a9f304]) {
          local_28 = 0;
          goto LAB_0056f4fa;
        }
        DAT_01a9f304 = DAT_01a9f304 + 1;
      }
    }
    if (DAT_01aae364 < 0x30) {
      DAT_01aae364 = DAT_01aae364 + 1;
    }
    register0x0000001c = ram0x01aae446 + 1;
    (&DAT_01aae364)[DAT_01aae364] = DAT_01a9f300;
    local_70 = &DAT_01cac242 + DAT_00791440 * 0x1e;
    local_60[0] = 0;
    local_74 = 0x1e;
    local_6c = 0x1e;
    local_24 = FUN_005fc330(local_60,0x1a,0x784ff01,&DAT_0076a3d0,&local_74,&DAT_0079fed8);
  }
LAB_0056f4fa:
  FUN_005f33c9(&stack0xfffffffc,0x56f51f);
  *(undefined4 *)(puVar3 + -0x1c) = 0;
  if (OUTPUT_MODE == -1) {
    *(undefined4 *)(puVar3 + -0x5c) = 0;
    *(undefined4 *)(puVar3 + -0x68) = 0x1e;
    *(undefined **)(puVar3 + -100) = &DAT_01caf830;
    iVar1 = FUN_005fc330(puVar3 + -0x5c,0x18,0x784ff01,&DAT_0076a3f4,puVar3 + -0x68,&DAT_0079fe84);
    *(int *)(puVar3 + -8) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(puVar3 + -0x68) = *(undefined4 *)(puVar3 + 8);
      iVar1 = FUN_005fc980(puVar3 + -0x5c,&DAT_0076a358,puVar3 + -0x68);
      *(int *)(puVar3 + -8) = iVar1;
      if (iVar1 == 0) {
        *(undefined **)(puVar3 + -0x68) = &DAT_009a82d0;
        uVar2 = FUN_005fc980(puVar3 + -0x5c,&DAT_0076a3f0,puVar3 + -0x68);
        *(undefined4 *)(puVar3 + -8) = uVar2;
      }
    }
  }
  else {
    *(undefined4 *)(puVar3 + -0xc) = 0;
  }
  **(float **)(puVar3 + 8) = DAT_01a9f308;
  _DAT_009a82d0 = DAT_01a9f30c;
  *(undefined4 *)(puVar3 + -4) = 0;
  return;
}


