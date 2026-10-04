// FUN_004c25e4 @ 004c25e4 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_004c25e4(undefined4 *param_1)

{
  DAT_0079485c = DAT_0079485c + 1;
  DAT_0089fa90 = DAT_0078dec4;
  if (7 < DAT_007cc610) {
    DAT_0089fa90 = 0;
  }
  *(undefined4 *)(&DAT_007ccd24 + DAT_0079485c * 4) = DAT_0089fa90;
  (&DAT_007cbd3c)[DAT_0079485c] = DAT_0079484c;
  (&DAT_007cdb34)[DAT_0079485c] = DAT_007cbfa0;
  (&DAT_007cd684)[DAT_0079485c] = *param_1;
  if (_DAT_007cc614 == DAT_00794850) {
    (&DAT_007cd684)[DAT_0079485c] = 0;
  }
  *(int *)(&DAT_007cc61c + DAT_0079485c * 4) = DAT_007cc610;
  *(float *)(DAT_0079485c * 4 + 0x7cd8dc) = DAT_00794850;
  (&DAT_007cc874)[DAT_0079485c] = DAT_007cc604;
  *(undefined4 *)(DAT_0079485c * 4 + 0x7ccacc) = DAT_007cc60c;
  *(int *)(DAT_0079485c * 4 + 0x7cd42c) = ITEM_I;
  *(undefined4 *)(&DAT_007ccf7c + DAT_0079485c * 4) = DAT_00794840;
  _DAT_007cc614 = DAT_00794850;
  DAT_007cc60c = 0;
  return;
}


