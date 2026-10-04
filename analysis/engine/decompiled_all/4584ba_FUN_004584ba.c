// FUN_004584ba @ 004584ba (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004584ba(void)

{
  int iVar1;
  float10 in_ST0;
  
  DAT_007fecf0 = 1;
  DAT_01c00600 = DAT_01c0c260;
  for (iVar1 = DAT_01c0c260; 0 < iVar1; iVar1 = iVar1 + -1) {
    *(int *)(DAT_007fecf0 * 0xc + 0x1c005f8) =
         (int)ROUND((float)_DAT_01c005c0 +
                    (float)*(int *)(&DAT_01c0c258 + DAT_007fecf0 * 0xc) * _DAT_01c005c8);
    in_ST0 = (float10)_DAT_01c005c4;
    *(int *)(DAT_007fecf0 * 0xc + 0x1c005fc) =
         (int)ROUND(in_ST0 - (float10)*(int *)(&DAT_01c0c25c + DAT_007fecf0 * 0xc) *
                             (float10)_DAT_01c005cc);
    (&DAT_01c00600)[DAT_007fecf0 * 3] = (&DAT_01c0c260)[DAT_007fecf0 * 3];
    DAT_007fecf0 = DAT_007fecf0 + 1;
  }
  ffree(in_ST0);
  return;
}


