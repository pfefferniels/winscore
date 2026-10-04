// FUN_00413608 @ 00413608 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Removing unreachable block (ram,0x00413656) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00413608(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_007d1390 = ITEM_WORDS;
  DAT_007d138c = ITEM_WORDS;
  _DAT_007d1388 = ITEM_I;
  iVar2 = ITEM_WORDS;
  for (iVar1 = 1; iVar1 < 0x7a; iVar1 = iVar1 + 1) {
    (&ITEM_LEN)[iVar2] = i_0;
    iVar2 = iVar2 + 1;
  }
  _DAT_007d1384 = STAFF_Y0;
  DAT_007d1380 = ((float)*param_1 - f_2400) / f_150;
  DAT_007d137c = ((float)*param_3 - f_2400) / f_150;
  DAT_007d1378 = (float)(*param_2 - STAFF_Y0) / f_175;
  DAT_007d1374 = (float)(*param_4 - STAFF_Y0) / f_175;
  (&ITEM_LEN)[DAT_007d138c] = f_26;
  (&ITEM_P1)[DAT_007d138c] = f_4;
  (&ITEM_P2)[DAT_007d138c] = i_0;
  (&ITEM_P3)[DAT_007d138c] = DAT_007d1380;
  (&ITEM_P6)[DAT_007d138c] = DAT_007d137c;
  *(float *)(&ITEM_P10 + DAT_007d138c * 4) = f_4;
  (&ITEM_P4)[DAT_007d138c] = DAT_007d1378;
  (&ITEM_P5)[DAT_007d138c] = DAT_007d1378;
  *(float *)(&ITEM_P26 + DAT_007d138c * 4) = f_990000;
  DAT_007d138c = ITEM_WORDS + 0x1b;
  ITEM_I = ITEM_I + 1;
  ITEM_WORDS = DAT_007d138c;
  (&ITEM_LEN)[DAT_007d138c] = f_26;
  (&ITEM_P1)[DAT_007d138c] = f_4;
  (&ITEM_P2)[DAT_007d138c] = i_0;
  (&ITEM_P3)[DAT_007d138c] = DAT_007d1380;
  (&ITEM_P6)[DAT_007d138c] = DAT_007d137c;
  *(float *)(&ITEM_P10 + DAT_007d138c * 4) = f_4;
  (&ITEM_P4)[DAT_007d138c] = DAT_007d1374;
  (&ITEM_P5)[DAT_007d138c] = DAT_007d1374;
  *(float *)(&ITEM_P26 + DAT_007d138c * 4) = f_990000;
  DAT_007d138c = ITEM_WORDS + 0x1b;
  ITEM_I = ITEM_I + 1;
  ITEM_WORDS = DAT_007d138c;
  (&ITEM_LEN)[DAT_007d138c] = f_26;
  (&ITEM_P1)[DAT_007d138c] = f_4;
  (&ITEM_P2)[DAT_007d138c] = i_0;
  (&ITEM_P3)[DAT_007d138c] = DAT_007d1380;
  (&ITEM_P6)[DAT_007d138c] = DAT_007d1380;
  *(float *)(&ITEM_P10 + DAT_007d138c * 4) = f_4;
  (&ITEM_P4)[DAT_007d138c] = DAT_007d1378;
  (&ITEM_P5)[DAT_007d138c] = DAT_007d1374;
  *(float *)(&ITEM_P26 + DAT_007d138c * 4) = f_990000;
  DAT_007d138c = ITEM_WORDS + 0x1b;
  ITEM_I = ITEM_I + 1;
  ITEM_WORDS = DAT_007d138c;
  (&ITEM_LEN)[DAT_007d138c] = f_26;
  (&ITEM_P1)[DAT_007d138c] = f_4;
  (&ITEM_P2)[DAT_007d138c] = i_0;
  (&ITEM_P3)[DAT_007d138c] = DAT_007d137c;
  (&ITEM_P6)[DAT_007d138c] = DAT_007d137c;
  *(float *)(&ITEM_P10 + DAT_007d138c * 4) = f_4;
  (&ITEM_P4)[DAT_007d138c] = DAT_007d1378;
  (&ITEM_P5)[DAT_007d138c] = DAT_007d1374;
  *(float *)(&ITEM_P26 + DAT_007d138c * 4) = f_990000;
  ITEM_WORDS = ITEM_WORDS + 0x1b;
  ITEM_I = ITEM_I + 1;
  DAT_01f9a6f4 = 1;
  draw_items();
  thunk_FUN_00549422();
  ITEM_WORDS = DAT_007d1390;
  return;
}


