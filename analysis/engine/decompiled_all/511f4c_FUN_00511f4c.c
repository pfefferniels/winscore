// FUN_00511f4c @ 00511f4c (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00511fbd) */

void FUN_00511f4c(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  
  puVar3 = &stack0xfffffffc;
  puVar2 = &DAT_00941f70;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  iVar1 = 0x80;
  DAT_00941f68 = 0x80;
  do {
    if (' ' < *(char *)(DAT_00941f68 + 0x941f6f)) {
      FUN_005f46bc(&stack0xfffffffc,0x511fde);
      FUN_005f34d1(puVar3,0x511ff4);
      return;
    }
    DAT_00941f68 = DAT_00941f68 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


