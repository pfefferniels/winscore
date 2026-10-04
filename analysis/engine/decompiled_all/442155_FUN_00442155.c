// FUN_00442155 @ 00442155 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00442155(void)

{
  int iVar1;
  
  _DAT_007f7dfc = (float)DAT_01fbb860;
  if (P3 == f_0) {
    P3 = DAT_0078d894;
  }
  if (P2 == f_0) {
    P2 = f_1;
  }
  DAT_007f7df8 = 1;
  for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&DAT_020492a4)[DAT_020492a4 + DAT_007f7df8] = (&DAT_020492a4)[DAT_007f7df8];
    DAT_007f7df8 = DAT_007f7df8 + 1;
  }
  while (P2 == _DAT_007f7dfc) {
LAB_00442337:
    P2 = P2 + f_1;
    if (P3 < P2) {
      return;
    }
  }
  DAT_007f7df8 = 1;
  iVar1 = ITEM_I;
joined_r0x0044223a:
  if (0 < iVar1) {
    DAT_007f7df4 = (&ITEM_PTR0)[DAT_007f7df8];
    if (P2 != (float)(&ITEM_P2)[DAT_007f7df4]) goto code_r0x0044226d;
    FUN_0044236f();
    DAT_007f7df8 = 1;
    for (iVar1 = DAT_020492a4; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_007f7df4 = (&DAT_020492a4)[DAT_007f7df8];
      if (-1 < DAT_007f7df4) {
        *(float *)(&DAT_02053438 + DAT_007f7df4 * 4) = P2;
      }
      (&DAT_020492a4)[DAT_007f7df8] = (&DAT_020492a4)[DAT_020492a4 + DAT_007f7df8];
      DAT_007f7df8 = DAT_007f7df8 + 1;
    }
  }
  goto LAB_00442337;
code_r0x0044226d:
  DAT_007f7df8 = DAT_007f7df8 + 1;
  iVar1 = iVar1 + -1;
  goto joined_r0x0044223a;
}


