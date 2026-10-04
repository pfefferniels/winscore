// FUN_0047bbee @ 0047bbee (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0047bbee(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  ITEM_I = ITEM_I + 1;
  DAT_00828504 = (&ITEM_PTR0)[ITEM_I];
  (&ITEM_LEN)[DAT_00828504] = f_7;
  (&ITEM_P1)[DAT_00828504] = f_10;
  (&ITEM_P2)[DAT_00828504] = (float)DAT_01c2cc24;
  (&ITEM_P3)[DAT_00828504] = *param_2;
  (&ITEM_P4)[DAT_00828504] = f_15;
  (&ITEM_P5)[DAT_00828504] = (float)*param_1;
  (&ITEM_P6)[DAT_00828504] = DAT_01fbb8b8 + f_1;
  *(float *)(&ITEM_P7 + DAT_00828504 * 4) = f_1;
  if (999 < *param_1) {
    (&ITEM_LEN)[DAT_00828504] = f_18;
    (&ITEM_P5)[DAT_00828504] = f_0;
    (&ITEM_P18)[DAT_00828504] = (float)*param_1;
    iVar2 = DAT_00828504 + 8;
    iVar3 = (DAT_00828504 - iVar2) + 0x12;
    if (iVar3 < 0) {
      iVar3 = 0;
    }
    for (iVar1 = 1; iVar1 <= iVar3; iVar1 = iVar1 + 1) {
      (&ITEM_LEN)[iVar2] = f_0;
      iVar2 = iVar2 + 1;
    }
  }
  ITEM_WORDS = (int)ROUND((float)ITEM_WORDS + (float)(&ITEM_LEN)[DAT_00828504] + f_1);
  (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
  return;
}


