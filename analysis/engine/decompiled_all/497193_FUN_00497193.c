// FUN_00497193 @ 00497193 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00497248) */
/* WARNING: Removing unreachable block (ram,0x004971c4) */
/* WARNING: Removing unreachable block (ram,0x004972b0) */

void FUN_00497193(void)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  int local_18;
  
  puVar3 = &stack0xfffffffc;
  puVar4 = &stack0xfffffffc;
  local_18 = 0x7f;
  DAT_00791460 = 0x80;
  do {
    iVar1 = FUN_00601a30(0x20);
    if (iVar1 == 0) break;
    DAT_00791460 = DAT_00791460 + -1;
    local_18 = local_18 + -1;
  } while (0 < local_18);
  DAT_0082a598 = 1;
  iVar1 = DAT_00791460;
  while( true ) {
    if (iVar1 < 1) {
      FUN_005f34d1(&stack0xfffffffc,0x497306);
      *(undefined4 *)(puVar4 + -4) = 0;
      return;
    }
    iVar2 = FUN_005f4660(0x20);
    if (iVar2 != 0) break;
    DAT_0082a598 = DAT_0082a598 + 1;
    iVar1 = iVar1 + -1;
  }
  FUN_005f46bc(&stack0xfffffffc,0x4972d0);
  FUN_005f34d1(puVar3,0x4972e6);
  return;
}


