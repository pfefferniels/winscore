// FUN_004d09d8 @ 004d09d8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004d0afa) */
/* WARNING: Removing unreachable block (ram,0x004d0b5d) */

undefined4 FUN_004d09d8(short *param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  short *psVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int local_1c;
  
  puVar7 = &stack0xfffffffc;
  puVar2 = &stack0xfffffffc;
  puVar3 = &stack0xfffffffc;
  psVar4 = param_1;
  puVar5 = &DAT_0089feb8;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar5 = *(undefined4 *)psVar4;
    psVar4 = psVar4 + 2;
    puVar5 = puVar5 + 1;
  }
  if (*param_1 != 0x5c5c) {
    DAT_0089feb4 = 0;
    local_1c = 0x80;
    DAT_0089feb0 = 1;
    do {
      if (*(char *)((int)&DAT_0089feb4 + DAT_0089feb0 + 3) == '.') {
        DAT_0089feb4 = DAT_0089feb0;
      }
      if (*(char *)((int)&DAT_0089feb4 + DAT_0089feb0 + 3) == '\0') goto LAB_004d0a91;
      DAT_0089feb0 = DAT_0089feb0 + 1;
      local_1c = local_1c + -1;
    } while (0 < local_1c);
    DAT_0089feb0 = 0x80;
LAB_004d0a91:
    puVar3 = &stack0xfffffffc;
    if (*(char *)((int)&DAT_0089feb8 + DAT_0089feb4) < '!') {
      DAT_0089feac = DAT_0089feb0 + -1;
      if (-DAT_0089feac / -1 < 1) {
        thunk_FUN_0054d831("Output must be to .EPS file.",0x1d);
        puVar3 = &stack0xfffffffc;
      }
      else {
        if (*(char *)((int)&DAT_0089feb4 + DAT_0089feb0 + 2) == '.') {
          FUN_005f46bc(&stack0xfffffffc,0x4d0b1e);
          puVar2 = puVar7;
          FUN_005f34d1(puVar7,0x4d0b34);
          *(undefined1 *)((int)&DAT_0089feb8 + DAT_0089feac + 3) = 0;
        }
        else {
          FUN_005f46bc(&stack0xfffffffc,0x4d0b81);
          FUN_005f34d1(puVar2,0x4d0b97);
          *(undefined1 *)((int)&DAT_0089febc + DAT_0089feac) = 0;
        }
        puVar5 = &DAT_0089feb8;
        puVar6 = *(undefined4 **)(puVar2 + 8);
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        puVar5 = *(undefined4 **)(puVar2 + 8);
        puVar6 = &DAT_01a14984;
        for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
          *puVar6 = *puVar5;
          puVar5 = puVar5 + 1;
          puVar6 = puVar6 + 1;
        }
        *(undefined4 *)(puVar2 + -8) = 0;
        puVar3 = puVar2;
      }
    }
  }
  return *(undefined4 *)(puVar3 + -0x20);
}


