// FUN_00560a40 @ 00560a40 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_00560a40(void)

{
  int iVar1;
  bool bVar2;
  
  DAT_009a7a30 = DAT_01ba0d5c;
  if (DAT_01ba0d5c == 0) {
    DAT_009a7a30 = (int)ROUND(P2);
  }
  if (DAT_009a7a30 == 0) {
    DAT_0078b4e0 = 0x42;
  }
  else {
    DAT_01ba0d54 = DAT_009a7a30;
    DAT_009a7a2c = DAT_009a7a30 + 7;
    if (0xd < DAT_009a7a2c) {
      DAT_009a7a2c = DAT_009a7a30 + -5;
    }
    if (0xd < DAT_009a7a2c) {
      DAT_009a7a2c = DAT_009a7a2c + -0xc;
    }
    if (DAT_009a7a2c < 1) {
      DAT_009a7a2c = DAT_009a7a2c + 0xc;
    }
    DAT_01ba0d50 = *(undefined4 *)(&DAT_0079f480 + DAT_009a7a2c * 4);
    DAT_009a7a2c = DAT_009a7a30;
    if (DAT_009a7a30 < 0) {
      DAT_009a7a2c = -DAT_009a7a30;
    }
    iVar1 = DAT_009a7a2c % 0xc;
    DAT_009a7a34 = *(int *)(&DAT_0079f454 + iVar1 * 4);
    if (0xb < DAT_009a7a2c) {
      DAT_009a7a34 = DAT_009a7a34 + 7;
    }
    bVar2 = DAT_009a7a30 < 0;
    DAT_009a7a30 = iVar1;
    if (bVar2) {
      DAT_009a7a30 = -iVar1;
      DAT_009a7a34 = -DAT_009a7a34;
    }
    DAT_01ba0d58 = DAT_009a7a34;
    DAT_01ba0d44 = 0xffffffff;
    DAT_01ba0d4c = 0;
  }
  return;
}


