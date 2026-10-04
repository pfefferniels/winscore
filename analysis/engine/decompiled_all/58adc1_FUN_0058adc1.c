// FUN_0058adc1 @ 0058adc1 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


void FUN_0058adc1(int *param_1)

{
  undefined2 in_FPUControlWord;
  int local_34;
  uint local_30;
  int local_2c;
  
  DAT_009a9348 = (int)ROUND(P2);
  if ((DAT_009a9348 < 1) || (ITEM_I < DAT_009a9348)) {
    DAT_009a9348 = ITEM_I;
  }
  local_30 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  local_2c = (int)ROUND(P3);
  DAT_009a9344 = local_2c;
  if (ITEM_I < local_2c) {
    DAT_009a9344 = ITEM_I;
  }
  if (DAT_009a9344 < 1) {
    DAT_009a9344 = 1;
  }
  if (DAT_009a9344 != DAT_009a9348) {
    DAT_009a9340 = (&ITEM_PTR0)[DAT_009a9348];
    DAT_009a933c = (&ITEM_PTR0)[DAT_009a9344];
    DAT_009a9338 = (&DAT_02091d20)[DAT_009a9348];
    DAT_009a9334 = (&DAT_02091d20)[DAT_009a9344];
    DAT_009a9330 = DAT_009a9338 - DAT_009a9340;
    if (DAT_009a9348 < DAT_009a9344) {
      local_34 = DAT_009a9340 + -1;
      thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&local_34);
      local_34 = DAT_009a9334 - DAT_009a9338;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_009a9338,&DAT_01e9997c + DAT_009a9340,&local_34);
      thunk_FUN_0054c590(&ITEM_LEN + DAT_009a9340,
                         &DAT_01e9997c + ((DAT_009a9334 + DAT_009a9340) - DAT_009a9338),
                         &DAT_009a9330);
      local_34 = DAT_009a9334 + -1;
      thunk_FUN_0054c590(&DAT_01e99980,&ITEM_P1,&local_34);
    }
    else {
      local_34 = DAT_009a933c + -1;
      thunk_FUN_0054c590(&ITEM_P1,&DAT_01e99980,&local_34);
      thunk_FUN_0054c590(&ITEM_LEN + DAT_009a9340,&DAT_01e9997c + DAT_009a933c,&DAT_009a9330);
      local_34 = DAT_009a9340 - DAT_009a933c;
      thunk_FUN_0054c590(&ITEM_LEN + DAT_009a933c,&DAT_01e9997c + DAT_009a9330 + DAT_009a933c,
                         &local_34);
      local_34 = DAT_009a9338 + -1;
      thunk_FUN_0054c590(&DAT_01e99980,&ITEM_P1,&local_34);
    }
    if (*param_1 == 0) {
      draw_items();
    }
    else {
      index_items();
    }
    DAT_0078b4f0 = 1;
    DAT_0078b4ec = 0;
  }
  return;
}


