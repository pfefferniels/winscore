// FUN_004ff7ed @ 004ff7ed (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004ff7ed(undefined4 param_1,int *param_2,int *param_3,int *param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  
  DAT_0090247c = 0;
  iVar2 = *param_3;
  for (iVar1 = (*param_4 - iVar2) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_0090247c = DAT_0090247c + *(int *)(param_5 + -4 + iVar2 * 4);
    iVar2 = iVar2 + 1;
  }
  DAT_00902474 = DAT_0090247c / *param_2;
  _DAT_00902468 = 0;
  DAT_0090246c = 0;
  DAT_00902464 = *param_3;
  DAT_00902460 = 0;
LAB_004ff8a4:
  DAT_00902470 = 0;
  DAT_0090245c = DAT_00902464;
  DAT_00902458 = 0;
  while (DAT_0090246c < *param_2 + -1) {
    DAT_00902470 = DAT_00902470 + *(int *)(param_5 + -4 + DAT_00902464 * 4);
    if (DAT_00902474 < DAT_00902470) goto LAB_004ff92b;
    DAT_00902464 = DAT_00902464 + 1;
    DAT_00902458 = DAT_00902458 + 1;
  }
  DAT_0090246c = *param_2;
  *(undefined4 *)(DAT_0090246c * 4 + param_6 + -4) = 0;
  (&DAT_009025e4)[DAT_0090246c] = 0;
  (&DAT_0090247c)[DAT_0090246c] = DAT_0090247c;
  (&DAT_0090256c)[DAT_0090246c] = DAT_00902464;
  (&DAT_009024f4)[DAT_0090246c] = *param_4;
  DAT_00902474 = DAT_00902464;
  for (iVar2 = (*param_4 - DAT_00902464) + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
    *(int *)(DAT_0090246c * 4 + param_6 + -4) = *(int *)(param_6 + -4 + DAT_0090246c * 4) + 1;
    (&DAT_009025e4)[DAT_0090246c] =
         (&DAT_009025e4)[DAT_0090246c] + *(int *)(param_5 + -4 + DAT_00902474 * 4);
    DAT_00902474 = DAT_00902474 + 1;
  }
LAB_004ffaea:
  do {
    DAT_00902474 = 1;
    DAT_00902464 = 1;
    DAT_00902478 = 1;
    DAT_00902470 = DAT_009025e8;
    DAT_0090245c = DAT_009025e8;
    for (iVar2 = DAT_0090246c; 0 < iVar2; iVar2 = iVar2 + -1) {
      if (DAT_0090245c < (int)(&DAT_009025e4)[DAT_00902478]) {
        DAT_0090245c = (&DAT_009025e4)[DAT_00902478];
        DAT_00902464 = DAT_00902478;
      }
      else if ((int)(&DAT_009025e4)[DAT_00902478] < DAT_00902470) {
        DAT_00902470 = (&DAT_009025e4)[DAT_00902478];
        DAT_00902474 = DAT_00902478;
      }
      DAT_00902478 = DAT_00902478 + 1;
    }
    if (DAT_00902474 <= DAT_00902464) {
      if (DAT_00902474 == DAT_00902464) {
                    /* WARNING: Subroutine does not return */
        FUN_006013a0(&DAT_00766bbc,0,0x784ff00,0,0);
      }
      DAT_0090244c = 0;
      DAT_00902478 = DAT_00902474;
      for (iVar2 = DAT_00902464 - DAT_00902474; 0 < iVar2; iVar2 = iVar2 + -1) {
        if (*(int *)(param_5 + -4 + (&DAT_00902570)[DAT_00902478] * 4) +
            (&DAT_009025e4)[DAT_00902478] < (int)(&DAT_009025e4)[DAT_00902464]) {
          (&DAT_009025e4)[DAT_00902478] =
               *(int *)(param_5 + -4 + (&DAT_00902570)[DAT_00902478] * 4) +
               (&DAT_009025e4)[DAT_00902478];
          (&DAT_009025e8)[DAT_00902478] =
               (&DAT_009025e8)[DAT_00902478] -
               *(int *)(param_5 + -4 + (&DAT_00902570)[DAT_00902478] * 4);
          *(int *)(DAT_00902478 * 4 + param_6 + -4) = *(int *)(param_6 + -4 + DAT_00902478 * 4) + 1;
          *(int *)(DAT_00902478 * 4 + param_6) = *(int *)(DAT_00902478 * 4 + param_6) + -1;
          (&DAT_0090247c)[DAT_00902478] =
               *(int *)(param_5 + -4 + (&DAT_00902570)[DAT_00902478] * 4) +
               (&DAT_0090247c)[DAT_00902478];
          (&DAT_009024f4)[DAT_00902478] = (&DAT_009024f4)[DAT_00902478] + 1;
          (&DAT_00902570)[DAT_00902478] = (&DAT_00902570)[DAT_00902478] + 1;
          DAT_0090244c = 1;
        }
        DAT_00902478 = DAT_00902478 + 1;
      }
      if (DAT_0090244c != 0) goto LAB_004ffaea;
    }
    DAT_0090244c = 0;
    DAT_00902478 = DAT_00902474;
    for (iVar2 = (DAT_00902464 - DAT_00902474) / -1; 0 < iVar2; iVar2 = iVar2 + -1) {
      if ((&DAT_009025e4)[DAT_00902478] + *(int *)(param_5 + -4 + (&DAT_009024f0)[DAT_00902478] * 4)
          < (int)(&DAT_009025e4)[DAT_00902464]) {
        (&DAT_009025e4)[DAT_00902478] =
             *(int *)(param_5 + -8 + (&DAT_009024f4)[DAT_00902478] * 4) +
             (&DAT_009025e4)[DAT_00902478];
        (&DAT_009025e0)[DAT_00902478] =
             (&DAT_009025e0)[DAT_00902478] -
             *(int *)(param_5 + -8 + (&DAT_009024f4)[DAT_00902478] * 4);
        *(int *)(DAT_00902478 * 4 + param_6 + -4) = *(int *)(param_6 + -4 + DAT_00902478 * 4) + 1;
        *(int *)(DAT_00902478 * 4 + param_6 + -8) = *(int *)(DAT_00902478 * 4 + param_6 + -8) + -1;
        (&DAT_0090247c)[DAT_00902478] =
             *(int *)(param_5 + -8 + (&DAT_0090256c)[DAT_00902478] * 4) +
             (&DAT_0090247c)[DAT_00902478];
        (&DAT_009024f0)[DAT_00902478] = (&DAT_009024f0)[DAT_00902478] + -1;
        (&DAT_0090256c)[DAT_00902478] = (&DAT_0090256c)[DAT_00902478] + -1;
        DAT_0090244c = 1;
      }
      DAT_00902478 = DAT_00902478 + -1;
    }
    if (DAT_0090244c == 0) {
      return;
    }
  } while( true );
LAB_004ff92b:
  DAT_00902470 = DAT_00902470 - *(int *)(param_5 + -4 + DAT_00902464 * 4);
  DAT_00902460 = DAT_00902470 + DAT_00902460;
  if (DAT_0090246c < *param_2) {
    DAT_0090246c = DAT_0090246c + 1;
  }
  (&DAT_009024f4)[DAT_0090246c] = DAT_00902464 + -1;
  (&DAT_0090247c)[DAT_0090246c] = DAT_00902460;
  *(int *)(DAT_0090246c * 4 + param_6 + -4) = DAT_00902458;
  (&DAT_009025e4)[DAT_0090246c] = DAT_00902470;
  (&DAT_0090256c)[DAT_0090246c] = DAT_0090245c;
  _DAT_00902454 = DAT_00902470;
  _DAT_00902450 = DAT_0090245c;
  goto LAB_004ff8a4;
}


