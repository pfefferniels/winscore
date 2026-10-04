// FUN_004f9e92 @ 004f9e92 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x004f9f7b) */
/* WARNING: Removing unreachable block (ram,0x004f9ec5) */
/* WARNING: Removing unreachable block (ram,0x004f9fef) */

void FUN_004f9e92(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  puVar2 = &stack0xfffffffc;
  DAT_009011ec = 1;
  while( true ) {
    FUN_005f46bc(puVar2,0x4f9ee8);
    FUN_005f34d1(puVar2,0x4f9efe);
    if (DAT_009011f0 == '.') {
      *(undefined4 *)(puVar2 + -0xc) = 0;
      return;
    }
    if (DAT_009011f0 == ' ') break;
    DAT_009011ec = DAT_009011ec + 1;
    *(int *)(puVar2 + -0x10) = *(int *)(puVar2 + -0x10) + -1;
    if (*(int *)(puVar2 + -0x10) < 1) {
      FUN_005f33c9(puVar2,0x4fa047);
      FUN_005f34d1(puVar2,0x4fa062);
      *(undefined4 *)(puVar2 + -4) = 0;
      return;
    }
  }
  *(undefined4 *)(puVar2 + -8) = 0;
  *(int *)(puVar2 + -0x34) = DAT_009011ec + -1;
  iVar1 = (DAT_009011ec - *(int *)(puVar2 + -0x34)) + 0x7c;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(puVar2 + -0x38) = iVar1;
  FUN_005f46bc(puVar2,0x4f9fbc);
  FUN_005f34d1(puVar2,0x4f9fd2);
  FUN_005f46bc(puVar2,0x4fa010);
  FUN_005f34d1(puVar2,0x4fa026);
  return;
}


