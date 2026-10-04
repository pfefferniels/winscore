// FUN_0044122d @ 0044122d (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0044122d(int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  char *pcVar2;
  
  DAT_01c585c0 = 0;
  if (*(char *)(param_1 + -1 + DAT_01c58668) != '_') {
    if (DAT_01c5867c == 0) {
      DAT_01c5867c = -1;
    }
    else if (-1 < DAT_01c5867c) {
      DAT_01c585c0 = 1;
      *param_3 = 0x5f;
      puVar1 = param_3 + DAT_01c585c0;
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *puVar1 = (char)DAT_007f7d3c;
      puVar1 = param_3 + DAT_01c585c0;
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *puVar1 = (char)((uint)DAT_007f7d3c >> 8);
    }
  }
  DAT_01c5865c = DAT_01c58668;
  DAT_01c58678 = DAT_01c58668;
  do {
    DAT_01c585e0._0_1_ = *(char *)(param_1 + -1 + DAT_01c5865c);
    if ((char)DAT_01c585e0 == '_') {
      if (((DAT_01c58678 == DAT_01c5865c) ||
          ((char)DAT_007f7d3c != *(char *)(param_1 + DAT_01c5865c))) ||
         (DAT_007f7d3c._1_1_ != *(char *)(param_1 + 1 + DAT_01c5865c))) {
        DAT_01c5867c = 1;
        DAT_007f7d3c._0_2_ =
             CONCAT11(*(undefined1 *)(param_1 + 1 + DAT_01c5865c),
                      *(undefined1 *)(DAT_01c5865c + param_1));
        goto LAB_004413dc;
      }
      DAT_01c5865c = DAT_01c5865c + 3;
    }
    else {
LAB_004413dc:
      pcVar2 = param_3 + DAT_01c585c0;
      DAT_01c585c0 = DAT_01c585c0 + 1;
      *pcVar2 = (char)DAT_01c585e0;
      DAT_01c5865c = DAT_01c5865c + 1;
    }
    if (DAT_01c585d4 < DAT_01c5865c) {
      return;
    }
  } while( true );
}


