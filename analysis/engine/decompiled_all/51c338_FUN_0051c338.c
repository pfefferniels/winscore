// FUN_0051c338 @ 0051c338 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0051c338(void)

{
  int iVar1;
  
  DAT_01be6c60 = 1;
  DAT_01fb8c74 = 0;
  thunk_FUN_00534c40(&DAT_01be6c60,&DAT_01fb8c64,&DAT_01fb8c74,&DAT_01f998e0,&DAT_01f99c00,
                     &DAT_01f9a6f0);
  if (DAT_01fb8c74 != 0) {
    if ((float)(&DAT_01f99bfc)[DAT_01fb8c74] != f_m14) {
      DAT_01fb8c74 = DAT_01fb8c74 + 1;
      (&DAT_01f99bfc)[DAT_01fb8c74] = f_m14;
      (&DAT_01f998dc)[DAT_01fb8c74] = DAT_01fbb8b8;
    }
    DAT_01be6c6c = (float)(&DAT_01f998dc)[DAT_01fb8c74];
    iVar1 = DAT_01fb8c74;
    for (DAT_01be6c64 = 1; (0 < iVar1 && ((float)(&DAT_01f99bfc)[DAT_01be6c64] <= f_0));
        DAT_01be6c64 = DAT_01be6c64 + 1) {
      iVar1 = iVar1 + -1;
    }
    DAT_01be6c78 = (float)(&DAT_01f998dc)[DAT_01be6c64];
    DAT_01be6c70 = DAT_01be6c6c - DAT_01be6c78;
    DAT_01be6c74 = (float)(&DAT_01f99bfc)[DAT_01be6c64];
    (&DAT_01f99bfc)[DAT_01be6c64] = DAT_01be6c78;
    DAT_01be6c80 = DAT_01be6c70 / _DAT_01f9a6f0;
    DAT_01be6c68 = DAT_01be6c64 + 1;
    _DAT_0094e398 = DAT_01be6c78;
    _DAT_0094e394 = DAT_01be6c6c;
    for (iVar1 = (DAT_01fb8c74 - DAT_01be6c68) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_01be6c7c = (float)(&DAT_01f99bfc)[DAT_01be6c68];
      if (f_0 <= DAT_01be6c7c) {
        DAT_01be6c78 = DAT_01be6c80 * DAT_01be6c74 + DAT_01be6c78;
        DAT_01be6c74 = DAT_01be6c7c;
        (&DAT_01f99bfc)[DAT_01be6c68] = DAT_01be6c78;
      }
      DAT_01be6c68 = DAT_01be6c68 + 1;
    }
    DAT_01fb8c74 = DAT_01fb8c74 + 1;
    (&DAT_01f998dc)[DAT_01fb8c74] = DAT_01be6c6c;
    (&DAT_01f99bfc)[DAT_01fb8c74] = DAT_01be6c6c;
    DAT_01e67910 = DAT_01f998e0;
    DAT_01e67914 = DAT_01be6c6c;
  }
  return;
}


