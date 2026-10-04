// FUN_00571b78 @ 00571b78 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00571cc2) */
/* WARNING: Removing unreachable block (ram,0x00571bd2) */
/* WARNING: Removing unreachable block (ram,0x00571c71) */
/* WARNING: Removing unreachable block (ram,0x00571d13) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00571b78(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined1 *puVar3;
  int local_1c;
  
  puVar3 = &stack0xfffffffc;
  puVar2 = (undefined4 *)&DAT_009a83f8;
  for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  _DAT_009a83f0 = 0;
  local_1c = 0x7f;
  DAT_009a83ec = 2;
  while( true ) {
    if (*(char *)(DAT_009a83ec + 0x9a83f7) == '\0') {
      for (; *(char *)(DAT_009a83ec + 0x9a83f6) < '!'; DAT_009a83ec = DAT_009a83ec + -1) {
      }
      FUN_005f46bc(&stack0xfffffffc,0x571c92);
      FUN_005f34d1(puVar3,0x571ca8);
      FUN_005f46bc(puVar3,0x571ce0);
      FUN_005f34d1(puVar3,0x571cf6);
      FUN_005f46bc(puVar3,0x571d34);
      FUN_005f34d1(puVar3,0x571d4a);
      return;
    }
    iVar1 = FUN_005f4660(0x20);
    if (iVar1 != 0) break;
    DAT_009a83ec = DAT_009a83ec + 1;
    local_1c = local_1c + -1;
    if (local_1c < 1) {
      return;
    }
  }
  return;
}


