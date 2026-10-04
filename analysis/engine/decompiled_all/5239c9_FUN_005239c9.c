// FUN_005239c9 @ 005239c9 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_005239c9(int *param_1,float *param_2)

{
  int iVar1;
  
  DAT_0094e624 = *param_1;
  DAT_0094e618 = (int)ROUND(*param_2 -
                            (float)(int)ROUND((float)(&ITEM_LEN)[(&ITEM_PTR0)[DAT_0094e624]]));
  (&ITEM_LEN)[(&ITEM_PTR0)[DAT_0094e624]] = *param_2;
  DAT_0094e624 = DAT_0094e624 + 1;
  DAT_0094e620 = (&ITEM_PTR0)[DAT_0094e624];
  if (DAT_0094e618 < 1) {
    DAT_0094e61c = DAT_0094e618 + DAT_0094e620;
    for (iVar1 = (ITEM_WORDS - DAT_0094e61c) + 1; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&ITEM_LEN)[DAT_0094e61c] = (&ITEM_LEN)[DAT_0094e61c - DAT_0094e618];
      DAT_0094e61c = DAT_0094e61c + 1;
    }
  }
  else {
    DAT_0094e61c = ITEM_WORDS;
    for (iVar1 = ((DAT_0094e620 - ITEM_WORDS) + -1) / -1; 0 < iVar1; iVar1 = iVar1 + -1) {
      (&ITEM_LEN)[DAT_0094e618 + DAT_0094e61c] = (&ITEM_LEN)[DAT_0094e61c];
      DAT_0094e61c = DAT_0094e61c + -1;
    }
    thunk_FUN_0054c419(&ITEM_LEN + DAT_0094e620,&DAT_0094e618);
  }
  DAT_0094e61c = DAT_0094e624;
  for (iVar1 = (ITEM_I - DAT_0094e624) + 2; 0 < iVar1; iVar1 = iVar1 + -1) {
    (&ITEM_PTR0)[DAT_0094e61c] = (&ITEM_PTR0)[DAT_0094e61c] + DAT_0094e618;
    DAT_0094e61c = DAT_0094e61c + 1;
  }
  ITEM_WORDS = DAT_0094e618 + ITEM_WORDS;
  return;
}


