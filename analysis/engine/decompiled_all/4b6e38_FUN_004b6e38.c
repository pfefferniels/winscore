// FUN_004b6e38 @ 004b6e38 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004b6e38(int *param_1,int param_2,int param_3)

{
  DAT_01c585c0 = 2;
  do {
    while( true ) {
      DAT_01c585c4 = DAT_01c585c0 + -1;
      if (*(float *)(param_2 + -4 + DAT_01c585c4 * 4) <= *(float *)(param_2 + -4 + DAT_01c585c0 * 4)
         ) break;
      DAT_01c585c8 = *(undefined4 *)(param_3 + -4 + DAT_01c585c0 * 4);
      *(undefined4 *)(param_3 + -4 + DAT_01c585c0 * 4) =
           *(undefined4 *)(param_3 + -4 + DAT_01c585c4 * 4);
      *(undefined4 *)(param_3 + -4 + DAT_01c585c4 * 4) = DAT_01c585c8;
      DAT_01c585d0 = *(undefined4 *)(param_2 + -4 + DAT_01c585c0 * 4);
      *(undefined4 *)(param_2 + -4 + DAT_01c585c0 * 4) =
           *(undefined4 *)(param_2 + -4 + DAT_01c585c4 * 4);
      *(undefined4 *)(param_2 + -4 + DAT_01c585c4 * 4) = DAT_01c585d0;
      if (1 < DAT_01c585c4) {
        DAT_01c585c0 = DAT_01c585c4;
      }
    }
    DAT_01c585c0 = DAT_01c585c0 + 1;
  } while (DAT_01c585c0 <= *param_1);
  return;
}


