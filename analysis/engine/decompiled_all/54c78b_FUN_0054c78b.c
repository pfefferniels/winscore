// FUN_0054c78b @ 0054c78b (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0054c78b(int *param_1)

{
  int iVar1;
  
  iVar1 = 0x200;
  *param_1 = 0x200;
  do {
    if (' ' < (char)(&DAT_020b8e9f)[*param_1]) break;
    *param_1 = *param_1 + -1;
    iVar1 = iVar1 + -1;
  } while (0 < iVar1);
  iVar1 = *param_1;
  DAT_009a238c = 1;
  for (; 0 < iVar1; iVar1 = iVar1 + -1) {
    FUN_0054c768(&DAT_020b8e9f + DAT_009a238c);
    DAT_009a238c = DAT_009a238c + 1;
  }
  DAT_0078b4e0 = (uint)(byte)DAT_020b8ea0;
  DAT_0078b4e4 = (uint)DAT_020b8ea0._1_1_;
  return;
}


