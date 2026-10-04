// FUN_0054e3b1 @ 0054e3b1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x0054e48b) */
/* WARNING: Removing unreachable block (ram,0x0054e42a) */
/* WARNING: Removing unreachable block (ram,0x0054e4e3) */

void FUN_0054e3b1(void)

{
  int iVar1;
  undefined1 *puVar2;
  int local_8;
  
  puVar2 = &stack0xfffffffc;
  local_8 = 0x20;
  DAT_009a2ad8 = 0x31;
  do {
    *(undefined1 *)(DAT_009a2ad8 * 3 + 0x1a1af3f) = 0x20;
    DAT_009a2ad8 = DAT_009a2ad8 + 1;
    local_8 = local_8 + -1;
  } while (0 < local_8);
  iVar1 = 0x30;
  DAT_009a2ad8 = 1;
  do {
    FUN_005f46bc(puVar2,0x54e449);
    FUN_005f34d1(puVar2,0x54e45f);
    FUN_0054c768(&DAT_009a2ad0);
    FUN_005f46bc(puVar2,0x54e4ac);
    FUN_005f34d1(puVar2,0x54e4c2);
    FUN_005f46bc(puVar2,0x54e504);
    FUN_005f34d1(puVar2,0x54e51a);
    DAT_009a2ad8 = DAT_009a2ad8 + 1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  return;
}


