// FUN_00449145 @ 00449145 (Ghidra decompilation, names from analysis/engine/names.tsv and globals.tsv)


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_00449145(void)

{
  int iVar1;
  undefined2 in_FPUControlWord;
  undefined4 local_64;
  undefined4 *local_60;
  undefined4 local_5c;
  int local_58;
  undefined4 *local_54;
  uint local_50;
  int local_4c;
  undefined4 local_48 [8];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_c;
  
  for (iVar1 = 1; iVar1 < 0x101; iVar1 = iVar1 + 1) {
    *(undefined4 *)(&DAT_007fd85c + iVar1 * 4) = 0;
  }
  DAT_0078b4e0 = 0;
  DAT_01c4c828 = 1;
  for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
    DAT_01c4c830 = (int)ROUND((float)(&ITEM_P1)[(&ITEM_PTR0)[DAT_01c4c828]]);
    DAT_01c4c83c = (int)ROUND((float)(&ITEM_P2)[(&ITEM_PTR0)[DAT_01c4c828]]);
    if (DAT_01c4c830 == 8) {
      *(undefined4 *)(&DAT_007fd85c + DAT_01c4c83c * 4) = 1;
    }
    if ((DAT_01c4c830 < 3) && (*(int *)(&DAT_007fd85c + DAT_01c4c83c * 4) == 1)) {
      *(undefined4 *)(&DAT_007fd85c + DAT_01c4c83c * 4) = 0xffffffff;
    }
    if ((DAT_01c4c830 == 8) && (DAT_0078b4e0 < DAT_01c4c83c)) {
      DAT_0078b4e0 = DAT_01c4c83c;
    }
    DAT_01c4c828 = DAT_01c4c828 + 1;
  }
  local_50 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
  DAT_01c4c824 = (int)ROUND(_DAT_01c4c858);
  local_4c = DAT_01c4c824;
  while( true ) {
    DAT_0078b4e0 = DAT_0078b4e0 - DAT_01c4c824;
    DAT_01c4c830 = 1;
    DAT_01c4c828 = 1;
    for (iVar1 = ITEM_I; 0 < iVar1; iVar1 = iVar1 + -1) {
      DAT_01c4c83c = (&ITEM_PTR0)[DAT_01c4c828];
      local_50 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
      local_4c = (int)ROUND((float)(&ITEM_P2)[DAT_01c4c83c]);
      DAT_0078b4e4 = local_4c;
      if (DAT_0078b4e0 < local_4c) {
        if (*(int *)(&DAT_007fd85c + local_4c * 4) < 0) {
          local_24 = 0;
          (&ITEM_P2)[DAT_01c4c83c] = (float)(local_4c - DAT_0078b4e0);
          local_50 = CONCAT22(in_FPUControlWord,in_FPUControlWord) | 0xc000000;
          DAT_01c4c838 = (int)ROUND((float)(&ITEM_LEN)[DAT_01c4c83c]);
          local_54 = (undefined4 *)(DAT_01c4c838 + 1);
          local_4c = DAT_01c4c838;
          thunk_FUN_0054c590(&ITEM_LEN + DAT_01c4c83c,&DAT_01c6da5c + DAT_01c4c830 * 4,&local_54);
          DAT_01c4c830 = DAT_01c4c838 + DAT_01c4c830 + 1;
          (&ITEM_P2)[DAT_01c4c83c] = f_0;
        }
        else if (*(int *)(&DAT_007fd85c + local_4c * 4) == 2) {
          local_20 = 0;
        }
        else {
          *(undefined4 *)(&DAT_007fd85c + local_4c * 4) = 2;
          local_1c = 0;
        }
      }
      else {
        local_28 = 0;
      }
      local_18 = 0;
      DAT_01c4c828 = DAT_01c4c828 + 1;
    }
    thunk_FUN_00502575(&DAT_00760bd4,&DAT_01c4c7a0,0x80,&DAT_00760bd8);
    (&DAT_01c6da60)[DAT_01c4c830] = (float)DAT_01c5860c;
    (&DAT_01c6da64)[DAT_01c4c830] = (float)DAT_0078b4e8;
    (&DAT_01c6da68)[DAT_01c4c830] = f_4;
    DAT_01c4c830 = DAT_01c4c830 + 4;
    *(float *)(&DAT_01c6da5c + DAT_01c4c830 * 4) = f_m9999;
    local_48[0] = 0;
    local_54 = &DAT_01c4c830;
    FUN_005fa4d0(local_48,9,0x784ff00,&DAT_00760bc8,&local_54);
    local_60 = &DAT_01c6da60;
    local_58 = DAT_01c4c830;
    if (DAT_01c4c830 < 0) {
      local_58 = 0;
    }
    DAT_01c4c828 = local_58 + 1;
    local_64 = 1;
    local_5c = 1;
    local_54 = (undefined4 *)0x4;
    FUN_005fa9f0(local_48,&DAT_00760bc4,&local_64);
    DAT_01c4c848 = DAT_01c4c848 + 1;
    DAT_01c4c7ac = DAT_01c4c7ac + '\x01';
    if (DAT_01c4c7ac < '[') {
      local_10 = 0;
    }
    else {
      DAT_01c4c7ab = DAT_01c4c7ab + '\x01';
      DAT_01c4c7ac = 'A';
    }
    if (DAT_0078b4e0 < 1) break;
    local_c = 0;
  }
  local_48[0] = 0;
  FUN_005f7950(local_48,9,0x784ff00,&DAT_00760bc0,0);
  return;
}


