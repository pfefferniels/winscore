// FUN_0056edfd @ 0056edfd (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0056eeff) */

void FUN_0056edfd(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_d4 [44];
  undefined4 local_24;
  int local_18;
  
  puVar3 = &stack0xfffffffc;
  DAT_009a8238 = DAT_0078b6a0 % 100;
  if (DAT_00791448 == 0) {
    DAT_00791448 = 1;
    puVar4 = &DAT_019c682c;
    puVar5 = local_d4;
    for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    DAT_009a8234 = FUN_005ff950(local_d4,0x80);
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) {
      DAT_009a8234 = DAT_009a8234 + -1;
    }
    FUN_005f34d1(&stack0xfffffffc,0x56ef54);
    FUN_005f46bc(puVar3,0x56ef89);
    FUN_005f46bc(puVar3,0x56efa5);
    FUN_005f34d1(puVar3,0x56efbb);
    thunk_FUN_0050bea3();
    *(undefined4 *)(puVar3 + -0x1c) = 4;
    DAT_009a8234 = 2;
    do {
      (&DAT_009a8238)[DAT_009a8234] = 0xffffffff;
      DAT_009a8234 = DAT_009a8234 + 1;
      *(int *)(puVar3 + -0x1c) = *(int *)(puVar3 + -0x1c) + -1;
    } while (0 < *(int *)(puVar3 + -0x1c));
    *(undefined4 *)(puVar3 + -0x18) = 0;
  }
  else {
    local_24 = 0;
    local_18 = 5;
    DAT_009a8234 = 1;
    do {
      if (DAT_009a8238 == (&DAT_009a8238)[DAT_009a8234]) {
        return;
      }
      DAT_009a8234 = DAT_009a8234 + 1;
      local_18 = local_18 + -1;
    } while (0 < local_18);
    DAT_00791448 = DAT_00791448 + 1;
    puVar3 = &stack0xfffffffc;
    if (5 < DAT_00791448) {
      DAT_00791448 = 1;
      puVar3 = &stack0xfffffffc;
    }
  }
  (&DAT_009a8238)[DAT_00791448] = DAT_009a8238;
  if (((DAT_009a8238 < 0x5a) && (DAT_009a8238 != 0x21)) && (DAT_009a8238 != 0x22)) {
    DAT_009a8234 = 1;
    if (DAT_0078b6a0 < 100) {
      *(undefined4 *)(puVar3 + -0x40) = 0;
      *(undefined4 *)(puVar3 + -0x50) = 0x1e;
      *(undefined **)(puVar3 + -0x4c) = &DAT_01cac260;
      *(undefined4 *)(puVar3 + -0x48) = 0x1e;
      iVar1 = FUN_005fc330(puVar3 + -0x40,0x18,0x784ff01,&DAT_0076a390,puVar3 + -0x50,&DAT_0079fd2c)
      ;
      *(int *)(puVar3 + -8) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(puVar3 + -0x50) = 0x1e;
        *(undefined **)(puVar3 + -0x4c) = &DAT_01cac242 + DAT_009a8234 * 0x1e;
        *(undefined4 *)(puVar3 + -0x48) = 0x1e;
        uVar2 = FUN_005fc980(puVar3 + -0x40,&DAT_0076a3d0,puVar3 + -0x50);
        *(undefined4 *)(puVar3 + -8) = uVar2;
      }
      if (*(int *)(puVar3 + -8) != 0) {
        thunk_FUN_004cf1c2();
        return;
      }
    }
    DAT_00791444 = 0xffffffff;
    DAT_009a8234 = DAT_01cadcfc;
    if (DAT_0078b6a0 < 100) {
      thunk_FUN_0056b845();
    }
    DAT_01cadcfc = DAT_009a8234;
    *(undefined4 *)(puVar3 + -4) = 0;
  }
  else {
    *(undefined4 *)(puVar3 + -0xc) = 0;
  }
  return;
}


