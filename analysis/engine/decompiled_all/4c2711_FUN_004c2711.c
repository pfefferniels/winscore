// FUN_004c2711 @ 004c2711 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_004c2711(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  DAT_00794850 = DAT_0078cae8 + DAT_00794850;
  DAT_0089fab0 = *param_3;
  DAT_0089faac = *param_2;
  DAT_0089faa8 = *param_1;
  while( true ) {
    DAT_0089faa4 = (&ITEM_PTR0)[DAT_0089faac];
    DAT_0089faa0 = ITEM_WORDS;
    DAT_0089fa9c = (int)ROUND((float)(&ITEM_LEN)[DAT_0089faa4] + f_1);
    thunk_FUN_0054c590(&ITEM_LEN + DAT_0089faa4,&ITEM_LEN + ITEM_WORDS,&DAT_0089fa9c);
    (&ITEM_P3)[DAT_0089faa0] = DAT_00794850;
    ITEM_I = ITEM_I + 1;
    ITEM_WORDS = DAT_0089fa9c + ITEM_WORDS;
    (&DAT_02091d20)[ITEM_I] = ITEM_WORDS;
    DAT_0089faa4 = ITEM_I;
    DAT_0089fa98 = DAT_0089fa94;
    thunk_FUN_004ddb6e(&DAT_0089faa4);
    DAT_0089fa94 = DAT_0089fa98;
    DAT_007cc610 = *(undefined4 *)(&DAT_007cc61c + DAT_0089faa8 * 4);
    DAT_0078dec4 = *(undefined4 *)(&DAT_007ccd24 + DAT_0089faa8 * 4);
    DAT_01fb9634 = *(undefined4 *)(&DAT_007cd1d4 + DAT_0089faa8 * 4);
    DAT_007cbfa0 = (&DAT_007cdb34)[DAT_0089faa8];
    DAT_00794840 = *(undefined4 *)(&DAT_007ccf7c + DAT_0089faa8 * 4);
    FUN_004c25e4(param_4);
    DAT_0089fab0 = DAT_0089fab0 + -1;
    if (DAT_0089fab0 == 0) break;
    DAT_0089faac = DAT_0089faac + 1;
    DAT_0089faa8 = DAT_0089faa8 + 1;
    *param_4 = 0;
  }
  return;
}


