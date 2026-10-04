// FUN_0049731a @ 0049731a (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Unable to track spacebase fully for stack */

void FUN_0049731a(undefined4 param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 *puVar4;
  int iVar5;
  int local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  int local_38;
  int local_34;
  undefined4 local_30 [10];
  int local_8;
  
  local_8 = param_2;
  *param_3 = 0xffffffff;
  local_30[0] = 0;
  local_44 = param_2;
  local_40 = param_1;
  local_3c = &DAT_0082a5a0;
  FUN_005f47c0(local_30,0xffffffff,0x784ff00,&DAT_007630e8,&local_44);
  if ((DAT_0082a5a0 & 1) != 0) {
    local_34 = local_8;
    puVar4 = &stack0xffffffac;
    for (uVar2 = local_8 + 7U & 0xfffffff8; 0x1000 < (int)uVar2; uVar2 = uVar2 - 0x1000) {
      puVar4 = puVar4 + -0x1000;
    }
    iVar5 = (int)puVar4 - uVar2;
    *(undefined4 *)(iVar5 + -4) = 0x4973df;
    *(undefined1 **)(iVar5 + -8) = &stack0xfffffffc;
    *(undefined4 *)(iVar5 + -0xc) = 0x4973df;
    local_38 = iVar5;
    FUN_005f33c9();
    iVar1 = *(int *)(iVar5 + -8);
    *(undefined4 *)(iVar1 + -0x30) = *(undefined4 *)(iVar1 + -0x30);
    for (uVar2 = *(int *)(iVar1 + -0x30) + 7U & 0xfffffff8; 0x1000 < (int)uVar2;
        uVar2 = uVar2 - 0x1000) {
      iVar5 = iVar5 + -0x1000;
    }
    iVar5 = iVar5 - uVar2;
    *(int *)(iVar1 + -0x38) = iVar5;
    *(undefined4 *)(iVar5 + -4) = 0x497436;
    *(int *)(iVar5 + -8) = iVar1;
    *(undefined4 *)(iVar5 + -0xc) = 0x497436;
    FUN_005f46bc();
    *(undefined4 *)(iVar5 + -4) = 0x49744c;
    *(undefined4 *)(iVar5 + -8) = *(undefined4 *)(iVar5 + -8);
    *(undefined4 *)(iVar5 + -0xc) = 0x49744c;
    FUN_005f34d1();
    iVar1 = *(int *)(iVar5 + -8);
    *(undefined4 *)(iVar5 + -4) = *(undefined4 *)(iVar1 + -0x30);
    *(undefined4 *)(iVar5 + -8) = *(undefined4 *)(iVar1 + -0x38);
    *(undefined4 *)(iVar5 + -0xc) = 0x49745d;
    DAT_0082a59c = FUN_005ff950();
    *(undefined4 *)(iVar1 + -0x54) = 0x49748e;
    *(int *)(iVar1 + -0x58) = iVar1;
    *(undefined4 *)(iVar1 + -0x5c) = 0x49748e;
    FUN_005f46bc();
    *(undefined4 *)(iVar1 + -0x54) = 0x4974a4;
    *(undefined4 *)(iVar1 + -0x58) = *(undefined4 *)(iVar1 + -0x58);
    *(undefined4 *)(iVar1 + -0x5c) = 0x4974a4;
    FUN_005f34d1();
    iVar5 = *(int *)(iVar1 + -0x58);
    (&DAT_020b90a0)[DAT_0082a59c] = 0;
    *(undefined **)(iVar1 + -0x58) = &DAT_0076320c;
    *(undefined4 *)(iVar1 + -0x5c) = 0x4974c4;
    uVar3 = thunk_FUN_00579410();
    **(undefined4 **)(iVar5 + 0x10) = uVar3;
  }
  return;
}


