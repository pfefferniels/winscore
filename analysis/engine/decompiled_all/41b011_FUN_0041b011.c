// FUN_0041b011 @ 0041b011 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0041b011(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  uint local_4c;
  int local_48;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
    *(undefined4 *)(&DAT_01e67104 + iVar1 * 4) = 0;
  }
  DAT_007d157c = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    local_4c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
    local_48 = (int)ROUND((float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_007d157c]]);
    DAT_007d1578 = local_48;
    *(undefined4 *)(&DAT_01e67104 + local_48 * 4) = 0xffffffff;
    DAT_007d157c = DAT_007d157c + 1;
  }
  _DAT_007d1574 = 0;
  P5 = f_0;
  if (DAT_01a14948 < DAT_01a14950) {
    thunk_FUN_0054c68f(&DAT_01a14948,&DAT_01a14950);
  }
  if (DAT_01a1494c < DAT_01a14944) {
    thunk_FUN_0054c68f(&DAT_01a14944,&DAT_01a1494c);
  }
  if (DAT_01a1494c == 0) {
    DAT_01a1494c = DAT_01a14944;
  }
  if (DAT_01a14944 == 0) {
    DAT_01a14944 = DAT_01a1494c;
  }
  DAT_007d1578 = 0;
  local_4c = VIEW_DY + DAT_01a1494c;
  DAT_007d157c = FUN_0041baa2(&local_4c);
  if (DAT_01a14944 == DAT_01a1494c) {
    DAT_007d1578 = 1;
  }
  P4 = (float)DAT_007d157c;
  DAT_01a1494c = ((&STAFF_MID0)[DAT_007d157c] - VIEW_DY) + 1000;
  local_4c = VIEW_DY + DAT_01a14944;
  DAT_007d157c = FUN_0041baa2(&local_4c);
  P1 = (float)DAT_007d157c;
  DAT_01a14944 = ((&STAFF_MID0)[DAT_007d157c] - VIEW_DY) + -1000;
  if (DAT_01fbb8a4 == 10) {
    if (DAT_01fbb8a0 == 2) {
      if (P4 != P1) {
        DAT_01a1494c = ((&STAFF_MID0)[DAT_007d157c] - VIEW_DY) + 1000;
        P4 = P1;
      }
      _DAT_007d156c = DAT_01a1494c;
      _DAT_007d1570 = P1;
    }
    else if ((_DAT_007d1570 <= P4) && (P1 <= _DAT_007d1570)) {
      P1 = _DAT_007d1570 + f_1;
      local_4c = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_48 = (int)ROUND(P1);
      DAT_01a1494c = ((&STAFF_MID0)[local_48] - VIEW_DY) + 1000;
      DAT_01a14944 = ((&STAFF_MID0)[local_48] - VIEW_DY) + -1000;
      P4 = P1;
    }
  }
  DAT_007d1568 = DAT_01a14950;
  DAT_007d1564 = DAT_01a14948;
  if ((DAT_020b90a0 == 'L') || (DAT_01a14950 == 0)) {
LAB_0041b33e:
    if ((DAT_01fbb8a0 == 3) || (DAT_01fbb8a0 == 600)) {
      if (DAT_007d1578 == 0) {
        DAT_01a14948 = (DAT_01fbb8b0 + DAT_01a14950) - DAT_01fbb8ac;
        local_24 = 0;
        goto LAB_0041b394;
      }
      if ((34000 < DAT_01a14950) || (34000 < DAT_01a14948)) {
        DAT_007d1560 = 34000;
        if (34000 < DAT_01fbb8b0) {
          DAT_007d1560 = 0;
        }
        DAT_01a14950 = (DAT_007d1560 + DAT_01fbb8ac) - VIEW_DX;
        DAT_01a14948 = (DAT_007d1560 + DAT_01fbb8b0) - VIEW_DX;
        local_20 = 0;
        goto LAB_0041b5cf;
      }
      if (34000 < DAT_01fbb8b0) {
        DAT_01a14950 = (DAT_01fbb8ac - VIEW_DX) + -34000;
        DAT_01a14948 = (DAT_01fbb8b0 - VIEW_DX) + -34000;
        local_1c = 0;
        goto LAB_0041b5cf;
      }
      if (DAT_01fbb8ac == 0) {
        DAT_01a14948 = RIGHT_LIMIT;
        local_18 = 0;
      }
      else {
        DAT_01a14950 = DAT_01fbb8ac - VIEW_DX;
        DAT_01a14948 = DAT_01fbb8b0 - VIEW_DX;
        local_14 = 0;
      }
    }
    else {
      DAT_01a14950 = 0;
      DAT_01a14948 = RIGHT_LIMIT;
    }
  }
  else {
    iVar1 = DAT_01a14948 - DAT_01a14950;
    if (iVar1 < 0) {
      iVar1 = -iVar1;
    }
    if (iVar1 < 200) goto LAB_0041b33e;
LAB_0041b394:
    DAT_01a14950 = DAT_01a14950 - VIEW_DX;
    DAT_01a14948 = DAT_01a14948 - VIEW_DX;
  }
  P2 = (float)DAT_01a14950 / f_150;
  _DAT_007d155c = (float)DAT_01a14948;
  P3 = _DAT_007d155c / f_150;
  _DAT_007d1574 = 1;
  if ((f_200 < P2) && (f_220 < P3)) {
    P2 = P2 - f_227;
    P3 = P3 - f_227;
  }
  if (P3 - P2 < f_2) {
    P2 = f_0;
    P3 = f_200;
  }
  if ((DAT_01e66cc0 == 1) && (DAT_01fbb8a0 == 2)) {
    thunk_FUN_004e7380();
    DAT_01e66cc0 = 0;
    return;
  }
  local_10 = 0;
LAB_0041b5cf:
  _DAT_007d1574 = 1;
  FUN_0041bc5a();
  DAT_01fbb8ac = DAT_007d1568;
  DAT_01fbb8b0 = DAT_007d1564;
  if (DAT_01fbb8a4 != 0x59) {
    push_words(&DAT_0075f678,&P1);
    FUN_0041b6c4(&DAT_007d1574);
    pop_words(&DAT_0075f678,&P1);
  }
  if ((DAT_01fbb8a0 != 8) && (ABS(P3 - P2) <= f_4)) {
    P2 = f_0;
    P3 = f_0;
  }
  P7 = P4 - P1;
  return;
}


