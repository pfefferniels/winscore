// FUN_004f1bd4 @ 004f1bd4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004f1bd4(float *param_1)

{
  uint uVar1;
  int iVar2;
  
  if (IP6 < 0) {
    uVar1 = IP4 & 1;
    if ((uVar1 != 0) && (IP4 < 0)) {
      uVar1 = uVar1 - 2;
    }
    if ((int)uVar1 < 0) {
      uVar1 = -uVar1;
    }
    if (uVar1 == 1) {
      FUN_004f1f69();
    }
  }
  push_words(&DAT_00766534,&P1);
  push_words(&DAT_00766534,&IP1);
  P1 = f_9;
  DAT_01a9f328 = Y_POS;
  P4 = P4 - f_1_68;
  _DAT_01a9f32c = X_POS / f_150;
  _DAT_008d19d8 = f_1_45;
  P3 = (DAT_01a9f318 * f_1_45) / f_25 + _DAT_01a9f32c;
  _DAT_008d19d4 = f_0_475;
  P7 = f_0_475 * *param_1;
  P6 = *param_1 * f_0_58;
  iVar2 = 0x11;
  DAT_008d19d0 = 8;
  do {
    *(float *)(&P0 + DAT_008d19d0 * 4) = f_0;
    DAT_008d19d0 = DAT_008d19d0 + 1;
    iVar2 = iVar2 + -1;
  } while (0 < iVar2);
  P5 = f_89;
  if (IP6 < 0) {
    P5 = f_88;
  }
  draw_item();
  pop_words(&DAT_00766534,&IP1);
  pop_words(&DAT_00766534,&P1);
  return;
}


