// FUN_00495d4f @ 00495d4f (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING (jumptable): Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00496259) */
/* WARNING: Removing unreachable block (ram,0x00496193) */
/* WARNING: Removing unreachable block (ram,0x004960cd) */
/* WARNING: Removing unreachable block (ram,0x0049631c) */
/* WARNING: Removing unreachable block (ram,0x00495f48) */
/* WARNING: Removing unreachable block (ram,0x00495e73) */
/* WARNING: Removing unreachable block (ram,0x00495eca) */
/* WARNING: Removing unreachable block (ram,0x00495f9f) */
/* WARNING: Removing unreachable block (ram,0x0049606a) */
/* WARNING: Removing unreachable block (ram,0x00496130) */
/* WARNING: Removing unreachable block (ram,0x004961f6) */
/* WARNING: Removing unreachable block (ram,0x004962bc) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00495d4f(undefined4 *param_1)

{
  undefined *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined1 *puVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  puVar4 = &stack0xfffffffc;
  _DAT_0082a314 = FUN_00601b80(&DAT_020b8ea0,0x200);
  puVar5 = &DAT_0082a318;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *param_1;
    param_1 = param_1 + 1;
    puVar5 = puVar5 + 1;
  }
  DAT_0082a310 = 0;
  FUN_005f34d1(&stack0xfffffffc,0x495da4);
  *(undefined4 *)(puVar4 + -0x44) = 0x7f;
  DAT_0082a30c = 0x7f;
  do {
    if (' ' < *(char *)(DAT_0082a30c + 0x82a317)) {
      DAT_0082a310 = DAT_0082a30c;
      *(undefined1 *)((int)&DAT_0082a318 + DAT_0082a30c) = 0;
      *(undefined4 *)(puVar4 + -0x3c) = 0;
      break;
    }
    *(undefined4 *)(puVar4 + -0x40) = 0;
    *(undefined4 *)(puVar4 + -0x38) = 0;
    DAT_0082a30c = DAT_0082a30c + -1;
    *(int *)(puVar4 + -0x44) = *(int *)(puVar4 + -0x44) + -1;
  } while (0 < *(int *)(puVar4 + -0x44));
  puVar5 = &DAT_0082a318;
  puVar6 = (undefined4 *)&DAT_020b90a0;
  for (iVar3 = 0x20; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  if (ITEM_I == 0) {
    DAT_0082a310 = 1;
    DAT_020b90a0 = 0;
    *(undefined4 *)(puVar4 + -0x30) = 0;
  }
  else {
    *(undefined4 *)(puVar4 + -0x34) = 0;
    (&DAT_020b90a0)[DAT_0082a310] = 0x20;
    if (DAT_0078b4f0 == 0) {
      FUN_005f46bc(puVar4,0x495e97);
      FUN_005f34d1(puVar4,0x495ead);
      puVar1 = &DAT_020b90ac + DAT_0082a310;
      *(undefined4 *)(puVar4 + -100) = 0;
      *(undefined4 *)(puVar4 + -0x78) = 4;
      *(undefined **)(puVar4 + -0x74) = puVar1;
      *(int **)(puVar4 + -0x70) = &ITEM_I;
      FUN_005f34f0(puVar4 + -100,0x784ff00,&DAT_00763170,puVar4 + -0x78,&DAT_007916a0);
      iVar3 = DAT_0082a310 + 2;
      DAT_0082a310 = DAT_0082a310 + 0x1a;
      *(undefined1 *)((int)&DAT_020b90b7 + iVar3) = 0;
    }
    else {
      FUN_005f46bc(puVar4,0x495f6c);
      FUN_005f34d1(puVar4,0x495f82);
      puVar1 = &DAT_020b90b0 + DAT_0082a310;
      *(undefined4 *)(puVar4 + -100) = 0;
      *(undefined4 *)(puVar4 + -0x78) = 4;
      *(undefined **)(puVar4 + -0x74) = puVar1;
      *(int **)(puVar4 + -0x70) = &ITEM_I;
      FUN_005f34f0(puVar4 + -100,0x784ff00,&DAT_00763170,puVar4 + -0x78,&DAT_007916b4);
      puVar2 = &DAT_020b90bd + DAT_0082a310;
      DAT_0082a310 = DAT_0082a310 + 0x1e;
      *puVar2 = 0;
    }
  }
  if (PAPER == 0) {
    *(undefined4 *)(puVar4 + -0x24) = 0;
  }
  else {
    switch(PAPER) {
    default:
      FUN_005f46bc(puVar4,0x496340);
      FUN_005f34d1(puVar4,0x496356);
      *(undefined4 *)(puVar4 + -0x20) = 0;
      break;
    case 2:
      FUN_005f46bc(puVar4,&LAB_0049608e);
      FUN_005f34d1(puVar4,&LAB_004960a4);
      *(undefined4 *)(puVar4 + -0x1c) = 0;
      break;
    case 3:
      FUN_005f46bc(puVar4,&LAB_004960f1);
      FUN_005f34d1(puVar4,&LAB_00496107);
      *(undefined4 *)(puVar4 + -0x18) = 0;
      break;
    case 4:
      FUN_005f46bc(puVar4,&LAB_00496154);
      FUN_005f34d1(puVar4,&LAB_0049616a);
      *(undefined4 *)(puVar4 + -0x14) = 0;
      break;
    case 5:
      FUN_005f46bc(puVar4,&LAB_004961b7);
      FUN_005f34d1(puVar4,&LAB_004961cd);
      *(undefined4 *)(puVar4 + -0x10) = 0;
      break;
    case 6:
      FUN_005f46bc(puVar4,&LAB_0049621a);
      FUN_005f34d1(puVar4,&LAB_00496230);
      *(undefined4 *)(puVar4 + -0xc) = 0;
      break;
    case 7:
      FUN_005f46bc(puVar4,&LAB_0049627d);
      FUN_005f34d1(puVar4,&LAB_00496293);
      *(undefined4 *)(puVar4 + -8) = 0;
      break;
    case 8:
      FUN_005f46bc(puVar4,&LAB_004962e0);
      FUN_005f34d1(puVar4,&LAB_004962f6);
      *(undefined4 *)(puVar4 + -4) = 0;
    }
  }
  thunk_FUN_00579770(&DAT_007630fc,1,&DAT_020b90a0);
  return;
}


