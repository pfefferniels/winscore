// FUN_00508ad8 @ 00508ad8 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00508ad8(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  thunk_FUN_0054c419(&DAT_009403d0,&DAT_00766fb0);
  if (*param_1 < 0) {
    DAT_009403c8 = 6;
    iVar2 = -*param_1;
    DAT_009403c4 = 1;
    if (*param_1 != 0 && -1 < iVar2) {
      do {
        (&DAT_009403d0)[DAT_009403c8] = 1;
        iVar1 = DAT_009403c8 + -4;
        if (DAT_009403c8 + -4 < 0) {
          iVar1 = DAT_009403c8 + 3;
        }
        DAT_009403c8 = iVar1;
        DAT_009403c4 = DAT_009403c4 + 1;
        iVar2 = iVar2 + -1;
      } while (0 < iVar2);
    }
  }
  else {
    DAT_009403c8 = 3;
    iVar2 = *param_1;
    DAT_009403c4 = 1;
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      (&DAT_009403d0)[DAT_009403c8] = 2;
      iVar1 = DAT_009403c8 + 4;
      if (6 < DAT_009403c8 + 4) {
        iVar1 = DAT_009403c8 + -3;
      }
      DAT_009403c8 = iVar1;
      DAT_009403c4 = DAT_009403c4 + 1;
    }
  }
  DAT_009403c0 = *param_2;
  for (iVar2 = (*param_3 - DAT_009403c0) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    if ((*(char *)((int)&DAT_01b34588 + DAT_009403c0 + 3) == '\x01') &&
       ((&DAT_01b42feb)[DAT_009403c0] == '\0')) {
      (&DAT_01b42feb)[DAT_009403c0] =
           *(undefined1 *)(&DAT_009403d0 + *(char *)((int)&DAT_01b408d8 + DAT_009403c0 + 3) % '\a');
    }
    DAT_009403c0 = DAT_009403c0 + 1;
  }
  return;
}


